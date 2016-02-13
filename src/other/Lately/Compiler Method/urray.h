/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						ULTRA ARRAY CLASS
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _ULTRA_ARRAY_
#define _ULTRA_ARRAY_

#include "rac.h"
#include <stdio.h>
#include <vector>
#include <queue>

	//
	//	Ultra Array Value Structure
	//
template<typename _Ty, class _Alloc> struct 
	_Urray_base_types
	{
	typedef typename _Alloc::template rebind<_Ty>::other _Alty;

	typedef typename _Alty::pointer _Tptr;
	typedef typename _Alty::template rebind<_Tptr>::other _Alpty;
	};

template<class _Urray_val> struct
	_Urray_transfer
		: public _Container_base
	{
public:
	typedef _Urray_transfer<_Urray_val> _MyT;

	typedef typename _Urray_val::value_type value_type;
	typedef typename _Urray_val::pointer pointer;
	typedef typename _Urray_val::reference reference;
	typedef typename _Urray_val::const_pointer const_pointer;
	typedef typename _Urray_val::const_reference const_reference;
	typedef typename _Urray_val::size_type size_type;
	typedef typename _Urray_val::difference_type difference_type;

	_Urray_transfer()
		{
		_Myfirst = pointer();
		_Mylast = pointer();
		_Myend = pointer();
		}

	pointer& operator*()
		{
		return _Mylast;
		}

	pointer _Myfirst;
	pointer _Mylast;
	pointer _Myend;
	};


template<typename __base_types> class
	_urray_alloc
		: public _Urray_transfer<typename __base_types::_Alty>
	{
public:
	typedef _urray_alloc<__base_types>	_Myt;
	typedef typename __base_types::_Alty _Alty;
	typename _Alty _Alval;

	_urray_alloc(const _Alty& _Al = _Alty())
		: _Alval(_Al)
		{
		typename _Alty::template rebind<_Container_proxy>::other
			_Alproxy(this->_Alval);
		this->_Myproxy = _Alproxy.allocate(1);
		_Alproxy.construct(this->_Myproxy, _Container_proxy());
		}

	~_urray_alloc()
		{
		typename _Alty::template rebind<_Container_proxy>::other
			_Alproxy(this->_Alval);
		_Alproxy.destroy(this->_Myproxy);
		_Alproxy.deallocate(this->_Myproxy, 1);
		this->_Myproxy = 0;
		}

	void _replace(const _Alty& _Al)
		{
		typename _Alty::template rebind<_Container_proxy>::other
			_Alproxy(this->_Alval);
		_Alproxy.destroy(this->_Myproxy);
		_Alproxy.deallocate(this->_Myproxy, 1);
		this->_Myproxy = 0;
		this->_Alval = _Al;
		this->_Myproxy = _Alproxy.allocate(1);
		_Alproxy.construct(this->_Myproxy, _Container_proxy());
		}

	template<typename _Mt>
		void Swaping(_Mt& _Left, _Mt& _Right)
		{
		_Mt _l = _Left;
		_Left = _Right;
		_Right = l;
		}

	void _swap(_Myt& _N_alloc)
		{
		Swaping(this->_Alval, _N_alloc._Alval);
		Swaping(this->_Myproxy, _N_alloc._Myproxy);
		}

	_Alty& _get()
		{
		return this->_Alval;
		}

	const _Alty& _get() const
		{
		return this->_Alval;
		}
	
	};

