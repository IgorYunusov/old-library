#include <Windows.h>
#include <iostream>
BOOL EqualsMajorVersion(DWORD majorVersion)
{
    OSVERSIONINFOEX osVersionInfo;
    ::ZeroMemory(&osVersionInfo, sizeof(OSVERSIONINFOEX));
    osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    osVersionInfo.dwMajorVersion = majorVersion;
    ULONGLONG maskCondition = ::VerSetConditionMask(0, VER_MAJORVERSION, VER_EQUAL);
    return ::VerifyVersionInfo(&osVersionInfo, VER_MAJORVERSION, maskCondition);
}

BOOL EqualsMinorVersion(DWORD minorVersion)
{
    OSVERSIONINFOEX osVersionInfo;
    ::ZeroMemory(&osVersionInfo, sizeof(OSVERSIONINFOEX));
    osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    osVersionInfo.dwMinorVersion = minorVersion;
    ULONGLONG maskCondition = ::VerSetConditionMask(0, VER_MINORVERSION, VER_EQUAL);
    return ::VerifyVersionInfo(&osVersionInfo, VER_MINORVERSION, maskCondition);
}
BOOL EqualsServicePack(WORD servicePackMajor)
{
    OSVERSIONINFOEX osVersionInfo;
    ::ZeroMemory(&osVersionInfo, sizeof(OSVERSIONINFOEX));
    osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    osVersionInfo.wServicePackMajor = servicePackMajor;
    ULONGLONG maskCondition = ::VerSetConditionMask(0, VER_SERVICEPACKMAJOR, VER_EQUAL);
    return ::VerifyVersionInfo(&osVersionInfo, VER_SERVICEPACKMAJOR, maskCondition);
}

BOOL EqualsProductType(BYTE productType)
{
    OSVERSIONINFOEX osVersionInfo;
    ::ZeroMemory(&osVersionInfo, sizeof(OSVERSIONINFOEX));
    osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    osVersionInfo.wProductType = productType;
    ULONGLONG maskCondition = ::VerSetConditionMask(0, VER_PRODUCT_TYPE, VER_EQUAL);
    return ::VerifyVersionInfo(&osVersionInfo, VER_PRODUCT_TYPE, maskCondition);
}

BYTE GetProductType()
{
    if (EqualsProductType(VER_NT_WORKSTATION))
    {
        return VER_NT_WORKSTATION;
    }
    else if (EqualsProductType(VER_NT_SERVER))
    {
        return VER_NT_SERVER;
    }
    else if (EqualsProductType(VER_NT_DOMAIN_CONTROLLER))
    {
        return VER_NT_DOMAIN_CONTROLLER;
    }
    return 0;//unkown
}  
struct WindowsNTOSInfo
{
    DWORD dwMajorVersion;
    DWORD dwMinorVersion;
    WORD wServicePackMajor;    
    //const TCHAR * pcszOSDisplayName;
};

struct WindowsNTOSInfoEx :WindowsNTOSInfo
{
    BYTE ProductType;
};

const WindowsNTOSInfo KnownVersionsOfWindows[] =
{
    { 6, 3, 0,   },	//win8.1,server2012 r2
    { 6, 2, 0,   },	//win8,server2012

    { 6, 1, 1,  },	//win7,win2008r2 sp1
    { 6, 1, 0,  },	//win7,win2008r2

    { 5, 1, 3,  },	//winxp sp3
    { 5, 1, 2,  },	//winxp sp2
    { 5, 1, 1,  },	//winxp sp1
    { 5, 1, 0,  },	//winxp

    { 6, 0, 2,  },	//WinVista,server2008 SP2
    { 6, 0, 1,  },	//WinVista,Server2008 Sp1
    { 6, 0, 0,  },	//WinVista,Server2008

    { 5, 2, 2,  },	//Windows Server 2003 Sp2
    { 5, 2, 1,  },	//Windows Server 2003 Sp1
    { 5, 2, 0,  },	//Windows Server 2003

    { 5, 1, 4,  },	//Windows Server 2000 Sp4
    { 5, 1, 3,  },	//Windows Server 2000 Sp3
    { 5, 1, 2,  },	//Windows Server 2000 Sp2
    { 5, 1, 2,  },	//Windows Server 2000 Sp1
    { 5, 1, 0,  },	//Windows Server 2000
};

