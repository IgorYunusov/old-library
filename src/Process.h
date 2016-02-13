/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Process.h

Purpose:

   RollRat Library

Author:

   10-11-2015:   HyunJun Jeong, Creation

***/

#ifndef _PROCESS_9bf1541fdf7efd41b7b39543fd870ac4_
#define _PROCESS_9bf1541fdf7efd41b7b39543fd870ac4_

#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h> 
#include <ntstatus.h>
#include <ntdef.h>

#include "WString.h"

namespace Utility {
	
#   define NT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)

#   define ROUND_TO_PAGES(Size, PageSize)  (((ULONG_PTR)(Size) + PageSize - 1) & ~(PageSize - 1))
#   define RVA_TO_ADDR(Mapping,Rva) ((PVOID)(((ULONG_PTR) (Mapping)) + (Rva)))

#   define FASTCALL __fastcall

	typedef enum _SYSTEM_INFORMATION_CLASS {
		SystemProcessInformation = 5,
	} SYSTEM_INFORMATION_CLASS, *PSYSTEM_INFORMATION_CLASS;
	
	typedef enum __PROCESS_INFORMATION_CLASS{
		ProcessImageFileName = 27,
	} __PROCESS_INFORMATION_CLASS, *__PPROCESS_INFORMATION_CLASS;
	
	typedef struct _ANSI_STRING {
		USHORT Length;
		USHORT MaximumLength;
		PSTR  Buffer;
	} ANSI_STRING, *PANSI_STRING;
	
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
	
	typedef CONST OBJECT_ATTRIBUTES *PCOBJECT_ATTRIBUTES;
	typedef struct _OBJECT_TYPE *POBJECT_TYPE;
	typedef CCHAR KPROCESSOR_MODE;
	
	typedef struct _OBJECT_HANDLE_INFORMATION {
		ULONG HandleAttributes;
		ACCESS_MASK GrantedAccess;
	} OBJECT_HANDLE_INFORMATION, *POBJECT_HANDLE_INFORMATION;
	
	typedef struct _KPROCESS *PKPROCESS, *PRKPROCESS, *PEPROCESS;
	typedef struct _ACCESS_STATE *PACCESS_STATE;
	
	typedef enum _MODE {
		KernelMode,
		UserMode,
		MaximumMode
	} MODE;
	
	typedef struct _KAPC_STATE {
		LIST_ENTRY ApcListHead[MaximumMode];
		struct _KPROCESS *Process;
		union {
			UCHAR InProgressFlags;
			struct {
				BOOLEAN KernelApcInProgress : 1;
				BOOLEAN SpecialApcInProgress : 1;
			};
		};
	
		BOOLEAN KernelApcPending;
		BOOLEAN UserApcPending;
	} KAPC_STATE, *PKAPC_STATE, *PRKAPC_STATE;
	
	typedef
	NTSTATUS(
	NTAPI *
	_ZwReadVirtualMemory)(
		_In_ HANDLE ProcessHandle,
		_In_ PVOID BaseAddress,
		_Out_opt_ PVOID Buffer,
		_In_ ULONG BufferLength,
		_Out_opt_ PULONG ReturnLength OPTIONAL
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
	_ZwOpenProcess)(
		_Out_opt_ PHANDLE ProcessHandle,
		_In_ ACCESS_MASK DesiredAccess,
		_In_ POBJECT_ATTRIBUTES ObjectAttributes,
		_In_ PCLIENT_ID ClientId OPTIONAL
		);
	
	typedef
	NTSTATUS(
	NTAPI *
	_ZwDuplicateObject)(
		_In_ HANDLE SourceProcessHandle,
		_In_ HANDLE SourceHandle,
		_In_opt_ HANDLE TargetProcessHandle,
		_Out_opt_ PHANDLE TargetHandle,
		_In_ ACCESS_MASK DesiredAccess,
		_In_ ULONG HandleAttritues,
		_In_ ULONG Options
		);
	
	typedef
	NTSTATUS(
	NTAPI *
	_ZwQuerySystemInformation)(
		_In_ HANDLE ProcessHandle,
		_In_ __PROCESS_INFORMATION_CLASS ProcessInformationClass,
		_Inout_ PVOID ProcessInformation,
		_In_ ULONG ProcessInformationLength,
		_Out_opt_ PULONG ReturnLength
		);
	
	typedef
	NTSTATUS(
	NTAPI *
	__ZwQuerySystemInformation)(
		_In_ SYSTEM_INFORMATION_CLASS SystemInformationClass,
		_Inout_ PVOID SystemInformation,
		_In_ ULONG SystemInformationLength,
		_Out_opt_ PULONG ReturnLength
		);
	
	typedef
	NTSTATUS(
	NTAPI *
	_ZwClose)(
		_In_ HANDLE hHandle
		);
	
#   define ExFreePool(a) ExFreePoolWithTag (a,0)
#   define InitializeObjectAttributes( p, n, a, r, s ) { \
	(p)->Length = sizeof(OBJECT_ATTRIBUTES);          \
	(p)->RootDirectory = r;                             \
	(p)->Attributes = a;                                \
	(p)->ObjectName = n;                                \
	(p)->SecurityDescriptor = s;                        \
	(p)->SecurityQualityOfService = NULL;               \
	}
