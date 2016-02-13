/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once
#ifndef _vector_
#define _vector_

#pragma once
#ifndef _x_lib_strfmy
#define _x_lib_strfmy
#pragma once
#ifndef _x_lib_mate
#define _x_lib_mate
#
#if !defined(_UNDEF_NAMESPACE) && defined(__cplusplus)
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
#
#else
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
#
#endif
#if defined(__cplusplus)
#define _EX_SUCCESS
#endif
#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
#ifndef _SIZE_T_DEFINED
#ifdef  _WIN64
typedef unsigned __int64    size_t;
#else
typedef _w64 unsigned int   size_t;
#endif
#define _SIZE_T_DEFINED
#endif
#define _u	unsigned
typedef _u	int			uint;
typedef _u	char		uchar;
typedef _u	short		ushort;
typedef long long		llong;
typedef _u	long long	ullong;
#define UHigh( _hx )			((_hx) << (4)))
#define ULow( _hx )				((_hx) && (0xFF))
#define UCow( _hx , _x )		(((_hx) << (8)) | (_x))
#define UGet( _hx )				((_hx) & (0xFFFFFFFF))
#define LHigh( _hx )			((_hx) << (8))
#define LLow( _hx )				((_hx) && (0xFFFF))
#define LCow( _hx , _x )		(((_hx) << (4)) | (_x))
#define LGet( _hx )				((_hx) & (0xFFFF))
#define INT_MAX		0xffffffff
#define INT_HMAX	0x7fffffff
#define THROW_ERROR_INPUT(that) throw (that);
#define _NOTHROW				throw ()
#define BEGIN_TRY				try {
#define BEGIN_CATCH(what)		catch(what){
#define END_CATCH				}
#define END_TRY					}
#define INLINE			inline
#define FORCE_INLINE	__forceinline

template<class _Ty> inline
	_Ty *AddressOf(_Ty& _Val)
	{	// return address of _Val
	return (reinterpret_cast<_Ty *>(
		(&const_cast<char&>(
		reinterpret_cast<const volatile char&>(_Val)))));
	}

_X_LIB_END
#endif
#endif
#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

/*-------------------------------------------------

			Template Level Grid

	+-------+-----------------------------------+
	| _Ty1  | One level inherit or complexible  |
	| _Ty2  | Two level inherit or complexible  |
	|_Ty3~10| Three level inherit or complexible|
	+-------+-----------------------------------+
	| _Ty6  | Poly or unlimited level inherit   |
	+-------+-----------------------------------+
	| _Ty11 | Complex high level inherit        |
	+-------+-----------------------------------+

-------------------------------------------------*/

	// TEMPLATE STRUCT TYPE FAMILY
template<class _Ty01>
	struct __type
	{ // str type
	typedef _Ty01 value_type;
	typedef _Ty01 &reference;
	typedef _Ty01 *pointer;
	};

template<class _Ty01>
	struct __type<const _Ty01>
	{ // str type
	typedef _Ty01 value_type;
	typedef _Ty01 &reference;
	typedef _Ty01 *pointer;
	};

template<class _Ty01>
	struct _type
	{ // str type
	typedef __type<_type> type;
	};

template<class _Ty01, class _Ty02 = int>
	struct _Base
	{ // base type
	typedef _Ty01 value_type;
	typedef const _Ty01 const_value_type;
	typedef _Ty01* pointer;
	typedef const _Ty01* const_pointer;
	typedef _Ty01& reference;
	typedef const _Ty01& const_reference;
	typedef _Ty02 difference_type;
	typedef const _Ty02 const_difference_type;
	};

	// TEMPLATE STRUCT REMOVE FAMILY
template<class _Ty01> struct 
	ridof_const
	{ // remove const
	typedef typename _Ty01 type;
	};

template<class _Ty01> struct 
	ridof_const<const _Ty01>
	{ // remove const
	typedef typename _Ty01 type;
	};

template<class _Ty01> struct 
	ridof_const<const _Ty01[]>
	{ // remove const
	typedef typename _Ty01 type[];
	};

template<class _Ty01> struct 
	ridof_vole
	{ // remove volatile
	typedef typename _Ty01 type;
	};

template<class _Ty01> struct 
	ridof_vole<volatile _Ty01>
	{ // remove volatile
	typedef typename _Ty01 type;
	};

