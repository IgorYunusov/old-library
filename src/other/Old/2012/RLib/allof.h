/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_
#define _x_lib_

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

template<class _Ty> inline
	_Ty *AddressOf(_Ty& _Val)
	{	// return address of _Val
	return (reinterpret_cast<_Ty *>(
		(&const_cast<char&>(
		reinterpret_cast<const volatile char&>(_Val)))));
	}
_X_LIB_END
#endif

//////////////////////////////////////////////////////
//												    //
// NOTE : This set of algorithm made of to use in   //
//		  Standard C++ Array Algorithm.			    //
//												    //
//////////////////////////////////////////////////////

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

template<class _Ty2>
	struct cmlx_sign
	{ // complex sign
	_Ty2 numberic;
	_Ty2 cmlx_numberic;
	};
	
template<class _Ty0 = int>
	class cmlx
	{ // complex int
	cmlx_sign<_Ty0> numberic;
public:
	explicit cmlx()
		{numberic.numberic = 0;
		numberic.cmlx_numberic = 0;}
	explicit cmlx(_Ty0 i)
		{numberic.numberic = i;
		numberic.cmlx_numberic = 0;}
	cmlx<_Ty0>*& operator+(cmlx<_Ty0> _left)
		{cmlx_plus(_left); return *this;}
	cmlx<_Ty0>*& operator-(cmlx<_Ty0> _left)
		{cmlx_minus(_left); return *this;}
	cmlx<_Ty0>*& operator*(cmlx<_Ty0> _left)
		{cmlx_multiple(_left); return *this;}
	cmlx<_Ty0>*& operator/(cmlx<_Ty0> _left)
		{cmlx_divide(_left); return *this;}
	_Ty0& operator&()
		{return numberic.cmlx_numberic;}
	_Ty0& operator*()
		{return numberic.numberic;}
	string<char>& operator()()
		{ // operator()
		string<char> cht;
		cht += numberic.numberic;
		cht += " ";
		cht += numberic.cmlx_numberic;
		cht += "i";
		return cht;}
private:
	void cmlx_plus(cmlx_sign<_Ty0> numberic)
		{ // cmlx +
		this->numberic.numberic += numberic.numberic;
		this->numberic.cmlx_numberic 
			+= numberic.cmlx_numberic;
		}
	void cmlx_minus(cmlx_sign<_Ty0> numberic)
		{ // cmlx -
		this->numberic.numberic -= numberic.numberic;
		this->numberic.cmlx_numberic 
			-= numberic.cmlx_numberic;
		}
	void cmlx_multiple(cmlx_sign<_Ty0> numberic)
		{ // cmlx *
		this->numberic.numberic *= numberic.numberic;
		this->numberic.cmlx_numberic 
			*= numberic.cmlx_numberic;
		}
	void cmlx_divide(cmlx_sign<_Ty0> numberic)
		{ // cmlx *
		this->numberic.numberic /= numberic.numberic;
		this->numberic.cmlx_numberic 
			/= numberic.cmlx_numberic;
		}
	};

template<class _Ty1> inline
	_Ty1* _Allocate(size_t _Val, _Ty1 *)
	{ // allocate memory
	void *_Ptr = 0;
	if (_Val)
		_Ptr = ::operator new(_Val * sizeof(_Ty1));
	return ((_Ty1 *)_Ptr);
	}

template<class _Ty1> inline
	_Ty1* _Allocate(size_t _Val)
	{ // allocate memory
	void *_Ptr = 0;
	if (_Val)
		_Ptr = ::operator new(_Val * sizeof(_Ty1));
	return ((_Ty1 *)_Ptr);
	}

template<class _Ty1> inline
	void _Construct(_Ty1 *_xPtr)
	{ // creat new memory
	void *_Ptr = _xPtr;
	_xPtr = new _Ty1(0);
	}

template<class _Ty1> inline
	void _Delete(_Ty1 _First)
	{ // delete element
	delete _First;
	}

template<class _Ty1> inline
	void _Delete(_Ty1 *_First)
	{ // delete element
	delete[] _First;
	}

template<class _Ty1, 
	class _TySize> inline
	void _Delete(_Ty1 *_First, _TySize _Second)
	{ // delete element
	for(int i = 0; i <= _Second; i++)
		_Delete(_First[i]);
	_Delete(_First);
	}

template<class _Ty1, 
	class _TySize> inline
	void _Realloc_n(_Ty1 *_First, 
		_TySize _Second, _TySize _Third)
	{ // reallocate memory
	_Ty1 *buf = _Allocate<_Ty1> (_Third);
	for(_TySize n = 0; n <= _Second;n++)
		buf[n] = _First[n];
	return buf;
	}

template<class _Ty1> inline
	void _Swap(_Ty1 &_Left, _Ty1 &_Right)
	{ // swap element to element
	_Ty1 t = _Left; 
	_Left = _Right; 
	_Right = _Left;
	}

template<class _Ty1,
	class _TySize> inline
	void _Swap(_Ty1* _Left, _TySize f)
	{ // algorithm element, change from point to point
	_Ty1 _buf;
	_buf = *_Left;
	*_Left = _Left[f];
	_Left[f] = _buf;
	}

template<class _Ty1,
	class _TySize> inline
	void _Swap(_Ty1 *_Left, 
		_TySize i, _TySize f)
	{ // algorithm element, change from _left[i] to _left[f]
	_Ty1 _buf;
	_buf = _Left[i];
	_Left[i] = _Left[f];
	_Left[f] = _buf;
	}

template<class _Ty1, 
	class _TySize> inline
	void _Fill_n(_Ty1 *_Left, 
		_TySize _LSize, _Ty1 _Elem = 0)
	{ // fill element
	for(_TySize n = 0; n <= _LSize;n++)
		_Left[n] = _Elem;
	}

template<class _Ty1,
	class _Ty2,
	class _TySize> inline
	void _Copy_n(const _Ty1 _Left, 
		_Ty2 &_Right, _TySize _LSize)
	{ // copy function
	for(_TySize i = 0; i <= _LSize; i++)
		_Right[i] = _Left[i];
	};

template<class _Ty1,
	class _TySize> inline
	_Ty1* _Copy_n(const _Ty1 *_Left, _TySize _LSize)
	{ // copy function
	_Ty1 *_Ptr = _Allocate<_Ty1> (_LSize);
	_Copy_n(_Left, _Ptr, _LSize);
	return _Ptr;
	};

template<class _Ty1,
	class _Ty2 = _Ty1>
	class ptr
	{ // pointer
	typedef typename ridof_cvpr<_Ty2>::type _MyT;
	typename _MyT* ptrs;
	public:
	explicit ptr(_MyT *_First) : ptrs(_First) 
		{}
	ptr() : ptrs(0) 
		{ptrs = _Allocate<_MyT> (0);}
	_MyT*& operator=(_MyT* _First)
		{return ptrs = _First;}
	void operator++(int)
		{ptrs++;}
	void operator--(int)
		{ptrs--;}
	void operator+=(int _First)
		{ptrs += _First;}
	void operator-=(int _First)
		{ptrs -= _First;}
	_MyT& operator*()
		{return *ptrs;}
	_MyT&& operator&()
		{return &ptrs;}
	virtual ~ptr() 
		{delete[] ptrs;}
	};

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

