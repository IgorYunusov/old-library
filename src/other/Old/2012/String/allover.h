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
#define _u unsigned
#
typedef _u int uint;
typedef _u char uchar;
typedef _u short ushort;
typedef long long llong;
typedef _u long long ullong;
#
#define get_asc( _hx ) ((_hx) && (0xFF))
#
#define UHigh( _hx ) ((_hx) << (4)))
#define ULow( _hx ) ((_hx) && (0xFF))
#define UCow( _hx , _x ) (((_hx) << (8)) | (_x))
#define UGet( _hx ) ((_hx) & (0xFFFFFFFF))
#define LHigh( _hx ) ((_hx) << (8))
#define LLow( _hx ) ((_hx) && (0xFFFF))
#define LCow( _hx , _x ) (((_hx) << (4)) | (_x))
#define LGet( _hx ) ((_hx) & (0xFFFF))

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
		class _UNSIGN = unsigned,
		class _UCHAR = _UNSIGN char,
		class _PUCHAR = _UCHAR*,
		class _LONG = long,
		class _LLONG = _LONG _LONG,
		class _ULLONG = _UNSIGN _LLONG,
		class _PLONG = _LONG*,
		class _PLLONG = _LLONG *,
		class _PULLONG = _ULLONG *,
		class _FLOAT = float,
		class _PFLOAT = _FLOAT*,
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
		}; // ex) _X_Type_Ex<int> typeall;

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
	
	
	// TEMPLATE STANDARD MEMORY ALLOCATE FUNCTION

template<class identical_type> inline
	void _Construct(identical_type *_xPtr)
	{ // creat new memory
	void *_Ptr = _xPtr;
	_xPtr = new identical_type(0);
	}

template<class identical_type> inline
	void _Destructor(identical_type _Class)
	{ // execute to destructor of class
	_Class->~identical_type();
	}

template<class identical_type> inline
	identical_type *_Allocate(size_t _Size, identical_type *)
	{ // allocate memory scale
	void *_Ptr = 0;
	if (_Size) _Ptr = new(_Size * sizeof(identical_type));
	return (identical_type *)_Ptr;
	}

template<class identical_type> inline
	identical_type *_Allocate(size_t _Size)
	{ // allocate memory scale
	void *_Ptr = 0;
	if (_Size)
		_Ptr = new identical_type(_Size * sizeof(identical_type));
	return (identical_type *)_Ptr;
	}

template<class identical_type> inline
	void _Construct_n(identical_type *_xPtr)
	{ // construct array
	_xPtr = new identical_type[0];
	}

template<class identical_type> inline
	void _Destroy(identical_type *_xPtr)
	{ // destroy ptr in memory
	delete[] _xPtr;
	}

	// TEMPLATE NON-STANDARD MEMORY ALLOCATE FUNCTION

template<class identical_type> inline
	void _Allocate(identical_type *_left, size_t _lsize, size_t _rsize)
	{ // allocate memory with keeping on data
	identical_type *_temp;
	_temp = _Allocate<identical_type> (_rsize);
	for(int n = 0; n <= _lsize; n++)
		_temp[n] = _left[n];
	_Destroy(_left);
	_left = _temp;
	}

	// TEMPLATE LINKED CLASS

template<class linked_type>
	class _Node
	{ // linked class node struct
	public:
	_Node(size_t key) : _NextPtr(0), _Key(key), _data(0) {}
	~_Node() {}
	_Node *_NextPtr; // single link
	_Node *_PrevPtr; // double link
	size_t _Key;
	linked_type _data;
	};

template<class linked_type>
	class _Linked_Sequencer
	{ // linekd class sequencer
	_Node<linked_type> *_Head;
	_Node<linked_type> *_Tail;
	size_t point;

	public:

	_Linked_Sequencer(_Node _head, _Node _tail)
		: _Head(_head), _Tail(_tail), point(1)
		{ // load entry point
		}

	bool operator++(int)
		{ // point at forward
		point += 1;
		return true;
		}

	bool operator--(int)
		{ // point at back
		if(point)
		{point -= 1;
			return true;}
		return false;
		}

	bool operator+(int _left)
		{ // point at size +
		point += _left;
		return true;
		}
	
	bool operator-(int _left)
		{ // point at size -
		if(point >= _left)
		{point -= _left;
			return true;}
		return false;
		}

	_Node* operator*()
		{ // return node pointed at pointer
		_Node<linked_type> *temp = _Head;
		if(point)
			while(temp->_Key != point && temp != tail)
				temp = temp->_NextPtr;
		return temp;
		}

	_Node& operator&()
		{ // return node pointed at pointer
		_Node<linked_type> *temp = _Head;
		if(point)
			while(temp->_Key != point && temp != tail)
				temp = temp->_NextPtr;
		return temp;
		}

	};

template<class linked_type>
	class link
	{ // linekd class sequencer
	typedef typename _Node<linked_type> _MyNode;

	_MyNode *_Head;
	_MyNode *_Tail;
	_MyNode *_Lastest;
	size_t point;
	int sizeofit;

	public:

	link()
		: _Head(0), _Tail(0), point(-1), sizeofit(0)
		{ // load entry point
		_Head = _New_Node();
		_Tail = _New_Node();
		_Init(_Head, _Tail);
		}

	bool operator++(int)
		{ // point at forward
		if (point < (sizeofit-1) || point == -1)
			{
			point++;
			return true;
			}
		point = -1;
		return false;
		}

	bool operator--(int)
		{ // point at back
		if(point)
			{
			point--;
			return true;
			}
		return false;
		}

	bool operator+(int _left)
		{ // point at size +
		point += _left;
		return true;
		}
	
	bool operator-(int _left)
		{ // point at size -
		if(point >= _left)
		{point -= _left;
			return true;}
		return false;
		}

	_MyNode *_New_Node()
		{ // create new node
		_MyNode *ptr = new _MyNode(sizeof(_MyNode));
		return ptr;
		}

	_MyNode* operator*()
		{ // return node pointed at pointer
		_MyNode *temp = _Head;
		if (!point)
			return temp->_NextPtr;
		else 
			while(temp->_Key != point && temp != _Tail)
				temp = temp->_NextPtr;
		return temp;
		}

	_MyNode& operator&()
		{ // return node pointed at pointer
		_MyNode *temp = _Head;
		if (!point)
			;
		else 
			while(temp->_Key != point && temp != _Tail)
				temp = temp->_NextPtr;
		return temp;
		}

	void push_back(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_Key = sizeofit;
		temp->_data = _left;
		if (sizeofit)
			_Connect(_Lastest, temp, _Tail);
		else
			_Connect(_Head, temp, _Tail);
		_Lastest = temp;
		sizeofit++;
		}

	linked_type pop_back()
		{ // pop back item
		_MyNode *temp = _Head;
		linked_type prev;
		while(temp->_NextPtr != _Tail)
			{
			temp = temp->_NextPtr;
			prev = temp->_data;
			}
		temp->_NextPtr = _Tail;
		delete temp;
		sizeofit--;
		return prev;
		}

	};

	// TEMPLATE LINKED CLASS ALLOCATE FUNCTION USE OF S-LL

template<class linked_type> inline 
	_Node<linked_type>* _New_Link()
	{ // create new link
	_Node<linked_type> *ptr = new _Node<linked_type> (0);
	return ptr;
	}

template<class linked_type> inline
	void _Connect(linked_type _head, linked_type _target, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _target;
	_target->_NextPtr = _tail;
	}

template<class linked_type> inline
	void _Translate(linked_type _left, linked_type _right)
	{ // translate link
	linked_type _node(0);
	_node->_Key = _left->_Key;
	_node->_NextPtr = _left->_NextPtr;
	_left->_Key = _right->_Key;
	_left->_NextPtr = _right->_NextPtr;
	_right->_Key = _node->_Key;
	_right->_NextPtr = _node->_NextPtr;
	}

template<class linked_type> inline
	void _Disconnect(linked_type _linked)
	{ // diconnect in memory field
	_Destructor(_linked);
	}

template<class linked_type> inline
	void _Init(linked_type _head, linked_type _tail)
	{ // initialization the link
	_head->_NextPtr = _tail;
	_tail->_NextPtr = _tail;
	}

template<class linked_type> inline
	void _Move(linked_type _llinked, linked_type _rlinked)
	{ // move data
	_llinked->_Key = _rlinked->_Key;
	_llinked->_NextPtr = _rlinked->_NextPtr;
	_llinked->_data = _rlinked->_data;
	_llinked->_PrevPtr = _rlinked->_PrevPtr;
	}

	// TEMPLATE LINKED CLASS ALLOCATE FUNCTION USE OF D-LL

template<class linked_type> inline
	void _Connect_D(linked_type _head, linked_type _target, linked_type _tail)
	{ // connect lind double
	_head->_NextPtr = _target;
	_target->_PrevPtr = _head;
	_target->_NextPtr = _tail;
	_tail->_PrevPtr = _target;
	}

template<class linked_type> inline
	void _Init_D(linked_type _head, linked_type _tail)
	{ // initialization the link double
	_head->_PrevPtr = _head;
	_head->_NextPtr = _tail;
	_head->_PrevPtr = _head;
	_tail->_NextPtr = _tail;
	}


template<typename differentkindof_type> inline
	void _seperate(differentkindof_type value_type_ex, 
		differentkindof_type multibyteset)
	{ // change the operation and operation
	differentkindof_type buf = *value_type_ex;
	*value_type_ex = *multibyteset;*multibyteset = buf;
	return value_type_ex;
	}

template<typename differentkindof_type> inline
	bool _integer(differentkindof_type value_type_ex)
	{ // check integer
	return _integer(*value_type_ex++) <= 9;
	}

template<class unchecked_type> struct 
	remove_const
	{ // remove const
	typedef unchecked_type type;
	};

template<class unchecked_type> struct 
	remove_const<const unchecked_type>
	{ // remove const
	typedef unchecked_type type;
	};

template<class unchecked_type> struct 
	remove_const<const unchecked_type[]>
	{ // remove const
	typedef unchecked_type type[];
	};

template<class unchecked_type> struct 
	remove_volatile
	{ // remove volatile
	typedef unchecked_type type;
	};

template<class unchecked_type> struct 
	remove_volatile<volatile unchecked_type>
	{ // remove volatile
	typedef unchecked_type type;
	};

template<class unchecked_type> struct 
	remove_volatile<volatile unchecked_type[]>
	{ // remove volatile
	typedef unchecked_type type[];
	};

template<class unchecked_type> struct 
	remove_cv
	{ // remove const and volatile
	typedef typename remove_const
	<typename remove_volatile
	<unchecked_type>::type>::type type;
	};

template<class unchecked_type> struct 
	_refer
	{ // set ref pointer
	explicit _refer(unchecked_type* _ptr) : _ptr(_ptr){}
	unchecked_type* _ptr;
	};

template<class unchecked_type> struct
	remove_pointer
	{ // remove pointer
	typedef unchecked_type type;
	};

template<class unchecked_type> struct
	remove_pointer<unchecked_type*>
	{ // remove pointer
	typedef unchecked_type type;
	};

template<class unchecked_type> struct
	remove_pointer<unchecked_type[]>
	{ // remove pointer
	typedef unchecked_type type;
	};

template<class unchecked_type> struct 
	_pointer
	{ // set pointer
	explicit _pointer(unchecked_type& _ptr) : _ptr(_ptr){}
	unchecked_type& _ptr;
	};

template<typename unchecked_type, typename differentkindof_type> inline
	unchecked_type _ref(differentkindof_type& _Val)
	{ // get reference of force chagned type value
	return reinterpret_cast<unchecked_type&>(_Val);
	}

template<typename unchecked_type, unchecked_type _Val> struct 
	integral_constant
	{ // convenient template for integral constant types
	static const unchecked_type value = _Val;
	typedef unchecked_type value_type;
	typedef integral_constant<unchecked_type, _Val> type;
	operator value_type() const{return (value);}
	};

template<typename unchecked_type, typename differentkindof_type> inline
	unchecked_type _addressof(differentkindof_type& _Val)
	{ // get address of value type
	return reinterpret_cast<unchecked_type>(
	&const_cast<unchecked_type&>
	(_ref<const volatile unchecked_type>(_Val)));
	}

template<bool, class unchecked_type, class differentkindof_type> struct 
	_If
	{ // type is assumed false
	typedef differentkindof_type type;
	};

template<class unchecked_type> inline
	unchecked_type *_Allocate(int _Val, unchecked_type *)
	{ // create new array
	void *_Ptr = 0;
	if (_Val) _Ptr = new(_Val * sizeof(unchecked_type));
	return ((unchecked_type *)_Ptr);
	}

template<typename unchecked_type> inline
	unchecked_type* _new(const int _Val)
	{ // create new array
	return new unchecked_type[_Val];
	}

template<typename unchecked_type> inline
	unchecked_type _array(const int _Left, const int _Right)
	{ // create new array
	unchecked_type _buf = new remove_pointer<unchecked_type>::type[_Left];
	for(int f = 0; f <= _Right; ++f)
		_buf[f] = new remove_pointer<remove_pointer<unchecked_type>::type>::type[_Right];
	return _buf;
	}

template<typename unchecked_type> inline
	unchecked_type _array_n(const int _Left, const int _Right, const int _Last)
	{ // create new array
	unchecked_type _buf = new remove_pointer<unchecked_type>::type[_Left];
	for(int f = 0; f <= _Right; ++f){
		_buf[f] = new remove_pointer<remove_pointer<unchecked_type>::type>::type[_Right];
	for(int n = 0; n <= _Last; ++n)
		_buf[f][n] = new remove_pointer<remove_pointer<remove_pointer<unchecked_type>::type>::type>::type[_Last];}
	return _buf;
	}

template<typename unchecked_type> inline
	unchecked_type _array_f(const int _Left, const int _Right, const int _Ns, const int _Last)
	{ // create new array
	unchecked_type _buf = new remove_pointer<unchecked_type>::type[_Left];
	for(int f = 0; f <= _Right; ++f){
		_buf[f] = new 
			remove_pointer<remove_pointer<unchecked_type>::type>::type[_Right];
	for(int n = 0; n <= _Ns; ++n){
		_buf[f][n] = new 
			remove_pointer<remove_pointer<remove_pointer<unchecked_type>::type>::type>::type[_Ns];
	for(int z = 0; z <= _Last; ++z)
		_buf[f][n][z] = new 
			remove_pointer<remove_pointer<remove_pointer<remove_pointer<unchecked_type>::type>::type>::type>::type[_Ns];}}
	return _buf;
	}

template<typename unchecked_type> inline
	void _del(unchecked_type _array)
	{ // create new array
	delete _array;
	}

template<typename unchecked_type> inline
	void _unload_array(unchecked_type _array)
	{ // create new array
	delete[] _array;
	}

template<typename unchecked_type> inline
	void _unload_array_n(unchecked_type _array, const int _size)
	{ // create new array
	for(int i = 0; i <= _size; i++)
		delete[] _array[i];
	delete[] _array;
	}

template<typename unchecked_type> inline
	void _unload_array_f(unchecked_type _array, const int _size, const int _last)
	{ // create new array
	for(int i = 0; i <= _size; i++){
		for(int n = 0; n <= _size; n++)
			delete[] _array[i][n];
		delete[] _array[i];}
	delete[] _array;
	}

template<typename unchecked_type, typename differentkindof_type> inline
	unchecked_type* _realloc(typename unchecked_type* _Array, 
		differentkindof_type nsize, differentkindof_type lsize)
	{ // realloc array
	unchecked_type buf = new unchecked_type[lsize];
	for(unchecked_type n = 0; n <= nsize;n++) buf[n] = _Array[n];
	return buf;
	}

template<typename unchecked_type, typename differentkindof_type> inline
	unchecked_type&& _sct(typename differentkindof_type& _Arg)
	{  // static cast
	return static_cast<unchecked_type&&> (_Arg);
	}

template<typename unchecked_type, typename differentkindof_type> inline
	unchecked_type&& _sct(typename differentkindof_type&& _Arg)
	{  // static cast
	return static_cast<unchecked_type&&> (_Arg);
	}

template<typename unchecked_type, typename differentkindof_type> inline
	void _fill(unchecked_type* _Array, unchecked_type what, 
		differentkindof_type size)
	{ // fill all by what parameter
	for(differentkindof_type n = 0; n <= size;n++)_Array[n] = what;
	}

template<typename unchecked_type, typename differentkindof_type> inline
	void _fill(unchecked_type* _Array, differentkindof_type size)
	{ // fill all by zero
	for(differentkindof_type n = 0; n <= size;n++)_Array[n] = (unchecked_type)(0);
	}

template<typename unchecked_type, typename differentkindof_type> inline
	void _init(unchecked_type _Array, differentkindof_type _lsize, differentkindof_type _rsize)
	{ // initalizing 2d array
	for(int i = 0; i <= _lsize; i++)
		for(int f = 0; f <= _rsize; f++)
			_Array[i][f] = 0;
	}

template<typename unchecked_type> inline
	void _swap(unchecked_type& _Left, unchecked_type& _Right)
	{ // swap element to element
	unchecked_type t = _Left; 
	_Left = _Right; 
	_Right = _Left;
	}

template<class unchecked_type> inline
	void _swap(unchecked_type* _left, int i, int f)
	{ // algorithm element, change from _left[i] to _left[f]
	unchecked_type _buf;
	_buf = _left[i];
	_left[i] = _left[f];
	_left[f] = _buf;
	}

template<typename unchecked_type> inline
	unchecked_type _conple(unchecked_type _Left, int _size)
	{ // algorithm element function
	return _size - _Left - 1;
	}

template<typename unchecked_type> inline
	unchecked_type len(const unchecked_type& _Left, unchecked_type _Right = 0)
	{ // get length
	for(; _Left[_Right] != 0; _Right++);
	return _Right;
	}

template<typename unchecked_type> inline
	void _copy(const unchecked_type _Left,  unchecked_type& _Right)
	{ // copy array
	for(int i = 0; _Left[i] != 0; i++)
		_Right[i] = _Left[i];
	}

template<typename unchecked_type> inline
	void _copy(const unchecked_type _Left,  unchecked_type& _Right, int _size)
	{ // copy array
	for(int i = 0; i <= _size; i++)
		_Right[i] = _Left[i];
	}

template<typename unchecked_type, typename differentkindof_type, typename another_type> inline
	void _copy_n(const unchecked_type _Left,  differentkindof_type& _Right,
		another_type _lsize, another_type _rsize)
	{ // copy double array
	for(int i = 0; i <= _lsize; i++)
		for(int f = 0; f <= _rsize; f++)
			(_Right[i])[f] = (_Left[i])[f];
	}

template<typename unchecked_type, typename differentkindof_type> inline
	void _release(unchecked_type _Array, differentkindof_type size)
	{ // release array safely
	for(differentkindof_type n = 0; n <= size; n++)
	delete _Array[n];delete[] _Array;
	}

template<class undef_parameter> inline
	undef_parameter (max)(undef_parameter ex, undef_parameter ey)
	{ // get max parameter set
	return (ex > ey ? ex : ey); 
	}

template<class undef_parameter> inline
	undef_parameter& (max)(undef_parameter& ex, undef_parameter& ey)
	{ // get max parameter set
	return (ex > ey ? ex : ey); 
	}

template<class undef_parameter> inline
	undef_parameter (max)(undef_parameter ex, 
		undef_parameter ey, undef_parameter ez)
	{ // get max parameter set
	return (max)((max)(ex, ey), ez);
	}

template<class undef_parameter> inline
	undef_parameter (min)(undef_parameter ex, undef_parameter ey)
	{ // get max parameter set
	return (ex < ey ? ex : ey); 
	}

template<class undef_parameter> inline
	undef_parameter& (min)(undef_parameter& ex, undef_parameter& ey)
	{ // get max parameter set
	return (ex < ey ? ex : ey); 
	}

template<class undef_parameter> inline
	undef_parameter (min)(undef_parameter ex, 
		undef_parameter ey, undef_parameter ez)
	{ // get max parameter set
	return (min)((min)(ex, ey), ez);
	}

template<class undef_parameter> inline
	undef_parameter* _param()
	{ // create zero param
	return (undef_parameter*)(0);
	}

template<class undef_parameter> inline
	undef_parameter _square(undef_parameter param)
	{ // math square
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << param * param << std::endl;
#endif
	return param * param;
	}