template<class _Ty01> struct 
	ridof_vole<volatile _Ty01[]>
	{ // remove volatile
	typedef typename _Ty01 type[];
	};

template<class _Ty01> struct 
	ridof_cv
	{ // remove const and volatile
	typedef typename ridof_const
	<typename ridof_vole
	<_Ty01>::type>::type type;
	};

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

template<class _Ty01> struct
	ridof_reference
	{ // remove reference
	typedef typename _Ty01 type;
	};

template<class _Ty01> struct
	ridof_reference<_Ty01&>
	{ // remove reference
	typedef typename _Ty01 type;
	};

template<class _Ty01> struct 
	ridof_pr
	{ // remove pointer and reference
	typedef typename ridof_reference
	<typename ridof_reference
	<_Ty01>::type>::type type;
	};

template<class _Ty01> struct
	ridof_cvpr
	{ // remove c v p r
	typedef typename ridof_cv
	<typename ridof_pr
	<_Ty01>::type>::type type;
	};

#define _VECTOR_ELEMENT_OPERATION(my_) \
	template<class my_>
#define _VECTOR_OPERATOR_ITERS(my_) \
	template<class my_>
#define _VECTOR_ITERATOR(my_, _fn, _cls_) \
	template<class my_>\
		_cls_ _fn{\
		_fn() : {} }

typedef void _Forcee;
#define __Force __forceinline
#define _Force __Force _Forcee
typedef bool _Hence;
#define _Hence __Force _Hence
namespace _vector_operation
{
	_VECTOR_ELEMENT_OPERATION(_Ty0)
		struct _VECTOR_NODES
		{ // vector nodes DNA
		_Ty0 _DATA;
		_VECTOR_NODES *_NEXT;
		_VECTOR_NODES *_PREV;
		};

#define _VECTOR_OPERATION _vector_operation::
}

_VECTOR_OPERATOR_ITERS(__Ty1)
	_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 
		operator<<(_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 
			*&_First, __Ty1 _Last)
	{ // first search
	for( ; _First != _First->_NEXT; )
		if(_First->_DATA == _Last)
			return _First;
		else
			_First = _First->_NEXT;
	return _First;
	}

_VECTOR_OPERATOR_ITERS(__Ty1)
	_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 
		operator>>(_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 
			*&_First, __Ty1 _Last)
	{ // last search
	for( ; _First != _First->_PREV; )
		if(_First->_DATA == _Last)
			return _First;
		else
			_First = _First->_PREV;
	return _First;
	}

template<class _Ty0> inline
	void _vector_move_forward(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, int _Last = 0)
	{ // vector move forward
	if(!_Last)
		for( ; _First != _First->_NEXT; )
			_First = _First->_NEXT;
	else
		for(int _TMP = 0; _TMP <= _Last &&
			_First != _First->_NEXT; )
			_First = _First->_NEXT;
	}

template<class _Ty0> inline
	void _vector_move_back(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, int _Last = 0)
	{ // vector move back
	if(!_Last)
		for( ; _First != _First->_PREV; )
			_First = _First->_PREV;
	else
		for(int _TMP = 0; _TMP <= _Last &&
			_First != _First->_PREV; )
			_First = _First->_PREV;
	}

template<class _Ty0, 
		typename _Fn0> inline
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		_vector_move_that_forward(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
		*&_First, _Ty0 _Last)
	{ // vector move that forward
	for( ; _First != _First->_NEXT; )
		if(_Fn0(_First->_DATA) == _Last)
			return _First;
		else
			_First = _First->_NEXT;
	}

template<class _Ty0, 
		typename _Fn0> inline
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		_vector_move_that_back(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
		*&_First, _Ty0 _Last)
	{ // vector move that back
	for( ; _First != _First->_PREV; )
		if(_Fn0(_First->_DATA) == _Last)
			return _First;
		else
			_First = _First->_PREV;
	}

namespace _vector_swap_
{
	template<typename unchecked_type> inline
		void _swap(unchecked_type& _Left, unchecked_type& _Right)
		{ // fill all by what parameter
		unchecked_type t = _Left; 
		_Left = _Right; 
		_Right = t;
		}

#define _VECTOR_SWAP _vector_swap_::
}

