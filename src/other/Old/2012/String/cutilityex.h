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

#include "rutil.h"
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