template<class _Ty1> inline
	bool _Error(_Ty1 value_type_ex)
	{ // runtime patcher
	return _Error(value_type_ex) <= 9;
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
	shared_ptr
	: public _X_TYPE<unchecked_type>
	{ // shared ptr class
	typedef shared_ptr<unchecked_type> _MyT;
	typedef typename _X_TYPE<unchecked_type>::Value_Type _MyVT;
	typedef typename _X_TYPE<unchecked_type>::Arrays _MyAY;
	typedef typename _X_TYPE<unchecked_type&>::UnPointer _MyUP;
	typedef typename _X_TYPE<unchecked_type*>::Pointer _MyPI;

	_MyVT *_MyPtr;

	public: 

	shared_ptr(_MyPI PtrHe)
		{ _MyPtr = PtrHe; }
	explicit shared_ptr(_MyPI* PtrHeT)
		{_MyPtr = reinterpret_cast<_MyPI> (PtrHeT);}
	~shared_ptr()
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

template<class _Ty11, class _Func> inline
	void func_completly_complex(_Ty11& that,
		int line, int queue, _Func& what)
	{ // completly filler (x 3)
	for(int i = 0, f = 0, g = 0, k = 0, z = 0, a = 0; a == 0 ? z ==
		0 ? f <= queue :z == 1 ? f >= 0 :z == 2 ? i < f && i > 0 &&
		f > 0 :z == 3 ? i <= line :z == 4 ? f <= line && i <= queue
		&& i >= 0 && f >=0 :z == 5 ? i >= 0 && f >= 0 :z == 6 ? g ==
		0 ? f <= queue - 4 : g == 1 ? i <= line - 4 :g == 2 ? f >= 4
		: i>= 4 + 1 : k == 0 ? f <= queue - 6 : (k == 1 ? i <= line 
		- 6 : (k == 2 ? f >= 6 : i >= 6 + 1)) : a == 1 ? z == 0 ? f 
		<= queue :z == 1 ? f >= 0 :z == 2 ? i < f && i > 0 && f > 0 :
		z == 3 ? i <= line :z == 4 ? f <= line && i <= queue && i >= 
		0 && f >=0 :z == 5 ? i >= 0 && f >= 0 :z == 6 ? g == 0 ? f <=
		queue - 4 : g == 1 ? i <= line - 4 :g == 2 ? f >= 4 : i>= 4 +
		1 : k == 0 ? f <= queue - 6 : (k == 1 ? i <= line - 6 : (k ==
		2 ? f >= 6 : i >= 6 + 1)) : a == 2 ? z == 0 ? f <= queue :z 
		== 1 ? f >= 0 :z == 2 ? i < f && i > 0 && f > 0 :z == 3 ? i 
		<= line :z == 4 ? f <= line && i <= queue && i >= 0 && f >=0 
		: z == 5 ? i >= 0 && f >= 0 :z == 6 ? g == 0 ? f <= queue - 4 
		: g == 1 ? i <= line - 4 :g == 2 ? f >= 4 : i>= 4 + 1 : k == 
		0 ? f <= queue - 6 : (k == 1 ? i <= line - 6 : (k == 2 ? f >=
		6 : i >= 6 + 1)) : 0; a == 0 ? z == 0 ? f++ :z == 1 ? f-- :z 
		== 2 ? i--, f-- :z == 3 ? i++ :z == 4 ? i++, f++ :z == 5 ? 
		i--, f-- :z == 6 ? g == 0 ? f++ : g == 1 ? i++ : g == 2 ? f-- 
		: i--,f == queue - 4 && g == 0 ? that[i][f] = what(), g = 1, 
		i = 4 + 1, f = queue - 4 : i == line - 4 && g == 1 ? that[i][f]
		= what(), g = 2, i = line - 4, f -= 1 :f == 4 && g == 2 ? 
		that[i][f] = what(), g = 3, f = 4, i -= 1 : 0 : k == 0 ? f++ 
		: (k == 1 ? i++ : (k == 2 ? f-- : i--)), k == 0 && !(f <= queue
		- 6) ? k = 1, i = 6 + 1, f = queue - 6 : (k == 1 && !(f = queue
		- 6) ? k =2, i = line - 6, f -= 1 : k == 2 && !(f >= 6) ? 
		f = 6, i -= 1 :0 ), z == 0 && f == queue ? that[i][f] = 
		what(), z = 1, i += 1,f = queue : z == 1 && f == 0 ? that[i][f]
		= what(), z = 2, i = queue, f = line :  z == 2 && (i == f || i
		== 1 && f == 1) ? that[i][f] = what(), z = 3, i = 0, f = 0 : z
		== 3 && i == line? that[i][f] = what(), z = 4, i = line :z == 
		4 && f == line &&i == queue && i == 0 && f == 0 ? that[i][f] =
		what(), z = 5, i= line, f = queue : z == 5 && i == 0 && f ==0 
		? that[i][f] = what(), z = 6, i = 4, f = 4, g = 0 : z == 6 && 
		g == 0 ? f <= queue - 4 : g == 1 ? i <= line - 4 :g == 2 ? f >=
		4 : i >= 4 + 1 ? that[i][f] = what(), z = 7, i = 6, f = 6, k = 
		0 : 0 : a == 1 ? z == 0 ? f++ :z == 1 ? f-- :z == 2 ? i--, f-- 
		:z == 3 ? i++ :z == 4 ? i++, f++ :z == 5 ? i--, f-- :z == 6 ? g
		== 0 ? f++ : g == 1 ? i++ : g == 2 ? f-- : i--,f == queue - 4 
		&& g == 0 ? that[i][f] = what(), g = 1, i = 4 + 1, f = queue - 
		4 : i == line - 4 && g == 1 ? that[i][f] = what(), g = 2, i = 
		line - 4, f -= 1 :f == 4 && g == 2 ? that[i][f] = what(), g = 3,
		f = 4, i -= 1 : 0 : k == 0 ? f++ : (k == 1 ? i++ : (k == 2 ? f--
		: i--)), k == 0 && !(f <= queue - 6) ? k = 1, i = 6 + 1, f = 
		queue - 6 : (k == 1 && !(f = queue - 6) ? k =2, i = line - 6, f
		-= 1 : k == 2 && !(f >= 6) ? f = 6, i -= 1 :0 ), z == 0 && f == 
		queue ? that[i][f] = what(), z = 1, i += 1,f = queue : z == 1 && 
		f == 0 ? that[i][f] = what(), z = 2, i = queue, f = line :  z == 
		2 && (i == f || i == 1 && f == 1) ? that[i][f] = what(), z = 3, 
		i = 0, f = 0 : z == 3 && i == line? that[i][f] = what(), z = 4, 
		i = line :z == 4 && f == line &&i == queue && i == 0 && f == 0 
		? that[i][f] = what(), z = 5, i= line, f = queue : z == 5 && i ==
		0 && f ==0 ? that[i][f] = what(), z = 6, i = 4, f = 4, g = 0 : z 
		== 6 && g == 0 ? f <= queue - 4 : g == 1 ? i <= line - 4 :g == 2 ?
		f >= 4 : i >= 4 + 1 ? that[i][f] = what(), z = 7, i = 6, f = 6, 
		k = 0 : 0 :a == 2 ? z == 0 ? f++ :z == 1 ? f-- :z == 2 ? i--, f--
		:z == 3 ? i++ :z == 4 ? i++, f++ :z == 5 ? i--, f-- :z == 6 ? g 
		== 0 ? f++ : g == 1 ? i++ : g == 2 ? f-- : i--,f == queue - 4 && 
		g == 0 ? that[i][f] = what(), g = 1, i = 4 + 1, f = queue - 4 : i
		== line - 4 && g == 1 ? that[i][f] = what(), g = 2, i = line - 4, 
		f -= 1 :f == 4 && g == 2 ? that[i][f] = what(), g = 3, f = 4, i 
		-= 1 : 0 : k == 0 ? f++ : (k == 1 ? i++ : (k == 2 ? f-- : i--)), 
		k == 0 && !(f <= queue - 6) ? k = 1, i = 6 + 1, f = queue - 6 : (k
		== 1 && !(f = queue - 6) ? k =2, i = line - 6, f -= 1 : k == 2 
		&& !(f >= 6) ? f = 6, i -= 1 :0 ), z == 0 && f == queue ? that[i][f]
		= what(), z = 1, i += 1,f = queue : z == 1 && f == 0 ? that[i][f]
		= what(), z = 2, i = queue, f = line :  z == 2 && (i == f || i ==
		1 && f == 1) ? that[i][f] = what(), z = 3, i = 0, f = 0 : z == 3 &&
		i == line? that[i][f] = what(), z = 4, i = line :z == 4 && f == line
		&&i == queue && i == 0 && f == 0 ? that[i][f] = what(), z = 5, i
		= line, f = queue : z == 5 && i == 0 && f ==0 ? that[i][f] = what()
		, z = 6, i = 4, f = 4, g = 0 : z == 6 && g == 0 ? f <= queue - 4 
		: g == 1 ? i <= line - 4 :g == 2 ? f >= 4 : i >= 4 + 1 ? that[i][f]
		= what(), z = 7, i = 6, f = 6, k = 0 : 0 : 0,a == 0 && z == 0 ? f
		<= queue :z == 1 ? f >= 0 :z == 2 ? i < f && i > 0 && f > 0 :z == 
		3 ? i <= line :z == 4 ? f <= line && i <= queue && i >= 0 && f >=0 
		:z == 5 ? i >= 0 && f >= 0 :z == 6 ? g == 0 ? f <= queue - 4 : g ==
		1 ? i <= line - 4 :g == 2 ? f >= 4 : i>= 4 + 1 : k == 0 ? f <= queue
		- 6 : (k == 1 ? i <= line - 6 : (k == 2 ? f >= 6 : i >= 6 + 1)) ? 
		that[i][f] = what(), a = 1, i = 2, f = 2, g = 2, k = 2, z = 2 : a 
		== 1 && z == 0 ? f <= queue :z == 1 ? f >= 0 :z == 2 ? i < f && i >
		0 && f > 0 :z == 3 ? i <= line :z == 4 ? f <= line && i <= queue &&
		i >= 0 && f >=0 :z == 5 ? i >= 0 && f >= 0 :z == 6 ? g == 0 ? f <= 
		queue - 4 : g == 1 ? i <= line - 4 :g == 2 ? f >= 4 : i>= 4 + 1 : 
		k == 0 ? f <= queue - 6 : (k == 1 ? i <= line - 6 : (k == 2 ? f >=
		6 : i >= 6 + 1)) ? that[i][f] = what(), a = 1, i = 3, f = 3, g = 3
		, k = 3, z = 3 : 0)
		that[i][f] = what();
	}

	// STANDARD SWAP ALGORITHM ONE LEVELS
template<class _Ty1> inline
	void _swap(_Ty1& _Left, _Ty1& _Right)
	{ // standard one level swap
	_Ty1 temp = _Left;
	_Left = _Right;
	_Right = temp;
	}

template<class _Ty1> inline
	void _pswap(_Ty1& _Left, _Ty1& _Right)
	{ // pointer swap
	_Ty1 temp = *_Left;
	*_Left = *_Right;
	*_Right = temp;
	}

template<class _Ty1> inline
	void _cswap(_Ty1& _Left, _Ty1& _Right)
	{ // complex swap
	swap((swap(_Left, _Right), 
		swap(_Left, _Right), _Left), _Right)
	}

template<class _Ty1, 
	class _Ty2> inline
	void _rswap(_Ty1& _Left, _Ty2& _Right)
	{ // reinterpret swap
	swap(_Left, reinterpret_cast<_Ty2> (_Right));
	}

	// STANDARD SWAP ALGORITHM TWO LEVELS
template<class _Ty1> inline
	void swap(_Ty1*& _Left, _Ty1*& _Right, int size)
	{ // standard two level swap
	for(int i = 0; i <= size; i++)
		_swap(_Left[i], _Right[i]);
	}

template<class _Ty1> inline
	void pswap(_Ty1*& _Left, _Ty1*& _Right)
	{ // pointer swap
	_Ty1 temp = *_Left;
	*_Left = *_Right;
	*_Right = temp;
	}

template<class _Ty1> inline
	void aswap(_Ty1*& _Left, _Ty1*& _Right, int that)
	{ // array swap 1
	swap(_Left[that], _Right[that]);
	}

template<class _Ty1> inline
	void aswap(_Ty1*& _Left, int that, int thats)
	{ // array swap 2
	swap(_Left[that], _Left[thats]);
	}

	// STANDARD SWAP ALGORITHM THREE LEVELS
template<class _Ty1> inline
	void tswap(_Ty1**& _Left, int i, int j, int size)
	{ // ta swap
	for(int f = 0; f <= size; f++)
		swap(_Left[i][f], _Left[j][f]);
	}

template<class _Ty1> inline
	void jswap(_Ty1**& _Left, _Ty1**& _Right, 
		int size, int around)
	{ // j swap
	for(int f = 0; f <= size; f++)
		swap(_Left[f][around], _Right[f][around]);
	}


template<class _Ty0 = char,
		class _Ty0_0 = int,
		class _Ty0_1 = double> // position
	class characters
	{ // characters class
public:
	characters *next;
	characters *prev;
	_Ty0 *name;
	_Ty0_0 age, hp, mp, exp, status, install,
		tall, sex, foot, head, pos_x, pos_y, level,
		side, up, down, left, right;
	_Ty0_1 hp, mp, exp;
	};

template<class _Ty0 = char,
		class _Ty0_0 = int,
		class _Ty0_1 = double>
	class others_in
	{ // others class
public:
	_Ty0 *name;
	_Ty0_0 pos_x, pos_y, hp, mp, exp, install,
		up, down, left, right, statud;
	_Ty0_1 hp, mp, exp;
	};

template<class _Ty0 = char>
	class _keyset
	{ // key set
public:
	_Ty0 attack, left, right, jump, down, rope,
		rabber, pickup, menu, items;
	};

template<class _function>
	class _funcset
	{ // funcset
public:
	_function gotoxy;
	_function wherex, wherey;
	_function putcharxy;
	_function setcolor;
	_function sleep;
	};

template<class _Ty10 = char, 
	class _func>
	class cl_map
	{ // cl map class
	characters *_head;
	characters *_now;
	characters *_tail;
	others_in<> *others_icn;
	_keyset<_Ty10> keyset;
	int x, y, w, z, mx, my, mw, mz;
	_funcset<_func> func;
	_Ty10** map;
	int item;
public:
	void set_func(_funcset<_func> funcs)
		{ func = funcs; }
	void set_keys(_keyset<_Ty10> keys)
		{ keys = keyset; }
	void key_state(_Ty10 keys)
		{
		switch( keys )
			{
		case keyset.attack:
			attack_calculation(_now, *others_icn);
			attack_action(_now);
			attack_render(_now);
		case keyset.left:
			if(!(_now->pos_x - _now->foot < x))
				_now->pos_x -= _now->foot;
			c_render();
		case keyset.right:
			if(!(_now->pos_x + _now->foot > y))
				_now->pos_x += _now->foot;
			c_render();
		case keyset.jump:
			if(!(_now->pos_y + _now->install > w))
				_now->pos_y += _now->install;
			j_render();
		case keyset.down:
		case keyset.rope:
		case keyset.rabber:
		case keyset.pickup:
			if(map[func.wherey()][func.wherex()] !=
				item)
				;
			else
				;
			}
		}
private:
	void attack_action(characters *who)
	{}
	void attack_render(characters *who)
	{}
	void attack_calculation(characters *who, 
		others_in<> what)
	{}
	void c_render()
	{}
	void j_render()
	{}
	};

	
/**************************************
	Conjunction Connect Source (-CCS)
	Channel
 **************************************/

#define CJCT_SUCCESS			0x01
#define CJCT_NEXT				0x02
#define CJCT_PREV				0x03
#define CJCT_RETRY				0x04
#define CJCT_ERROR				0x05
#define CJCT_ENTRY				0x00
#define CJCT_JUMP				0x09

#define _u unsigned

#define get_asc( _hx ) ((_hx) && (0xFF))

#define UHigh( _hx ) ((_hx) << (4)))
#define ULow( _hx ) ((_hx) && (0xFF))
#define UCow( _hx , _x ) (((_hx) << (8)) | (_x))
#define UGet( _hx ) ((_hx) & (0xFFFFFFFF))
#define LHigh( _hx ) ((_hx) << (8))
#define LLow( _hx ) ((_hx) && (0xFFFF))
#define LCow( _hx , _x ) (((_hx) << (4)) | (_x))
#define LGet( _hx ) ((_hx) & (0xFFFF))

#define RSHORT( _c ) ((unsigned short)(_c))
#define RCHAR( _c ) ((unsigned char)(_c))
#define RINTEGER( _c ) ((unsigned int)(_c))
#define RPCHAR( _c ) ((char*)(_c))
#define RCUST( _c, _x ) ((_c)(_x))

template<class _Ty0>
	struct Conjuctions
	{ // conjectsion sign
	public:
	_Ty0 Left; // ccs sign
	_Ty0 Right; // ccs parameter
	};

template<class _Ty0>
	struct CCS_Other
	{ // ccs other
	public:
	_Ty0 _First; // ccs sign
	_Ty0 _Second;// ccs parameter
	_Ty0 _Last;  // ccs parameter
	};

class _Match_Ex_a
	{ // basis match ex
	public:

	_Match_Ex_a(char *Target)
		: _Target(Target), _Pointer(0)
		{ // entry
		len();
		}

	bool operator++(int)
		{ // plus
		_Pointer++;
		if(_Pointer == _len)
			{
			_Pointer--;
			return false;
			}
		return true;
		}

	void len()
		{ // len
		for(int i = 0; _Target[i]; i++)
			if(_Target[i] == 0)
				_len = i;
		}

	bool operator--(int)
		{ // minus
		_Pointer--;
		if(_Pointer == 0)
			{
			_Pointer++;
			return false;
			}
		return true;
		}

	char operator*()
		{ // operator *
		return _Target[_Pointer];
		}

	char *operator()()
		{ // operator all
		return _Target;
		}

	private:

	int _Pointer;
	char *_Target;
	int _len;

	};


/*------------------------------------------------------------

					FLOOR Algorithm

	This header provides the function that matches to the 
	user as a 'floor' header. Further, by utilizing this, 
	it can be possible to reduce a complex algorithms 
	Blueprint, thereby shortening the access time by using 
	complex algorithms. You can at the end, as a hexagonal 
	structure, 'atom' all gave six arms, but burn.

------------------------------------------------------------*/

//template<class linked_type>
//	class quark
//	{ // linked class node struct
//	public:
//	// up
//	quark *_Up_Left;	// 1
//	quark *_Up_Mid;		// 2
//	quark *_Up_Right;	// 3
//	// down
//	quark *_Dw_Left;	// 4
//	quark *_Dw_Mid;		// 5
//	quark *_Dw_Right;	// 6
//	linked_type _data;
//	};

enum _QUARK_POS
	{
	up_left = 1	,
	up_mid		,
	up_right	,
	dw_left		,
	dw_mid		,
	dw_right	,
	};

template<class _Ty0> inline
	_QUARK_POS _transmission_qp(_Ty0 pos)
	{ // transmission quark pos
	if(pos == 1)
		return up_left;
	else if(pos == 2)
		return up_mid;
	else if(pos == 3)
		return up_right;
	else if(pos == 4)
		return dw_left;
	else if(pos == 5)
		return dw_mid;
	else if(pos == 6)
		return dw_right;
	}

template<class linked_type>
	class quark
	{ // lineked class PREVIOUS atom
	typedef typename quark<linked_type> _MyQuark;
	linked_type _DATA;
	public:
	quark *_UL, *_UM, *_UR, *_DL, *_DM, *_DR;
	explicit quark()
		: _DATA(0)
		{ // entry point set
		_UL = _DR; _UM = _DM; _UR = _DL;
		_DL = _UR; _DM = _UM; _DR = _UL;
		}
	explicit quark(linked_type _First)
		: _DATA(_First)
		{ // entry point set
		_UL = _DR; _UM = _DM; _UR = _DL;
		_DL = _UR; _DM = _UM; _DR = _UL;
		}
	__forceinline void Connect(quark*& quk, _QUARK_POS pos)
		{ // connect simple
		switch(pos){
		case 1: _UL = quk; quk = _DR;
		case 2: _UM = quk; quk = _DM;
		case 3: _UR = quk; quk = _DL;
		case 4: _DL = quk; quk = _UR;
		case 5: _DM = quk; quk = _UM;
		case 6: _DR = quk; quk = _UL;};
		}
	__forceinline void Set(linked_type _First) { _DATA = _First; }
	__forceinline linked_type& Get() 
			{ return _DATA; }
	__forceinline _MyQuark* New()
		{ // allocate quark
		_MyQuark *ptr = new _MyQuark;
		return ptr;
		}
	inline _MyQuark *C_UL(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_UL = Ptr;
		return _UL;
		}
	inline _MyQuark *C_UM(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_UM = Ptr;
		return _UM;
		}
	inline _MyQuark *C_UR(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_UR = Ptr;
		return Ptr;
		}
	inline _MyQuark *C_DL(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_DL = Ptr;
		return _DL;
		}
	inline _MyQuark *C_DM(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_DM = Ptr;
		return _DM;
		}
	inline _MyQuark *C_DR(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_DR = Ptr;
		return _DR;
		}
	};

template<class linked_type> inline
	linked_type* _quark_alloc()
	{ // quark alloc
	linked_type *ptr = new linked_type;
	return ptr;
	}

template<class identical_type>
	class floor_const_iterator
	{ // the _sequencer class
	typedef typename quark<identical_type> _MyNode;
	
	_MyNode *point;

	public:

	__forceinline identical_type operator*() const
		{ // return point
		return point->_DATA;
		}

	__forceinline void operator=(_MyNode *_left)
		{
		point = _left;
		}

	void Set(_MyNode *_Left)
		{
		point = _Left;
		}

	bool _UL()
		{
		point = point->_UL;
		return point != point->_UL;
		}

	bool _UM()
		{
		point = point->_UM;
		return point != point->_UM;
		}

	bool _UR()
		{
		point = point->_UR;
		return point != point->_UR;
		}

	bool _DL()
		{
		point = point->_DL;
		return point != point->_DL;
		}

	bool _DM()
		{
		point = point->_DM;
		return point != point->_DM;
		}

	bool _DR()
		{
		point = point->_DR;
		return point != point->_DR;
		}

	__forceinline bool operator==(_MyNode *_left) const
		{ // operator ==
		return point == _left;
		}

	__forceinline bool operator!=(_MyNode *_left) const
		{ // operator !=
		return point != _left;
		}

	__forceinline bool operator==(identical_type _left) const
		{ // operator ==
		return this->operator* == _left;
		}

	__forceinline bool operator!=(identical_type _left) const
		{ // operator !=
		return this->operator* != _left;
		}

	__forceinline bool operator<(identical_type _left) const
		{ // operator <
		return this->operator* < _left;
		}

	__forceinline bool operator>(identical_type _left) const
		{ // operator >
		return this->operator* > _left;
		}

	__forceinline bool operator<=(identical_type _left) const
		{ // operator <=
		return this->operator* <= _left;
		}

	__forceinline bool operator>=(identical_type _left) const
		{ // operator >=
		return this->operator* >= _left;
		}

	};

template<class identical_type>
	class floor_iterator
	{ // the _sequencer class

	typedef typename __type
		<typename quark<identical_type> 
		>::value_type _MyNode;
	
	_MyNode *point;

	public:

	__forceinline identical_type& operator*()
		{ // return point
		return point->Get();
		}

	__forceinline void operator=(_MyNode *_left)
		{
		point = _left;
		}

	void Set(_MyNode *_Left)
		{
		point = _Left;
		}

	bool _UL()
		{
		point = point->_UL;
		return point != point->_UL;
		}

	bool _UM()
		{
		point = point->_UM;
		return point != point->_UM;
		}

	bool _UR()
		{
		point = point->_UR;
		return point != point->_UR;
		}

	bool _DL()
		{
		point = point->_DL;
		return point != point->_DL;
		}

	bool _DM()
		{
		point = point->_DM;
		return point != point->_DM;
		}

	bool _DR()
		{
		point = point->_DR;
		return point != point->_DR;
		}

	__forceinline bool operator==(_MyNode *_left) 
		{ // operator ==
		return point == _left;
		}

	__forceinline bool operator!=(_MyNode *_left)
		{ // operator !=
		return point != _left;
		}

	__forceinline bool operator==(identical_type _left)
		{ // operator ==
		return this->operator* == _left;
		}

	__forceinline bool operator!=(identical_type _left)
		{ // operator !=
		return this->operator* != _left;
		}

	__forceinline bool operator<(identical_type _left)
		{ // operator <
		return this->operator* < _left;
		}

	__forceinline bool operator>(identical_type _left)
		{ // operator >
		return this->operator* > _left;
		}

	__forceinline bool operator<=(identical_type _left)
		{ // operator <=
		return this->operator* <= _left;
		}

	__forceinline bool operator>=(identical_type _left)
		{ // operator >=
		return this->operator* >= _left;
		}

	};

template<class linked_type>
	class floor
	{ // the floor class
	typedef typename floor _MyT;
	typedef typename __type
		<typename quark<linked_type> 
		>::reference _MyQRef;
	typedef typename __type
		<typename quark<linked_type> 
		>::pointer _MyQPtr;
	_MyQPtr _Main;
	_MyT *_Next_Floor;
	_MyT *_Prev_Floor;

	public:
		
	typedef typename __type
		<typename quark<linked_type> 
		>::value_type Quark;
	typedef typename floor_const_iterator<linked_type> const_iterator;
	typedef typename floor_iterator<linked_type> iterator;

	explicit floor()
		{ // entry point it
		_Main = _quark_alloc<Quark> ();
		_Next_Floor = this;
		_Prev_Floor = this;
		};

	__forceinline void Connect_Floor(floor _First)
		{ // connect floor
		_Next_Floor = _First;
		}

	__forceinline void Up_Left(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(1));}
	__forceinline void Up_Mid(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(2));}
	__forceinline void Up_Right(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(3));}
	__forceinline void Dw_Left(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(4));}
	__forceinline void Dw_Mid(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(5));}
	__forceinline void Dw_Right(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(6));}

	__forceinline _MyQPtr Up_Left() { return _Main->_UL; }
	__forceinline _MyQPtr Up_Mid() { return _Main->_UM; }
	__forceinline _MyQPtr Up_Right() { return _Main->_UR; }
	__forceinline _MyQPtr Dw_Left() { return _Main->_DL; }
	__forceinline _MyQPtr Dw_Mid() { return _Main->_DM; }
	__forceinline _MyQPtr Dw_Right() { return _Main->_DR; }

	_MyQPtr begin()
		{ // begin
		return _Main;
		}

	inline _MyQPtr Create_UL(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Up_Left(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_UM(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Up_Mid(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_UR(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Dw_Right(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_DL(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Dw_Left(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_DM(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Dw_Mid(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_DR(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Dw_Right(Ptr);
		return Ptr;
		}
	};

	// UL ALGORITHM
template<class _Quark0>
	void UL_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_UL(ccc);
		}

template<class _Quark0, class _Ty0>
	void UL_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_UL(_Second);
		}

template<class _Quark0>
	void UL_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_UL = _First;
		}

template<class _Quark0>
	void UL_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_UL = _Second->_DR;
		_Second->_DR = _First->_UL;
		}

	// UM ALGORITHM
template<class _Quark0>
	void UM_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_UM(ccc);
		}

template<class _Quark0, class _Ty0>
	void UM_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_UM(_Second);
		}

template<class _Quark0>
	void UM_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_UM = _First;
		}

template<class _Quark0>
	void UM_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_UM = _Second->_DM;
		_Second->_DM = _First->_UM;
		}

	// UR ALGORITHM
template<class _Quark0>
	void UR_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_UR(ccc);
		}