template<class _Ty0> inline
	void _vector_swap(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // vector swap
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *_TMP = _Second;
	_Second->_NEXT = _First->_NEXT;
	_Second->_PREV = _First->_PREV;
	_VECTOR_SWAP _swap<_Ty0> (_First->_DATA, _Second->_DATA);
	_First->_NEXT = _TMP->_NEXT;
	_First->_PREV = _TMP->_PREV;
	}

template<class _Ty0> inline
	void _vector_dswap(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // data swap
	_VECTOR_SWAP _swap<_Ty0> (_First->_DATA, _Second->_DATA);
	}

namespace _vector_alloc
{
	template<typename unchecked_type> inline
		_VECTOR_OPERATION 
			_VECTOR_NODES<unchecked_type> *_alloc()
		{ // fill all by what parameter
		_VECTOR_OPERATION 
			_VECTOR_NODES<unchecked_type> *ptr = new _VECTOR_OPERATION 
				_VECTOR_NODES<unchecked_type>;
		return ptr;
		}

#define _VECTOR_ALLOC _vector_alloc::
}

template<class _Ty0> inline
	void _vector_transfer(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // transfer to first
	_First->_NEXT = _Second->_NEXT;
	_First->_DATA = _Second->_DATA;
	_First->_PREV = _Second->_PREV;
	}

template<class _Ty0> inline
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*_vector_move(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
			*&_First)
	{ // vector move
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*_Temp = _VECTOR_ALLOC _alloc();
	_vector_transfer(_Temp, _First);
	return _Temp;
	}

namespace _vector_reverse
{
	template<class _Ty0> inline
		void _reverse(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
			*&_Head)
	{ // vector reverse
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *prev = 0;
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *curr = _Head;
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *next;
    while (curr != curr->_NEXT)
		{
        next = curr->_NEXT;
        curr->_NEXT = prev;
        prev = curr;
        curr = next;
		}
    _Head = prev;
	}

#define _VECTOR_REVERSE _vector_reverse::
}

template<class _Ty0> inline
	void _vector_homo(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // homo
	_First->_NEXT = _Second;
	_Second->_PREV = _First;
	}

template<class _Ty0> inline
	void _vector_hetero(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second,
			 _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Last)
	{ // hetero
	_First->_NEXT = _Second;
	_Second->_PREV = _First;
	_Second->_NEXT = _Last;
	_Last->_PREV = _Second;
	}

template<class _Ty0> inline
	void _vector_qsort(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // quick sort
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *set;
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *curr;
	if (_First == _Second) 
		return;
	set = _First;
	curr = set->_NEXT;
	while (1)
		{
		if (set->_DATA < curr->_DATA)
			_vector_dswap(set, curr);
		if (curr == _Second) 
			break;
		curr = curr->_NEXT;
		}
	_vector_dswap(_First, curr);
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *currs = curr;
	curr = curr->_PREV;
	if (curr != 0)
		if ((_First->_PREV != curr) && (curr->_NEXT != _First))
			_vector_qsort(_First, curr);
	curr = currs;
	curr = curr->_NEXT;
	if (curr != 0)
		if ((curr->_PREV != _Second) && (_Second->_NEXT != curr))
			_vector_qsort(curr, _Second);
	}

template<class _Ty0> inline
	int _vector_value(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // vector value
	int i = 0;
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *_TMP = _First;
	for(; _TMP != _Second; i++, _TMP = _TMP->_NEXT);
	return i + 1;
	}

template<class _Ty0> inline
	void _vector_sort(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // bubble sort
	int size = _vector_value(_First, _Second);
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *_TMP = _First;
	for(int n = 0; n <= size; n++)
		{
		for( ; _TMP != _Second; _TMP = _TMP->_NEXT)
			if(_TMP->_DATA > _TMP->_NEXT->_DATA)
				_vector_dswap(_TMP, _TMP->_NEXT);
		_TMP = _First;
		}
	}

template<class _Ty0> inline
	void _vector_remove(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // vector remove
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first = _First->_NEXT->_NEXT;
	for( ; first != _Second; first = first->_NEXT);
		delete first->_PREV;
	delete _First;
	delete _Second;
	}

template<class _Ty0> inline
	void _vector_copy(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second,
			_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
				*&_Third, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Last)
	{ // vector copy

	}

