
/****************************************************************
 *                *
 *                *
 *   ROLLRAT AUTO PERSONA VERBOTER LIBROFEX    *
 *                *
 *                *
 *  COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.  *
 *                *
 *                *
 ****************************************************************/

#ifndef __ASLO_PE
#define __ASLO_PE

#include <windows.h>

///*---------------------------------------------------------------
//
//	 Apvl String Local Origin
//
//	 ---------------------------------------------------------------*/
//
//// The Portable Executable File Format
//
//#define GetByte(xt) (BYTE)(*xt)
//#define GetWord(xt) (WORD)(*xt << 8 | *(xt + 1))
//#define GetDWord(xt) (DWORD)((DWORD)(((WORD)(*xt << 8 | *(xt + 1))) << 16) | \
//	(DWORD)(((WORD)(*(xt + 2) << 8 | *(xt + 3)))))
//#define up2(t)  t += 2;
//#define up4(t)  t += 4;
//
//#define SEndian4(tx) ((tx & 0xff) << 8) | ((tx & 0xff00) >> 8)
//#define SEndian8(tx) ((tx & 0xff) << 24) | ((tx & 0xff00) << 8) \
//	| ((tx & 0xff0000) >> 8) | ((tx & 0xff000000) >> 24)
//
///****************************************
// Mark Zbikowski DOS MZ executable
// ****************************************/
//
//#define MZ_MAGIC (WORD)(0x4D00 | 0x5A)
//typedef IMAGE_DOS_HEADER ASLO_IDH;
//
////***********************************************
//// FILL IDH STRUCTURE
////***********************************ROLLRAT ASLO
//void FillIDH(ASLO_IDH *x, char *szData)
//{
//	char *low_char = szData;
//	int i;
//	x->e_magic = MZ_MAGIC;
//	up2(low_char) x->e_cblp = GetWord(low_char);  // Bytes on last page of file
//	up2(low_char) x->e_cp = GetWord(low_char);   // Pages in file
//	up2(low_char) x->e_crlc = GetWord(low_char);  // Relocations
//	up2(low_char) x->e_cparhdr = GetWord(low_char);  // Size of header in paragraphs
//	up2(low_char) x->e_minalloc = GetWord(low_char); // Minimum extra paragraphs needed
//	up2(low_char) x->e_maxalloc = GetWord(low_char); // Maximum extra paragraphs needed
//	up2(low_char) x->e_ss = GetWord(low_char);   // Initial (relative) SS value
//	up2(low_char) x->e_sp = GetWord(low_char);   // Initial SP value
//	up2(low_char) x->e_csum = GetWord(low_char);  // Checksum
//	up2(low_char) x->e_ip = GetWord(low_char);   // Initial IP value
//	up2(low_char) x->e_cs = GetWord(low_char);   // Initial (relative) CS value
//	up2(low_char) x->e_lfarlc = GetWord(low_char);  // File address of relocation table
//	up2(low_char) x->e_ovno = GetWord(low_char);  // Overlay number
//	up2(low_char)
//	for (i = 0; i < 4; i++, low_char += 2)
//		x->e_res[i] = GetWord(low_char);   // Reserved words
//	x->e_oemid = GetWord(low_char);      // OEM identifier (for e_oeminfo)
//	up2(low_char) x->e_oeminfo = GetWord(low_char);  // OEM information; e_oemid specific
//	up2(low_char)
//	for (i = 0; i < 10; i++, low_char += 2)
//		x->e_res2[i] = GetWord(low_char);   // Reserved words
//	x->e_lfanew = SEndian8(GetDWord(low_char));   // File address of new exe header
//}
//
//
///****************************************
// The Portable Executable File Format
// ****************************************/
//
//#define PE_SIGN  (DWORD)(0x50450000)
//typedef IMAGE_NT_HEADERS32 ASLO_INH32;
//typedef IMAGE_NT_HEADERS64 ASLO_INH64;
//typedef IMAGE_SECTION_HEADER ASLO_ISH;
//
//void FillINH32(ASLO_INH32 *x, char *szData)
//{
//	char *lc = szData;
//	int i;
//	IMAGE_FILE_HEADER FileHeader;
//	IMAGE_OPTIONAL_HEADER32 OptionalHeader;
//	IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
//	x->Signature = PE_SIGN;
//	/////////////////////////////////////////
//	up4(lc) FileHeader.Machine = SEndian4(GetWord(lc));
//	up2(lc) FileHeader.NumberOfSections = SEndian4(GetWord(lc));
//	up2(lc) FileHeader.TimeDateStamp = SEndian8(GetDWord(lc));
//	up4(lc) FileHeader.PointerToSymbolTable = SEndian8(GetDWord(lc));
//	up4(lc) FileHeader.NumberOfSymbols = SEndian8(GetDWord(lc));
//	up4(lc) FileHeader.SizeOfOptionalHeader = SEndian4(GetWord(lc));
//	up2(lc) FileHeader.Characteristics = SEndian4(GetWord(lc));
//	x->FileHeader = FileHeader;
//	/////////////////////////////////////////
//	up2(lc) OptionalHeader.Magic = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.MajorLinkerVersion = (BYTE)(SEndian4(GetWord(lc)) >> 2);
//	OptionalHeader.MinorLinkerVersion = (BYTE)(SEndian4(GetWord(lc)) & 0xff);
//	up2(lc) OptionalHeader.SizeOfCode = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.SizeOfInitializedData = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.SizeOfUninitializedData = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.AddressOfEntryPoint = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.BaseOfCode = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.BaseOfData = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.ImageBase = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.SectionAlignment = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.FileAlignment = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.MajorOperatingSystemVersion = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.MinorOperatingSystemVersion = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.MajorImageVersion = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.MinorImageVersion = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.MajorSubsystemVersion = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.MinorSubsystemVersion = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.Win32VersionValue = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.SizeOfImage = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.SizeOfHeaders = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.CheckSum = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.Subsystem = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.DllCharacteristics = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.SizeOfStackReserve = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.SizeOfStackCommit = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.SizeOfHeapReserve = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.SizeOfHeapCommit = SEndian8(GetDWord(lc));
//	up4(lc) OptionalHeader.LoaderFlags = SEndian4(GetWord(lc));
//	up2(lc) OptionalHeader.NumberOfRvaAndSizes = SEndian4(GetWord(lc));
//	/////////////////////////////////////////
//	for (i = 0; i < 16; i++, lc += 4)
//	{
//		OptionalHeader.DataDirectory[i].VirtualAddress = SEndian8(GetDWord(lc));
//		up4(lc)
//			OptionalHeader.DataDirectory[i].Size = SEndian8(GetDWord(lc));
//	}
//	/////////////////////////////////////////
//	x->OptionalHeader = OptionalHeader;
//}
//
//void FillISH(ASLO_ISH *x, char *szData)
//{
//	char *lc = szData;
//	int i;
//	for (i = 0; i < 8; i++, lc++)
//		x->Name[i] = GetByte(lc);
//	// x->Misc.PhysicalAddress = SEndian8(GetDWord(lc));
//	/* up4(lc) */ x->Misc.VirtualSize = SEndian8(GetDWord(lc));
//	up4(lc) x->VirtualAddress = SEndian8(GetDWord(lc));
//	up4(lc) x->SizeOfRawData = SEndian8(GetDWord(lc));
//	up4(lc) x->PointerToRawData = SEndian8(GetDWord(lc));
//	up4(lc) x->PointerToRelocations = SEndian8(GetDWord(lc));
//	up4(lc) x->PointerToLinenumbers = SEndian8(GetDWord(lc));
//	up4(lc) x->NumberOfRelocations = SEndian4(GetWord(lc));
//	up2(lc) x->NumberOfLinenumbers = SEndian4(GetWord(lc));
//	up2(lc) x->Characteristics = SEndian8(GetDWord(lc));
//}
//
//DWORD GetRWA(ASLO_ISH x)
//{
//	return x.VirtualAddress - x.VirtualAddress + x.PointerToRawData;
//}

