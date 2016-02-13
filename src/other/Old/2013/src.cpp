/*************************************************************************
*
*                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
*
*                         (C) Copyright 2009-2014
*                                  rollrat
*                           All Rights Reserved
*
*************************************************************************/

#include <stdio.h>

#ifndef _SIZE_T_DEFINED
#ifdef  _WIN64
typedef unsigned __int64    size_t;
#else
typedef _w64 unsigned int   size_t;
#endif
#define _SIZE_T_DEFINED
#endif
#define _u	unsigned
#define TEMPLATE template
#define CLST	class
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
#define _X_LIB
#pragma pack( push , 8 ) /* Padding bit */
#define IF(dest)			{try { dest; }
#define SWITCH_START(ret)	catch(char *value){ ret result = (ret)value;
#define SWITCH_END			}
#define RETURN				throw (char *)(void *)
#define END_IF				}
#define THROWX				throw()
#define NONE_RET			void
#if !defined(NO_USING_NAMESPACE)
#	define _ADK_START	namespace adk {
#	define _ADK_END		}
#	define _ADK			::adk::
#else /* defined(NO_USING_NAMESPACE) */
#	define _ADK_START
#	define _ADK_END
#	define _ADK
#endif /* (NO_USING_NAMESPACE) */
#define _IN		inline
#pragma pack( pop )
#define offset_of(_Stru, _Member) \
	(_OffSet)&((_Stru *)0)->_Member

#define container_of(_Pt, _Stru, _Member) \
	(_Stru *)((char *)_Ptr - offset_of<_Stru, _Member>())

#define receive_pointer( t )	*(_ADK receive(&t))

#pragma pack( push , 8 ) /* Padding bit */

#define _TADC(x) int hf = make_hash(_Dest); _Addr[count]._Addr = _Addr(_Stru, _Ptr);\
	_Addr[count].size = x; _Addr[count].hash_code = hf; count += 1

#define _Addr(ap, v) *((ap *)_Address_of(v))

#pragma pack( pop )

#define _In_		const
#define _Out_
#define _In_Var_
#define _addr
#define _stringc
#define _t_cast(x)	((char *)(void *)(x))
#define _r_cast(x)	(reinterpret_cast<char *> (x))
#define _Expc(x)	(*x).
#define _Impl(x)	(*x).
#define UMC
#define ERROR		(-1)
#define SUCCESS		(0)
#define IF_SUCCESS(x)	if(x == SUCCESS){
#define IF_ERROR(x)		if(x == ERROR){
#define FOR_ZERO(x)		for(; *x; x++){
#define FOR_LAST(x,y)	for(; y; x--){
#define END_FOR			}
#define END_IF			}
#define bit_switch			( pos )					(1 << ((pos) - 1))
#define bit_get				( bits, rank )			((bits) & bit_switch(rank))
#define bit_set				( bits, rank, bit )		(bit_get(bits, rank) & bit_switch(rank))
#define bit_get_s			( bits, rank )			(((bits) & bit_switch(rank)) >> (rank))
#define bit_duplicate		( rank )				((2 << ((rank) + 1)) - 1)
#define bit_rotate_l		( bits, rank, n )		(((bits) << (rank)) | ((bits) >> ((n)-(rank))))
#define bit_rotate_r		( bits, rank, n )		(((bits) >> (rank)) | ((bits) << ((n)-(rank))))
#define bit_rotate_l32		( bits, rank )			bit_rotate_l(bist, rank, 32)
#define bit_rotate_r32		( bits, rank )			bit_rotate_r(bist, rank, 32)
#define bit_lock			( bits, obits )			((bits) ^ (~(obits)))

  #define pvcl	public: virtual void pvcl() = 0;

#define getrvalue_macro( t, v )	( ( t&& ) v )

#define INLINE			inline

#define _VECTOR_ELEMENT_OPERATION(my_) \
	TEMPLATE<CLST my_>
#define _VECTOR_OPERATOR_ITERS(my_) \
	TEMPLATE<CLST my_>
#define _VECTOR_ITERATOR(my_, _fn, _cls_) \
	TEMPLATE<CLST my_>\
		_cls_ _fn{\
		_fn() : {} }

typedef void _Force;
typedef bool _Hence;
#define __Force __forceinline
#define _Force __Force _Force

#define _Hence __Force _Hence
#define _VECTOR_OPERATION _vector_operation::

#define _VECTOR_SWAP _vector_swap_::

#define _VECTOR_ALLOC _vector_alloc::

#define _VECTOR_REVERSE _vector_reverse::
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

	#define COMMON_INCLASS_USEAGE_FOR _InputT n = 0; n <= arange; n++

#define radian 0.01745329251994329576923690768489
#define _INCREASE(x)		x += 1
#define _DECREASE(x)		x -= 1

#define __Lock_Int(x)	___tg1_lock_ptr<x, int>::

#ifdef  __cplusplus
#define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
#else
#define _ADDRESSOF(v)   ( &(v) )
#endif

#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (va_list)0 )

#define _EOFSETUP		0

#define _NONE_ACTIVE	;

#define _VALIATED_RETURN( val, set, x ) \
if (!val) return set ? 0 : x

#define _U	unsigned

#define put(x) n++, *(sptr++) = x

#define forward (_ptr + i + 1)


typedef _u	int			uint;typedef _u	char		uchar;typedef _u	short		ushort;typedef long long		llong;typedef _u	long long	ullong;TEMPLATE<CLST _Ty> inline	_Ty *AddressOf(_Ty& _Val)	{	
	return (reinterpret_cast<_Ty *>(		(&const_cast<char&>(		reinterpret_cast<const volatile char&>(_Val)))));	}typedef unsigned int size_t;
TEMPLATE<CLST _Ty>struct remove_pointer	{	
	typedef _Ty type;	};TEMPLATE<CLST _Ty>struct remove_pointer<_Ty *>	{	
	typedef _Ty type;	};	
TEMPLATE<CLST _Ty01>	struct __type	{ 
	typedef _Ty01 value_type;	typedef _Ty01 &reference;	typedef _Ty01 *pointer;	};TEMPLATE<CLST _Ty01>	struct __type<const _Ty01>	{ 
	typedef _Ty01 value_type;	typedef _Ty01 &reference;	typedef _Ty01 *pointer;	};TEMPLATE<CLST _Ty01>	struct _type	{ 
	typedef __type<_type> type;	};TEMPLATE<CLST _Ty01, CLST _Ty02 = int>	struct _Base	{ 
	typedef _Ty01 value_type;	typedef const _Ty01 const_value_type;	typedef _Ty01* pointer;	typedef const _Ty01* const_pointer;	typedef _Ty01& reference;	typedef const _Ty01& const_reference;	typedef _Ty02 difference_type;	typedef const _Ty02 const_difference_type;	};	
TEMPLATE<CLST _Ty01> struct 	ridof_const	{ 
	typedef typename _Ty01 type;	};TEMPLATE<CLST _Ty01> struct 	ridof_const<const _Ty01>	{ 
	typedef typename _Ty01 type;	};TEMPLATE<CLST _Ty01> struct 	ridof_const<const _Ty01[]>	{ 
	typedef typename _Ty01 type[];	};TEMPLATE<CLST _Ty01> struct 	ridof_vole	{ 
	typedef typename _Ty01 type;	};TEMPLATE<CLST _Ty01> struct 	ridof_vole<volatile _Ty01>	{ 
	typedef typename _Ty01 type;	};TEMPLATE<CLST _Ty01> struct 	ridof_vole<volatile _Ty01[]>	{ 
	typedef typename _Ty01 type[];	};TEMPLATE<CLST _Ty01> struct 	ridof_cv	{ 
	typedef typename ridof_const	<typename ridof_vole	<_Ty01>::type>::type type;	};TEMPLATE<CLST _Ty01> struct	ridof_pointer	{ 
	typedef typename _Ty01 type;	};TEMPLATE<CLST _Ty01> struct	ridof_pointer<_Ty01*>	{ 
	typedef typename _Ty01 type;	};TEMPLATE<CLST _Ty01> struct	ridof_pointer<_Ty01[]>	{ 
	typedef typename _Ty01 type;	};TEMPLATE<CLST _Ty01> struct	ridof_reference	{ 
	typedef typename _Ty01 type;	};TEMPLATE<CLST _Ty01> struct	ridof_reference<_Ty01&>	{ 
	typedef typename _Ty01 type;	};TEMPLATE<CLST _Ty01> struct 	ridof_pr	{ 
	typedef typename ridof_reference	<typename ridof_reference	<_Ty01>::type>::type type;	};TEMPLATE<CLST _Ty01> struct	ridof_cvpr	{ 
	typedef typename ridof_cv	<typename ridof_pr	<_Ty01>::type>::type type;	};_ADK_START TEMPLATE<CLST _adk_base> struct	base_list	{ 
	typedef typename _adk_base value_type;	typedef typename _adk_base* pointer;	typedef typename _adk_base& reference;	typedef typename const _adk_base* const_pointer;	typedef typename const _adk_base& const_reference;	};TEMPLATE<CLST _adk_list> struct	_adk_list		: public base_list<_adk_list>	{ 
	typedef struct _adk_list* str_pointer;	str_pointer _Next;	str_pointer _Prev;	value_type _Data;	};TEMPLATE<CLST _iterator> CLST	iterator	{ 
	typedef iterator<_iterator> this_type;		typedef typename _iterator::value_type value_type;	typedef typename _iterator::pointer pointer;	typedef typename _iterator::str_pointer str_pointer;	typedef typename _iterator::reference reference;public:	iterator()		: _Ptr()		{ 
		}	iterator(str_pointer ptr)		: _Ptr(ptr)		{ 
		}	void operator=(str_pointer ptr)		{ 
		_Ptr = ptr;		}	pointer operator->()		{ 
		return &(**this);		}	this_type& operator++()		{ 
		if(this->_Ptr->_Next == this->_Ptr)			return (*this);		this->_Ptr = this->_Ptr->_Next;		return (*this);		}	this_type operator++(int)		{ 
		this_type _Tmp = *this;		++*this;		return (_Tmp);		}		this_type& operator--()		{ 
		if(this->_Ptr->_Prev == this->_Ptr)			return (*this);		this->_Ptr = this->_Ptr->_Prev;		return (*this);		}	this_type operator--(int)		{ 
		this_type _Tmp = *this;		--*this;		return (_Tmp);		}	reference operator*()		{ 
		return (_Ptr->_Data);		}	this_type& operator+=(int _Off)		{ 
		if(_Off > 0)			for( int i = 0; i < _Off; i++)				++*this;		else if(_Off < 0)			for( int i = 0; i < -_Off; i++)				--*this;		return (*this);		}	this_type operator+(int _Off)		{ 
		this_type _Tmp = *this;		return (_Tmp += _Off);		}	this_type& operator-=(int _Off)		{ 
		return (*this += -_Off);		}	this_type operator-(int _Off)		{ 
		this_type _Tmp = *this;		return (_Tmp -= _Off);		}	int operator-(const this_type& _Right) const		{ 
		int _tmp;		str_pointer my = _Ptr, rig = _Right._Ptr;		if(my == rig)			return (0);		for(_tmp = 0; (my != rig) && (my != my->_Next)			; _tmp++, my = my->_Next)			;		if(my == rig)			return (_tmp);		for(_tmp = 0, my = _Ptr; (my != rig) && (rig != rig->_Next)			; _tmp++, rig = rig->_Next)			;		if(my == rig)			return (_tmp);		return (-1);		}	reference operator[](int _Off)		{ 
		return (*(*this + _Off));		}	bool operator==(const this_type& _Right) const		{ 
		return (this->_Ptr == _Right._Ptr);		}	bool operator!=(const this_type& _Right) const		{ 
		return (!(*this == _Right));		}	bool operator<(const this_type& _Right) const		{ 
		return (this->_Ptr < _Right._Ptr);		}	bool operator>(const this_type& _Right) const		{ 
		return (_Right < *this);		}	bool operator<=(const this_type& _Right) const		{ 
		return (!(_Right < *this));		}	bool operator>=(const this_type& _Right) const		{ 
		return (!(*this < _Right));		}protected:	str_pointer _Ptr;	};TEMPLATE<CLST _iterator> CLST	const_iterator	{ 
	typedef const_iterator<_iterator> this_type;		typedef typename _iterator::value_type value_type;	typedef typename _iterator::pointer pointer;	typedef typename _iterator::str_pointer str_pointer;	typedef typename _iterator::reference reference;public:	const_iterator()		: _Ptr()		{ 
		}	const_iterator(str_pointer ptr)		: _Ptr(ptr)		{ 
		}		void operator=(str_pointer ptr)		{ 
		_Ptr = ptr;		}	pointer operator->() const		{ 
		return &(**this);		}	this_type& operator++()		{ 
		if(this->_Ptr->_Next == this->_Ptr)			return (*this);		this->_Ptr = this->_Ptr->_Next;		return (*this);		}	this_type operator++(int)		{ 
		this_type _Tmp = *this;		++*this;		return (_Tmp);		}		this_type& operator--()		{ 
		if(this->_Ptr->_Prev == this->_Ptr)			return (*this);		this->_Ptr = this->_Ptr->_Prev;		return (*this);		}	this_type operator--(int)		{ 
		this_type _Tmp = *this;		--*this;		return (_Tmp);		}	reference operator*() const		{ 
		return (_Ptr->_Data);		}	this_type& operator+=(int _Off)		{ 
		if(_Off > 0)			for( int i = 0; i < _Off; i++)				++*this;		else if(_Off < 0)			for( int i = 0; i < -_Off; i++)				--*this;		return (*this);		}	this_type operator+(int _Off)		{ 
		this_type _Tmp = *this;		return (_Tmp += _Off);		}	this_type& operator-=(int _Off)		{ 
		return (*this += -_Off);		}	this_type operator-(int _Off)		{ 
		this_type _Tmp = *this;		return (_Tmp -= _Off);		}	int operator-(const this_type& _Right) const		{ 
		int _tmp;		str_pointer my = _Ptr, rig = _Right._Ptr;		if(my == rig)			return (0);		for(_tmp = 0; (my != rig) && (my != my->_Next)			; _tmp++, my = my->_Next)			;		if(my == rig)			return (_tmp);		for(_tmp = 0, my = _Ptr; (my != rig) && (rig != rig->_Next)			; _tmp++, rig = rig->_Next)			;		if(my == rig)			return (_tmp);		return (-1);		}	reference operator[](int _Off) const		{ 
		return (*(*this + _Off));		}	bool operator==(const this_type& _Right) const		{ 
		return (this->_Ptr == _Right._Ptr);		}	bool operator!=(const this_type& _Right) const		{ 
		return (!(*this == _Right));		}	bool operator<(const this_type& _Right) const		{ 
		return (this->_Ptr < _Right._Ptr);		}	bool operator>(const this_type& _Right) const		{ 
		return (_Right < *this);		}	bool operator<=(const this_type& _Right) const		{ 
		return (!(_Right < *this));		}	bool operator>=(const this_type& _Right) const		{ 
		return (!(*this < _Right));		}	protected:	str_pointer _Ptr;	};TEMPLATE<CLST _adk_array> CLST/*	Caution : 	That For comparison is the front() and back(), and that for 	the assignment is begin() and end(). */	basic_array	{ 
	typedef _adk_list<_adk_array> _MyList;		typedef typename _MyList::value_type value_type;	typedef typename _MyList::pointer pointer;	typedef typename _MyList::str_pointer str_pointer;	typedef typename _MyList::reference reference;public:		typedef iterator<_adk_list<_adk_array> > iterator;	typedef const_iterator<_adk_list<_adk_array> > const_iterator;	explicit basic_array()		{ 
		_Head = new _MyList;		_Tail = new _MyList;		_Head->_Prev = _Head;		_Head->_Next = _Tail;		_Tail->_Prev = _Head;		_Tail->_Next = _Tail;		_Curr = _Head;		}	void allocate(int size)		{ 
		for(int i = 0; i < size; i++)			{			str_pointer _Tmp = new _MyList;			_Curr->_Next = _Tmp;			_Tmp->_Prev = _Curr;			_Tmp->_Next = _Tail;			_Tail->_Prev = _Tmp;			_Curr = _Tmp;			}		}	str_pointer& begin()		{ 
		return this->_Head->_Next;		}	str_pointer& front()		{ 
		return this->_Head;		}	str_pointer& end()		{ 
		return this->_Tail->_Prev;		}	str_pointer& back()		{ 
		return this->_Tail;		}protected:		str_pointer _Head;	str_pointer _Curr;	str_pointer _Tail;	};TEMPLATE<CLST _adk_array> CLST/*	Caution : 	That For comparison is the front() and back(), and that for 	the assignment is begin() and end(). */	array		: public basic_array<_adk_array>, 		public iterator<_adk_list<_adk_array> >	{ 
	typedef _adk_list<_adk_array> _MyList;		typedef typename _MyList::value_type value_type;	typedef typename _MyList::pointer pointer;	typedef typename _MyList::str_pointer str_pointer;	typedef typename _MyList::reference reference;public:		void allocate(int size)		{ 
		for(int i = 0; i < size; i++)			{			str_pointer _Tmp = new _MyList;			_Curr->_Next = _Tmp;			_Tmp->_Prev = _Curr;			_Tmp->_Next = _Tail;			_Tail->_Prev = _Tmp;			_Curr = _Tmp;			}		_Ptr = _Head->_Next;		}	};TEMPLATE<CLST _adk_array> CLST/*	Caution : 	That For comparison is the front() and back(), and that for 	the assignment is begin() and end(). */	arrayex		: public array<_adk_array>	{ 
	typedef _adk_list<_adk_array> _MyList;		typedef typename _MyList::value_type value_type;	typedef typename _MyList::pointer pointer;	typedef typename _MyList::str_pointer str_pointer;	typedef typename _MyList::reference reference;public:		typedef _ADK iterator<_adk_list<_adk_array> > iterator;	typedef _ADK const_iterator<_adk_list<_adk_array> > const_iterator;	void push_back(_adk_array _data)		{ 
		str_pointer _Tmp = new _MyList;		_Tmp->_Data = _data;		_Curr->_Next = _Tmp;		_Tmp->_Prev = _Curr;		_Tmp->_Next = _Tail;		_Tail->_Prev = _Tmp;		_Curr = _Tmp;		_Ptr = _Head->_Next;		}	void push_front(_adk_array _data)		{ 
		str_pointer _HN = _Head->_Next;		str_pointer _Tmp = new _MyList;		_Tmp->_Data = _data;		_Head->_Next = _Tmp;		_Tmp->_Prev = _Head;		_Tmp->_Next = _HN;		_HN->_Prev = _Tmp;		_Ptr = _Head->_Next;		}	value_type pop_back()		{ 
		str_pointer _Del = _Tail->_Prev;		str_pointer _Prev = _Del->_Prev;		value_type ret = _Del->_Data;		_Prev->_Next = _Tail;		_Tail->_Prev = _Prev;		delete _Del;		_Ptr = _Head->_Next;		return ret;		}	value_type pop_front()		{ 
		str_pointer _Del = _Head->_Next;		value_type ret = _Del->_Data;		_Head->_Next = _Del->_Next;		_Del->_Next->_Prev = _Head;		delete _Del;		_Ptr = _Head->_Next;		return ret;		}	};		
TEMPLATE<CLST _Iter, 	CLST _Func> void 	for_each(_Iter _Left, _Iter _Right, _Func& _Func)	{ 
	for(; _Left != _Right; _Left++)		_Func(*_Left);	}		
TEMPLATE<CLST _Arr> void	_Fill(arrayex<_Arr>& _Left, _Arr _Right, int _Time)	{ 
	for(int i = 0; i < _Time; i++)		_Left.push_back(_Right);	}TEMPLATE<CLST _Iter> void	_Fill(_Iter _Left, _Iter _Right)	{ 
	for(; _Left != _Right; _Left++)		*_Left = (_Iter *)(0);	}TEMPLATE<CLST _Arr> void	_Fill(iterator<_Arr> _Left, iterator<_Arr> _Right, _Arr _Data)	{ 
	for(; _Left != _Right; _Left++)		*_Left = (_Data);	}TEMPLATE<CLST _Arr> void	_Fill(const_iterator<_Arr> _Left, 		const_iterator<_Arr> _Right, _Arr _Data)	{ 
	for(; _Left != _Right; _Left++)		*_Left = (_Data);	}		