template<class _Quark0, class _Ty0>
	void UR_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_UR(_Second);
		}

template<class _Quark0>
	void UR_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_UR = _First;
		}

template<class _Quark0>
	void UR_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_UR = _Second->_DR;
		_Second->_DR = _First->_UR;
		}

	// DL ALGORITHM
template<class _Quark0>
	void DL_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_DL(ccc);
		}

template<class _Quark0, class _Ty0>
	void DL_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_DL(_Second);
		}

template<class _Quark0>
	void DL_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_DL = _First;
		}

template<class _Quark0>
	void DL_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_DL = _Second->_UR;
		_Second->_UR = _First->_DL;
		}

	// DM ALGORITHM
template<class _Quark0>
	void DM_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_DM(ccc);
		}

template<class _Quark0, class _Ty0>
	void DM_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_DM(_Second);
		}

template<class _Quark0>
	void DM_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_DM = _First;
		}

template<class _Quark0>
	void DM_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_DM = _Second->_UM;
		_Second->_UM = _First->_DM;
		}

	// DR ALGORITHM
template<class _Quark0>
	void DR_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_DR(ccc);
		}

template<class _Quark0, class _Ty0>
	void DR_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_DR(_Second);
		}

template<class _Quark0>
	void DR_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_DR = _First;
		}

