/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_ARRAY_
#define _ROLLRAT_ARRAY_

/*=========================================================

		The RollRat Array Class Using Overloadding

	Iterators and the STL algorithms and the syntax is 
	almost identical, as can be used in parallel.
	Two-dimensional array, and three-dimensional arrays 
	are also available.Memory relocation algorithm, 
	please refer to the algorithm header. And binding
	array is also provided.

=========================================================*/

#include "cutilityex.h"

 using namespace xlib;

#if defined(_EX_SUCCESS)

_X_UTIL_BEGIN
	
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



_X_UTIL_END

#endif

#endif
/*
 *	the rollrat library
 *	http://blog.naver.com/rollrat
V0.2:1600****/