TEMPLATE<CLST _Iter> int	_Distance(_Iter _Left, _Iter _Right)	{ 
	int i = 0;	for(; _Left != _Right; _Left++) 		i++;	return i;	}TEMPLATE<CLST _Ptr> _IN NONE_RET call(_Ptr& t)	{ 
	RETURN (t);	}TEMPLATE<CLST _Ptr> _IN _Ptr receive(_Ptr t) THROWX	{ 
	IF(call(t))		SWITCH_START(_Ptr)			return result;		SWITCH_END	END_IF	return t;	}TEMPLATE<CLST _Ptr> _IN _Ptr& receive(_Ptr& t) THROWX	{ 
	IF(call(t))		SWITCH_START(_Ptr&)			return result;		SWITCH_END	END_IF	return t;	}TEMPLATE<CLST _Ty> _IN	_Ty *_Address_of(_Ty& _Val)	{	
	return receive((reinterpret_cast<_Ty *>(		(&const_cast<char&>(		reinterpret_cast<const volatile char&>(_Val))))));	}TEMPLATE<CLST _Stru = char *,	int _MAX_STRU = 256> CLST	structure	{ 	typedef struct		{ 
			_Stru _Addr;			int hash_code, size;		} structure_app;	structure_app *_Addr;	int count;public:	explicit structure()		: count(0)		{ 
		_Addr = new structure_app[_MAX_STRU];		for(int i = 0; i < _MAX_STRU; i++)			_Addr[i]._Addr = 0;		}	_Stru operator[](const char * _Dest)		{ 
		int hf = make_hash(_Dest);		for(int i = 0; i < count; i++)			if(_Addr[i].hash_code == hf)				return _Addr[i]._Addr;		return 0;		}	int offset(const char * _Dest)		{ 
		int hf = make_hash(_Dest);		for(int i = 0, j = 0; i < count; i++)			if(_Addr[i].hash_code == hf)				return j - _Addr[i].size + 1;			else				j += _Addr[i].size;		return 0;		}	_Stru operator*()		{ 
		int j = 0;		for(int i = 0; i < count; i++)			j += _Addr[i].size;		if(!j)			return 0;		_Stru c_ret = new remove_pointer<_Stru>::type[j];		for(int i = 0, f = 0; i < count; f += _Addr[i++].size)			for(j = 0; j < _Addr[i].size; j++)				c_ret[f + j] = (_Addr[i]._Addr)[j];		return c_ret;		}	TEMPLATE<CLST _Ty> _IN		void operator()(const char * _Dest, const _Ty *_Ptr)		{ 
		_TADC(sizeof(_Ty));		}	_IN void operator()(const char * _Dest, const char *_Ptr)		{ 
		_TADC(sizeof(char) * strlen_c(_Ptr));		}private:	int strlen_c(const char *_Dest)		{ 
		const char *_ptr = _Dest;		while( *_ptr != 0 )			_ptr++;		return _ptr - _Dest - 1;		}	int make_hash(const char *key)		{ 
		int j = 0;		for(int i = 0; *key; key++)			j = (j << ((_MAX_STRU | 0x7A64) + i)) + *key;		return j;		}	};TEMPLATE<CLST _adk_char> CLST	basic_string	{ 
	typedef basic_string<_adk_char> _MyString;	typedef typename _adk_list<_adk_char>::value_type value_type;	typedef typename _adk_list<_adk_char>::const_pointer const_pointer;	typedef typename _adk_list<_adk_char>::pointer pointer;	typedef typename _adk_list<_adk_char>::reference reference;	arrayex<char> _string;public:		typedef typename arrayex<char>::iterator iterator;	typedef typename arrayex<char>::const_iterator const_iterator;	_MyString& operator+(const_pointer _str)		{ 
		for(; *_str; _str++)			_string.push_back(*_str);		return *this;		}	_MyString& operator+(_MyString& _str)		{ 
		for(const_iterator			_it = _str._string.begin(); 			_it != _str._string.back(); _it++)			_string.push_back(*_it);		return *this;		}	pointer operator*()		{ 
		iterator _it_L = _string.begin(), _it_R = _string.back();		int _len = _ADK _Distance(_it_L, _it_R), i;		pointer _Tmp = new value_type[_len + 1];		for(i = 0, _it_L = _string.begin(); 			i < _len + 1; i++, _it_L++)			_Tmp[i] = *_it_L;		_Tmp[_len + 1] = 0;		return _Tmp;		}	};		
TEMPLATE<CLST _Atm> int	_strchr(_In_ _Atm *left, _In_ _Atm right) 	{	
	const char * ptr = left;	FOR_ZERO(ptr)		if(*ptr == right)			return ptr - left + 1;	END_FOR	return 0;	}TEMPLATE<CLST _Atm> int	strchr_(_In_ _Atm *left, _In_ _Atm right) 	{	
	const char * ptr = left;	while(*ptr++)		;	FOR_LAST(ptr, ptr != left)		if(*ptr == right)			return ptr - left + 1;	END_FOR	return 0;	}TEMPLATE<CLST _Atm> _addr _Atm *	__strchr(_In_ _Atm *left, _In_ _Atm right) 	{	
	char * ptr = (char *)left;	FOR_ZERO(ptr)		if(*ptr == right)			return ptr;	END_FOR	return 0;	}TEMPLATE<CLST _Atm> _addr _Atm *	strchr__(_In_ _Atm *left, _In_ _Atm right) 	{	
	char * ptr = (char *)left;	while(*ptr++)		;	FOR_LAST(ptr, ptr != left)		if(*ptr == right)			return ptr;	END_FOR	return 0;	}		
TEMPLATE<CLST _Atm> _addr _Atm *	_strstr(_In_ _Atm *left, _In_ _Atm *right)	{	
	char * ptr = (char *)left;	char * s1, * s2;	FOR_ZERO(ptr)		s1 = ptr;		s2 = (char *)right;		while (*s1 && *s2 && !(*s1 - *s2))			s1++, s2++;		if (!*s2)			return (ptr);	END_FOR	return 0;	}TEMPLATE<CLST _Atm> _addr _Atm *	strstr_(_In_ _Atm *left, _In_ _Atm *right)	{	
	char * ptr = (char *)left;	char * s1, * s2;	while(*ptr++)		;	FOR_LAST(ptr, ptr != left)		s1 = ptr;		s2 = (char *)right;		while (*s1 && *s2 && !(*s1 - *s2))			s1++, s2++;		if (!*s2)			return (ptr);	END_FOR	return 0;	}TEMPLATE<CLST _Atm> _addr _Atm *	_m_d_strstr(_In_ _Atm *left, _In_ _Atm *right)	{	
	char * ptr = (char *)left;	char * s1, * s2;	FOR_ZERO(ptr)		s1 = ptr;		s2 = (char *)right;		while (*s1 && *s2 && !(*s1 - *s2))			s1++, s2++;		if (!*s2)			return (s1);	END_FOR	return 0;	}		
TEMPLATE<CLST _Atm> _addr _Atm *	_strspc(_In_ _Atm *left, _In_ _Atm middle1, _In_ _Atm middle2, _Out_ _Atm *right)	{	
	char * ptr = right;	char * s1, * s2;	if(!(s1 = __strchr( left, middle1 )))		right = 0;	if(!(s2 = strchr__( left, middle2 )))		right = 0;	for(s1 += 1; s1 != s2; s1++, ptr++)		*ptr = *s1;	return right;	}TEMPLATE<CLST _Atm> _addr _Atm *	_strspc(_In_ _Atm *left, _In_ _Atm *middle1, _In_ _Atm *middle2, _Out_ _Atm *right)	{	
	char * ptr = right;	char * s1, * s2;	if(!(s1 = _m_d_strstr( left, middle1 )))		right = 0;	if(!(s2 = strstr_( left, middle2 )))		right = 0;	for(; s1 != s2; s1++, ptr++)		*ptr = *s1;	return right;	}TEMPLATE<CLST _Atm> _addr _Atm *	strspc_(_In_ _Atm *left, _In_ _Atm middle1, _In_ _Atm middle2, _Out_ _Atm *right)	{	
	char * ptr = right;	char * s1, * s2;	if(!(s1 = __strchr( left, middle1 )))		right = 0;	if(!(s2 = __strchr( s1, middle2 )))		right = 0;	for(s1 += 1; s1 != s2; s1++, ptr++)		*ptr = *s1;	return right;	}TEMPLATE<CLST _Atm> _addr _Atm *	strspc_(_In_ _Atm *left, _In_ _Atm *middle1, _In_ _Atm *middle2, _Out_ _Atm *right)	{	
	char * ptr = right;	char * s1, * s2;	if(!(s1 = _m_d_strstr( left, middle1 )))		right = 0;	if(!(s2 = _strstr( s1, middle2 )))		right = 0;	for(; s1 != s2; s1++, ptr++)		*ptr = *s1;	return right;	}  /**   *  @brief /Bind iterator CLST to iterator CLST   *   *  @param _Left cl_iterator _Right cl_iterator   */   TEMPLATE<typename _Atm,	TEMPLATE<typename Actr> CLST iterator, typename... _Axt>      void bind(iterator<_Atm>& _Left,      iterator<_Atm>& _Right)      {   	   _Left += _Right;      }      TEMPLATE<typename _Atm,   	TEMPLATE<typename Actr> CLST iterator, typename... _Axt>   		auto bind(iterator<_Atm>& _Left,		iterator<_Atm>& _Right, _Axt... args)   		-> decltype(   			!_ADK getrvalue<iterator<_Atm>>()   		)	{   		bind(_Left, _Right);   		bind(_Left, args...);   		return _Left.operator!();   	}      TEMPLATE<typename _Atm,   		TEMPLATE<typename Actr> CLST iterator, typename... _Axt>   	auto bind(const iterator<_Atm>& _Left)   		-> decltype(   			!iterator<_Atm>()   		)	{   		return _Left.data;   	}  TEMPLATE<typename _Atm,   			TEMPLATE<typename Actr, typename iter =  		_ADK iterator<Actr>> CLST iterator, typename _Ltm, typename... _Axt>  	void bind(iterator<_Atm, _Ltm>& _Left,   		iterator<_Atm, _Ltm>& _Right)  	{  		_Left += _Right;  	}    TEMPLATE<typename _Atm,  			TEMPLATE<typename Actr, typename iter =  		_ADK iterator<Actr>> CLST iterator, typename _Ltm, typename... _Axt>  	auto bind(iterator<_Atm, _Ltm>& _Left,   		iterator<_Atm, _Ltm>& _Right, _Axt... args) 		-> decltype(			!_ADK getrvalue<iterator<_Atm, _Ltm>>()		)  	{  		bind(_Left, _Right);  		bind(_Left, args...);  		return _Left.operator!();  	}    TEMPLATE<typename _Atm,  			TEMPLATE<typename Actr, typename iter =  		_ADK iterator<Actr >> CLST iterator, typename _Ltm, typename... _Axt>  	auto bind(const iterator<_Atm, _Ltm>& _Left)   		-> decltype(			!iterator<_Atm, _Ltm>()		)  	{  		return _Left.data;  	}/***  @brief /Get the R-Value .using variable only**  @param t cast_type v variable*/TEMPLATE<CLST urv> 	urv&&getrvalue();TEMPLATE < CLST _StrWcx > INLINE int    _Length( const _StrWcx *sWcT )    { 
        const _StrWcx *sWcTK = sWcT;        for( ; *sWcTK; sWcTK++)            ;        return (sWcTK - sWcT - 1);    } TEMPLATE < CLST _StrWcx > INLINE void    _Copy( const _StrWcx *sWcT, _StrWcx*& sWcTX )    { 
        const _StrWcx *sWcTK = sWcT;        _StrWcx *t = sWcTX;        for( ; *sWcTK; sWcTK++, t++)            *t = *sWcTK;    } TEMPLATE < CLST _StrWcx > INLINE const _StrWcx *    _Catch( const _StrWcx *sWcT, const _StrWcx *sWcCT, int n )    { 
        const _StrWcx *sWcTK = sWcT, *sWcCTK = sWcCT, *sWc;        if(n == 0)            return sWcTK;        for(int i = 0; *sWcTK; sWcTK++)            if(*sWcTK == *sWcCT)            {                for( sWcCTK = sWcCT, sWc = sWcTK; ; sWcCTK++, sWc++)                    if(!*sWcCTK)                    {                        i++;                        if(i == n)                            break;                        break;                    }                    else if(*sWcCTK != *sWc || !*sWc)                        break;            }            else if(i == n)                break;        return (sWcTK + _Length(sWcCT));    } TEMPLATE < CLST _StrWcx > INLINE const _StrWcx *    _PutZero( const _StrWcx *sWcT, const _StrWcx *sWcJ)    { 
        const _StrWcx *sWcTK = sWcT, *sWcCTK = sWcJ, *sWc;        _StrWcx *Mem;        int f = 0;        for( ; ; sWcTK++, f++)            if(*sWcTK == *sWcJ)            {                for( sWcCTK = sWcJ, sWc = sWcTK; ; sWcCTK++, sWc++)                    if(!*sWcCTK)                        break;                    else if(*sWcCTK != *sWc || !*sWc)                        break;                if(!*sWcCTK)                    break;            }        Mem = new _StrWcx[_Length(sWcT) - f + 1];        _Copy(sWcT, Mem);        Mem[f] = 0;        return Mem;    } TEMPLATE < CLST _StrWcx > INLINE const _StrWcx *    _Split( const _StrWcx *sWcT, const _StrWcx *sWcCT, int n )    { 
        return _PutZero(_Catch(sWcT, sWcCT, n),             _Catch(sWcT, sWcCT, n + 1) - _Length(sWcCT) - 1);    }
/**************************************************												 **			RollRat Software Library			 **												 **	Copyright (c) rollrat. All rights reserved.  **_______________________________________________*//* *	The rollrat x_library *  Updated : 2013-05 *	http:
 *  Copyright (c) 2009-2013 by rollrat. All right reserved. *  For more information, refer to the documentation on the license.V0.1:0012****//* *	This item, is available free of charge. However, if you change  *	yourself, you can bring fatal consequences. This project is  *	based on the ethical issues of the information, and began to  *	improve the openness of the program. You can use anyone, but  *	please observe the clear copyright notice. When you beat this,  *	you can go into the legal action.V0.1_x_Library_btype*/	
TEMPLATE<CLST _Ty1> inline	void _swap(_Ty1& _Left, _Ty1& _Right)	{ 
	_Ty1 temp = _Left;	_Left = _Right;	_Right = temp;	}TEMPLATE<CLST _Ty1> inline	void _pswap(_Ty1& _Left, _Ty1& _Right)	{ 
	_Ty1 temp = _Left;	*_Left = *_Right;	*_Right = *temp;	}TEMPLATE<CLST _Ty1> inline	void _cswap(_Ty1& _Left, _Ty1& _Right)	{ 
	swap((swap(_Left, _Right), 		swap(_Left, _Right), _Left), _Right)	}TEMPLATE<CLST _Ty1, 	CLST _Ty2> inline	void _rswap(_Ty1& _Left, _Ty2& _Right)	{ 
	swap(_Left, reinterpret_cast<_Ty2> (_Right));	}	
TEMPLATE<CLST _Ty1> inline	void swap(_Ty1*& _Left, _Ty1*& _Right, int size)	{ 
	for(int i = 0; i <= size; i++)		_swap(_Left[i], _Right[i]);	}TEMPLATE<CLST _Ty1> inline	void pswap(_Ty1*& _Left, _Ty1*& _Right)	{ 
	_Ty1 temp = *_Left;	*_Left = *_Right;	*_Right = temp;	}TEMPLATE<CLST _Ty1> inline	void aswap(_Ty1*& _Left, _Ty1*& _Right, int that)	{ 
	swap(_Left[that], _Right[that]);	}TEMPLATE<CLST _Ty1> inline	void aswap(_Ty1*& _Left, int that, int thats)	{ 
	swap(_Left[that], _Left[thats]);	}	
TEMPLATE<CLST _Ty1> inline	void tswap(_Ty1**& _Left, int i, int j, int size)	{ 
	for(int f = 0; f <= size; f++)		swap(_Left[i][f], _Left[j][f]);	}TEMPLATE<CLST _Ty1> inline	void jswap(_Ty1**& _Left, _Ty1**& _Right, 		int size, int around)	{ 
	for(int f = 0; f <= size; f++)		swap(_Left[f][around], _Right[f][around]);	}TEMPLATE<CLST _Ty0>	struct _stack_nodes	{ 
	_Ty0 _DATA;	_stack_nodes *_NEXT;	_stack_nodes *_PREV;	};TEMPLATE<CLST _Ty0> inline	void __remove(_stack_nodes<_Ty0> 		*&_First, _stack_nodes<_Ty0> *&_Second)	{ 
		_stack_nodes<_Ty0> *first = _First->_NEXT->_NEXT;	for( ; first != _Second; first = first->_NEXT);		delete first->_PREV;	delete _First;	delete _Second;	}TEMPLATE<CLST _Stack_Element>	CLST tree_stack	{ 
	_stack_nodes<_Stack_Element> *_Head;	_stack_nodes<_Stack_Element> *_Lastest;	_stack_nodes<_Stack_Element> *_Tail;public:	explicit tree_stack()	{ 
	_Head = _New_Node();	_Tail = _New_Node();	_Head->_PREV = _Head;	_Head->_NEXT = _Tail;	_Tail->_PREV = _Head;	_Tail->_NEXT = _Tail;	_Head->_DATA = 0;	_Lastest = _Head;	}	virtual ~tree_stack()	{ 
	__remove(_Head, _Tail);	}	void push(_Stack_Element _left)	{ 
	_stack_nodes<_Stack_Element> *temp = _New_Node();	temp->_DATA = _left;	_Connects(_Lastest, temp, _Tail);	_Lastest = temp;	}	_Stack_Element& pop()	{ 
	_stack_nodes<_Stack_Element> *ptr = _Tail->_PREV;	_stack_nodes<_Stack_Element> *prev = _Tail->_PREV->_PREV;	_Stack_Element ret;	ret = ptr->_DATA;	delete ptr;	_Connect(prev, _Tail);	return ret;	}private:	inline void _Connect(		_stack_nodes<_Stack_Element> *_head,			_stack_nodes<_Stack_Element> *_tail)	{ 
	_head->_NEXT = _tail;	_tail->_PREV = _head;	}	inline void _Connects(	_stack_nodes<_Stack_Element> *_First,			_stack_nodes<_Stack_Element> *_Target,					_stack_nodes<_Stack_Element> *_Last)	{ 
	_First->_NEXT = _Target;	_Target->_PREV = _First;	_Target->_NEXT = _Last;	_Last->_PREV = _Target;	}	inline _stack_nodes<_Stack_Element> *_New_Node()	{ 
	_stack_nodes<_Stack_Element> *ptr = new  		_stack_nodes<_Stack_Element>;	return ptr;	}	};TEMPLATE<CLST _Ty2>	CLST leaf	{ 
public:	leaf *left, *right;	_Ty2 _data;	inline _Ty2& operator*()		{ return _data; }	};TEMPLATE<CLST _Ty2> inline	void swap_lr_l(leaf<_Ty2>*& _first)	{ 
	leaf<_Ty2> *right = _first->right;	_first->right = _first->left;	_first->left = right;	}TEMPLATE<CLST _Ty0> inline 	_Ty0 *new_leaf()	{ 
	_Ty0 *ptr = new _Ty0;	return ptr;	}	
TEMPLATE<CLST _Tree_Element>	CLST tree	{ 
	typedef leaf<_Tree_Element> _MyLeaf;	_MyLeaf *_Head;	tree_stack<_MyLeaf *> _Stack;public:	tree()		{ 
		_Head = new_leaf<_MyLeaf>();		suture(_Head);		_Head->_data = 0;		}	void left(_Tree_Element _datas)		{ 
		_MyLeaf *ptr = new_leaf<_MyLeaf>();		suture(ptr);		ptr->_data  = _datas;		_Head->left = ptr;		}	void right(_Tree_Element _datas)		{ 
		_MyLeaf *ptr = new_leaf<_MyLeaf>();		suture(ptr);		ptr->_data = _datas;		_Head->right = ptr;		}	_MyLeaf*& left()		{ return _Head->left; }	_MyLeaf*& right()		{ return _Head->right; }	void visit_left()		{ 
		_Stack.push(_Head);		_Head = _Head->left;		}	void visit_right()		{ 
		_Stack.push(_Head);		_Head = _Head->right;		}	_Tree_Element& operator*()		{ return (_Head->_data); }	_MyLeaf*& operator&()		{ return _Head; }	void leave()		{ _Head = _Stack.pop(); }private:	inline void suture(_MyLeaf *that)		{ 
		that->left = that;		that->right = that;		}	};	
TEMPLATE<CLST _Ty1> inline	void _tree_rotate_right(tree<_Ty1>& _first)	{ 
	leaf<_Ty1> *_head = &_first,	
		*_right = _first.right(),	
		*_left = _first.left();		
	_swap(_head->_data, _right->_data); 
	_swap(_head->_data, _left->_data); 
	}TEMPLATE<CLST _Ty1> inline	void _tree_rotate_left(tree<_Ty1>& _first)	{ 
	leaf<_Ty1> *_head = &_first,	
		*_right = _first.right(),	
		*_left = _first.left();		
	_swap(_head->_data, _left->_data); 
	_swap(_head->_data, _right->_data); 
	}	