#define MZ_MAGIC (WORD)(0x5A00 | 0x4D)//(WORD)(0x4D00 | 0x5A)

#define PE_SIGNATURE	(DWORD)(0x00004550)

class pe32
	{
public:
	IMAGE_DOS_HEADER *idh;
	IMAGE_NT_HEADERS32 *inh32;
	IMAGE_NT_HEADERS64 *inh64;
	IMAGE_SECTION_HEADER **ish;
	DWORD EP_RVA;
	DWORD IMAGE_BASE;
	DWORD IMAGE_SIZE;
	int SUBSYSTEM;
	DWORD EP_ORIGIN;

	const BYTE *t;

	pe32(const BYTE *program)
		: t(program)
		{
		idh = new IMAGE_DOS_HEADER;

		for (int i = 0; i < sizeof(IMAGE_DOS_HEADER); i++)
			((BYTE *)(void *)idh)[i] = t[i];

		if (idh->e_magic != MZ_MAGIC)
			throw(MZ_MAGIC);

		inh32 = new IMAGE_NT_HEADERS32;

		for (int i = idh->e_lfanew, j = 0; i < sizeof(IMAGE_NT_HEADERS32) + idh->e_lfanew; i++, j++)
			((BYTE *)(void *)inh32)[j] = t[i];

		if (inh32->Signature != PE_SIGNATURE)
			throw(PE_SIGNATURE);

		if (inh32->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR32_MAGIC)
			throw(IMAGE_NT_OPTIONAL_HDR32_MAGIC);

		EP_RVA = inh32->OptionalHeader.AddressOfEntryPoint;

		IMAGE_BASE = inh32->OptionalHeader.ImageBase;
		IMAGE_SIZE = inh32->OptionalHeader.SizeOfImage;
		SUBSYSTEM = inh32->OptionalHeader.Subsystem;

		ish = new IMAGE_SECTION_HEADER*[inh32->FileHeader.NumberOfSections];

		for (int i = 0; i < inh32->FileHeader.NumberOfSections; i++)
			ish[i] = new IMAGE_SECTION_HEADER;

		for (int i = 0, k = idh->e_lfanew + sizeof(IMAGE_NT_HEADERS32); i < inh32->FileHeader.NumberOfSections; i++)
			{
			for(int j = 0; j < sizeof(IMAGE_SECTION_HEADER); j++, k++)
				((BYTE *)(void *)ish[i])[j] = t[k];
			}

		EP_ORIGIN = EP_RVA - (*ish)->VirtualAddress + (*ish)->PointerToRawData;
		}

	DWORD cal_CALL_addr(DWORD addr)
		{

		}

private:

	bool check_NOS()
		{
		return inh32->FileHeader.NumberOfSections > 0;
		}

	};

#endif