template<class _Quark0>
	void DR_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_DR = _Second->_UR;
		_Second->_UR = _First->_DR;
		}


template<typename _Ty1> inline
	_Ty1 Translate_Char_Int(_Ty1 _First)
	{ // char -> int
	if('0' <= _First && _First <= '9')
		return _First - '0';
	if(_First == 0)
		return 0;
	}

template<typename _Ty1> inline
	_Ty1 Translate_Int_Char(_Ty1 _First)
	{ // int -> char
	if(0 <= _First && _First <= 9)
		return _First + '0';
	if(_First == 0)
		return 0;
	}

template<typename _Ty1> inline
	int Get_Length(_Ty1 _First)
	{ // get length
	for(int i = 0; ; )
		if(!_First[i++])
			return i;
	}

template<typename _Ty1> inline
	_Ty1 *reverse(_Ty1 *s)
	{ // reverse char
	_Ty1  c;
	_Ty1 *s0 = s - 1;
	_Ty1 *s1 = s;
	for( ; *s1; ) ++s1;
	for( ; s1-- > ++s0; )
		{
		c   = *s0;
		*s0 = *s1;
		*s1 =  c;
		}
	return s;
	}

typedef enum Sign
	{
	minus	= -1,
	zero	= 0,
	plus	= 1,
	};

#define MAX_CHAR 32767 // max char in x64 arcitacture

template<class _Ty0 = int>
	class UInteger
	{ // unsigned integer
	public:

	UInteger()
		: Sign(zero), Length(0), retbuf(0)
		{ // entry point
		uintegerbuf = new char[MAX_CHAR];
		for(register int i = 0; i <= MAX_CHAR; i++)
			uintegerbuf[i] = 0;
		uintegerbuf[0] = '0';
		}

	~UInteger()
		{ // desconductor
		delete[] uintegerbuf;
		}

	void operator++(int)
		{ // public algorithm
		for(register long long i = 0; ; i++)
			{
			if(uintegerbuf[i] == '0' || uintegerbuf[i] == 0)
				{
				uintegerbuf[i] = '1';
				break;
				}
			else if(uintegerbuf[i] == '9')
				uintegerbuf[i] = '0';
			else 
				{
				uintegerbuf[i] += 1;
				break;
				}
			}
		}

	void operator--(int)
		{ // public algorithm
		for(register long long i = 0; ; i++)
			{
			if(uintegerbuf[i] == '0')
				uintegerbuf[i] = '9';
			else
				{
				uintegerbuf[i] -= 1;
				break;
				}
			}
		}

	char *operator()()
		{ // operator()
		_reverse();
		return uintegerbuf;
		}

	void _reverse()
		{ // reverse me
		reverse(uintegerbuf);
		}

	void operator+=(int _First)
		{ // operator += int
		static char *buf = new char[MAX_CHAR];
		for(long long i = 0; i <= MAX_CHAR; i++)
			buf[i] = 0;
		itoa(_First, buf, 10);/*
		for(register long long i = 0; i <= f; i++)
			if ('0' <= buf[i] && buf[i] <= '9')
				;
			else 
				buf[i] = 0;*/
		operator+=(buf);
		}

	void operator+=(char* _me)
		{ // algorithm
		char* me;
		me = reverse(_me);
		int f = Get_Length(me);
		for(register long long i = 0; i <= f - 1; i++)
			{
			if(0 <= (Translate_Char_Int(me[i]) + Translate_Char_Int(uintegerbuf[i])) 
				&& (Translate_Char_Int(me[i]) + Translate_Char_Int(uintegerbuf[i])) < 10)
				uintegerbuf[i] = Translate_Int_Char(Translate_Char_Int(me[i]) 
				+ Translate_Char_Int(uintegerbuf[i]));
			else if(10 <= (Translate_Char_Int(me[i]) + Translate_Char_Int(uintegerbuf[i])) 
				&& (Translate_Char_Int(me[i]) + Translate_Char_Int(uintegerbuf[i])) <= 18 )
				uintegerbuf[i] = Translate_Int_Char(Translate_Char_Int(me[i]) 
					+ Translate_Char_Int(uintegerbuf[i]) - 10),
				pluse_n_come_char_innex_parameter(i + 1);
			}
		}

	void pluse_n_come_char_innex_parameter(long long state)
		{
		if(uintegerbuf[state] == '9')
			{
			uintegerbuf[state] = '0';
			pluse_n_come_char_innex_parameter(state + 1);
			}
		else
			if(uintegerbuf[state] == 0)
				uintegerbuf[state] = '1';
			else
				uintegerbuf[state] = uintegerbuf[state] + 1;
		}

	void operator-=(int _First)
		{ // operator += int
		static char *buf = new char[MAX_CHAR];
		for(long long i = 0; i <= MAX_CHAR; i++)
			buf[i] = 0;
		itoa(_First, buf, 10);/*
		for(register long long i = 0; i <= f; i++)
			if ('0' <= buf[i] && buf[i] <= '9')
				;
			else 
				buf[i] = 0;*/
		operator-=(buf);
		}

	void operator*=(int _First)
		{
		static char *buf = new char[MAX_CHAR];
		for(long long i = 0; i <= MAX_CHAR; i++)
			buf[i] = 0;
		itoa(_First, buf, 10);/*
		for(register long long i = 0; i <= f; i++)
			if ('0' <= buf[i] && buf[i] <= '9')
				;
			else 
				buf[i] = 0;*/
		operator*=(buf);
		}

	void operator*=(char *_buf)
		{ // algorithm
		}

	private:

	char *retbuf;
	char *uintegerbuf;
	Sign Sign;
	long long Length;

	};

