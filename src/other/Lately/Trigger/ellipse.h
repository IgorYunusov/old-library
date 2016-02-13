/*************************************************************************
 *
 * FILE NAME : ellipse.h - Data Structure
 *
 * ROLLRAT LIBRARY
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.11.13
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _ELLIPSE_
#define _ELLIPSE_

#include <tuple>

template<class _Ty1, 
	class _Ty2> 
	class ellipse_node
	{
public:
	typedef ellipse_node<_Ty1, _Ty2> _Myt;

	_Myt *left, *right;
	_Ty1 key;
	_Ty2 value;
	};

template<class _Ty1, 
		class _Ty2> 
	class ellipse 
	{	// ?I?O queue
public:
	typedef ellipse<_Ty1, _Ty2>		_Myt;
	typedef ellipse_node<_Ty1, _Ty2>	_Mynode;
	_Mynode *last;

	ellipse()
		: last(nullptr), _size(0)
		{
		}

	void push(_Ty1 key, _Ty2 value)
		{
		if(last == nullptr) {
			last = cnode();
			last->key = key;
			last->value = value;
			_size++;
		} else {
			_Mynode *node = cnode();
			node->left = last;
			node->right = last->right;
			last->right = node;
			node->key = key;
			node->value = value;
			last = node;
			_size++;
		}
		}

	void pop(_Ty1 key)
		{
		_Mynode *keydata = nullptr;
		for (_Mynode *_first = last, *_last = last->right; 
			_last != _first; _last = _last->right)
			if(_last->key == key) {
				keydata = _last;
				break;
			}
			
		if (keydata != nullptr) {
			keydata->left->right = keydata->right;
			keydata->right->left = keydata->left;
			delete keydata;
			_size--;
		} else if(last->key == key) {
				_Mynode *tmplast = last->right;
				last->left->right = last->right;
				last->right->left = last->left;
				delete last;
				last = tmplast;
				_size--;
			}
		}

	std::tuple<bool, _Ty2> operator[](_Ty1 key)
		{
		_Mynode *keydata = nullptr;
		for (_Mynode *_first = last, *_last = last->right; 
			_last != _first; _last = _last->right)
			if(_last->key == key) {
				keydata = _last;
				break;
			}
		if (keydata != nullptr)
			return std::make_tuple(true, keydata->value);
		else {
			if(last->key == key)
				return std::make_tuple(true, last->value);
			else
				return std::make_tuple(false, last->value);
			}
		}

	template<class _Func> 
		void travel(_Func& function)
		{
		if(last == nullptr)
			return;
		_Mynode *_first = last, *_last = last->right;
		for (;  _last != _first; _last = _last->right)
			function(_last->value);
		if (_last == _first)
			function(_last->value);
		}

	size_t size() const 
		{
		return _size;
		}
	
private:
	_Mynode*& cnode() {
			_Mynode *ret = new _Mynode();
			ret->right = ret;
			ret->left = ret;
			return ret;
		}

	size_t _size;
	};



#endif