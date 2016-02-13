/*--------------------------------------------------------------------

		AIM Library
		(Another Imaginary Management)

		Copyright (c) Kuroko_decs. 2013. All rights reserved.

--------------------------------------------------------------------*/

#pragma once

#ifndef _AIM_LIB_EXARRAY
#define _AIM_LIB_EXARRAY

template<class _Ale>
	class _smart_array
	{ // not smart ptr
public:

	explicit _smart_array()
		: ptr(0) , size(0)
#ifdef _FLAG_USING_ARRAYPTR_INTEGER
		, point(0)
#endif
		{ // ep
		}

	~_smart_array()
		{ // lp
		delete[] ptr;
		}

	void operator+=(const _Ale x)
		{ // oper +==
		ptr = keep(size++ + 1, ptr);
		ptr[size - 1] = x;
		return;
		}
	
	void resize_nokeep(const size x)
		{ // no keep resize
		ptr = new _Ale[x];
		size = x;
		return;
		}

	void resize(const size x)
		{ // resize keep
		ptr = keep(x, ptr);
		size = x;
		return;
		}

	void operator+=(const size x)
		{ // oper +== size
		ptr = keep(size + x, ptr);
		size += x;
		return;
		}

	void operator-=(const size x)
		{ // oper -== size
		ptr = keep(size - x, ptr);
		size -= x;
		return;
		}

private:

	template<class _x>
	_Ale *keep(_x sizex, const _Ale *x)
		{ // resize keep
		_Ale *sizex = new _Ale[sizex];
		if(sizex < size)
			for(int xy = 0; xy < sizex; xy++)
				sizex[xy] = x[xy];
		else
			for(int xy = 0; xy < size; xy++)
				sizex[xy] = x[xy];
		return sizex;
		}



	_Ale *ptr;
#ifdef _FLAG_USING_ARRAYPTR_INTEGER
	size point;
#endif
	size size;

	};

#endif