#if defined(_IOSTREAM_)
std::ostream &operator<<(std::ostream &os, UInteger<>& x) 
	{
	os << x();
	x._reverse();
	return os;
	}
#endif


template<typename _Ty0> inline
	_Ty0*& itoas(int i)
	{ // itoa
	static _Ty0 buf[21];
	_Ty0 *p = buf + 19 + 1;
	if (i >= 0) 
		{while (i != 0)
			*--p = '0' + (i % 10), i /= 10;
		return p;}
	else{while (i != 0)
			*--p = '0' - (i % 10), i /= 10;
		*--p = '-';}
	return p;
	}

template<typename _Ty0> inline
	double atof(_Ty0* chars)
	{ // atof
	_Ty0* point = chars;
	double dev, floa, floating;
	bool sign = false;
	while(*point && isspace(*point))
		point++;
	if(!*point)
		return 0;
	else if(!isnumberic(*point))
		sign = ((*point++ - 43 == 0) ? 0 : 1);
	while(*point && isnumberic(*point) || *point == '.')
		{
			if(*point == '.')
			{
				*point++;
				while(*point && isnumberic(*point))
				{
					floa = floa * 10 + *point - 48;
					floating = 0.1 * floating;
					*point++;
				}
				floa = floa * floating;
			}
			else
			{
				dev = dev * 10 + dev - 48;
				*point++;
			}
		}
	if (sign)
		return -1 * (dev + floa);
	return dev + floa;
	}

template<typename _Ty0> inline
	bool isnumberic(_Ty0 what)
	{ // is numberic
	return '0' <= what && what <= '9';
	}

template<typename _Ty0> inline
	_Ty0 isspace(_Ty0 c_ch)
	{ // isspace
	switch(c_ch)
		{
		case '\n':
		case '\v':
		case '\f':
		case '\t':
		case '\r':
		case  ' ':
			return 1;
		}
	return 0;
	}

template<typename _Ty0>
	_Ty0* strtok(_Ty0* strToken, const _Ty0* strDelimit)
	{ // strtok
	char *str;
	const char *ctrl = strDelimit;
	unsigned char map[32];
	int count;

	for (count = 0; count < 32; count++)
		map[count] = 0;

	do {
		map[*ctrl >> 3] |= (1 << (*ctrl & 7));
	} while (*ctrl++);

	if (strToken)
		str = strToken;

	while ((map[*str >> 3] & (1 << (*str & 7))) && *str)
		str++;

	strToken = str;

	for ( ; *str ; str++ )
		if ( map[*str >> 3] & (1 << (*str & 7)) ) {
			*str++ = '\0';
			break;
		}

	if ( strToken == str ) 
		return 0;
	else 
		return strToken;
	}


template<class linked_type>
	class iterator_node
	{ // linked class node struct
	public:
	iterator_node *_NextPtr;
	iterator_node *_PrevPtr;
	linked_type _data;
	};

template<class identical_type>
	class iterator
	{ // the _sequencer class
	typedef typename iterator_node<identical_type> _MyNode;

	_MyNode *point;

	public:

	__forceinline identical_type& operator*()
		{ // return point
		return point->_data;
		}

	__forceinline void operator++(int)
		{ // point at forward
		point = point->_NextPtr;
		}

	__forceinline void operator--(int)
		{ // point at forward
		point = point->_PrevPtr;
		}

	__forceinline void operator=(_MyNode *_left)
		{
		point = _left;
		}

	__forceinline bool operator==(_MyNode *_left)
		{ // operator ==
		return point == _left;
		}

	__forceinline bool operator!=(_MyNode *_left)
		{ // operator !=
		return point != _left;
		}

	__forceinline bool operator==(identical_type _left)
		{ // operator ==
		return this->operator* == _left;
		}

	__forceinline bool operator!=(identical_type _left)
		{ // operator !=
		return this->operator* != _left;
		}

	__forceinline bool operator<(identical_type _left)
		{ // operator <
		return this->operator* < _left;
		}

	__forceinline bool operator>(identical_type _left)
		{ // operator >
		return this->operator* > _left;
		}

	__forceinline bool operator<=(identical_type _left)
		{ // operator <=
		return this->operator* <= _left;
		}

	__forceinline bool operator>=(identical_type _left)
		{ // operator >=
		return this->operator* >= _left;
		}

	};

template<class identical_type>
	class const_iterator
	{ // the _sequencer class
	typedef typename iterator_node<identical_type> _MyNode;
	
	_MyNode *point;

	public:

	__forceinline identical_type operator*() const
		{ // return point
		return point->_data;
		}

	__forceinline void operator++(int)
		{ // point at forward
		point = point->_NextPtr;
		}

	__forceinline void operator--(int)
		{ // point at forward
		point = point->_PrevPtr;
		}

	__forceinline void operator=(_MyNode *_left)
		{
		point = _left;
		}

	__forceinline bool operator==(_MyNode *_left) const
		{ // operator ==
		return point == _left;
		}

	__forceinline bool operator!=(_MyNode *_left) const
		{ // operator !=
		return point != _left;
		}

	__forceinline bool operator==(identical_type _left) const
		{ // operator ==
		return this->operator* == _left;
		}

	__forceinline bool operator!=(identical_type _left) const
		{ // operator !=
		return this->operator* != _left;
		}

	__forceinline bool operator<(identical_type _left) const
		{ // operator <
		return this->operator* < _left;
		}

	__forceinline bool operator>(identical_type _left) const
		{ // operator >
		return this->operator* > _left;
		}

	__forceinline bool operator<=(identical_type _left) const
		{ // operator <=
		return this->operator* <= _left;
		}

	__forceinline bool operator>=(identical_type _left) const
		{ // operator >=
		return this->operator* >= _left;
		}

	};

template<class linked_type> inline
	void _Link_Connect(linked_type _head, linked_type _target, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _target;
	_target->_PrevPtr = _head;
	_target->_NextPtr = _tail;
	_tail->_PrevPtr = _target;
	}

template<class linked_type> inline
	void _Link_Connect(linked_type _head, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _tail;
	_tail->_PrevPtr = _head;
	}

template<class linked_type> inline
	void _Link_Init(linked_type _head, linked_type _tail)
	{ // initialization the link
	_head->_PrevPtr = _head;
	_head->_NextPtr = _tail;
	_head->_PrevPtr = _head;
	_tail->_NextPtr = _tail;
	}

template<class linked_type>
	class link
	{ // linekd class
		
	typedef typename iterator_node<linked_type> _MyNode;

	_MyNode *_Head;
	_MyNode *_Tail;
	_MyNode *_Lastest;

	int sizeofit;

	public:
		
	typedef typename iterator_node<linked_type> _NodeIt;
	typedef typename iterator<linked_type> iterator;
	typedef typename const_iterator<linked_type> const_iterator;

	link()
		: _Head(0), _Tail(0), sizeofit(0)
		{ // load entry point
		_Head = _New_Node();
		_Tail = _New_Node();
		_Link_Init(_Head, _Tail);
		}

	__forceinline _MyNode*& begin()
		{ // begin function
		return _Head->_NextPtr;
		}

	__forceinline _MyNode*& end()
		{ // end function
		return _Tail;
		}
	
	__forceinline _MyNode* _New_Node()
		{ // create new node
		_MyNode *ptr = new _MyNode;
		return ptr;
		}

	int operator^(int) const
		{ // operator ^
		return sizeofit;
		}

	void push_back(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_data = _left;
		if (sizeofit)
			_Link_Connect(_Lastest, temp, _Tail);
		else
			_Link_Connect(_Head, temp, _Tail);
		_Lastest = temp;
		sizeofit++;
		}

	void push_front(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_data = _left;
		_Link_Connect(_Head, temp, _Head->_NextPtr);
		_Lastest = temp;
		sizeofit++;
		}

	linked_type pop_back()
		{ // pop back item
		_MyNode *ptr = _Head;
		_MyNode *prev = _Head;
		linked_type ret;
		for(int f = -1; ;f++)
			{
			if(ptr == _Tail)
				break;
			ret = ptr->_data;
			if(f > 0)
				prev = prev->_NextPtr;
			ptr = ptr->_NextPtr;
			}
		delete prev->_NextPtr;
		_Link_Connect(prev, _Tail);
		return ret;
		}

	linked_type pop_front()
		{ // pop back item
		_MyNode *ptr = _Head->_NextPtr;
		linked_type ret = ptr->_data;
		_Link_Connect(_Head, ptr->_NextPtr);
		delete ptr;
		return ret;
		}

	};


template<typename _Ty0> inline
	int strlen_dev(
		const _Ty0 *str)
	{ // strlen dev
	const _Ty0 *ch = str;
	while(*ch++)
		;
	return ((int)(ch - str - 1));
	}

template<typename _Ty0> inline
	_Ty0 *strrev_dev(
		_Ty0 *string
		)
	{ // strrev
	_Ty0 *start = string;
	_Ty0 *left = string;
	_Ty0 ch;
	while(*string++)
		;
	string -= 2;
	while (left < string)
		{
		ch = *left;
		*left++ = *string;
		*string-- = ch;
		}
	return(start);
	}

