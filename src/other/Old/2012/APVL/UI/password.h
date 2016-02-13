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

#ifndef __APVL_PASSWORD
#define __APVL_PASSWORD

// ROLLRAT PASSWORD SYSTEM V 1.0 with C++

/*********************************************

	NOTICE :
	Before include, declared '_PASS_WORD'.

	EX)
	#define _PASS_WORD "rollrat"

*********************************************/

#ifndef _PASS_WORD
#error Check Notice.
#define _PASS_WORD		0
#endif

// Input for users only(not programmer)
#define _In_User_

// for programmer only
#define _In_Prog_

template<class _Ty01> struct
	ridof_pointer
	{ // remove pointer
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct
	ridof_pointer<_Ty01*>
	{ // remove pointer
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct
	ridof_pointer<_Ty01[]>
	{ // remove pointer
	typedef typename _Ty01 type;
	};

#define _APVL_UI_PASSWORDSYS_ALP	"abcdefghijklmnopqrstuvwxyz"

#define _HASH		unsigned long long

#define GetBytePos(_x, x) (_x & (0xff << (x << 2 + 1)))
#define GetWordPos(_x, x) (_x & (0xffff << (x << 4)))
#define GetByteFromPos(_x, x) (GetBytePos(_x, x) >> (x << 2 + 1))
#define GetWordFromPos(_x, x) (GetWordPos(_x, x) >> (x << 4))

#define _LBYTE(_x) ((unsigned char)_x)
#define _HBYTE(_x) ((unsigned short)_x >> 8 & 0xff)

template<class _Input_Stream_ = unsigned char *> class Slot
{
	typedef typename ridof_pointer<_Input_Stream_>::type _MyUTP;
public:

	//////////////////////////
	// Component of hash	//
	//////////////////////////
	// 0xAABBCCDDEEFFGGHH	//
	// AA	: Message Type	// 6
	// BB	: High Param	// 5
	// CC	: Low Param		// 4
	// DD	: Hash Type		// 3
	// EEFF : Store Key		// 2
	// GGHH	: Access Code	// 1 0
	//////////////////////////



	_MyUTP make_table(_HASH _hash_msg, ... )
	{

	}

private:
	_MyUTP *utp;
};

#define _APVL_UI_PASSWRODSYS_MESSAGE		0x001F

#endif