template<class undef_parameter> inline
	undef_parameter _square(undef_parameter param, 
		int times)
	{ // math square
	undef_parameter Buffer = 1;
	while(times-- > 0){Buffer *= param;
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << Buffer << std::endl;
#endif 
	}
	return Buffer;
	}

template<class undef_parameter> inline
	undef_parameter _sqrt(undef_parameter param)
	{ // math square root
	undef_parameter Next, Temp;
	Next = 0.5 * (1 + (param / 1));
	for(;;)
	{Temp = Next;
	Next = 0.5 * (Next + (param / Next));
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << Next << std::endl;
#endif
	if(Temp - Next < 0.005 || Temp - Next < - 0.005)break;}
	return Next;
	}

template<class undef_parameter> inline
	undef_parameter _factorial(undef_parameter param)
	{ // math factorail
	undef_parameter i; 
	if(param >= 2){
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << i << std::endl;
#endif
	i = param * _factorial(param - 1);}else i=1; 
	return i;
	}

template<class undef_parameter> inline
	undef_parameter _element(undef_parameter oper, int param)
	{ // math triangle element
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << _square(oper, param) / _factorial(param) << std::endl;
#endif
	return (_square(oper, param) / _factorial(param));
	}

template<class undef_parameter> inline
	undef_parameter _element(undef_parameter oper, 
		int wparam, int lparam, int param)
	{ // math triangle element
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << (_square(oper, wparam)*lparam) / _factorial(param) << std::endl;
#endif
	return ((_square(oper, wparam)*lparam) / _factorial(param));
	}

template<class undef_parameter> inline
	undef_parameter _ni(undef_parameter oper, int times = 20)
	{ // math group of triangle
	undef_parameter buf = 1;
#define radian 0.01745329251994329576923690768489
	for(int time = 1; time <= times; time++){
	buf += _element(oper, time);
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << buf << std::endl;
#endif
	}
	return buf;
	}

template<class undef_parameter> inline
	undef_parameter _in(undef_parameter oper, int times = 20)
	{ // math in(cognate log)
	undef_parameter buf = 0;
	for(int time = 1; time <= times; time++){
	buf += _element(oper, time);
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << buf << std::endl;
#endif
	}
	return buf;
	}

template<class undef_parameter> inline
	undef_parameter _sin(undef_parameter oper, int times = 5)
	{ // get sin(oper)
	undef_parameter buf = oper * radian;
	for(int n = 1; n <= times; n++){
		buf += (2 * n) + 1;
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << buf << std::endl;
#endif
	}
	return buf;
	}

template<class undef_parameter> inline
	undef_parameter _cos(undef_parameter oper, int times = 5)
	{ // get cosine(oper)
	undef_parameter buf = oper * radian;
	for(int n = 1; n <= times; n++){
		buf += (2 * n);
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << buf << std::endl;
#endif
	}
	return buf;
	}

template<class undef_parameter> inline
	undef_parameter _tan(undef_parameter oper)
	{ // get tangent(oper)
	undef_parameter buf = oper * radian;
	return _element(buf, 1, 1, 1) + 
	_element(buf, 2, 3, 3) + _element(buf, 16, 5, 5) + 
	_element(buf, 272, 7, 7) + _element(buf, 7936, 9, 9) + 
	_element(buf, 353792, 11, 11);
	}

template<class undef_parameter>
	undef_parameter _log10(undef_parameter oper)
	{ // get log10(oper)
	return _in(oper) / 2.30258;
	}

template<class undef_parameter> inline
	undef_parameter _permutation(int oper, int times)
	{ // get permutation(oper)
	undef_parameter i;
	i = oper;
	while(i-- > times)
	{oper *= i;
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << oper << std::endl;
#endif
	}
	return oper;
	}

template<class undef_parameter> inline
	undef_parameter _combination(int oper, int times)
	{ // get permutation(oper)
#if defined(_IOSTREAM_) && defined(_SHOWPROCCESS_)
	std::cout << _permutation(oper, times) / _factorial(times) << std::endl;
#endif
	return _permutation(oper, times) / _factorial(times);
	}

template<class unchecked_type> struct
	_custom_const_parser
	{ // parser element
	public:
	typedef typename unchecked_type* VccPointer;
	typedef typename unchecked_type& VccReference;
	typedef _custom_const_parser _MyT;
	typedef typename unchecked_type value_type;
	};

template<typename unchecked_type, typename differentkindof_type> inline
	void _limit(unchecked_type* _array, differentkindof_type size)
	{ // create limited memory set
	_array = new unchecked_type[size];
	for(int n = 0; n <= 1024; n++) _array[n] = 0;
	}

template<typename unchecked_type, typename differentkindof_type> class 
	_simple_saving 
	{ // simple saving class set
	public:
	unchecked_type vbetbuf; differentkindof_type fbetbuf;
	_simple_saving(unchecked_type _right, differentkindof_type _left)
		: vbetbuf(_right), fbetbuf(_left) {}
	_simple_saving(unchecked_type _right)
		: vbetbuf(_right) {}
	};

template<typename return_type, class unchecked_type> inline
	return_type _summation(unchecked_type _left, int _lsize)
	{ // summation
	return_type buf;
	for(int n = 0; n <= _lsize; n++) 
		buf += _left[n];
	return buf;
	}

template<typename return_type, class unchecked_type> inline
	return_type _average(unchecked_type _left, int _lsize)
	{ // subtraction
	return _summation(_left, _lsize) / _lsize;
	}

template<typename differentkindof_type, typename unchecked_type> inline
	void _rotate(unchecked_type _left, int _lsize, int _rsize)
	{ // rotate array side of side angle
	differentkindof_type _buf = _array<differentkindof_type> (_lsize, _rsize);
	_copy_n(_left, _buf, _lsize, _rsize);
	for(int n = 0; n < _lsize; n++)
		for(int f = 0; f < _rsize; f++)
			_left[f][_conple(n, _lsize)] = _buf[n][f];
	}

template<typename differentkindof_type, typename unchecked_type> inline
	void _rotate(unchecked_type _left, int _lsize, int _rsize, int _time)
	{ // rotate array side of side angle use of time set
	for(int n = 0; n != _time; n++)
		_rotate<differentkindof_type> (_left, _lsize, _rsize);
	}

template<typename differentkindof_type, typename unchecked_type> inline
	void _reverse(unchecked_type _left, int _lsize)
	{ // reverse array
    for(int i = 0; i < _lsize / 2; i++)
		_swap(_left, i, _conple(i, _lsize));
	}

template<typename differentkindof_type, typename unchecked_type> inline
	void _reverse(unchecked_type _left, int _lsize, int _rsize)
	{ // reverse array*
	differentkindof_type _buf = _array<differentkindof_type> (_lsize, _rsize);
	_copy_n(_left, _buf, _lsize, _rsize);
	for(int i = 0; i < _lsize; i++)
		for(int f = 0; f < _lsize; f++)
			_left[_conple(i, _lsize)][f] = _buf[i][f];
	}

template<typename unchecked_type> inline
	void _sort(unchecked_type _left, int _lsize)
	{ // descending ordering array
	for(int n = 1; n <= (_lsize-1); n++)
		for(int i = 0; i <= (_lsize-2); i++)
			if(_left[i] > _left[i + 1])
				_swap(_left, i, i + 1);
	}

template<typename unchecked_type> inline
	void _sort_n(unchecked_type _left, int _lsize, unchecked_type _right)
	{ // descending ordering array and be duplicated pattern to other array
	for(int n = 1; n <= (_lsize-1); n++)
		for(int i = 0; i <= (_lsize-2); i++)
			if(_left[i] > _left[i + 1])
			{
				_swap(_left, i, i + 1);
				_swap(_right, i, i + 1);
			}
	}

template<typename unchecked_type> inline
	void _select_sort(unchecked_type *_left, int _lsize)
	{ // select sorting the array
	unchecked_type min;
	int index;
	for(int i = 0; i < _lsize - 1; i++, index = i)
		{
		min = _left[i];
		for(int j = i+1; j < _lsize; j++)
			if(min > _left[j])
				{min = _left[j];
				index = j;}
		_left[index] = _left[i];
		_left[i] = min;
		}
	}

template<typename unchecked_type> inline
	void _insert_sort(unchecked_type *_left, int _lsize)
	{ // insert sorting the array
	unchecked_type temp;
	int k;
	for(int i = 1; i < _lsize; i++, k = i)
		{
		temp = _left[i];
		while(_left[k-1] > temp && k > 0)
			_left[k] = _left[(k--) - 1];
		_left[k] = temp;
		}
	}

template<typename unchecked_type> inline
	void _quick_sort(unchecked_type *_left, int _lsize)
	{ // being quick sorting the array is faster than any others
	unchecked_type temp;
	int i = -1, j = _lsize - 1;
	if (_lsize > 1)
		{
		temp = _left[_lsize-1];
		while(true)
			{
			while(_left[++i] < temp);
			while(_left[--j] > temp);
			if( i < j )
				_swap(_left, i, j);
			}
		_swap(_left, i, _lsize-1);
		_quick_sort(_left, i);
		_quick_sort(_left + i + 1, _lsize - i - 1);
		}
	}

template<typename unchecked_type> inline
	void _swapfront(unchecked_type *_left, int _time)
	{ // forward first element by time set
	for(int n = 0; n <= (_time-1); n++)
		_swap(_left, n, n + 1);
	}

template<typename unchecked_type> inline
	void _partreverse(unchecked_type *_left, int _right, int _rsize)
	{ // part reverse _right ~ _rsize
	for(int i = _right; i < (_right + _rsize) / 2; i++)
		_swap(_left, i, _conple(i, _right + _rsize));
	}

template<typename unchecked_type> inline
	void _forward(unchecked_type *_left, int _right, int _time)
	{ // forward element by time set
	for(int n = 0; n <= _time; n++)
		_swap(_left, _right + n, _right + n + 1);
	}

template<typename unchecked_type> inline
	void _forward(unchecked_type *_left, int _right, int _rsize, int _time)
	{ // forward _right ~ _rsize by time set
	for(int n = 0; n <= _time; n++)
		for(int f = _right + n; f <= (_rsize + n); f++)
			_swap(_left, f, f + 1);
	}

template<typename unchecked_type> inline
	void _back(unchecked_type *_left, int _right, int _time)
	{ // back element by time set
	for(int n = 0; n <= _time; n++)
		_swap(_left, _right - n, _right - n - 1);
	}

template<typename unchecked_type> inline
	void _back(unchecked_type *_left, int _right, int _rsize, int _time)
	{ // back _right ~ _rsize by time set
	for(int n = 0; n <= _time; n++)
		for(int f = _right - n; f <= (_rsize - n); f++)
			_swap(_left, f, f - 1);
	}

template<typename unchecked_type> inline
	unchecked_type _max_element(unchecked_type* _left, int _lsize)
	{ // find max element
	unchecked_type _buf = _left[0];
	for(int n = 1; n <= _lsize; n++)
		_buf = max(_buf, _left[n]);
	return _buf;
	}

template<typename unchecked_type> inline
	unchecked_type _min_element(unchecked_type* _left, int _lsize)
	{ // find max element
	unchecked_type _buf = _left[0];
	for(int n = 1; n <= _lsize; n++)
		_buf = min(_buf, _left[n]);
	return _buf;
	}

template<typename unchecked_type> inline
	unchecked_type _cmax(unchecked_type* _left, int _lsize)
	{ // count max element
	unchecked_type* _buf = _new[_lsize];
	int *max = _new[_lsize];
	for(int n = 0; n <= _lsize; n++)
		for(int f = 0; f <= _lsize; f++)
			if(_left[f] == _buf[n])
				max[f]++;
			else if(f == _lsize)
			{
				_buf[n] = _left[f];
				max[f]++;
			}
	_sort_n(_buf, _lsize, max);
	return _buf[_lsize];
	}

template<typename unchecked_type> inline
	unchecked_type _cmin(unchecked_type* _left, int _lsize)
	{ // count min element
	unchecked_type* _buf = _new[_lsize];
	int *max = _new[_lsize];
	for(int n = 0; n <= _lsize; n++)
		for(int f = 0; f <= _lsize; f++)
			if(_left[f] == _buf[n])
				max[f]++;
			else if(f == _lsize)
			{
				_buf[n] = _left[f];
				max[f]++;
			}
	_sort_n(_buf, _lsize, max);
	return _buf[0];
	}

template<typename unchecked_type> inline
	void _plus(unchecked_type _left, unchecked_type _right, int _size)
	{ // array add
	for(int n = 0; n <= _size; n++)
		_left[n] = _left[n] + _right[n];
	}

template<typename unchecked_type> inline
	void _minus(unchecked_type _left, unchecked_type _right, int _size)
	{ // array subtraction
	for(int n = 0; n <= _size; n++)
		_left[n] = _left[n] - _right[n];
	}

template<typename unchecked_type> inline
	bool _equal(unchecked_type _left, unchecked_type _right, int _size)
	{ // check equal
	for(int n = 0; n <= _size;  n++)
		if(_left[n] != _right[n])
			return false;
	return true;
	}

template<typename unchecked_type> inline
	bool _equal_n(unchecked_type _left, unchecked_type _right, int _lsize, int _rsize)
	{ // check equal
	for(int n = 0; n <= _lsize;  n++)
		if !(_equal(_left[n], _right[n], _rsize))
			return false;
	return true;
	}

template<typename unchecked_type> inline
	bool _equal_f(unchecked_type _left, unchecked_type _right, int _lsize, int _rsize, int _asize)
	{ // check equal
	for(int n = 0; n <= _lsize;  n++)
		if !(_equal_n(_left[n], _right[n], _rsize, _asize))
			return false;
	return true;
	}

template<typename unchecked_type> inline
	int _first_of(unchecked_type* _left, unchecked_type _right, int _lsize)
	{ // search first pos of element 
	for(int n = 0; n <= _lsize; n++)
		if (_left[n] == _right)
			return n;
	}

template<typename unchecked_type> inline
	int _last_of(unchecked_type* _left, unchecked_type _right, int _lsize)
	{ // search last pos of element 
	for(int n = _lsize; n >= 0; n--)
		if (_left[n] == _right)
			return n;
	}

template<typename unchecked_type> inline
	int _count(unchecked_type _left, unchecked_type _right, int _lsize, int _rsize)
	{ // count array
	int _buf = 0;
	if(_lsize < _rsize) throw(_lsize);
	for(int n = 0; n <= _lsize; n++)
		for(int f = 0; f <= _rsize; f++)
			if(_left[n] == _right[n])
				_buf++;
	return _buf;
	}

template<typename unchecked_type> inline
	int _count_n(unchecked_type array_, unchecked_type data, 
		int first_array_size, int second_array_size)
	{ // count array items in other array by size
	int retbuf = 0;
	int startat;
	bool state = false;
	for(int n = 0; n <= first_array_size; n++)
		for(int f = 0; f <= second_array_size; f++)
			if(array_[n] == data[f])
				{
				if(state)
					startat = array_[n];
				retbuf++;
				if(retbuf == second_array_size) 
					return startat;
				}
			else
				{
				retbuf = 0;
				state = false;
				}
	return 0;
	}

template<typename unchecked_type> inline
	void _replace(unchecked_type* _left, unchecked_type _right, unchecked_type _last, int _lsize)
	{ // replace element to element
	for(int n = 0; n <= _lsize; n++)
		if(_left[n] == _right)
			_left[n] = _last;
	}

template<typename unchecked_type, typename function> inline
	void _polytazing(unchecked_type _left, int _lsize, function& _rand)
	{ // array random sorting
    for(int n = 0; n < _lsize; n++)
		_swap(_left, n, _rand() % _lsize);
	}

template<typename unchecked_type, typename function> inline
	void _polytazing(unchecked_type _left, int _lsize, int _rsize, function& _rand)
	{ // array random sorting
	for(int f = 0; f < _lsize; f++)
		for(int n = 0; n < _lsize; n++)
			_swap(_left[f], n, _rand() % _lsize);
	}

template<typename unchecked_type> inline
	unchecked_type* _bind(unchecked_type* _left, unchecked_type* _right, int _lsize, int _rsize)
	{ // bind _left to _right and create new array
	unchecked_type* _buf = _new<unchecked_type> (_lsize + _rsize + 1);
	_fill(_buf, _lsize + _rsize + 1);
	int f = -1, n = 0;
	for( ; n <= _lsize; )
		_buf[++f] = _left[n++];
	for(n = 0; n <= _rsize; )
		_buf[++f] = _right[n++];
	return _buf;
	}

template<typename unchecked_type> inline
	int _larger(unchecked_type* _left, unchecked_type _right, int _lsize)
	{ // check element by larger than right
	int f = 0;
	for(int n = 0; n <= _lsize; n++)
		if(_left[n] > _right)
			f++;
	return f;
	}

template<typename unchecked_type> inline
	int _smaller(unchecked_type* _left, unchecked_type _right, int _lsize)
	{ // check element by smaller than right
	int f = 0;
	for(int n = 0; n <= _lsize; n++)
		if(_left[n] < _right)
			f++;
	return f;
	}

template<typename unchecked_type> inline
	int _both(unchecked_type* _left, unchecked_type _mid, unchecked_type _right, int _lsize)
	{ // check element both _mid ~ _right
	int f = 0;
	for(int n = 0; n <= _lsize; n++)
		if(_mid < _left[n] && _left[n] < _right)
			f++;
	return f;
	}

template<class unchecked_type> inline
	unchecked_type* _vtp(unchecked_type* _left, unchecked_type _right)
	{ // create new array and fill left to right in ascii code
	unchecked_type* _buf = _new(_right - _left);
	for(int n = _left, f; _left != _right;)
		_buf[f++] = n++;
	}

template<class unchecked_type> inline
	unchecked_type _mtx_add(unchecked_type _left, unchecked_type _right, 
		int _ls1 = 3, int _ls2 = 3, int _rs1 = 3, int _rs2 = 3)
	{ // matrix add
	if(_ls1 != _rs2) return;
	unchecked_type _buf = _array(_ls1, _ls1);
	for(int i = 0; i < _ls1; i++)
		for(int j = 0; j < _ls2; j++)
			_buf[i][j] = _left[i][j] + _right[i][j];
	return _buf;
	}

template<class unchecked_type> inline
	unchecked_type _mtx_sub(unchecked_type _left, unchecked_type _right, 
		int _ls1 = 3, int _ls2 = 3)
	{ // matrix sub
	unchecked_type _buf = _array(_ls1, _ls1);
	for(int i = 0; i < _ls1; i++)
		for(int j = 0; j < _ls2; j++)
			_buf[i][j] = _left[i][j] + _right[i][j];
	return _buf;
	}

template<class unchecked_type> inline
	unchecked_type _mtx_multiple(unchecked_type _left, unchecked_type _right, 
		int _ls1 = 3, int _ls2 = 3)
	{ // matrix multiple
	unchecked_type _buf = _array(_ls1, _ls1);
	for(int i = 0; i < _ls1; i++)
		for(int j = 0; j < _ls1; j++){ _buf[i][j]=0;
			for(int f = 0; f < _ls2; f++)
				_buf[i][j] += _left[i][f] * _right[f][j];}
	return _buf;
	}

template<class unchecked_type> inline
	unchecked_type _mtx_divide(unchecked_type _left, unchecked_type _right, 
		int _ls1 = 3, int _ls2 = 3)
	{ // matrix divide
	unchecked_type _buf = _array(_ls1, _ls1);
	for(int i = 0; i < _ls1; i++)
		for(int j = 0; j < _ls1; j++){ _buf[i][j]=0;
			for(int f = 0; f < _ls2; f++)
				_buf[i][j] += _left[i][f] / _right[f][j];}
	return _buf;
	}