template<typename _Ty0> inline
	_Ty0 *split_ch(
		const _Ty0 *rCharText, 
		const _Ty0 fSplit, 
		int Arrange)
	{ // split character
	int i=0, f=0, Split=0;
	_Ty0 Buf[10][1000];
	while(rCharText[f])
		{
		if(rCharText[f] == fSplit)
			{
			Buf[Split][++i] = 0;
			Split++;
			i = 0;
			}
		if(rCharText[f] != fSplit)
			Buf[Split][i] = rCharText[f];
		else
			Buf[Split][--i] = rCharText[f];
		i++;
		f++;
		}
	if(rCharText[f] == 0)
		{
		Buf[Split][++i] = 0;
		Split++;
		i = 0;
		}
	if(rCharText[f] != fSplit)
		Buf[Split][i] = rCharText[f];
	else
		Buf[Split][--i] = rCharText[f];
	return Buf[Arrange];
	}

template<typename _Ty0> inline
	_Ty0 *left_ch(
		const _Ty0 *str,
		_Ty0 ch)
	{ // get character left
	while(*str && *str != ch)
		str++;
	if(*str == ch)
		return ((_Ty0 *)(++str));
	return (0);
	}

template<typename _Ty0> inline
	_Ty0 *right_ch(
		const _Ty0 *str,
		_Ty0 ch)
	{ // get character right
	_Ty0 *start = (_Ty0 *)str;
	while(*str++)
		;
	while(--str != start && *str != (ch))
		;
	if(*str == ch)
		return ((_Ty0 *)(++str));
	return (0);
	}

template<typename _Ty0> inline
	_Ty0 *replace_ch(
		const _Ty0 *str,
		_Ty0 _left,
		_Ty0 _right)
	{ // replace character
	int len = strlen_dev(str);
	int back = 0;
	_Ty0 *start = new _Ty0[len];
	for(int i = 0; i <= len; i++)
		start[i] = str[i];
	while(*start && *start != _left)
		start++, back++;
	*start = _right;
	return start - back;
	}

template<typename _Ty0> inline
	_Ty0 *replace_ch_n(
		const _Ty0 *str,
		_Ty0 _left,
		_Ty0 _right)
	{ // replace all character
	int len = strlen_dev(str);
	int back = 0;
	_Ty0 *start = new _Ty0[len];
	for(int i = 0; i <= len; i++)
		start[i] = str[i];
	while(*start)
		if(*start == _left)
			*start = _right;
		else
			start++, back++;
	return start - back;
	}

template<class _Ty>
	class parser
	{ // parser
	typedef typename __type<_Ty>::value_type _MyT;

	public:
		
	_MyT *strs;

	parser(_MyT *str)
		: strs(str)
		{ // entry point
		}

	explicit parser(const _MyT *str)
		: strs((_MyT *)(str))
		{ // entry point
		}

#ifndef _EXPLICITFF_
	explicit parser()
		: strs(0)
		{ // entry point
		}
#endif

	_MyT *cut(int _First)
		{ // cut all
		_MyT *_tmp = new _MyT[_First];
		for(int i = 0; i <= _First; i++)
			_tmp[i] = strs[i];
		return _tmp;
		}
	
	_MyT *cut_between(int _First, int _Second)
		{ // cut between
		_MyT *_tmp = new _MyT[_Second - _First];
		for(int i = _First, f = 0; i <= _Second; i++, f++)
			_tmp[f] = strs[i];
		return _tmp;
		}

	_MyT *cut_bind(int _LFirst, int _LSecond,
			int _RFirst, int _RSecond)
		{ // cut bind
		_MyT *_tmp = new _MyT[_LSecond + _RSecond - _LFirst - _RFirst];
		int f = 0;
		for(int i = _LFirst; i <= _LSecond; i++, f++)
			_tmp[f] = strs[i];
		for(int i = _RFirst; i <= _RSecond; i++, f++)
			_tmp[f] = strs[i];
		return _tmp;
		}

	};
	
	typedef enum _xdfef
		{
			OPERATOR_PLUS,
			OPERATOR_MINUS,
			OPERATOR_MULTIPLE,
			OPERATOR_DIVIDE,
			OPERATOR_MOD,
			OPERATOR_EQUAL,
		};

template<class _Ty = char>
	class _numberic_form
		: public parser<_Ty>
	{ // numberic form
	typedef typename __type<_Ty>::value_type _MyVT;

	public:

	#define OPERATOR_SET			"+-*/%="
	#define SPECIFICOPERATOR_SET	"sprt/root/sin/cos/tan/in/log/arcsin/arccos/arctan/csc/sec/cotan/"
	#define SET_SYMBOLS				"∧;∨;¬;⇒;→,iff;∀;∃;∃1,∃!;∴;∵;:=,:⇔;∈;∋;∉;=;≠;⊆;⊇;⊂;⊃;⊊;⊋;⊄;⊅;"
		//∫

	int solve_form_int(_Ty *_First)
		{ // solve form int
		int len = strlen_dev(_First);
		
		}

	bool IsNumberic(_Ty *_First)
		{ // is numberic
		while(*_First)
			if(!('0' <= *_First && *_First <= '9'))
				return false;
			else
				_First++;
		return true;
		}

	bool IsIni(_Ty _First)
		{ // is ini
		char set[] = OPERATOR_SET;
		for(int i = 1; i <= 6; i++)
			if(_First == set[i])
				return true;
		return false;
		}

	bool IsScs(_Ty *_That)
		{
		char set[] = SPECIFICOPERATOR_SET;
		char jjj[13];

		}

	};


template<class _Ty0>
	struct _stack_nodes
	{ // nodes
	_Ty0 _DATA;
	_stack_nodes *_NEXT;
	_stack_nodes *_PREV;
	};

template<class _Ty0> inline
	void __remove(_stack_nodes<_Ty0> 
		*&_First, _stack_nodes<_Ty0> *&_Second)
	{ // vector remove
		_stack_nodes<_Ty0> *first = _First->_NEXT->_NEXT;
	for( ; first != _Second; first = first->_NEXT);
		delete first->_PREV;
	delete _First;
	delete _Second;
	}

template<class _Stack_Element>
	class tree_stack
	{ // stack class
	_stack_nodes<_Stack_Element> *_Head;
	_stack_nodes<_Stack_Element> *_Lastest;
	_stack_nodes<_Stack_Element> *_Tail;
public:
	explicit tree_stack()
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
	virtual ~tree_stack()
	{ // stack desconductor
	__remove(_Head, _Tail);
	}
	void push(_Stack_Element _left)
	{ // push back item
	_stack_nodes<_Stack_Element> *temp = _New_Node();
	temp->_DATA = _left;
	_Connects(_Lastest, temp, _Tail);
	_Lastest = temp;
	}
	_Stack_Element& pop()
	{ // pop back item
	_stack_nodes<_Stack_Element> *ptr = _Tail->_PREV;
	_stack_nodes<_Stack_Element> *prev = _Tail->_PREV->_PREV;
	_Stack_Element ret;
	ret = ptr->_DATA;
	delete ptr;
	_Connect(prev, _Tail);
	return ret;
	}
private:
	inline void _Connect(
		_stack_nodes<_Stack_Element> *_head,
			_stack_nodes<_Stack_Element> *_tail)
	{ // connect link
	_head->_NEXT = _tail;
	_tail->_PREV = _head;
	}
	inline void _Connects(
	_stack_nodes<_Stack_Element> *_First,
			_stack_nodes<_Stack_Element> *_Target,
					_stack_nodes<_Stack_Element> *_Last)
	{ // nodes connect
	_First->_NEXT = _Target;
	_Target->_PREV = _First;
	_Target->_NEXT = _Last;
	_Last->_PREV = _Target;
	}
	inline _stack_nodes<_Stack_Element> *_New_Node()
	{ // create new node
	_stack_nodes<_Stack_Element> *ptr = new  
		_stack_nodes<_Stack_Element>;
	return ptr;
	}
	};

template<class _Ty2>
	class leaf
	{ // leaf of tree
public:
	leaf *left, *right;
	_Ty2 _data;
	inline _Ty2& operator*()
		{ return _data; }
	};

template<class _Ty2> inline
	void swap_lr_l(leaf<_Ty2>*& _first)
	{ // swap left right leaf
	leaf<_Ty2> *right = _first->right;
	_first->right = _first->left;
	_first->left = right;
	}

template<typename unchecked_type> inline
	void _swap(unchecked_type& _Left, unchecked_type& _Right)
	{ // fill all by what parameter
	unchecked_type t = _Left; 
	_Left = _Right; 
	_Right = t;
	}

template<class _Ty0> inline 
	_Ty0 *new_leaf()
	{ // new leaf
	_Ty0 *ptr = new _Ty0;
	return ptr;
	}

	// STANDRAD Tree
template<class _Tree_Element>
	class tree
	{ // tree
	typedef leaf<_Tree_Element> _MyLeaf;
	_MyLeaf *_Head;
	tree_stack<_MyLeaf *> _Stack;
public:
	tree()
		{ // entry point
		_Head = new_leaf<_MyLeaf>();
		suture(_Head);
		_Head->_data = 0;
		}
	void left(_Tree_Element _datas)
		{ // left
		_MyLeaf *ptr = new_leaf<_MyLeaf>();
		suture(ptr);
		ptr->_data  = _datas;
		_Head->left = ptr;
		}
	void right(_Tree_Element _datas)
		{ // left
		_MyLeaf *ptr = new_leaf<_MyLeaf>();
		suture(ptr);
		ptr->_data = _datas;
		_Head->right = ptr;
		}
	_MyLeaf*& left()
		{ return _Head->left; }
	_MyLeaf*& right()
		{ return _Head->right; }
	void visit_left()
		{ // visit left
		_Stack.push(_Head);
		_Head = _Head->left;
		}
	void visit_right()
		{ // visit right
		_Stack.push(_Head);
		_Head = _Head->right;
		}
	_Tree_Element& operator*()
		{ return (_Head->_data); }
	_MyLeaf*& operator&()
		{ return _Head; }
	void leave()
		{ _Head = _Stack.pop(); }
private:
	inline void suture(_MyLeaf *that)
		{ // suture
		that->left = that;
		that->right = that;
		}
	};

	// TREE ROTATE ALGORITHM
