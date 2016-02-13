/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef ___literator
#define ___literator

#include "llist.h"

template<class _iterator> class
	literator
	{ // basic literator
	typedef literator<_iterator> this_type;
	
	typedef typename _iterator::value_type value_type;
	typedef typename _iterator::pointer pointer;
	typedef typename _iterator::str_pointer str_pointer;
	typedef typename _iterator::reference reference;
public:

	literator()
		: _Ptr()
		{ // nullptr
		}

	literator(str_pointer ptr)
		: _Ptr(ptr)
		{ // set pointer
		}

	pointer operator->()
		{ // return pointer to class object
		return &(**this);
		}

	this_type& operator++()
		{ // pre increment
		if(this->_Ptr->_Next == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Next;
		return (*this);
		}

	this_type operator++(int)
		{ // post increment
		this_type _Tmp = *this;
		++*this;
		return (_Tmp);
		}
	
	this_type& operator--()
		{ // pre decrement
		if(this->_Ptr->_Prev == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Prev;
		return (*this);
		}

	this_type operator--(int)
		{ // post decrement
		this_type _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	reference operator*()
		{ // return
		return (_Ptr->_Data);
		}

	this_type& operator+=(int _Off)
		{ // increment by integer
		if(_Off > 0)
			for( int i = 0; i < _Off; i++)
				++*this;
		else if(_Off < 0)
			for( int i = 0; i < -_Off; i++)
				--*this;
		return (*this);
		}

	this_type operator+(int _Off)
		{ // return this + integer
		this_type _Tmp = *this;
		return (_Tmp += _Off);
		}

	this_type& operator-=(int _Off)
		{ // decrement by integer
		return (*this += -_Off);
		}

	this_type operator-(int _Off)
		{ // return this - integer
		this_type _Tmp = *this;
		return (_Tmp -= _Off);
		}

	int operator-(const this_type& _Right) const
		{ // return difference of iterators
		int _tmp;
		str_pointer my = _Ptr, rig = _Right._Ptr;
		if(my == rig)
			return (0);
		for(_tmp = 0; (my != rig) && (my != my->_Next)
			; _tmp++, my = my->_Next)
			;
		if(my == rig)
			return (_tmp);
		for(_tmp = 0, my = _Ptr; (my != rig) && (rig != rig->_Next)
			; _tmp++, rig = rig->_Next)
			;
		if(my == rig)
			return (_tmp);
		return (-1);
		}

	reference operator[](int _Off)
		{ // subscript
		return (*(*this + _Off));
		}

	bool operator==(const this_type& _Right) const
		{ // test for iterator equality
		return (this->_Ptr == _Right._Ptr);
		}

	bool operator!=(const this_type& _Right) const
		{ // test for iterator inequality
		return (!(*this == _Right));
		}

	bool operator<(const this_type& _Right) const
		{ // test if this < _Right
		return (this->_Ptr < _Right._Ptr);
		}

	bool operator>(const this_type& _Right) const
		{ // test if this > _Right
		return (_Right < *this);
		}

	bool operator<=(const this_type& _Right) const
		{ // test if this <= _Right
		return (!(_Right < *this));
		}

	bool operator>=(const this_type& _Right) const
		{ // test if this >= _Right
		return (!(*this < _Right));
		}

protected:

	str_pointer _Ptr;
	};

template<class _iterator> class
	const_literator
	{ // basic literator
	typedef const_literator<_iterator> this_type;
	
	typedef typename _iterator::value_type value_type;
	typedef typename _iterator::pointer pointer;
	typedef typename _iterator::str_pointer str_pointer;
	typedef typename _iterator::reference reference;
public:

	const_literator()
		: _Ptr()
		{ // nullptr
		}

	const_literator(str_pointer ptr)
		: _Ptr(ptr)
		{ // set pointer
		}

	pointer operator->() const
		{ // return pointer to class object
		return &(**this);
		}

	this_type& operator++()
		{ // pre increment
		if(this->_Ptr->_Next == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Next;
		return (*this);
		}

	this_type operator++(int)
		{ // post increment
		this_type _Tmp = *this;
		++*this;
		return (_Tmp);
		}
	
	this_type& operator--()
		{ // pre decrement
		if(this->_Ptr->_Prev == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Prev;
		return (*this);
		}

	this_type operator--(int)
		{ // post decrement
		this_type _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	reference operator*() const
		{ // return
		return (_Ptr->_Data);
		}

	this_type& operator+=(int _Off)
		{ // increment by integer
		if(_Off > 0)
			for( int i = 0; i < _Off; i++)
				++*this;
		else if(_Off < 0)
			for( int i = 0; i < -_Off; i++)
				--*this;
		return (*this);
		}

	this_type operator+(int _Off)
		{ // return this + integer
		this_type _Tmp = *this;
		return (_Tmp += _Off);
		}

	this_type& operator-=(int _Off)
		{ // decrement by integer
		return (*this += -_Off);
		}

	this_type operator-(int _Off)
		{ // return this - integer
		this_type _Tmp = *this;
		return (_Tmp -= _Off);
		}

	int operator-(const this_type& _Right) const
		{ // return difference of iterators
		int _tmp;
		str_pointer my = _Ptr, rig = _Right._Ptr;
		if(my == rig)
			return (0);
		for(_tmp = 0; (my != rig) && (my != my->_Next)
			; _tmp++, my = my->_Next)
			;
		if(my == rig)
			return (_tmp);
		for(_tmp = 0, my = _Ptr; (my != rig) && (rig != rig->_Next)
			; _tmp++, rig = rig->_Next)
			;
		if(my == rig)
			return (_tmp);
		return (-1);
		}

	reference operator[](int _Off) const
		{ // subscript
		return (*(*this + _Off));
		}

	bool operator==(const this_type& _Right) const
		{ // test for iterator equality
		return (this->_Ptr == _Right._Ptr);
		}

	bool operator!=(const this_type& _Right) const
		{ // test for iterator inequality
		return (!(*this == _Right));
		}

	bool operator<(const this_type& _Right) const
		{ // test if this < _Right
		return (this->_Ptr < _Right._Ptr);
		}

	bool operator>(const this_type& _Right) const
		{ // test if this > _Right
		return (_Right < *this);
		}

	bool operator<=(const this_type& _Right) const
		{ // test if this <= _Right
		return (!(_Right < *this));
		}

	bool operator>=(const this_type& _Right) const
		{ // test if this >= _Right
		return (!(*this < _Right));
		}
	
protected:

	str_pointer _Ptr;
	};

#endif