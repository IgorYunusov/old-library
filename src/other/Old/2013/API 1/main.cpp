#include <windows.h>
#include <tlhelp32.h>
#include <winerror.h>

typedef struct _UNICODE_STRING {
	USHORT Length;
	USHORT MaximumLength;
	PWSTR Buffer;
} UNICODE_STRING, *PUNICODE_STRING;

typedef struct _OBJECT_ATTRIBUTES {
	ULONG  Length;
	HANDLE  RootDirectory;
	PUNICODE_STRING  ObjectName;
	ULONG  Attributes;
	PVOID  SecurityDescriptor;
	PVOID  SecurityQualityOfService;
} OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

typedef struct _CLIENT_ID {
	HANDLE UniqueProcess;
	HANDLE UniqueThread;
} CLIENT_ID, *PCLIENT_ID;

#define InitializeObjectAttributes( p, n, a, r, s ) { \
	(p)->Length = sizeof(OBJECT_ATTRIBUTES);          \
	(p)->RootDirectory = r;                             \
	(p)->Attributes = a;                                \
	(p)->ObjectName = n;                                \
	(p)->SecurityDescriptor = s;                        \
	(p)->SecurityQualityOfService = NULL;               \
	}

typedef
NTSTATUS(
NTAPI *
_ZwOpenProcess)(
	_Out_opt_ PHANDLE ProcessHandle,
	_In_ ACCESS_MASK DesiredAccess,
	_In_ POBJECT_ATTRIBUTES ObjectAttributes,
	_In_ PCLIENT_ID ClientId OPTIONAL
	);

typedef
NTSTATUS(
NTAPI *
_ZwClose)(
	_In_ HANDLE hHandle
	);

typedef
NTSTATUS(
NTAPI *
_ZwWriteVirtualMemory)(
	_In_ HANDLE ProcessHandle,
	_In_ PVOID BaseAddress,
	_In_ PVOID Buffer,
	_In_ SIZE_T NumberOfBytesToWrite,
	_Out_opt_ PSIZE_T NumberOfBytesWritten
	);

typedef
NTSTATUS(
NTAPI *
_ZwProtectVirtualMemory)(
	IN HANDLE ProcessHandle,
	IN OUT PVOID *BaseAddress,
	IN OUT PULONG ProtectSize,
	IN ULONG NewProtect,
	OUT PULONG OldProtect
	);

#define OBJ_KERNEL_HANDLE       0x00000200L

DWORD FindProcess(char * szProcess)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 ProcessEntry32;

	if (hSnapshot)
	{
		ProcessEntry32.dwSize = sizeof(PROCESSENTRY32);

		while (Process32Next(hSnapshot, &ProcessEntry32))
		{
			if (strcmp(ProcessEntry32.szExeFile, szProcess) == 0)
				return ProcessEntry32.th32ProcessID;
		}
		CloseHandle(hSnapshot);
	}
	return 0;
}

NTSTATUS _$WriteProcessMemoryWithNativeApi(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID value, int size)
{
	DWORD lpfOldProtect;
	_ZwWriteVirtualMemory _ZwWVM =
		(_ZwWriteVirtualMemory)GetProcAddress(GetModuleHandle("ntdll.dll"), "ZwWriteVirtualMemory");
	_ZwProtectVirtualMemory _ZwPVM =
		(_ZwProtectVirtualMemory)GetProcAddress(GetModuleHandle("ntdll.dll"), "ZwProtectVirtualMemory");
	NTSTATUS ret;
	//VirtualProtectEx(hProcess, lpBaseAddress, size, PAGE_EXECUTE_READWRITE, &lpfOldProtect);
	_ZwPVM(hProcess, (PVOID *)lpBaseAddress, (PULONG)size, PAGE_EXECUTE_READWRITE, &lpfOldProtect);
	ret = _ZwWVM(hProcess, lpBaseAddress, (PVOID)value, size, NULL);
	_ZwPVM(hProcess, (PVOID *)lpBaseAddress, (PULONG)size, lpfOldProtect, NULL);
	//VirtualProtectEx(hProcess, lpBaseAddress, size, lpfOldProtect, NULL);
	return ret;
}

BOOL SetPrivilege(HANDLE hHandle, LPCTSTR lpszPrivilege, BOOL bEnablePrivilege)
{
	TOKEN_PRIVILEGES tp;
	HANDLE hToken;
	LUID luid;

	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY,
		&hToken))
		return FALSE;

	if (!LookupPrivilegeValue(NULL,           // lookup privilege on local system
		lpszPrivilege,  // privilege to lookup 
		&luid))        // receives LUID of privilege
		return FALSE;

	tp.PrivilegeCount = 1;
	tp.Privileges[0].Luid = luid;
	if (bEnablePrivilege)
		tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	else
		tp.Privileges[0].Attributes = 0;

	if (!AdjustTokenPrivileges(hToken,
		FALSE,
		&tp,
		sizeof(TOKEN_PRIVILEGES),
		(PTOKEN_PRIVILEGES)NULL,
		(PDWORD)NULL))
		return FALSE;

	if (GetLastError() == ERROR_NOT_ALL_ASSIGNED)
		return FALSE;

	return TRUE;
}

int main()
{
	OBJECT_ATTRIBUTES ObjectAttributes;
	InitializeObjectAttributes(&ObjectAttributes, NULL,
		OBJ_KERNEL_HANDLE, NULL, NULL);
	
	_ZwOpenProcess _ZwOP =
		(_ZwOpenProcess)GetProcAddress(GetModuleHandle("ntdll.dll"), "ZwOpenProcess");
	_ZwClose _ZwC =
		(_ZwClose)GetProcAddress(GetModuleHandle("ntdll.dll"), "ZwClose");
	
	FARPROC pThreadProc;
	CLIENT_ID cid;
	HANDLE hHandle;
	pThreadProc = GetProcAddress(GetModuleHandleA("user32.dll"), "FindWindowA");

	cid.UniqueProcess = (HANDLE)FindProcess("Taskmgr.exe");
	cid.UniqueThread = 0;
	//SetPrivilege(cid.UniqueProcess, SE_INCREASE_QUOTA_NAME, TRUE);

	//_ZwOP(&hHandle, MAXIMUM_ALLOWED, &ObjectAttributes, &cid);
	hHandle = OpenProcess(MAXIMUM_ALLOWED, FALSE, (DWORD)cid.UniqueProcess);
	//_$WriteProcessMemoryWithNativeApi(hHandle, (LPVOID)((DWORD)pThreadProc), (LPCVOID)0xC2, 1);

	DWORD lpfOldProtect;
	VirtualProtectEx(hHandle, (LPVOID)((DWORD)pThreadProc), 1, PAGE_EXECUTE_READWRITE, &lpfOldProtect);
	WriteProcessMemory(hHandle, (LPVOID)((DWORD)pThreadProc), (LPCVOID)0xC2, 1, 0);
	VirtualProtectEx(hHandle, (LPVOID)((DWORD)pThreadProc), 1, lpfOldProtect, NULL);

	CloseHandle(hHandle);
	//_ZwC(hHandle);

	return 0;
}
