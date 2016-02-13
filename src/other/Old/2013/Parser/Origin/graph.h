/*
            ROLLRAT MATHEMATICS PROJECT

             Cpy (c) 14. ALL RIGHTS RESERVED.
   */

#ifndef _GRAPH_
#define _GRAPH_
#pragma once

#include "mathematics.h"
#include "matrix.h"

template<class _PtrRef, class _Hash = unsigned int> 
class GraphNodeEx{
public:
	// ZERO REEL COMPATIBILITY
	typedef typename _PtrRef value_type;
	typedef typename _PtrRef* pointer;
	typedef typename _PtrRef& reference;
	typedef typename const _PtrRef* const_pointer;
	typedef typename const _PtrRef& const_reference;
	typedef class GraphNodeEx<_PtrRef> * str_pointer;

	GraphNodeEx() : 
		_Data(0), _Hash(0), _Next(nullptr), _Prev(nullptr)
		{
		}
	GraphNodeEx(_PtrRef _data, _PtrRef _hash) : 
		_Data(_data), _Hash(_hash), _Next(nullptr), _Prev(nullptr)
		{
		}

	inline _PtrRef& operator*()
		{
		return _Data;
		}

	GraphNodeEx<_PtrRef> *_Next, *_Prev;
	_PtrRef _Data;
	_Hash _Hash;
	};

template<class _type, typename size_type = unsigned int>
class Graph
	{
public:
	typedef typename GraphNodeEx<_type> _Graph;
	typedef typename GraphNodeEx<_type> *_Graph_Ptr;
	
	size_type _last_hash;
	size_type size;

	Matrix<> mat;

	Graph()
		: size(0), _last_hash(0)
		{
		}

	explicit Graph(size_type _Size)
		: size(_Size), _last_hash(0)
		{
		mat = new Matrix<> (_Size);
		}

	void operator()(size_type hash)
		{
		}

	};

#endif