#   define OBJ_INHERIT             0x00000002L
#   define OBJ_PERMANENT           0x00000010L
#   define OBJ_EXCLUSIVE           0x00000020L
#   define OBJ_CASE_INSENSITIVE    0x00000040L
#   define OBJ_OPENIF              0x00000080L
#   define OBJ_OPENLINK            0x00000100L
#   define OBJ_KERNEL_HANDLE       0x00000200L
#   define OBJ_FORCE_ACCESS_CHECK  0x00000400L
#   define OBJ_VALID_ATTRIBUTES    0x000007F2L

#   define RtlEqualMemory(Destination,Source,Length) (!memcmp((Destination),(Source),(Length)))
#   define RtlMoveMemory(Destination,Source,Length) memmove((Destination),(Source),(Length))
#   define RtlCopyMemory(Destination,Source,Length) memcpy((Destination),(Source),(Length))
#   define RtlFillMemory(Destination,Length,Fill) memset((Destination),(Fill),(Length))
#   define RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))

	class ProcessImplements
	{
	public:

		static DWORD GetPidFromName(const WString& ws)
		{
			HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			PROCESSENTRY32W ProcessEntry32W;

			if (hSnapshot)
			{
				ProcessEntry32W.dwSize = sizeof(PROCESSENTRY32W);

				while (Process32NextW(hSnapshot, &ProcessEntry32W))
				{
					if (ws == ProcessEntry32W.szExeFile)
						return ProcessEntry32W.th32ProcessID;
				}
				CloseHandle(hSnapshot);
			}
			return -1;
		}
		
		static HANDLE OpenProcessFromPid(const DWORD pid)
		{
			HANDLE ret;
			OBJECT_ATTRIBUTES ObjectAttributes;
			CLIENT_ID cid;
			InitializeObjectAttributes(&ObjectAttributes, NULL,
				OBJ_KERNEL_HANDLE, NULL, NULL);
			_ZwOpenProcess _ZwOP =
				(_ZwOpenProcess)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwOpenProcess");

			cid.UniqueProcess = (HANDLE)pid;
			cid.UniqueThread = 0;

			_ZwOP(&ret, MAXIMUM_ALLOWED, &ObjectAttributes, &cid);

			return ret;
		}

		static void CloseProcess(HANDLE handle)
		{
			_ZwClose _ZwC =
				(_ZwClose)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwClose");
			_ZwC(handle);
		}

		static DWORD* GetPid(OUT size_t *size)
		{
			DWORD *r_pid;
			DWORD pid[16381];
			HANDLE hHandle;
			OBJECT_ATTRIBUTES ObjectAttributes;
			CLIENT_ID cid;
			size_t g = 0;
			InitializeObjectAttributes(&ObjectAttributes, NULL,
				OBJ_KERNEL_HANDLE, NULL, NULL);
			_ZwOpenProcess _ZwOP =
				(_ZwOpenProcess)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwOpenProcess");
			_ZwClose _ZwC =
				(_ZwClose)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwClose");

			for (int i = 0x8; i <= 0xffff; i += 4)
			{
				cid.UniqueProcess = (HANDLE)i;
				cid.UniqueThread = 0;
				_ZwOP(&hHandle, MAXIMUM_ALLOWED, &ObjectAttributes, &cid);

				if (hHandle > 0)
				{
					pid[g++] = i;
					_ZwC(hHandle);
				}
			}

			r_pid = new DWORD[g];
			for (int i = 0; i < g; i++)
				r_pid[i] = pid[i];

			*size = g;
			return r_pid;
		}

		static WString& GetImageFileName(const DWORD pid)
		{
			HANDLE hHandle;
			OBJECT_ATTRIBUTES ObjectAttributes;
			CLIENT_ID cid;
			PUNICODE_STRING us;
			InitializeObjectAttributes(&ObjectAttributes, NULL,
				OBJ_KERNEL_HANDLE, NULL, NULL);
			_ZwOpenProcess _ZwOP =
				(_ZwOpenProcess)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwOpenProcess");
			_ZwClose _ZwC =
				(_ZwClose)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwClose");
			_ZwQuerySystemInformation _ZwQSI =
				(_ZwQuerySystemInformation)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwQuerySystemInformation");

			cid.UniqueProcess = (HANDLE)pid;
			cid.UniqueThread = 0;

			_ZwOP(&hHandle, MAXIMUM_ALLOWED, &ObjectAttributes, &cid);
			_ZwQSI(&hHandle, ProcessImageFileName, &us, sizeof(UNICODE_STRING), 0);
			_ZwC(hHandle);

			return WString(us->Buffer, us->Length);
		}

	};

	class ModuleImplements
	{
	public:

		static HMODULE GetModuleFromPidWithName(DWORD pid, const WString& ws)
		{
			HANDLE hProcess;
			HMODULE hMods[1024];
			TCHAR szModName[MAX_PATH];
			DWORD cbNeeded;

			if (hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid))
			{
				if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
				{
					for (size_t k = 0; k < (cbNeeded / sizeof(HMODULE)); ++k)
					{
						if (GetModuleFileNameExW(hProcess, hMods[k], szModName, sizeof(szModName) / sizeof(TCHAR)))
						{
							if (wcsstr(szModName, ws.Reference()))
							{
								CloseHandle(hProcess);
								return hMods[k];
							}
						}
					}
				}
			}

			CloseHandle(hProcess);
			return NULL;

		}

	};
}

#endif