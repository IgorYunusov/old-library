/*************************************************************************
 *
 * FILE NAME : graph.h
 *
 * ROLLRAT LIBRARY
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.11.16
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _GRAPH_
#define _GRAPH_

#include "ellipse.h"
#include "matrix.h"
#include <vector>
#include <stack>

	// GRAPH bridge [type]
template<class _Ty1, 
		class _Ty2>
	class bridge_normal 
	{
public:
	_Ty2 left, right;
	_Ty1 bridge_name;
	};


	// GRAPH circle [type]
template<class _Ty1,
	class _Ty2>
	class circle_normal
	{
public:
	typedef circle_normal<_Ty1, _Ty2> _Myt;
	//typedef bridge_normal<_Ty2, _Myt *> _Myb;

	_Ty1 key;
	_Ty2 value;
	ellipse<_Ty1, _Myt *> queue;
	//ellipse<_Ty1, _Myb *> queue;
	};
	
	// graph class
class graph_normal
	{
	};

	// graph option class - bridge
class graph_bridge
	{
	};

	// graph option class - direction
class graph_direction
	{
	};

	// graph
template<class _Ty1,	// key type
	class _Ty2,			// data type
	class _Option = graph_normal>
	class graph
	{
	};

template<class _Ty1,
	class _Ty2>
	class graph<_Ty1, _Ty2, graph_normal>
	{
public:
	typedef circle_normal<_Ty1, _Ty2> _Circle;
	_Circle *_Center;
	std::stack search_stack;

	graph(const Matrix<bool>& _graph, const std::vector<_Ty1>& keys,
			const std::vector<_Ty2>& data) 
		{
		if (_graph.column != _graph.row)
			throw new std::string("This is not square matrix.");
		if (_graph.column != data.size())
			throw new std::string("The number of data and the size of the matrix is different.");
		if (keys.size() != data.size())
			throw new std::string("The size of keys and the size of the matrix is different.");
		createFromMatrix(_graph, keys, data);
		}

	ellipse<_Ty1, _Circle *> get_this_queue()
		{
		return _Center->queue;
		}

private:

	void createFromMatrix(const Matrix<bool>& _graph, const std::vector<_Ty1>& keys,
			const std::vector<_Ty2>& data)
		{
		ellipse<_Ty1, _Circle *> temp;
		for (int i = 0; i < keys.size(); i++){
			_Circle *_temp = new _Circle;
			_temp->key = keys[i];
			_temp->value = data[i];
			temp.push(keys[i], _temp);
			_Center = _temp;
			}
		_Center = std::get<1>(temp[keys[0]]);
		for (int i = 1; i < _graph.row; i++)
			for (int j = i + 1; j <= _graph.column; j++)
				if(_graph(i, j) == true){
					_Circle *rowc = std::get<1>(temp[keys[i-1]]);
					_Circle *columnc = std::get<1>(temp[keys[j-1]]);
					rowc->queue.push(keys[j-1],columnc);
					columnc->queue.push(keys[i-1],rowc);
				}
		}

	};

#endif