template<typename _Ty, class _Alloc = allocator<_Ty>> class
	urray
		: public _urray_alloc<_Urray_base_types<_Ty, _Alloc>>
	{
public:
	typedef urray<_Ty, _Alloc> _MyUrray;
	typedef _urray_alloc<_Urray_base_types<_Ty, _Alloc>> _Mybase;

	typedef typename _Mybase::_Alty _Alty;

	typedef typename _Mybase::value_type value_type;
	typedef typename _Mybase::size_type size_type;
	typedef typename _Mybase::pointer pointer;
	typedef typename _Mybase::const_pointer const_pointer;
	typedef typename _Mybase::reference reference;
	typedef typename _Mybase::const_reference const_reference;


	urray()
		: _Mybase(), _Ptr_count(0)
		{
		this->_Myfirst = pointer();
		this->_Mylast = pointer();
		this->_Myend = pointer();
		}

	explicit urray(size_type _Count)
		: _Mybase(), _Ptr_count(0)
		{
		if(_buy(_Count))
			{
			_Alty _Alval(this->_get());
			pointer _Next = this->_Myfirst;
			for (; 0 < _Count; --_Count, ++_Next)
				*_Next = 0;
			this->_Mylast += _Count;
			}
		}

	~urray()
		{
		if (this->_Myfirst != pointer())
			{
			_Alty _Alval(this->_get());
			pointer _Next1 = this->_Myfirst;
			for (; _Next1 != this->_Mylast; ++_Next1)
				_Alval.destroy(_Next1);
			this->_get().deallocate(this->_Myfirst,
				this->_Myend - this->_Myfirst);
			}
		}

	const_reference operator[](size_type _Pos) const
		{
		return *(this->_Myfirst + _Pos + _Ptr_count);
		}

	reference operator[](size_type _Pos)
		{
		return *(this->_Myfirst + _Pos + _Ptr_count);
		}

	const_reference operator()(size_type _Pos) const
		{
		return *(this->_Myfirst + _Pos);
		}

	reference operator()(size_type _Pos)
		{
		return *(this->_Myfirst + _Pos);
		}

	size_type size() const _USE_NOEXCEPT
		{
		return this->_Mylast - this->_Myfirst;
		}

	reference operator*()
		{
		return *(this->_Mylast);
		}

	const_reference operator*() const
		{
		return *(this->_Mylast + _Ptr_count);
		}

	_MyUrray& operator++()
		{
		++_Ptr_count;
		return *this;
		}

	_MyUrray operator++(int)
		{
		_MyUrray _Ret = *this;
		++*this;
		return _Ret;
		}

	_MyUrray& operator--()
		{
		if (_Ptr_count == 0)
			return *this;
		--_Ptr_count;
		return *this;
		}

	_MyUrray operator--(int)
		{
		_MyUrray _Ret = *this;
		--*this;
		return _Ret;
		}

	_MyUrray& operator=(const _MyUrray& _copy)
		{
		if (_copy._get() != this->_get())
			this->_replace(_copy._get());
		this->_Myfirst = _copy._Myfirst;
		this->_Mylast = _copy._Mylast;
		this->_Myend = _copy._Myend;
		return (*this);
		}

	bool Empty() const _USE_NOEXCEPT
		{
		return (this->_Myfirst == this->_Mylast);
		}

	void Resize(size_type _Size)
		{
		if(_Size > size())
			{
			_Alty _Alval(this->_get());
			_ensure_room(_Size - size());
			pointer _Next = this->_Mylast, _Last = this->_Mylast;
			for (; 0 < _Size - size(); --_Size, ++_Last)
				_Alval.construct(_Last);
			this->_Mylast += _Size - size();
			}
		else if(_Size < size())
			{
			_Alty _Alval(this->_get());
			pointer _Ptr = this->_Mylast - (size() - _Size), _Next;
			_Next = _Ptr;
			for (; _Next != this->_Mylast; ++_Next)
				_Alval.destroy(_Next);
			this->_Mylast = _Ptr;
			}
		}

	void Add(const value_type& _Val)
		{
		if(_Inside(__addressof(_Val)))
			{
			size_type _Idx = __addressof(_Val) - this->_Myfirst;
			if (this->_Mylast == this->_Myend)
				_ensure_room(1);
			this->_get().construct(this->_Mylast, this->_Myfirst[_Idx]);
			++this->_Mylast;
			}
		else
			{
			if (this->_Mylast == this->_Myend)
				_ensure_room(1);
			this->_get().construct(this->_Mylast, _Val);
			++this->_Mylast;
			}
		}

	void Add(const value_type&& _Val)
		{
		if(_Inside(__addressof(_Val)))
			{
			size_type _Idx = __addressof(_Val) - this->_Myfirst;
			if (this->_Mylast == this->_Myend)
				_ensure_room(1);
			this->_get().construct(this->_Mylast, forward<value_type>(this->_Myfirst[_Idx]));
			++this->_Mylast;
			}
		else
			{
			if (this->_Mylast == this->_Myend)
				_ensure_room(1);
			this->_get().construct(this->_Mylast, forward<value_type>((value_type&&)_Val));
			++this->_Mylast;
			}
		}

	void Insert(size_type pos, const value_type& _Val)
		{
		}

	void Remove()
		{
		this->_get().destroy(this->_Mylast - 1);
		--this->_Mylast;
		}

	bool Contains(const value_type& item)
		{
		pointer _First = this->_Myfirst, _Last = this->_Mylast;
		for (; _First != _Last; ++_First)
			if (*_First == item)
				return true;
		return false;
		}

	bool Contains(const value_type *item)
		{
		return _Inside(item);
		}

protected:

	size_type _Ptr_count;



	bool _Inside(const value_type *_Ptr) const
		{
		return (_Ptr < this->_Mylast && this->_Myfirst <= _Ptr);
		}

	bool _buy(size_type _Capacity)
		{
		this->_Myfirst = pointer();
		this->_Mylast = pointer();
		this->_Myend = pointer();

		if (_Capacity == 0)
			return false;
		else if (max_size() < _Capacity)
			throw "Capacity is too long!";
		else
			{
			this->_Myfirst = this->_get().allocate(_Capacity);
			this->_Mylast = this->_Myfirst;
			this->_Myend = this->_Myfirst + _Capacity;
			}
		return true;
		}

	size_type max_size() const _USE_NOEXCEPT
		{
		return this->_get().max_size();
		}

	size_type _unused_capacity() const _USE_NOEXCEPT
		{
		return this->_Myend - this->_Mylast;
		}

	size_type _capacity() const _USE_NOEXCEPT
		{
		return this->_Myend - this->_Myfirst;
		}

	size_type _Grow_to(size_type _Count) const
		{	// grow by 50% or at least to _Count
		size_type _Capacity = _capacity();

		_Capacity = max_size() - _Capacity / 2 < _Capacity
			? 0 : _Capacity + _Capacity / 2;	// try to grow by 50%
		if (_Capacity < _Count)
			_Capacity = _Count;
		return (_Capacity);
		}

	void _ensure_room(size_type _Count)
		{
		if(_unused_capacity() < _Count)
			{
			if (max_size() - size() < _Count)
				throw "Capacity is too long!";
			_Reallocate(_Grow_to(size() + _Count));
			}
		}

	void _Reallocate(size_type _Count)
		{
		pointer _Ptr = this->_get().allocate(_Count);
		_Alty _Alval(this->_get());
		pointer _First = this->_Myfirst, _Last = this->_Mylast;
		/*for (; _Next != this->_Mylast; ++_Next)
			_Alval.destroy(_Next);*/
		/*for (; _First != _Last; ++_First, ++_Last)
			_Alval.construct(_First);*/
		size_type __Count = (size_type)(_Last - _First);
		memmove(&*_Ptr, &*_First, __Count * sizeof(*_First));

		size_type _Size = size();
		if (this->_Myfirst != pointer())
			{	// destroy and deallocate old array
			_Alty _Alval(this->_get());
			pointer _Next1 = this->_Myfirst;
			for (; _Next1 != this->_Mylast; ++_Next1)
				_Alval.destroy(_Next1);
			this->_get().deallocate(this->_Myfirst,
				this->_Myend - this->_Myfirst);
			}
		this->_Myend = _Ptr + _Count;
		this->_Mylast = _Ptr + _Size;
		this->_Myfirst = _Ptr;
		}

	};

#endif