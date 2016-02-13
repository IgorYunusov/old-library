/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef ___llist
#define ___llist

template<class _llist> struct
	llist
	{ // linked list
	typedef struct llist* str_pointer;
	typedef _llist* pointer;
	typedef _llist* const_pointer;
	typedef _llist& reference;
	typedef _llist& const_reference;
	typedef _llist value_type;
	str_pointer _Next;
	str_pointer _Prev;
	value_type _Data;
	};

template<class _ll> inline
	void bind_llist(_ll _Left, 
		_ll _Right)
		{ // bind list
		_Left->_Next = _Right;
		_Right->_Prev = _Left;
		}

#endif