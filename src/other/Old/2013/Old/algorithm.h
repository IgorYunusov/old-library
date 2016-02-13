/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_algorithm
#define _x_lib_algorithm

#include "xmemory0.h"
#include "iterator.h"

//////////////////////////////////////////////////////
//												    //
// NOTE : This set of algorithm made of to use in   //
//		  Standard C++ Array Algorithm.			    //
//												    //
//////////////////////////////////////////////////////

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

	// TEMPLATE ROLLRAT ALGORITHMS
template<class _Ty1> inline
	_Ty1 _Seperate(_Ty1 value_type_ex, 
		_Ty1 multibyteset)
	{ // change the operation and operation
	_Ty1 buf = *value_type_ex;
	*value_type_ex = *multibyteset;
	*multibyteset = buf;
	return value_type_ex;
	}

template<class _Ty1, 
	class _Ty2> inline
	_Ty1* _Realloc(typename _Ty1* _Array, 
		_Ty2 nsize, _Ty2 lsize)
	{ // realloc array
	_Ty1 buf = new _Ty1[lsize];
	for(_Ty1 n = 0; n <= nsize;n++) 
		buf[n] = _Array[n];
	return buf;
	}

template<class _Ty1> inline
	_Ty1 (max)(_Ty1 ex, _Ty1 ey)
	{ // get max parameter set
	return (ex > ey ? ex : ey); 
	}

template<class _Ty1> inline
	_Ty1& (max)(_Ty1& ex, _Ty1& ey)
	{ // get max parameter set
	return (ex > ey ? ex : ey); 
	}

template<class _Ty1> inline
	_Ty1 (max)(_Ty1 ex, 
		_Ty1 ey, _Ty1 ez)
	{ // get max parameter set
	return (max)((max)(ex, ey), ez);
	}

template<class _Ty1> inline
	_Ty1 (min)(_Ty1 ex, _Ty1 ey)
	{ // get max parameter set
	return (ex < ey ? ex : ey); 
	}

template<class _Ty1> inline
	_Ty1& (min)(_Ty1& ex, _Ty1& ey)
	{ // get max parameter set
	return (ex < ey ? ex : ey); 
	}

template<class _Ty1> inline
	_Ty1 (min)(_Ty1 ex, 
		_Ty1 ey, _Ty1 ez)
	{ // get max parameter set
	return (min)((min)(ex, ey), ez);
	}

template<class _Ty1> inline
	_Ty1 abs(_Ty1 ex)
	{ // get absolute value
	return (ex > 0 ? ex : ( ex * -1 ));
	}

template<class _Ty1> inline
	_Ty1* _param()
	{ // create zero param
	return (_Ty1*)(0);
	}

template<typename _Tyr, class _Ty1> inline
	_Tyr _summation(_Ty1 _left, int _lsize)
	{ // summation
	_Tyr buf;
	for(int n = 0; n <= _lsize; n++) 
		buf += _left[n];
	return buf;
	}

template<typename _Ty1, 
	typename _Ty2, typename _Ty3> inline
	void _copy_n(const _Ty1 _Left,  _Ty2& _Right,
		_Ty3 _lsize, _Ty3 _rsize)
	{ // copy double array
	for(int i = 0; i <= _lsize; i++)
		for(int f = 0; f <= _rsize; f++)
			(_Right[i])[f] = (_Left[i])[f];
	}

template<typename return_type, class _Ty1> inline
	return_type _average(_Ty1 _left, int _lsize)
	{ // subtraction
	return _summation(_left, _lsize) / _lsize;
	}

template<typename _Ty1> inline
	_Ty1 _array(const int _Left, const int _Right)
	{ // create new array
	_Ty1 _buf = new ridof_pr<_Ty1>::type[_Left];
	for(int f = 0; f <= _Right; ++f)
		_buf[f] = new ridof_pr<ridof_pr<_Ty1>::type>::type[_Right];
	return _buf;
	}

template<typename _Ty1> inline
	_Ty1 _conple(_Ty1 _Left, int _size)
	{ // algorithm element function
	return _size - _Left - 1;
	}

