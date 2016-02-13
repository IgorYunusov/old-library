#include "tree.h"

#include <iostream>
#include <cstring>

#include "matrix.h"
#include "equation.h"
#include "ultra.h"

int main()
{
	////std::stack<int> yacc;
	//stack<int> yacc;
	//structure<> A;
	//yacc.push(10);
	//yacc.push(12);
	//A("asdfasdf", IN(yacc));
	//std::cout << OUT(A["asdfasdf"], stack<int>)top() << std::endl;
	//std::cout << yacc.top() << std::endl;
	//yacc.pop();
	//std::cout << yacc.top() << std::endl;
	//yacc.pop();
	//xtree<int> treex;
	//treex.push_left(10);
	//treex.push_right(11);
	//xtree<int>::in_order_iterator ioi(*treex);
	//ioi++;
	//xtree<int>::leaf_iterator T(treex._Current->_First);
	//xtree<int>::leaf_analyzer yT(*treex);
	////yT.save();
	//yT._find(10);
	//T++;
	//*T;
	//treex.into(0);
	////treex.escape();
	//std::cout << treex.hookstack()._Stack->_Data->_Data << std::endl;
	////std::cout << treex.hookstack()._Stack->_Next->_Data->_Data << std::endl;
	////std::cout << treex[1] << std::endl;

	Matrix<> t5(5);

	t5.new_row(3);
	t5.new_column(3);
	
	t5(0, 0) = 2;
	
	t5 = t5 * t5;



	std::cout << t5(0, 0);

	Equation<int> t;
	t.push(5, 4);
	t=t + t;

	UltraUnsignedInteger<> Int;

	for (int i = 0; i <= 500; i++)
		Int += "9997613213";

	std::cout << *Int << std::endl;
	Int += "99";

	std::cout << *Int << std::endl;

	// x=1 y=2
	
	/*Unrolling<4, decltype(_t)>::Do(_t);*/

	std::cout << (char)('T' ^ 0x20) << std::endl;

	std::cout << (int)('0' & 0xf) << std::endl;

	return 0;
}

int makin()
{
	char words[100000] = "lloololoollloo";
	char target[36] = "lo";
	char save[100000];

	char * wordst = words;
	char * targett = target;

	int i = 0, t = 0;

AGAIN:

	for(t = 0; *wordst; )
	{
		if (*wordst == *targett)
		{
			if (strncmp(wordst, targett, strlen(targett)) == 0)
			{
				for (; *targett; targett++, wordst++)
					;
				targett = target;
				t++;
				continue;
			}
			else
				save[i++] = *wordst;
		}
		else
			save[i++] = *wordst;

		wordst++;
	}
	
	save[i] = '\0';

	if (t)
	{
		wordst = save;
		i = 0;
		goto AGAIN;
	}


	std::cout << save << std::endl;
}

#include <stdio.h>
 
int exp();
int factor();
 
const char *variable;

int var()
{
    int tmp = exp();
    while((*variable == '+') || (*variable == '-'))
	{
        if(*variable == '+') 
        {
            variable++;
            tmp = tmp + exp();
        }
        else if(*variable == '-')
        {
            variable++;
            tmp = tmp - exp(); 
        }
	}
    return tmp;
}
 
int exp()
{
    int tmp = factor();
    while(*variable == '*' || *variable == '/')
	{
        switch(*variable)
        {
        case '*':
            variable++;
            tmp *= factor();
            break;
        case '/':
            variable++;
            tmp /= factor();
            break;
        }
	}
    return tmp;
}
 
int factor()
{
    int tmp = 0;
    if (*variable == '(')
    {
        variable++;
        tmp = var();
        if (*variable == ')')
        {
            variable++;
            return tmp;
        }
    }
	else if ('0' <= *variable && *variable <= '9')
	{
		while (true)
		{
			if ('0' <= *variable && *variable <= '9')
			{
				tmp *= 10;
				tmp += *variable & 0xf;
				variable++;
			}
			else
				break;
		}
		return tmp;
	}


}
 



































//
//#include <Windows.h>
//
//char * ReadSectors(int drive, DWORD startinglogicalsector, int numberofsectors)
//{
//
//	// All msdos data structures must be packed on a 1 byte boundary
//#pragma pack (1)
//	struct
//	{
//		DWORD StartingSector;
//		WORD NumberOfSectors;
//		DWORD pBuffer;
//	}ControlBlock;
//#pragma pack ()
//
//#pragma pack (1)
//	typedef struct _DIOC_REGISTERS
//	{
//		DWORD reg_EBX;
//		DWORD reg_EDX;
//		DWORD reg_ECX;
//		DWORD reg_EAX;
//		DWORD reg_EDI;
//		DWORD reg_ESI;
//		DWORD reg_Flags;
//	} DIOC_REGISTERS;
//#pragma pack ()
//
//	char* buffer = (char*)malloc(512 * numberofsectors);
//	HANDLE hDevice;
//	DIOC_REGISTERS reg;
//	BOOL  fResult;
//	DWORD cb;
//
//	// Creating handle to vwin32.vxd (win 9x)
//	hDevice = CreateFile("\\\\.\\vwin32",
//		0,
//		0,
//		NULL,
//		0,
//		FILE_FLAG_DELETE_ON_CLOSE,
//		NULL);
//
//	if (hDevice == INVALID_HANDLE_VALUE)
//	{
//		// win NT/2K/XP code 
//		HANDLE hDevice;
//		DWORD bytesread;
//
//		char _devicename[] = "\\\\.\\A:";
//		_devicename[4] += drive;
//
//		// Creating a handle to disk drive using CreateFile () function ..
//		hDevice = CreateFile(_devicename,
//			GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
//			NULL, OPEN_EXISTING, 0, NULL);
//
//		if (hDevice == INVALID_HANDLE_VALUE)
//			return NULL;
//
//		// Setting the pointer to point to the start of the sector we want to read ..
//		SetFilePointer(hDevice, (startinglogicalsector * 512), NULL, FILE_BEGIN);
//
//		if (!ReadFile(hDevice, buffer, 512 * numberofsectors, &bytesread, NULL))
//			return NULL;
//	}
//	else
//	{
//		// code for win 95/98
//		ControlBlock.StartingSector = (DWORD)startinglogicalsector;
//		ControlBlock.NumberOfSectors = (DWORD)numberofsectors;
//		ControlBlock.pBuffer = (DWORD)buffer;
//
//		//-----------------------------------------------------------
//		// SI contains read/write mode flags
//		// SI=0h for read and SI=1h for write
//		// CX must be equal to ffffh for
//		// int 21h's 7305h extention
//		// DS:BX -> base addr of the
//		// control block structure
//		// DL must contain the drive number
//		// (01h=A:, 02h=B: etc)
//		//-----------------------------------------------------------
//
//		reg.reg_ESI = 0x00;
//		reg.reg_ECX = -1;
//		reg.reg_EBX = (DWORD)(&ControlBlock);
//		reg.reg_EDX = drive + 1;
//		reg.reg_EAX = 0x7305;
//
//		//  6 == VWIN32_DIOC_DOS_DRIVEINFO
//		fResult = DeviceIoControl(hDevice,
//			6,
//			&(reg),
//			sizeof (reg),
//			&(reg),
//			sizeof (reg),
//			&cb,
//			0);
//
//		if (!fResult || (reg.reg_Flags & 0x0001)) return NULL;
//	}
//
//	CloseHandle(hDevice);
//	return buffer;
//}