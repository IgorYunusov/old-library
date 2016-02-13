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

#ifndef __parse_metry
#define __parse_metry

#include "vector.h"

#define __force_cast(_t)		(_t *)(void *)

typedef unsigned int size_t;

#define _INCREASE(x)		x += 1
#define _DECREASE(x)		x -= 1

template<typename _parse> 
	size_t __length(const _parse *_T)
    { // get lenth
	const _parse *_Ptr = _T;
	for( ; *_Ptr; _Ptr++)
		;
	return (_Ptr - _T - 1);
    }

template<class _parse = char> class
	____tx__parse__limited
	{
	_parse *_Ptr;
	size_t Size;
public:
	____tx__parse__limited() : _Ptr(0), Size(0) {}
	~____tx__parse__limited() {if(_Ptr) delete[] _Ptr;}
	void push_back(_parse value)
		{
		_parse *_xtt = new _parse[Size + 1];
		for(int i = 0; i < Size; i++)
			_xtt[i] = _Ptr[i];
		_xtt[Size] = value;
		Size++;
		_Ptr = _xtt;
		}
	void push_front(_parse value)
		{
		_parse *_xtt = new _parse[Size + 1];
		for(int i = 0; i < Size; i++)
			_xtt[i + 1] = _Ptr[i];
		*_xtt = value;
		Size++;
		_Ptr = _xtt;
		}
	_parse pop_back()
		{
		_parse *_xtt = new _parse[Size - 1];
		_parse atret = _Ptr[Size - 1];
		for(int i = 0; i < (Size - 1); i++)
			_xtt[i] = _Ptr[i];
		_Ptr = _xtt;
		Size--;
		return atret;
		}
	_parse pop_front()
		{
		_parse *_xtt = new _parse[Size - 1];
		_parse atret = *_Ptr;
		for(int i = 0; i < (Size - 1); i++)
			_xtt[i] = _Ptr[i + 1];
		_Ptr = _xtt;
		Size--;
		return atret;
		}
	void deletex()
		{
		Size ^= Size;
		delete[] _Ptr;
		_Ptr = 0;
		}
	void deletenone()
		{
		Size ^= Size;
		_Ptr = 0;
		}
	bool operator*()
		{
		return Size != 0;
		}
	bool get_one()
		{
		return Size != 1;
		}
	_parse& back()
		{
		return _Ptr[Size - 1];
		}
	_parse& front()
		{
		return *_Ptr;
		}
	_parse*& operator&()
		{
		return _Ptr;
		}
	};

template<class _parse> inline bool
	one_match(const _parse *x, const _parse y)
	{
	const _parse *ptr = x;
	for( ; *ptr; ptr++)
		if(y == *ptr)
			return true;
	return false;
	}

#endif