TEMPLATE<CLST _Ty3> inline	void _tree_swap_sr_tr(tree<_Ty3>& _first)	{ 
	leaf<_Ty3> *_l = _first.left()->right,			*_r = _first.right();	_swap(_r->_data, _l->_data);	}TEMPLATE<CLST _Ty3> inline	void _tree_swap_sl_tl(tree<_Ty3>& _first)	{ 
	leaf<_Ty3> *_l = _first.right()->left,			*_r = _first.left();	_swap(_r->_data, _l->_data);	}TEMPLATE<CLST _Ty3> inline	void _tree_swap_ftl_str(tree<_Ty3>& _first)	{ 
	leaf<_Ty3> *_l = _first.left()->right,			*_r = _first.right()->left;	_swap(_r->_data, _l->_data);	}TEMPLATE<CLST _Ty3> inline	void _tree_swap_ftr_stl(tree<_Ty3>& _first)	{ 
	leaf<_Ty3> *_l = _first.left()->left,			*_r = _first.right()->right;	_swap(_r->_data, _l->_data);	}TEMPLATE<CLST _Ty3> inline	void _tree_swap_ftl_stl(tree<_Ty3>& _first)	{ 
	leaf<_Ty3> *_l = _first.left()->left,			*_r = _first.right()->left;	_swap(_r->_data, _l->_data);	}TEMPLATE<CLST _Ty3> inline	void _tree_swap_ftr_str(tree<_Ty3>& _first)	{ 
	leaf<_Ty3> *_l = _first.left()->right,			*_r = _first.right()->right;	_swap(_r->_data, _l->_data);	}TEMPLATE<CLST _Ty3> inline	void _tree_swap(tree<_Ty3>& _first)	{ 
	leaf<_Ty3> *_l = _first.left(),			*_r = _first.right();	_swap(_r->_data, _l->_data);	}TEMPLATE<CLST _Ty3> inline	void _tree_swap_s_tr(tree<_Ty3>& _first)	{ 
	leaf<_Ty3> *_rl = _first.right()->left,			*_rr = _first.right()->right;	_swap(_first.left()->_data, _rl->_data);	_swap(_first.right()->_data, _rr->_data);	}TEMPLATE<CLST _Ty3> inline	void _tree_swap_s_tl(tree<_Ty3>& _first)	{ 
	leaf<_Ty3> *_rl = _first.left()->left,			*_rr = _first.left()->right;	_swap(_first.left()->_data, _rl->_data);	_swap(_first.right()->_data, _rr->_data);	}namespace _vector_operation{	_VECTOR_ELEMENT_OPERATION(_Ty0)		struct _VECTOR_NODES		{ 
		_Ty0 _DATA;		_VECTOR_NODES *_NEXT;		_VECTOR_NODES *_PREV;		};}_VECTOR_OPERATOR_ITERS(__Ty1)	_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 		operator<<(_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 			*&_First, __Ty1 _Last)	{ 
	for( ; _First != _First->_NEXT; )		if(_First->_DATA == _Last)			return _First;		else			_First = _First->_NEXT;	return _First;	}_VECTOR_OPERATOR_ITERS(__Ty1)	_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 		operator>>(_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 			*&_First, __Ty1 _Last)	{ 
	for( ; _First != _First->_PREV; )		if(_First->_DATA == _Last)			return _First;		else			_First = _First->_PREV;	return _First;	}TEMPLATE<CLST _Ty0> inline	void _vector_move_forward(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, int _Last = 0)	{ 
	if(!_Last)		for( ; _First != _First->_NEXT; )			_First = _First->_NEXT;	else		for(int _TMP = 0; _TMP <= _Last &&			_First != _First->_NEXT; )			_First = _First->_NEXT;	}TEMPLATE<CLST _Ty0> inline	void _vector_move_back(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, int _Last = 0)	{ 
	if(!_Last)		for( ; _First != _First->_PREV; )			_First = _First->_PREV;	else		for(int _TMP = 0; _TMP <= _Last &&			_First != _First->_PREV; )			_First = _First->_PREV;	}TEMPLATE<CLST _Ty0, 		typename _Fn0> inline	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		_vector_move_that_forward(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>		*&_First, _Ty0 _Last)	{ 
	for( ; _First != _First->_NEXT; )		if(_Fn0(_First->_DATA) == _Last)			return _First;		else			_First = _First->_NEXT;	}TEMPLATE<CLST _Ty0, 		typename _Fn0> inline	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		_vector_move_that_back(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>		*&_First, _Ty0 _Last)	{ 
	for( ; _First != _First->_PREV; )		if(_Fn0(_First->_DATA) == _Last)			return _First;		else			_First = _First->_PREV;	}namespace _vector_swap_{	TEMPLATE<typename unchecked_type> inline		void _swap(unchecked_type& _Left, unchecked_type& _Right)		{ 
		unchecked_type t = _Left; 		_Left = _Right; 		_Right = t;		}}TEMPLATE<CLST _Ty0> inline	void _vector_swap(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)	{ 
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *_TMP = _Second;	_Second->_NEXT = _First->_NEXT;	_Second->_PREV = _First->_PREV;	_VECTOR_SWAP _swap<_Ty0> (_First->_DATA, _Second->_DATA);	_First->_NEXT = _TMP->_NEXT;	_First->_PREV = _TMP->_PREV;	}TEMPLATE<CLST _Ty0> inline	void _vector_dswap(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)	{ 
	_VECTOR_SWAP _swap<_Ty0> (_First->_DATA, _Second->_DATA);	}namespace _vector_alloc{	TEMPLATE<typename unchecked_type> inline		_VECTOR_OPERATION 			_VECTOR_NODES<unchecked_type> *_alloc()		{ 
		_VECTOR_OPERATION 			_VECTOR_NODES<unchecked_type> *ptr = new _VECTOR_OPERATION 				_VECTOR_NODES<unchecked_type>;		return ptr;		}}TEMPLATE<CLST _Ty0> inline	void _vector_transfer(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)	{ 
	_First->_NEXT = _Second->_NEXT;	_First->_DATA = _Second->_DATA;	_First->_PREV = _Second->_PREV;	}TEMPLATE<CLST _Ty0> inline	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*_vector_move(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>			*&_First)	{ 
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*_Temp = _VECTOR_ALLOC _alloc();	_vector_transfer(_Temp, _First);	return _Temp;	}namespace _vector_reverse{	TEMPLATE<CLST _Ty0> inline		void _reverse(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 			*&_Head)	{ 
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *prev = 0;	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *curr = _Head;	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *next;    while (curr != curr->_NEXT)		{        next = curr->_NEXT;        curr->_NEXT = prev;        prev = curr;        curr = next;		}    _Head = prev;	}}TEMPLATE<CLST _Ty0> inline	void _vector_homo(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)	{ 
	_First->_NEXT = _Second;	_Second->_PREV = _First;	}TEMPLATE<CLST _Ty0> inline	void _vector_hetero(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second,			 _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Last)	{ 
	_First->_NEXT = _Second;	_Second->_PREV = _First;	_Second->_NEXT = _Last;	_Last->_PREV = _Second;	}TEMPLATE<CLST _Ty0> inline	void _vector_qsort(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)	{ 
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *set;	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *curr;	if (_First == _Second) 		return;	set = _First;	curr = set->_NEXT;	while (1)		{		if (set->_DATA < curr->_DATA)			_vector_dswap(set, curr);		if (curr == _Second) 			break;		curr = curr->_NEXT;		}	_vector_dswap(_First, curr);	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *currs = curr;	curr = curr->_PREV;	if (curr != 0)		if ((_First->_PREV != curr) && (curr->_NEXT != _First))			_vector_qsort(_First, curr);	curr = currs;	curr = curr->_NEXT;	if (curr != 0)		if ((curr->_PREV != _Second) && (_Second->_NEXT != curr))			_vector_qsort(curr, _Second);	}TEMPLATE<CLST _Ty0> inline	int _vector_value(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)	{ 
	int i = 0;	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *_TMP = _First;	for(; _TMP != _Second; i++, _TMP = _TMP->_NEXT);	return i + 1;	}TEMPLATE<CLST _Ty0> inline	void _vector_sort(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)	{ 
	int size = _vector_value(_First, _Second);	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *_TMP = _First;	for(int n = 0; n <= size; n++)		{		for( ; _TMP != _Second; _TMP = _TMP->_NEXT)			if(_TMP->_DATA > _TMP->_NEXT->_DATA)				_vector_dswap(_TMP, _TMP->_NEXT);		_TMP = _First;		}	}TEMPLATE<CLST _Ty0> inline	void _vector_remove(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)	{ 
	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *first = _First->_NEXT->_NEXT;	for( ; first != _Second; first = first->_NEXT);		delete first->_PREV;	delete _First;	delete _Second;	}TEMPLATE<CLST _Ty0> inline	void _vector_copy(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second,			_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 				*&_Third, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Last)	{ 
	}namespace _vector_operation{	namespace _vector_iterator	{		_VECTOR_OPERATOR_ITERS(__Ty2)			CLST _vector_iterator_dis_const			{				typedef typename _X_LIB __type<__Ty2>::value_type 					iterator_vector_type;				typedef typename _X_LIB __type<typename 						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::pointer					iterator_vector_type_disconst;				typedef typename _X_LIB __type<typename 						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::value_type					iterator_vector_disconst;				iterator_vector_disconst *__vector__temporary;			public:				_vector_iterator_dis_const()					:					{ }				_vector_iterator_dis_const(iterator_vector_disconst _First)					: __vector__temporary(_First)					{ }				_Force operator=(iterator_vector_disconst *_First)					{ 
					__vector__temporary = _First;					}				__Force __Ty2& operator*()					{ 
					return __vector__temporary->_DATA;					}				_Hence operator++(int)					{ 
					__vector__temporary = __vector__temporary->_NEXT;					return __vector__temporary != __vector__temporary->_NEXT;					}				_Hence operator--(int)					{ 
					__vector__temporary = __vector__temporary->_PREV;					return __vector__temporary != __vector__temporary->_PREV;					}				_VECTOR_OPEARTOR_ITERATOR_DISCONST_CONST_OPEARTION					(__vector__temporary, iterator_vector_disconst, __Ty2, )			};		_VECTOR_OPERATOR_ITERS(__Ty2)			CLST _vector_iterator_const			{				typedef typename _X_LIB __type<__Ty2>::value_type 					iterator_vector_type;				typedef typename _X_LIB __type<typename 						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::pointer					iterator_vector_type_const;				typedef typename _X_LIB __type<typename 						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::value_type					iterator_vector_const;				iterator_vector_const *__vector__temporary;			public:				_vector_iterator_const()					:					{ }				_vector_iterator_const(iterator_vector_const _First)					: __vector__temporary(_First)					{ }				_Force operator=(iterator_vector_const *_First)					{ 
					__vector__temporary = _First;					}				__Force __Ty2 operator*() const					{ 
					return __vector__temporary->_DATA;					}				_Hence operator++(int)					{ 
					__vector__temporary = __vector__temporary->_NEXT;					return __vector__temporary != __vector__temporary->_NEXT;					}				_Hence operator--(int)					{ 
					__vector__temporary = __vector__temporary->_PREV;					return __vector__temporary != __vector__temporary->_PREV;					}				_VECTOR_OPEARTOR_ITERATOR_DISCONST_CONST_OPEARTION					(__vector__temporary, iterator_vector_const, __Ty2, const)			};	}}		
TEMPLATE<CLST _Vector_Element>	CLST vector	{ 
	_VECTOR_OPERATION 		_VECTOR_NODES<_Vector_Element> *_Head;	_VECTOR_OPERATION 		_VECTOR_NODES<_Vector_Element> *_Lastest;	_VECTOR_OPERATION 		_VECTOR_NODES<_Vector_Element> *_Tail;	int _Pointer, _Back_PP, _size;	bool vlock;	public:	typedef typename _VECTOR_OPERATION _VECTOR_ITERATION 		_vector_iterator_const<_Vector_Element>		const_iterator;	typedef typename _VECTOR_OPERATION _VECTOR_ITERATION 		_vector_iterator_dis_const<_Vector_Element>		iterator;	explicit vector()		: _Back_PP(0), _Pointer(0), _size(0)		{ 
			_Head = _New_Node();			_Tail = _New_Node();			_Head->_PREV = _Head;			_Head->_NEXT = _Tail;			_Tail->_PREV = _Head;			_Tail->_NEXT = _Tail;			vlock = true;		}	virtual ~vector()		{ 
		_vector_remove(_Head, _Tail);		}	private: __Force void _Vector_Nodes_Connects(_VECTOR_OPERATION 				 _VECTOR_NODES<_Vector_Element> *_First,					_VECTOR_OPERATION 						_VECTOR_NODES<_Vector_Element> *_Target,							_VECTOR_OPERATION								_VECTOR_NODES<_Vector_Element> *_Last)			{ 
				_First->_NEXT = _Target;				_Target->_PREV = _First;				_Target->_NEXT = _Last;				_Last->_PREV = _Target;			}	public:		__Force _VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *&begin()			{ 
				return _Head->_NEXT;			}		__Force _VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *&end()			{ 
				return _Tail;			}	private: __Force _VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *_New_Node()		{ 
		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *ptr = new _VECTOR_OPERATION 				_VECTOR_NODES<_Vector_Element>;		return ptr;		}	public:		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *&operator[](int _First)		{ 
		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *_Temp = _Head;		for( int Fn_n = 0; 				Fn_n <= _First; Fn_n++)			_Temp = _Temp->_NEXT;		return _Temp;		}		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *&operator()(int _First)		{ 
		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *_Temp = _Tail;		for( int Fn_n = 0; 				Fn_n <= _First; Fn_n++)			_Temp = _Temp->_PREV;		return _Temp;		}		void push_back(_Vector_Element _left)		{ 
		if(vlock){		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *temp = _New_Node();		temp->_DATA = _left;		if (_Back_PP)			_Vector_Nodes_Connects(_Lastest, temp, _Tail);		else			_Vector_Nodes_Connects(_Head, temp, _Tail);		_Lastest = temp;		_Back_PP++;		_size++;		}		}		void push_front(_Vector_Element _left)		{ 
		if(vlock){		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *temp = _New_Node();		temp->_DATA = _left;		_Vector_Nodes_Connects(_Head, temp, _Head->_NEXT);		_Lastest = temp;		_Back_PP++;		_size++;		}		}		_Vector_Element pop_back()		{ 
		if(vlock){		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *ptr = _Head;		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *prev = _Head;		_Vector_Element ret;		for(int f = -1; ; f++)			{			if(ptr == _Tail->_PREV)				break;			if(f >= 0)				prev = prev->_NEXT;			ptr = ptr->_NEXT;			}		ret = ptr->_DATA;		delete ptr;		_Connect(prev, _Tail);		_Back_PP--;		_size--;		return ret;		}		}		_Vector_Element pop_front()		{ 
		if(vlock){		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;		_Vector_Element ret = ptr->_DATA;		_Connect(_Head, ptr->_NEXT);		delete ptr;		_Back_PP--;		_size--;		return ret;		}		}		_Force remove()		{ 
		if(vlock){		_vector_remove(_Head, _Tail);		}		}	private: _Force _Connect(_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *_head, _VECTOR_OPERATION 				_VECTOR_NODES<_Vector_Element> *_tail)		{ 
		_head->_NEXT = _tail;		_tail->_PREV = _head;		}	public:		_Force reserve(int _First)		{ 
		if(vlock){		for(int i = 0; i <= _First; i++)			push_back(0);		}		}		__Force int size() const		{ 
		return _size;		}		void insert(_Vector_Element _First, int _Pos)		{ 
		if(vlock){		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *ptr_next;		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *temps = _New_Node();		for( int Fn_n = 0; 				Fn_n <= _Pos; Fn_n++)			ptr = ptr->_NEXT;		ptr_next = ptr->_NEXT;		ptr->_NEXT = temps;		temps->_NEXT = ptr_next;		ptr_next->_PREV = temps;		temps->_DATA = _First;		}		}		void erase(int _Pos)		{ 
		if(vlock){		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *ptr_next;		for( int Fn_n = 0; 				Fn_n <= _Pos; Fn_n++)			ptr = ptr->_NEXT;		ptr->_PREV->_NEXT = ptr->_NEXT;		ptr->_NEXT->_PREV = ptr->_PREV;		delete ptr;		}		}		__Force _VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *&front()		{ 
		return _Head->_NEXT;		}		__Force _VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *&back()		{ 
		return _Tail->_PREV;		}		_Force fill(_Vector_Element _Elem)		{ 
		if(vlock){		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;		for( ; ptr != _Tail; )			ptr->_DATA = _Elem, ptr = ptr->_NEXT;		}		}		_Force assign(_Vector_Element _First, int _Last)		{ 
		if(vlock){		for(int i = 0; i <= _Last; i++)			push_back(_First);}		}		_Force asign(_Vector_Element _First, int _LPos, int _RPos)		{ 
		if(vlock){		_VECTOR_OPERATION 			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;		for(int f = 0; f <= _LPos; f++)			ptr = ptr->_NEXT;		for(int i = _LPos; i <= _RPos; i++)			ptr->_DATA = _First, ptr = ptr->_NEXT;}		}		_Force reverse()		{ 
		if(vlock)		_VECTOR_REVERSE _reverse(_Head);		}		_Force sort()		{ 
		if(vlock)		_vector_sort(front(), back());		}		_Force lock()		{ 
		vlock = false;		}		_Force unlock()		{ 
		vlock = true;		}	};TEMPLATE<CLST _Ty0> inline	int _vector_first_match(vector<_Ty0> *&_First, 		_Ty0 &_Last)	{ 
	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *ptr = _First->front();	for(int i = 0 ; ptr != _First->_Tail; 			ptr = ptr->_NEXT, i++)		if(ptr->_DATA == _Last)			return i;	}TEMPLATE<CLST _Ty0> inline	int _vector_perfect_match(vector<_Ty0> *&_First, 		vector<_Ty0> *&_Last)	{ 
	if(_First->size() < _Last->size())		return -1;	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *first_next = _First->front();	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *last_next = _Last->front();	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *first_temp = 0;	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *last_temp = 0;	int flen = _First->size(), llen = _Last->size();	for(int i = 0; i <= flen; i++, first_next = first_next->_NEXT)		if(first_next->_DATA == last_next->_DATA){			first_temp = first_next, last_temp = last_next;			for(int n = 0; n <= llen; n++, last_next = last_next->_NEXT, 					first_next = first_next->_NEXT)				if(last_next->_DATA != first_next->_DATA)					first_next = first_temp, last_next = last_temp, 					break;				else if(n == llen)					return i;}	}TEMPLATE<CLST _Ty0> inline	int _vector_times_match(vector<_Ty0> *&_First, 		_Ty0 &_Last, int times = 1)	{ 
	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *ptr = _First->front();	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *ptrs = 0;	for(int i = 0 ; ptr != _First->_Tail; 			ptr = ptr->_NEXT, i++)		if(ptr->_DATA == _Last){			ptrs = ptr;			for(int f = 1; f <= times; 				ptr = ptr->_NEXT, f++)				if(ptr->_DATA == _Last)					return i;			ptr = ptrs;}	}TEMPLATE<CLST _Ty0> inline	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *& 		_vector_disconnect_and_connect(_VECTOR_OPERATION 			_VECTOR_NODES<_Ty0> *&_First, _VECTOR_OPERATION 				_VECTOR_NODES<_Ty0> *&_Second, _VECTOR_OPERATION 					_VECTOR_NODES<_Ty0> *&_Third, _VECTOR_OPERATION 						_VECTOR_NODES<_Ty0> *&_Last)	{ 
	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *first_next = _First->_NEXT;	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *last_prev = _Last->_PREV;	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *gd = _VECTOR_ALLOC _alloc();	_First->_NEXT = _Second;	_Second->_PREV = _First;	_Third->_NEXT = _Last;	_Last->_PREV = _Third;	gd->_NEXT = first_next;	gd->_PREV = last_prev;	return gd;	}TEMPLATE<CLST _Ty0> inline	int _vector_element_count(_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *&_First, _Ty0 _Second)	{ 
	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *first_next = _First;	int let = 0;	for( ; first_next != 		first_next->_NEXT; first_next = first_next->_NEXT)			if(first_next->_DATA == _Second)				let++;	return let;	}		
TEMPLATE<CLST _Stack_Element>	CLST stack	{ 
	_VECTOR_OPERATION 		_VECTOR_NODES<_Stack_Element> *_Head;	_VECTOR_OPERATION 		_VECTOR_NODES<_Stack_Element> *_Lastest;	_VECTOR_OPERATION 		_VECTOR_NODES<_Stack_Element> *_Tail;		public:		explicit stack()		{ 
		_Head = _New_Node();		_Tail = _New_Node();		_Head->_PREV = _Head;		_Head->_NEXT = _Tail;		_Tail->_PREV = _Head;		_Tail->_NEXT = _Tail;		_Head->_DATA = 0;		_Lastest = _Head;		}		virtual ~stack()		{ 
		_vector_remove(_Head, _Tail);		}		void push(_Stack_Element _left)		{ 
		_VECTOR_OPERATION 			_VECTOR_NODES<_Stack_Element> *temp = _New_Node();		temp->_DATA = _left;		_Vector_Nodes_Connects(_Lastest, temp, _Tail);		_Lastest = temp;		}		_Stack_Element pop()		{ 
		_VECTOR_OPERATION 			_VECTOR_NODES<_Stack_Element> *ptr = _Head;		_VECTOR_OPERATION 			_VECTOR_NODES<_Stack_Element> *prev = _Head;		_Stack_Element ret;		for(int f = -1; ; f++)			{			if(ptr == _Tail->_PREV)				break;			if(f >= 0)				prev = prev->_NEXT;			ptr = ptr->_NEXT;			}		ret = ptr->_DATA;		delete ptr;		_Connect(prev, _Tail);		return ret;		}	private:		_Force _Connect(_VECTOR_OPERATION 			_VECTOR_NODES<_Stack_Element> *_head, _VECTOR_OPERATION 				_VECTOR_NODES<_Stack_Element> *_tail)		{ 
		_head->_NEXT = _tail;		_tail->_PREV = _head;		}		__Force void _Vector_Nodes_Connects(_VECTOR_OPERATION 		 _VECTOR_NODES<_Stack_Element> *_First,			_VECTOR_OPERATION 				_VECTOR_NODES<_Stack_Element> *_Target,					_VECTOR_OPERATION						_VECTOR_NODES<_Stack_Element> *_Last)		{ 
		_First->_NEXT = _Target;		_Target->_PREV = _First;		_Target->_NEXT = _Last;		_Last->_PREV = _Target;		}		__Force _VECTOR_OPERATION 			_VECTOR_NODES<_Stack_Element> *_New_Node()		{ 
		_VECTOR_OPERATION 			_VECTOR_NODES<_Stack_Element> *ptr = new _VECTOR_OPERATION 				_VECTOR_NODES<_Stack_Element>;		return ptr;		}	};	
TEMPLATE<CLST _Ty0> inline	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0>*& _vector_nondisjunction(_VECTOR_OPERATION 			_VECTOR_NODES<_Ty0> *&_First)	{ 
	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *_next = _First->_NEXT;	_First->_NEXT = _First->_PREV;	_First->_PREV = _next;	return _next;	}TEMPLATE<CLST _Ty0> inline	void _vector_translocation(_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *&_First, _VECTOR_OPERATION 			_VECTOR_NODES<_Ty0> *&_Last, bool dataion = 0)	{ 
	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *_next = _First->_NEXT;	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0> *_prev = _First->_PREV;	_First->_NEXT = _Last->_NEXT;	_First->_PREV = _Last->_PREV;	_Last->_NEXT = _next;	_Last->_PREV = _prev;	if(!dataion)		_vector_dswap(_First, _Last);	}TEMPLATE<CLST _Ty0> inline	_VECTOR_OPERATION 		_VECTOR_NODES<_Ty0>*& _vector_deletion(_VECTOR_OPERATION 			_VECTOR_NODES<_Ty0> *&_First, _VECTOR_OPERATION 				_VECTOR_NODES<_Ty0> *&_Second, _VECTOR_OPERATION 					_VECTOR_NODES<_Ty0> *&_Last, bool deletes = 0)	{ 
	_First->_NEXT = _Last;	_Second->_NEXT = _Second;	_Second->_PREV = _Second;	_Last->_PREV = _First;	if(deletes)		delete _Second;	return _Second;	}	
