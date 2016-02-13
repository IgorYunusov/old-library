#include <windows.h>
#include <stddef.h>
#ifndef _AUSTIN_POWER_
#define _AUSTIN_POWER_

class AustinPower{
private:
	BOOL		FFirstBreakpointHit;
	CONTEXT	OriginalThreadContext,
		FakeLoadLibraryContext;
	PVOID		AddressOfBase;
	BYTE		m_originalExeEntryPointOpcode;
	char		szHookedDllName[ MAX_PATH ];
	PROCESS_INFORMATION			ProcessInfo;
	CREATE_PROCESS_DEBUG_INFO	ProcessDbgInfo;
	
#pragma pack( push, 1 )
	struct FAKE_LOADLIBRARY_CODE{
		BYTE	instr_PUSH;
		DWORD	operand_PUSH_value;
		BYTE	instr_MOV_EAX;
		DWORD	operand_MOV_EAX;
		WORD	instr_CALL_EAX;
		BYTE	instr_INT_3;
		char	data_DllName[ MAX_PATH ];
		
		// Constructor builds known in advance fields
		FAKE_LOADLIBRARY_CODE() : instr_PUSH( 0x68 ),
			instr_MOV_EAX( 0xB8 ),
			instr_CALL_EAX( 0xD0FF ), instr_INT_3( 0xCC ){ }
	};
#pragma pack( pop )
	
	FAKE_LOADLIBRARY_CODE	SourceStub;
	FAKE_LOADLIBRARY_CODE	*TargetStub;
	PVOID							TargetStubBP;
	
	public:
		AustinPower();
		BOOL CreateAustinPower( char *szFileCmd, char *szDllName );
		void DebugLoop();
		BOOL InjectSpyDll();
		BOOL ReplaceOriginalPagesAndContext();
		PVOID FindFirstCodePage( HANDLE hProcess, PVOID PProcessBase );
		void HandleException( LPDEBUG_EVENT lpEvent, PDWORD continueStatus );
		PVOID GetMemoryForLoadLibrayStub();
		BOOL SetEntryPointBP();
		BOOL RemoveEntryPointBP();
};


AustinPower::AustinPower()
{
	FFirstBreakpointHit = false;
}

BOOL AustinPower::CreateAustinPower( char *szFileCmd, char *szDllName )
{
	STARTUPINFO		sInfo;

	ZeroMemory( &sInfo, sizeof( sInfo ) );
	sInfo.cb = sizeof( sInfo );

	if( CreateProcess(
							0,
							szFileCmd,
							0,
							0,
							FALSE,
							DEBUG_ONLY_THIS_PROCESS,
							0,
							0,
							&sInfo,
							&ProcessInfo ) ){
		strncpy( szHookedDllName, szDllName, strlen( szDllName ) + 1 );

		DebugLoop();
		return true;
	}

	return false;
}

void AustinPower::DebugLoop()
{
	DEBUG_EVENT event;
	DWORD continueStatus;

	while( 1 ){
		WaitForDebugEvent( &event, INFINITE );

		continueStatus = DBG_EXCEPTION_NOT_HANDLED;

		if( event.dwDebugEventCode == CREATE_PROCESS_DEBUG_EVENT )
			ProcessDbgInfo = event.u.CreateProcessInfo;
		else if( event.dwDebugEventCode == EXCEPTION_DEBUG_EVENT )
			HandleException( &event, &continueStatus );

		if( event.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT )
			return;

		ContinueDebugEvent( event.dwProcessId,
			event.dwThreadId,
			continueStatus );
	}
}

void AustinPower::HandleException( LPDEBUG_EVENT lpEvent, PDWORD continueStatus )
{
	EXCEPTION_RECORD &exceptRec = lpEvent->u.Exception.ExceptionRecord;

	if( lpEvent->u.Exception.ExceptionRecord.ExceptionCode
		== EXCEPTION_BREAKPOINT ){
		if( FFirstBreakpointHit == FALSE ){
			SetEntryPointBP();
			FFirstBreakpointHit = TRUE;
		}else if( exceptRec.ExceptionAddress == AddressOfBase ){
			RemoveEntryPointBP();
			InjectSpyDll();
		}else if( exceptRec.ExceptionAddress == TargetStubBP ){
			ReplaceOriginalPagesAndContext();
		}

		*continueStatus = DBG_CONTINUE;
	}else{
		*continueStatus = DBG_EXCEPTION_NOT_HANDLED;
	}
}

BOOL AustinPower::SetEntryPointBP()
{
	DWORD cBytesMoved;

	AddressOfBase = ProcessDbgInfo.lpStartAddress;

	BOOL retValue = ReadProcessMemory( ProcessInfo.hProcess,
		AddressOfBase,
		&m_originalExeEntryPointOpcode,
		sizeof( m_originalExeEntryPointOpcode ),
		&cBytesMoved );

	if( !retValue )
		return FALSE;

	BYTE bpOpcode = 0xCC;

	return WriteProcessMemory( ProcessInfo.hProcess,
		AddressOfBase,
		&bpOpcode,
		sizeof( bpOpcode ),
		&cBytesMoved );
}

