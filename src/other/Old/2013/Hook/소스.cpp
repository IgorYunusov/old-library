#include <Windows.h>
#include <stdio.h>
#include <tlhelp32.h>

DWORD search_enum()
{
	HANDLE hs;
	PROCESSENTRY32 pe;
	TCHAR str[256];
	
	hs = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hs == (HANDLE)-1)
		return 0;

	pe.dwSize = sizeof(PROCESSENTRY32);
	if (Process32First(hs, &pe))
	do{
		wsprintf(str, "%5d - %s\n", pe.th32ProcessID, pe.szExeFile);
		if (!strcmp(pe.szExeFile, "notepad.exe"))
			return pe.th32ProcessID;
		printf(str);
	} while (Process32Next(hs, &pe));
	CloseHandle(hs);
	return 0;
}

int main()
{
	DWORD dwPID;
	DEBUG_EVENT de;
	DWORD dwCS;

	LPVOID g_pfWF = NULL;
	CREATE_PROCESS_DEBUG_INFO g_cpdi;
	BYTE g_chINT3 = 0xCC, g_chOrgByte = 0;

	dwPID = search_enum();
	
	__asm{
		mov eax, dword ptr fs : [18h]
		mov eax, dword ptr[eax + 20h]
		mov dwPID, eax
	}

	printf("%d\n", dwPID);

	dwPID = GetCurrentProcessId();
	WriteProcessMemory(0, 0, 0, 0, NULL);
	printf("%d", dwPID);

	if (!DebugActiveProcess(GetCurrentProcessId()))
		return 1;

	while (WaitForDebugEvent(&de, INFINITE))
	{
		dwCS = DBG_CONTINUE;
		if (de.dwDebugEventCode == CREATE_PROCESS_DEBUG_EVENT)
		{
			g_pfWF = GetProcAddress(GetModuleHandle("kernel32.dll"), "WriteFile");
			memcpy(&g_cpdi, &de.u.CreateProcessInfo, sizeof(CREATE_PROCESS_DEBUG_INFO));
			ReadProcessMemory(g_cpdi.hProcess, g_pfWF, &g_chOrgByte, sizeof(BYTE), NULL);
			WriteProcessMemory(g_cpdi.hProcess, g_pfWF, &g_chINT3, sizeof(BYTE), NULL);
		}
		else if (de.dwDebugEventCode == EXCEPTION_DEBUG_EVENT)
		{
			CONTEXT ctx;
			PBYTE lpBuffer = NULL;
			DWORD dwNumOfBytesToWrite, dwAddrOfBuffer, i;
			PEXCEPTION_RECORD per = &de.u.Exception.ExceptionRecord;

			if (per->ExceptionCode == EXCEPTION_BREAKPOINT)
			{
				if (g_pfWF == per->ExceptionAddress)
				{
					WriteProcessMemory(g_cpdi.hProcess, g_pfWF, &g_chOrgByte, sizeof(BYTE), NULL);
					ctx.ContextFlags = CONTEXT_CONTROL;
					GetThreadContext(g_cpdi.hThread, &ctx);
					ReadProcessMemory(g_cpdi.hProcess, (LPVOID)(ctx.Esp + 0x8), &dwAddrOfBuffer, sizeof(DWORD), NULL);
					ReadProcessMemory(g_cpdi.hProcess, (LPVOID)(ctx.Esp + 0xC), &dwNumOfBytesToWrite, sizeof(DWORD), NULL);
					lpBuffer = (PBYTE)malloc(dwNumOfBytesToWrite + 1);
					memset(lpBuffer, 0, dwNumOfBytesToWrite + 1);
					ReadProcessMemory(g_cpdi.hProcess, (LPVOID)dwAddrOfBuffer, lpBuffer, dwNumOfBytesToWrite, NULL);
					for (i = 0; i < dwNumOfBytesToWrite; i++)
						if (0x61 <= lpBuffer[i] && lpBuffer[i] <= 0x7A)
							lpBuffer[i] -= 0x20;
					WriteProcessMemory(g_cpdi.hProcess, (LPVOID)dwAddrOfBuffer, lpBuffer, dwNumOfBytesToWrite, NULL);
					free(lpBuffer);
					ctx.Eip = (DWORD)g_pfWF;
					SetThreadContext(g_cpdi.hThread, &ctx);
					ContinueDebugEvent(de.dwProcessId, de.dwThreadId, DBG_CONTINUE);
					Sleep(0);
					WriteProcessMemory(g_cpdi.hProcess, g_pfWF, &g_chINT3, sizeof(BYTE), NULL);
				}
			}
		}
		else if (de.dwDebugEventCode == EXIT_PROCESS_DEBUG_EVENT)
			break;

		ContinueDebugEvent(de.dwProcessId, de.dwThreadId, dwCS);
	}
}