TEMPLATE<CLST _Ty3> inline	void _vector_replace(vector<_Ty3>& _First,  		vector<_Ty3>& _Second,			vector<_Ty3>& _Last)	{ 
	_VECTOR_OPERATION _VECTOR_NODES<_Ty3>		*_f_n = _First.front(), *f_n_b,		*_f_p = _First.back(),		*_s_n = _Second.front(), *s_n_b,		*_s_p = _Second.back(),		*_l_n = _Last.front(),		*_l_p = _Last.back();	for( ; _f_n != _f_p; _f_n = _f_n->_NEXT)		if(_f_n->_DATA == _s_n->_DATA)			for(s_n_b = _s_n, f_n_b = _f_n				; _s_n->_DATA == _f_n->_DATA; _s_n = 				_s_n->_NEXT, _f_n = _f_n->_NEXT)				if(_f_n->_DATA != _s_n->_DATA){					_f_n = f_n_b, _s_n = s_n_b;break;}				else if (_s_n == _s_p->_PREV){					f_n_b->_PREV->_NEXT = _l_n, 					_l_p->_NEXT = _f_n;					return;}	}TEMPLATE<CLST _Ty3> inline	void _vector_replace2(vector<_Ty3>& _First,  		vector<_Ty3>& _Second,			vector<_Ty3>& _Last)	{ 
	_VECTOR_OPERATION _VECTOR_NODES<_Ty3>		*_f_n = _First.front(), *f_n_b,		*_f_p = _First.back(),		*_s_n = _Second.front(), *s_n_b,		*_s_p = _Second.back(),		*_l_n = _Last.front(),		*_l_p = _Last.back();	for( ; _f_n != _f_p; _f_n = _f_n->_NEXT)		if(_f_n->_DATA == _s_n->_DATA)			for(f_n_b = _f_n, s_n_b = _s_n;				_s_n != _s_p;				_f_n = _f_n->_NEXT, _s_n = _s_n->_NEXT)				if(_s_n->_DATA != _f_n->_DATA){					_s_n = s_n_b;_f_n = f_n_b;break;}				else if(_s_n == _s_p->_PREV){					f_n_b->_PREV->_NEXT = _l_n;					_l_p->_NEXT = _f_n;					return;}	}TEMPLATE<CLST _Pt>	_Pt* virtual_alloc(int _Val)	{ 
	void *_Ptr = 0;	if (_Val)		_Ptr = ::operator new(_Val * sizeof(_Pt));	return ((_Pt *)_Ptr);	}CLST _error	{ 
	char *_Msg;public:	explicit _error(const char *_lst = 0)		{ 
		_Msg = const_cast<char *> (_lst);		}	void show(char * = 0)		{ 
		call();		}private:	void call()		{ 
		show(_Msg);		}	};TEMPLATE<CLST _Ty0> inline	int pointer_len(_Ty0 *that)	{ 
	_Ty0 *pp = that;	while(*pp++);	return pp - that - 1;	}TEMPLATE<CLST _Ty2> inline	_Ty2& fast_cast(const _Ty2 _lest)	{ 
	_Ty2 _PtrEx = virtual_alloc<typename 		remove_pointer<_Ty2>::type> 			(sizeof(_lest) / sizeof(typename 				remove_pointer<_Ty2>::type));	for(int i = sizeof(_lest) / sizeof(typename 		remove_pointer<_Ty2>::type), f = 0; 			i >= f; f++)				_PtrEx[f] = _lest[f];	return _PtrEx;	}TEMPLATE<CLST _Ty0> inline	void pointer_back(_Ty0 *that)	{ 
	while(*that++);	}TEMPLATE<CLST _Ty0> inline	void pointer_front(_Ty0 *that)	{ 
	while(*that--);	}TEMPLATE<CLST _Ty0>	CLST const_alloc	{ 
	mutable _Ty0 *pointer;	int point, size;public:	explicit const_alloc(_Ty0 *pointer)		: pointer(pointer), point(0)		{ 
		size = pointer_len(pointer);		}	bool operator++(int)		{ 
		if(point == size)			return false;		point++, return true;		}	bool operator--(int)		{ 
		if(!point)			return false;		point--, return true;		}	bool operator+(int _left)		{ 
		if((point + _left) > size)			return false;		point += _left, return true;		}	bool operator-(int _left)		{ 
		if((point - _left) < 0)			return false;		point -= _left, return true;		}	_Ty0& operator*()		{ 
		return pointer[point];		}	_Ty0& operator()(int _right)		{ 
		return pointer[size - _right];		}	_Ty0& operator[](int _right)		{ 
		return pointer[_right];		}	};TEMPLATE<CLST _Ty1> inline	_Ty1* _Allocate(size_t _Val, _Ty1 *)	{ 
	void *_Ptr = 0;	if (_Val)		_Ptr = ::operator new(_Val * sizeof(_Ty1));	return ((_Ty1 *)_Ptr);	}TEMPLATE<CLST _Ty1> inline	_Ty1* _Allocate(size_t _Val)	{ 
	void *_Ptr = 0;	if (_Val)		_Ptr = ::operator new(_Val * sizeof(_Ty1));	return ((_Ty1 *)_Ptr);	}TEMPLATE<CLST _Ty1> inline	void _Construct(_Ty1 *_xPtr)	{ 
	void *_Ptr = _xPtr;	_xPtr = new _Ty1(0);	}TEMPLATE<CLST _Ty1> inline	void _Delete(_Ty1 _First)	{ 
	delete _First;	}TEMPLATE<CLST _Ty1> inline	void _Delete(_Ty1 *_First)	{ 
	delete[] _First;	}TEMPLATE<CLST _Ty1, 	CLST _TySize> inline	void _Delete(_Ty1 *_First, _TySize _Second)	{ 
	for(int i = 0; i <= _Second; i++)		_Delete(_First[i]);	_Delete(_First);	}TEMPLATE<CLST _Ty1, 	CLST _TySize> inline	void _Realloc_n(_Ty1 *_First, 		_TySize _Second, _TySize _Third)	{ 
	_Ty1 *buf = _Allocate<_Ty1> (_Third);	for(_TySize n = 0; n <= _Second;n++)		buf[n] = _First[n];	return buf;	}TEMPLATE<CLST _Ty1> inline	void _Swap(_Ty1 &_Left, _Ty1 &_Right)	{ 
	_Ty1 t = _Left; 	_Left = _Right; 	_Right = _Left;	}TEMPLATE<CLST _Ty1,	CLST _TySize> inline	void _Swap(_Ty1* _Left, _TySize f)	{ 
	_Ty1 _buf;	_buf = *_Left;	*_Left = _Left[f];	_Left[f] = _buf;	}TEMPLATE<CLST _Ty1,	CLST _TySize> inline	void _Swap(_Ty1 *_Left, 		_TySize i, _TySize f)	{ 
	_Ty1 _buf;	_buf = _Left[i];	_Left[i] = _Left[f];	_Left[f] = _buf;	}TEMPLATE<CLST _Ty1, 	CLST _TySize> inline	void _Fill_n(_Ty1 *_Left, 		_TySize _LSize, _Ty1 _Elem = 0)	{ 
	for(_TySize n = 0; n <= _LSize;n++)		_Left[n] = _Elem;	}TEMPLATE<CLST _Ty1,	CLST _Ty2,	CLST _TySize> inline	void _Copy_n(const _Ty1 _Left, 		_Ty2 &_Right, _TySize _LSize)	{ 
	for(_TySize i = 0; i <= _LSize; i++)		_Right[i] = _Left[i];	};TEMPLATE<CLST _Ty1,	CLST _TySize> inline	_Ty1* _Copy_n(const _Ty1 *_Left, _TySize _LSize)	{ 
	_Ty1 *_Ptr = _Allocate<_Ty1> (_LSize);	_Copy_n(_Left, _Ptr, _LSize);	return _Ptr;	};TEMPLATE<CLST _Ty1A> INLINE	void _ptr_last(_Ty1A *_Ptr)	{ 
	while(*_Ptr++)			;	}TEMPLATE<CLST _Ty1A> INLINE	int _ptr_last_i(_Ty1A *_Ptr)	{ 
	int i = 0;	for( ; *_Ptr; _Ptr++, i++)		;	return i;	}TEMPLATE<CLST _Ty2A> INLINE	_Ty2A _ptr_length(const _Ty2A *_Left, _Ty2A _Hide_Right = 255)	{ 
	const _Ty2A *_Ptr = _Left;	_Ty2A n;	for(n = 0; n < _Hide_Right && *_Ptr; _Ptr++, n++)		; 
	return ((int)_Ptr - (int)_Left - 1); 
	}TEMPLATE<CLST _Ty5A> INLINE	_Ty5A _ptr_next(_Ty5A *_Ptr)	{ 
	return *(_Ty5A *)(AddressOf(*_Ptr) + sizeof(_Ty5A));	}TEMPLATE<CLST _Ty5A> INLINE	_Ty5A _ptr_prev(_Ty5A *_Ptr)	{ 
	return *(_Ty5A *)(AddressOf(*_Ptr) - sizeof(_Ty5A));	}TEMPLATE<CLST _Ty1A> INLINE	_Ty1A **_ptr_spect(_Ty1A *_Ptr)	{ 
	return (_Ty1A **)*(AddressOf(*_Ptr));	}TEMPLATE<CLST _Ty1A> INLINE	_Ty1A **_ptr_read(_Ty1A *_Ptr)	{ 
	return AddressOf(_Ptr);	}TEMPLATE<CLST _Ty2A> INLINE	_Ty2A *_ptr_check(const _Ty2A *_Left, _Ty2A _Right)	{ 
	_Ty2A *_Ptr = _Left;	for( ; *_Ptr; )		if(*_Ptr++ == _Right)			return _Ptr;	return 0;	}TEMPLATE<CLST _Ty2A> INLINE 	_Ty2A *_ptr_checkl(_Ty2A *_Left, 		_Ty2A _Right, _Ty2A _Times)	{ 
	int i = 1;	_Ty2A *_Ptr = _Left;	for(bool x = false; *_Ptr			&& x ? i != _Times : 1; x ? i++ : 0)		if(*_Ptr++ == _Right)			x = true;		else if(x)			x = false, i = 1;	return _Ptr - _Times + 1;	}TEMPLATE<CLST _Ty1A> INLINE	_Ty1A *_ptr_new(_Ty1A *_Ptr)	{ 
	_Ty1A *_Check_Ptr = _Ptr;	return _Check_Ptr;	}TEMPLATE<CLST _Ty7A> INLINE	_Ty7A **_ptr_upper(_Ty7A *_Ptr)	{ 
	_Ty7A *_First = _Ptr, *_Last = _Ptr;	while(*_Last++)		;	return (_Ty7A **)*((_Ty7A *)_ptr_read(*_Last) - _First + 1);	}TEMPLATE<CLST _Ty7A> INLINE	_Ty7A **_ptr_lower(_Ty7A *_Ptr)	{ 
	_Ty7A *_First = _Ptr, *_Last = _Ptr;	while(*_Last++)		;	return (_Ty7A **)*((_Ty7A *)_ptr_read(*_Last));	}TEMPLATE<CLST _Ty1A> INLINE	bool _ptr_perpectmatch_prefix(_Ty1A *_Left, _Ty1A *_Right)	{ 
	_Ty1A *_Ptr = _Left, *_Sptr = _Right;	for( ; *_Ptr; _Ptr++, _Sptr++)		if(*_Ptr != *_Sptr)			return false;	return true;	}TEMPLATE<CLST _Ty1A> INLINE	bool _ptr_perpectmatch(_Ty1A *_Left, _Ty1A *_Right)	{ 
	_Ty1A *_Ptr = _Left, *_Sptr = _Right;	for( ; *_Ptr; _Ptr++, _Sptr++)		if(*_Ptr != *_Sptr)			return false;	for(_Ptr = _Left, _Sptr = _Right			; *_Sptr; _Sptr++, _Ptr++)		if(*_Ptr != *_Sptr)			return false;	return true;	}TEMPLATE<CLST _Ty2A> INLINE	_Ty2A *_ptr_find_match(_Ty2A *_Left, _Ty2A *_Right)	{ 
	_Ty2A *_Ptr = _Left, *_Sptr = _Right;	for(_Ty2A *_N; *_Ptr; _Ptr++)		if(*_Ptr == *_Sptr)			for(_N = _Ptr; ; _N++, _Sptr++)				if(!*_Sptr)					return _Ptr;				else if(*_N != *_Sptr){					_Sptr = _Right;					_Ptr++;					break;				}	return _Left;	}TEMPLATE<CLST _Ty2A> INLINE	_Ty2A *_ptr_find_match_n(_Ty2A *_Left, _Ty2A *_Right)	{ 
	_Ty2A *_Ptr = _Left, *_Sptr = _Right;	for(_Ty2A *_N; *_Ptr; _Ptr++)		if(*_Ptr == *_Sptr)			for(_N = _Ptr; ; _N++, _Sptr++)				if(!*_Sptr)					return _N;				else if(*_N != *_Sptr){					_Sptr = _Right;					_Ptr++;					break;				}	return _Left;	}TEMPLATE<CLST _Ty2A> INLINE	void _ptr_forcemerge(_Ty2A *_Left, _Ty2A *_Right)	{ 
	_Ty2A *_Ptr = _Left, *_Sptr = _Right;	int i = _ptr_last_i(_Ptr);	while(*_Sptr)        *(_Ty2A *)(AddressOf(*_Ptr) 			+ sizeof(_Ty2A) * (_Sptr - _Right)) = *_Sptr++;	for(int f = 0; f <= i; f++)		_Ptr++;	}TEMPLATE<CLST _Ty2A> INLINE	void _ptr_merge(_Ty2A *_Left, _Ty2A *_Right)	{ 
	_Ty2A *_V_ptr = _Left; 
	_Ty2A *_Ptr = _Right;	_ptr_forcemerge(_Left, _Right);	if(!*_Left)		_ptr_merge(_V_ptr, _Ptr);	_ptr_forcemerge(_Ptr, _V_ptr);	}TEMPLATE<CLST _Ty2A> INLINE	void _ptr_change(_Ty2A *_Left, _Ty2A *_Right)	{ 
	_Ty2A _First = *_Right;	_Ty2A *_Ptr = ++_Left;	(*--_Ptr = _First, _Ptr++);	while(*_Right++)		*(_Ptr++) = *(_Right);	}TEMPLATE<CLST _Ty3A> 	CLST shared_ptr	{	
public:		shared_ptr()		: _Ptr(0), size(0)		{ 
		_Ptr = pointer_alloc(1);		_Reset(_Ptr, _Ptr);		}	~shared_ptr()		{ 
		delete _Ptr;		}	INLINE _Ty3A *&operator*()		{ 
		return *_Ptr;		}	INLINE _Ty3A &operator->() 		{ 
		return _Ptr;		}	INLINE void extend(int i)		{ 
		ptr_extend(i);		}	INLINE void realloc(int i)		{ 
		ptr_realloc(i);		}	INLINE _Ty3A &operator[](int i)		{ 
		return _Ptr[i];		}	INLINE _Ty3A &operator()(int i)		{ 
		return _Ptr[size - i];		}		INLINE void fill(_Ty3A _Val)		{ 
		ptr_fill(_Val);		}	INLINE void fill(int i, int f, _Ty3A _Val)		{ 
		ptr_fill(i, f, _Val);		}private:		void _Reset(_Ty3A *_Ptr_EP, _Ty3A *_Ptr_First)		{ 
		_Ptr = _Ptr_EP; 		_First = _Ptr_First;		}	_Ty3A* pointer_alloc(int _Val)		{ 
		void *_Ptr = 0;		if (_Val)			_Ptr = ::operator new(_Val * sizeof(_Ty3A));		return ((_Ty3A *)_Ptr);		}	void ptr_extend()		{ 
		_Ty3A *_Ptr = pointer_alloc(++size);		for(int i = 0; i <= (size-1); i++)			_Ptr[i] = this->_Ptr[i];		this->_Ptr = (_Ty3A *)_Ptr;		_Reset(this->_Ptr, this->_Ptr);		}	void ptr_extend(int i)		{ 
		_Ty3A *_Ptr = pointer_alloc((size, size += i));		for(int i = 0; i <= (size - i); i++)			_Ptr[i] = this->_Ptr[i];		this->_Ptr = (_Ty3A *)_Ptr;		_Reset(this->_Ptr, this->_Ptr);		}	void ptr_realloc(int i)		{ 
		_Ty3A *_Ptr = pointer_alloc(i);		for(int f = 0; size > i 				? f <= i : f <= size; f++)			_Ptr[f] = this->_Ptr[f];		this->_Ptr = (_Ty3A *)_Ptr;		_Reset(this->_Ptr, this->_Ptr);		size = i;		}	void ptr_fill(int size_mi, 			int size_ma, _Ty3A _what)		{ 
		if(size_ma > size)			ptr_realloc(size_ma);		for(int i = size_mi; i <= size_ma; i++)			_Ptr[i] = _what;		}	void ptr_fill(_Ty3A _what)		{ 
		for(int i = 0; i <= size; i++)			_Ptr[i] = _what;		}	_Ty3A *_First;	_Ty3A *_Ptr;	int size;	};TEMPLATE<CLST _Ty0> inline	int strlen(_Ty0 *that)	{ 
	for( int i = 0; ; )		if(!that[++i])			return i;	}TEMPLATE<CLST _Ty0> inline	int f_len(_Ty0 *that)	{ 
	_Ty0 *pp = that;	while(*pp++);	return pp - that - 1;	}TEMPLATE<CLST _String_Element = char>	CLST string	{ 
	vector<_String_Element> str;	bool reverses;	public:		string()			: reverses(false)			{ }		string(_String_Element* _valuable_char)			: reverses(false)			{ 
			char_put(_valuable_char);			}		string(const _String_Element* _const_char)			: reverses(false)			{ 
			char_put(const_cast<_String_Element*> (_const_char));			}		inline _String_Element& operator[](int pos)			{ 
			if(!reverses)				return str[pos];			else				return str(pos);			}		inline void reverse()			{ 
			reverses = true;			}		inline int lenth()			{ 
			return str.size();			}		_String_Element* operator*()			{ 
			int len = lenth();			_String_Element *ret = new _String_Element[len];			if(!reverses)				for(int n = 0; n < len; n++)					ret[n] = str[n]->_DATA;			else				for(int n = 0; n < len; n++)					ret[n] = str(n)->_DATA;			ret[len] = 0;			return ret;			}		inline void operator+=(_String_Element* _valuable_char)			{ 
			char_put(_valuable_char);			}		inline void operator+=(const _String_Element* _const_char)			{ 
			char_put(const_cast<_String_Element*> (_const_char));			}		inline void operator+=(int _valuable_int)			{ 
			char_put(itoas<char> (_valuable_int));			}		inline vector<_String_Element> &ch_n()			{ 
			return str;			}		string<_String_Element> &operator<(_String_Element *get)			{ 
			char_put(get);			return *this;			}		string<_String_Element> &operator<(const _String_Element *get)			{ 
			char_put(const_cast<_String_Element*> (get));			return *this;			}		string<_String_Element> &operator<(string<_String_Element> &get)			{ 
			char_put(*get);			return *this;			}		string<_String_Element> &operator>(_String_Element *get)			{ 
			char_put_r(get);			return *this;			}		string<_String_Element> &operator>(const _String_Element *get)			{ 
			char_put_r(const_cast<_String_Element*> (get));			return *this;			}		string<_String_Element> &operator>(string<_String_Element> &get)			{ 
			char_put_r(*get);			return *this;			}		void replace_test(string<_String_Element> &retchars, 				string<_String_Element> &gotchars)			{ 
			_vector_replace2(str, retchars.ch_n(), gotchars.ch_n());			}		void replace(string<_String_Element> &retchars, 				string<_String_Element> &gotchars)			{ 
			_VECTOR_OPERATION 				_VECTOR_NODES<_String_Element> 					*start = str.front();			_VECTOR_OPERATION 				_VECTOR_NODES<_String_Element> 					*last = str.front();			_VECTOR_OPERATION 				_VECTOR_NODES<_String_Element> 					*buf = gotchars.ch_n().front();			_VECTOR_OPERATION 				_VECTOR_NODES<_String_Element> 					*publicq = 0;			int i = replace_find(retchars), 				f = i + gotchars.lenth();			for(int d = 0; d < i; d++)				start = start->_NEXT;			for(int d = 0; d <= f; d++)				last = last->_NEXT;			buf->_PREV = start;			start = gotchars.ch_n().front();			buf->_NEXT = last;			publicq = last;			last = gotchars.ch_n().back();			publicq->_NEXT = last;			}	private:		inline void char_put(_String_Element *_char)			{ 
			int f = strlen(_char);			if(!reverses)				for(int i = 0; i < f; i++)					str.push_back(_char[i]);			else				for(int i = 0; i < f; i++)					str.push_front(_char[i]);			}		inline void char_put_r(_String_Element *_char)			{ 
			int f = strlen(_char);			if(!reverses)				for(int i = 0; i < f; i++)					str.push_front(_char[i]);			else				for(int i = 0; i < f; i++)					str.push_back(_char[i]);			}		inline int replace_find(string<_String_Element> &retchars)			{ 
			_VECTOR_OPERATION 				_VECTOR_NODES<_String_Element> *start = str.front();			_VECTOR_OPERATION 				_VECTOR_NODES<_String_Element> *s_start = retchars.ch_n().front();			int n = retchars.lenth(), f = lenth();			for(int i = 0; i <= f; i++, start = start->_NEXT)				if(start->_DATA == s_start->_DATA)					for(int fd = i; fd <= i+n; fd++, start = start->_NEXT,							s_start = s_start->_NEXT)						if(fd == i + n)							return i;						else 							if(start->_DATA != s_start->_DATA)								break;			}		};TEMPLATE<typename _Ty0> inline	_Ty0*& itoas(int i)	{ 
	static _Ty0 buf[21];	_Ty0 *p = buf + 19 + 1;	if (i >= 0) 		{while (i != 0)			*--p = '0' + (i % 10), i /= 10;		return p;}	else{while (i != 0)			*--p = '0' - (i % 10), i /= 10;		*--p = '-';}	return p;	}TEMPLATE<typename _Ty11> inline	_Ty11*& ftoa(float i)	{ 
	static _Ty11 buf[100];	_Ty11 *p = buf + 99;	if (i >= 0)		{		while(i >= 1)			{			*--p = '0' + ((int)i % 10);			i /= 10;			}		*--p = '.';		while(i > 0){			i *= 10;			*--p = '0' + (int)((int)i % 10);			i -= (int)((int)i % 10);			}		}	else		{		while(i >= 1)			*--p = '0' + ((int)i % 10), i /= 10;		*--p = '.';		while(i != 0)			*--p = '0' + (int)(i * 10), i -= (int)i % 10;		*--p = '-';		}	return p;	}TEMPLATE<typename _Ty0> inline	double atof(_Ty0* chars)	{ 
	_Ty0* point = chars;	double dev, floa, floating;	bool sign = false;	while(*point && isspace(*point))		point++;	if(!*point)		return 0;	else if(!isnumberic(*point))		sign = ((*point++ - 43 == 0) ? 0 : 1);	while(*point && isnumberic(*point) || *point == '.')		{			if(*point == '.')			{				*point++;				while(*point && isnumberic(*point))				{					floa = floa * 10 + *point - 48;					floating = 0.1 * floating;					*point++;				}				floa = floa * floating;			}			else			{				dev = dev * 10 + dev - 48;				*point++;			}		}	if (sign)		return -1 * (dev + floa);	return dev + floa;	}TEMPLATE<typename _Ty0> inline	bool isnumberic(_Ty0 what)	{ 
	return '0' <= what && what <= '9';	}TEMPLATE<typename _Ty0> inline	_Ty0 isspace(_Ty0 c_ch)	{ 
	switch(c_ch)		{		case '\n':		case '\v':		case '\f':		case '\t':		case '\r':		case  ' ':			return 1;		}	return 0;	}TEMPLATE<typename _Ty0>	_Ty0* strtok(_Ty0* strToken, const _Ty0* strDelimit)	{ 
	char *str;	const char *ctrl = strDelimit;	unsigned char map[32];	int count;	for (count = 0; count < 32; count++)		map[count] = 0;	do {		map[*ctrl >> 3] |= (1 << (*ctrl & 7));	} while (*ctrl++);	if (strToken)		str = strToken;	while ((map[*str >> 3] & (1 << (*str & 7))) && *str)		str++;	strToken = str;	for ( ; *str ; str++ )		if ( map[*str >> 3] & (1 << (*str & 7)) ) {			*str++ = '\0';			break;		}	if ( strToken == str ) 		return 0;	else 		return strToken;	}TEMPLATE<typename _Ty0> inline	int strlen_dev(		const _Ty0 *str)	{ 
	const _Ty0 *ch = str;	while(*ch++)		;	return ((int)(ch - str - 1));	}TEMPLATE<typename _Ty0> inline	_Ty0 *strrev_dev(		_Ty0 *string		)	{ 
	_Ty0 *start = string;	_Ty0 *left = string;	_Ty0 ch;	while(*string++)		;	string -= 2;	while (left < string)		{		ch = *left;		*left++ = *string;		*string-- = ch;		}	return(start);	}TEMPLATE<typename _Ty0> inline	_Ty0 *split_ch(		const _Ty0 *rCharText, 		const _Ty0 fSplit, 		int Arrange)	{ 
	int i=0, f=0, Split=0;	_Ty0 Buf[10][1000];	while(rCharText[f])		{		if(rCharText[f] == fSplit)			{			Buf[Split][++i] = 0;			Split++;			i = 0;			}		if(rCharText[f] != fSplit)			Buf[Split][i] = rCharText[f];		else			Buf[Split][--i] = rCharText[f];		i++;		f++;		}	if(rCharText[f] == 0)		{		Buf[Split][++i] = 0;		Split++;		i = 0;		}	if(rCharText[f] != fSplit)		Buf[Split][i] = rCharText[f];	else		Buf[Split][--i] = rCharText[f];	return Buf[Arrange];	}TEMPLATE<typename _Ty0> inline	_Ty0 *left_ch(		const _Ty0 *str,		_Ty0 ch)	{ 
	while(*str && *str != ch)		str++;	if(*str == ch)		return ((_Ty0 *)(++str));	return (0);	}TEMPLATE<typename _Ty0> inline	_Ty0 *right_ch(		const _Ty0 *str,		_Ty0 ch)	{ 
	_Ty0 *start = (_Ty0 *)str;	while(*str++)		;	while(--str != start && *str != (ch))		;	if(*str == ch)		return ((_Ty0 *)(++str));	return (0);	}TEMPLATE<typename _Ty0> inline	_Ty0 *replace_ch(		const _Ty0 *str,		_Ty0 _left,		_Ty0 _right)	{ 
	int len = strlen_dev(str);	int back = 0;	_Ty0 *start = new _Ty0[len];	for(int i = 0; i <= len; i++)		start[i] = str[i];	while(*start && *start != _left)		start++, back++;	*start = _right;	return start - back;	}TEMPLATE<typename _Ty0> inline	_Ty0 *replace_ch_n(		const _Ty0 *str,		_Ty0 _left,		_Ty0 _right)	{ 
	int len = strlen_dev(str);	int back = 0;	_Ty0 *start = new _Ty0[len];	for(int i = 0; i <= len; i++)		start[i] = str[i];	while(*start)		if(*start == _left)			*start = _right;		else			start++, back++;	return start - back;	}	