BOOL AustinPower::RemoveEntryPointBP()
{
	DWORD cBytesMoved;

	return WriteProcessMemory( ProcessInfo.hProcess,
		AddressOfBase,
		&m_originalExeEntryPointOpcode,
		sizeof( m_originalExeEntryPointOpcode ),
		&cBytesMoved );
}

BOOL AustinPower::InjectSpyDll()
{

	DWORD cBytesMoved;

	OriginalThreadContext.ContextFlags = CONTEXT_FULL;
	if( !GetThreadContext( ProcessDbgInfo.hThread, 
		&OriginalThreadContext ) )
		return FALSE;

	OriginalThreadContext.Eip = OriginalThreadContext.Eip - 1;

	// DLL�� ������ ���μ����� ���� �ڵ� �ּҸ� ��� ��
	TargetStub = ( FAKE_LOADLIBRARY_CODE * ) GetMemoryForLoadLibrayStub();

	if( !TargetStub )
		return false;

	TargetStubBP = ( PBYTE ) TargetStub +
							offsetof( FAKE_LOADLIBRARY_CODE, instr_INT_3 );

	// ���� ����ü�� �ϼ�
	strcpy( SourceStub.data_DllName, szHookedDllName );

	SourceStub.operand_PUSH_value = ( DWORD ) TargetStub
		+ offsetof( FAKE_LOADLIBRARY_CODE, data_DllName );

	SourceStub.operand_MOV_EAX = ( DWORD ) GetProcAddress(
		GetModuleHandle( "kernel32.dll" ), "LoadLibraryA" );

	// ������ ���μ����� ���� ����
	BOOL retValue;
	retValue = WriteProcessMemory( ProcessInfo.hProcess, TargetStub,
											&SourceStub, sizeof( SourceStub ),
											&cBytesMoved );
	if( !retValue )
		return false;

	// ������ ������ ���μ����� EIP �������Ϳ� ��� ������ ������ �ּҸ� �־� �����ϵ��� �Ѵ�.
	CONTEXT stubContext = OriginalThreadContext;
	stubContext.Eip = ( DWORD ) TargetStub;

	SetThreadContext( ProcessInfo.hThread, &stubContext );

	return true;
}

BOOL AustinPower::ReplaceOriginalPagesAndContext( void )
{

	if( !SetThreadContext( ProcessDbgInfo.hThread,
									&OriginalThreadContext ) )
		return FALSE;

	return TRUE;
}

typedef
LPVOID ( __stdcall * PFNVIRTALLEX )( HANDLE, LPVOID, SIZE_T, DWORD, DWORD );

PVOID AustinPower::GetMemoryForLoadLibrayStub( void )
{
	OSVERSIONINFO osvi = { sizeof( osvi ) };

	GetVersionEx( &osvi );

	if( osvi.dwPlatformId == VER_PLATFORM_WIN32_NT ){
		// NT, 2000, XP�� ��� VirtualAllocEx�� �̿��Ͽ� �ٸ� ���μ�����
		// �޸� �ּ� ������ �޸𸮸� �Ҵ��� �� �ִ�. ������ 95�� ���� ���� �������� �� �Ǿ� �ִ�.
		PFNVIRTALLEX pfnVirtualAllocEx = ( PFNVIRTALLEX )
			GetProcAddress( GetModuleHandle( "kernel32.dll" ), "VirtualAllocEx" );

		LPVOID pStubMemory = pfnVirtualAllocEx(
									ProcessDbgInfo.hProcess,
									0, sizeof( FAKE_LOADLIBRARY_CODE ),
									MEM_COMMIT, PAGE_READWRITE );

		return ( FAKE_LOADLIBRARY_CODE * ) pStubMemory;
	}else if( osvi.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS ){
		// ������ 9X�� ��� �޸� �� ������ ��´�. ������ 9X�� ��쿡
		// �޸� �� ������ �����Ǵ� ���� 2GB ������ ������ ������
		// ��� ���μ������� ������ �����ϴ�.
		HANDLE hFileMapping = CreateFileMapping(
									INVALID_HANDLE_VALUE, 0,
									PAGE_READWRITE | SEC_COMMIT,
									0,
									sizeof( FAKE_LOADLIBRARY_CODE ),
									0 );
		if( hFileMapping ){
			LPVOID pStubMemory = MapViewOfFile( hFileMapping,
										FILE_MAP_WRITE,
										0, 0,
										sizeof( FAKE_LOADLIBRARY_CODE ) );

			return ( FAKE_LOADLIBRARY_CODE * ) pStubMemory;
		}else
			CloseHandle( hFileMapping );
	}

	return 0;
}

#endif