namespace _vector_operation
{
	namespace _vector_iterator
	{
#define _VECTOR_ITERATION _vector_iterator::

#define _VECTOR_OPEARTOR_ITERATOR_DISCONST_CONST_OPEARTION(temporary, iterbuf, iters, consts) \
			_Hence operator==(iterbuf *_left) consts\
			{\
			return temporary == _left;\
			}\
			_Hence operator!=(iterbuf *_left) consts\
			{\
			return temporary != _left;\
			}\
			_Hence operator==(iters _left) consts\
			{\
			return this->operator* == _left;\
			}\
			_Hence operator!=(iters _left) consts\
			{\
			return this->operator* != _left;\
			}\
			_Hence operator<(iters _left) consts\
			{\
			return this->operator* < _left;\
			}\
			_Hence operator>(iters _left) consts\
			{\
			return this->operator* > _left;\
			}\
			_Hence operator<=(iters _left) consts\
			{\
			return this->operator* <= _left;\
			}\
			_Hence operator>=(iters _left) consts\
			{\
			return this->operator* >= _left;\
			}

		_VECTOR_OPERATOR_ITERS(__Ty2)
			class _vector_iterator_dis_const
			{
				typedef typename _X_LIB __type<__Ty2>::value_type 
					iterator_vector_type;
				typedef typename _X_LIB __type<typename 
						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::pointer
					iterator_vector_type_disconst;
				typedef typename _X_LIB __type<typename 
						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::value_type
					iterator_vector_disconst;

				iterator_vector_disconst *__vector__temporary;

			public:

				_vector_iterator_dis_const()
					:
					{ }

				_vector_iterator_dis_const(iterator_vector_disconst _First)
					: __vector__temporary(_First)
					{ }

				_Force operator=(iterator_vector_disconst *_First)
					{ // operator =
					__vector__temporary = _First;
					}

				__Force __Ty2& operator*()
					{ // operator *
					return __vector__temporary->_DATA;
					}

				_Hence operator++(int)
					{ // operator ++
					__vector__temporary = __vector__temporary->_NEXT;
					return __vector__temporary != __vector__temporary->_NEXT;
					}

				_Hence operator--(int)
					{ // operator --
					__vector__temporary = __vector__temporary->_PREV;
					return __vector__temporary != __vector__temporary->_PREV;
					}

				_VECTOR_OPEARTOR_ITERATOR_DISCONST_CONST_OPEARTION
					(__vector__temporary, iterator_vector_disconst, __Ty2, )

			};

		_VECTOR_OPERATOR_ITERS(__Ty2)
			class _vector_iterator_const
			{
				typedef typename _X_LIB __type<__Ty2>::value_type 
					iterator_vector_type;
				typedef typename _X_LIB __type<typename 
						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::pointer
					iterator_vector_type_const;
				typedef typename _X_LIB __type<typename 
						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::value_type
					iterator_vector_const;

				iterator_vector_const *__vector__temporary;

			public:

				_vector_iterator_const()
					:
					{ }

				_vector_iterator_const(iterator_vector_const _First)
					: __vector__temporary(_First)
					{ }

				_Force operator=(iterator_vector_const *_First)
					{ // operator =
					__vector__temporary = _First;
					}

				__Force __Ty2 operator*() const
					{ // operator *
					return __vector__temporary->_DATA;
					}

				_Hence operator++(int)
					{ // operator ++
					__vector__temporary = __vector__temporary->_NEXT;
					return __vector__temporary != __vector__temporary->_NEXT;
					}

				_Hence operator--(int)
					{ // operator --
					__vector__temporary = __vector__temporary->_PREV;
					return __vector__temporary != __vector__temporary->_PREV;
					}

				_VECTOR_OPEARTOR_ITERATOR_DISCONST_CONST_OPEARTION
					(__vector__temporary, iterator_vector_const, __Ty2, const)

			};
	}
}
	
	// STANDRAD VECTOR
