/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_UTIL_
#define _ROLLRAT_UTIL_
#
#	// basically defined
#
#ifndef __DESCRIPT_STDCALL
#	define __DESCRIPTION_STDCALL		__stdcall
#else
#	undef __DESCRIPTION_STDCALL			__stdcall
#	define __DESCRIPTION_STDCALL		__stdcall
#endif
#
#ifndef __DESCRIPTION_CDECL
#	define __DESCRIPTION_CDECL			__cdecl
#else
#	undef __DESCRIPTION_CDECL			__cdecl
#	define __DESCRIPTION_CDECL			__cdecl
#endif
#
#ifndef __DESCRIPTION_FASTCALL
#	define __DESCRIPTION_FASTCALL		__fastcall
#else
#	undef __DESCRIPTION_FASTCALL		__fastcall
#	define __DESCRIPTION_FASTCALL		__fastcall
#endif
#
#ifndef __DESCRIPT_CLRCALL
#	define __DESCRIPT_CLRCALL			__clrcall
#else
#	undef __DESCRIPT_CLRCALL			__fastcall
#	define __DESCRIPT_CLRCALL			__fastcall
#endif
#
#if !defined(_UNDEF_NAMESPACE) && defined(__cplusplus)
#
#	// The namespace of rollrat library.
#
#	ifndef _X_LIB
#			define	_X_LIB_BEGIN	namespace xlib	{
#			define	_X_LIB_END		}
#			define	_X_LIB			::xlib::
#		else
#			undef	_X_LIB_BEGIN
#			undef	_X_LIB_END
#			undef	_X_LIB
#			define	_X_LIB_BEGIN	namespace xlib	{
#			define	_X_LIB_END		}
#			define	_X_LIB			::xlib::
#	endif
#	ifndef _X_UTIL
#			define	_X_UTIL_BEGIN	namespace xutil	{
#			define	_X_UTIL_END		}
#			define	_X_UTIL			::xutil::
#		else
#			define	_X_UTIL_BEGIN
#			define	_X_UTIL_END
#			define	_X_UTIL
#			define	_X_UTIL_BEGIN	namespace xutil	{
#			define	_X_UTIL_END		}
#			define	_X_UTIL			::xutil::
#	endif
#
#else
#
#	// The regularly expression of rollrat library.
#
#	if defined(_X_LIB)
#		undef	_X_LIB
#		define	_X_LIB
#		if defined(_X_LIB_BEGIN) || defined(_X_LIB_END)
#			undef	_X_LIB_BEGIN
#			define	_X_LIB_BEGIN
#			undef	_X_LIB_END
#			define	_X_LIB_END
#		endif
#	else
#		define	_X_LIB
#		define	_X_LIB_BEGIN
#		define	_X_LIB_END
#	endif
#	if defined(_X_UTIL)
#		undef	_X_UTIL
#		define	_X_UTIL
#		if defined(_X_UTIL_BEGIN) || defined(_X_UTIL_END)
#			undef	_X_UTIL_BEGIN
#			define	_X_UTIL_BEGIN
#			undef	_X_UTIL_END
#			define	_X_UTIL_END
#		endif
#	else
#		define	_X_UTIL
#		define	_X_UTIL_BEGIN
#		define	_X_UTIL_END
#	endif
#
#endif
#
#ifndef _SIZE_T_DEFINED
#ifdef  _WIN64
typedef unsigned __int64    size_t;
#else
typedef _w64 unsigned int   size_t;
#endif
#define _SIZE_T_DEFINED
#endif
#
#if defined(__cplusplus)
#
#	// the Access Right
#
#	define _EX_SUCCESS
#	define _EX_TEMPLATE_ALL
#	define _EX_TEMPLATE_MT
#	define _EX_TEMPLATE_CONTENT
#
#endif
#
#// Template Level
#define _CCC_A_TEMPLATE_CS	// simple struct or class
#define _CCC_B_TEMPLATE_CS	// usually
#define _CCC_C_TEMPLATE_CS	// hard coding struct or class
#
#// Acces Information
#define _ELF_ACCESS
#define _ELF_COMMON
#define _ELF_PASS
#
#// License Information
#define _ELF_LICENSE_NUMBER_CODE_EX
#define _ELF_LICENSE_ACCESS_CODE_EX
#
#// typedef struct
#define STR_TD	typedef struct
#define STR_PUBLICQ public:
#
#// int type
#define INT_MAX		0xffffffff
#define INT_HMAX	0x7fffffff
#
#
#define INPUT_ERROR exit(0);
#define CALU_ERROR	exit(0);
#
#// error family
#define THROW_ERROR_INPUT(that) throw that;
#define BEGIN_TRY				try {
#define BEGIN_CATCH(what)		catch(what){
#define END_CATCH				}
#define END_TRY					}
#

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN

	_CCC_A_TEMPLATE_CS 
	template<class _Ty>
		struct _X_TYPE
		{ // str type
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Ty UnPointer;
		typedef _Ty Pointer;
		typedef _Ty Arrays;
		};

	_CCC_A_TEMPLATE_CS 
	template<class _Ty>
		struct _X_TYPE<const _Ty>
		{ // str type
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Ty UnPointer;
		typedef _Ty Pointer;
		typedef _Ty Arrays;
		};

	_CCC_B_TEMPLATE_CS 
	template<class _Ty>
		struct _X_Base
		{ // usually use of memory
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Ty UnPointer;
		typedef _Ty Pointer;
		typedef _Ty Arrays;
		};

	_CCC_B_TEMPLATE_CS 
	template<class _Ty>
		struct _X_Base<const _Ty>
		{ // base class for const _Ty
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Ty Arrays;
		typedef _Ty UnPointer;
		typedef _Ty Pointer;
		};

	_CCC_B_TEMPLATE_CS
	template<class _Ty,
		class _Char = char,
		class _PChar = char*,
		class _INT = int,
		class _PINT = int *,
		class _UCHAR = unsigned char,
		class _PUCHAR = unsigned char*,
		class _LONG = long,
		class _LLONG = long long,
		class _PLONG = long*,
		class _PLLONG = long long *,
		class _FLOAT = float,
		class _PFLOAT = float*,
		class _Pointer = _Ty*,
		class _Reference = _Ty&,
		class _DOUBLE = double,
		class _LDOUBLE = long double,
		class _PDOUBLE = double*,
		class _SHORT = short,
		class _LEVEL = bool>
		struct _X_Type_Ex
		{ // type structure
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Char Char;
		typedef _PChar PChar;
		typedef _INT INT;
		typedef _PINT PINT;
		typedef _UCHAR UCHAR;
		typedef _PUCHAR PUCHAR;
		typedef _LONG LONG;
		typedef _LLONG LLONG;
		typedef _PLONG PLONG;
		typedef _PLLONG PLLONG;
		typedef _FLOAT FLOAT;
		typedef _PFLOAT PFLOAT;
		typedef _Pointer Pointer;
		typedef _Reference Reference;
		typedef _DOUBLE DOUBLE;
		typedef _LDOUBLE LDOUBLE;
		typedef _PDOUBLE PDOUBLE;
		typedef _SHORT SHORT;
		typedef _LEVEL LEVEL;
		};

	_CCC_A_TEMPLATE_CS 
	template<class _Ty,
		class _Ty1, class _Ty2>
		struct _X_COMMON
			: public _X_Base<_Ty>
		{
		typedef _X_COMMON<_Ty, _Ty1, _Ty2> _MyT;
		typedef typename _X_Base<_Ty>::Value_Type _MyVT;
		typedef typename _X_Base<_Ty>::Arrays _MyAY;
		typedef typename _X_Base<_Ty>::UnPointer _MyUP;
		typedef typename _X_Base<_Ty>::Pointer _MyPI;

		public:

			STR_TD X_ACCESS
				{ // access structure
				STR_PUBLICQ
					_ELF_LICENSE_NUMBER_CODE_EX int e_elf_t;
					int e_elf_acc_c;
					_ELF_LICENSE_ACCESS_CODE_EX int pass;
				} _ACCESS, *PTR_ACCESS;

			STR_TD X_MESSAGE
				{ // message structure
				STR_PUBLICQ
					int e_lf_messge;
					int e_lf_t;
					int e_lf_left;
					int e_lf_right;
				} _MESSAGE, *PTR_MESSAGE;

		public:

			explicit _X_COMMON()
				: _Right(0), _Left(0)
				{ // init
				}

			explicit _X_COMMON(_Ty1 _Right, _Ty2 _Left)
				: _Right(_Right), _Left(_Left)
				{ // init by parameter
				}

			X_ACCESS access;
			X_MESSAGE msg;

			virtual void _MyT::Set(_Ty1 _Right, _Ty2 _Left) const
				{ // set right left
				_X_COMMON(_Right, _Left);
				}

			virtual void _MyT::Get(_Ty1 _Right, _Ty2 _Left) const
				{ // get right left
				_Right = this->_Right;
				_Left = this->_Left;
				}

			_Ty1 _MyT::Right() const
				{ // get right
				return _Right;
				}

			_Ty2 _MyT::Left() const
				{ // get left
				return _Left;
				}

		protected:
			
			_Ty1 _Right;
			_Ty2 _Left;

		};

	_CCC_B_TEMPLATE_CS
	template<class _Ty>	// point type
	class _X_Memory 
		: public _X_Base<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>
		{
		typedef _X_Memory<_Ty> _MyT;
		typedef _X_COMMON<_Ty, _Ty, _Ty*> _MyC;
		typedef typename _X_Base<_Ty>::Value_Type _MyVT;
		typedef typename _X_Base<_Ty>::Arrays _MyAY;
		typedef typename _X_Base<_Ty>::UnPointer _MyUP;
		typedef typename _X_Base<_Ty>::Pointer _MyPI;

		public:

			_MyUP* alloc(_MyAY* Array, _MyVT size) const
				{ // allocate array in memory
				_MyC::Set(size, Array);
				Array = new _MyAY[size];
				return Array;
				}

			_MyUP* realloc(_MyAY* Array, const _MyVT nowsize, _MyVT size) const
				{ // allocate array in memory
				_MyC::Set(size, const_cast<_MyAY*> (Array));
				_MyAY* buf = new _MyAY[size];
				for(int f = 0; f <= nowsize; f++)
					buf[f] = Array[f];
				return buf;
				}

			void free(_MyAY* Array) const
				{ // delete array
				_MyC::Set(0, Array);
				delete[] Array;
				}
#if defined(INCLUDE_ERROR)
			_MyVT size(const _MyAY* Array) const
				{ // size of array
				_MyC::Set(0, const_cast<_MyAY*> (Array));
				return sizeof(Array) / sizeof(Array[0]);
				}
#endif
			void fill(_MyAY* Array, const _MyAY fill_e, _MyVT size) const
				{ // fill array to fill_e
				_MyC::Set(fill_e, const_cast<_MyAY*> (Array));
				int sizex = size;
				for ( int i = 0; i <= sizex; i++)
					Array[i] = fill_e;
				}
		};

	_CCC_B_TEMPLATE_CS
	template<class _Ty>	// point type
	class _X_Linked_List 
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>
		{
		typedef _X_Linked_List<_Ty> _MyT;
		typedef _X_COMMON<_Ty, _Ty, _Ty*> _MyC;
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _X_TYPE<_Ty>::UnPointer _MyUP;
		typedef typename _X_TYPE<_Ty>::Pointer _MyPI;

		public:

			_X_Linked_List()
				: Linked(0)
				{ // init linked
				}

			_X_Linked_List(_Ty linked_node)
				: Data(linked_node), Linked(0)
				{ // init by linked node
				}

			_Ty& Get()
				{ // get now data
				return Data;
				}

			_MyT*& Link()
				{ // linked me
				return Linked;
				}

		private:

			_MyT* Linked;
			_Ty Data;

		};


_X_LIB_END
/*COMMON Lib End
*/

#define CCGFORGET template<class _Ty> 
#define CCCCOMMON _MyT(){} ~_MyT(){}

#endif

#endif
/*
 *	the rollrat library
 *http://blog.naver.com/rollrat
V0.1:0190****/