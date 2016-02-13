/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef _STU_UIC
#define _STU_UIC

/*-----------------------------------------------------

				RollRat Data Structure

-----------------------------------------------------*/

#define DS_TYPE				char **

typedef unsigned char       BYTE;	// 0x      FF
typedef unsigned short      WORD;	// 0x    FFFF
typedef unsigned long       DWORD;	// 0xFFFFFFFF

#define _NO_USING							(BYTE)(0x00)
#define _USING								(BYTE)(0xff)

#define _BYTE(xt)							(BYTE)(xt)
#define _WORD(xt)							(WORD)(xt)
#define _DWORD(xt)							(DWORD)(xt)

#define _WORD_SMALL_ENDIAN(xt)				(((xt & 0xff00) >> 8) | (xt & 0x00ff))
#define _DWORD_SMALL_ENDIAN(xt)				((xt & 0xff << 24) >> 24 | (xt & 0xff << 16) >> 8 | (xt & 0xff << 8) << 8 | (xt & 0xff) << 24)

#define _ROLLRAT_DATA_STRUCTURE_SIGNATURE	(DWORD)(0x52004453)		// "R DS"

//
//	Image Standard Header Structure
//
typedef struct _IMAGE_STD_HEADER {
	DWORD	el_sign;					// ISH sign
	WORD	el_isz;						// Image std header size
	BYTE	el_itdf;					// Data array rule(IsThisDataForward)
	BYTE	el_uds;						// Inside structure for data list(UsingDataStructure)
	BYTE	el_etype;					// Set endian type
	DWORD	el_mslad;					// Main section start address(RVA)
}	IMAGE_STD_HEADER, *PTR_IMAGE_STD_HEADER;
#define IMAGE_STD_HEADER_SIZE				sizeof(IMAGE_STD_HEADER)

//
//	Data Array Rule
//
#define IMAGE_STD_DATAARRAYRULE_FORWARD		(BYTE)(0x01)
#define IMAGE_STD_DATAARRAYRULE_BACKWARD	(BYTE)(0x02)
#define IMAGE_STD_DATAARRAYRULE_SEARCH		(BYTE)(0x03)
#define IMAGE_STD_DATAARRAYRULE_STANDARD	(BYTE)(0x04)
#define IMAGE_STD_DATAARRAYRULE_GROUP		(BYTE)(0x05)

//
//	Endian Type
//
#define IMAGE_STD_ENDIANTYPE_INTEL32		(BYTE)(0x00)	// Small endian
#define IMAGE_STD_ENDIANTYPE_BIGENDIAN		(BYTE)(0x01)	// Big endian
#define IMAGE_STD_ENDIANTYPE_DEFAULE		(BYTE)(0x02)	// Default Set

/*=====================================

	Image Sections Header

	.List, .Data, .Array(Structure)
	.PassWord, .Note

=====================================*/

typedef struct _IMAGE_MAIN_SECTIONS_HEADER {
	WORD	SectionTime;				// How many be sections(Max 5, B 1)
	DWORD	SectionAddress[5];			// Chile section connect address
	DWORD	DataSize;					// File Size or Last Pointer of Data
	BYTE	Separation;					// Division character(Normal 0)
	WORD	GroupingTrue;				// Using Array Structure
	WORD	GroupingSize;				// Set grouping size(if GT <> 0)
	WORD	SimpleListSection;			// Save space by save list section
	WORD	PassWordTrue;				// Using PassWord Algorithm
	WORD	UsingNote;					// Note to user before access
	WORD	UsingUnicodeForData;		// Using unicode data
}	IMAGE_MAIN_SECTIONS_HEADER, *PTR_IMAGE_MAIN_SECTIONS_HEADER;
#define IMAGE_MAIN_SECTIONS_HEADER_SIZE		sizeof(IMAGE_MAIN_SECTIONS_HEADER)


typedef struct _IMAGE_SECTIONS_HEADER {
	BYTE	SectionName[8];				// Put secton name
	DWORD	Option;						// Put Option
	DWORD	MainAddress;				// Section's Main Address
	DWORD	SectionSize;				// Section size
	BYTE	SectionSeparation;			// Division character(Normal 0)
	WORD	MakeVirtualAddress;			// Make virtual address
	WORD	SearchData;					// Only use search algorithm
	WORD	PassWordTrue;				// Using PassWord Algorithm(Warning!)
	DWORD	PassWordKey;				// Password Key(Simple Key)
	BYTE	GroupingHighSeparation;		// Grouping  high Separation Character
	BYTE	GroupingLowSeparation;		// Grouping low Separation Character
	WORD	GroupTheNumber;				// The Number of Group
	DWORD	SzData[4];					// Be used for sections header data
	DWORD	OutputRule;					// Output way
	DWORD	DataStoreRule;				// Data Store Rule
	WORD	DataTheNumber;				// The Number of Data
	BYTE	AskBeforeAccess;			// Ask Before Access
}	IMAGE_SECTIONS_HEADER, *PTR_IMAGE_SECTIONS_HEADER;
#define IMAGE_SECTIONS_HEADER_SIZE			sizeof(IMAGE_SECTIONS_HEADER)

//
//	Data Store Rule	(with Overlap, Order, and )
//
#define IMAGE_SECTIONS_DATASTROERULE_STANDARD		(WORD)(0x0000)
#define IMAGE_SECTIONS_DATASTROERULE_REVERSE		(WORD)(0x0001)	// Endian Reverse
#define IMAGE_SECTIONS_DATASTROERULE_REPLACEBIT		(WORD)(0x0002)	// Example 2A => A2
#define IMAGE_SECTIONS_DATASTORERULE_GROUPREVERSE	(WORD)(0x0004)
#define IMAGE_SECTIONS_DATASTORERULE_PARALLER		(WORD)(0x0008)

void stdsetish(PTR_IMAGE_STD_HEADER gx);
void stdsetimsh(PTR_IMAGE_MAIN_SECTIONS_HEADER gx);
void stdsetishe(PTR_IMAGE_SECTIONS_HEADER gx);

char *ishtostr(IMAGE_STD_HEADER gx);
void strtoish(PTR_IMAGE_STD_HEADER gx, const char *x);
char *imshtostr(IMAGE_MAIN_SECTIONS_HEADER gx);
void strtoimsh(PTR_IMAGE_MAIN_SECTIONS_HEADER gx, const char *x);
char *ishetostr(IMAGE_SECTIONS_HEADER gx);
void strtoishe(PTR_IMAGE_SECTIONS_HEADER gx, const char *x);

char *make(IMAGE_STD_HEADER x, IMAGE_MAIN_SECTIONS_HEADER y, 
		   IMAGE_SECTIONS_HEADER z, const DS_TYPE a);

#endif