/*-------------------------------------------------

		RollRat Software Vertex Class

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

/***********************************************************

		 _____    __  __   ______           __
		/  __ |___\ \ \ \ /  __  | __   _ __\ \__
		| |_| | _ \ | | | | |__| |/  \_| |/___  _/
		|  __/ (_)| | | | |  _  / |(_)  |   | |
		| |  \ ___/ |_| |_| | \ \ \____/    | |
		\_/ \_\    \__\\__\_/  \_\          \_\

		RollRatSoftware-PrivateProgrammingLab

	Copyright (c) rollrat. 2009-2013 All rights reserved.


************************************************************/

#pragma once
#ifndef _ROLLRAT_VERTEX_
#define _ROLLRAT_VERTEX_

#include "libVectorR.h"

template<class _TD> 
class Vertex
{
public:
	struct VERTEX_INFO
	{
		struct VERTEX_SIZE
		{
			_TD X;
			_TD Y;
			_TD Z;
		};
		VERTEX_SIZE w1;
		VERTEX_SIZE w2;
		VERTEX_SIZE w3;
	};

public:

	Vertex()
		:
		{
		}
	~Vertex()
		{
			Release();
		}
	void CreateVertex(VERTEX_INFO vtx)
		{
			TVTBuf.push_back(vtx);
		}
	_TD operator[](int size_)
		{
			if(size_<=TVTBuf.Size())
				return TVTBuf[size_];
		}
	_TD operator[](int size_) const
		{
			if(size_<=TVTBuf.Size())
				return TVTBuf[size_];
		}
	void Release()
		{
			TVTBuf.Release();
		}

private:

	Vector<VERTEX_INFO> TVTBuf;

};

typedef Vertex<int>		Vtx_Int;
typedef Vertex<long>	Vtx_Long;
typedef Vertex<float>	Vtx_Float;

#define VERTEX_INFO( _type ) Vertex<_type>::VERTEX_INFO

#endif