const size_t n_KnownVersionofWindows = sizeof(KnownVersionsOfWindows) / sizeof(WindowsNTOSInfo);
bool GetKnownWindowsVersion(WindowsNTOSInfoEx& osInfo)
{
    for (size_t i = 0; i < n_KnownVersionofWindows; i++)
    {
        if (EqualsMajorVersion(KnownVersionsOfWindows[i].dwMajorVersion))
        {
            if (EqualsMinorVersion(KnownVersionsOfWindows[i].dwMinorVersion))
            {
                if (EqualsServicePack(KnownVersionsOfWindows[i].wServicePackMajor))
                {
                    osInfo.dwMajorVersion = KnownVersionsOfWindows[i].dwMajorVersion;
                    osInfo.dwMinorVersion = KnownVersionsOfWindows[i].dwMinorVersion;
                    osInfo.wServicePackMajor = KnownVersionsOfWindows[i].wServicePackMajor;
                    osInfo.ProductType = GetProductType();
                    return true;
                }
            }
        }
    }
    return false;
}
const DWORD MajorVersion_Start = 6;
const DWORD MinorVersion_Start = 3;
const WORD ServicePackVersion_Start = 1;

const DWORD MajorVersion_Max = 10;
const DWORD MinorVersion_Max = 5;
const WORD ServicePackVersion_Max = 4;

bool GetUnkownVersion(WindowsNTOSInfoEx& osInfo)
{
    DWORD minorVersionCounterSeed = MinorVersion_Start;
    DWORD servicePackCounterSeed = ServicePackVersion_Start;
    //by design, if we can't find the right service pack we will return true;
    for (DWORD majorVersion = MajorVersion_Start; majorVersion <= MajorVersion_Max; majorVersion++)
    {
        if (EqualsMajorVersion(majorVersion))
        {
            for (DWORD minorVersion = minorVersionCounterSeed; 
                    minorVersion <= MinorVersion_Max; minorVersion++)
            {
                if (EqualsMinorVersion(minorVersion))
                {
                    osInfo.dwMajorVersion = majorVersion;
                    osInfo.dwMinorVersion = minorVersion;
                    osInfo.ProductType = GetProductType();
                    for (WORD servicePack = servicePackCounterSeed; 
                           servicePack <= ServicePackVersion_Max; servicePack++)
                    {
                        if (EqualsServicePack(servicePack))
                        {                            
                            osInfo.wServicePackMajor = servicePack;
                            break;
                        }
                    }
                    return true;
                }
                else
                {
                    //reset servicepack version counter to 0 because
                    //we are going to increment our minor version.
                    servicePackCounterSeed = 0;
                }                
            }
        }
        else
        {
            //reset minor version to start from 0 because we are going to increment majorVersion;
            minorVersionCounterSeed = 0;
        }
    }
    return false;
}
bool GetWindowsVersion(WindowsNTOSInfoEx& osInfo)
{
   /* bool capturedWinVersion = GetKnownWindowsVersion(osInfo);
    if (!capturedWinVersion)
    {*/
        return GetUnkownVersion(osInfo);
   /* }
    return capturedWinVersion;*/
}

OSVERSIONINFOEX GetKernelVersion()
{
   /* OSVERSIONINFOEX osVersionInfo;
    ::ZeroMemory(&osVersionInfo, sizeof(OSVERSIONINFOEX));
    osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    osVersionInfo.dwMinorVersion = minorVersion;
    ULONGLONG maskCondition = ::VerSetConditionMask(0, VER_MINORVERSION, VER_EQUAL);
    return ::VerifyVersionInfo(&osVersionInfo, VER_MINORVERSION, maskCondition);*/
	int kernelVerMajor = 10, kernelVerMinor = 5, kernelVerServie = 5;
	OSVERSIONINFOEX osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	ULONGLONG maskCondition = ::VerSetConditionMask(0, VER_MINORVERSION, VER_EQUAL);
	/*if (VerifyVersionInfo(&osvi, VER_MINORVERSION, maskCondition))
		break;*/
	for(DWORD kvmj = 0; kvmj < kernelVerMajor; kvmj++)
	{
		osvi.dwMajorVersion = kvmj;
		if(VerifyVersionInfo(&osvi, VER_SERVICEPACKMAJOR, maskCondition))
			for(DWORD kvmi = 0; kvmi < kernelVerMinor; kvmi++)
			{
				osvi.dwMinorVersion = kvmi;
				if(VerifyVersionInfo(&osvi, VER_SERVICEPACKMAJOR, maskCondition))
				for(WORD kvs = 0; kvs < kernelVerServie; kvs++)
				{
					osvi.wServicePackMajor = kvs;
					if (VerifyVersionInfo(&osvi, VER_SERVICEPACKMAJOR, maskCondition))
						return osvi;
				}
			}
	}

	//GetWindowsVersion(osvi);
	return osvi;
}



int main()
{
	WindowsNTOSInfoEx x;
	GetWindowsVersion(x);
	std::cout << GetKernelVersion().dwMajorVersion;
	return 0;
}