template<class _Vector_Element>
	class vector
	{ // vector class
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Vector_Element> *_Head;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Vector_Element> *_Lastest;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Vector_Element> *_Tail;

	int _Pointer, _Back_PP, _size;
	bool vlock;

	public:

	typedef typename _VECTOR_OPERATION _VECTOR_ITERATION 
		_vector_iterator_const<_Vector_Element>
		const_iterator;

	typedef typename _VECTOR_OPERATION _VECTOR_ITERATION 
		_vector_iterator_dis_const<_Vector_Element>
		iterator;

	explicit vector()
		: _Back_PP(0), _Pointer(0), _size(0)
		{ // vector intalled
			_Head = _New_Node();
			_Tail = _New_Node();
			_Head->_PREV = _Head;
			_Head->_NEXT = _Tail;
			_Tail->_PREV = _Head;
			_Tail->_NEXT = _Tail;
			vlock = true;
		}

	virtual ~vector()
		{ // vector desconductor
#ifndef _VECTOR_REMOVE_OPTION_USELESS
		_vector_remove(_Head, _Tail);
#endif
		}

	private: __Force void _Vector_Nodes_Connects(_VECTOR_OPERATION 
				 _VECTOR_NODES<_Vector_Element> *_First,
					_VECTOR_OPERATION 
						_VECTOR_NODES<_Vector_Element> *_Target,
							_VECTOR_OPERATION
								_VECTOR_NODES<_Vector_Element> *_Last)
			{ // nodes connect
				_First->_NEXT = _Target;
				_Target->_PREV = _First;
				_Target->_NEXT = _Last;
				_Last->_PREV = _Target;
			}

	public:

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&begin()
			{ // begin function
				return _Head->_NEXT;
			}

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&end()
			{ // begin function
				return _Tail;
			}

	private: __Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *_New_Node()
		{ // create new node
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = new _VECTOR_OPERATION 
				_VECTOR_NODES<_Vector_Element>;
		return ptr;
		}

	public:

		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&operator[](int _First)
		{ // operator []
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *_Temp = _Head;
		for( int Fn_n = 0; 
				Fn_n <= _First; Fn_n++)
			_Temp = _Temp->_NEXT;
		return _Temp;
		}

		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&operator()(int _First)
		{ // operator ()
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *_Temp = _Tail;
		for( int Fn_n = 0; 
				Fn_n <= _First; Fn_n++)
			_Temp = _Temp->_PREV;
		return _Temp;
		}

		void push_back(_Vector_Element _left)
		{ // push back item
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *temp = _New_Node();
		temp->_DATA = _left;
		if (_Back_PP)
			_Vector_Nodes_Connects(_Lastest, temp, _Tail);
		else
			_Vector_Nodes_Connects(_Head, temp, _Tail);
		_Lastest = temp;
		_Back_PP++;
		_size++;
		}
		}

		void push_front(_Vector_Element _left)
		{ // push back item
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *temp = _New_Node();
		temp->_DATA = _left;
		_Vector_Nodes_Connects(_Head, temp, _Head->_NEXT);
		_Lastest = temp;
		_Back_PP++;
		_size++;
		}
		}

		_Vector_Element pop_back()
		{ // pop back item
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *prev = _Head;
		_Vector_Element ret;
		for(int f = -1; ; f++)
			{
			if(ptr == _Tail->_PREV)
				break;
			if(f >= 0)
				prev = prev->_NEXT;
			ptr = ptr->_NEXT;
			}
		ret = ptr->_DATA;
		delete ptr;
		_Connect(prev, _Tail);
		_Back_PP--;
		_size--;
		return ret;
		}
		}

		_Vector_Element pop_front()
		{ // pop back item
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		_Vector_Element ret = ptr->_DATA;
		_Connect(_Head, ptr->_NEXT);
		delete ptr;
		_Back_PP--;
		_size--;
		return ret;
		}
		}

		_Force remove()
		{ // vector clear
		if(vlock){
		_vector_remove(_Head, _Tail);
		}
		}

	private: _Force _Connect(_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *_head, _VECTOR_OPERATION 
				_VECTOR_NODES<_Vector_Element> *_tail)
		{ // connect link
		_head->_NEXT = _tail;
		_tail->_PREV = _head;
		}

	public:

		_Force reserve(int _First)
		{ // resize vector
		if(vlock){
		for(int i = 0; i <= _First; i++)
			push_back(0);
		}
		}

		__Force int size() const
		{ // get size
		return _size;
		}

		void insert(_Vector_Element _First, int _Pos)
		{ // insert value
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr_next;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *temps = _New_Node();
		for( int Fn_n = 0; 
				Fn_n <= _Pos; Fn_n++)
			ptr = ptr->_NEXT;

		ptr_next = ptr->_NEXT;
		ptr->_NEXT = temps;
		temps->_NEXT = ptr_next;
		ptr_next->_PREV = temps;

		temps->_DATA = _First;
		}
		}

		void erase(int _Pos)
		{ // erase value
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr_next;
		for( int Fn_n = 0; 
				Fn_n <= _Pos; Fn_n++)
			ptr = ptr->_NEXT;
		ptr->_PREV->_NEXT = ptr->_NEXT;
		ptr->_NEXT->_PREV = ptr->_PREV;
		delete ptr;
		}
		}

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&front()
		{ // front function
		return _Head->_NEXT;
		}

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&back()
		{ // front function
		return _Tail->_PREV;
		}

		_Force fill(_Vector_Element _Elem)
		{ // fill all
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		for( ; ptr != _Tail; )
			ptr->_DATA = _Elem, ptr = ptr->_NEXT;
		}
		}

		_Force assign(_Vector_Element _First, int _Last)
		{ // assign function
		if(vlock){
		for(int i = 0; i <= _Last; i++)
			push_back(_First);}
		}

		_Force asign(_Vector_Element _First, int _LPos, int _RPos)
		{ // asign funciton
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		for(int f = 0; f <= _LPos; f++)
			ptr = ptr->_NEXT;
		for(int i = _LPos; i <= _RPos; i++)
			ptr->_DATA = _First, ptr = ptr->_NEXT;}
		}

		_Force reverse()
		{ // vector reverse
		if(vlock)
		_VECTOR_REVERSE _reverse(_Head);
		}

		_Force sort()
		{ // vector sort
		if(vlock)
		_vector_sort(front(), back());
		}

		_Force lock()
		{ // vector lock
		vlock = false;
		}

		_Force unlock()
		{ // vector unlock
		vlock = true;
		}

	};