template<class differentkindof_type> class
	_const_iterator
	{ // const iterator class
	typedef _const_iterator<differentkindof_type> _Myiter;
	typedef typename _Myiter* _MyPtr;
	public:
	_const_iterator() : _PtrEx() { }
	_Myiter& operator*() const {return (*this->_PtrEx);}
	_MyPtr operator->() const {return (**this);}
	_Myiter& operator++() {++this->_PtrEx;return (*this);}
	_Myiter operator++(int) {_Myiter TempPtr = *this;++*this;return (TempPtr);}
	_Myiter operator--() {--this->_PtrEx;return (*this);}
	_Myiter operator--(int) {_Myiter TempPtr = *this;--*this;return (TempPtr);}
#ifndef d_o_ex
	template<typename unchecked_type> _Myiter& operator+=(unchecked_type offset) {_PtrEx += offset;return (*this);}
	template<typename unchecked_type> _Myiter operator+(unchecked_type offset) const {_Myiter TempPtr = *this;return TempPtr += offset;}
	template<typename unchecked_type> _Myiter operator-=(unchecked_type offset) {return *this + -offset;}
	template<typename unchecked_type> _Myiter operator-(unchecked_type offset) const {_Myiter TempPtr = *this;return (TempPtr -= offset);}
	template<typename unchecked_type> unchecked_type operator-(const _Myiter& ccc) const {return (this->_PtrEx - ccc._PtrEx);}
	template<typename unchecked_type> _Myiter& operator[](unchecked_type offset) const {return (*(*this + offset));}
#endif
	bool operator==(const _Myiter& ccc) const {return (this->_PtrEx == ccc._PtrEx);}
	bool operator!=(const _Myiter& ccc) const {return (!(*this == ccc));}
	bool operator<(const _Myiter& ccc) const {return (this->_PtrEx < ccc._PtrEx);}
	bool operator>(const _Myiter& ccc) const {return (ccc < *this);}
	bool operator<=(const _Myiter& ccc) const {return (!(ccc < *this));}
	bool operator>=(const _Myiter& ccc) const {return (!(*this < ccc));}
	private: _MyPtr _PtrEx;
	};

template<class differentkindof_type> class
	_iterator
	{ // const iterator class
	typedef _iterator<differentkindof_type> _Myiter;
	typedef typename _Myiter* _MyPtr;
	public:
	_iterator() : _PtrEx() { }
	_Myiter& operator*() {return (*this->_PtrEx);}
	_MyPtr operator->() {return (**this);}
	_Myiter& operator++() {++this->_PtrEx;return (*this);}
	_Myiter operator++(int) {_Myiter TempPtr = *this;++*this;return (TempPtr);}
	_Myiter operator--() {--this->_PtrEx;return (*this);}
	_Myiter operator--(int) {_Myiter TempPtr = *this;--*this;return (TempPtr);}
#ifndef d_o_ex
	template<typename unchecked_type>_Myiter& operator+=(unchecked_type offset) {_PtrEx += offset;return (*this);}
	template<typename unchecked_type> _Myiter operator+(unchecked_type offset) {_Myiter TempPtr = *this;return TempPtr += offset;}
	template<typename unchecked_type> _Myiter operator-=(unchecked_type offset) {return *this + -offset;}
	template<typename unchecked_type> _Myiter operator-(unchecked_type offset) {_Myiter TempPtr = *this;return (TempPtr -= offset);}
	template<typename unchecked_type> unchecked_type operator-(const _Myiter& ccc) {return (this->_PtrEx - ccc._PtrEx);}
	template<typename unchecked_type> _Myiter& operator[](unchecked_type offset) {return (*(*this + offset));}
#endif
	bool operator==(const _Myiter& ccc) const {return (this->_PtrEx == ccc._PtrEx);}
	bool operator!=(const _Myiter& ccc) const {return (!(*this == ccc));}
	bool operator<(const _Myiter& ccc) const {return (this->_PtrEx < ccc._PtrEx);}
	bool operator>(const _Myiter& ccc) const {return (ccc < *this);}
	bool operator<=(const _Myiter& ccc) const {return (!(ccc < *this));}
	bool operator>=(const _Myiter& ccc) const {return (!(*this < ccc));}
	private: _MyPtr _PtrEx;
	};

template<class unchecked_type>
	class _const_array_iterator
	{ // const array iterator
	unchecked_type _Myarray;
	int _Mysize;
	int _Myindex;
public:
	typedef _const_array_iterator<unchecked_type> _MyT;
	typedef _MyT& _Myrefer;
	typedef typename unchecked_type difference_type;
	typedef typename unchecked_type *pointer;
	typedef typename unchecked_type& reference;
	_const_array_iterator(): _Myarray(), _Mysize(0), _Myindex(0){}
	_const_array_iterator(unchecked_type _Array, int _Size, int _Index = 0)
		: _Myarray(_Array), _Mysize(_Size), _Myindex(_Index){}
	unchecked_type base() const{return (_Myarray + _Myindex);}
	_MyT& _Rechecked(unchecked_type _Right){_Myindex = _Right - _Myarray;return (*this);}
	unchecked_type _Unchecked() const {return (base());}
	reference operator*() const {return (_Myarray[_Myindex]);}
	pointer operator->() const {return (**this);}
#ifndef d_o_ex
	bool operator==(const _MyT& _Right) const {return (_Myindex == _Right._Myindex);}
	bool operator!=(const _MyT& _Right) const {return (!(*this == _Right));}
	bool operator<(const _MyT& _Right) const {return (_Myindex < _Right._Myindex);}
	bool operator>(const _MyT& _Right) const {return (_Right < *this);}
	bool operator<=(const _MyT& _Right) const {return (!(_Right < *this));}
	bool operator>=(const _MyT& _Right) const {return (!(*this < _Right));}
#endif
	_Myrefer operator++() {++_Myindex;return (*this);}
	_MyT operator++(int) {_MyT _Tmp = *this;++*this;return (_Tmp);}
	_Myrefer operator--() {--_Myindex;return (*this);}
	_MyT operator--(int) {_MyT _Tmp = *this;--*this;return (_Tmp);}
	_Myrefer operator+=(difference_type _Off) {_Myindex += _Off;return (*this);}
	_MyT operator+(difference_type _Off) const {_MyT _Tmp = *this;return (_Tmp += _Off);}
	_Myrefer operator-=(difference_type _Off) {return (*this += -_Off);}
	_MyT operator-(difference_type _Off) const {_MyT _Tmp = *this;return (_Tmp -= _Off);}
	difference_type operator-(const _MyT& _Right) const {return (_Myindex - _Right._Myindex);}
	reference operator[](difference_type _Off) const {return (*(*this + _Off));}
	};

template<class _Iterator> inline
	typename _const_array_iterator<_Iterator>::_Iterator
	_Unchecked(_const_array_iterator<_Iterator> _Iter)
	{ // unchecked function
	return (_Iter._Unchecked());
	}

template<class _Iterator> inline
	_const_array_iterator<_Iterator>& _Rechecked(_const_array_iterator<_Iterator>& _Iter,
	typename _const_array_iterator<_Iterator>::_Iterator _Right)
	{ // rechecked function
	return (_Iter._Rechecked(_Right));
	}

template<class unchecked_type>	class 
	_list_linked
	: public _X_TYPE<unchecked_type>, public _X_COMMON<unchecked_type, unchecked_type, unchecked_type*>
	{  // linked list class
	typedef _list_linked<unchecked_type> _MyT;
	typedef _X_COMMON<unchecked_type, unchecked_type, unchecked_type*> _MyC;
	typedef typename _X_TYPE<unchecked_type>::Value_Type _MyVT;
	typedef typename _X_TYPE<unchecked_type>::Arrays _MyAY;
	typedef typename _X_TYPE<unchecked_type&>::UnPointer _MyUP;
	typedef typename _X_TYPE<unchecked_type*>::Pointer _MyPI;
	public:
	_list_linked() : Linked(0){}
	_list_linked(unchecked_type linked_node) : Data(linked_node), Linked(0){}
	_MyUP Get(){return Data;}
	_MyT*& Link(){return Linked;}private:
	_MyT* Linked;
	unchecked_type Data;
	};

template<class unchecked_type> 
class _linked_list;

template<class unchecked_type> class 
	_node
	{ // list node class
	friend class _linked_list<unchecked_type>;
	public:_node(const unchecked_type &info){data = info;nextPtr = 0;}
	unchecked_type getData() const{return data;}private:unchecked_type data;_node *nextPtr;
	};

template<class unchecked_type> class 
	_linked_list
	{ // linked list class
	typedef typename _node<unchecked_type> _MyLN;
	public: _linked_list(){firstPtr = lastPtr = 0;}~_linked_list()
	{if(!isEmpty()){_MyLN *currentPtr = firstPtr, *tempPtr;
	while(currentPtr != 0){tempPtr = currentPtr;currentPtr = currentPtr->nextPtr;delete tempPtr;}}}
	void insertAtFront(const unchecked_type &value){_MyLN *newPtr = getNewNode(value);
	if(!isEmpty())firstPtr = lastPtr = newPtr;else {lastPtr->nextPtr = newPtr;lastPtr = newPtr;}}
	void insertAtBack(const unchecked_type &value){_MyLN *newPtr = getNewNode(value);
	if(isEmpty())firstPtr = lastPtr = newPtr;else {lastPtr->nextPtr = newPtr;lastPtr = newPtr;}}int 
	removeFromFront(unchecked_type &value){if(isEmpty())return 0;else{_MyLN *tempPtr = firstPtr;
	if(firstPtr == lastPtr)firstPtr = lastPtr = 0;else firstPtr = firstPtr->nextPtr;value = tempPtr->data;
	delete tempPtr;return 1;}}int removeFromBack(unchecked_type &value){if(isEmpty())return 0;
	else{_MyLN *tempPtr = firstPtr;if(firstPtr == lastPtr)firstPtr = lastPtr = 0;
	else{_MyLN *currentPtr = firstPtr;while(currentPtr->nextPtr != lastPtr)currentPtr = 
	currentPtr->nextPtr;lastPtr = currentPtr;currentPtr->nextPtr = 0;}value = tempPtr->data;delete 
	tempPtr;return 1;}}int isEmpty() const{return firstPtr == 0;}private:_MyLN *firstPtr;
	_MyLN *lastPtr;_MyLN *getNewNode(const unchecked_type &value){_MyLN *ptr = new _MyLN(value);return ptr;}
	};

template<class unchecked_type> class
	shared_ptr
	: public _X_TYPE<unchecked_type>
	{ // shared ptr class
	typedef shared_ptr<unchecked_type> _MyT;
	typedef typename _X_TYPE<unchecked_type>::Value_Type _MyVT;
	typedef typename _X_TYPE<unchecked_type>::Arrays _MyAY;
	typedef typename _X_TYPE<unchecked_type&>::UnPointer _MyUP;
	typedef typename _X_TYPE<unchecked_type*>::Pointer _MyPI;
	_MyVT *_MyPtr; public: shared_ptr(_MyPI PtrHe){ _MyPtr = PtrHe; } explicit shared_ptr(_MyPI* PtrHeT) 
	{_MyPtr = reinterpret_cast<_MyPI> (PtrHeT);}~shared_ptr(){delete _MyPtr;}
	_MyPI operator*() const {return *_MyPtr;}_MyUP operator->() const {return _MyPtr;}
	};

template<class unchecked_type> class 
	auto_ptr
	: public _X_TYPE<unchecked_type>
	{ // auto ptr class
	typedef auto_ptr<unchecked_type> _MyT;
	typedef typename _X_TYPE<unchecked_type>::Value_Type _MyVT;
	typedef typename _X_TYPE<unchecked_type>::Arrays _MyAY;
	typedef typename _X_TYPE<unchecked_type&>::UnPointer _MyUP;
	typedef typename _X_TYPE<unchecked_type*>::Pointer _MyPI;_MyVT *_MyPtr;
	public: explicit auto_ptr(unchecked_type *_Ptr) : _MyPtr(_Ptr){} explicit 
	auto_ptr() : _MyPtr(0){}auto_ptr(_MyT& _met) : _MyPtr(_met.release()){}
	auto_ptr(_refer<unchecked_type> _met){unchecked_type *_Ptr = _met._ptr;_met._ptr = 0;_MyPtr = _Ptr;}
	template<class differentkindof_type>operator auto_ptr<differentkindof_type>()
	{return (auto_ptr<differentkindof_type>(*this));}
	template<class differentkindof_type>operator _refer<differentkindof_type>()
	{differentkindof_type *_buf = _MyPtr;_refer<differentkindof_type> _re(_buf);_MyPtr = 0;return (_re);}
	template<class differentkindof_type>_MyT& operator=(auto_ptr<differentkindof_type>& _met)
	{reset(_met.release());return (*this);}template<class differentkindof_type>auto_ptr
	(auto_ptr<differentkindof_type>& _met): _MyPtr(_met.release()){}_MyT& operator=(_MyT& _met)
	{reset(_met.release());return (*this);}_MyT& operator=(_refer<unchecked_type> _met)
	{_MyVT *_Ptr = _met._ptr;_met._ptr = 0;reset(_Ptr);return (*this);}~auto_ptr(){delete _MyPtr;}
	_MyVT& operator*() const {return (*get());}_MyVT *operator->() const {return (get());}
	_MyVT *get() const {return (_MyPtr);}_MyVT *release(){_MyVT *_Tmp = _MyPtr;_MyPtr = 0;return (_Tmp);}
	void reset(_MyVT *_ptr = 0){if (_ptr != _MyPtr)delete _MyPtr;_MyPtr = _ptr;}
	};

STR_TD X_ACCESS
	{ // access structure
	STR_PUBLICQ
		_ELF_LICENSE_NUMBER_CODE_EX int e_elf_t;
		int e_elf_acc_c;
		_ELF_LICENSE_ACCESS_CODE_EX int pass;
	} _ACCESS, *PTR_ACCESS, &REF_ACCESS;

STR_TD X_MESSAGE
	{ // message structure
	STR_PUBLICQ
		int e_lf_messge;
		int e_lf_t;
		int e_lf_left;
		int e_lf_right;
	} _MESSAGE, *PTR_MESSAGE, &REF_MESSAGE;

template<class unchecked_type> class 
	_access 
	: public _X_TYPE<unchecked_type>, 
	public _X_COMMON<unchecked_type, unchecked_type, unchecked_type*>
	{
	typedef _access<unchecked_type> _MyT;
	typedef _X_COMMON<unchecked_type, unchecked_type, unchecked_type*> _MyC;
	typedef typename _X_TYPE<unchecked_type>::Value_Type _MyVT;
	typedef typename _X_TYPE<unchecked_type>::Arrays _MyAY;
	typedef typename _X_TYPE<unchecked_type&>::UnPointer _MyUP;
	typedef typename _X_TYPE<unchecked_type*>::Pointer _MyPI;
	typedef _iterator<unchecked_type> _Myiter;

	public:

		template<typename differentkindof_type>
			void new_access_right(_MyVT _left, differentkindof_type _right)
			{
				Iterator->operator*() = _left;
			}

	private:
		_Myiter Iterator;
	};

/*=========================================================

			The Memory Allocator Class

	This class provides all the functions on the memory.
	You can redirect all pointers, and provides a number 
	of features for the user's convenience. In addition, 
	the array can be controlled sensitively. Similarly
	Memory Controller Class.

=========================================================*/

template<class _Ty,
		 class _Vector,
		 class _Pointer = _Ty *,
		 class _Reference = _Ty&>
		 struct _mem_allocator_ty
		 { // the ma type class
		 typedef _Vector Iterator;
		 typedef _Ty Value_Type;
		 typedef _Pointer Pointer;
		 typedef _Reference Reference;
		 };

template<class _Ty, 
		 class _Vector = _Ty, 
		 class _Pointer = _Ty *,
		 class _Reference = _Ty&>