template<typename _Tyd, 
	typename _Ty1> inline
	void _rotate(_Ty1 _left, int _lsize, int _rsize)
	{ // rotate array side of side angle
	_Tyd _buf = _array<_Tyd> (_lsize, _rsize);
	_copy_n(_left, _buf, _lsize, _rsize);
	for(int n = 0; n < _lsize; n++)
		for(int f = 0; f < _rsize; f++)
			_left[f][_conple(n, _lsize)] = _buf[n][f];
	}

template<typename _Tyd, 
	typename _Ty1> inline
	void _rotate(_Ty1 _left, int _lsize, int _rsize, int _time)
	{ // rotate array side of side angle use of time set
	for(int n = 0; n != _time; n++)
		_rotate<_Tyd> (_left, _lsize, _rsize);
	}

template<typename _Ty1> inline
	void _reverse(_Ty1 &_left, int _lsize)
	{ // reverse array
    for(int i = 0; i < _lsize / 2; i++)
		_Swap(_left, i, _conple(i, _lsize));
	}

template<typename _Tyd, 
	typename _Ty1> inline
	void _reverse(_Ty1 _left, int _lsize, int _rsize)
	{ // reverse array*
	_Tyd _buf = _array<_Tyd> (_lsize, _rsize);
	_copy_n(_left, _buf, _lsize, _rsize);
	for(int i = 0; i < _lsize; i++)
		for(int f = 0; f < _lsize; f++)
			_left[_conple(i, _lsize)][f] = _buf[i][f];
	}

template<typename _Ty1> inline
	void _sort(_Ty1 _left, int _lsize)
	{ // descending ordering array
	for(int n = 1; n <= (_lsize-1); n++)
		for(int i = 0; i <= (_lsize-2); i++)
			if(_left[i] > _left[i + 1])
				_Swap(_left, i, i + 1);
	}

template<typename _Ty1> inline
	void _sort_n(_Ty1 _left, int _lsize, _Ty1 _right)
	{ // descending ordering array and be duplicated pattern to other array
	for(int n = 1; n <= (_lsize-1); n++)
		for(int i = 0; i <= (_lsize-2); i++)
			if(_left[i] > _left[i + 1])
			{
				_Swap(_left, i, i + 1);
				_Swap(_right, i, i + 1);
			}
	}