template<class _Ty0> inline
	int _vector_first_match(vector<_Ty0> *&_First, 
		_Ty0 &_Last)
	{ // vector first match method
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *ptr = _First->front();
	for(int i = 0 ; ptr != _First->_Tail; 
			ptr = ptr->_NEXT, i++)
		if(ptr->_DATA == _Last)
			return i;
	}

template<class _Ty0> inline
	int _vector_perfect_match(vector<_Ty0> *&_First, 
		vector<_Ty0> *&_Last)
	{ // vector first match method
	if(_First->size() < _Last->size())
		return -1;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first_next = _First->front();
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *last_next = _Last->front();
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first_temp = 0;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *last_temp = 0;
	int flen = _First->size(), llen = _Last->size();
	for(int i = 0; i <= flen; i++, first_next = first_next->_NEXT)
		if(first_next->_DATA == last_next->_DATA){
			first_temp = first_next, last_temp = last_next;
			for(int n = 0; n <= llen; n++, last_next = last_next->_NEXT, 
					first_next = first_next->_NEXT)
				if(last_next->_DATA != first_next->_DATA)
					first_next = first_temp, last_next = last_temp, 
					break;
				else if(n == llen)
					return i;}
	}

template<class _Ty0> inline
	int _vector_times_match(vector<_Ty0> *&_First, 
		_Ty0 &_Last, int times = 1)
	{ // vector times match
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *ptr = _First->front();
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *ptrs = 0;
	for(int i = 0 ; ptr != _First->_Tail; 
			ptr = ptr->_NEXT, i++)
		if(ptr->_DATA == _Last){
			ptrs = ptr;
			for(int f = 1; f <= times; 
				ptr = ptr->_NEXT, f++)
				if(ptr->_DATA == _Last)
					return i;
			ptr = ptrs;}
	}

template<class _Ty0> inline
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *& 
		_vector_disconnect_and_connect(_VECTOR_OPERATION 
			_VECTOR_NODES<_Ty0> *&_First, _VECTOR_OPERATION 
				_VECTOR_NODES<_Ty0> *&_Second, _VECTOR_OPERATION 
					_VECTOR_NODES<_Ty0> *&_Third, _VECTOR_OPERATION 
						_VECTOR_NODES<_Ty0> *&_Last)
	{ // disconnect and connect
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first_next = _First->_NEXT;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *last_prev = _Last->_PREV;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *gd = _VECTOR_ALLOC _alloc();
	_First->_NEXT = _Second;
	_Second->_PREV = _First;
	_Third->_NEXT = _Last;
	_Last->_PREV = _Third;
	gd->_NEXT = first_next;
	gd->_PREV = last_prev;
	return gd;
	}

