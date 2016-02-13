/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _GRAPH
#define _GRAPH

#include "literator.h"

template<class _llist> struct
	simple_graph_list
	{ // linked list
	typedef struct simple_graph_list* str_pointer;
	typedef _llist* pointer;
	typedef _llist* const_pointer;
	typedef _llist& reference;
	typedef _llist& const_reference;
	typedef _llist value_type;
	str_pointer _Next;
	str_pointer _Prev;
	str_pointer _Loop;
	value_type _Data;
	};

template<class _graph> class
	basic_simple_graph_literator
		: public literator<_graph>
	{
	typedef typename _graph::value_type value_type;

public:
	
	value_type operator()(bool b)
		{ // get _loop data set
		if(!b)
			return **this;
		else{
			_Ptr = _Ptr->_Loop;
			return _Ptr->_Data;
			}
		}
	
	void operator=(_graph* ptr)
		{ // put data into ptr
		_Ptr = ptr;
		}

	};

template<class _graph> class
	const_basic_simple_graph_literator
		: public const_literator<_graph>
	{
	typedef typename _graph::value_type value_type;

public:
	
	value_type operator()(bool b)
		{ // get _loop data set
		if(b)
			return **this;
		else{
			_Ptr = _Ptr->_Loop;
			return _Ptr->_Data;
			}
		}
	
	void operator=(_graph* ptr)
		{ // put data into ptr
		_Ptr = ptr;
		}

	};

template<class _graph> class
	basic_simple_graph
	{ // basic simple graph
public:
		
	typedef simple_graph_list<_graph> _MyList;
	
	typedef typename _MyList& reference;
	typedef typename _MyList* pointer;
	typedef typename _MyList::value_type value_type;
	typedef typename _MyList::pointer _MyPtr;
	typedef typename _MyList::reference _MyRef;

	typedef basic_simple_graph_literator<_MyList> iterator;
	typedef const_basic_simple_graph_literator<_MyList> const_iterator;

	pointer Head;
	pointer Current;
	pointer Tail;

	basic_simple_graph()
		{ // create head
		Head = new _MyList;
		Head->_Prev = Head;
		Tail = new _MyList;
		Tail->_Next = Tail;
		bind_llist(Head, Tail);
		Current = Head;
		}

	virtual void push(value_type data)
		{ // push back function
		pointer x = new _MyList;
		x->_Prev = Current;
		x->_Next = Tail;
		x->_Data = data;
		Current->_Next = x;
		Current = x;
		}

	virtual value_type pop()
		{ // pop back funciton
		value_type tmp = Current->_Data;
		pointer x = Current->_Prev;
		delete Current;
		Current = x;
		bind_llist(Current, Tail);
		return tmp;
		}

	pointer begin()
		{ // get start point of llist
		return Head->_Next;
		}

	pointer end()
		{ // get end point of llist
		return Tail;
		}

	};

template<class _graph> class
	simple_graph	: 
			public basic_simple_graph<_graph>
	{ // simple graph
	basic_simple_graph<pointer> stack;
public:

	void save()
		{ // save now point
		stack.push(Current);
		}

	void load()
		{ // load now point
		Current->_Loop = stack.pop()->_Next;
		}

	};

typedef simple_graph<char> automata;

template<class _llist> struct
	graph_list
	{ // linked list
	typedef struct graph_list* str_pointer;
	typedef _llist* pointer;
	typedef _llist* const_pointer;
	typedef _llist& reference;
	typedef _llist& const_reference;
	typedef _llist value_type;
	str_pointer _Left;
	str_pointer _Right;
	value_type _Data;
	int point;
	};

template<class _graph> class
	binary_tree
	{ // binary tree
	typedef graph_list<_graph> _MyList;
	
	typedef typename _MyList& reference;
	typedef typename _MyList* pointer;
	typedef typename _MyList::value_type value_type;
	typedef typename _MyList::pointer _MyPtr;
	typedef typename _MyList::reference _MyRef;
/*
	typedef literator<_MyList> iterator;
	typedef const_literator<_MyList> const_iterator;*/

	pointer Head;
	pointer Current;

	basic_simple_graph<_MyList> _Stack;
public:

	binary_tree()
		{ // create head
		Head = new _MyList;
		bind_own(Head);
		Head->_Data = 0;
		Current = Head;
		}

	void left(value_type _Dt)
		{ // left
		pointer ptr = new _MyList;
		bind_own(ptr);
		ptr->_Data  = _Dt;
		Current->_Left = ptr;
		}

	void right(value_type _Dt)
		{ // right
		pointer ptr = new _MyList;
		bind_own(ptr);
		ptr->_Data  = _Dt;
		Current->_Right = ptr;
		}

	pointer left()
		{ // left
		return Current->_Left;
		}

	pointer right()
		{ // right
		return Current->_Right;
		}

	void visit_left()
		{ // visit left
		_Stack.push(Current);
		Current = Current->_Left;
		}

	void visit_right()
		{ // visit right
		_Stack.push(Current);
		Current = Current->_Right;
		}

	value_type operator*()
		{ // get current data
		return (Current->_Data);
		}

	void leave()
		{ // leave now
		Current = _Stack.pop();
		}
	
private:

	inline void bind_own(pointer that)
		{ // bind own
		that->_Left = that;
		that->_Right = that;
		}

	};

#endif