class _mem_allocator
	: public _X_TYPE<_Ty>, 
	public _X_COMMON<_Ty, _Ty, _Ty*>,
	public _X_Memory<_Ty>,
	public _mem_allocator_ty<_Vector, _Ty, _Pointer, _Reference>
	{
	typedef _mem_allocator<_Ty, _Vector, _Pointer, _Reference> _MyT;
	#ifndef _USELESS_OF_COMMON
	typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
	#else
	typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
	#endif
	typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
	typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
	typedef typename _X_TYPE<_Ty>::UnPointer _MyUP;
	typedef typename _X_TYPE<_Ty>::Pointer _MyPI;
	typedef typename _mem_allocator_ty<_Ty, _Vector, _Pointer, _Reference>::Iterator _VeIC;
	//typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Iterator Iterator;
	typedef typename _mem_allocator_ty<_Ty, _Vector, _Pointer, _Reference>::Value_Type _VeT;
	typedef typename _mem_allocator_ty<_Ty, _Vector, _Pointer, _Reference>::Pointer _VePI;
	typedef typename _mem_allocator_ty<_Ty, _Vector, _Pointer, _Reference>::Reference _VeUP;
	typedef typename _X_Memory<_Ty> _XM;
	int size;
	_VePI List;
	int push_point;

	public:

	explicit _mem_allocator()
		: size(0), push_point(0)
		{ // entry of vector
		List = new _VeIC[sizeof(_VeIC)];
		}

	explicit _mem_allocator(int size)
		: size(size+1), push_point(0)
		{ // entry of vector
		List = new _VeIC[this->size - 1];
		}

	~_mem_allocator()
		{ // desconductor
		release();
		}

	int find(_MyVT what)
		{ // find the element in vector
		for(int f = 0; f <= this->size; f++)
			if(this->operator[f] == what)
				return f;
		return -1;
		}

	_VePI resize(_VePI Array, _MyVT size)
		{ // allocate array in memory
		_MyC::Set(size, const_cast<_VePI> (Array));
		_VePI buf = new _VeT[size];
		for(int f = 0; f <= this->size; f++)
			buf[f] = Array[f];
		this->List = buf;
		return buf;
		}

	void resize(_MyVT size)
		{ // allocate array in memory
		_MyC::Set(size, const_cast<_VePI> (List));
		_VePI buf = new _VeT[size];
		for(int f = 0; f <= this->size; f++)
			buf[f] = List[f];
		this->size = size;
		this->List = buf;
		}

	_VeT operator[](size_t size) const
		{ // operator [ size~ ]
		return (this->List[size]);
		}

	void operator>>(int size)
		{ // operator << decrease
		_MyC::Set(this->size, const_cast<_VePI> (List));
		_VePI buf = new _VeT[this->size - size];
		for(int i = 0; i <= size; i++)
			buf[i] = List[i+size];
		insertion(buf, this->size - size);
		}

	void operator<<(int size)
		{ // operator >> increase
		_MyC::Set(this->size, const_cast<_VePI> (List));
		_VePI buf = new _VeT[this->size + size];
		for(int i = 0; i <= this->size; i++)
			buf[i] = List[i];
		insertion(buf, this->size + size);
		}

	void operator=(_MyT& _List)
		{ // operator = equal
			BEGIN_TRY
		if((this->size && INT_MAX) <= 0) 
			THROW_ERROR_INPUT(_List)
		this->List = _List.List;
		this->push_point = _List.push_point;
		this->size = _List.size;
			END_TRY
			BEGIN_CATCH(_MyT _List)
		throw 0;
			END_CATCH
		}

	bool operator==(_MyT& _List)
		{ // if input = this
		return _List.List == this->List;
		}

	bool operator!=(_MyT& _List)
		{ // if not input = this
		return _List.List != this->List;
		}

	bool operator<(_MyT& _List)
		{ // compare to size
		return this->size < _List.size;
		}
	
	bool operator>(_MyT& _List)
		{ // compare to size
		return this->size > _List.size;
		}
	
	bool operator<=(_MyT& _List)
		{ // compare to size
		return this->size <= _List.size;
		}
	
	bool operator>=(_MyT& _List)
		{ // compare to size
		return this->size >= _List.size;
		}

	_MyT* operator->()
		{ // return this pointer
		return this;
		}

	void swap(_MyT& _List)
		{ // swap input and list
		int size=_List.size, pp=_List.push_point;
		_VeT* buf = new _VeT[_List.size];
		buf = _List.List;
		this->List = _List.List;
		this->size = _List.size;
		this->push_point = _List.push_point;
		_List.size = size;
		_List.new_vector(buf, size);
		_List.push_point = pp;
		}

	void insertion(_VePI _List, int _Size)
		{ // put info
		this->List = _List;
		this->size = _Size;
		this->push_point = _Size;
		}

	void clear()
		{ // clear the vector
			BEGIN_TRY
		if((this->size && INT_MAX) == 0)
			THROW_ERROR_INPUT(size)
		release();
		this->size = 0;
		this->push_point = 0;
			END_TRY
			BEGIN_CATCH(int size)
		throw 0;
			END_CATCH
		}

	void push_back(_VeT data)
		{ // push the data to back list
		_MyC::Set(size, const_cast<_VePI> (List));
		resize(List, size + 1);
		List[push_point++] = data;
		size++;
		}

	void push_back(_MyT& data)
		{ // push the data to back list
		_MyC::Set(size, const_cast<_VePI> (List));
		for(int i = 0; i <= data.size; i++)
			push_back(data.List[i]);
		}

	void push_back(_VeT* data, int size_)
		{ // push the data to back list
		_MyC::Set(size, const_cast<_VePI> (List));
		for(int i = 0; i <= size_; i++)
			push_back(data[i]);
		}

	void push_front(_VeT data)
		{ // push the data to front list
		_MyC::Set(size, const_cast<_VePI> (List));
		_VePI buf = List;
		resize(this->List, size + 1);
		for(int i = 0; i<= size + 1; i++)
			this->List[i + 1] = buf[i];
		this->List[0] = data;
		push_point++;
		size++;
		}

	void push_front(_VeT* data, int size_)
		{ // push the data to front list
		_MyC::Set(size, const_cast<_VePI> (List));
		for(int i = 0; i <= size_; i++)
			push_front(data[i]);
		}

	void push_front(_MyT& data)
		{ // push the data to back list
		_MyC::Set(size, const_cast<_VePI> (List));
		for(int i = 0; i <= data.size; i++)
			push_front(data.List[i]);
		}

	_VeT pop()
		{ // pop the data and return that
		_MyC::Set(size, const_cast<_VePI> (List));
		_VeT pop = List[size - 1];
		if (size>0){
		resize(--size);
		--this->push_point;}
		return pop;
		}

	void pop_back()
		{ // pop the data to back list
		_MyC::Set(size, const_cast<_VePI> (List));
		_VeT pop = List[size - 1];
		if (size>0){
		resize(--size);
		--this->push_point;}
		}

	void pop_front()
		{ // pop the data to front list
		_MyC::Set(size, const_cast<_VePI> (List));
		_VeT pop = this->List[0];
		_VePI buf = this->List;
		if (size>0)
		{for(int i = 0; i<= size - 1; i++)
			this->List[i - 1] = buf[i];
		resize(--size);
		--this->push_point;}
		}

	void fill(_VeT data)
		{ // fill list by data
		_MyC::Set(size, const_cast<_VePI> (List));
		for(int i = 0; i <= size; i++)
			List[i] = data;
		}

	void fill(size_t _point, _VeT data)
		{ // fill list by data
		_MyC::Set(size, const_cast<_VePI> (List));
		for(int i = 0; i <= _point; i++)
			List[i] = data;
		}

	void fill(_VeT data, size_t _point)
		{ // fill list by data
		_MyC::Set(size, const_cast<_VePI> (List));
		for(int i = _point; i <= size; i++)
			List[i] = data;
		}

	void fill(_VeT data, int _point, int size_)
		{ // fill list by data
		_MyC::Set(size, const_cast<_VePI> (List));
		for(int i = _point; i <= size_; i++)
			List[i] = data;
		}

	void reverse()
		{ // reverse the array point
		_MyC::Set(size, const_cast<_VePI> (List));
		_VeT * buf = new _VeT[size];
		int _size = size - 1;
		for(int i = 0; i <= _size; i++)
			buf[i] = pop();
		size = 0;
		for(int f = 0; f <= _size; f++)
			push_back(buf[f]);
		}

	void sort()
		{ // sorting list
		_MyC::Set(size, const_cast<_VePI> (List));
		int i, pass;
		_VeT hold;
		for(pass = 1; pass <= (size-1); pass++)
		for(i = 0; i <= (size-2); i++)
		if(List[i] > List[i + 1])
		{hold = List[i];
		List[i] = List[i + 1];
		List[i + 1] = hold;}
		}

	void erase(int point, int size_)
		{ // erase the data by p-s
		_MyC::Set(size, const_cast<_VePI> (List));
		int _size = size - (size_ + 1);
		_VePI buf = new _VeT[_size];
		for(int i = 0, f = 0; i<=size; i++)
		{if (point <= i <= (point+size_))continue;
		buf[f++] = List[i];}
		insertion(buf, _size);
		}

	void erase(int point)
		{ // erase the data by point at
		_MyC::Set(size, const_cast<_VePI> (List));
		_VePI buf = new _VeT[size - 1];
		for(int i = 0, f = 0; i < (size - 1); i++)
		{if(i == point) continue;
		buf[f++] = List[i];}
		insertion(buf, size - 1);
		}

	void insert(int point, _VeT Data)
		{ // insert the data to point
		_MyC::Set(size, const_cast<_VePI> (List));
		_VePI buf = new _VeT[size + 1];
		for(int i = 0; i < point; i++)buf[i] = List[i];
		for(int f = point + 1; f <= size; f++)buf[f] = List[f];
		buf[point] = Data;
		insertion(buf, size+1);
		}

	void insert(int point, int size_, _VeT Data)
		{ // insert the data to point
		_MyC::Set(size, const_cast<_VePI> (List));
		_VePI buf = new _VeT[size + size_];
		for(int i = 0; i < (size + size_); i++)
		{if(point <= i < (point + size_)) buf[i] = Data;
		buf[i] = List[i];}
		insertion(buf, size + size_);
		}

	_VeT at(int point)
		{ // return point
		if(point > size) 
			THROW_ERROR_INPUT(size)
		return List[point];
		}

	void assign(int n, _VeT Data)
		{ // put data by n
		for(int i = 0; i < n; i++)
			this->push_back(Data);
		}

	void asign(int n, int m, _VeT Data)
		{ // put data n ~ m
		for(int i = n; n <= m; i++)
			List[i] = Data;
		}

	_VeT front() const
		{ // get the front list item
		return List[0];
		}

	_VeT back() const
		{ // get the back list item
		return List[size - 1];
		}

	int size_r() const
		{ // return size
		return size - 1;
		}

	void new_vector()
		{ // create new vector
		if(if_size())
			release();
		_mem_allocator;
		this->size = 0;
		this->push_point = 0;
		}

	void new_memset(_VeT * _List, int size)
		{ // create new vector 
		_VePI listheap = new _VeT[size];
		for(int i = 0; i <= size; i++)
			listheap[i] = _List[i];
		this->List = listheap;
		}

	bool if_size() const
		{ // if size
		return (this->size && INT_MAX) > 0;
		}

	bool empty() const
		{ // if empty
		return size == 0;
		}

	void set_point(int point)
		{ // set point array
		if((point && INT_MAX) <= 0)
			exit(0);
		push_point = point;
		}

	void release() const
		{ // desconductor event
		_XM::free(List);
		}

	_VePI get_pi()
		{ // return list
		return (this->List);
		}

	int get_pp()
		{ // get push point
		return push_point;
		}

	};

template<class _TD> class 
	_vertex
	{ // vertex class
	public:
	struct VERTEX_INFO
	{struct VERTEX_SIZE
	{_TD X;_TD Y;_TD Z;};
	VERTEX_SIZE w1;
	VERTEX_SIZE w2;VERTEX_SIZE w3;};
#define VERTEX_INFO( _type ) _vertex<_type>::VERTEX_INFO
	public:
	_vertex():{}~_vertex(){Release();}
	void CreateVertex(VERTEX_INFO vtx){TVTBuf.push_back(vtx);}
	_TD operator[](int size_){if(size_<=TVTBuf.Size())return TVTBuf[size_];}
	_TD operator[](int size_) const{if(size_<=TVTBuf.Size())return TVTBuf[size_];}
	void Release(){TVTBuf.Release();}
	private: _mem_allocator<VERTEX_INFO> TVTBuf;
	};

template<class unchecked_type> struct
	__def
	{ // scope defination
	public:
	typedef typename unchecked_type value_type;
	typedef typename unchecked_type* pointer;
	typedef typename unchecked_type& reference;
	typedef typename unchecked_type** dipointer;
	};

template<class unchecked_type> struct
	__def<const unchecked_type>
	{ // scope defination
	public:
	typedef typename unchecked_type value_type;
	typedef typename unchecked_type* pointer;
	typedef typename unchecked_type& reference;
	};

template<class unchecked_type> struct
	__def<volatile unchecked_type>
	{ // scope defination
	public:
	typedef typename unchecked_type value_type;
	typedef typename unchecked_type* pointer;
	typedef typename unchecked_type& reference;
	};

template<class unchecked_type> struct
	__cdefine
	{ // c defined structure
	public:
	typedef typename __def<unchecked_type>::pointer pointer;
	typedef typename __def<unchecked_type>::value_type value_type;
	typedef typename __def<unchecked_type>::reference reference;
	};

template<class unchecked_type> struct
	__polydef 
	: __def<unchecked_type>
	{ // poly defined structure
	public:
	typedef typename __cdefine<__def<unchecked_type> >::pointer::pointer dipointer;
	typedef typename __cdefine<__cdefine<__def<unchecked_type> > >::pointer::pointer::pointer expointer;
	typedef typename __cdefine<__def<unchecked_type> >::reference::pointer refptr;
	typedef typename __cdefine<__def<unchecked_type> >::pointer::reference ptrref;
	typedef typename __cdefine<__def<unchecked_type> >::reference::reference diref;
	};

template<class unchecked_type> class
	_escape
	{ // escape class
	public:
	typedef _escape<__polydef<unchecked_type> > _MyT;
	_MyT Me;
	};

/*=========================================================

			The Remote Memory Class

	To this class, you may be able to fly to put the 
	memory already allocated on the heap. Referenced by 
	the pointer is being controlled, you can vary the 
	size of the memory allocated on the heap.

=========================================================*/

template<class unchecked_type> class
	_remote
	{ // remote memory class
	typedef typename __cdefine<unchecked_type>::pointer _MyPtr;
	public:

	template<typename different_type>
	_remote( _MyPtr& _Array, int _Size)
		: _Array( _Array ), _Size( _Size )
		{
		}

	_remote()
		: _Array( 0 ), _Size( 0 )
		{
		}

	void create_new(int size = 0)
		{
		_Array = new unchecked_type[size];
		_Size = size;
		}

	bool empty()
		{
		return _Size == 0;
		}

	void swap(_MyPtr& _Left, _MyPtr& _Right)
		{
		_swap(_Left, _Right);
		}

	shared_ptr<_MyPtr> _Array;
	int _Size;
	};

template<class unchecked_type> class
	_tree
	{
	typedef typename __cdefine<unchecked_type>::value_type _MyCVT;
	typedef typename __cdefine<unchecked_type>::pointer _MyPtr;
	typedef typename auto_ptr<_MyCVT> _MyPtrA;
	typedef typename auto_ptr<_MyPtrA> _MyPtrEx;

	#define _MyAlloc _mem_allocator
	_MyAlloc<_MyCVT> _MyAllocator;
	_MyAlloc<_MyCVT> _ElemAllocator;
	_MyAlloc<_MyPtrA> _MySequencer;

	public:
	CCCDEFALL(_tree)

	void CreateContainer(const char* _Name)
		{ // create container
		_MyAllocator.push_back(_Name);
		}

	void CreateElement(const char* _Name, const _MyCVT _elem)
		{ // creaet element
		_ElemAllocator.resize(_ElemAllocator.size_r() + _MyAllocator.find(_Name) * 8);
		_ElemAllocator[_MyAllocator.find(_Name) * 8] = _elem;

		}
	
	};

