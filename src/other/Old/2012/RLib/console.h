/*=================================================

			RollRat Software Expression

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _console_
#define _console_

#include "algorithm.h"

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

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

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0001****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/