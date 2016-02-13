/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						ALLOCATOR COLLECTION
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _ALLOCATOR_COLLECTION_
#define _ALLOCATOR_COLLECTION_

#include <new>

	//
	//	Ultra Array Value Structure
	//
#define _ALLOCATOR_NORMAL		0

#ifdef _AC_CUSTROM_ALLOCATOR
#define _ALLOCATOR_DESTROY		1
#endif

#ifndef _CUSTROM_SIZE_TYPE
using::size_t;
#define __SIZE_TYPE		size_t
#endif
#ifndef _CUSTOM_OTHER_TYPE
//using::ptrdiff_t;
typedef int __w64 ptrdiff_t;
#define __OTHER_TYPE	ptrdiff_t
#endif
#define _USE_NOEXCEPT		throw()

// 참조표시를 지워 그 타입을 가져옴.
template<class _Ty>
	struct remove_reference
	{ typedef _Ty type; };

template<class _Ty>
	struct remove_reference<_Ty&>
	{ typedef _Ty type; };

template<class _Ty>
	struct remove_reference<_Ty&&>
	{ typedef _Ty type; };

template<class _Ty>
	struct remove_pointer
	{ typedef _Ty type; };

template<class _Ty>
	struct remove_pointer<_Ty*>
	{ typedef _Ty type; };


// lvalue참조 : Lvalue는 단일 표현식 이후에도 없어지지 않고 지속되는 객체!
template<class _Ty> inline
	_Ty&& forward(typename remove_reference<_Ty>::type& _Arg)
	{ return (static_cast<_Ty&&>(_Arg)); }

template<class _Ty> inline
	_Ty&& forward(typename remove_reference<_Ty>::type&& _Arg)
	{ return (static_cast<_Ty&&>(_Arg)); }

template<typename _Ty> 
_Ty* __addressof(_Ty& __r)
	{
	return reinterpret_cast<_Ty *>
	(&const_cast<char&>(reinterpret_cast<const volatile char&>(__r)));
	}

template<typename _Ty> class
	_Normal_new_allocator
	{
public:
	typedef typename __SIZE_TYPE	size_type;
	typedef typename __OTHER_TYPE	difference_type;
	typedef typename _Ty*			pointer;
	typedef typename const _Ty*		const_pointer;
	typedef typename _Ty&			reference;
	typedef typename const _Ty&		const_reference;
	typedef typename _Ty			value_type;

	template<typename _Ty1>
		struct rebind
		{
			typedef _Normal_new_allocator<_Ty1> other;
		};

	typedef _Normal_new_allocator<_Ty> _MyT;


	_Normal_new_allocator() _USE_NOEXCEPT {}
	_Normal_new_allocator(const _Normal_new_allocator&) _USE_NOEXCEPT {}
	template<typename _Ty1> 
	_Normal_new_allocator(const _Normal_new_allocator<_Ty1>&) _USE_NOEXCEPT {}
	
	~_Normal_new_allocator() _USE_NOEXCEPT {}

	pointer address(reference __x) const _USE_NOEXCEPT
		{
		return __addressof(__x);
		}

	const_pointer address(const_reference __x) const _USE_NOEXCEPT
		{
		return __addressof(__x);
		}

	pointer allocate(size_type __n, const void* = 0)
		{
		if (__n > this->max_size())
			throw "bad_alloc!";

		return static_cast<_Ty *>	(new _Ty[__n * sizeof(_Ty)]);
		}
	
	void deallocate(pointer __p, size_type)
		{
		delete __p;
		}

	size_type max_size() const _USE_NOEXCEPT
		{
		return size_type(-1) / sizeof(_Ty);
		}

	template<typename _Up, typename ... _Args>
		void construct(_Up* __p, _Args&&... __args)
		{
		//__p = new _Up(forward<_Args>(__args) ...);
		new ((void *)__p) _Up(forward<_Args>(__args)...);
		}

	template<typename _Up>
		void destroy(_Up* __p)
		{
		__p->~_Up();
		}

	void construct(_Ty *_Ptr)
		{
		new ((void *)_Ptr) _Ty();
		}

	void construct(pointer __p, const _Ty& _Val)
		{
		//__p = new _Ty(_Val);
		new ((void *)__p) _Ty(_Val);
		}

	void destroy(pointer __p)
		{
		__p->~_Ty();
		}

	};

template<typename _Ty>
	inline bool operator==(const _Normal_new_allocator<_Ty>&, const _Normal_new_allocator<_Ty>&)
	{ return true; }

template<typename _Ty>
	inline bool operator!=(const _Normal_new_allocator<_Ty>&, const _Normal_new_allocator<_Ty>&)
	{ return false; }

template<typename _Typ>
	using _Normal_allocator_base = _Normal_new_allocator < _Typ > ;

template<typename _Ty> class
	_Normal_allocator
		: public _Normal_allocator_base<_Ty>
	{
public:
	typedef typename __SIZE_TYPE	size_type;
	typedef typename __OTHER_TYPE	difference_type;
	typedef typename _Ty*			pointer;
	typedef typename const _Ty*		const_pointer;
	typedef typename _Ty&			reference;
	typedef typename const _Ty&		const_reference;
	typedef typename _Ty			value_type;
	
	_Normal_allocator() _USE_NOEXCEPT { }
	_Normal_allocator(const _Normal_allocator<_Ty>& _Val) _USE_NOEXCEPT
		: _Normal_allocator_base<_Ty>(_Val) { }
	template<typename _Ty1>
	_Normal_allocator(const _Normal_allocator<_Ty1>&) _USE_NOEXCEPT { }
	~_Normal_allocator() _USE_NOEXCEPT { }

	template<typename _Ty1>
		struct rebind
		{
			typedef _Normal_allocator<_Ty1> other;
		};

	template<typename _Ty1>
		_Normal_allocator<_Ty>& operator=(const _Normal_allocator<_Ty1>&)
		{
		return *this;
		}
		
	};

template<typename _TyLeft, typename _TyRight>
	inline bool operator==(const _Normal_allocator<_TyLeft>&, const _Normal_allocator<_TyRight>&)
	{ return true; }

template<typename _TyLeft, typename _TyRight>
	inline bool operator!=(const _Normal_allocator<_TyLeft>& _Left, const _Normal_allocator<_TyRight>& _Right)
	{ return !(_Left == _Right); }

template<typename _Typ>
	using allocator = _Normal_allocator < _Typ > ;

#endif