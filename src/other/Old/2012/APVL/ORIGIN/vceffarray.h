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

#pragma once

#ifndef __VCEFFARRAY
#define __VCEFFARRAY

#include "vcefflink.h"

// only c++ users.
template<class _VcAry>
	class array_n
	{ // vceff Array MEMS
	typedef typename _Base<_VcAry>::pointer _MyPtr;
	typedef typename _Base<_VcAry>::value_type _MyT;
	typedef typename _Base<_VcAry>::reference _MyRef;
	_MyPtr _array;
	int point;
	int size;

	public:

	explicit array_n()
		: _array(0), size(0), point(0)
		{ // entry point
		}

	_MyRef operator[](int _left)
		{ // return element
		if(size < _left)
			THROW_ERROR_INPUT(_left)
		return _array[_left];
		}

	array_n* operator->()
		{ // return array reference
		return (**this);
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

	void operator=(array_n _left)
		{ // equal
		_array = _left._array;
		size = _left.size;
		point = _left.point;
		}

	void operator=(int _left)
		{ // point at
		point = _left;
		}

	_MyT operator*()
		{ // return point
		return _array[point];
		}

	_MyRef operator&()
		{ // return reference
		return _array[point];
		}

	bool operator==(array_n _left)
		{ // operator ==
		return this->operator* == *_left;
		}

	bool operator!=(array_n _left)
		{ // operator !=
		return this->operator* != *_left;
		}

	bool operator<(array_n _left)
		{ // operator <
		return this->operator* < *_left;
		}

	bool operator>(array_n _left)
		{ // operator >
		return this->operator* > *_left;
		}

	bool operator<=(array_n _left)
		{ // operator <=
		return this->operator* <= *_left;
		}

	bool operator>=(array_n _left)
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

	bool operator&&(array_n _left)
		{ // operator &&
		return this->operator* && *_left;
		}

	bool operator||(array_n _left)
		{ // operator ||
		return this->operator* || *_left;
		}

	int size_of() const
		{ // get size
		return size;
		}

	void allocate(int _size)
		{ // allocatre all array
		_MyPtr _buf = _new<_MyT> (_size);
		size = _size;
		_array = _buf;
		}

	void keep(int _size)
		{ // allocate with keep using data
		_MyPtr _buf = _new<_MyT> (_size);
		_Copy_n(_array, _buf, size);
		size = _size;
		_array = _buf;
		}
	
	template<typename _Ty1> inline
	_Ty1* _new(const int _Val)
		{ // create new array
		return new _Ty1[_Val];
		}
	
	};



#endif