template<class _Ty1> inline
	void _tree_rotate_right(tree<_Ty1>& _first)
	{ // rotate right (1,2,3) -> (2,3,1)
	leaf<_Ty1> *_head = &_first,	// 1
		*_right = _first.right(),	// 2
		*_left = _first.left();		// 3
	_swap(_head->_data, _right->_data); // (1,2,3) -> (3,2,1)
	_swap(_head->_data, _left->_data); // (3,2,1) -> (2,3,1)
	}

template<class _Ty1> inline
	void _tree_rotate_left(tree<_Ty1>& _first)
	{ // rotate right (1,2,3) -> (3,1,2)
	leaf<_Ty1> *_head = &_first,	// 1
		*_right = _first.right(),	// 2
		*_left = _first.left();		// 3
	_swap(_head->_data, _left->_data); // (1,2,3) -> (2,1,3)
	_swap(_head->_data, _right->_data); // (2,1,3) -> (3,1,2)
	}

	// TREE SWAP ALGORITHM
template<class _Ty3> inline
	void _tree_swap_sr_tr(tree<_Ty3>& _first)
	{ // swap second right <-> third right
	leaf<_Ty3> *_l = _first.left()->right,
			*_r = _first.right();
	_swap(_r->_data, _l->_data);
	}

template<class _Ty3> inline
	void _tree_swap_sl_tl(tree<_Ty3>& _first)
	{ // swap second left <-> third left
	leaf<_Ty3> *_l = _first.right()->left,
			*_r = _first.left();
	_swap(_r->_data, _l->_data);
	}

template<class _Ty3> inline
	void _tree_swap_ftl_str(tree<_Ty3>& _first)
	{ // f_third right - s_third left
	leaf<_Ty3> *_l = _first.left()->right,
			*_r = _first.right()->left;
	_swap(_r->_data, _l->_data);
	}

template<class _Ty3> inline
	void _tree_swap_ftr_stl(tree<_Ty3>& _first)
	{ // f_third left - s_third right
	leaf<_Ty3> *_l = _first.left()->left,
			*_r = _first.right()->right;
	_swap(_r->_data, _l->_data);
	}

template<class _Ty3> inline
	void _tree_swap_ftl_stl(tree<_Ty3>& _first)
	{ // f_third left - s_thid left
	leaf<_Ty3> *_l = _first.left()->left,
			*_r = _first.right()->left;
	_swap(_r->_data, _l->_data);
	}

template<class _Ty3> inline
	void _tree_swap_ftr_str(tree<_Ty3>& _first)
	{ // f_third right - s_third right
	leaf<_Ty3> *_l = _first.left()->right,
			*_r = _first.right()->right;
	_swap(_r->_data, _l->_data);
	}

template<class _Ty3> inline
	void _tree_swap(tree<_Ty3>& _first)
	{ // f_second - s_second
	leaf<_Ty3> *_l = _first.left(),
			*_r = _first.right();
	_swap(_r->_data, _l->_data);
	}

template<class _Ty3> inline
	void _tree_swap_s_tr(tree<_Ty3>& _first)
	{ // second - right third
	leaf<_Ty3> *_rl = _first.right()->left,
			*_rr = _first.right()->right;
	_swap(_first.left()->_data, _rl->_data);
	_swap(_first.right()->_data, _rr->_data);
	}

template<class _Ty3> inline
	void _tree_swap_s_tl(tree<_Ty3>& _first)
	{ // second - right left
	leaf<_Ty3> *_rl = _first.left()->left,
			*_rr = _first.left()->right;
	_swap(_first.left()->_data, _rl->_data);
	_swap(_first.right()->_data, _rr->_data);
	}


typedef enum
	{ // traverse sign
	Preorder, Postorder, Inorder
	} traverse_sign;

template<class _Ty0>
	class traver
	{ // tree traver
	typedef leaf<_Ty0> _MyLeaf;
	_MyLeaf *_Head, *Prev;
	tree_stack<_MyLeaf *> _Stack;
	traverse_sign g;
	int tree_deep;
public:
	traver(tree<_Ty0>& _tree, traverse_sign f)
		: _Head((&_tree)), g(f), tree_deep(0)
		{ }
	_MyLeaf*& operator*()
		{ // return now form
		return _Head;
		}
	bool operator++()
		{ // operator ++
		if (g == Preorder)
			{
			if(_Head != _Head->left){tree_deep++;
				_Stack.push(_Head);_Head = _Head->left; 
				return true;}
			if(_Head != _Head->right){tree_deep++;
				_Stack.push(_Head);_Head = _Head->right;
				return true;}
			tree_deep--;
			for(int i = 0; i <= tree_deep; i++){
				Prev = _Head;
				_Head = _Stack.pop();
				if((_Head != _Head->right) 
					&& _Head->right != Prev){
				_Head = _Head->right;
				return true;}
				}
			tree_deep = 0;
			return false;
			} else 
		if (g == Postorder)
			{
			if(!tree_deep)
				for( ; _Head != _Head->left; _Head = _Head->left, tree_deep++)
					;

			} else
		if (g == Inorder)
			{
			}
		}
	};


#define _VECTOR_ELEMENT_OPERATION(my_) \
	template<class my_>
#define _VECTOR_OPERATOR_ITERS(my_) \
	template<class my_>
#define _VECTOR_ITERATOR(my_, _fn, _cls_) \
	template<class my_>\
		_cls_ _fn{\
		_fn() : {} }

typedef void _Force;
#define __Force __forceinline
#define _Force __Force _Force
typedef bool _Hence;
#define _Hence __Force _Hence
namespace _vector_operation
{
	_VECTOR_ELEMENT_OPERATION(_Ty0)
		struct _VECTOR_NODES
		{ // vector nodes
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
			_Head->_DATA = 0;
			vlock = true;
		}