template<typename _Ty1> inline
	void _select_sort(_Ty1 *_left, int _lsize)
	{ // select sorting the array
	_Ty1 min;
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

template<typename _Ty1> inline
	void _insert_sort(_Ty1 *_left, int _lsize)
	{ // insert sorting the array
	_Ty1 temp;
	int k;
	for(int i = 1; i < _lsize; i++, k = i)
		{
		temp = _left[i];
		while(_left[k-1] > temp && k > 0)
			_left[k] = _left[(k--) - 1];
		_left[k] = temp;
		}
	}

template<typename _Ty1> inline
	void _quick_sort(_Ty1 *_left, int _lsize)
	{ // being quick sorting the array is faster than any others
	int i = 0, j = _lsize;
	_Ty1 temp;
	if (_lsize > 1)
		{
		while(i < j)
			{
			while(_left[++i] < *_left && i < _lsize);
			while(_left[--j] > *_left);
			if ( i < j ) 
				_Swap(_left, i, j);
			}
		_Swap(_left, j++);
		_quick_sort(_left, j - 1);
		_quick_sort(_left + j, _lsize - j - 2);
		}
	}

template<typename _Ty1> inline
	void _swapfront(_Ty1 *_left, int _time)
	{ // forward first element by time set
	for(int n = 0; n <= (_time-1); n++)
		_Swap(_left, n, n + 1);
	}

template<typename _Ty1> inline
	void _partreverse(_Ty1 *_left, int _right, int _rsize)
	{ // part reverse _right ~ _rsize
	for(int i = _right; i < (_right + _rsize) / 2; i++)
		_Swap(_left, i, _conple(i, _right + _rsize));
	}

template<typename _Ty1> inline
	void _forward(_Ty1 *_left, int _right, int _time)
	{ // forward element by time set
	for(int n = 0; n <= _time; n++)
		_Swap(_left, _right + n, _right + n + 1);
	}

template<typename _Ty1> inline
	void _forward(_Ty1 *_left, int _right, int _rsize, int _time)
	{ // forward _right ~ _rsize by time set
	for(int n = 0; n <= _time; n++)
		for(int f = _right + n; f <= (_rsize + n); f++)
			_Swap(_left, f, f + 1);
	}

template<typename _Ty1> inline
	void _back(_Ty1 *_left, int _right, int _time)
	{ // back element by time set
	for(int n = 0; n <= _time; n++)
		_Swap(_left, _right - n, _right - n - 1);
	}

template<typename _Ty1> inline
	void _back(_Ty1 *_left, int _right, int _rsize, int _time)
	{ // back _right ~ _rsize by time set
	for(int n = 0; n <= _time; n++)
		for(int f = _right - n; f <= (_rsize - n); f++)
			_Swap(_left, f, f - 1);
	}

template<typename _Ty1> inline
	_Ty1 _max_element(_Ty1* _left, int _lsize)
	{ // find max element
	_Ty1 _buf = _left[0];
	for(int n = 1; n <= _lsize; n++)
		_buf = max(_buf, _left[n]);
	return _buf;
	}

template<typename _Ty1> inline
	_Ty1 _min_element(_Ty1* _left, int _lsize)
	{ // find max element
	_Ty1 _buf = _left[0];
	for(int n = 1; n <= _lsize; n++)
		_buf = min(_buf, _left[n]);
	return _buf;
	}

template<typename _Ty1> inline
	_Ty1* _new(const int _Val)
	{ // create new array
	return new _Ty1[_Val];
	}

template<typename _Ty1> inline
	_Ty1 _cmax(_Ty1* _left, int _lsize)
	{ // count max element
	_Ty1* _buf = _new[_lsize];
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

template<typename _Ty1> inline
	_Ty1 _cmin(_Ty1* _left, int _lsize)
	{ // count min element
	_Ty1* _buf = _new[_lsize];
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

template<typename _Ty1> inline
	void _plus(_Ty1 _left, _Ty1 _right, int _size)
	{ // array add
	for(int n = 0; n <= _size; n++)
		_left[n] = _left[n] + _right[n];
	}

template<typename _Ty1> inline
	void _minus(_Ty1 _left, _Ty1 _right, int _size)
	{ // array subtraction
	for(int n = 0; n <= _size; n++)
		_left[n] = _left[n] - _right[n];
	}

template<typename _Ty1> inline
	bool _equal(_Ty1 _left, _Ty1 _right, int _size)
	{ // check equal
	for(int n = 0; n <= _size;  n++)
		if(_left[n] != _right[n])
			return false;
	return true;
	}

template<typename _Ty1> inline
	bool _equal_n(_Ty1 _left, _Ty1 _right, int _lsize, int _rsize)
	{ // check equal
	for(int n = 0; n <= _lsize;  n++)
		if !(_equal(_left[n], _right[n], _rsize))
			return false;
	return true;
	}

template<typename _Ty1> inline
	bool _equal_f(_Ty1 _left, _Ty1 _right, int _lsize, int _rsize, int _asize)
	{ // check equal
	for(int n = 0; n <= _lsize;  n++)
		if !(_equal_n(_left[n], _right[n], _rsize, _asize))
			return false;
	return true;
	}

template<typename _Ty1> inline
	int _first_of(_Ty1* _left, _Ty1 _right, int _lsize)
	{ // search first pos of element 
	for(int n = 0; n <= _lsize; n++)
		if (_left[n] == _right)
			return n;
	}

template<typename _Ty1> inline
	int _last_of(_Ty1* _left, _Ty1 _right, int _lsize)
	{ // search last pos of element 
	for(int n = _lsize; n >= 0; n--)
		if (_left[n] == _right)
			return n;
	}

template<typename _Ty1> inline
	int _count(_Ty1 _left, _Ty1 _right, int _lsize, int _rsize)
	{ // count array
	int _buf = 0;
	if(_lsize < _rsize) throw(_lsize);
	for(int n = 0; n <= _lsize; n++)
		for(int f = 0; f <= _rsize; f++)
			if(_left[n] == _right[n])
				_buf++;
	return _buf;
	}

template<typename _Ty1> inline
	int _count_n(_Ty1 array_, _Ty1 data, 
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
				retbuf = 0, state = false;
	return 0;
	}

template<typename _Ty1> inline
	void _replace(_Ty1* _left, _Ty1 _right, _Ty1 _last, int _lsize)
	{ // replace element to element
	for(int n = 0; n <= _lsize; n++)
		if(_left[n] == _right)
			_left[n] = _last;
	}

template<typename _Ty1, typename function> inline
	void _polytazing(_Ty1 _left, int _lsize, function& _rand)
	{ // array random sorting
    for(int n = 0; n < _lsize; n++)
		_Swap(_left, n, _rand() % _lsize);
	}

template<typename _Ty1, typename function> inline
	void _polytazing(_Ty1 _left, int _lsize, int _rsize, function& _rand)
	{ // array random sorting
	for(int f = 0; f < _lsize; f++)
		for(int n = 0; n < _lsize; n++)
			_Swap(_left[f], n, _rand() % _lsize);
	}

template<typename _Ty1> inline
	_Ty1* _bind(_Ty1* _left, _Ty1* _right, int _lsize, int _rsize)
	{ // bind _left to _right and create new array
	_Ty1* _buf = _new<_Ty1> (_lsize + _rsize + 1);
	_fill(_buf, _lsize + _rsize + 1);
	int f = -1, n = 0;
	for( ; n <= _lsize; )
		_buf[++f] = _left[n++];
	for(n = 0; n <= _rsize; )
		_buf[++f] = _right[n++];
	return _buf;
	}

template<typename _Ty1> inline
	int _larger(_Ty1* _left, _Ty1 _right, int _lsize)
	{ // check element by larger than right
	int f = 0;
	for(int n = 0; n <= _lsize; n++)
		if(_left[n] > _right)
			f++;
	return f;
	}

template<typename _Ty1> inline
	int _smaller(_Ty1* _left, _Ty1 _right, int _lsize)
	{ // check element by smaller than right
	int f = 0;
	for(int n = 0; n <= _lsize; n++)
		if(_left[n] < _right)
			f++;
	return f;
	}

template<typename _Ty1> inline
	int _both(_Ty1* _left, _Ty1 _mid, _Ty1 _right, int _lsize)
	{ // check element both _mid ~ _right
	int f = 0;
	for(int n = 0; n <= _lsize; n++)
		if(_mid < _left[n] && _left[n] < _right)
			f++;
	return f;
	}

template<class _Ty1> inline
	_Ty1* _vtp(_Ty1* _left, _Ty1 _right)
	{ // create new array and fill left to right in ascii code
	_Ty1* _buf = _new(_right - _left);
	for(int n = _left, f; _left != _right;)
		_buf[f++] = n++;
	}

template<class _Ty1> inline
	_Ty1 _mtx_add(_Ty1 _left, _Ty1 _right, 
		int _ls1 = 3, int _ls2 = 3, int _rs1 = 3, int _rs2 = 3)
	{ // matrix add
	if(_ls1 != _rs2) return;
	_Ty1 _buf = _array(_ls1, _ls1);
	for(int i = 0; i < _ls1; i++)
		for(int j = 0; j < _ls2; j++)
			_buf[i][j] = _left[i][j] + _right[i][j];
	return _buf;
	}

template<class _Ty1> inline
	_Ty1 _mtx_sub(_Ty1 _left, _Ty1 _right, 
		int _ls1 = 3, int _ls2 = 3)
	{ // matrix sub
	_Ty1 _buf = _array(_ls1, _ls1);
	for(int i = 0; i < _ls1; i++)
		for(int j = 0; j < _ls2; j++)
			_buf[i][j] = _left[i][j] + _right[i][j];
	return _buf;
	}

template<class _Ty1> inline
	_Ty1 _mtx_multiple(_Ty1 _left, _Ty1 _right, 
		int _ls1 = 3, int _ls2 = 3)
	{ // matrix multiple
	_Ty1 _buf = _array(_ls1, _ls1);
	for(int i = 0; i < _ls1; i++)
		for(int j = 0; j < _ls1; j++){ _buf[i][j]=0;
			for(int f = 0; f < _ls2; f++)
				_buf[i][j] += _left[i][f] * _right[f][j];}
	return _buf;
	}

template<class _Ty1> inline
	_Ty1 _mtx_divide(_Ty1 _left, _Ty1 _right, 
		int _ls1 = 3, int _ls2 = 3)
	{ // matrix divide
	_Ty1 _buf = _array(_ls1, _ls1);
	for(int i = 0; i < _ls1; i++)
		for(int j = 0; j < _ls1; j++){ _buf[i][j]=0;
			for(int f = 0; f < _ls2; f++)
				_buf[i][j] += _left[i][f] / _right[f][j];}
	return _buf;
	}

	// TEMPLATE ARRAY CLASS
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

	virtual ~control()
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
	array_
	: public control<_operator_type>
	{ // the array class
	_operator_type* _array;
	int point;
	int size;

	public:

	explicit array_()
		: _array(0), size(0), point(0)
		{ // entry point
		}

	_operator_type& operator[](int _left)
		{ // return element
		if(size < _left)
			THROW_ERROR_INPUT(_left)
		return _array[_left];
		}

	array_* operator->()
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

	void operator=(array_ _left)
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

	bool operator==(array_ _left)
		{ // operator ==
		return this->operator* == *_left;
		}

	bool operator!=(array_ _left)
		{ // operator !=
		return this->operator* != *_left;
		}

	bool operator<(array_ _left)
		{ // operator <
		return this->operator* < *_left;
		}

	bool operator>(array_ _left)
		{ // operator >
		return this->operator* > *_left;
		}

	bool operator<=(array_ _left)
		{ // operator <=
		return this->operator* <= *_left;
		}

	bool operator>=(array_ _left)
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

	bool operator&&(array_ _left)
		{ // operator &&
		return this->operator* && *_left;
		}

	bool operator||(array_ _left)
		{ // operator ||
		return this->operator* || *_left;
		}

	int size_of() const
		{ // get size
		return size;
		}

	void bind(array_ _left)
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
	: public array_<array_<_operator_type> >
	{ // the array class by two dimention
	};

template<class _operator_type> class
	array_f
	: public array_n<array_<_operator_type> >
	{ // the array class by three dimention
	};

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

	// PREVIOUS VERSION X LIBRARY CLASS ELEMENT <!--
template<class _Ty>
	struct _X_TYPE
	{ // str type
	typedef _Ty Value_Type;
	typedef _Ty UnPointer;
	typedef _Ty Pointer;
	typedef _Ty Arrays;
	};

template<class _Ty>
	struct _X_TYPE<const _Ty>
	{ // str type
	typedef _Ty Value_Type;
	typedef _Ty UnPointer;
	typedef _Ty Pointer;
	typedef _Ty Arrays;
	};

template<class _Ty>
	struct _X_Base
	{ // usually use of memory
	typedef _Ty Value_Type;
	typedef _Ty UnPointer;
	typedef _Ty Pointer;
	typedef _Ty Arrays;
	};

template<class _Ty>
	struct _X_Base<const _Ty>
	{ // base class for const _Ty
	typedef _Ty Value_Type;
	typedef _Ty Arrays;
	typedef _Ty UnPointer;
	typedef _Ty Pointer;
	};

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

		explicit _X_COMMON()
			: _Right(0), _Left(0)
			{ // init
			}

		explicit _X_COMMON(_Ty1 _Right, _Ty2 _Left)
			: _Right(_Right), _Left(_Left)
			{ // init by parameter
			}

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

template<class _Ty, 
	class _Vector = _Ty, 
	class _Pointer = _Ty *,
	class _Reference = _Ty&>
	class _x_vector
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Memory<_Ty>,
		public _X_Vector_Ty<_Vector, _Ty, _Pointer, _Reference>
	{ // array vector type
	typedef _x_vector<_Ty, _Vector, _Pointer, _Reference> _MyT;
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

	explicit _x_vector()
		: size(0), push_point(0)
		{ // entry of vector
		List = new _VeIC[sizeof(_VeIC)];
		}

	explicit _x_vector(int size)
		: size(size+1), push_point(0)
		{ // entry of vector
		List = new _VeIC[this->size - 1];
		}

	~_x_vector()
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

template<class unchecked_type> class
	shared_ptr_e
	: public _X_TYPE<unchecked_type>
	{ // shared ptr class
	typedef shared_ptr_e<unchecked_type> _MyT;
	typedef typename _X_TYPE<unchecked_type>::Value_Type _MyVT;
	typedef typename _X_TYPE<unchecked_type>::Arrays _MyAY;
	typedef typename _X_TYPE<unchecked_type&>::UnPointer _MyUP;
	typedef typename _X_TYPE<unchecked_type*>::Pointer _MyPI;

	_MyVT *_MyPtr;

	public: 

	shared_ptr_e(_MyPI PtrHe)
		{ _MyPtr = PtrHe; }
	explicit shared_ptr_e(_MyPI* PtrHeT)
		{_MyPtr = reinterpret_cast<_MyPI> (PtrHeT);}
	~shared_ptr_e()
		{delete _MyPtr;}
	_MyPI operator*() const 
		{return *_MyPtr;}
	_MyUP operator->() const 
		{return _MyPtr;}

	};
	// --!>

	// THE TEMPLATE ROLLRAT ALGORITHM PART 2 -- SEARCH
template<class _Ty1, 
	class _Ty2> inline
	_Ty2 _First_Match(_Ty1 *_First, 
		_Ty1 _Elem, _Ty2 _Size)
	{ // First Match
	for(int i = 0; i <= _Size; i++)
		if(_First[i] == _Elem)
			return i;
	return 0;
	}

template<class _Ty1, 
	class _Ty2> inline
	_Ty2 _Last_Match(_Ty1 *_First, 
		_Ty1 _Elem, _Ty2 _Size)
	{ // Last Match
	for(int i = _Size; i; i--)
		if(_First[i] == _Elem)
			return i;
	return 0;
	}

template<class _Ty1,
	class _Ty2> inline
	_Ty2 _Next_Match(_Ty1 *_First,
		_Ty1 _Elem, _Ty2 _Size, _Ty2 _When)
	{ // Next Match
	for(int i = _When + 1; i <= _Size; i++)
		if(_First[i] == _Elem)
			return i;
	return 0;
	}

template<class _Ty1,
	class _Ty2> inline
	_Ty2 _Count(_Ty1 *_First, 
		_Ty1 _Elem, _Ty2 _Size)
	{ // count element in array
	int _Temp = 0;
	for(int i = 0; i <= _Size; i++)
		if(_First[i] == _Elem)
			_Temp++;
	return _Temp;
	}

template<class _Ty1,																		 
	class _Ty2> inline
	_Ty2 _Search_C(_Ty1 *_First, _Ty1 *_Last, 
		_Ty2 _FSize, _Ty2 _LSize)
	{ // search array element use by array
	int _Iteior = _First_Match(_First, *_Last, _FSize);

	if(_Iteior)

		for( ; _Iteior <= _FSize; _Iteior++)
			for(int i = 0; i <= _LSize; i++)

				if(_First[_Iteior] != _Last[i])
					goto _Ex;
				else if(i == _LSize)
					return _Iteior;

_Ex:

	_Iteior = _Next_Match(_First, *_Last, _FSize, _Iteior);

	if(_Iteior)

		for( ; _Iteior <= _FSize; _Iteior++)
			for(int i = 0; i <= _LSize; i++)

				if(_First[_Iteior] != _Last[i])
					goto _Ex;
				else if(i == _LSize)
					return _Iteior;

	return 0;
	}

template<class _Ty0> inline
	void ptrcat(_Ty0 *_left, const _Ty0 *_right)
	{ // ptrcat function
	char *ptr = _left;
	while(*ptr)
		ptr++;	// move pointer back
	while(*ptr++ = *_right++)
			;
	return (_left);
	}

template<class _Ty0> inline
	void ptrcpy(_Ty0 *_left, const _Ty0 *_right)
	{ // ptrcpy function
	char *ptr = _left;
	while(*ptr++ = *_right++)
			;
	return (_left);
	}

template<class _Ty0> inline
	int ptrlen(_Ty0 *_left)
	{ // ptrlen function
	_Ty0 *ptr = _left;
	while(*ptr++)
			;
	return (ptr - _left - 1);
	}

	// ALGORITHM 20130517 A-SET-A
template<class _Ty0 = int>
	class inc_num
	{ // inc num
	_Ty0 what;
public:
	inc_num(_Ty0 f)
		: what(f)
		{}
	inc_num()
		{what = (_Ty0)0;}
	_Ty0 operator()()
		{ // operator()
		return what++;}
	};

template<class _Ty0 = int>
	class dec_num
	{ // dec num
	_Ty0 what;
public:
	dec_num(_Ty0 f)
		: what(f)
		{}
	_Ty0 operator()()
		{ // operator()
		return what--;}
	};

template<class _Ty2, class _Func> inline
	void func_cross_fleft(_Ty2& that, 
		int line, int queue, _Func& what)
	{ // cross first left
	for(int i = 0, f = 0; i <= line && f <= queue; i++, f++)
		that[i][f] = what();
	}

template<class _Ty2, class _Func> inline
	void func_cross_fright(_Ty2& that, 
		int line, int queue, _Func& what)
	{ // cross first right
	for(int i = 0, f = queue; i <= line && f >= 0; i--, f++)
		that[i][f] = what();
	}

template<class _Ty2, class _Func> inline
	void func_cross_lleft(_Ty2& that, 
		int line, int queue, _Func& what)
	{ // cross last left
	for(int i = line, f = 0; i >= 0 && f <= queue; i--, f++)
		that[i][f] = what();
	}

template<class _Ty2, class _Func> inline
	void func_cross_lright(_Ty2& that, 
		int line, int queue, _Func& what)
	{ // cross last right
	for(int i = line, f = queue; i >= 0 && f >= 0; i--, f--)
		that[i][f] = what();
	}

template<class _Ty3, class _Func> inline
	void func_cross_fx(_Ty3& that, 
		int line, int queue, _Func& what)
	{ // cross first x
	for(int i = 0, f = 0; i <= line && f <= queue; i++, f++){
		that[i][f] = what();
		if(f != queue - f)
			that[i][queue - f] = what();
		}
	}

template<class _Ty3, class _Func> inline
	void func_cross_lx(_Ty3& that,
		int line, int queue, _Func& what)
	{ // cross last x
	for(int i = line, f = queue; i >= 0 && f >= 0; i--, f--){
		that[i][f] = what();
		if(f != queue - f)
			that[i][queue - f] = what();
		}
	}

template<class _Ty7, class _Func> inline
	void func_tetragon(_Ty7& that,
		int line, int queue, _Func& what, 
			const int depth = 0)
	{ // tetragon filler
	for(int i = depth, f = depth, g = 0; g == 0 ? f <= queue - depth : 
		g == 1 ? i <= line - depth :g == 2 ? f >= depth : i >= depth + 
		1; g == 0 ? f++ : g == 1 ? i++ : g == 2 ? f-- : i--,f == queue 
		- depth && g == 0 ? that[i][f] = what(), g = 1, i = depth + 1, 
		f = queue - depth : i == line - depth && g == 1 ? that[i][f] = 
		what(), g = 2, i = line - depth, f -= 1 :f == depth && g == 2 
		? that[i][f] = what(), g = 3, f = depth, i -= 1 : 0)
		that[i][f] = what();
	}

template<class _Ty8, class _Func> inline
	void func_snail(_Ty8& that,
		int line, int queue, _Func& what, 
			int depth)
	{ // snail filler
	for(int z = 0; z <= depth; z++)
		for(int i = z, f = z, g = 0; g == 0 ? f <= queue - z : 
			g == 1 ? i <= line - z :g == 2 ? f >= z : i >= z + 
			1; g == 0 ? f++ : g == 1 ? i++ : g == 2 ? f-- : i--,f == queue 
			- z && g == 0 ? that[i][f] = what(), g = 1, i = z + 1, 
			f = queue - z : i == line - z && g == 1 ? that[i][f] = 
			what(), g = 2, i = line - z, f -= 1 :f == z && g == 2 
			? that[i][f] = what(), g = 3, f = z, i -= 1 : 0)
		that[i][f] = what();
	}

template<class _Ty8, class _Ty0> inline
	void snail_sort(_Ty8& that,
		int line, int queue, _Ty0& what, 
			int depth)
	{ // snail sort
	for(int z = 0; z <= depth; z++)
		for(int i = z, f = z, g = 0, h = 0; g == 0 ? f <= queue - z : 
			g == 1 ? i <= line - z :g == 2 ? f >= z : i >= z + 
			1; g == 0 ? f++ : g == 1 ? i++ : g == 2 ? f-- : i--,f == queue 
			- z && g == 0 ? that[i][f] = what[h++], g = 1, i = z + 1, 
			f = queue - z : i == line - z && g == 1 ? that[i][f] = 
			what[h++], g = 2, i = line - z, f -= 1 :f == z && g == 2 
			? that[i][f] = what[h++], g = 3, f = z, i -= 1 : 0, h++)
		that[i][f] = what[h];
	}

template<class _Ty6, class _Func> inline
	void func_half_tetragon(_Ty6& that,
		int line, int queue, _Func& what, 
			int depth = 0)
	{ // half tetragon filler
	for(int i = depth, f = depth, k = 0; k == 0 ? f <= queue - depth : 
		(k == 1 ? i <= line - depth : (k == 2 ? f >= depth : i >= 
		depth + 1)); k == 0 ? f++ : (k == 1 ? i++ : (k == 2 ? f-- : i--)
		), k == 0 && !(f <= queue - depth) ? k = 1, i = depth + 1, f = 
		queue - depth : (k == 1 && !(f = queue - depth) ? k = 2, i = line 
		- depth, f -= 1 : k == 2 && !(f >= depth) ? f = depth, i -= 1 : 0 ))
		that[i][f] = what();
	}

template<class _Ty0> inline
	int chartoint(_Ty0 *i)
	{ // chartoint
	int ret = 0;
	for( ; *i; )
		ret = 10 * ret + (*i++ - '0');
	return ret;
	}

template<class _Ty0> inline
	_Ty0 solver_x_intonly(const char *f_x, _Ty0 value)
	{ // unregularly solver
	const char *fx_p = f_x;
	char savt[21] = {0, };
	char *p_avt = savt;
	bool t = false;
	_Ty0 returning = 0, last;
	while(*fx_p)
		{
			if(t)
				if('0' <= *fx_p && *fx_p <= '9')
					*p_avt++ = *fx_p;
				else
				{
					last = chartoint(savt);
					t = false;
					for(int i = 0; i <= 20; i++)
						savt[i] = 0;
					p_avt = savt;
				}
			if(('0' <= *fx_p && *fx_p <= '9') && !t)
				*p_avt++ = *fx_p,
				t = true;
			else 
				switch(*fx_p)
				{
				case '+':
					returning += last;
					break;
				case '-':
					returning -= last;
					break;
				case '*':
					returning *= last;
					break;
				case '/':
					returning /= last;
					break;
				case 'x':
					last = value;
					break;
				}
			*fx_p++;
		}
	return returning;
	}

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-04
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/