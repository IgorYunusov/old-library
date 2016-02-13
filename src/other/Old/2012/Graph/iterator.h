/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef ___iterator
#define ___iterator

template<class _iter> struct
	iterator_base
	{ // iterator base
	typedef _iter* pointer;
	typedef _iter* const_pointer;
	typedef _iter& reference;
	typedef _iter& const_reference;
	typedef _iter value_type;
	};

template<class _iterator> class
	iterator
	{ // basic iterator
	typedef iterator<_iterator> this_type;
	
	typedef typename _iterator::value_type value_type;
	typedef typename _iterator::pointer pointer;
	typedef typename _iterator::reference reference;
public:

	iterator()
		: _Ptr()
		{ // nullptr
		}

	iterator(pointer ptr)
		: _Ptr(ptr)
		{ // set pointer
		}

	pointer operator->()
		{ // return pointer to class object
		return &(**this);
		}

	this_type& operator++()
		{ // pre increment
		++this->_Ptr;
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
		--this->_Ptr;
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
		return (*this->_Ptr);
		}

	this_type& operator+=(int _Off)
		{ // increment by integer
		_Ptr += _Off;
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
		return (this->_Ptr - _Right._Ptr);
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

private:

	pointer _Ptr;
	};

template<class _iterator> class
	const_iterator
	{ // basic const iterator
	typedef const_iterator<_iterator> this_type;
	
	typedef typename _iterator::value_type value_type;
	typedef typename _iterator::const_pointer pointer;
	typedef typename _iterator::const_reference reference;
public:

	const_iterator()
		: _Ptr()
		{ // nullptr
		}

	const_iterator(pointer ptr)
		: _Ptr(ptr)
		{ // set pointer
		}

	pointer operator->() const
		{ // return pointer to class object
		return &(**this);
		}

	this_type& operator++()
		{ // pre increment
		++this->_Ptr;
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
		--this->_Ptr;
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
		return (*this->_Ptr);
		}

	this_type& operator+=(int _Off)
		{ // increment by integer
		_Ptr += _Off;
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
		return (this->_Ptr - _Right._Ptr);
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

private:

	pointer _Ptr;
	};

#endif