template<class unchecked_type> class
	_console
	{
	typedef typename __cdefine<unchecked_type>::value_type _MyT;
	public:


	};


	class Char
	{
	public:

		char GetCharInt(const char oper)
			{
				if('0' <= oper && oper <= '9')
					return oper - '0';
				if('A' <= oper && oper <= 'F')
					return oper - 'A' + 10;
				if('a'<= oper && oper <= 'f')
					return oper - 'a' + 10;
				return 0;
			}

		char GetIntChar(const char oper)
			{
				if(oper == 0)
					return 0;
				if(0 <= oper && oper <= 9)
					return oper + '0';
				if(10 <= oper && oper <= 16)
					return oper + 'a' - 10;
				return 0;
			}

		char CGetCharInt(const char oper)
			{
				if('0' <= oper && oper <= '9')
					return oper - '0';
				if(oper == 0)
					return 0;
			}

		char CGetIntChar(const char oper)
			{
				if(0 <= oper && oper <= 9)
					return oper + '0';
				if(oper == 0)
					return 0;
			}

		char* ReverseChar(char* oper)
			{
				int LEN = strlen(oper);
				char* buf = new char[LEN];
				for(int f = 0; f<=LEN; f++)
					buf[f] = 0;
				int i=0,k=0,j; 
				while(oper[i++]!=0)
					k++;
				for (i = 0, j = k - 1; i < k,j >= 0; i++, j--)
					buf[i] = oper[j];
				return buf;
			}

		char* ReverseChar(const char* oper)
			{
				int LEN = strlen(oper);
				char* buf = new char[LEN];
				for(int f = 0; f<=LEN; f++)
					buf[f] = 0;
				int i=0,k=0,j; 
				while(oper[i++]!=0)
					k++;
				for (i = 0, j = k - 1; i < k,j >= 0; i++, j--)
					buf[i] = oper[j];
				return buf;
			}

		char* ReverseChar(char* oper) const
			{
				int LEN = strlen(oper);
				char* buf = new char[LEN];
				for(int f = 0; f<=LEN; f++)
					buf[f] = 0;
				int i=0,k=0,j; 
				while(oper[i++]!=0)
					k++;
				for (i = 0, j = k - 1; i < k,j >= 0; i++, j--)
					buf[i] = oper[j];
				return buf;
			}

		char* ReverseChar(const char* oper) const
			{
				int LEN = strlen(oper);
				char* buf = new char[LEN];
				for(int f = 0; f<=LEN; f++)
					buf[f] = 0;
				int i=0,k=0,j; 
				while(oper[i++]!=0)
					k++;
				for (i = 0, j = k - 1; i < k,j >= 0; i++, j--)
					buf[i] = oper[j];
				return buf;
			}

		char* Trim(char* buf)
			{
				RTrim(buf);
				return LTrim(buf);
			}

		char* RTrim(char* buf)
			{
				char t[4096];
				char* end;
				strcpy(t, buf);
				end = t + strlen(t) - 1;
				while (end != t && isspace(*end))
					end--;
				*(end + 1) = 0;
				buf = t;
				return buf;
			}

		char* LTrim(char* buf)
			{
				char* begin;
				begin = buf;
				while (*begin != 0) {
					if (isspace(*begin))
						begin++;
					else {
						buf = begin;
						break;
					}
				}
				return buf;
			}
	};

	
	_CCC_B_TEMPLATE_CS
	template<typename _NT_MATH>
		class MATH{
		public:
			MATH();
			~MATH();
			void _Set(_NT_MATH,_NT_MATH);
			_NT_MATH _Get_Operator();
			_NT_MATH Add(_NT_MATH, _NT_MATH);
			_NT_MATH Sub(_NT_MATH, _NT_MATH);
			_NT_MATH Mul(_NT_MATH, _NT_MATH);
			_NT_MATH Div(_NT_MATH, _NT_MATH);
			_NT_MATH Sqrt(_NT_MATH);
			_NT_MATH Square(_NT_MATH, int);
			_NT_MATH Reci(_NT_MATH);
			_NT_MATH Fact(int);
			_NT_MATH NI(_NT_MATH);
			_NT_MATH IN(_NT_MATH);
			_NT_MATH Sin(_NT_MATH);
			_NT_MATH Cos(_NT_MATH);
			_NT_MATH Tan(_NT_MATH);
			_NT_MATH Log(_NT_MATH);
			_NT_MATH Permutation(int,int);
			_NT_MATH Combination(int,int);

		private:
			_NT_MATH _Operand;
			_NT_MATH _Operator;

		};

		#define max(a,b)            (((a) > (b)) ? (a) : (b))
		#define min(a,b)            (((a) < (b)) ? (a) : (b))
		#define inc(a)				((a) + 1)
		#define des(a)				((a) - 1)
		#define abs(num)			( num > 0 ? num : ( num * -1 ))
		#define Mov(a,b)			((a) % (b))

		#define E					2.71828182845904523536
		#define PI					3.14159265358979323846
		#define RATIO				0.01745329251994329576923690768489

		#define Tf(x)				Div(Square(Operand, x),		Fact(x))
		#define Tff(x, y, z)		Div(Square(Operand, x) * y,	Fact(z))

		//<-- 2013-02-20 Extra Set

		#define SIN_30	0.50000000000000000000000000000000
		#define SIN_60  0.86602540378443864676372317075294
		#define SIN_90	1.00000000000000000000000000000000
		#define COS_30  0.86602540378443864676372317075294
		#define COS_60	0.50000000000000000000000000000000
		#define COS_90	0.00000000000000000000000000000000
		#define TAN_30	0.57735026918962576450914878050196
		#define TAN_60	1.7320508075688772935274463415059

		//-->

		template<class _NT_MATH> inline
		MATH<_NT_MATH>::MATH()
		{
			_Operand = 0; 
			_Operator = 0;
		}

		template<class _NT_MATH> inline
		MATH<_NT_MATH>::~MATH()
		{	}

		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::_Get_Operator()
		{ 
			return _Operator; 
		}
		template<class _NT_MATH> inline
		void MATH<_NT_MATH>::_Set(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			_Operand = Operand; 
			_Operator = Operator; 
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Add(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			return Operand + Operator; 
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Sub(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			return Operand - Operator; 
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Mul(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			return Operand * Operator;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Div(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			return Operand / Operator;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Reci(_NT_MATH Operand)
		{ 
			return 1 / Operand;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Sqrt(_NT_MATH Operand)
		{ 
			_NT_MATH Next, Temp;
			Next = 0.5 * (1 + (Operand / 1));
			for(;;)
			{
				Temp = Next;
				Next = 0.5 * (Next + (Operand / Next));
				if(Temp - Next < 0.005 || Temp - Next < - 0.005)
				break;
			}
			return Next;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Square(_NT_MATH Operand,int SquareSet)
		{ 
			_NT_MATH Buffer = 1;
			while(SquareSet-- > 0) 
			{
				Buffer *= Operand;
			}
			return Buffer;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Fact(int Operand)
		{ 
			_NT_MATH i; 
			if(Operand >= 2)
			{
				i = Operand * Fact(Operand - 1);
			}else{
				i=1; 
			}
			return i;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::NI(_NT_MATH Operand)
		{ 
			return 1 + Tf(1) + Tf(2) + Tf(3) +
				Tf(4) + Tf(5) + Tf(6) + Tf(7) + Tf(8) + Tf(9) + Tf(10) + Tf(11) + Tf(12) + Tf(13) + Tf(14) 
				+ Tf(15) + Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20);	
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::IN(_NT_MATH Operand)
		{ 
			return Tf(1) + Tf(2) + Tf(3) + Tf(4) + Tf(5) + Tf(6) + Tf(7) + Tf(8) +
				Tf(9) + Tf(10) + Tf(11) + Tf(12) + Tf(13) + Tf(14) + Tf(15) + Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Sin(_NT_MATH Operand)
		{ 
			Operand *= RATIO;
			return Operand - Tf(3) + Tf(5) - Tf(7) + Tf(9) - Tf(11);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Cos(_NT_MATH Operand)
		{
			Operand *= RATIO;
			return 1 - Tf(2) + Tf(4) - Tf(6) + Tf(8) - Tf(10);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Tan(_NT_MATH Operand)
		{ 
			Operand *= RATIO;
			return Tff(1,1,1) + Tff(2,3,3) + Tff(16,5,5) + Tff(272,7,7) + Tff(7936,9,9) + Tff(353792,11,11);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Log(_NT_MATH Operand)
		{ 
			return Div(IN(Operand),2.30258);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Permutation(int Operand, int Operator)
		{
			_NT_MATH i;
			i = Operand;
			while(i-- > Operator)
			{
				Operand *= i;
			}
			return Operand;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Combination(int Operand,int Operator)
		{
			return Permutation(Operand,Operator)
				/
				Fact(Operator);
		}//2012-10-27 Check.h<by rollrat>

		
	template<class _Ty, 
			class _Pointer = _Ty*, 
			class _Reference = _Ty&>
		struct _X_MATH_EX
		{ // File struct
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Pointer Pointer;
		typedef _Reference Reference;
		};

	_CCC_B_TEMPLATE_CS
	template<class _Ty>
		class MATH_EX
			: public _X_MATH_EX<_Ty>, 
			public MATH<_Ty>
		{
			typedef MATH_EX<_Ty> _MyT;
			typedef typename _X_MATH_EX<_Ty>::Value_Type _MyVT;
			typedef typename _X_MATH_EX<_Ty>::Reference _MyRE;
			typedef typename _X_MATH_EX<_Ty>::Pointer _MyPI;
			typedef MATH<_Ty>	_MyTH;
		public:

			struct _point{_Ty x; _Ty y;};
			struct _triangle{_Ty w1; _Ty w2; _Ty w3; _Ty area;};
			struct function{_Ty x; _Ty y; _Ty z;};

			function Equation_Substitution(char* equation, char* variable, _Ty* variables)
				{
					
				}

		};


	#define MAX_CHAR 32767

	typedef enum Sign
	{
		minus	= -1,
		zero	= 0,
		plus	= 1,
	};

	typedef enum Signe
	{
	};
	
	class UInteger
		: public Char
	{
	public:

		UInteger()
			: Sign(zero), Length(0)
			{ // entry point
				uintegerbuf = new char[MAX_CHAR];
				for(register int i = 0; i <= MAX_CHAR; i++)
					uintegerbuf[i] = 0;
				uintegerbuf[0] = '0';
 			}

		~UInteger()
			{
				delete[] uintegerbuf;
			}

		void SetLength()
			{ // set this length
				register long long i = 0, len = 0;
				while(uintegerbuf[i++] != 0);
				Length = len;
			}

		Sign GetSign() const
			{ // get sign
				return Sign;
			}

		long long GetLenth() const
			{ // get lenth
				return Length;
			}

		char* getbuf() const
			{
				return Char::ReverseChar(uintegerbuf);
			}

		void operator++() 
			{ // increase integer
				for(register long long i = 0; i <= Length + 1; i++)
				{
					if(uintegerbuf[i] == 0)
					{
						uintegerbuf[i] = '1';
						goto exit_for;
					}
					if('0' <= uintegerbuf[i] && uintegerbuf[i] <= '8')
					{
						uintegerbuf[i] = uintegerbuf[i] + 1;
						goto exit_for;
					}
					if(uintegerbuf[i] == '9')
						uintegerbuf[i] = '0';
				}
exit_for:
				SetLength();
			}

		void operator--() 
			{ // decrease integer
				for(register long long i = 0; i <= Length + 1; i++)
				{
					if('1' <= uintegerbuf[i] && uintegerbuf[i] <= '9')
					{
						uintegerbuf[i] = uintegerbuf[i] - 1;
						goto exit_for;
					}
					if(uintegerbuf[i] == '0')
						uintegerbuf[i] = '9';
				}
exit_for:
				SetLength();
			}

		void operator+=(const int me)
			{
				char* buf = new char[MAX_CHAR];
				itoa(me, buf, 10);
				for(register long long i = 0; i <= strlen(buf); i++)
					if ('0' <= buf[i] && buf[i] <= '9');
						else buf[i] = 0;
				operator+=(buf);
				delete[] buf;
			}

		void operator+=(const char* _me)
			{// Memory 520MB -> 1.7MB
				char* me ;//= new char[MAX_CHAR];
				//for(int i = 0; i <= MAX_CHAR; i++)
				//	me[i] = 0;
				me = Char::ReverseChar(_me);
				for(register long long i = 0; i <= strlen(me) - 1; i++)
				{
					if(0 <= (Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i])) && (Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i])) < 10)
					{
						uintegerbuf[i] = Char::CGetIntChar(Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i]));
					}
					else if(10 <= (Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i])) && (Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i])) <= 18 )
					{
						uintegerbuf[i] = Char::CGetIntChar(Char::CGetCharInt(me[i]) + Char::CGetCharInt(uintegerbuf[i]) - 10);
						plusencomecharinnexparameter(i + 1);
					}
				}
			}

		void operator-=(const char* _me)
			{
				char* me = new char[MAX_CHAR];
				for(register int i = 0; i <= MAX_CHAR; i++)
					me[i] = 0;
				me = Char::ReverseChar(_me);
				for(register long long i = 0; i <= strlen(me) - 1; i++)
				{
					if(1 <= (Char::CGetCharInt(uintegerbuf[i]) - Char::CGetCharInt(me[i])) && (Char::CGetCharInt(uintegerbuf[i]) - Char::CGetCharInt(me[i])) < 10)
					{
						uintegerbuf[i] = Char::CGetIntChar(Char::CGetCharInt(uintegerbuf[i]) - Char::CGetCharInt(me[i]));
					}
				}
			}

		void plusencomecharinnexparameter(long long state)
			{
				if(uintegerbuf[state] == '9')
					plusencomecharinnexparameter(state + 1);
				else
					if(uintegerbuf[state] == 0)
						uintegerbuf[state] = '1';
					else
						uintegerbuf[state] = uintegerbuf[state] + 1;
			}

		void minusencomecharinnexparameter(long long state)
			{
				if(uintegerbuf[state] == '0')
					minusencomecharinnexparameter(state + 1);
				else
					if(uintegerbuf[state] == 0)
						uintegerbuf[state] = '9';
					else
						uintegerbuf[state] = uintegerbuf[state] - 1;
			}

		unsigned long long checkprime(unsigned long long num)
			{
				unsigned long long sqrtprimenum = (unsigned long long)sqrt(num);
				register unsigned long long div = sqrtprimenum;
				for(; num %div; div--);
				return div;
			}
		
		void operator=(const UInteger& me){uintegerbuf = Char::ReverseChar(me.uintegerbuf); }
		void operator=(const int me){itoa(me, uintegerbuf, 10);uintegerbuf = Char::ReverseChar(uintegerbuf);SetLength();}
		void operator=(const char* cp){uintegerbuf = Char::ReverseChar(cp);SetLength();}

	private:

		char* uintegerbuf;
		Sign Sign;
		long long Length;

	};

	std::ostream &operator <<(std::ostream &os, const UInteger& x) 
	{
		if (x.GetSign() == Sign::minus)
			os << '-';
		os << x.getbuf();
		return os;
	}


	_CCC_C_TEMPLATE_CS
	template<class _Ty,
			 class _Vector,
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
			 struct _X_Vector_Ty
			 { // the vector type class
			 typedef _Vector Iterator;
			 typedef _Ty Value_Type;
			 typedef _Pointer Pointer;
			 typedef _Reference Reference;
			 };

	_CCC_C_TEMPLATE_CS
	template<class differentkindof_type> class
		_const_iterator_vex
	{ // const iterator class
		typedef _const_iterator_vex<differentkindof_type> _Myiter;
		typedef typename _Myiter* _MyPtr;
	public:
		_const_iterator_vex() : _PtrEx() { }
		_Myiter& operator*() const {return (*this->_PtrEx);}
		_MyPtr operator->() const {return (**this);}
		_Myiter& operator++() {++this->_PtrEx;return (*this);}
		_Myiter operator++(int) {_Myiter TempPtr = *this;++*this;return (TempPtr);}
		_Myiter operator--() {--this->_PtrEx;return (*this);}
		_Myiter operator--(int) {_Myiter TempPtr = *this;--*this;return (TempPtr);}
		template<typename unchecked_type> _Myiter& operator+=(unchecked_type offset) {_PtrEx += offset;return (*this);}
		template<typename unchecked_type> _Myiter operator+(unchecked_type offset) const {_Myiter TempPtr = *this;return TempPtr += offset;}
		template<typename unchecked_type> _Myiter operator-=(unchecked_type offset) {return *this + -offset;}
		template<typename unchecked_type> _Myiter operator-(unchecked_type offset) const {_Myiter TempPtr = *this;return (TempPtr -= offset);}
		template<typename unchecked_type> unchecked_type operator-(const _Myiter& ccc) const {return (this->_PtrEx - ccc._PtrEx);}
		template<typename unchecked_type> _Myiter& operator[](unchecked_type offset) const {return (*(*this + offset));}
		bool operator==(const _Myiter& ccc) const {return (this->_PtrEx == ccc._PtrEx);}
		bool operator!=(const _Myiter& ccc) const {return (!(*this == ccc));}
		bool operator<(const _Myiter& ccc) const {return (this->_PtrEx < ccc._PtrEx);}
		bool operator>(const _Myiter& ccc) const {return (ccc < *this);}
		bool operator<=(const _Myiter& ccc) const {return (!(ccc < *this));}
		bool operator>=(const _Myiter& ccc) const {return (!(*this < ccc));}
	private: _MyPtr _PtrEx;
	};

	template<class differentkindof_type> class
		_iterator_vex
	{ // const iterator class
		typedef _iterator_vex<differentkindof_type> _Myiter;
		typedef typename _Myiter* _MyPtr;
	public:
		_iterator_vex() : _PtrEx() { }
		_Myiter& operator*() {return (*this->_PtrEx);}
		_MyPtr operator->() {return (**this);}
		_Myiter& operator++() {++this->_PtrEx;return (*this);}
		_Myiter operator++(int) {_Myiter TempPtr = *this;++*this;return (TempPtr);}
		_Myiter operator--() {--this->_PtrEx;return (*this);}
		_Myiter operator--(int) {_Myiter TempPtr = *this;--*this;return (TempPtr);}
		template<typename unchecked_type>_Myiter& operator+=(unchecked_type offset) {_PtrEx += offset;return (*this);}
		template<typename unchecked_type> _Myiter operator+(unchecked_type offset) {_Myiter TempPtr = *this;return TempPtr += offset;}
		template<typename unchecked_type> _Myiter operator-=(unchecked_type offset) {return *this + -offset;}
		template<typename unchecked_type> _Myiter operator-(unchecked_type offset) {_Myiter TempPtr = *this;return (TempPtr -= offset);}
		template<typename unchecked_type> unchecked_type operator-(const _Myiter& ccc) {return (this->_PtrEx - ccc._PtrEx);}
		template<typename unchecked_type> _Myiter& operator[](unchecked_type offset) {return (*(*this + offset));}
		bool operator==(const _Myiter& ccc) const {return (this->_PtrEx == ccc._PtrEx);}
		bool operator!=(const _Myiter& ccc) const {return (!(*this == ccc));}
		bool operator<(const _Myiter& ccc) const {return (this->_PtrEx < ccc._PtrEx);}
		bool operator>(const _Myiter& ccc) const {return (ccc < *this);}
		bool operator<=(const _Myiter& ccc) const {return (!(ccc < *this));}
		bool operator>=(const _Myiter& ccc) const {return (!(*this < ccc));}
	private: _MyPtr _PtrEx;
	};

	_CCC_C_TEMPLATE_CS
	template<class _Ty, 
			 class _Vector = _Ty, 
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
	class _X_Vector_Ex 
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Memory<_Ty>,
		public _X_Vector_Ty<_Vector, _Ty, _Pointer, _Reference>
		{
		typedef _X_Vector_Ex<_Ty, _Vector, _Pointer, _Reference> _MyT;
		#ifndef _USELESS_OF_COMMON
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		#else
		typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
		#endif
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _X_TYPE<_Ty>::UnPointer _MyUP;
		typedef typename _X_TYPE<_Ty>::Pointer _MyPI;

		public:
		typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Iterator _VeIC;
		//typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Iterator Iterator;
		typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Value_Type _VeT;
		typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Pointer _VePI;
		typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Reference _VeUP;
		typedef typename _X_Memory<_Ty> _XM;

		public:

			explicit _X_Vector_Ex()
				: size(0), push_point(0)
				{ // entry of vector
				List = new _VeIC[sizeof(_VeIC)];
				}

			explicit _X_Vector_Ex(int size)
				: size(size+1), push_point(0)
				{ // entry of vector
				List = new _VeIC[this->size - 1];
				}

			~_X_Vector_Ex()
				{ // desconductor
				release();
				}

			_VePI resize(_VePI Array, _MyVT size)
				{ // allocate array in memory
				_MyC::Set(size, const_cast<_VePI> (Array));
				_VePI buf = new _VeT[size];
				for(int f = 0; f <= this->size; f++)
					buf[f] = Array[f];
				this->List = buf;
				return buf;
				}

			void resize(_MyVT size)
				{ // allocate array in memory
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[size];
				for(int f = 0; f <= this->size; f++)
					buf[f] = List[f];
				this->size = size;
				this->List = buf;
				}

			_VeT operator[](size_t size) const
				{ // operator [ size~ ]
				return (this->List[size]);
				}

			void operator>>(int size)
				{ // operator << decrease
				_MyC::Set(this->size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[this->size - size];
				for(int i = 0; i <= size; i++)
					buf[i] = List[i+size];
				insertion(buf, this->size - size);
				}

			void operator<<(int size)
				{ // operator >> increase
				_MyC::Set(this->size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[this->size + size];
				for(int i = 0; i <= this->size; i++)
					buf[i] = List[i];
				insertion(buf, this->size + size);
				}

			void operator=(_MyT& _List)
				{ // operator = equal
					BEGIN_TRY
				if((this->size && INT_MAX) <= 0) 
					THROW_ERROR_INPUT(_List)
				this->List = _List.List;
				this->push_point = _List.push_point;
				this->size = _List.size;
					END_TRY
					BEGIN_CATCH(_MyT _List)
				throw 0;
					END_CATCH
				}

			bool operator==(_MyT& _List)
				{ // if input = this
				return _List.List == this->List;
				}

			bool operator!=(_MyT& _List)
				{ // if not input = this
				return _List.List != this->List;
				}

			bool operator<(_MyT& _List)
				{ // compare to size
				return this->size < _List.size;
				}
			
			bool operator>(_MyT& _List)
				{ // compare to size
				return this->size > _List.size;
				}
			
			bool operator<=(_MyT& _List)
				{ // compare to size
				return this->size <= _List.size;
				}
			
			bool operator>=(_MyT& _List)
				{ // compare to size
				return this->size >= _List.size;
				}

			_MyT* operator->()
				{ // return this pointer
				return this;
				}

			void swap(_MyT& _List)
				{ // swap input and list
				int size=_List.size, pp=_List.push_point;
				_VeT* buf = new _VeT[_List.size];
				buf = _List.List;
				this->List = _List.List;
				this->size = _List.size;
				this->push_point = _List.push_point;
				_List.size = size;
				_List.new_vector(buf, size);
				_List.push_point = pp;
				}

			void insertion(_VePI _List, int _Size)
				{ // put info
				this->List = _List;
				this->size = _Size;
				this->push_point = _Size;
				}

			void clear()
				{ // clear the vector
					BEGIN_TRY
				if((this->size && INT_MAX) == 0)
					THROW_ERROR_INPUT(size)
				release();
				this->size = 0;
				this->push_point = 0;
					END_TRY
					BEGIN_CATCH(int size)
				throw 0;
					END_CATCH
				}

#if defined(_ELF_COMMON) // use  _X_COMMON<_Ty, _Ty, _Ty*> set

			void push_back(_VeT data)
				{ // push the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				resize(List, size + 1);
				List[push_point++] = data;
				size++;
				}

			void push_back(_MyT& data)
				{ // push the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= data.size; i++)
					push_back(data.List[i]);
				}

			void push_back(_VeT* data, int size_)
				{ // push the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= size_; i++)
					push_back(data[i]);
				}

			void push_front(_VeT data)
				{ // push the data to front list
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = List;
				resize(this->List, size + 1);
				for(int i = 0; i<= size + 1; i++)
					this->List[i + 1] = buf[i];
				this->List[0] = data;
				push_point++;
				size++;
				}

			void push_front(_VeT* data, int size_)
				{ // push the data to front list
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= size_; i++)
					push_front(data[i]);
				}

			void push_front(_MyT& data)
				{ // push the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= data.size; i++)
					push_front(data.List[i]);
				}

			_VeT pop()
				{ // pop the data and return that
				_MyC::Set(size, const_cast<_VePI> (List));
				_VeT pop = List[size - 1];
				if (size>0){
				resize(--size);
				--this->push_point;}
				return pop;
				}

			void pop_back()
				{ // pop the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				_VeT pop = List[size - 1];
				if (size>0){
				resize(--size);
				--this->push_point;}
				}

			void pop_front()
				{ // pop the data to front list
				_MyC::Set(size, const_cast<_VePI> (List));
				_VeT pop = this->List[0];
				_VePI buf = this->List;
				if (size>0)
				{for(int i = 0; i<= size - 1; i++)
					this->List[i - 1] = buf[i];
				resize(--size);
				--this->push_point;}
				}

			void fill(_VeT data)
				{ // fill list by data
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= size; i++)
					List[i] = data;
				}

			void fill(size_t _point, _VeT data)
				{ // fill list by data
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= _point; i++)
					List[i] = data;
				}

			void fill(_VeT data, size_t _point)
				{ // fill list by data
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = _point; i <= size; i++)
					List[i] = data;
				}

			void fill(_VeT data, int _point, int size_)
				{ // fill list by data
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = _point; i <= size_; i++)
					List[i] = data;
				}

			void reverse()
				{ // reverse the array point
				_MyC::Set(size, const_cast<_VePI> (List));
				_VeT * buf = new _VeT[size];
				int _size = size - 1;
				for(int i = 0; i <= _size; i++)
					buf[i] = pop();
				size = 0;
				for(int f = 0; f <= _size; f++)
					push_back(buf[f]);
				}

			void sort()
				{ // sorting list
				_MyC::Set(size, const_cast<_VePI> (List));
				int i, pass;
				_VeT hold;
				for(pass = 1; pass <= (size-1); pass++)
				for(i = 0; i <= (size-2); i++)
				if(List[i] > List[i + 1])
				{hold = List[i];
				List[i] = List[i + 1];
				List[i + 1] = hold;}
				}

			void erase(int point, int size_)
				{ // erase the data by p-s
				_MyC::Set(size, const_cast<_VePI> (List));
				int _size = size - (size_ + 1);
				_VePI buf = new _VeT[_size];
				for(int i = 0, f = 0; i<=size; i++)
				{if (point <= i <= (point+size_))continue;
				buf[f++] = List[i];}
				insertion(buf, _size);
				}

			void erase(int point)
				{ // erase the data by point at
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[size - 1];
				for(int i = 0, f = 0; i < (size - 1); i++)
				{if(i == point) continue;
				buf[f++] = List[i];}
				insertion(buf, size - 1);
				}

			void insert(int point, _VeT Data)
				{ // insert the data to point
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[size + 1];
				for(int i = 0; i < point; i++)buf[i] = List[i];
				for(int f = point + 1; f <= size; f++)buf[f] = List[f];
				buf[point] = Data;
				insertion(buf, size+1);
				}

			void insert(int point, int size_, _VeT Data)
				{ // insert the data to point
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[size + size_];
				for(int i = 0; i < (size + size_); i++)
				{if(point <= i < (point + size_)) buf[i] = Data;
				buf[i] = List[i];}
				insertion(buf, size + size_);
				}

#endif

			_VeT at(int point)
				{ // return point
				if(point > size) 
					THROW_ERROR_INPUT(size)
				return List[point];
				}

			void assign(int n, _VeT Data)
				{ // put data by n
				for(int i = 0; i < n; i++)
					this->push_back(Data);
				}

			void asign(int n, int m, _VeT Data)
				{ // put data n ~ m
				for(int i = n; n <= m; i++)
					List[i] = Data;
				}

			_VeT front() const
				{ // get the front list item
				return List[0];
				}

			_VeT back() const
				{ // get the back list item
				return List[size - 1];
				}

			int size_r() const
				{ // return size
				return size - 1;
				}

			void new_vector()
				{ // create new vector
				if(if_size())
					release();
				_X_Vector_Ex;
				this->size = 0;
				this->push_point = 0;
				}

			void new_vector(_VeT * _List, int size)
				{ // create new vector 
				_VePI listheap = new _VeT[size];
				for(int i = 0; i <= size; i++)
					listheap[i] = _List[i];
				this->List = listheap;
				}

			bool if_size() const
				{ // if size
				return (this->size && INT_MAX) > 0;
				}

			bool empty() const
				{ // if empty
				return size == 0;
				}

			void set_point(int point)
				{ // set point array
				if((point && INT_MAX) <= 0)
					exit(0);
				push_point = point;
				}

			void release() const
				{ // desconductor event
				_XM::free(List);
				}

			_VePI get_pi()
				{ // return list
				return (this->List);
				}

			int get_pp()
				{
				return push_point;
				}

		private:

			int size;
			_VePI List;
			int push_point;

		};

	/*=========================================================

				The Memory Controller Class

		This class provides all the functions on the memory.
		You can redirect all pointers, and provides a number 
		of features for the user's convenience. In addition, 
		the array can be controlled sensitively.

	=========================================================*/

	_CCC_C_TEMPLATE_CS
	template<class _Ty,
			 class _InputT = unsigned,
			 class _Vector = _Ty, 
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
	class _X_Mem_Controller
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Memory<_Ty>
		{
		typedef _X_Mem_Controller<_Ty> _MyT;
		#ifndef _USELESS_OF_COMMON
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		#else
		typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
		#endif
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _Reference _MyUP;
		typedef typename _Pointer _MyPI;

		public:
		typedef typename _X_Memory<_Ty> _XM;

		#define COMMON_INCLASS_USEAGE_FOR _InputT n = 0; n <= arange; n++

		public:
			
			template<class _TyX>
			_TyX& ForceChangeType(_MyPI& _Val)
				{ // get volatile 
				return reinterpret_cast<_TyX&>(_Val);
				}

			_InputT AddressOf(_MyPI& _Val)
				{ // return address of _Val
				return reinterpret_cast<_InputT>(&
					const_cast<_InputT&>
					(ForceChangeType<const volatile _InputT>(_Val)));
				}

			_MyPI ForceArraySet(_MyPI array_, const _InputT set)
				{ // force array value changed
				if(!set)
					return array_;
				array_ = new _MyVT[set];
				return array_;
				}

			_MyPI ForceArraySetWithKeep(const _MyPI array_, 
					const _InputT arange, const _InputT set)
				{ // force array value changed with keep the data
				_MyPI buf = new _MyVT[set];
				for(COMMON_INCLASS_USEAGE_FOR)
					buf[f] = array_[f];
				return buf;
				}

			_MyPI Fill(_MyPI array_, _MyVT value, const _InputT arange)
				{ // fill data by arange to array
				for(COMMON_INCLASS_USEAGE_FOR)
					array_[n] = value;
				return array_;
				}

			_MyPI ZeroMemory(_MyPI array_, const _InputT arange)
				{ // fill zero data by arange to array
				for(COMMON_INCLASS_USEAGE_FOR)
					array_[n] = 0;
				return array_;
				}

			_MyPI Copying(_MyPI oper, const _MyPI array_, const _InputT arange)
				{ // copy datas by arange to array
				for(COMMON_INCLASS_USEAGE_FOR)
					oper[n] = array_[n];
				return oper;
				}

			_MyPI Moving(const _MyPI oper, _MyPI array_, const _InputT arange)
				{ // move data array_ to oper
				for(COMMON_INCLASS_USEAGE_FOR)
					array_[n] = oper[n];
				ZeroMemory(oper, arange);
				return oper;
				}

			_MyPI Swaping(_MyPI oper, _MyPI array_)
				{ // swap from datas to datas
				_MyUP buf1 = *oper;
				_MyUP buf2 = *array_;
				oper = &buf2;
				array_ = &buf1;
				return oper;
				}

			_MyVT SwapVT(_MyVT oper, _MyVT array_)
				{ // swap from data to data
				_MyVT buf = *oper;
				*oper = *array_;
				*array_ = buf;
				return oper;
				}

			_InputT CountItem(_MyPI array_, _MyVT data, const _InputT arange)
				{ // count array item
				_InputT retbuf = 0;
				for(COMMON_INCLASS_USEAGE_FOR)
					if(array_[n] == data)
						retbuf++;
				return retbuf;
				}

			_InputT CountArray(_MyPI array_, _MyVT data, 
					const _InputT first_array_size, const _InputT second_array_size)
				{ // count array items in other array by size
				_InputT retbuf = 0;
				_InputT startat;
				bool state = false;
				for(_InputT n = 0; n <= first_array_size; n++)
					for(_InputT f = 0; f <= second_array_size; f++)
						if(array_[n] == data[f]){
							if(state)startat = array_[n];
								retbuf++;if(retbuf == second_array_size) return startat;}
							else{retbuf = 0;state = false;}
				return 0;
				}

			void ReleaseArray(_MyPI array_, const _InputT array_size)
				{ // release array
				for(_InputT n = 0; n <= array_size; n++)
					delete array_[n];
				delete[] array_;
				}

			void ReleaseArray(_MyPI array_)
				{ // release array
				delete[] array_;
				}

			_MyPI PasteArray(_MyPI array_, _MyVT data, 
					const _InputT first_array_size, const _InputT second_array_size)
				{ // paste two array
				_MyPI buf = new _MyVT[first_array_size + second_array_size];
				_InputT at = 0;
				for(_InputT n = 0; n <= first_array_size; n++, at++)
					buf[n] = array_[n];
				for(_InputT n = 0; n <= second_array_size; n++)
					buf[n + at] = data[n];
				return buf;
				}

			void SetCommonArray(const _MyPI array_, const _InputT size)
				{ // set common array
				CommonArray = new _MyVT[size];
				CommonSize = size;
				Copying(CommonArray, array_, size);
				}

			_MyPI operator>>(const int shift_value)
				{ // create new array which size is basisvalue + shiftvalue
				_MyPI buf = new _MyVT[CommonSize + shift_value];
				for(int n = shift_value; n <= (CommonSize + shift_value); n++)
					buf[n] = CommonArray[n - shift_value];
				return buf;
				}

			_MyPI operator<<(const int shift_value)
				{ // create new array which size is basisvalue - shiftvalue
				if(CommonSize < shift_value)
					throw this*;
				_MyPI buf = new _MyVT[CommonSize - shift_value];
				for(int n = 0; n <= (CommonSize - shift_value); n++)
					buf[n] = CommonArray[n + shift_value];
				return buf;
				}

			_MyPI ReverseArray(_MyPI array_, const _InputT array_size)
				{ // reverse the array
				_MyPI buf = new _MyVT[array_size];
				ZeroMemory(buf, array_size);
				for(_InputT n = 0, f = array_size; n <= array_size; n++, f--)
					buf[n] = array_[f];
				return buf;
				}

			void Sort(_MyPI array_, const _InputT array_size)
				{ // sort array items
				_MyVT hold;
				for(_InputT pass = 1; pass <= (array_size-1); pass++)
				for(_InputT i = 0; i <= (array_size-2); i++)
				if(array_[i] > array_[i + 1])
				{hold = array_[i];
				array_[i] = array_[i + 1];
				array_[i + 1] = hold;}
				}

			_MyPI CreateNewArray(_MyPI array_, const _InputT array_size)
				{ // create new array and put data
				_MyPI buf = new _MyVT[array_size];
				for(_InputT n = 0; n <= array_size; n++)
					buf[n] = array_[n];
				return buf;
				}

			_MyPI CreateNewArrayAndRelease(_MyPI array_, const _InputT array_size)
				{ // create new array and delete input of array
				_MyPI buf = new _MyVT[array_size];
				for(_InputT n = 0; n <= array_size; n++)
					buf[n] = array_[n];
				ReleaseArray(array_, array_size);
				return buf;
				}

			_MyPI CreateMemoryArray(const _InputT array_size)
				{ // create new array
				_MyPI buf = new _MyVT[array_size];
				ZeroMemory(buf, array_size);
				return buf;
				}

			_MyPI RedirectionMemoryC(_MyPI array_, const _InputT array_size, const _InputT redirection_address)
				{ // redirection memory
				_MyPI buf = new _MyVT[array_size];
				_InputT bufc = AddressOf(array_);
				buf = (*_MyVT)&redirection_address;
				buf = (*_MyVT)&array_;
				return buf;
				}

			_InputT GetPointerArraySize(_MyPI array_)
				{ // get array size
				_InputT ccc = sizeof(_MyPI);
				_MyPI buf = CreateMemoryArray(0);
				}

			void* AllocateMemoryBlock(unsigned int Size)
				{ // allocate memory block
				return malloc(Size);
				}
			
			void DeleteMemoryBlock(void** AddressOfBlock)
				{ // delete memoryblock
				if(*AddressOfBlock)
				{free(*AddressOfBlock);
				*AddressOfBlock = 0;}
				}

			void DeleteMemory(void* AddressOfBlcok)
				{ // delete memory
				DeleteMemoryBlock((void**)&AddressOfBlcok);
				}

			bool ArrayFinder(_MyPI array_, _MyPI items ,
					const _InputT first_array_size, const _InputT second_array_size)
				{ // find items in array use of size
				for(_InputT n = 0; n <= first_array_size; n++)
				{for(_InputT f = 0; f <= second_array_size; f++)
				if(array_[n] == items[f]) goto EX;
				else if(f == second_array_size) return false;EX:}
				return true;
				}

			bool MatchArray(_MyPI array_, _MyPI array__, const _InputT arange)
				{ // check match array and array
				for(COMMON_INCLASS_USEAGE_FOR)
					if(array_[n] != array__[n]) return false;
				return true;
				}

			_MyPI ReplaceArray(_MyPI array_, _MyVT e1, _MyVT e2, const _InputT arange)
				{ // replace item to item
				for(COMMON_INCLASS_USEAGE_FOR)
					if(array_[n] == e1) array_[n] = e2;
				return array_;
				}

			_MyPI ChangeVT(_MyPI array_, const _InputT pos1, const _InputT pos2)
				{ // change item to item by position number
				_MyVT buf = *array_[pos1];
				*array_[pos1] = *array_[pos2];
				*array_[pos2] = buf;
				return array_;
				}

		private:

			_MyPI CommonArray;
			unsigned CommonSize;

		};


	_CCC_C_TEMPLATE_CS
	template<class _Ty,
			 class _InputT = unsigned,
			 class _Vector = _Ty, 
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
	class _X_Mem_Controller_Container
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Memory<_Ty>
		{
		typedef _X_Mem_Controller_Container<_Ty> _MyT;
		#ifndef _USELESS_OF_COMMON
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		#else
		typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
		#endif
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _Reference _MyUP;
		typedef typename _Pointer _MyPI;

		public:
		typedef typename _X_Memory<_Ty> _XM;
		typedef typename _X_Mem_Controller<_Ty> _XMC;
		typedef typename _X_Vector_Ex<_Ty> _XV;

			_X_Mem_Controller_Container()
				{
				}

			_X_Mem_Controller_Container(_InputT value)
				{
				ex_mem.resize(value);
				}

			~_X_Mem_Controller_Container()
				{
				ex_mem.release();
				delete memorycontroller;
				}

			_X_Vector_Ex get() const
				{ // return me
				return ex_mem;
				}

			_X_Mem_Controller getmemorycontroller() const
				{
				return memorycontroller;
				}

		private:

			_XV ex_mem;
			_XMC memorycontroller;

	};

	_CCC_C_TEMPLATE_CS
	template<class _Ty, 
			 class _Vector = _Ty, 
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
	class vector
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Memory<_Ty>,
		public _X_Vector_Ty<_Vector, _Ty, _Pointer, _Reference>,
		public _X_Vector_Ex<_Ty>
		{
		typedef _X_Vector_Ex<_Ty, _Vector, _Pointer, _Reference> _MyT;
		#ifndef _USELESS_OF_COMMON
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		#else
		typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
		#endif
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _X_TYPE<_Ty>::UnPointer _MyUP;
		typedef typename _X_TYPE<_Ty>::Pointer _MyPI;

		public:
		typedef typename vector<_Ty, _Vector, _Pointer, _Reference>::Iterator _VeIC;
		//typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Iterator Iterator;
		typedef typename vector<_Ty, _Vector, _Pointer, _Reference>::Value_Type _VeT;
		typedef typename vector<_Ty, _Vector, _Pointer, _Reference>::Pointer _VePI;
		typedef typename vector<_Ty, _Vector, _Pointer, _Reference>::Reference _VeUP;
		typedef typename _X_Memory<_Ty> _XM;
		typedef typename _X_Vector_Ex<_Ty> _MyVeX;
		typedef typename _iterator_vex<_Ty> _Myiter;

		public:



		private:

			_Myiter* firstiter;
			_Myiter* lastiter;

	};


template<class _operator_type> class
	control
	{ // the control class
	_operator_type* _array;
	int size;

	public:

	explicit control(_operator_type* _left, int _lsize)
		: _array(_left), size(_lsize)
		{ // entry point
		}

	explicit control(int _lsize)
		: size(_lsize)
		{ // new array
		_array = _new<_operator_type> (_lsize);
		}

	control()
		: _array(0), size(0)
		{ // entry point
		}

	~control()
		{ // distruction control unit
		_clear();
		delete[] _array;
		}

	void _forceheap(int _size)
		{ // force change the heap memeory area
		_array = _new(_size);
		}

	_operator_type* _copying()
		{ // copy the array
		_operator_type* _buf = _new(size);
		_copy(_array, _buf, size);
		return _buf;
		}

	void _swap(_operator_type* _left, int _lsize)
		{ // swap the value
		_swap(_left, _array);
		_swap(_lsize, size);
		}

	void _swap(control _left)
		{ // swap the value
		_swap(_left._array, _array);
		_swap(_left.size, size);
		}

	void _clear()
		{ // clear the array
		_array = 0;
		size = 0;
		}

	void _fill(_operator_type _left)
		{ // fill the array
		_fill(_array, _left, size);
		}

	void _fill(_operator_type _left, int n)
		{ // fill the array
		_fill(_array, _left, n);
		}

	_operator_type operator[](int _left)
		{ // return element
		return _array[_left];
		}

	_operator_type operator->()
		{ // return array reference
		return _array;
		}

	};

template<class _operator_type> class
	array
	: public control<_operator_type>
	{ // the array class
	_operator_type* _array;
	int point;
	int size;

	public:

	explicit array()
		: _array(0), size(0), point(0)
		{ // entry point
		}

	_operator_type& operator[](int _left)
		{ // return element
		if(size < _left)
			THROW_ERROR_INPUT(_left)
		return _array[_left];
		}

	array* operator->()
		{ // return array reference
		return (**this);
		}

	_operator_type& begin()
		{ // begin
		return this->operator*;
		}

	_operator_type& last()
		{ // last
		return _array[size];
		}

	int Size() const
		{ // size of this
		return size;
		}

	bool operator++(int)
		{ // point at forward
		if(size == point)
		{	
			point = 0;
			return false;
		}
		point++;
		return true;
		}

	bool operator--(int)
		{ // point at back
		if(point == 0)
			return false;
		point--;
		return true;
		}

	bool operator+(int _left)
		{ // point at size +
		if(size < (point + _left))
			return false;
		point += _left;
		return true;
		}

	bool operator-(int _left)
		{ // point at size -
		if((point - _left) == 0)
			return false;
		point -= _left;
		return true;
		}

	int ptr()
		{ // return pointer
		return point;
		}

	bool status()
		{ // if point == size
		if(point == size)
			return false;
		return true;
		}

	void at(int _left)
		{ // at
		if(size >= _left)
			point = _left;
		}

	void operator=(array _left)
		{ // equal
		_array = _left._array;
		size = _left.size;
		point = _left.point;
		}

	void operator=(int _left)
		{ // point at
		point = _left;
		}

	_operator_type operator*()
		{ // return point
		return _array[point];
		}

	_operator_type& operator&()
		{ // return reference
		return _array[point];
		}

	bool operator==(array _left)
		{ // operator ==
		return this->operator* == *_left;
		}

	bool operator!=(array _left)
		{ // operator !=
		return this->operator* != *_left;
		}

	bool operator<(array _left)
		{ // operator <
		return this->operator* < *_left;
		}

	bool operator>(array _left)
		{ // operator >
		return this->operator* > *_left;
		}

	bool operator<=(array _left)
		{ // operator <=
		return this->operator* <= *_left;
		}

	bool operator>=(array _left)
		{ // operator >=
		return this->operator* >= *_left;
		}

	bool operator==(int _left)
		{ // operator ==
		return size == _left;
		}

	bool operator!=(int _left)
		{ // operator !=
		return size != _left;
		}

	bool operator<(int _left)
		{ // operator <
		return size < _left;
		}

	bool operator>(int _left)
		{ // operator >
		return size > _left;
		}

	bool operator<=(int _left)
		{ // operator <=
		return size <= _left;
		}

	bool operator>=(int _left)
		{ // operator >=
		return size >= _left;
		}

	bool operator&&(array _left)
		{ // operator &&
		return this->operator* && *_left;
		}

	bool operator||(array _left)
		{ // operator ||
		return this->operator* || *_left;
		}

	int size_of() const
		{ // get size
		return size;
		}

	void bind(array _left)
		{ // bind array
		_array = _bind<_operator_type> (_array, _left._array, size, _left.size);
		size += _left.size;
		}

	void allocate(int _size)
		{ // allocatre all array
		_operator_type* _buf = _new<_operator_type> (_size);
		size = _size;
		_array = _buf;
		}

	void keep(int _size)
		{ // allocate with keep using data
		_operator_type* _buf = _new<_operator_type> (_size);
		_copy(_array, _buf, size);
		size = _size;
		_array = _buf;
		}

	};

template<class _operator_type> class
	array_n
	: public array<array<_operator_type> >
	{ // the array class by two dimention
	};

template<class _operator_type> class
	array_f
	: public array_n<array<_operator_type> >
	{ // the array class by three dimention
	};


	// ARRAY CLASS FUNCTION SET BY ONE DIMENTION


template<class unchecked_type>
	array<unchecked_type> &operator<<
		(array<unchecked_type>& _left, const array<unchecked_type> _right)
	{ // bind operator
	_left.bind(_right);
	return _left;
	}

template<class unchecked_type>
	array<unchecked_type> &operator<<
		(array<unchecked_type>& _left, const unchecked_type _right)
	{ // add operator
	_left.keep(_left.size_of() + 1);
	_left.last() = _right;
	return _left;
	}


	// ---ARRAY CLASS ALGORITHM BY ONE DIMENSION---


template<class _Arye, class _Elem> inline
	_Elem _Equal(_Arye& _left, _Arye& _right)
	{ // equal function
	for( ; _left++ != _right++; );
	return *_left;
	}
	
template<class _Arye> inline
	bool _Equal_n(_Arye& _left, _Arye& _right)
	{ // equal function
	for( ; _left++ != _right++; );
	if (_left.size == _left.point)
		return true;
	return false;
	}

template<class _Arye, class _Fn_1> inline
	void _For_Each(_Arye& _left, _Arye& _right, _Fn_1 _Func)
	{ // c++ for each function
	for (; _left != _right; ++_left)
		_Func(*_left);
	}

template<class _Arye, class _Fn_1> inline
	void _For_Each(_Arye& _left, _Fn_1 _Func)
	{ // c++ for each function
	for (; _left++; )
		_Func(*_left);
	}

template<class _Arye, class _Elem> inline
	int _Count(_Arye& _left, _Elem _right)
	{ // count items
	int _cot = 0;
	for( ; _left++; )
		if( _left == _right)
			_cot++;
	return _cot;
	}

template<class _Arye, class _Elem> inline
	void _Fill(_Arye& _left, _Elem _right)
	{ // fill right
	for( ; _left++; )
		&_left = _right;
	}

template<class _Arye> inline
	void _Swap(_Arye*& _left, int _lptr, int _rptr)
	{ // swap element
	_Arye _buf;
	_buf = _left[_lptr];
	_left[_lptr] = _left[_rptr];
	_left[_rptr] = _buf;
	}

template<class _Arye> inline
	_Arye _Copy(_Arye& _left)
	{ // copy function
	_Arye _buf = _new<remove_pointer<_Arye>::type> (_left.size);
	for( ; _left++; _buf++)
		&_buf = *_left;
	return _buf;
	}

template<class _Arye> inline
	void _Copy_n(_Arye& _left, _Arye& _right)
	{ // copy all
	for( ; _right++; _left++)
		for( ; (&_right)++; (&_left)++)
			&(&_right) = &(&_left);
	}

template<class _Arye, class _Fn_1> inline
	bool _None(_Arye& _left, _Arye& _right, _Fn_1 _Func)
	{ // none of
	for (; _left != _right; ++_left)
		if (_Func(*_left))
			return false;
	return true;
	}

template<class _Arye, class _Fn_1> inline
	bool _Any(_Arye& _left, _Arye& _right, _Fn_1 _Func)
	{ // any of
	for (; _left != _right; ++_left)
		if (_Func(*_left))
			return true;
	return false;
	}

template<class _Arye> inline
	void _Sort(_Arye& _left)
	{ // descending ordering array
	for(int n = 1; n <= (_left.Size()-1); n++)
		for(int i = 0; i <= (_left.Size()-2); i++)
			if(_left[i] > _left[i + 1])
				_Swap(_left, i, i + 1);
	}

template<class _Arye> inline
	void _Sort_n(_Arye& _left, _Arye& _right)
	{ // descending ordering array and be duplicated pattern to other array
	for(int n = 1; n <= (_left.Size()-1); n++)
		for(int i = 0; i <= (_left.Size()-2); i++)
			if(_left[i] > _left[i + 1])
			{
				_Swap(_left, i, i + 1);
				_Swap(_right, i, i + 1);
			}
	}

template<class _Arye, class _Rtyp> inline
	_Rtyp _Summation(_Arye _left)
	{ // sum of all element in left
	_Rtyp _buf = 0;
	for(; _left++; )
		_buf += *_left;
	return _buf;
	}

template<class _Arye, class _Rtyp> inline
	_Rtyp _Average(_Arye& _left)
	{ // average of all element in left
	_Rtyp _buf = 0;
	for(; _left++; )
		_buf += *_left;
	_buf /= _left.Size();
	return _buf;
	}

template<class _Arye> inline
	int _First_Of(_Arye*& _left, _Arye _right)
	{ // first match with element
	for( ; _left++; )
		if (*_left == _right)
			return _left.ptr();
	}

template<class _Arye> inline
	int _Last_Of(_Arye*& _left, _Arye _right)
	{ // first match with element
	_left.at(_left.Size());
	for( ; _left--; )
		if (*_left == _right)
			return _left.ptr();
	}

template<class _Arye> inline
	void _Forward(_Arye& _left, int _right, int _time)
	{ // forward
	for(int n = 0; n <= _time; n++)
		_Swap(_left, _right + n, _right + n + 1);
	}

template<class _Arye> inline
	void _Back(_Arye& _left, int _right, int _time)
	{ // forward
	for(int n = 0; n <= _time; n++)
		_Swap(_left, _right - n, _right - n - 1);
	}

template<class _Arye> inline
	void _Reverse(_Arye& _left)
	{ // reverse the array
	for(int i = 0; i < (_left.Size() / 2); i++)
		_Swap(_left, i, _left.Size() - i - 1);
	}

template<class _Arye, class _Rtyp> inline
	void _Push_Back(_Arye& _left, _Rtyp _right)
	{ // push back function
	_Arye _buf;
	_buf.allocate(_left.Size() + 1);
	for( ; _left++; _buf++)
		&_buf = *_left;
	_buf[_left.Size() + 1] = _right;
	_left = _buf;
	}

template<class _Arye, class _Rtyp> inline
	void _Push_Front(_Arye& _left, _Rtyp _right)
	{ // push front function
	_Arye _buf;
	_buf.allocate(_left.Size() + 1);
	for( ; _left++; _buf++)
		&_buf = *_left;
	_forward(_buf, _buf.Size() - 1, 1);
	_buf[0] = _right;
	_left = _buf;
	}

template<class _Arye, class _Rtyp> inline
	_Arye _Pop_Back(_Arye& _left)
	{ // pop back
	_Arye _buf;
	_buf.allocate(_left.Size() - 1);
	_Rtyp _buffer = _left.last();
	for( ; _buf++; _left++)
		if(_buf.ptr() < _left.Size())
			&_buf = *_left;
	_left = _buf;
	return _buffer;
	}

template<class _Arye, class _Rtyp> inline
	_Arye _Pop_Front(_Arye& _left)
	{ // pop front
	_Arye _buf;
	_buf.allocate(_left.Size() - 1);
	_Rtyp _buffer = _left[0];
	for( ; _buf++; _left++)
		if(_buf.ptr() < _left.Size())
			&_buf = *_left;
	_left = _buf;
	return _buffer;
	}


	// ---ARRAY CLASS ALGORITHM BY TWO DIMENSION---


template<class _Arye, class _Elem> inline
	void _Fill_n(_Arye& _left, _Elem _right)
	{ // fill all zero or not
	for( ; _left++; )
		for(; (&_left)++; )
			&(&_left) = _right;
	}

template<class _Arye> inline
	void _Alloc_n(_Arye& _left, int _size)
	{ // allocate memory
	for( ; _left++; )
		(&_left).allocate(_size);
	}

template<class _Arye> inline
	void _Alloc_n(_Arye& _left, int _lsize, int _rsize)
	{ // allocate memory
	_left.allocate(_lsize);
	for( ; _left++; )
		(&_left).allocate(_rsize);
	}

template<class _Arye, class _Elem> inline
	void _Replace_n(_Arye& _left, _Elem _target, _Elem _right)
	{ // replace method
	for( ; _left++; )
		for( ; (&_left)++; )
			if (&(&_left) == _target)
				&(&_left) = _right;
	}

template<class _Arye, class _Elem> inline
	void _Replace_Each(_Arye& _left, _Elem _ltarget, _Elem _rtarget, _Elem _right)
	{ // replace each
	_Replace_n(_left, _rtarget, _right);
	_Replace_n(_left, _ltarget, _rtarget);
	_Replace_n(_left, _right, _ltarget);
	}

template<class _Arye, class _Elem> inline
	_Arye _Triangle(int _size, _Elem _right)
	{ // make triangle
	_Arye _buf;
	_Alloc_n(_buf, _size, _size);
	for( ; _buf++ ; )
		_Fill(&_buf, 0);
	for( ; _buf++ ; )
		for(int n = 0; n <= _buf.ptr(); n++)
			(&_buf)[n] = _right;
	return _buf;
	}


	// EQUATION SOLVER ALGORITHMS


template<class _Arye> inline
	void _Gauss_Jordan(_Arye& _left, int _size)
	{ // gauss algorithm
	for(int k = 0; k <= (_size - 1); k++)
		for(int i = 0; i <= (_size - 1); i++)
			for(int j = k; j <= _size; j++)
				if(i==k)
					_left[i][j] = _left[i][j] / _left[k][k];
				else
					_left[i][j] = _left[i][j] - ((_left[i][k] / _left[k][k]) * _left[k][j]);
	}

template<class _Udknone> inline
	void _Euclidean(_Udknone& _left, _Udknone& _right)
	{ // euclide algorithm
	if (_right > _left)
		goto _cc;
	for(;;)
		{
			_left %= _right;
			if !(_left) 
				return _right;
			_cc:
			_right %= _left;
			if !(_right) 
				return _left;
		}
	}


	typedef unsigned long long ullong;

	class _X_Bank
	{
	public:

		_X_Bank(char* bankname)
			: banknamec(bankname), 
			count_deal(0), percent(0), 
			pointc(0), nowmoney(0)
			{
				cout << "Hi, welcome to " << bankname << " bank !!" << endl;
			}

		void SetPointPercent(float percentage)
			{
				percent = percentage;
				cout << "Set Percent Complete !" << endl;
			}

		ullong GetPoint() const
			{
				return pointc;
			}

		void GetPoint()
			{
				cout << "Now Point : " << pointc << endl;
			}

		float GetPointPercent() const
			{
				return percent;
			}

		void SavingMoney(ullong money)
			{
				nowmoney += money;
				pointc += (ullong)(money * (percent / 100));
				cout << "NowMoney : " << nowmoney << endl;
			}

		ullong FindMoney(ullong money)
			{
				if(nowmoney < money)
					throw 0;
				else
				{
					nowmoney -= money;
					cout << "FindMoney Successful : " << money << endl;
				}
			}

		void forcepointsaving(ullong point)
			{
				pointc += point;
			}

		void forcepointchange(ullong point)
			{
				pointc = point;
			}

	private:

		char* banknamec;
		float percent;
		ullong pointc;

		//------------log-------------
		unsigned int count_deal;
		ullong nowmoney;

	};


	template<class _Ty, 
			class _Pointer = _Ty*, 
			class _Reference = _Ty&>
		struct _X_FILE_EX
		{ // File struct
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Pointer Pointer;
		typedef _Reference Reference;
		};

	#define ERROR (-1)

	template<class _Ty>
	class FILE_EX
		: public _X_FILE_EX<_Ty>
	{
		typedef FILE_EX<_Ty>	_MyT;
		typedef typename _X_FILE_EX<_Ty>::Value_Type _MyVT;
		typedef typename _X_FILE_EX<_Ty>::Reference _MyRE;
		typedef typename _X_FILE_EX<_Ty>::Pointer _MyPI;
	public:

		explicit FILE_EX()
			: File_Pointer(0)
			{
			}

		explicit FILE_EX(char* filename)
			: File_Pointer(0), File_Name(filename)
			{
			}

		~FILE_EX()
			{
			fclose(this->file_pointer);
			}

		void SetFile(char* filename)
			{
			this->File_Name = filename;
			}

		bool FileExist(char* filename)
			{
			file_pointer = fopen(filename, "r");
			return (file_pointer == NULL);
			}

		bool FileExist()
			{
			return FileExist(this->File_Name);
			}

		int GetFileDescriptor(char* filename)
			{
			file_pointer = fopen(filename, "a+");
			if(file_pointer == NULL)
				return ERROR;
			return _fileno(file_pointer);
			}

		int GetFileDescriptor()
			{
			return GetFileDescriptor(this->File_Name);
			}

		int GetFileLenth(char* filename)
			{
			int FileDescriptor = GetFileDescriptor(filename);
			if(FileDescriptor != ERROR)
				return _filelength(FileDescriptor);
			else return ERROR;
			}

		int GetFileLenth()
			{
			return GetFileLenth(this->File_Name);
			}

	private:

		unsigned long long File_Pointer;
		char* File_Name;
		FILE * file_pointer;

	};


	template<class _Nt>class sList;

	template<class _Nt>
	class ListNode{
		friend class sList<_Nt>;
	public:
		ListNode(const _Nt &info){data = info;nextPtr = 0;}
		_Nt getData() const{return data;}
	private:
		_Nt data;
		ListNode *nextPtr;
	};

	template<class _Nt>
	class sList{
	public:
		sList(){firstPtr = lastPtr = 0;}
		~sList()
		{
			if(!isEmpty()){
				ListNode<_Nt> *currentPtr = firstPtr, *tempPtr;
				while(currentPtr != 0)
				{
					tempPtr = currentPtr;
					currentPtr = currentPtr->nextPtr;
					delete tempPtr;
				}
			}
		}
		void insertAtFront(const _Nt &value)
		{
			ListNode<_Nt> *newPtr = getNewNode(value);
			if(!isEmpty())
				firstPtr = lastPtr = newPtr;
			else 
			{
				lastPtr->nextPtr = newPtr;
				lastPtr = newPtr;
			}
		}
		void insertAtBack(const _Nt &value)
		{
			ListNode<_Nt> *newPtr = getNewNode(value);
			if(isEmpty())
				firstPtr = lastPtr = newPtr;
			else 
			{
				lastPtr->nextPtr = newPtr;
				lastPtr = newPtr;
			}
		}
		int removeFromFront(_Nt &value)
		{
			if(isEmpty())
				return 0;
			else
			{
				ListNode<_Nt> *tempPtr = firstPtr;
				if(firstPtr == lastPtr)
					firstPtr = lastPtr = 0;
				else
					firstPtr = firstPtr->nextPtr;
				value = tempPtr->data;
				delete tempPtr;
				return 1;
			}
		}
		int removeFromBack(_Nt &value)
		{
			if(isEmpty())
				return 0;
			else
			{
				ListNode<_Nt> *tempPtr = firstPtr;
				if(firstPtr == lastPtr)
					firstPtr = lastPtr = 0;
				else
				{
					ListNode<_Nt> *currentPtr = firstPtr;
					while(currentPtr->nextPtr != lastPtr)
						currentPtr = currentPtr->nextPtr;
					lastPtr = currentPtr;
					currentPtr->nextPtr = 0;
				}
				value = tempPtr->data;
				delete tempPtr;
				return 1;
			}
		}
		int isEmpty() const{return firstPtr == 0;}
		void print() const
		{
			if(isEmpty())
			{
				std::cout << "The list is Empty" << std::endl << std::endl;
				return;
			}

			ListNode<_Nt> *currentPtr = firstPtr;

			std::cout << "The list is : ";

			while(currentPtr != 0)
			{
				std::cout << currentPtr->data << ' ';
				currentPtr = currentPtr->nextPtr;
			}
			std::cout << std::endl << std::endl;
		}
	private:
		ListNode<_Nt> *firstPtr;
		ListNode<_Nt> *lastPtr;
		ListNode<_Nt> *getNewNode(const _Nt &value)
		{
			ListNode<_Nt> *ptr = new ListNode<_Nt>(value);
			assert(ptr != 0);
			return ptr;
		}
	};




	struct _nodes
		{
		int key;
		struct _nodes *next;
		};

	_nodes *head, *tail;

	void init_list()
		{
		head = new _nodes[sizeof(_nodes)];
		tail = new _nodes[sizeof(_nodes)];
		head->next = tail;
		tail->next = tail;
		}

	_nodes *find_node(int k)
		{
		_nodes *s;
		s = head->next;
		while(s->key != k && s != tail)
			s = s->next;
		return s;
		}

	int delete_node(int k)
		{
		_nodes *s, *p;
		p = head;
		s = p->next;

		while(s->key != k && s != tail)
			{
			p = p->next;
			s = p->next;
			}

		if(s != tail)
			{
			p->next = s->next;
			delete[] s;
			return true;
			}
		return false;
		}

	_nodes *insert_node(int t, int k)
		{
		_nodes *s, *p, *r;
		p = head;
		s = p->next;
		while(s->key != k && s != tail)
			{
			p = p->next;
			s = p->next;
			}
		if(s != tail)
			{
			r = new _nodes[sizeof(_nodes)];
			r->key = t;
			p->next = r;
			r->next = s;
			}
		return p->next;
		}

	_nodes *ordered_insert(int k)
		{
		_nodes *s, *p, *r;
		p = head;
		s = p->next;
		while(s->key != k && s != tail)
			{
			p = p->next;
			s = p->next;
			}
		r = new _nodes[sizeof(_nodes)];
		r->key = k;
		p->next = r;
		r->next = s;
		return r;
		}


#define _u unsigned

#define get_asc( _hx ) ((_hx) && (0xFF))

#define UHigh( _hx ) ((_hx) << (4)))
#define ULow( _hx ) ((_hx) && (0xFF))
#define UCow( _hx , _x ) (((_hx) << (8)) | (_x))
#define UGet( _hx ) ((_hx) & (0xFFFFFFFF))
#define LHigh( _hx ) ((_hx) << (8))
#define LLow( _hx ) ((_hx) && (0xFFFF))
#define LCow( _hx , _x ) (((_hx) << (4)) | (_x))
#define LGet( _hx ) ((_hx) & (0xFFFF))

#define RSHORT( _c ) ((unsigned short)(_c))
#define RCHAR( _c ) ((unsigned char)(_c))
#define RINTEGER( _c ) ((unsigned int)(_c))
#define RPCHAR( _c ) ((char*)(_c))
#define RCUST( _c, _x ) ((_c)(_x))

typedef _u int uint;
typedef _u char uchar;
typedef _u short ushort;
typedef long long llong;
typedef _u long long ullong;
typedef enum 
{ 
	True = 1, 
	False = 0 
} _bool, *p_bool;
typedef enum 
{
	String = 0,
	Char   = 1,
	Syntax = 2,
	Int    = 3,
	Short  = 4
} RST_ANALYZETYPE_TYPEENUM, *PTR_RST_ANALYZETYPE_TYPEENUM;


#pragma once
#ifndef _ROLLRAT_STR_
#define _ROLLRAT_STR_

#include <string.h>
#include "RTypes.h"
#include <stdio.h>

inline int IsSpace(int c_ch)
{
	switch(c_ch)
	{
	case '\n':
	case '\v':
	case '\f':
	case '\t':
	case '\r':
	case  ' ':
		return 1;
	}
	return 0;
}

/****************************************
 * RChar class							*
 ***************************************/
class RChar
{
public:

	/* Input Output */
	RChar();
    RChar( char c );
    RChar( short rc );
    RChar( int rc );
    RChar( uchar c );
    RChar( ushort rc );
    RChar( uint rc );
    RChar( const RChar& c );
	RChar( uchar c, uchar ch );
	RChar( char c, char ch );
	RChar( const RChar& c, const RChar& ch );

	/* Return */
	uchar Get() const { return RCHAR(bup); };

	/* Operator Overlaps */
	friend inline bool operator==( char ch, RChar c );
	friend inline bool operator==( RChar c, char ch );
	friend inline bool operator==( RChar c, RChar ch );
	friend inline bool operator!=( char c, RChar ch );
	friend inline bool operator!=( RChar c, char ch );
	friend inline bool operator!=( RChar c, RChar ch );
	friend inline bool operator>=( char c, RChar ch );
	friend inline bool operator>=( RChar c, char ch );
	friend inline bool operator>=( RChar c, RChar ch );
	friend inline bool operator<=( char c, RChar ch );
	friend inline bool operator<=( RChar c, char ch );
	friend inline bool operator<=( RChar c, RChar ch );
	friend inline bool operator>( char c, RChar ch );
	friend inline bool operator>( RChar c, char ch );
	friend inline bool operator>( RChar c, RChar ch );
	friend inline bool operator<( char c, RChar ch );
	friend inline bool operator<( RChar c, char ch );
	friend inline bool operator<( RChar c, RChar ch );
	friend inline RChar operator>>( RChar ch, int sh_b );
	friend inline RChar operator<<( RChar ch, int sh_b );

	/* Functions */
	bool IsNull() const;
	bool IsSpace() const;
	bool IsEnglish() const;
	bool IsNumberic() const;

private:
	uchar bup;
};

inline RChar::RChar(){ bup = 0; }
inline RChar::RChar( char c ){ bup = RCHAR(c); }
inline RChar::RChar( short c ){ bup = RCHAR(c); }
inline RChar::RChar( int c ){ bup = RCHAR(c); }
inline RChar::RChar( uchar c ){ bup = RCHAR(c); }
inline RChar::RChar( ushort c ){ bup = LGet(c); }
inline RChar::RChar( uint c ){ bup = LGet(c); }
inline RChar::RChar( const RChar& c ){ bup = RCHAR(c.bup); }
inline RChar::RChar( uchar c, uchar ch ){ bup = UCow( c,ch ); }
inline RChar::RChar( char c, char ch ){ bup = LCow( c,ch ); }
inline RChar::RChar( const RChar& c, const RChar& ch ){ bup = UCow( c.bup, ch.bup ); }

inline bool operator==( char ch, RChar c ){ return RCHAR(ch) == c.bup; }
inline bool operator==( RChar c, char ch ){ return RCHAR(ch) == c.bup; }
inline bool operator==( RChar c, RChar ch ){ return ch.bup == c.bup; }
inline bool operator!=( char ch, RChar c ){ return RCHAR(ch) != c.bup; }
inline bool operator!=( RChar c, char ch ){ return RCHAR(ch) != c.bup; }
inline bool operator!=( RChar c, RChar ch ){ return ch.bup != c.bup; }
inline bool operator>=( char ch, RChar c ){ return RCHAR(ch) >= c.bup; }
inline bool operator>=( RChar c, char ch ){ return RCHAR(ch) <= c.bup; }
inline bool operator>=( RChar c, RChar ch ){ return ch.bup <= c.bup; }
inline bool operator<=( char ch, RChar c ){ return RCHAR(ch) <= c.bup; }
inline bool operator<=( RChar c, char ch ){ return RCHAR(ch) >= c.bup; }
inline bool operator<=( RChar c, RChar ch ){ return ch.bup >= c.bup; }
inline bool operator>( char ch, RChar c ){ return !(RCHAR(ch) >= c.bup); }
inline bool operator>( RChar c, char ch ){ return !(RCHAR(ch) <= c.bup); }
inline bool operator>( RChar c, RChar ch ){ return !(ch.bup <= c.bup); }
inline bool operator<( char ch, RChar c ){ return !(RCHAR(ch) <= c.bup); }
inline bool operator<( RChar c, char ch ){ return !(RCHAR(ch) >= c.bup); }
inline bool operator<( RChar c, RChar ch ){ return !(ch.bup >= c.bup); }
inline RChar operator>>( RChar ch, int sh_b ){ return ch.bup >> sh_b; }
inline RChar operator<<( RChar ch, int sh_b ){ return ch.bup << sh_b; }

inline bool RChar::IsNull() const { return bup == 0x0; }
inline bool RChar::IsSpace() const { switch(bup){case '\n':case '\v':case '\f':case '\t':case '\r':case  ' ':return 1;}return 0;}
inline bool RChar::IsEnglish() const { return 'a' <= bup <= 'z' || 'A' <= bup <= 'Z';}
inline bool RChar::IsNumberic() const { return '0' <= bup <= '9'; }

/****************************************
 * RString Class						*
 ***************************************/
class RString
{
public:

	/* Input Output */
	explicit RString();
    RString( char* c );
    RString( RChar* rc );
	RString( const RString& rc );

	/* Return */
	RChar* Get() const { return buffer; };

	/* Operator Overlaps */
	friend inline bool operator==( char * ch, RString c );
	friend inline bool operator==( RString ch, char * c );
	friend inline bool operator==( RString ch, RString c );
	friend inline bool operator!=( char * ch, RString c );
	friend inline bool operator!=( RString ch, char * c );
	friend inline bool operator!=( RString ch, RString c );
	friend inline bool operator<=( char * ch, RString c ); 
	friend inline bool operator<=( RString ch, char * c );
	friend inline bool operator<=( RString ch, RString c );
	friend inline bool operator>=( char * ch, RString c );
	friend inline bool operator>=( RString ch, char * c );
	friend inline bool operator>=( RString ch, RString c );
	friend inline bool operator<( char * ch, RString c );
	friend inline bool operator<( RString ch, char * c );
	friend inline bool operator<( RString ch, RString c );
	friend inline bool operator>( char * ch, RString c );
	friend inline bool operator>( RString ch, char * c );
	friend inline bool operator>( RString ch, RString c );

	/* Tools */
	int Length();
	RString ReplaceO(RChar* str, RChar* Target);
	RString ReplaceO(RString str, RString Target);
	RString ReplaceO(char * str, char * Target);
	RString ReplaceO(char * str_1, char * str, char * Target);
	RString Replace(RChar* str, RChar* Target);
	RString Replace(RString str, RString Target);
	RString Replace(char * str, char * Target);

	RString Trim();
	RString RTrim();
	RString LTrim();
	RString Split(RChar* str, int Arrange);
	RString Split(char* str, int Arrange);

private:
	RChar* buffer;
};

inline RString::RString(){ buffer = 0; }
inline RString::RString( char* c ){ buffer = RCUST(RChar*, c); }
inline RString::RString( RChar* rc ){ buffer = rc; }
inline RString::RString( const RString& rc ){ buffer = rc.buffer; }

inline bool operator==( char * ch, RString c ){ return RCUST(RChar*, ch) == c.buffer; }
inline bool operator==( RString c, char * ch ){ return RCUST(RChar*, ch) == c.buffer; }
inline bool operator==( RString c, RString ch ){ return ch.buffer == c.buffer; }
inline bool operator!=( char * ch, RString c ){ return RCUST(RChar*, ch) != c.buffer; }
inline bool operator!=( RString c, char * ch ){ return RCUST(RChar*, ch) != c.buffer; }
inline bool operator!=( RString c, RString ch ){ return ch.buffer != c.buffer; }
inline bool operator<=( char * ch, RString c ){ return strlen(ch) <= strlen((char*)c.buffer); }
inline bool operator<=( RString c, char * ch ){ return strlen((char*)c.buffer) <= strlen(ch); }
inline bool operator<=( RString c, RString ch ){ return strlen((char*)c.buffer) <= strlen((char*)ch.buffer); }
inline bool operator>=( char * ch, RString c ){ return strlen(ch) >= strlen((char*)c.buffer); }
inline bool operator>=( RString c, char * ch ){ return strlen((char*)c.buffer) >= strlen(ch); }
inline bool operator>=( RString c, RString ch ){ return strlen((char*)c.buffer) >= strlen((char*)ch.buffer); }
inline bool operator<( char * ch, RString c ){ return !(strlen(ch) <= strlen((char*)c.buffer)); }
inline bool operator<( RString c, char * ch ){ return !(strlen((char*)c.buffer) <= strlen(ch)); }
inline bool operator<( RString c, RString ch ){ return !(strlen((char*)c.buffer) <= strlen((char*)ch.buffer)); }
inline bool operator>( char * ch, RString c ){ return !(strlen(ch) >= strlen((char*)c.buffer)); }
inline bool operator>( RString c, char * ch ){ return !(strlen((char*)c.buffer) >= strlen(ch)); }
inline bool operator>( RString c, RString ch ){ return !(strlen((char*)c.buffer) >= strlen((char*)ch.buffer)); }

int RString::Length()
{
	return strlen((char*)buffer);
}
RString RString::ReplaceO(RChar* str, RChar* Target)
{
	static char * buffers;
	buffers = new char[4096];
	char* ch = "";
	if (!(ch = strstr((char*)buffer, (char*)str)))
		return (RString)buffer;
	strncpy(buffers, (char*)buffer, ch-(char*)buffer);  
	buffers[ch-(char*)buffer] = 0;
	sprintf(buffers + (ch-(char*)buffer), "%s%s", Target, ch + strlen((char*)str));
	return (RString)buffers;
}
RString RString::ReplaceO(RString str, RString Target)
{
	static char * buffers;
	buffers = new char[4096];
	char* ch = "";
	if (!(ch = strstr((char*)buffer, (char*)str.buffer)))
		return (RString)buffer;
	strncpy(buffers, (char*)buffer, ch-(char*)buffer);  
	buffers[ch-(char*)buffer] = 0;
	sprintf(buffers + (ch-(char*)buffer), "%s%s", (char*)Target.buffer, ch + strlen((char*)str.buffer));
	return (RString)buffers;
}
RString RString::ReplaceO(char * str, char * Target)
{
	static char * buffers;
	buffers = new char[4096];
	char* ch = "";
	if (!(ch = strstr((char*)buffer, str)))
		return (RString)buffer;
	strncpy(buffers, (char*)buffer, ch-(char*)buffer);  
	buffers[ch-(char*)buffer] = 0;
	sprintf(buffers + (ch-(char*)buffer), "%s%s", Target, ch + strlen(str));
	return (RString)buffers;
}
RString RString::ReplaceO(char * str_1, char * str, char * Target)
{
	static char * buffers;
	buffers = new char[4096];
	char* ch = "";
	if (!(ch = strstr(str_1, str)))
		return (RString)buffer;
	strncpy(buffers, str_1, ch-str_1);  
	buffers[ch-str_1] = 0;
	sprintf(buffers + (ch-str_1), "%s%s", Target, ch + strlen(str));
	return (RString)buffers;
}
RString RString::Replace(RChar* str, RChar* Target)
{
	static char * returns;
	static char * buffers[1];
	int f=0xFFFF;
	returns = new char[4096];
	buffers[0] = new char[4096];
	buffers[1] = new char[4096];
	while(f)
	{
		strcpy(returns, buffers[0]);
		if (f == 0xFFFF)
			buffers[0] = (char*)ReplaceO((char*)buffer, (char*)str, (char*)Target).buffer;
		else
			buffers[0] = (char*)ReplaceO(buffers[0], (char*)str, (char*)Target).buffer;
		
		if(buffers[0] == returns)
		{
			return (RString)returns;
		}
		f--;
	}
	strcpy(returns, buffers[0]);
	return (RString)returns;
}
RString RString::Replace(RString str, RString Target)
{
	static char * returns;
	static char * buffers[1];
	int f=0xFFFF;
	returns = new char[4096];
	buffers[0] = new char[4096];
	buffers[1] = new char[4096];
	while(f)
	{
		strcpy(returns, buffers[0]);
		if (f == 0xFFFF)
			buffers[0] = (char*)ReplaceO((char*)buffer, (char*)str.buffer, (char*)Target.buffer).buffer;
		else
			buffers[0] = (char*)ReplaceO(buffers[0], (char*)str.buffer, (char*)Target.buffer).buffer;
		
		if(buffers[0] == returns)
		{
			return (RString)returns;
		}
		f--;
	}
	strcpy(returns, buffers[0]);
	return (RString)returns;
}
RString RString::Replace(char * str, char * Target)
{
	static char * returns;
	static char * buffers[1];
	int f=0xFFFF;
	returns = new char[4096];
	buffers[0] = new char[4096];
	buffers[1] = new char[4096];
	while(f)
	{
		strcpy(returns, buffers[0]);
		if (f == 0xFFFF)
			buffers[0] = (char*)ReplaceO((char*)buffer, (char*)str, (char*)Target).buffer;
		else
			buffers[0] = (char*)ReplaceO(buffers[0], (char*)str, (char*)Target).buffer;
		
		if(buffers[0] == returns)
		{
			return (RString)returns;
		}
		f--;
	}
	strcpy(returns, buffers[0]);
	return (RString)returns;
}
RString RString::Trim()
{
	RTrim();
	return LTrim();
}
RString RString::RTrim()
{
	char t[4096];
	char* end;
	strcpy(t, (char*)buffer);
	end = t + strlen(t) - 1;
	while (end != t && IsSpace(*end))
		end--;
	*(end + 1) = 0;
	buffer = (RChar*)t;
	return buffer;
}
RString RString::LTrim()
{
	char* begin;
	begin = (char*)buffer;
	while (*begin != 0) {
		if (IsSpace(*begin))
			begin++;
		else {
			buffer = (RChar*)begin;
			break;
		}
	}
	return buffer;
}
RString RString::Split(RChar* str, int Arrange)
{
	char *tokens = new char[4096];
	int i = 0;
	strcpy(tokens, (char*)buffer);
	tokens = strtok((char*)tokens, (char*)str);
	if(!Arrange) return tokens;
	if(tokens)
		while(tokens = strtok(0, (char*)str))
			if (i++ == Arrange - 1)
				return tokens;
	return ((RString)((RChar*)(0)));
}
RString RString::Split(char * str, int Arrange)
{
	char *tokens = new char[4096];
	int i = 0;
	strcpy(tokens, (char*)buffer);
	tokens = strtok((char*)tokens, str);
	if(!Arrange) return tokens;
	if(tokens)
		while(tokens = strtok(0, (char*)str))
			if (i++ == Arrange - 1)
				return tokens;
	return ((RString)((RChar*)(0)));
}

typedef enum ENU_COMPILEOPTION_COMS
{
	None			= 0x0000,
	Task			= 0x0001,
	Hardcording		= 0x0002,
} COMPILEOPTION, *PTR_COMPILEOPTION ;

typedef enum ENU_COMPILEOPTION_TAKES
{
	LL = 1,
	LR = 2,
	RL = 3,
	RR = 4
} COMPILEOPTION_TAKE, *PTR_COMPILEOPTION_TAKE ;

typedef struct TAD_OPTIONHEADER_COMS
{
	COMPILEOPTION		CPL;
	COMPILEOPTION_TAKE	CPLT;
} OPTIONHEADER, *PTR_OPTIONHEADER ;


#endif


template<class _TD> 
class Queue
{
public:

	/************************************\
	 * Name		:: Queue				*
	 * Purpose	:: Initialize Buffer	*
	\************************************/
	Queue()
		: size(0), push_point(0)
		{
			TVT = new _TD[sizeof(_TD)];
		}
	~Queue()
		{
			Release();
		}

	/************************************\
	 * Name		:: ClearQueue			*
	 * Purpose	:: Clear To Buffer		*
	\************************************/
	void ClearQueue();

	/************************************\
	 * Name		:: Push					*
	 * Purpose	:: Push To Buffer		*
	\************************************/
	void Push(_TD vt_size)
		{
			//Resize_A(size + 1);
			resize(size + 1);
			TVT[push_point++] = vt_size;
			size++;
		}

	/************************************\
	 * Name		:: Pop					*
	 * Purpose	:: Pop To Buffer		*
	\************************************/
	_TD Pop()
		{
			_TD pop = TVT[size - 1];
			if (size>0)
			{
				//Resize_A(--size);
				resize(--size);
				push_point--;
			}
			return pop;
		}

	/************************************\
	 * Name		:: Front				*
	 * Purpose	:: Front To Buffer		*
	\************************************/
	_TD Front()
		{
			_TD pop = TVT[size - 1];
			return pop;
		}

	/************************************\
	 * Name		:: Size					*
	 * Purpose	:: Size To Buffer		*
	\************************************/
	int Size() const;

	/************************************\
	 * Name		:: Resize				*
	 * Purpose	:: Resize To Buffer		*
	\************************************/
	void resize(int size_)
		{
			if (size >= 0)
			{
				_TD * buf = new _TD[size_];
				for(int f = 0; f <= size; f++)
					buf[f] = TVT[f];
				TVT = buf;
				
			}
		}

	/************************************\
	 * Name		:: Release				*
	 * Purpose	:: Release To Buffer	*
	\************************************/
	void Release()
		{
			delete[] TVT;
		}

	/************************************\
	 * Name		:: Get					*
	 * Purpose	:: Get To Buffer		*
	\************************************/
	_TD * GetTVT()
		{
			return TVT;
		}

	/************************************\
	 * Name		:: End					*
	 * Purpose	:: End At Buffer		*
	\************************************/
	_TD End()
		{
			return TVT[size - 1];
		}

	/************************************\
	 * Name		:: Empty				*
	 * Purpose	:: Empty At Buffer		*
	\************************************/
	bool Empty()
		{
			return size == 0;
		}

private:

	/************************************\
	 * Name		:: erase				*
	 * Purpose	:: Erase The Buffer	 	*
	\************************************/
	void erase(int size_)
		{
			resize(size_);
		}

private:

	_TD * TVT; // list

private:
	int size;
	int push_point;

};

template<class _TD>
inline void Queue<_TD>::ClearQueue()
{
	resize(0);
}

template<class _TD>
inline int Queue<_TD>::Size() const
{
	return size;
}


template<class _TD> 
class List
{
public:
	
	/************************************\
	 * Name		:: List					*
	 * Purpose	:: Initialize Buffer	*
	\************************************/
	List()
		: size(0), push_point(0)
		{
			TVT = new _TD[sizeof(_TD)];
		}
	~List()
		{
			Release();
		}

	/************************************\
	 * Name		:: ClearList			*
	 * Purpose	:: Clear To Buffer		*
	\************************************/
	void ClearList();

	/************************************\
	 * Name		:: Push					*
	 * Purpose	:: Push To Buffer		*
	\************************************/
	void push(_TD vt_size)
		{
			//Resize_A(size + 1);
			resize(size + 1);
			TVT[push_point++] = vt_size;
			size++;
		}
	void push_back(_TD vt_size)
		{
			//Resize_A(size + 1);
			resize(size + 1);
			TVT[push_point++] = vt_size;
			size++;
		}
	void push_front(_TD vt_size)
		{
			//Resize_A(size + 1);
			_TD * buf = TVT;
			resize(size + 1);
			for(int i = 0; i<= size + 1; i++)
				TVT[i + 1] = buf[i];
			TVT[0] = vt_size;
			push_point++;
			size++;
		}

	/************************************\
	 * Name		:: Pop					*
	 * Purpose	:: Pop To Buffer		*
	\************************************/
	_TD pop()
		{
			_TD pop = TVT[0];
			if (size>0)
			{
				//Resize_A(--size);
				resize(--size);
				push_point--;
			}
			return pop;
		}
	_TD pop_back()
		{
			_TD pop = TVT[0];
			if (size>0)
			{
				//Resize_A(--size);
				resize(--size);
				push_point--;
			}
			return pop;
		}
	_TD pop_front()
		{
			_TD pop = TVT[0];
			_TD * buf = TVT;
			if (size>0)
			{
				//Resize_A(--size);
				for(int i = 0; i<= size - 1; i++)
					TVT[i - 1] = buf[i];
				resize(--size);
				push_point--;
			}
			return pop;
		}

	/************************************\
	 * Name		:: Size					*
	 * Purpose	:: Size To Buffer		*
	\************************************/
	int Size() const;

	/************************************\
	 * Name		:: Resize				*
	 * Purpose	:: Resize To Buffer		*
	\************************************/
	void resize(int size_)
		{
			if (size >= 0)
			{
				_TD * buf = new _TD[size_];
				for(int f = 0; f <= size; f++)
					buf[f] = TVT[f];
				TVT = buf;
				
			}
		}

	/************************************\
	 * Name		:: Release				*
	 * Purpose	:: Release To Buffer	*
	\************************************/
	void Release()
		{
			delete[] TVT;
		}

	/************************************\
	 * Name		:: Get					*
	 * Purpose	:: Get To Buffer		*
	\************************************/
	_TD * GetTVT()
		{
			return TVT;
		}

	/************************************\
	 * Name		:: End					*
	 * Purpose	:: End At Buffer		*
	\************************************/
	_TD End()
		{
			return TVT[size - 1];
		}

	/************************************\
	 * Name		:: Empty				*
	 * Purpose	:: Empty At Buffer		*
	\************************************/
	bool Empty()
		{
			return size == 0;
		}

	/************************************\
	 * Name		:: Reverse				*
	 * Purpose	:: Reverse To Buffer	*
	\************************************/
	void Reverse()
		{
			_TD * buf = new _TD[size];
			int _size = size - 1;
			for(int i = 0; i <= _size; i++)
				buf[i] = pop();
			size = 0;
			for(int f = 0; f <= _size; f++)
				push(buf[f]);
		}

	/************************************\
	 * Name		:: sort					*
	 * Purpose	:: sort To Buffer		*
	\************************************/
	void sort()
		{
			int i, pass;
			_TD hold;
			for(pass = 1; pass <= (size-1); pass++)
				for(i = 0; i <= (size-2); i++)
					if(TVT[i] > TVT[i + 1])
					{
						hold = TVT[i];
						TVT[i] = TVT[i + 1];
						TVT[i + 1] = hold;
					}
		}

private:

	/************************************\
	 * Name		:: erase				*
	 * Purpose	:: Erase The Buffer	 	*
	\************************************/
	void erase(int size_)
		{
			resize(size_);
		}

private:

	_TD * TVT; // list

private:

	int size;
	int push_point;
	int pop_point;


};

template<class _TD>
inline void List<_TD>::ClearList()
{
	resize(0);
}

template<class _TD>
inline int List<_TD>::Size() const
{
	return size;
}


template<class _TD> 
class Stack
{
public:
	
	/************************************\
	 * Name		:: Stack				*
	 * Purpose	:: Initialize Buffer	*
	\************************************/
	Stack()
		: size(0), push_point(0)
		{
			TVT = new _TD[sizeof(_TD)];
		}
	~Stack()
		{
			Release();
		}

	/************************************\
	 * Name		:: ClearStack			*
	 * Purpose	:: Clear To Buffer		*
	\************************************/
	void ClearStack();

	/************************************\
	 * Name		:: Push					*
	 * Purpose	:: Push To Buffer		*
	\************************************/
	void push(_TD vt_size)
		{
			//Resize_A(size + 1);
			resize(size + 1);
			TVT[push_point++] = vt_size;
			size++;
		}

	/************************************\
	 * Name		:: Pop					*
	 * Purpose	:: Pop To Buffer		*
	\************************************/
	_TD pop()
		{
			_TD pop = TVT[0];
			if (size>0)
			{
				//Resize_A(--size);
				resize(--size);
				push_point--;
			}
			return pop;
		}

	/************************************\
	 * Name		:: Size					*
	 * Purpose	:: Size To Buffer		*
	\************************************/
	int Size() const;

	/************************************\
	 * Name		:: Resize				*
	 * Purpose	:: Resize To Buffer		*
	\************************************/
	void resize(int size_)
		{
			if (size >= 0)
			{
				_TD * buf = new _TD[size_];
				for(int f = 0; f <= size; f++)
					buf[f] = TVT[f];
				TVT = buf;
				
			}
		}

	/************************************\
	 * Name		:: Release				*
	 * Purpose	:: Release To Buffer	*
	\************************************/
	void Release()
		{
			delete[] TVT;
		}

	/************************************\
	 * Name		:: Get					*
	 * Purpose	:: Get To Buffer		*
	\************************************/
	_TD * GetTVT()
		{
			return TVT;
		}

	/************************************\
	 * Name		:: End					*
	 * Purpose	:: End At Buffer		*
	\************************************/
	_TD End()
		{
			return TVT[size - 1];
		}

	/************************************\
	 * Name		:: Empty				*
	 * Purpose	:: Empty At Buffer		*
	\************************************/
	bool Empty()
		{
			return size == 0;
		}

private:

	/************************************\
	 * Name		:: erase				*
	 * Purpose	:: Erase The Buffer	 	*
	\************************************/
	void erase(int size_)
		{
			resize(size_);
		}

private:

	_TD * TVT; // Stack

private:

	int size;
	int push_point;
	int pop_point;


};

template<class _TD>
inline void Stack<_TD>::ClearStack()
{
	resize(0);
}

template<class _TD>
inline int Stack<_TD>::Size() const
{
	return size;
}


_X_LIB_END
/*COMMON Lib End
*/

#define CCGFORGET template<class _Ty> 
#define CCCCOMMON _MyT(){} ~_MyT(){}
#define CCCDEFALL( _mytc ) _mytc(){} ~_mytc(){}

#endif

#endif
/*
 *	the rollrat library
 *	http://blog.naver.com/rollrat
V0.2:1290****/