TEMPLATE<CLST _Ty1> inline	_Ty1 _Seperate(_Ty1 value_type_ex, 		_Ty1 multibyteset)	{ 
	_Ty1 buf = *value_type_ex;	*value_type_ex = *multibyteset;	*multibyteset = buf;	return value_type_ex;	}TEMPLATE<CLST _Ty1, 	CLST _Ty2> inline	_Ty1* _Realloc(typename _Ty1* _Array, 		_Ty2 nsize, _Ty2 lsize)	{ 
	_Ty1 buf = new _Ty1[lsize];	for(_Ty1 n = 0; n <= nsize;n++) 		buf[n] = _Array[n];	return buf;	}TEMPLATE<CLST _Ty1> inline	_Ty1 (max)(_Ty1 ex, _Ty1 ey)	{ 
	return (ex > ey ? ex : ey); 	}TEMPLATE<CLST _Ty1> inline	_Ty1& (max)(_Ty1& ex, _Ty1& ey)	{ 
	return (ex > ey ? ex : ey); 	}TEMPLATE<CLST _Ty1> inline	_Ty1 (max)(_Ty1 ex, 		_Ty1 ey, _Ty1 ez)	{ 
	return (max)((max)(ex, ey), ez);	}TEMPLATE<CLST _Ty1> inline	_Ty1 (min)(_Ty1 ex, _Ty1 ey)	{ 
	return (ex < ey ? ex : ey); 	}TEMPLATE<CLST _Ty1> inline	_Ty1& (min)(_Ty1& ex, _Ty1& ey)	{ 
	return (ex < ey ? ex : ey); 	}TEMPLATE<CLST _Ty1> inline	_Ty1 (min)(_Ty1 ex, 		_Ty1 ey, _Ty1 ez)	{ 
	return (min)((min)(ex, ey), ez);	}TEMPLATE<CLST _Ty1> inline	_Ty1 abs(_Ty1 ex)	{ 
	return (ex > 0 ? ex : ( ex * -1 ));	}TEMPLATE<CLST _Ty1> inline	_Ty1* _param()	{ 
	return (_Ty1*)(0);	}TEMPLATE<typename _Tyr, CLST _Ty1> inline	_Tyr _summation(_Ty1 _left, int _lsize)	{ 
	_Tyr buf;	for(int n = 0; n <= _lsize; n++) 		buf += _left[n];	return buf;	}TEMPLATE<typename _Ty1, 	typename _Ty2, typename _Ty3> inline	void _copy_n(const _Ty1 _Left,  _Ty2& _Right,		_Ty3 _lsize, _Ty3 _rsize)	{ 
	for(int i = 0; i <= _lsize; i++)		for(int f = 0; f <= _rsize; f++)			(_Right[i])[f] = (_Left[i])[f];	}TEMPLATE<typename return_type, CLST _Ty1> inline	return_type _average(_Ty1 _left, int _lsize)	{ 
	return _summation(_left, _lsize) / _lsize;	}TEMPLATE<typename _Ty1> inline	_Ty1 _array(const int _Left, const int _Right)	{ 
	_Ty1 _buf = new ridof_pr<_Ty1>::type[_Left];	for(int f = 0; f <= _Right; ++f)		_buf[f] = new ridof_pr<ridof_pr<_Ty1>::type>::type[_Right];	return _buf;	}TEMPLATE<typename _Ty1> inline	_Ty1 _conple(_Ty1 _Left, int _size)	{ 
	return _size - _Left - 1;	}TEMPLATE<typename _Tyd, 	typename _Ty1> inline	void _rotate(_Ty1 _left, int _lsize, int _rsize)	{ 
	_Tyd _buf = _array<_Tyd> (_lsize, _rsize);	_copy_n(_left, _buf, _lsize, _rsize);	for(int n = 0; n < _lsize; n++)		for(int f = 0; f < _rsize; f++)			_left[f][_conple(n, _lsize)] = _buf[n][f];	}TEMPLATE<typename _Tyd, 	typename _Ty1> inline	void _rotate(_Ty1 _left, int _lsize, int _rsize, int _time)	{ 
	for(int n = 0; n != _time; n++)		_rotate<_Tyd> (_left, _lsize, _rsize);	}TEMPLATE<typename _Ty1> inline	void _reverse(_Ty1 &_left, int _lsize)	{ 
    for(int i = 0; i < _lsize / 2; i++)		_Swap(_left, i, _conple(i, _lsize));	}TEMPLATE<typename _Tyd, 	typename _Ty1> inline	void _reverse(_Ty1 _left, int _lsize, int _rsize)	{ 
	_Tyd _buf = _array<_Tyd> (_lsize, _rsize);	_copy_n(_left, _buf, _lsize, _rsize);	for(int i = 0; i < _lsize; i++)		for(int f = 0; f < _lsize; f++)			_left[_conple(i, _lsize)][f] = _buf[i][f];	}TEMPLATE<typename _Ty1> inline	void _sort(_Ty1 _left, int _lsize)	{ 
	for(int n = 1; n <= (_lsize-1); n++)		for(int i = 0; i <= (_lsize-2); i++)			if(_left[i] > _left[i + 1])				_Swap(_left, i, i + 1);	}TEMPLATE<typename _Ty1> inline	void _sort_n(_Ty1 _left, int _lsize, _Ty1 _right)	{ 
	for(int n = 1; n <= (_lsize-1); n++)		for(int i = 0; i <= (_lsize-2); i++)			if(_left[i] > _left[i + 1])			{				_Swap(_left, i, i + 1);				_Swap(_right, i, i + 1);			}	}TEMPLATE<typename _Ty1> inline	void _select_sort(_Ty1 *_left, int _lsize)	{ 
	_Ty1 min;	int index;	for(int i = 0; i < _lsize - 1; i++, index = i)		{		min = _left[i];		for(int j = i+1; j < _lsize; j++)			if(min > _left[j])				{min = _left[j];				index = j;}		_left[index] = _left[i];		_left[i] = min;		}	}TEMPLATE<typename _Ty1> inline	void _insert_sort(_Ty1 *_left, int _lsize)	{ 
	_Ty1 temp;	int k;	for(int i = 1; i < _lsize; i++, k = i)		{		temp = _left[i];		while(_left[k-1] > temp && k > 0)			_left[k] = _left[(k--) - 1];		_left[k] = temp;		}	}TEMPLATE<typename _Ty1> inline	void _quick_sort(_Ty1 *_left, int _lsize)	{ 
	int i = 0, j = _lsize;	_Ty1 temp;	if (_lsize > 1)		{		while(i < j)			{			while(_left[++i] < *_left && i < _lsize);			while(_left[--j] > *_left);			if ( i < j ) 				_Swap(_left, i, j);			}		_Swap(_left, j++);		_quick_sort(_left, j - 1);		_quick_sort(_left + j, _lsize - j - 2);		}	}TEMPLATE<typename _Ty1> inline	void _swapfront(_Ty1 *_left, int _time)	{ 
	for(int n = 0; n <= (_time-1); n++)		_Swap(_left, n, n + 1);	}TEMPLATE<typename _Ty1> inline	void _partreverse(_Ty1 *_left, int _right, int _rsize)	{ 
	for(int i = _right; i < (_right + _rsize) / 2; i++)		_Swap(_left, i, _conple(i, _right + _rsize));	}TEMPLATE<typename _Ty1> inline	void _forward(_Ty1 *_left, int _right, int _time)	{ 
	for(int n = 0; n <= _time; n++)		_Swap(_left, _right + n, _right + n + 1);	}TEMPLATE<typename _Ty1> inline	void _forward(_Ty1 *_left, int _right, int _rsize, int _time)	{ 
	for(int n = 0; n <= _time; n++)		for(int f = _right + n; f <= (_rsize + n); f++)			_Swap(_left, f, f + 1);	}TEMPLATE<typename _Ty1> inline	void _back(_Ty1 *_left, int _right, int _time)	{ 
	for(int n = 0; n <= _time; n++)		_Swap(_left, _right - n, _right - n - 1);	}TEMPLATE<typename _Ty1> inline	void _back(_Ty1 *_left, int _right, int _rsize, int _time)	{ 
	for(int n = 0; n <= _time; n++)		for(int f = _right - n; f <= (_rsize - n); f++)			_Swap(_left, f, f - 1);	}TEMPLATE<typename _Ty1> inline	_Ty1 _max_element(_Ty1* _left, int _lsize)	{ 
	_Ty1 _buf = _left[0];	for(int n = 1; n <= _lsize; n++)		_buf = max(_buf, _left[n]);	return _buf;	}TEMPLATE<typename _Ty1> inline	_Ty1 _min_element(_Ty1* _left, int _lsize)	{ 
	_Ty1 _buf = _left[0];	for(int n = 1; n <= _lsize; n++)		_buf = min(_buf, _left[n]);	return _buf;	}TEMPLATE<typename _Ty1> inline	_Ty1* _new(const int _Val)	{ 
	return new _Ty1[_Val];	}TEMPLATE<typename _Ty1> inline	_Ty1 _cmax(_Ty1* _left, int _lsize)	{ 
	_Ty1* _buf = _new[_lsize];	int *max = _new[_lsize];	for(int n = 0; n <= _lsize; n++)		for(int f = 0; f <= _lsize; f++)			if(_left[f] == _buf[n])				max[f]++;			else if(f == _lsize)			{				_buf[n] = _left[f];				max[f]++;			}	_sort_n(_buf, _lsize, max);	return _buf[_lsize];	}TEMPLATE<typename _Ty1> inline	_Ty1 _cmin(_Ty1* _left, int _lsize)	{ 
	_Ty1* _buf = _new[_lsize];	int *max = _new[_lsize];	for(int n = 0; n <= _lsize; n++)		for(int f = 0; f <= _lsize; f++)			if(_left[f] == _buf[n])				max[f]++;			else if(f == _lsize)			{				_buf[n] = _left[f];				max[f]++;			}	_sort_n(_buf, _lsize, max);	return _buf[0];	}TEMPLATE<typename _Ty1> inline	void _plus(_Ty1 _left, _Ty1 _right, int _size)	{ 
	for(int n = 0; n <= _size; n++)		_left[n] = _left[n] + _right[n];	}TEMPLATE<typename _Ty1> inline	void _minus(_Ty1 _left, _Ty1 _right, int _size)	{ 
	for(int n = 0; n <= _size; n++)		_left[n] = _left[n] - _right[n];	}TEMPLATE<typename _Ty1> inline	bool _equal(_Ty1 _left, _Ty1 _right, int _size)	{ 
	for(int n = 0; n <= _size;  n++)		if(_left[n] != _right[n])			return false;	return true;	}TEMPLATE<typename _Ty1> inline	bool _equal_n(_Ty1 _left, _Ty1 _right, int _lsize, int _rsize)	{ 
	for(int n = 0; n <= _lsize;  n++)		if !(_equal(_left[n], _right[n], _rsize))			return false;	return true;	}TEMPLATE<typename _Ty1> inline	bool _equal_f(_Ty1 _left, _Ty1 _right, int _lsize, int _rsize, int _asize)	{ 
	for(int n = 0; n <= _lsize;  n++)		if !(_equal_n(_left[n], _right[n], _rsize, _asize))			return false;	return true;	}TEMPLATE<typename _Ty1> inline	int _first_of(_Ty1* _left, _Ty1 _right, int _lsize)	{ 
	for(int n = 0; n <= _lsize; n++)		if (_left[n] == _right)			return n;	}TEMPLATE<typename _Ty1> inline	int _last_of(_Ty1* _left, _Ty1 _right, int _lsize)	{ 
	for(int n = _lsize; n >= 0; n--)		if (_left[n] == _right)			return n;	}TEMPLATE<typename _Ty1> inline	int _count(_Ty1 _left, _Ty1 _right, int _lsize, int _rsize)	{ 
	int _buf = 0;	if(_lsize < _rsize) throw(_lsize);	for(int n = 0; n <= _lsize; n++)		for(int f = 0; f <= _rsize; f++)			if(_left[n] == _right[n])				_buf++;	return _buf;	}TEMPLATE<typename _Ty1> inline	int _count_n(_Ty1 array_, _Ty1 data, 		int first_array_size, int second_array_size)	{ 
	int retbuf = 0;	int startat;	bool state = false;	for(int n = 0; n <= first_array_size; n++)		for(int f = 0; f <= second_array_size; f++)			if(array_[n] == data[f])				{				if(state)					startat = array_[n];				retbuf++;				if(retbuf == second_array_size) 					return startat;				}			else				retbuf = 0, state = false;	return 0;	}
	TEMPLATE<typename _Ty1> inline	void _replace(_Ty1* _left, _Ty1 _right, _Ty1 _last, int _lsize)	{ 
	for(int n = 0; n <= _lsize; n++)		if(_left[n] == _right)			_left[n] = _last;	}TEMPLATE<typename _Ty1, typename function> inline	void _polytazing(_Ty1 _left, int _lsize, function& _rand)	{ 
    for(int n = 0; n < _lsize; n++)		_Swap(_left, n, _rand() % _lsize);	}TEMPLATE<typename _Ty1, typename function> inline	void _polytazing(_Ty1 _left, int _lsize, int _rsize, function& _rand)	{ 
	for(int f = 0; f < _lsize; f++)		for(int n = 0; n < _lsize; n++)			_Swap(_left[f], n, _rand() % _lsize);	}TEMPLATE<typename _Ty1> inline	_Ty1* _bind(_Ty1* _left, _Ty1* _right, int _lsize, int _rsize)	{ 
	_Ty1* _buf = _new<_Ty1> (_lsize + _rsize + 1);	_fill(_buf, _lsize + _rsize + 1);	int f = -1, n = 0;	for( ; n <= _lsize; )		_buf[++f] = _left[n++];	for(n = 0; n <= _rsize; )		_buf[++f] = _right[n++];	return _buf;	}TEMPLATE<typename _Ty1> inline	int _larger(_Ty1* _left, _Ty1 _right, int _lsize)	{ 
	int f = 0;	for(int n = 0; n <= _lsize; n++)		if(_left[n] > _right)			f++;	return f;	}TEMPLATE<typename _Ty1> inline	int _smaller(_Ty1* _left, _Ty1 _right, int _lsize)	{ 
	int f = 0;	for(int n = 0; n <= _lsize; n++)		if(_left[n] < _right)			f++;	return f;	}TEMPLATE<typename _Ty1> inline	int _both(_Ty1* _left, _Ty1 _mid, _Ty1 _right, int _lsize)	{ 
	int f = 0;	for(int n = 0; n <= _lsize; n++)		if(_mid < _left[n] && _left[n] < _right)			f++;	return f;	}TEMPLATE<CLST _Ty1> inline	_Ty1* _vtp(_Ty1* _left, _Ty1 _right)	{ 
	_Ty1* _buf = _new(_right - _left);	for(int n = _left, f; _left != _right;)		_buf[f++] = n++;	}TEMPLATE<CLST _Ty1> inline	_Ty1 _mtx_add(_Ty1 _left, _Ty1 _right, 		int _ls1 = 3, int _ls2 = 3, int _rs1 = 3, int _rs2 = 3)	{ 
	if(_ls1 != _rs2) return;	_Ty1 _buf = _array(_ls1, _ls1);	for(int i = 0; i < _ls1; i++)		for(int j = 0; j < _ls2; j++)			_buf[i][j] = _left[i][j] + _right[i][j];	return _buf;	}TEMPLATE<CLST _Ty1> inline	_Ty1 _mtx_sub(_Ty1 _left, _Ty1 _right, 		int _ls1 = 3, int _ls2 = 3)	{ 
	_Ty1 _buf = _array(_ls1, _ls1);	for(int i = 0; i < _ls1; i++)		for(int j = 0; j < _ls2; j++)			_buf[i][j] = _left[i][j] + _right[i][j];	return _buf;	}TEMPLATE<CLST _Ty1> inline	_Ty1 _mtx_multiple(_Ty1 _left, _Ty1 _right, 		int _ls1 = 3, int _ls2 = 3)	{ 
	_Ty1 _buf = _array(_ls1, _ls1);	for(int i = 0; i < _ls1; i++)		for(int j = 0; j < _ls1; j++){ _buf[i][j]=0;			for(int f = 0; f < _ls2; f++)				_buf[i][j] += _left[i][f] * _right[f][j];}	return _buf;	}TEMPLATE<CLST _Ty1> inline	_Ty1 _mtx_divide(_Ty1 _left, _Ty1 _right, 		int _ls1 = 3, int _ls2 = 3)	{ 
	_Ty1 _buf = _array(_ls1, _ls1);	for(int i = 0; i < _ls1; i++)		for(int j = 0; j < _ls1; j++){ _buf[i][j]=0;			for(int f = 0; f < _ls2; f++)				_buf[i][j] += _left[i][f] / _right[f][j];}	return _buf;	}	
