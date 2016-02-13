/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Memory.h

Purpose:

   RollRat Library

Author:

   10-11-2015:   HyunJun Jeong, Creation

***/

#ifndef _MEMORY_9bf1541fdf7efd41b7b39543fd870ac4_
#define _MEMORY_9bf1541fdf7efd41b7b39543fd870ac4_

#include "Process.h"

namespace Utility {
	
	class ProcessMemoryFinder
	{
	public:

		static DWORD* FirstScan(DWORD pid, DWORD dwDest, size_t dwSize, size_t& count)
		{
			SYSTEM_INFO sys_info;
			MEMORY_BASIC_INFORMATION mbi;
			DWORD vqAddr;
			DWORD lpfOldProtect;
			DWORD *byte_code = new DWORD[256 * dwSize];
			BYTE *parts = new BYTE[dwSize];
			HANDLE hProcess;
			_ZwReadVirtualMemory _ZwRVM =
				(_ZwReadVirtualMemory)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwReadVirtualMemory");
			OBJECT_ATTRIBUTES ObjectAttributes;
			CLIENT_ID cid;
			cid.UniqueProcess = (HANDLE)pid;
			cid.UniqueThread = 0;

			InitializeObjectAttributes(&ObjectAttributes, NULL,
				OBJ_KERNEL_HANDLE, NULL, NULL);

			_ZwOpenProcess _ZwOP =
				(_ZwOpenProcess)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwOpenProcess");
			_ZwClose _ZwC =
				(_ZwClose)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwClose");

			_ZwOP(&hProcess, MAXIMUM_ALLOWED, &ObjectAttributes, &cid);

			if (!hProcess)
				return NULL;

			for (unsigned i = 0; i < dwSize; i++, dwDest /= 256)
				parts[i] = dwDest % 256;

			GetSystemInfo(&sys_info);
			vqAddr = (DWORD)sys_info.lpMinimumApplicationAddress;

			for (count = 0; vqAddr < (DWORD)sys_info.lpMaximumApplicationAddress;)
			{
				if (!VirtualQueryEx(hProcess, (LPVOID)vqAddr, &mbi, sizeof(mbi)) == sizeof(mbi))
					continue;
				if (!(mbi.Type == MEM_PRIVATE && mbi.State == MEM_COMMIT && mbi.RegionSize > 0))
					goto CAVECOURSE;

				BYTE * readmem = new BYTE[mbi.RegionSize];
				VirtualProtectEx(hProcess, mbi.BaseAddress, dwSize, PAGE_EXECUTE_READWRITE, &lpfOldProtect);

				_ZwRVM(hProcess, mbi.BaseAddress, reinterpret_cast<LPVOID> (readmem), mbi.RegionSize, NULL);

				for (size_t i = 0; i < mbi.RegionSize; i++)
				{
					for (int j = 0; j < dwSize; j++)
					{
						if ((i + dwSize + 1) > mbi.RegionSize)
							break;
						else if (readmem[i + j] != parts[j])
							break;
						else if (j == dwSize - 1)
						{
							if (count % 256 == 0)
								byte_code = (DWORD *)realloc(
								byte_code, dwSize * 256 * (count / 256 + 1)
								);
							byte_code[count] = (DWORD)mbi.BaseAddress + i;
							count++;
						}
					}
				}

				VirtualProtectEx(hProcess, mbi.BaseAddress, dwSize, lpfOldProtect, NULL);
				delete readmem;
			CAVECOURSE:
				vqAddr = (DWORD)mbi.BaseAddress + (DWORD)mbi.RegionSize;
			}

			_ZwC(hProcess);
			delete parts;
			return byte_code;
		}

		static DWORD* NextScan(DWORD pid, DWORD* pdwAddr, size_t dwBySize, DWORD dwDest, size_t dwSize, size_t& count)
		{
			SYSTEM_INFO sys_info;
			MEMORY_BASIC_INFORMATION mbi;
			DWORD vqAddr;
			DWORD lpfOldProtect;
			DWORD *byte_code = new DWORD[256 * dwSize];
			HANDLE hProcess;
			_ZwReadVirtualMemory _ZwRVM =
				(_ZwReadVirtualMemory)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwReadVirtualMemory");
			OBJECT_ATTRIBUTES ObjectAttributes;
			CLIENT_ID cid;
			cid.UniqueProcess = (HANDLE)pid;
			cid.UniqueThread = 0;

			InitializeObjectAttributes(&ObjectAttributes, NULL,
				OBJ_KERNEL_HANDLE, NULL, NULL);

			_ZwOpenProcess _ZwOP =
				(_ZwOpenProcess)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwOpenProcess");
			_ZwClose _ZwC =
				(_ZwClose)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwClose");

			_ZwOP(&hProcess, MAXIMUM_ALLOWED, &ObjectAttributes, &cid);

			if (!hProcess)
				return NULL;

			GetSystemInfo(&sys_info);
			vqAddr = pdwAddr[0];

			count = 0;

			for (size_t k = 0; k < dwBySize; vqAddr = pdwAddr[k++])
			{
				if (!VirtualQueryEx(hProcess, (LPVOID)vqAddr, &mbi, sizeof(mbi)) == sizeof(mbi))
					continue;
				if (!(mbi.Type == MEM_PRIVATE && mbi.State == MEM_COMMIT && mbi.RegionSize > 0))
					continue;

				DWORD readmem = 0;
				VirtualProtectEx(hProcess, (LPVOID)vqAddr, dwSize, PAGE_EXECUTE_READWRITE, &lpfOldProtect);

				_ZwRVM(hProcess, (LPVOID)vqAddr, reinterpret_cast<LPVOID> (&readmem), sizeof(DWORD), NULL);

				if (readmem == dwDest){
					if (count % 256 == 0)
						byte_code = (DWORD *)realloc(
						byte_code, dwSize * 256 * (count / 256 + 1)
						);
					byte_code[count] = vqAddr;
					count++;
				}

				VirtualProtectEx(hProcess, (LPVOID)vqAddr, dwSize, lpfOldProtect, NULL);
			}

			_ZwC(hProcess);
			return byte_code;
		}

	};

	class ProcessMemroyIO
	{
	public:

		void WriteProcessMemory(HANDLE hProcess, LPVOID lpBaseAddress, LPCVOID value, size_t size)
		{
			DWORD lpfOldProtect;
			_ZwWriteVirtualMemory _ZwRVM =
				(_ZwWriteVirtualMemory)GetProcAddress(GetModuleHandleW(L"ntdll.dll"), "ZwWriteVirtualMemory");
			VirtualProtectEx(hProcess, lpBaseAddress, size, PAGE_EXECUTE_READWRITE, &lpfOldProtect);
			_ZwRVM(hProcess, lpBaseAddress, (PVOID)value, size, NULL);
			VirtualProtectEx(hProcess, lpBaseAddress, size, lpfOldProtect, NULL);
		}

	};
}

#endif