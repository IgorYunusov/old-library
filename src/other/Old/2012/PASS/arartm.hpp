/***********************************************************************

	RollRat Software Array Utilize Technology

	Copyright (c) rollrat. 2013. All rights reserved.

***********************************************************************/

#pragma once

#ifndef __ARARTM
#define __ARARTM

#include "bitctr.h"
namespace starm{

	typedef struct {
		WORD lParam;
		DWORD rParam;
		DWORD rMsgsign;
	}	MSG_STANDARD;

	class _mss_service
	{ // message service
	public:
		void operator=(MSG_STANDARD s){mStd = s;}
		WORD l(){return mStd.lParam;}
		DWORD r(){return mStd.rParam;}
		DWORD m(){return mStd.rMsgsign;}
	private:
		MSG_STANDARD mStd;};

	template<class _Arc_D> class ac_alloc
	{ // arrary controler component(std array, not linked list)
	public:
		explicit ac() : pointx(0), size(0), _arry(0)
		{
		}
		void falloc(int size)
		{
			_arry = new _Arc_D[size];
			this->size = size;
		}
		void operator++()
		{
			if(size != pointx)
				pointx++;
		}
		void operator--()
		{
			if(pointx)
				pointx--;
		}
		_Arc_D& operator[](int i)
		{
			return _arry[i];
		}
		_Arc_D operator*()
		{
			return _arry[pointx];
		}
		_Arc_D& operator&()
		{
			return _arry[pointx];
		}
		_Arc_D*& get()
		{
			return _arry;
		}
	private:
		_Arc_D *_arry;
		int size;
		DWORD pointx;
	};

}
#endif