template<class _Ty0> inline
	int _vector_element_count(_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *&_First, _Ty0 _Second)
	{ // vector element count
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first_next = _First;
	int let = 0;
	for( ; first_next != 
		first_next->_NEXT; first_next = first_next->_NEXT)
			if(first_next->_DATA == _Second)
				let++;
	return let;
	}

		// STANDARD STACK
template<class _Stack_Element>
	class stack
	{ // stack class
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Stack_Element> *_Head;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Stack_Element> *_Lastest;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Stack_Element> *_Tail;
	
	public:

		explicit stack()
		{ // stack intalled
		_Head = _New_Node();
		_Tail = _New_Node();
		_Head->_PREV = _Head;
		_Head->_NEXT = _Tail;
		_Tail->_PREV = _Head;
		_Tail->_NEXT = _Tail;
		_Head->_DATA = 0;
		_Lastest = _Head;
		}

		virtual ~stack()
		{ // stack desconductor
		_vector_remove(_Head, _Tail);
		}

		void push(_Stack_Element _left)
		{ // push back item
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *temp = _New_Node();
		temp->_DATA = _left;
		_Vector_Nodes_Connects(_Lastest, temp, _Tail);
		_Lastest = temp;
		}

		_Stack_Element pop()
		{ // pop back item
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *ptr = _Head;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *prev = _Head;
		_Stack_Element ret;
		for(int f = -1; ; f++)
			{
			if(ptr == _Tail->_PREV)
				break;
			if(f >= 0)
				prev = prev->_NEXT;
			ptr = ptr->_NEXT;
			}
		ret = ptr->_DATA;
		delete ptr;
		_Connect(prev, _Tail);
		return ret;
		}

	private:

		_Force _Connect(_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *_head, _VECTOR_OPERATION 
				_VECTOR_NODES<_Stack_Element> *_tail)
		{ // connect link
		_head->_NEXT = _tail;
		_tail->_PREV = _head;
		}

		__Force void _Vector_Nodes_Connects(_VECTOR_OPERATION 
		 _VECTOR_NODES<_Stack_Element> *_First,
			_VECTOR_OPERATION 
				_VECTOR_NODES<_Stack_Element> *_Target,
					_VECTOR_OPERATION
						_VECTOR_NODES<_Stack_Element> *_Last)
		{ // nodes connect
		_First->_NEXT = _Target;
		_Target->_PREV = _First;
		_Target->_NEXT = _Last;
		_Last->_PREV = _Target;
		}

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *_New_Node()
		{ // create new node
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *ptr = new _VECTOR_OPERATION 
				_VECTOR_NODES<_Stack_Element>;
		return ptr;
		}

	};

	// VECTOR CHROMOSOMAL STRUCTURE ANOMALIES FAMILY
template<class _Ty0> inline
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0>*& _vector_nondisjunction(_VECTOR_OPERATION 
			_VECTOR_NODES<_Ty0> *&_First)
	{ // vector nondisjunction
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *_next = _First->_NEXT;
	_First->_NEXT = _First->_PREV;
	_First->_PREV = _next;
	return _next;
	}

template<class _Ty0> inline
	void _vector_translocation(_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *&_First, _VECTOR_OPERATION 
			_VECTOR_NODES<_Ty0> *&_Last, bool dataion = 0)
	{ // vector translocation (=<=> vector swap)
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *_next = _First->_NEXT;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *_prev = _First->_PREV;
	_First->_NEXT = _Last->_NEXT;
	_First->_PREV = _Last->_PREV;
	_Last->_NEXT = _next;
	_Last->_PREV = _prev;
	if(!dataion)
		_vector_dswap(_First, _Last);
	}

template<class _Ty0> inline
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0>*& _vector_deletion(_VECTOR_OPERATION 
			_VECTOR_NODES<_Ty0> *&_First, _VECTOR_OPERATION 
				_VECTOR_NODES<_Ty0> *&_Second, _VECTOR_OPERATION 
					_VECTOR_NODES<_Ty0> *&_Last, bool deletes = 0)
	{ // vector deletion
	_First->_NEXT = _Last;
	_Second->_NEXT = _Second;
	_Second->_PREV = _Second;
	_Last->_PREV = _First;
	if(deletes)
		delete _Second;
	return _Second;
	}

	// VECTOR REPLACE FUCNTIONS