TEMPLATE<CLST _operator_type> CLST	control	{ 
	_operator_type* _array;	int size;	public:	explicit control(_operator_type* _left, int _lsize)		: _array(_left), size(_lsize)		{ 
		}	explicit control(int _lsize)		: size(_lsize)		{ 
		_array = _new<_operator_type> (_lsize);		}	control()		: _array(0), size(0)		{ 
		}	virtual ~control()		{ 
		_clear();		delete[] _array;		}	void _forceheap(int _size)		{ 
		_array = _new(_size);		}	_operator_type* _copying()		{ 
		_operator_type* _buf = _new(size);		_copy(_array, _buf, size);		return _buf;		}	void _swap(_operator_type* _left, int _lsize)		{ 
		_swap(_left, _array);		_swap(_lsize, size);		}	void _swap(control _left)		{ 
		_swap(_left._array, _array);		_swap(_left.size, size);		}	void _clear()		{ 
		_array = 0;		size = 0;		}	void _fill(_operator_type _left)		{ 
		_fill(_array, _left, size);		}	void _fill(_operator_type _left, int n)		{ 
		_fill(_array, _left, n);		}	_operator_type operator[](int _left)		{ 
		return _array[_left];		}	_operator_type operator->()		{ 
		return _array;		}	};TEMPLATE<CLST _operator_type> CLST	array_	: public control<_operator_type>	{ 
	_operator_type* _array;	int point;	int size;	public:	explicit array_()		: _array(0), size(0), point(0)		{ 
		}	_operator_type& operator[](int _left)		{ 
		if(size < _left)			THROW_ERROR_INPUT(_left)		return _array[_left];		}	array_* operator->()		{ 
		return (**this);		}	int Size() const		{ 
		return size;		}	bool operator++(int)		{ 
		if(size == point)		{				point = 0;			return false;		}		point++;		return true;		}	bool operator--(int)		{ 
		if(point == 0)			return false;		point--;		return true;		}	bool operator+(int _left)		{ 
		if(size < (point + _left))			return false;		point += _left;		return true;		}	bool operator-(int _left)		{ 
		if((point - _left) == 0)			return false;		point -= _left;		return true;		}	int ptr()		{ 
		return point;		}	bool status()		{ 
		if(point == size)			return false;		return true;		}	void at(int _left)		{ 
		if(size >= _left)			point = _left;		}	void operator=(array_ _left)		{ 
		_array = _left._array;		size = _left.size;		point = _left.point;		}	void operator=(int _left)		{ 
		point = _left;		}	_operator_type operator*()		{ 
		return _array[point];		}	_operator_type& operator&()		{ 
		return _array[point];		}	bool operator==(array_ _left)		{ 
		return this->operator* == *_left;		}	bool operator!=(array_ _left)		{ 
		return this->operator* != *_left;		}	bool operator<(array_ _left)		{ 
		return this->operator* < *_left;		}	bool operator>(array_ _left)		{ 
		return this->operator* > *_left;		}	bool operator<=(array_ _left)		{ 
		return this->operator* <= *_left;		}	bool operator>=(array_ _left)		{ 
		return this->operator* >= *_left;		}	bool operator==(int _left)		{ 
		return size == _left;		}	bool operator!=(int _left)		{ 
		return size != _left;		}	bool operator<(int _left)		{ 
		return size < _left;		}	bool operator>(int _left)		{ 
		return size > _left;		}	bool operator<=(int _left)		{ 
		return size <= _left;		}	bool operator>=(int _left)		{ 
		return size >= _left;		}	bool operator&&(array_ _left)		{ 
		return this->operator* && *_left;		}	bool operator||(array_ _left)		{ 
		return this->operator* || *_left;		}	int size_of() const		{ 
		return size;		}	void bind(array_ _left)		{ 
		_array = _bind<_operator_type> (_array, _left._array, size, _left.size);		size += _left.size;		}	void allocate(int _size)		{ 
		_operator_type* _buf = _new<_operator_type> (_size);		size = _size;		_array = _buf;		}	void keep(int _size)		{ 
		_operator_type* _buf = _new<_operator_type> (_size);		_copy(_array, _buf, size);		size = _size;		_array = _buf;		}	};TEMPLATE<CLST _operator_type> CLST	array_n	: public array_<array_<_operator_type> >	{ 
	};TEMPLATE<CLST _operator_type> CLST	array_f	: public array_n<array_<_operator_type> >	{ 
	};TEMPLATE<CLST _Arye, CLST _Elem> inline	_Elem _Equal(_Arye& _left, _Arye& _right)	{ 
	for( ; _left++ != _right++; );	return *_left;	}	TEMPLATE<CLST _Arye> inline	bool _Equal_n(_Arye& _left, _Arye& _right)	{ 
	for( ; _left++ != _right++; );	if (_left.size == _left.point)		return true;	return false;	}TEMPLATE<CLST _Arye, CLST _Fn_1> inline	void _For_Each(_Arye& _left, _Arye& _right, _Fn_1 _Func)	{ 
	for (; _left != _right; ++_left)		_Func(*_left);	}TEMPLATE<CLST _Arye, CLST _Fn_1> inline	void _For_Each(_Arye& _left, _Fn_1 _Func)	{ 
	for (; _left++; )		_Func(*_left);	}TEMPLATE<CLST _Arye, CLST _Elem> inline	int _Count(_Arye& _left, _Elem _right)	{ 
	int _cot = 0;	for( ; _left++; )		if( _left == _right)			_cot++;	return _cot;	}TEMPLATE<CLST _Arye, CLST _Elem> inline	void _Fill(_Arye& _left, _Elem _right)	{ 
	for( ; _left++; )		&_left = _right;	}TEMPLATE<CLST _Arye> inline	void _Swap(_Arye*& _left, int _lptr, int _rptr)	{ 
	_Arye _buf;	_buf = _left[_lptr];	_left[_lptr] = _left[_rptr];	_left[_rptr] = _buf;	}TEMPLATE<CLST _Arye> inline	_Arye _Copy(_Arye& _left)	{ 
	_Arye _buf = _new<remove_pointer<_Arye>::type> (_left.size);	for( ; _left++; _buf++)		&_buf = *_left;	return _buf;	}TEMPLATE<CLST _Arye> inline	void _Copy_n(_Arye& _left, _Arye& _right)	{ 
	for( ; _right++; _left++)		for( ; (&_right)++; (&_left)++)			&(&_right) = &(&_left);	}TEMPLATE<CLST _Arye, CLST _Fn_1> inline	bool _None(_Arye& _left, _Arye& _right, _Fn_1 _Func)	{ 
	for (; _left != _right; ++_left)		if (_Func(*_left))			return false;	return true;	}TEMPLATE<CLST _Arye, CLST _Fn_1> inline	bool _Any(_Arye& _left, _Arye& _right, _Fn_1 _Func)	{ 
	for (; _left != _right; ++_left)		if (_Func(*_left))			return true;	return false;	}TEMPLATE<CLST _Arye> inline	void _Sort(_Arye& _left)	{ 
	for(int n = 1; n <= (_left.Size()-1); n++)		for(int i = 0; i <= (_left.Size()-2); i++)			if(_left[i] > _left[i + 1])				_Swap(_left, i, i + 1);	}TEMPLATE<CLST _Arye> inline	void _Sort_n(_Arye& _left, _Arye& _right)	{ 
	for(int n = 1; n <= (_left.Size()-1); n++)		for(int i = 0; i <= (_left.Size()-2); i++)			if(_left[i] > _left[i + 1])			{				_Swap(_left, i, i + 1);				_Swap(_right, i, i + 1);			}	}TEMPLATE<CLST _Arye, CLST _Rtyp> inline	_Rtyp _Summation(_Arye _left)	{ 
	_Rtyp _buf = 0;	for(; _left++; )		_buf += *_left;	return _buf;	}TEMPLATE<CLST _Arye, CLST _Rtyp> inline	_Rtyp _Average(_Arye& _left)	{ 
	_Rtyp _buf = 0;	for(; _left++; )		_buf += *_left;	_buf /= _left.Size();	return _buf;	}TEMPLATE<CLST _Arye> inline	int _First_Of(_Arye*& _left, _Arye _right)	{ 
	for( ; _left++; )		if (*_left == _right)			return _left.ptr();	}TEMPLATE<CLST _Arye> inline	int _Last_Of(_Arye*& _left, _Arye _right)	{ 
	_left.at(_left.Size());	for( ; _left--; )		if (*_left == _right)			return _left.ptr();	}TEMPLATE<CLST _Arye> inline	void _Forward(_Arye& _left, int _right, int _time)	{ 
	for(int n = 0; n <= _time; n++)		_Swap(_left, _right + n, _right + n + 1);	}TEMPLATE<CLST _Arye> inline	void _Back(_Arye& _left, int _right, int _time)	{ 
	for(int n = 0; n <= _time; n++)		_Swap(_left, _right - n, _right - n - 1);	}TEMPLATE<CLST _Arye> inline	void _Reverse(_Arye& _left)	{ 
	for(int i = 0; i < (_left.Size() / 2); i++)		_Swap(_left, i, _left.Size() - i - 1);	}TEMPLATE<CLST _Arye, CLST _Rtyp> inline	void _Push_Back(_Arye& _left, _Rtyp _right)	{ 
	_Arye _buf;	_buf.allocate(_left.Size() + 1);	for( ; _left++; _buf++)		&_buf = *_left;	_buf[_left.Size() + 1] = _right;	_left = _buf;	}TEMPLATE<CLST _Arye, CLST _Rtyp> inline	void _Push_Front(_Arye& _left, _Rtyp _right)	{ 
	_Arye _buf;	_buf.allocate(_left.Size() + 1);	for( ; _left++; _buf++)		&_buf = *_left;	_forward(_buf, _buf.Size() - 1, 1);	_buf[0] = _right;	_left = _buf;	}TEMPLATE<CLST _Arye, CLST _Rtyp> inline	_Arye _Pop_Back(_Arye& _left)	{ 
	_Arye _buf;	_buf.allocate(_left.Size() - 1);	_Rtyp _buffer = _left.last();	for( ; _buf++; _left++)		if(_buf.ptr() < _left.Size())			&_buf = *_left;	_left = _buf;	return _buffer;	}TEMPLATE<CLST _Arye, CLST _Rtyp> inline	_Arye _Pop_Front(_Arye& _left)	{ 
	_Arye _buf;	_buf.allocate(_left.Size() - 1);	_Rtyp _buffer = _left[0];	for( ; _buf++; _left++)		if(_buf.ptr() < _left.Size())			&_buf = *_left;	_left = _buf;	return _buffer;	}TEMPLATE<CLST _Arye, CLST _Elem> inline	void _Fill_n(_Arye& _left, _Elem _right)	{ 
	for( ; _left++; )		for(; (&_left)++; )			&(&_left) = _right;	}TEMPLATE<CLST _Arye> inline	void _Alloc_n(_Arye& _left, int _size)	{ 
	for( ; _left++; )		(&_left).allocate(_size);	}TEMPLATE<CLST _Arye> inline	void _Alloc_n(_Arye& _left, int _lsize, int _rsize)	{ 
	_left.allocate(_lsize);	for( ; _left++; )		(&_left).allocate(_rsize);	}TEMPLATE<CLST _Arye, CLST _Elem> inline	void _Replace_n(_Arye& _left, _Elem _target, _Elem _right)	{ 
	for( ; _left++; )		for( ; (&_left)++; )			if (&(&_left) == _target)				&(&_left) = _right;	}TEMPLATE<CLST _Arye, CLST _Elem> inline	void _Replace_Each(_Arye& _left, _Elem _ltarget, _Elem _rtarget, _Elem _right)	{ 
	_Replace_n(_left, _rtarget, _right);	_Replace_n(_left, _ltarget, _rtarget);	_Replace_n(_left, _right, _ltarget);	}TEMPLATE<CLST _Arye, CLST _Elem> inline	_Arye _Triangle(int _size, _Elem _right)	{ 
	_Arye _buf;	_Alloc_n(_buf, _size, _size);	for( ; _buf++ ; )		_Fill(&_buf, 0);	for( ; _buf++ ; )		for(int n = 0; n <= _buf.ptr(); n++)			(&_buf)[n] = _right;	return _buf;	}	
TEMPLATE<CLST _Ty>	struct _X_TYPE	{ 
	typedef _Ty Value_Type;	typedef _Ty UnPointer;	typedef _Ty Pointer;	typedef _Ty Arrays;	};TEMPLATE<CLST _Ty>	struct _X_TYPE<const _Ty>	{ 
	typedef _Ty Value_Type;	typedef _Ty UnPointer;	typedef _Ty Pointer;	typedef _Ty Arrays;	};TEMPLATE<CLST _Ty>	struct _X_Base	{ 
	typedef _Ty Value_Type;	typedef _Ty UnPointer;	typedef _Ty Pointer;	typedef _Ty Arrays;	};TEMPLATE<CLST _Ty>	struct _X_Base<const _Ty>	{ 
	typedef _Ty Value_Type;	typedef _Ty Arrays;	typedef _Ty UnPointer;	typedef _Ty Pointer;	};TEMPLATE<CLST _Ty,	CLST _Ty1, CLST _Ty2>	struct _X_COMMON		: public _X_Base<_Ty>	{	typedef _X_COMMON<_Ty, _Ty1, _Ty2> _MyT;	typedef typename _X_Base<_Ty>::Value_Type _MyVT;	typedef typename _X_Base<_Ty>::Arrays _MyAY;	typedef typename _X_Base<_Ty>::UnPointer _MyUP;	typedef typename _X_Base<_Ty>::Pointer _MyPI;	public:		explicit _X_COMMON()			: _Right(0), _Left(0)			{ 
			}		explicit _X_COMMON(_Ty1 _Right, _Ty2 _Left)			: _Right(_Right), _Left(_Left)			{ 
			}		virtual void _MyT::Set(_Ty1 _Right, _Ty2 _Left) const			{ 
			_X_COMMON(_Right, _Left);			}		virtual void _MyT::Get(_Ty1 _Right, _Ty2 _Left) const			{ 
			_Right = this->_Right;			_Left = this->_Left;			}		_Ty1 _MyT::Right() const			{ 
			return _Right;			}		_Ty2 _MyT::Left() const			{ 
			return _Left;			}	protected:				_Ty1 _Right;		_Ty2 _Left;	};TEMPLATE<CLST _Ty>	
	CLST _X_Memory 		: public _X_Base<_Ty>, 		public _X_COMMON<_Ty, _Ty, _Ty*>		{		typedef _X_Memory<_Ty> _MyT;		typedef _X_COMMON<_Ty, _Ty, _Ty*> _MyC;		typedef typename _X_Base<_Ty>::Value_Type _MyVT;		typedef typename _X_Base<_Ty>::Arrays _MyAY;		typedef typename _X_Base<_Ty>::UnPointer _MyUP;		typedef typename _X_Base<_Ty>::Pointer _MyPI;		public:			_MyUP* alloc(_MyAY* Array, _MyVT size) const				{ 
				_MyC::Set(size, Array);				Array = new _MyAY[size];				return Array;				}			_MyUP* realloc(_MyAY* Array, const _MyVT nowsize, _MyVT size) const				{ 
				_MyC::Set(size, const_cast<_MyAY*> (Array));				_MyAY* buf = new _MyAY[size];				for(int f = 0; f <= nowsize; f++)					buf[f] = Array[f];				return buf;				}			void free(_MyAY* Array) const				{ 
				_MyC::Set(0, Array);				delete[] Array;				}		void fill(_MyAY* Array, const _MyAY fill_e, _MyVT size) const			{ 
			_MyC::Set(fill_e, const_cast<_MyAY*> (Array));			int sizex = size;			for ( int i = 0; i <= sizex; i++)				Array[i] = fill_e;			}	};TEMPLATE<CLST _Ty,	CLST _Vector,	CLST _Pointer = _Ty *,	CLST _Reference = _Ty&>	struct _X_Vector_Ty	{ 
	typedef _Vector Iterator;	typedef _Ty Value_Type;	typedef _Pointer Pointer;	typedef _Reference Reference;	};TEMPLATE<CLST _Ty, 	CLST _Vector = _Ty, 	CLST _Pointer = _Ty *,	CLST _Reference = _Ty&>	CLST _x_vector		: public _X_TYPE<_Ty>, 		public _X_COMMON<_Ty, _Ty, _Ty*>,		public _X_Memory<_Ty>,		public _X_Vector_Ty<_Vector, _Ty, _Pointer, _Reference>	{ 
	typedef _x_vector<_Ty, _Vector, _Pointer, _Reference> _MyT;	typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;	typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;	typedef typename _X_TYPE<_Ty>::Arrays _MyAY;	typedef typename _X_TYPE<_Ty>::UnPointer _MyUP;	typedef typename _X_TYPE<_Ty>::Pointer _MyPI;	public:	typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Iterator _VeIC;	
	typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Value_Type _VeT;	typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Pointer _VePI;	typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Reference _VeUP;	typedef typename _X_Memory<_Ty> _XM;	public:	explicit _x_vector()		: size(0), push_point(0)		{ 
		List = new _VeIC[sizeof(_VeIC)];		}	explicit _x_vector(int size)		: size(size+1), push_point(0)		{ 
		List = new _VeIC[this->size - 1];		}	~_x_vector()		{ 
		release();		}	_VePI resize(_VePI Array, _MyVT size)		{ 
		_MyC::Set(size, const_cast<_VePI> (Array));		_VePI buf = new _VeT[size];		for(int f = 0; f <= this->size; f++)			buf[f] = Array[f];		this->List = buf;		return buf;		}	void resize(_MyVT size)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		_VePI buf = new _VeT[size];		for(int f = 0; f <= this->size; f++)			buf[f] = List[f];		this->size = size;		this->List = buf;		}	_VeT operator[](size_t size) const		{ 
		return (this->List[size]);		}	void operator>>(int size)		{ 
		_MyC::Set(this->size, const_cast<_VePI> (List));		_VePI buf = new _VeT[this->size - size];		for(int i = 0; i <= size; i++)			buf[i] = List[i+size];		insertion(buf, this->size - size);		}	void operator<<(int size)		{ 
		_MyC::Set(this->size, const_cast<_VePI> (List));		_VePI buf = new _VeT[this->size + size];		for(int i = 0; i <= this->size; i++)			buf[i] = List[i];		insertion(buf, this->size + size);		}	void operator=(_MyT& _List)		{ 
			BEGIN_TRY		if((this->size && INT_MAX) <= 0) 			THROW_ERROR_INPUT(_List)		this->List = _List.List;		this->push_point = _List.push_point;		this->size = _List.size;			END_TRY			BEGIN_CATCH(_MyT _List)		throw 0;			END_CATCH		}	bool operator==(_MyT& _List)		{ 
		return _List.List == this->List;		}	bool operator!=(_MyT& _List)		{ 
		return _List.List != this->List;		}	bool operator<(_MyT& _List)		{ 
		return this->size < _List.size;		}		bool operator>(_MyT& _List)		{ 
		return this->size > _List.size;		}		bool operator<=(_MyT& _List)		{ 
		return this->size <= _List.size;		}		bool operator>=(_MyT& _List)		{ 
		return this->size >= _List.size;		}	_MyT* operator->()		{ 
		return this;		}	void swap(_MyT& _List)		{ 
		int size=_List.size, pp=_List.push_point;		_VeT* buf = new _VeT[_List.size];		buf = _List.List;		this->List = _List.List;		this->size = _List.size;		this->push_point = _List.push_point;		_List.size = size;		_List.new_vector(buf, size);		_List.push_point = pp;		}	void insertion(_VePI _List, int _Size)		{ 
		this->List = _List;		this->size = _Size;		this->push_point = _Size;		}	void clear()		{ 
			BEGIN_TRY		if((this->size && INT_MAX) == 0)			THROW_ERROR_INPUT(size)		release();		this->size = 0;		this->push_point = 0;			END_TRY			BEGIN_CATCH(int size)		throw 0;			END_CATCH		}	void push_back(_VeT data)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		resize(List, size + 1);		List[push_point++] = data;		size++;		}	void push_back(_MyT& data)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		for(int i = 0; i <= data.size; i++)			push_back(data.List[i]);		}	void push_back(_VeT* data, int size_)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		for(int i = 0; i <= size_; i++)			push_back(data[i]);		}	void push_front(_VeT data)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		_VePI buf = List;		resize(this->List, size + 1);		for(int i = 0; i<= size + 1; i++)			this->List[i + 1] = buf[i];		this->List[0] = data;		push_point++;		size++;		}	void push_front(_VeT* data, int size_)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		for(int i = 0; i <= size_; i++)			push_front(data[i]);		}	void push_front(_MyT& data)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		for(int i = 0; i <= data.size; i++)			push_front(data.List[i]);		}	_VeT pop()		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		_VeT pop = List[size - 1];		if (size>0){		resize(--size);		--this->push_point;}		return pop;		}	void pop_back()		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		_VeT pop = List[size - 1];		if (size>0){		resize(--size);		--this->push_point;}		}	void pop_front()		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		_VeT pop = this->List[0];		_VePI buf = this->List;		if (size>0)		{for(int i = 0; i<= size - 1; i++)			this->List[i - 1] = buf[i];		resize(--size);		--this->push_point;}		}	void fill(_VeT data)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		for(int i = 0; i <= size; i++)			List[i] = data;		}	void fill(size_t _point, _VeT data)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		for(int i = 0; i <= _point; i++)			List[i] = data;		}	void fill(_VeT data, size_t _point)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		for(int i = _point; i <= size; i++)			List[i] = data;		}	void fill(_VeT data, int _point, int size_)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		for(int i = _point; i <= size_; i++)			List[i] = data;		}	void reverse()		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		_VeT * buf = new _VeT[size];		int _size = size - 1;		for(int i = 0; i <= _size; i++)			buf[i] = pop();		size = 0;		for(int f = 0; f <= _size; f++)			push_back(buf[f]);		}	void sort()		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		int i, pass;		_VeT hold;		for(pass = 1; pass <= (size-1); pass++)		for(i = 0; i <= (size-2); i++)		if(List[i] > List[i + 1])		{hold = List[i];		List[i] = List[i + 1];		List[i + 1] = hold;}		}	void erase(int point, int size_)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		int _size = size - (size_ + 1);		_VePI buf = new _VeT[_size];		for(int i = 0, f = 0; i<=size; i++)		{if (point <= i <= (point+size_))continue;		buf[f++] = List[i];}		insertion(buf, _size);		}	void erase(int point)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		_VePI buf = new _VeT[size - 1];		for(int i = 0, f = 0; i < (size - 1); i++)		{if(i == point) continue;		buf[f++] = List[i];}		insertion(buf, size - 1);		}	void insert(int point, _VeT Data)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		_VePI buf = new _VeT[size + 1];		for(int i = 0; i < point; i++)buf[i] = List[i];		for(int f = point + 1; f <= size; f++)buf[f] = List[f];		buf[point] = Data;		insertion(buf, size+1);		}	void insert(int point, int size_, _VeT Data)		{ 
		_MyC::Set(size, const_cast<_VePI> (List));		_VePI buf = new _VeT[size + size_];		for(int i = 0; i < (size + size_); i++)		{if(point <= i < (point + size_)) buf[i] = Data;		buf[i] = List[i];}		insertion(buf, size + size_);		}	_VeT at(int point)		{ 
		if(point > size) 			THROW_ERROR_INPUT(size)		return List[point];		}	void assign(int n, _VeT Data)		{ 
		for(int i = 0; i < n; i++)			this->push_back(Data);		}	void asign(int n, int m, _VeT Data)		{ 
		for(int i = n; n <= m; i++)			List[i] = Data;		}	_VeT front() const		{ 
		return List[0];		}	_VeT back() const		{ 
		return List[size - 1];		}	int size_r() const		{ 
		return size - 1;		}	void new_vector()		{ 
		if(if_size())			release();		_X_Vector_Ex;		this->size = 0;		this->push_point = 0;		}	void new_vector(_VeT * _List, int size)		{ 
		_VePI listheap = new _VeT[size];		for(int i = 0; i <= size; i++)			listheap[i] = _List[i];		this->List = listheap;		}	bool if_size() const		{ 
		return (this->size && INT_MAX) > 0;		}	bool empty() const		{ 
		return size == 0;		}	void set_point(int point)		{ 
		if((point && INT_MAX) <= 0)			exit(0);		push_point = point;		}	void release() const		{ 
		_XM::free(List);		}	_VePI get_pi()		{ 
		return (this->List);		}	int get_pp()		{		return push_point;		}	private:	int size;	_VePI List;	int push_point;	};TEMPLATE<CLST _Ty,		 CLST _InputT = unsigned,		 CLST _Vector = _Ty, 		 CLST _Pointer = _Ty *,		 CLST _Reference = _Ty&>CLST _X_Mem_Controller	: public _X_TYPE<_Ty>, 	public _X_COMMON<_Ty, _Ty, _Ty*>,	
		public _X_Memory<_Ty>	{	typedef _X_Mem_Controller<_Ty> _MyT;	
#ifndef _USELESS_OF_COMMON	typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;	
#else	typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;	
#endif	
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;	
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;	typedef typename _Reference _MyUP;	typedef typename _Pointer _MyPI;	public:	typedef typename _X_Memory<_Ty> _XM;	public:			TEMPLATE<CLST _TyX>	_TyX& ForceChangeType(_MyPI& _Val)		{ 
		return reinterpret_cast<_TyX&>(_Val);		}	_InputT AddressOf(_MyPI& _Val)		{ 
		return reinterpret_cast<_InputT>(&			const_cast<_InputT&>			(ForceChangeType<const volatile _InputT>(_Val)));		}	_MyPI ForceArraySet(_MyPI array_, const _InputT set)		{ 
		if(!set)			return array_;		array_ = new _MyVT[set];		return array_;		}	_MyPI ForceArraySetWithKeep(const _MyPI array_, 			const _InputT arange, const _InputT set)		{ 
		_MyPI buf = new _MyVT[set];		for(COMMON_INCLASS_USEAGE_FOR)			buf[f] = array_[f];		return buf;		}	_MyPI Fill(_MyPI array_, _MyVT value, const _InputT arange)		{ 
		for(COMMON_INCLASS_USEAGE_FOR)			array_[n] = value;		return array_;		}	_MyPI ZeroMemory(_MyPI array_, const _InputT arange)		{ 
		for(COMMON_INCLASS_USEAGE_FOR)			array_[n] = 0;		return array_;		}	_MyPI Copying(_MyPI oper, const _MyPI array_, const _InputT arange)		{ 
		for(COMMON_INCLASS_USEAGE_FOR)			oper[n] = array_[n];		return oper;		}	_MyPI Moving(const _MyPI oper, _MyPI array_, const _InputT arange)		{ 
		for(COMMON_INCLASS_USEAGE_FOR)			array_[n] = oper[n];		ZeroMemory(oper, arange);		return oper;		}	_MyPI Swaping(_MyPI oper, _MyPI array_)		{ 
		_MyUP buf1 = *oper;		_MyUP buf2 = *array_;		oper = &buf2;		array_ = &buf1;		return oper;		}	_MyVT SwapVT(_MyVT oper, _MyVT array_)		{ 
		_MyVT buf = *oper;		*oper = *array_;		*array_ = buf;		return oper;		}	_InputT CountItem(_MyPI array_, _MyVT data, const _InputT arange)		{ 
		_InputT retbuf = 0;		for(COMMON_INCLASS_USEAGE_FOR)			if(array_[n] == data)				retbuf++;		return retbuf;		}	_InputT CountArray(_MyPI array_, _MyVT data, 			const _InputT first_array_size, const _InputT second_array_size)		{ 
		_InputT retbuf = 0;		_InputT startat;		bool state = false;		for(_InputT n = 0; n <= first_array_size; n++)			for(_InputT f = 0; f <= second_array_size; f++)				if(array_[n] == data[f]){					if(state)startat = array_[n];						retbuf++;if(retbuf == second_array_size) return startat;}					else{retbuf = 0;state = false;}		return 0;		}	void ReleaseArray(_MyPI array_, const _InputT array_size)		{ 
		for(_InputT n = 0; n <= array_size; n++)			delete array_[n];		delete[] array_;		}	void ReleaseArray(_MyPI array_)		{ 
		delete[] array_;		}	_MyPI PasteArray(_MyPI array_, _MyVT data, 			const _InputT first_array_size, const _InputT second_array_size)		{ 
		_MyPI buf = new _MyVT[first_array_size + second_array_size];		_InputT at = 0;		for(_InputT n = 0; n <= first_array_size; n++, at++)			buf[n] = array_[n];		for(_InputT n = 0; n <= second_array_size; n++)			buf[n + at] = data[n];		return buf;		}	void SetCommonArray(const _MyPI array_, const _InputT size)		{ 
		CommonArray = new _MyVT[size];		CommonSize = size;		Copying(CommonArray, array_, size);		}	_MyPI operator>>(const int shift_value)		{ 
		_MyPI buf = new _MyVT[CommonSize + shift_value];		for(int n = shift_value; n <= (CommonSize + shift_value); n++)			buf[n] = CommonArray[n - shift_value];		return buf;		}	_MyPI operator<<(const int shift_value)		{ 
		if(CommonSize < shift_value)			throw this*;		_MyPI buf = new _MyVT[CommonSize - shift_value];		for(int n = 0; n <= (CommonSize - shift_value); n++)			buf[n] = CommonArray[n + shift_value];		return buf;		}	_MyPI ReverseArray(_MyPI array_, const _InputT array_size)		{ 
		_MyPI buf = new _MyVT[array_size];		ZeroMemory(buf, array_size);		for(_InputT n = 0, f = array_size; n <= array_size; n++, f--)			buf[n] = array_[f];		return buf;		}	void Sort(_MyPI array_, const _InputT array_size)		{ 
		_MyVT hold;		for(_InputT pass = 1; pass <= (array_size-1); pass++)		for(_InputT i = 0; i <= (array_size-2); i++)		if(array_[i] > array_[i + 1])		{hold = array_[i];		array_[i] = array_[i + 1];		array_[i + 1] = hold;}		}	_MyPI CreateNewArray(_MyPI array_, const _InputT array_size)		{ 
		_MyPI buf = new _MyVT[array_size];		for(_InputT n = 0; n <= array_size; n++)			buf[n] = array_[n];		return buf;		}	_MyPI CreateNewArrayAndRelease(_MyPI array_, const _InputT array_size)		{ 
		_MyPI buf = new _MyVT[array_size];		for(_InputT n = 0; n <= array_size; n++)			buf[n] = array_[n];		ReleaseArray(array_, array_size);		return buf;		}	_MyPI CreateMemoryArray(const _InputT array_size)		{ 
		_MyPI buf = new _MyVT[array_size];		ZeroMemory(buf, array_size);		return buf;		}	_MyPI RedirectionMemoryC(_MyPI array_, const _InputT array_size, const _InputT redirection_address)		{ 
		_MyPI buf = new _MyVT[array_size];		_InputT bufc = AddressOf(array_);		buf = (*_MyVT)&redirection_address;		buf = (*_MyVT)&array_;		return buf;		}	_InputT GetPointerArraySize(_MyPI array_)		{ 
		_InputT ccc = sizeof(_MyPI);		_MyPI buf = CreateMemoryArray(0);		}	void* AllocateMemoryBlock(unsigned int Size)		{ 
		return malloc(Size);		}		void DeleteMemoryBlock(void** AddressOfBlock)		{ 
		if(*AddressOfBlock)		{free(*AddressOfBlock);		*AddressOfBlock = 0;}		}	void DeleteMemory(void* AddressOfBlcok)		{ 
		DeleteMemoryBlock((void**)&AddressOfBlcok);		}	bool ArrayFinder(_MyPI array_, _MyPI items ,			const _InputT first_array_size, const _InputT second_array_size)		{ 
		for(_InputT n = 0; n <= first_array_size; n++)		{for(_InputT f = 0; f <= second_array_size; f++)		if(array_[n] == items[f]) goto EX;		else if(f == second_array_size) return false;EX:}		return true;		}	bool MatchArray(_MyPI array_, _MyPI array__, const _InputT arange)		{ 
		for(COMMON_INCLASS_USEAGE_FOR)			if(array_[n] != array__[n]) return false;		return true;		}	_MyPI ReplaceArray(_MyPI array_, _MyVT e1, _MyVT e2, const _InputT arange)		{ 
		for(COMMON_INCLASS_USEAGE_FOR)			if(array_[n] == e1) array_[n] = e2;		return array_;		}	_MyPI ChangeVT(_MyPI array_, const _InputT pos1, const _InputT pos2)		{ 
		_MyVT buf = *array_[pos1];		*array_[pos1] = *array_[pos2];		*array_[pos2] = buf;		return array_;		}	private:		_MyPI CommonArray;		unsigned CommonSize;	};