	virtual ~vector()
		{ // vector desconductor
		_vector_remove(_Head, _Tail);
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


template<class _Pt>
	_Pt* virtual_alloc(int _Val)
	{ // virtual alloc
	void *_Ptr = 0;
	if (_Val)
		_Ptr = ::operator new(_Val * sizeof(_Pt));
	return ((_Pt *)_Ptr);
	}

#define bad_alloc_member(stdyf, stdyt) virtual \
	void  stdyf( stdyt ) {

class _error
	{ // error class
	char *_Msg;
public:
	explicit _error(const char *_lst = 0)
		{ // constructure
		_Msg = const_cast<char *> (_lst);
		}

	void show(char * = 0)
		{ // operand
		call();
		}
private:
	void call()
		{ // Target operand
		show(_Msg);
		}
	};

template<class _Ty0> inline
	int pointer_len(_Ty0 *that)
	{ // pointer len
	_Ty0 *pp = that;
	while(*pp++);
	return pp - that - 1;
	}

template<class _Ty2> inline
	_Ty2& fast_cast(const _Ty2 _lest)
	{ // little cast
	_Ty2 _PtrEx = virtual_alloc<typename 
		remove_pointer<_Ty2>::type> 
			(sizeof(_lest) / sizeof(typename 
				remove_pointer<_Ty2>::type));
	for(int i = sizeof(_lest) / sizeof(typename 
		remove_pointer<_Ty2>::type), f = 0; 
			i >= f; f++)
				_PtrEx[f] = _lest[f];
	return _PtrEx;
	}

template<class _Ty0> inline
	void pointer_back(_Ty0 *that)
	{ // pointer move back
	while(*that++);
	}

template<class _Ty0> inline
	void pointer_front(_Ty0 *that)
	{ // pointer move front
	while(*that--);
	}

template<class _Ty0>
	class const_alloc
	{ // alloc class
	mutable _Ty0 *pointer;
	int point, size;
public:
	explicit const_alloc(_Ty0 *pointer)
		: pointer(pointer), point(0)
		{ // entry point
		size = pointer_len(pointer);
		}
	bool operator++(int)
		{ // point move forward
		if(point == size)
			return false;
		point++, return true;
		}
	bool operator--(int)
		{ // point move back
		if(!point)
			return false;
		point--, return true;
		}
	bool operator+(int _left)
		{ // operator +
		if((point + _left) > size)
			return false;
		point += _left, return true;
		}
	bool operator-(int _left)
		{ // operator -
		if((point - _left) < 0)
			return false;
		point -= _left, return true;
		}
	_Ty0& operator*()
		{ // operator*
		return pointer[point];
		}
	_Ty0& operator()(int _right)
		{ // operator()
		return pointer[size - _right];
		}
	_Ty0& operator[](int _right)
		{ // operator[]
		return pointer[_right];
		}
	};


template<class _In_0>
	struct _xlry_Fn_Lno
	{ // linked node
	public:
	typedef typename __type<_In_0>
		::value_type _Fn_T;
	_xlry_Fn_Lno(_In_0 _First)
		: _data(_First) { /* ... */ }
	_xlry_Fn_Lno() 
		: _data(0) { /* ... */ }
	_xlry_Fn_Lno *_next;
	_xlry_Fn_Lno *_prev;
	_In_0		  _data;
	};

template<class _In_1>
	class _xlry_iter_Fn
	{ // the iterator class
	typedef typename _xlry_Fn_Lno<_In_1> _MyNode;
	_MyNode *point;
	public:
	_In_1& operator*()
		{
		return point->_data;
		}
	void operator++(int)
		{
		point = point->_next->_next;
		}
	void operator--(int)
		{
		point = point->_prev;
		}
	void operator=(_MyNode *_left)
		{
		point = _left;
		}
	bool operator==(_MyNode *_left)
		{
		return point == _left;
		}
	bool operator!=(_MyNode *_left)
		{
		return point != _left;
		}
	bool operator==(_In_1 _left)
		{
		return this->operator* == _left;
		}
	bool operator!=(_In_1 _left)
		{
		return this->operator* != _left;
		}
	bool operator<(_In_1 _left)
		{
		return this->operator* < _left;
		}
	bool operator>(_In_1 _left)
		{
		return this->operator* > _left;
		}
	bool operator<=(_In_1 _left)
		{
		return this->operator* <= _left;
		}
	bool operator>=(_In_1 _left)
		{
		return this->operator* >= _left;
		}
	};

template<class _In_1>
	class _xlry_citer_Fn
	{ // the citerator class
	typedef typename _xlry_Fn_Lno<_In_1> _MyNode;
	_MyNode *point;
	public:
	_In_1 operator*() const
		{
		return point->_data;
		}
	void operator++(int)
		{
		point = point->_next;
		}
	void operator--(int)
		{
		point = point->_prev;
		}
	void operator=(_MyNode *_left)
		{
		point = _left;
		}
	bool operator==(_MyNode *_left) const
		{
		return point == _left;
		}
	bool operator!=(_MyNode *_left) const
		{
		return point != _left;
		}
	bool operator==(_In_1 _left) const
		{
		return this->operator* == _left;
		}
	bool operator!=(_In_1 _left) const
		{
		return this->operator* != _left;
		}
	bool operator<(_In_1 _left) const
		{
		return this->operator* < _left;
		}
	bool operator>(_In_1 _left) const
		{
		return this->operator* > _left;
		}
	bool operator<=(_In_1 _left) const
		{
		return this->operator* <= _left;
		}
	bool operator>=(_In_1 _left) const
		{
		return this->operator* >= _left;
		}
	};

template<class _Out_0,
		class _InputT_ = int>
	class array
	{ // link array fn
	typedef typename _xlry_Fn_Lno<typename 
		__type<_Out_0>::value_type> _MyLno;
	typedef typename 
		__type<_MyLno>::pointer _Input_;
	typedef typename 
		__type<_MyLno>::reference _Output_;

	_MyLno *_Head, *_Tail;
	_InputT_ _Pointer, _Back_PP;
	_MyLno *_Lastest;

	public:

	typedef typename _xlry_iter_Fn<_Out_0> iterator;
	typedef typename _xlry_citer_Fn<_Out_0> const_iterator;

	explicit array() _NOTHROW
		: _Pointer(0), _Back_PP(0)
		{ // array entry
		_Head = _New_Node();
		_Tail = _New_Node();
		__Init(_Head, _Tail);
		}

	__forceinline _MyLno *_New_Node()
		{ // create new node
		_MyLno *ptr = new _MyLno;
		return ptr;
		}

	__forceinline void operator++(_InputT_)
		{ // operator ++
		_Pointer++;
		}

	__forceinline void operator--(_InputT_)
		{ // operator --
		if(!_Pointer)
			_Pointer--;
		}

	__forceinline _MyLno *&begin()
		{ // begin function
		return _Head;
		}

	__forceinline _MyLno *&end()
		{ // end function
		return _Tail;
		}

	_MyLno *operator*()
		{ // operator *
		_MyLno *_Temp = _Head;
		for(_InputT_ Fn_n = 0; 
				Fn_n <= _Pointer; Fn_n++)
			_Temp = _Temp->_next;
		return _Temp;
		}

	_MyLno *&operator&()
		{ // operator &
		_MyLno *_Temp = _Head;
		for(_InputT_ Fn_n = 0; 
				Fn_n <= _Pointer; Fn_n++)
			_Temp = _Temp->_next;
		return _Temp;
		}

	_MyLno *&operator[](_InputT_ _First)
		{ // operator []
		_MyLno *_Temp = _Head;
		for(_InputT_ Fn_n = 0; 
				Fn_n <= _First; Fn_n++)
			_Temp = _Temp->_next;
		return _Temp;
		}

	_MyLno *&operator()(_InputT_ _First)
		{ // opeartor ()
		_MyLno *_Temp = _Tail;
		for(_InputT_ Fn_n = 0; 
				Fn_n <= _First; Fn_n++)
			_Temp = _Temp->_prev;
		return _Temp;
		}

	void push_back(_Out_0 _left)
		{ // push back item
		_MyLno *temp = _New_Node();
		temp->_data = _left;
		if (_Back_PP)
			__Connect(_Lastest, temp, _Tail);
		else
			__Connect(_Head, temp, _Tail);
		_Lastest = temp;
		_Back_PP++;
		}

	void push_front(_Out_0 _left)
		{ // push back item
		_MyLno *temp = _New_Node();
		temp->_data = _left;
		__Connect(_Head, temp, _Head->_next);
		_Lastest = temp;
		_Back_PP++;
		}

	_Out_0 pop_back()
		{ // pop back item
		_MyLno *ptr = _Head;
		_MyLno *prev = _Head;
		_Out_0 ret;
		for(int f = -1; ; f++)
			{
			if(ptr == _Tail)
				break;
			ret = ptr->_data;
			if(f > 0)
				prev = prev->_next;
			ptr = ptr->_next;
			}
		delete prev->_next;
		_Connect(prev, _Tail);
		_Back_PP--;
		return ret;
		}

	_Out_0 pop_front()
		{ // pop back item
		_MyLno *ptr = _Head->_next;
		_Out_0 ret = ptr->_data;
		_Connect(_Head, ptr->_next);
		delete ptr;
		_Back_PP--;
		return ret;
		}

	private:

	__forceinline void _Connect(_MyLno *_head, _MyLno *_tail)
		{ // connect link
		_head->_next = _tail;
		_tail->_prev = _head;
		}
	
	__forceinline void __Connect(_MyLno *_head, 
			_MyLno *_target, _MyLno *_tail)
		{ // connect link
		_head->_next = _target;
		_target->_prev = _head;
		_target->_next = _tail;
		_tail->_prev = _target;
		}

	__forceinline void __Init(_MyLno *_head, _MyLno *_tail)
		{ // initialization the link
		_head->_prev = _head;
		_head->_next = _tail;
		_head->_prev = _head;
		_tail->_next = _tail;
		}

	protected:
		array *_Compho;
	};


template<class _Ty0> inline
	int strlen(_Ty0 *that)
	{ // strlen
	for( int i = 0; ; )
		if(!that[++i])
			return i;
	}

template<class _Ty0> inline
	int f_len(_Ty0 *that)
	{ // f len
	_Ty0 *pp = that;
	while(*pp++);
	return pp - that - 1;
	}

template<class _String_Element = char>
	class string
	{ // string class

	vector<_String_Element> str;
	bool reverses;

	public:

		string()
			: reverses(false)
			{ }

		string(_String_Element* _valuable_char)
			: reverses(false)
			{ // entry
			char_put(_valuable_char);
			}

		string(const _String_Element* _const_char)
			: reverses(false)
			{ // entry
			char_put(const_cast<_String_Element*> (_const_char));
			}

		inline _String_Element& operator[](int pos)
			{ // operator[]
			if(!reverses)
				return str[pos];
			else
				return str(pos);
			}

		inline void reverse()
			{ // str reverse
			reverses = true;
			}

		inline int lenth()
			{ // length
			return str.size();
			}

		_String_Element* operator*()
			{ // operator *
			int len = lenth();
			_String_Element *ret = new _String_Element[len];
			if(!reverses)
				for(int n = 0; n < len; n++)
					ret[n] = str[n]->_DATA;
			else
				for(int n = 0; n < len; n++)
					ret[n] = str(n)->_DATA;
			ret[len] = 0;
			return ret;
			}

		inline void operator+=(_String_Element* _valuable_char)
			{ // operator +=
			char_put(_valuable_char);
			}

		inline void operator+=(const _String_Element* _const_char)
			{ // operator +=
			char_put(const_cast<_String_Element*> (_const_char));
			}

		inline void operator+=(int _valuable_int)
			{ // operator +=
			char_put(itoas<char> (_valuable_int));
			}

		inline vector<_String_Element> &ch_n()
			{ // vector return
			return str;
			}

		string<_String_Element> &operator<(_String_Element *get)
			{ // operator +=
			char_put(get);
			return *this;
			}

		string<_String_Element> &operator<(const _String_Element *get)
			{ // operator +=
			char_put(const_cast<_String_Element*> (get));
			return *this;
			}

		string<_String_Element> &operator<(string<_String_Element> &get)
			{ // operator +=
			char_put(*get);
			return *this;
			}

		string<_String_Element> &operator>(_String_Element *get)
			{ // operator +=
			char_put_r(get);
			return *this;
			}

		string<_String_Element> &operator>(const _String_Element *get)
			{ // operator +=
			char_put_r(const_cast<_String_Element*> (get));
			return *this;
			}

		string<_String_Element> &operator>(string<_String_Element> &get)
			{ // operator +=
			char_put_r(*get);
			return *this;
			}

		void replace_test(string<_String_Element> &retchars, 
				string<_String_Element> &gotchars)
			{ // replace test
			_vector_replace2(str, retchars.ch_n(), gotchars.ch_n());
			}

		void replace(string<_String_Element> &retchars, 
				string<_String_Element> &gotchars)
			{ // replace
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> 
					*start = str.front();
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> 
					*last = str.front();
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> 
					*buf = gotchars.ch_n().front();
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> 
					*publicq = 0;
			int i = replace_find(retchars), 
				f = i + gotchars.lenth();
			for(int d = 0; d < i; d++)
				start = start->_NEXT;
			for(int d = 0; d <= f; d++)
				last = last->_NEXT;
			buf->_PREV = start;
			start = gotchars.ch_n().front();
			buf->_NEXT = last;
			publicq = last;
			last = gotchars.ch_n().back();
			publicq->_NEXT = last;
			}

	private:

		inline void char_put(_String_Element *_char)
			{ // char put
			int f = strlen(_char);
			if(!reverses)
				for(int i = 0; i < f; i++)
					str.push_back(_char[i]);
			else
				for(int i = 0; i < f; i++)
					str.push_front(_char[i]);
			}

		inline void char_put_r(_String_Element *_char)
			{ // char put
			int f = strlen(_char);
			if(!reverses)
				for(int i = 0; i < f; i++)
					str.push_front(_char[i]);
			else
				for(int i = 0; i < f; i++)
					str.push_back(_char[i]);
			}

		inline int replace_find(string<_String_Element> &retchars)
			{ // replace find equal
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> *start = str.front();
			_VECTOR_OPERATION 
				_VECTOR_NODES<_String_Element> *s_start = retchars.ch_n().front();
			int n = retchars.lenth(), f = lenth();
			for(int i = 0; i <= f; i++, start = start->_NEXT)
				if(start->_DATA == s_start->_DATA)
					for(int fd = i; fd <= i+n; fd++, start = start->_NEXT,
							s_start = s_start->_NEXT)
						if(fd == i + n)
							return i;
						else 
							if(start->_DATA != s_start->_DATA)
								break;
			}
	
	};

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/