template<class _Ty3> inline
	void _vector_replace(vector<_Ty3>& _First,  
		vector<_Ty3>& _Second,
			vector<_Ty3>& _Last)
	{ // vector replcae
	_VECTOR_OPERATION _VECTOR_NODES<_Ty3>
		*_f_n = _First.front(), *f_n_b,
		*_f_p = _First.back(),
		*_s_n = _Second.front(), *s_n_b,
		*_s_p = _Second.back(),
		*_l_n = _Last.front(),
		*_l_p = _Last.back();
	for( ; _f_n != _f_p; _f_n = _f_n->_NEXT)
		if(_f_n->_DATA == _s_n->_DATA)
			for(s_n_b = _s_n, f_n_b = _f_n
				; _s_n->_DATA == _f_n->_DATA; _s_n = 
				_s_n->_NEXT, _f_n = _f_n->_NEXT)
				if(_f_n->_DATA != _s_n->_DATA){
					_f_n = f_n_b, _s_n = s_n_b;break;}
				else if (_s_n == _s_p->_PREV){
					f_n_b->_PREV->_NEXT = _l_n, 
					_l_p->_NEXT = _f_n;
					return;}
	}

template<class _Ty3> inline
	void _vector_replace2(vector<_Ty3>& _First,  
		vector<_Ty3>& _Second,
			vector<_Ty3>& _Last)
	{ // vector replcae2
	_VECTOR_OPERATION _VECTOR_NODES<_Ty3>
		*_f_n = _First.front(), *f_n_b,
		*_f_p = _First.back(),
		*_s_n = _Second.front(), *s_n_b,
		*_s_p = _Second.back(),
		*_l_n = _Last.front(),
		*_l_p = _Last.back();
	for( ; _f_n != _f_p; _f_n = _f_n->_NEXT)
		if(_f_n->_DATA == _s_n->_DATA)
			for(f_n_b = _f_n, s_n_b = _s_n;
				_s_n != _s_p;
				_f_n = _f_n->_NEXT, _s_n = _s_n->_NEXT)
				if(_s_n->_DATA != _f_n->_DATA){
					_s_n = s_n_b;_f_n = f_n_b;break;}
				else if(_s_n == _s_p->_PREV){
					f_n_b->_PREV->_NEXT = _l_n;
					_l_p->_NEXT = _f_n;
					return;}
	}

_X_LIB_END
#endif

/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_VECTOR_
#define _ROLLRAT_VECTOR_
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

/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_CUTILITYEX_
#define _ROLLRAT_CUTILITYEX_

/*-------------------------------------------------------------------------

				The Computer Data Algorithm List Set

	Contains a set of classes for a variety of algorithms. It is freely 
	available, constantly updated, but when it shall be reported to the 
	owner of copyright, without the prior written consent can be copied 
	and redistributed. Iterator also available in some cases, the original 
	array is a list of functions.However, please note that functions some 
	functions that should be included, if the argument is.

-------------------------------------------------------------------------*/

#if defined(_EX_SUCCESS)

_X_LIB_BEGIN
	
template<typename differentkindof_type> inline
	void _seperate(differentkindof_type value_type_ex, 
		differentkindof_type multibyteset)
	{ // change the operation and operation
	differentkindof_type buf = *value_type_ex;
	*value_type_ex = *multibyteset;
	*multibyteset = buf;
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
	void _swap(unchecked_type* _left, int f)
	{ // algorithm element, change from point to point
	unchecked_type _buf;
	_buf = *_left;
	*_left = _left[f];
	_left[f] = _buf;
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
	void _quick_sort(unchecked_type *_left, int _lsize, int _buf = 0)
	{ // being quick sorting the array is faster than any others
	int i = 0, j = _lsize;
	unchecked_type temp;
	if (_lsize > 1)
		{
		while(i < j)
			{
			while(_left[++i] < *_left && i < _lsize);
			while(_left[--j] > *_left);
			if ( i < j ) 
				_swap(_left, i, j);
			}
		_swap(_left, j++);
		_quick_sort(_left, j - 1);
		_quick_sort(_left + j, _lsize - j - 2);
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

_X_LIB_END

#endif

#endif
/*
 *	the rollrat library
 *	http://blog.naver.com/rollrat
V0.2:1452****/


#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN

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

_X_LIB_END

#endif
	
#endif

#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0013****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/