TEMPLATE<CLST _Ty1, 	CLST _Ty2> inline	_Ty2 _First_Match(_Ty1 *_First, 		_Ty1 _Elem, _Ty2 _Size)	{ 
	for(int i = 0; i <= _Size; i++)		if(_First[i] == _Elem)			return i;	return 0;	}TEMPLATE<CLST _Ty1, 	CLST _Ty2> inline	_Ty2 _Last_Match(_Ty1 *_First, 		_Ty1 _Elem, _Ty2 _Size)	{ 
	for(int i = _Size; i; i--)		if(_First[i] == _Elem)			return i;	return 0;	}TEMPLATE<CLST _Ty1,	CLST _Ty2> inline	_Ty2 _Next_Match(_Ty1 *_First,		_Ty1 _Elem, _Ty2 _Size, _Ty2 _When)	{ 
	for(int i = _When + 1; i <= _Size; i++)		if(_First[i] == _Elem)			return i;	return 0;	}TEMPLATE<CLST _Ty1,	CLST _Ty2> inline	_Ty2 _Count(_Ty1 *_First, 		_Ty1 _Elem, _Ty2 _Size)	{ 
	int _Temp = 0;	for(int i = 0; i <= _Size; i++)		if(_First[i] == _Elem)			_Temp++;	return _Temp;	}TEMPLATE<CLST _Ty1,																		 	CLST _Ty2> inline	_Ty2 _Search_C(_Ty1 *_First, _Ty1 *_Last, 		_Ty2 _FSize, _Ty2 _LSize)	{ 
	int _Iteior = _First_Match(_First, *_Last, _FSize);	if(_Iteior)		for( ; _Iteior <= _FSize; _Iteior++)			for(int i = 0; i <= _LSize; i++)				if(_First[_Iteior] != _Last[i])					goto _Ex;				else if(i == _LSize)					return _Iteior;_Ex:	_Iteior = _Next_Match(_First, *_Last, _FSize, _Iteior);	if(_Iteior)		for( ; _Iteior <= _FSize; _Iteior++)			for(int i = 0; i <= _LSize; i++)				if(_First[_Iteior] != _Last[i])					goto _Ex;				else if(i == _LSize)					return _Iteior;	return 0;	}TEMPLATE<CLST _Ty0> inline	void ptrcat(_Ty0 *_left, const _Ty0 *_right)	{ 
	char *ptr = _left;	while(*ptr)		ptr++;	
	while(*ptr++ = *_right++)			;	return (_left);	}TEMPLATE<CLST _Ty0> inline	void ptrcpy(_Ty0 *_left, const _Ty0 *_right)	{ 
	char *ptr = _left;	while(*ptr++ = *_right++)			;	return (_left);	}TEMPLATE<CLST _Ty0> inline	int ptrlen(_Ty0 *_left)	{ 
	_Ty0 *ptr = _left;	while(*ptr++)			;	return (ptr - _left - 1);	}	
TEMPLATE<CLST _Ty0 = int>	CLST inc_num	{ 
	_Ty0 what;public:	inc_num(_Ty0 f)		: what(f)		{}	inc_num()		{what = (_Ty0)0;}	_Ty0 operator()()		{ 
		return what++;}	};TEMPLATE<CLST _Ty0 = int>	CLST dec_num	{ 
	_Ty0 what;public:	dec_num(_Ty0 f)		: what(f)		{}	_Ty0 operator()()		{ 
		return what--;}	};TEMPLATE<CLST _Ty2, CLST _Func> inline	void func_cross_fleft(_Ty2& that, 		int line, int queue, _Func& what)	{ 
	for(int i = 0, f = 0; i <= line && f <= queue; i++, f++)		that[i][f] = what();	}TEMPLATE<CLST _Ty2, CLST _Func> inline	void func_cross_fright(_Ty2& that, 		int line, int queue, _Func& what)	{ 
	for(int i = 0, f = queue; i <= line && f >= 0; i--, f++)		that[i][f] = what();	}TEMPLATE<CLST _Ty2, CLST _Func> inline	void func_cross_lleft(_Ty2& that, 		int line, int queue, _Func& what)	{ 
	for(int i = line, f = 0; i >= 0 && f <= queue; i--, f++)		that[i][f] = what();	}TEMPLATE<CLST _Ty2, CLST _Func> inline	void func_cross_lright(_Ty2& that, 		int line, int queue, _Func& what)	{ 
	for(int i = line, f = queue; i >= 0 && f >= 0; i--, f--)		that[i][f] = what();	}TEMPLATE<CLST _Ty3, CLST _Func> inline	void func_cross_fx(_Ty3& that, 		int line, int queue, _Func& what)	{ 
	for(int i = 0, f = 0; i <= line && f <= queue; i++, f++){		that[i][f] = what();		if(f != queue - f)			that[i][queue - f] = what();		}	}TEMPLATE<CLST _Ty3, CLST _Func> inline	void func_cross_lx(_Ty3& that,		int line, int queue, _Func& what)	{ 
	for(int i = line, f = queue; i >= 0 && f >= 0; i--, f--){		that[i][f] = what();		if(f != queue - f)			that[i][queue - f] = what();		}	}TEMPLATE<CLST _Ty7, CLST _Func> inline	void func_tetragon(_Ty7& that,		int line, int queue, _Func& what, 			const int depth = 0)	{ 
	for(int i = depth, f = depth, g = 0; g == 0 ? f <= queue - depth : 		g == 1 ? i <= line - depth :g == 2 ? f >= depth : i >= depth + 		1; g == 0 ? f++ : g == 1 ? i++ : g == 2 ? f-- : i--,f == queue 		- depth && g == 0 ? that[i][f] = what(), g = 1, i = depth + 1, 		f = queue - depth : i == line - depth && g == 1 ? that[i][f] = 		what(), g = 2, i = line - depth, f -= 1 :f == depth && g == 2 		? that[i][f] = what(), g = 3, f = depth, i -= 1 : 0)		that[i][f] = what();	}TEMPLATE<CLST _Ty8, CLST _Func> inline	void func_snail(_Ty8& that,		int line, int queue, _Func& what, 			int depth)	{ 
	for(int z = 0; z <= depth; z++)		for(int i = z, f = z, g = 0; g == 0 ? f <= queue - z : 			g == 1 ? i <= line - z :g == 2 ? f >= z : i >= z + 			1; g == 0 ? f++ : g == 1 ? i++ : g == 2 ? f-- : i--,f == queue 			- z && g == 0 ? that[i][f] = what(), g = 1, i = z + 1, 			f = queue - z : i == line - z && g == 1 ? that[i][f] = 			what(), g = 2, i = line - z, f -= 1 :f == z && g == 2 			? that[i][f] = what(), g = 3, f = z, i -= 1 : 0)		that[i][f] = what();	}TEMPLATE<CLST _Ty8, CLST _Ty0> inline	void snail_sort(_Ty8& that,		int line, int queue, _Ty0& what, 			int depth)	{ 
	for(int z = 0; z <= depth; z++)		for(int i = z, f = z, g = 0, h = 0; g == 0 ? f <= queue - z : 			g == 1 ? i <= line - z :g == 2 ? f >= z : i >= z + 			1; g == 0 ? f++ : g == 1 ? i++ : g == 2 ? f-- : i--,f == queue 			- z && g == 0 ? that[i][f] = what[h++], g = 1, i = z + 1, 			f = queue - z : i == line - z && g == 1 ? that[i][f] = 			what[h++], g = 2, i = line - z, f -= 1 :f == z && g == 2 			? that[i][f] = what[h++], g = 3, f = z, i -= 1 : 0, h++)		that[i][f] = what[h];	}TEMPLATE<CLST _Ty6, CLST _Func> inline	void func_half_tetragon(_Ty6& that,		int line, int queue, _Func& what, 			int depth = 0)	{ 
	for(int i = depth, f = depth, k = 0; k == 0 ? f <= queue - depth : 		(k == 1 ? i <= line - depth : (k == 2 ? f >= depth : i >= 		depth + 1)); k == 0 ? f++ : (k == 1 ? i++ : (k == 2 ? f-- : i--)		), k == 0 && !(f <= queue - depth) ? k = 1, i = depth + 1, f = 		queue - depth : (k == 1 && !(f = queue - depth) ? k = 2, i = line 		- depth, f -= 1 : k == 2 && !(f >= depth) ? f = depth, i -= 1 : 0 ))		that[i][f] = what();	}TEMPLATE<CLST _Ty0> inline	int chartoint(_Ty0 *i)	{ 
	int ret = 0;	for( ; *i; )		ret = 10 * ret + (*i++ - '0');	return ret;	}TEMPLATE<CLST _Ty0> inline	_Ty0 solver_x_intonly(const char *f_x, _Ty0 value)	{ 
	const char *fx_p = f_x;	char savt[21] = {0, };	char *p_avt = savt;	bool t = false;	_Ty0 returning = 0, last;	while(*fx_p)		{			if(t)				if('0' <= *fx_p && *fx_p <= '9')					*p_avt++ = *fx_p;				else				{					last = chartoint(savt);					t = false;					for(int i = 0; i <= 20; i++)						savt[i] = 0;					p_avt = savt;				}			if(('0' <= *fx_p && *fx_p <= '9') && !t)				*p_avt++ = *fx_p,				t = true;			else 				switch(*fx_p)				{				case '+':					returning += last;					break;				case '-':					returning -= last;					break;				case '*':					returning *= last;					break;				case '/':					returning /= last;					break;				case 'x':					last = value;					break;				}			*fx_p++;		}	return returning;	}TEMPLATE <typename _AxList> 	size_t __length(const _AxList *_T)    { 
	const _AxList *_Ptr = _T;	for( ; *_Ptr; _Ptr++)		;	return (_Ptr - _T - 1);    }TEMPLATE<typename _ApLock>	_ApLock *__alloc(size_t _Size, _ApLock *)	{ 
	void *_Ptr = 0;	if(_Ptr = new _ApLock(_Size * sizeof(_ApLock)))		;	else		_Ptr = 0;	return ((_ApLock *)(_Ptr));	}TEMPLATE<typename _EnLock>	_EnLock *__realloc(_EnLock *_Origin, size_t _Size_origin, size_t _Size)	{ 
	_EnLock *_Ptr = __alloc(_Size, _Origin);	if(_Size_origin >= _Size)		for(int i = 0; i < _Size_origin; i++)			_Ptr[i] = _Origin[i];	else		for(int i = 0; i < _Size; i++)			_Ptr[i] = _Origin[i];	return _Ptr;	}TEMPLATE<CLST _Ty> inline	_Ty *AddressOf(_Ty& _Val)	{	
	return (reinterpret_cast<_Ty *>(		(&const_cast<char&>(		reinterpret_cast<const volatile char&>(_Val)))));	}/*============================================================================		1 Generation Pointer/ Address============================================================================*/TEMPLATE<CLST _AxList, 	CLST _Accerlates = _AxList *> CLST	___tg1_lock_ptr	{ 
public:	static inline _Accerlates Lock(_AxList& _px)		{ 
		_Accerlates _x = reinterpret_cast<_Accerlates>			(&reinterpret_cast<char &> (_px));		return _x;		}	static inline _AxList& UnLock(_Accerlates _tx)		{ 
		return *reinterpret_cast<_AxList *> (_tx);		}	};TEMPLATE<CLST _AxList> CLST	___tg1_memory_ptr	{ 
	int lock_ptr;public:	inline void Put(_AxList *ptr)		{ 
		lock_ptr = __Lock_Int(_AxList *)Lock(ptr);		}	inline _AxList *Get()		{ 
		return __Lock_Int(_AxList *)UnLock(lock_ptr);		}	};TEMPLATE<CLST _AxList> CLST	___tg1_argv_ptr	{ 
	int *xt;	size_t xtsize;	typedef ___tg1_argv_ptr<_AxList> __AxTG8;public:	___tg1_argv_ptr()		: xt(0), xtsize(0)		{ 
		xt = __alloc(0, xt);		}	inline __AxTG8& operator<<(int Lx)		{ 
		xt = __realloc(xt, xtsize, xtsize + 1);		xt[xtsize] = Lx;		_INCREASE(xtsize);		return *this;		}	TEMPLATE<typename _LxType>		inline __AxTG8& operator<<(_LxType& Lx)		{ 
		xt = __realloc(xt, xtsize, xtsize + 1);		xt[xtsize] = __Lock_Int(_LxType)Lock(Lx);		_INCREASE(xtsize);		return *this;		}	__AxTG8& operator<<(__AxTG8*& Lx)		{ 
		xt = __realloc(xt, xtsize, xtsize + Lx->xtsize);		xtsize += Lx->xtsize;		for(int i = 0; i < Lx->xtsize; i++)			xt[xt - Lx->xtsize + i] = Lx->xt[i];		return *this;		}	TEMPLATE<typename _LxType>		inline _LxType getptr(int ghj)		{ 
		return __Lock_Int(_LxType)UnLock(xt[ghj]);		}	size_t operator*()		{ 
		return xtsize;		}	};/*============================================================================		2 Generation Pointer/ Array============================================================================*/TEMPLATE<CLST _AxList> CLST	___tg2__e_array	{ 
	_AxList *Ptr_ts;	_AxList *ts_ptr;	size_t size;	typedef ___tg2__e_array<_AxList> __AxTG9;public:	___tg2__e_array() : Ptr_ts(0), size(0)		{ 
		}	__AxTG9& operator<<(_AxList x)		{ 
		push_front(x);		return *this;		}	__AxTG9& operator>>(_AxList x)		{ 
		push_back(x);		return *this;		}	void operator()(int y)		{ 
		__realloc(Ptr_ts, size, y);		}	_AxList& operator[](int xt)		{ 
		return Ptr_ts[xt];		}	void operator++()		{ ts_ptr++; }	void operator--()		{ ts_ptr--; }	_AxList operator*()		{ return *ts_ptr; }	_AxList& operator&()		{ return *ts_ptr; }	void operator^(int y)		{ return ts_ptr[y]; }	_AxList* getptr()		{ return Ptr_ts; }	void init()		{ delete[] Ptr_ts; ts_ptr = 0; }	void push_front(_AxList t)		{ 
		_AxList *Ptr_C = __alloc(size + 1, Ptr_ts);		for(int i = 0; i < size; i++)			Ptr_C[i + 1] = Ptr_ts[i];		_INCREASE(size);		*Ptr_C = t;		Ptr_ts = Ptr_C;		}	void push_back(_AxList t)		{ 
		_AxList *Ptr_C = __alloc(size + 1, Ptr_ts);		for(int i = 0; i < size; i++)			Ptr_C[i] = Ptr_ts[i];		_INCREASE(size);		Ptr_C[size] = t;		Ptr_ts = Ptr_C;		}	};/*============================================================================		3 Generation Pointer/ Linked List		(Under Construction.)============================================================================*/
TEMPLATE<CLST linked_type>	CLST _Node	{ 
public:	_Node *_NextPtr; 
	_Node *_PrevPtr; 
	size_t _Key;	linked_type _data;	};
TEMPLATE<CLST linked_type>	CLST ___tg3__e_link	{ 
	typedef typename _Node<linked_type> _MyNode;	_MyNode *_Head;	_MyNode *_Tail;	_MyNode *_Lastest;	size_t point;	int sizeofit;public:	___tg3__e_link()		: _Head(0), _Tail(0), point(-1), sizeofit(0)		{ 
		_Head = _New_Node();		_Tail = _New_Node();		_Init(_Head, _Tail);		}	bool operator++(int)		{ 
		if (point < sizeofit-1 || point == -1)		{			point++;			return true;		}		point = -1;		return false;		}	bool operator--(int)		{ 
		if(point)		{			point--;			return true;		}		return false;		}	bool operator+(int _left)		{ 
		point += _left;		return true;		}	bool operator-(int _left)		{ 
		if(point >= _left)		{point -= _left;		return true;}		return false;		}	_MyNode *_New_Node()		{ 
		_MyNode *ptr = new _MyNode(sizeof(_MyNode));		return ptr;		}	_MyNode* operator*()		{ 
		_MyNode *temp = _Head;		if (!point)			return temp->_NextPtr;		else 			while(temp->_Key != point && temp != _Tail)				temp = temp->_NextPtr;		return temp;		}	_MyNode& operator&()		{ 
		_MyNode *temp = _Head;		if (!point)			;		else 			while(temp->_Key != point && temp != _Tail)				temp = temp->_NextPtr;		return temp;		}	void push_back(linked_type _left)		{ 
		_MyNode *temp = _New_Node();		temp->_Key = sizeofit;		temp->_data = _left;		if (sizeofit)			_Connect(_Lastest, temp, _Tail);		else			_Connect(_Head, temp, _Tail);		_Lastest = temp;		sizeofit++;		}	void _Connect(linked_type _head, linked_type _target, linked_type _tail)		{ 
		_head->_NextPtr = _target;		_target->_NextPtr = _tail;		}	linked_type pop_back()		{ 
		_MyNode *temp = _Head;		linked_type prev;		while(temp->_NextPtr != _Tail)		{			temp = temp->_NextPtr;			prev = temp->_data;		}		temp->_NextPtr = _Tail;		delete temp;		sizeofit--;		return prev;		}	};TEMPLATE<CLST _ptr> int 	ptrlen(const _ptr *x)	{ 
	const char *len = x;	while(*len++)		;	return len - x - 1;	}TEMPLATE<CLST _ptr> _ptr*&	ptrset(_ptr*& _Dst, int _Val, int _Size)	{ 
	for(int i = 0; i < _Size; i++)		(((char *)(void *)(_Dst))[i]) = _Val;	return _Dst;	}TEMPLATE<CLST _ptr> bool	isnull(_ptr*& _Dst)	{ 
	return *(char *)(void *)(_Dst) == 0;	}int strcmp_x(const char * src, const char * dst)	{ 
	int ret = 0;	while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)		++src, ++dst;	if ( ret < 0 )		ret = -1;	else if ( ret > 0 )		ret = 1;	return( ret );	}TEMPLATE<CLST Key = char *, CLST Value = Key>	struct xh_link	{ 
public:	Key key;	Value value;	struct xh_link* next;	};TEMPLATE<CLST Value>	struct xh_ll	{ 
public:	struct xh_ll* next;	Value value;	struct xh_ll* prev;	};TEMPLATE<CLST Value>	struct xh_modll	{ 
public:	struct xh_ll<Value>* _HEAD;	struct xh_ll<Value>* _CURR;	struct xh_ll<Value>* _TAIL;	};TEMPLATE<CLST Key = char *, CLST Value = Key>	struct xh_table	{ 
public:	xh_link<Key, Value> **table;	int t_size;	};TEMPLATE<CLST Key = char *, CLST Value = Key, int Size = 0xFFFF>	CLST hash	{ 
	typedef struct xh_table<Key, Value> xt;	typedef struct xh_link<Key, Value> xl;	typedef struct xh_link<Key, Value> *xlp;	typedef xh_table<Key, Value>* hash_table;	hash_table ht;public:	hash()		{ 
		ht = new xt;		ht->t_size = Size;		ht->table = new xlp[Size];		ptrset(ht->table, 0, sizeof(xlp) * Size);		}	~hash()		{ 
		delete[] ht->table;		delete ht;		}	xl*& operator[](Key key)		{ 
		int addr = hf(key);		xl* x = ht->table[addr];		xl* t;		if(ht->table[addr] == NULL){			xl* nn = cn(key);			ht->table[addr] = nn;			return ht->table[addr];}		while(x != NULL){			t = x;			if(strcmp_x(x->key, key) == 0)				break;			x = x->next;}		if(!x){			xl* nn = cn(key);			nn->next = ht->table[addr];			ht->table[addr] = nn;			return ht->table[addr];}		return x;		}private:	int hf(const char *key)		{ 
		int k = ptrlen(key), j = 0;		for(int i = 0; i < k; i++)			j = j << ((ht->t_size ^ (0x31 | i)) + 3) + key[i];		return j % ht->t_size;		}	xl* cn(char *key)		{ 
		xl* nn = new xl;		nn->key = key;		nn->next = NULL;		return nn;		}	};int __strncmp(const char *first, const char *last, size_t count)	{ 
	size_t x = 0;	if (!count)		return 0;	if( count >= 4 )		for (; x < count-4; x+=4)			{		first+=4;		last +=4;		if (*(first-4) == 0 || *(first-4) != *(last-4))			return(*(unsigned char *)(first-4) - *(unsigned char *)(last-4));		if (*(first-3) == 0 || *(first-3) != *(last-3))			return(*(unsigned char *)(first-3) - *(unsigned char *)(last-3));		if (*(first-2) == 0 || *(first-2) != *(last-2))			return(*(unsigned char *)(first-2) - *(unsigned char *)(last-2));		if (*(first-1) == 0 || *(first-1) != *(last-1))			return(*(unsigned char *)(first-1) - *(unsigned char *)(last-1));			}	for (; x < count; x++, first++, last++)		if (*first == 0 || *first != *last)			return(*(unsigned char *)first - *(unsigned char *)last);	return 0;	}TEMPLATE<CLST _Val, _Val x>	struct _exp	{	static const _Val value = x;	operator _Val()		{			return x;		}	};TEMPLATE<bool>	struct __Cat_base		: _exp<bool, false>	{	};TEMPLATE<>	struct __Cat_base<true>		: _exp<bool, true>	{	};TEMPLATE<typename _Ty> 	struct _Is_String		: _exp<bool, false>	{	};TEMPLATE<> 	struct _Is_String<char *>		: _exp<bool, true>	{	};TEMPLATE<typename _Ty> 	struct _Is_Unicode		: _exp<bool, false>	{	};TEMPLATE<> 	struct _Is_Unicode<unsigned char *>		: _exp<bool, true>	{	};TEMPLATE<typename _Ty>	struct _rm_cst	{	typedef _Ty type;	};TEMPLATE<typename _Ty>	struct _rm_cst<const _Ty>	{	typedef _Ty type;	};TEMPLATE<CLST _Ty>	struct _rm_cst<const _Ty[]>	{	
		typedef _Ty type[];	};TEMPLATE<CLST _Ty>	struct _rm_ref	{	typedef _Ty type;	};TEMPLATE<CLST _Ty>	struct _rm_ref<_Ty&>	{	typedef _Ty type;	};TEMPLATE<CLST _Ty>	struct _rm_ref<_Ty&&>	
	{	typedef _Ty type;	};TEMPLATE<typename _Ty>	struct is_pointer		: __Cat_base<			_Is_String<_Ty>::value 				|| _Is_Unicode<				_Ty>::value>	{	};TEMPLATE<CLST _Category = char *, 		int _Size = 0xFFFF, 		int _CSize = 0xFF>CLST	_category_scr	{ 
	typedef typename _rm_cst<_Category>::type _MyPtr;	typedef hash<_MyPtr, _MyPtr, _Size>* _MyHash;	_MyHash category;	is_pointer<_MyPtr> _Capture;public:	_category_scr()		{			if( _Capture )				category = new hash<_MyPtr, _MyPtr, _Size>[_CSize];		}	~_category_scr()		{			delete[] category;		}	hash<_MyPtr, _MyPtr, _Size> &		operator[] ( const _MyPtr key )		{			int addr = hf( key );			return category [ addr ];		}private:		int hf( const _MyPtr key )		{ 
			int k = ptrlen( key ), j = 2166136261;			for( int i = 0;  i < k;  i++ )				j  =  ( ( j  *  16777619 )  ^  key[i] ) ;			return ( j ^ ( j >> 3 ) ) % _CSize;		}	};int strmch(char first[], char last[]){	int first_len = ptrlen(first), last_len = ptrlen(last);	for(int i = 0; i <= first_len - last_len; i++)		if(!__strncmp(first + i, last, last_len))			return i;	return (-1);}int strmch_rk(char first[], char last[]){	int first_len = ptrlen(first), last_len = ptrlen(last), t = 1, l1 = 0, l2 = 0;	for(int i = 0; i < last_len - 1; i++)	
			t = (t * 0xff) % 123;	for(int i = 0; i < last_len; i++)		l1 = (l1 * 0xff + first[i]) % 123, l2 = (l2 * 0xff + last[i]) % 123;	for(int i = 0, j = 0; i <= first_len - last_len; i++){		if(l1 == l2 && !__strncmp(first + i, last, last_len))			return i;		j = (l1 - first[i] * t) % 123;		if(j < 0)			j += 123;		l1 = (j * 0xff + first[i + last_len]) % 123;}	return (-1);}int strmch_mp(char first[], char last[]){	int t[0xff];	int first_len = ptrlen(first), last_len = ptrlen(last);	*t = -1;	for(int i = 1, j = -1; i < last_len; i++){		while(j >= 0 && last[j + 1] != last[i])			j = t[j];		if(last[j + 1] == last[i])			j++;		t[i] = j;}	for(int i = 0, j = -1; i < first_len; i++){		while(j >= 0 && last[j + 1] != first[i])			j = t[j];		if(last[j + 1] == first[i])			j++;		if(j == last_len - 1)			return i - last_len + 1;}	return (-1);}typedef char * va_list;int sprintf_r(	char * str,	const char * format, 	... 	)/* Print Formatted String */{	int i;		/*	ptr counter			*/	int valid;	/*	integer temp		*/_U	int uvalid;	/*	uinteger temp		*/	int tp;		/*	con-valid value		*/_U	int utp;	/*	ucon-valid value	*/	int pd;		/*	format option		*/	int pt;		/*	str count			*/	int sign;	/*	integer sign		*/	int ps;		/*	minus sign			*/	int n;		/*	n counter			*/	int px;		/*	zero sign			*/	int num;	/*	number system		*/	va_list _VAL;	
			char *sptr;	const char * _temp;	const char * _ptr;	_VALIATED_RETURN( ( _ptr = format ), 
			_EOFSETUP, (-1) ) ;	i = 0;	sign = 0;	ps = 0;	n = 0;	px = 0;	num = 0;	sptr = str;	va_start( _VAL, format ) ;/* printf-format-strings */	while(_ptr[i] != '\0' && *_ptr)	{		switch(_ptr[i])		{		case '\\':			put(_ptr[++i]);			break;		case '%':			gb_s:			switch(_ptr[i + 1])			{			case '\#':				sprintf_r(sptr, "0x");				n += 2;				goto gb_t;			case '\+':				sign = 1;				goto gb_t;		
			case '\-':				ps = 1;				goto gb_t;			case '0':				px = 1;gb_t:				i++;				goto gb_s;			}			for(pd = 0 ; *forward; i++)				if( '0' <= *forward && *forward <= '9' )					pd = pd * 10 + *forward - '0';				else				{					i++;					break;				}			switch(_ptr[i])			{			case 'd': /* STD Output of Integer */				num = 8;			case 'b': /* STD Output of Binary */				num ^= 10;			case 'o': /* STD Output of Octal Digit */				num ^= 8;				valid = va_arg( _VAL, int );				if(!valid)				{					put('0');					break;				}				for( tp = 0, pt = 0; valid; valid /= num, pt++ )					tp = tp * num + valid % num;								if(sign)				{					
			if( tp > 0 )						put('+');					else if( tp < 0 )						put('-');					sign = 0;				}				if(!pd)					for( ; pt; tp /= num, pt-- )						put((char)(tp % num + '0'));				else					if(pt > pd)					{						for( ; pt; tp /= num, pt--)							if(!(pt > pd))								put((char)(tp % num + '0'));					}					else if(pt <= pd)					{						if(ps && pt != pd)						{							for( ; pt; tp /= num, pt--, pd--)								put((char)(tp % num + '0'));							if(!px)								for( ; pd; pd--)									put(' ');							else								for( ; pd; pd--)									put('0');							ps = 0;						}						else						{							if(!px)								for( ; pt != pd; pd--)									put(' ');							else								for( ; pt != pd; pd--)									put('0');							for( ; pd; tp /= num, pd--)								put((char)(tp % num + '0'));						}					}									num = 0;				break;							case 'u': /* EX-STD Output of UInteger */			case 'D': /* EX-STD Output of UInteger */	
			num = 8;			case 'B': /* EX-STD Output of UBinary */				num ^= 10;			case 'O': /* EX-STD Output of UOctal Digit */				num ^= 8;				uvalid = va_arg( _VAL, unsigned int );				if(!uvalid)				{					put('0');					break;				}				for( utp = 0, pt = 0; uvalid; uvalid /= num, pt++ )					utp = utp * num + uvalid % num;								if(sign)				{					if( utp > 0 )						put('+');					else if( utp < 0 )						put('-');					sign = 0;				}				if(!pd)					
			for( ; pt; utp /= num, pt-- )						put((char)(utp % num + '0'));				else					if(pt > pd)					{						for( ; pt; utp /= num, pt--)							if(!(pt > pd))								put((char)(utp % num + '0'));					}					else if(pt <= pd)					{						if(ps && pt != pd)						{							for( ; pt; utp /= num, pt--, pd--)								put((char)(utp % num + '0'));							if(!px)								for( ; pd; pd--)									put(' ');							else								for( ; pd; pd--)									put('0');							ps = 0;						}						else						{							if(!px)								for( ; pt != pd; pd--)									put(' ');							else								for( ; pt != pd; pd--)									put('0');							for( ; pd; utp /= num, pd--)								put((char)(utp % num + '0'));						}					}									num = 0;				break;			case 'c': /* STD Output of Character */				
			valid = va_arg( _VAL, char );				put(valid);				break;			case 's': /* STD Output of String */								_temp = va_arg( _VAL, char * );				if(!pd)					for( ; *_temp; _temp++)						put(*_temp);				else				{					for(pt = 0; _temp[pt]; pt++)						;					if(pt > pd)					{						for( ; pt && *_temp; _temp++, pt--)							if(!(pt > pd))								put(*_temp);					}					else if(pt <= pd)					{						for( ; pt != pd; pd--)							put(' ');						for( ; *_temp; _temp++)							put(*_temp);					}				}				break;			case 'x': /* STD Output of Integer to Hex */				valid = va_arg( _VAL, int );				if(!valid)				{					put('0');					break;				}		
			if(sign)				{					if( tp > 0 )						put('+');					else if( tp < 0 )						put('-');					sign = 0;				}								for( tp = 0, pt = 0; valid; valid /= 16, pt++ )					tp = tp * 16 + valid % 16;								if(!pd)					for( ; pt; tp /= 16, pt-- )						put((char)((tp % 16 < 0xa) ? (tp % 16 + '0') : (tp % 16 - 0xa + 'a')));				else					if(pt > pd)					{						for( ; pt; tp /= 16, pt--)							if(!(pt > pd))								put((char)((tp % 16 < 0xa) ? (tp % 16 + '0') : (tp % 16 - 0xa + 'a')));					}					else if(pt <= pd)					{						if(ps && pt != pd)						{							for( ; pt; tp /= 16, pt--, pd--)								put((char)((tp % 16 < 0xa) ? (tp % 16 + '0') : (tp % 16 - 0xa + 'a')));							if(!px)								for( ; pd; pd--)									put(' ');							else								for( ; pd; pd--)									put('0');							ps = 0;						}						else						{							if(!px)								for( ; pt != pd; pd--)									put(' ');							else								for( ; pt != pd; pd--)									put('0');							for( ; pd; tp /= 16, pd--)								put((char)((tp % 16 < 0xa) ? (tp % 16 + '0') : (tp % 16 - 0xa + 'a')));						}					}				break;			case 'n': /* EX-STD Write value of Current string length  */				*va_arg( _VAL, int * ) = n;								break;			case 'p': /* STD Output of Pointer to Hex */				valid = va_arg( *&_VAL, int );								n += sprintf_r(sptr, "%x", valid);				break;			default:				_NONE_ACTIVE			}			break;		default:			put(_ptr[i]);		}		i++;	}	va_end( _VAL) ;		return n;}int GetFileSize(	FILE *fp	)/* Get File Size */{	fseek(fp, 0, SEEK_END);	return ftell(fp);}int ReadFileData(	void * buffer,	FILE *fp	)/* Read File Data */{	int file_size;	file_size = GetFileSize(fp);
			fseek(fp, 0, SEEK_SET);	fread(buffer, file_size, 1, fp);	return 0;}int CopyFileData(	FILE *fp_target,	FILE *fp_sniper	)/* Copy File Data */{	char buf[0x400];	while(!feof(fp_target))		fgets(buf, 0x400, fp_target),		fputs(buf, fp_sniper);	return 0;}TEMPLATE<CLST _Ty0 = char>	CLST str_n	{ 
	vector<_Ty0> str;	bool reverses;	unsigned int point;public:	str_n()		: reverses(false), point(0)		{ }	str_n(_Ty0 *_valuable_char)		: reverses(false), point(0)		{ 
		char_put(_valuable_char);		}	str_n(const _Ty0 *_const_char)		: reverses(false), point(0)		{ 
		char_put(const_cast<_Ty0 *> 			(_const_char));		}	inline _Ty0& operator[](int pos)		{ 
		if(!reverses)			return str[pos];		else			return str(pos);		}	inline _Ty0& operator()(int pos)		{ 
		if(reverses)			return str[pos];		else			return str(pos);		}	inline _Ty0*& operator()()		{ 
		int len = lenth();		_Ty0 *ret = new _Ty0[len];		if(!reverses)			for(int n = 0; n < len; n++)				ret[n] = str[n]->_DATA;		else			for(int n = 0; n < len; n++)				ret[n] = str(n)->_DATA;		ret[len] = 0;		return ret;		}	inline void reverse()		{ 
		reverses = true;		}	inline int lenth()		{ 
		return str.size();		}	void operator++()		{ 
		point++;		}	void operator--()		{ 
		point--;		}	_Ty0& operator*()		{ 
		if(!reverses)			return str[point];		else			return str(point);		}	inline vector<_Ty0> &ch_n()		{ 
		return str;		}	str_n<_Ty0> &operator<<(_Ty0 *get)		{ 
		char_put(get);		return *this;		}	str_n<_Ty0> &operator<<(const _Ty0 *get)		{ 
		char_put(const_cast<_Ty0*> (get));		return *this;		}	str_n<_Ty0> &operator<<(str_n<_Ty0> &get)		{ 
		char_put(*get);		return *this;		}	str_n<_Ty0> &operator<<(_Ty0 &get)		{ 
		if(!reverses)			str.push_back(get);		else			str.push_front(get);		return *this;		}	str_n<_Ty0> &operator>>(_Ty0 *get)		{ 
		char_put_r(get);		return *this;		}	str_n<_Ty0> &operator>>(const _Ty0 *get)		{ 
		char_put_r(const_cast<_Ty0*> (get));		return *this;		}	str_n<_Ty0> &operator>>(str_n<_Ty0> &get)		{ 
		char_put_r(*get);		return *this;		}	str_n<_Ty0> &operator>>(_Ty0 &get)		{ 
		if(!reverses)			str.push_front(get);		else			str.push_back(get);		return *this;		}private:	inline int strlen(_Ty0 *that)		{ 
		for( int i = 0; ; )			if(!that[++i])				return i;		}	inline void char_put(_Ty0 *_char)		{ 
		int f = strlen(_char);		if(!reverses)			for(int i = 0; i < f; i++)				str.push_back(_char[i]);		else			for(int i = 0; i < f; i++)				str.push_front(_char[i]);		}	inline void char_put_r(_Ty0 *_char)		{ 
		int f = strlen(_char);		if(!reverses)			for(int i = 0; i < f; i++)				str.push_front(_char[i]);		else			for(int i = 0; i < f; i++)				str.push_back(_char[i]);		}	};_ADK_END