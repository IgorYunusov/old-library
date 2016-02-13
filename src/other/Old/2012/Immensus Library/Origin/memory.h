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

#ifndef __memory_apvl
#define __memory_apvl

typedef unsigned int size_t;

#define _INCREASE(x)		x += 1
#define _DECREASE(x)		x -= 1

template <typename _AxList> 
	size_t __length(const _AxList *_T)
    { // get lenth
	const _AxList *_Ptr = _T;
	for( ; *_Ptr; _Ptr++)
		;
	return (_Ptr - _T - 1);
    }

template<typename _ApLock>
	_ApLock *__alloc(size_t _Size, _ApLock *)
	{ // safe allocate
	void *_Ptr = 0;
	if(_Ptr = new _ApLock(_Size * sizeof(_ApLock)))
		;
	else
		_Ptr = 0;
	return ((_ApLock *)(_Ptr));
	}

template<typename _EnLock>
	_EnLock *__realloc(_EnLock *_Origin, size_t _Size_origin, size_t _Size)
	{ // realloc
	_EnLock *_Ptr = __alloc(_Size, _Origin);
	if(_Size_origin >= _Size)
		for(int i = 0; i < _Size_origin; i++)
			_Ptr[i] = _Origin[i];
	else
		for(int i = 0; i < _Size; i++)
			_Ptr[i] = _Origin[i];
	return _Ptr;
	}

template<class _Ty> inline
	_Ty *AddressOf(_Ty& _Val)
	{	// return address of _Val
	return (reinterpret_cast<_Ty *>(
		(&const_cast<char&>(
		reinterpret_cast<const volatile char&>(_Val)))));
	}

/*============================================================================

		1 Generation Pointer/ Address

============================================================================*/

template<class _AxList, 
	class _Accerlates = _AxList *> class
	___tg1_lock_ptr
	{ // ptr to (Ax) or int to (Ax)
public:
	static inline _Accerlates Lock(_AxList& _px)
		{ // Lock
		_Accerlates _x = reinterpret_cast<_Accerlates>
			(&reinterpret_cast<char &> (_px));
		return _x;
		}

	static inline _AxList& UnLock(_Accerlates _tx)
		{ // UnLock
		return *reinterpret_cast<_AxList *> (_tx);
		}
	};

#define __Lock_Int(x)	___tg1_lock_ptr<x, int>::

template<class _AxList> class
	___tg1_memory_ptr
	{ // memory manager
	int lock_ptr;
public:
	inline void Put(_AxList *ptr)
		{ // put pointer
		lock_ptr = __Lock_Int(_AxList *)Lock(ptr);
		}

	inline _AxList *Get()
		{ // get pointer
		return __Lock_Int(_AxList *)UnLock(lock_ptr);
		}
	};

template<class _AxList> class
	___tg1_argv_ptr
	{ // argv pointer
	int *xt;
	size_t xtsize;
	typedef ___tg1_argv_ptr<_AxList> __AxTG8;
public:
	___tg1_argv_ptr()
		: xt(0), xtsize(0)
		{ // main
		xt = __alloc(0, xt);
		}

	inline __AxTG8& operator<<(int Lx)
		{ // operator <<
		xt = __realloc(xt, xtsize, xtsize + 1);
		xt[xtsize] = Lx;
		_INCREASE(xtsize);
		return *this;
		}

	template<typename _LxType>
		inline __AxTG8& operator<<(_LxType& Lx)
		{ // operator <<
		xt = __realloc(xt, xtsize, xtsize + 1);
		xt[xtsize] = __Lock_Int(_LxType)Lock(Lx);
		_INCREASE(xtsize);
		return *this;
		}

	__AxTG8& operator<<(__AxTG8*& Lx)
		{ // operator <<
		xt = __realloc(xt, xtsize, xtsize + Lx->xtsize);
		xtsize += Lx->xtsize;
		for(int i = 0; i < Lx->xtsize; i++)
			xt[xt - Lx->xtsize + i] = Lx->xt[i];
		return *this;
		}

	template<typename _LxType>
		inline _LxType getptr(int ghj)
		{ // getptr
		return __Lock_Int(_LxType)UnLock(xt[ghj]);
		}

	size_t operator*()
		{ // get size
		return xtsize;
		}
	};

/*============================================================================

		2 Generation Pointer/ Array

============================================================================*/

template<class _AxList> class
	___tg2__e_array
	{ // pointer
	_AxList *Ptr_ts;
	_AxList *ts_ptr;
	size_t size;
	typedef ___tg2__e_array<_AxList> __AxTG9;
public:
	___tg2__e_array() : Ptr_ts(0), size(0)
		{ // main
		}
	__AxTG9& operator<<(_AxList x)
		{ // operator <<
		push_front(x);
		return *this;
		}
	__AxTG9& operator>>(_AxList x)
		{ // operator <<
		push_back(x);
		return *this;
		}
	void operator()(int y)
		{ // resize array
		__realloc(Ptr_ts, size, y);
		}
	_AxList& operator[](int xt)
		{ // get value
		return Ptr_ts[xt];
		}
	void operator++()
		{ ts_ptr++; }
	void operator--()
		{ ts_ptr--; }
	_AxList operator*()
		{ return *ts_ptr; }
	_AxList& operator&()
		{ return *ts_ptr; }
	void operator^(int y)
		{ return ts_ptr[y]; }
	_AxList* getptr()
		{ return Ptr_ts; }
	void init()
		{ delete[] Ptr_ts; ts_ptr = 0; }
	void push_front(_AxList t)
		{ // push front
		_AxList *Ptr_C = __alloc(size + 1, Ptr_ts);
		for(int i = 0; i < size; i++)
			Ptr_C[i + 1] = Ptr_ts[i];
		_INCREASE(size);
		*Ptr_C = t;
		Ptr_ts = Ptr_C;
		}
	void push_back(_AxList t)
		{ // push back
		_AxList *Ptr_C = __alloc(size + 1, Ptr_ts);
		for(int i = 0; i < size; i++)
			Ptr_C[i] = Ptr_ts[i];
		_INCREASE(size);
		Ptr_C[size] = t;
		Ptr_ts = Ptr_C;
		}
	};

/*============================================================================

		3 Generation Pointer/ Linked List

		(Under Construction.)

============================================================================*/

// from EXCMEM.h
template<class linked_type>
	class _Node
	{ // linked class node struct
public:
	_Node *_NextPtr; // single link
	_Node *_PrevPtr; // double link
	size_t _Key;
	linked_type _data;
	};

// from EXCMEM.h
template<class linked_type>
	class ___tg3__e_link
	{ // linekd class sequencer
	typedef typename _Node<linked_type> _MyNode;

	_MyNode *_Head;
	_MyNode *_Tail;
	_MyNode *_Lastest;
	size_t point;
	int sizeofit;

public:

	___tg3__e_link()
		: _Head(0), _Tail(0), point(-1), sizeofit(0)
		{ // load entry point
		_Head = _New_Node();
		_Tail = _New_Node();
		_Init(_Head, _Tail);
		}
	bool operator++(int)
		{ // point at forward
		if (point < sizeofit-1 || point == -1)
		{
			point++;
			return true;
		}
		point = -1;
		return false;
		}

	bool operator--(int)
		{ // point at back
		if(point)
		{
			point--;
			return true;
		}
		return false;
		}

	bool operator+(int _left)
		{ // point at size +
		point += _left;
		return true;
		}

	bool operator-(int _left)
		{ // point at size -
		if(point >= _left)
		{point -= _left;
		return true;}
		return false;
		}

	_MyNode *_New_Node()
		{ // create new node
		_MyNode *ptr = new _MyNode(sizeof(_MyNode));
		return ptr;
		}

	_MyNode* operator*()
		{ // return node pointed at pointer
		_MyNode *temp = _Head;
		if (!point)
			return temp->_NextPtr;
		else 
			while(temp->_Key != point && temp != _Tail)
				temp = temp->_NextPtr;
		return temp;
		}

	_MyNode& operator&()
		{ // return node pointed at pointer
		_MyNode *temp = _Head;
		if (!point)
			;
		else 
			while(temp->_Key != point && temp != _Tail)
				temp = temp->_NextPtr;
		return temp;
		}

	void push_back(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_Key = sizeofit;
		temp->_data = _left;
		if (sizeofit)
			_Connect(_Lastest, temp, _Tail);
		else
			_Connect(_Head, temp, _Tail);
		_Lastest = temp;
		sizeofit++;
		}

	void _Connect(linked_type _head, linked_type _target, linked_type _tail)
		{ // connect link
		_head->_NextPtr = _target;
		_target->_NextPtr = _tail;
		}

	linked_type pop_back()
		{ // pop back item
		_MyNode *temp = _Head;
		linked_type prev;
		while(temp->_NextPtr != _Tail)
		{
			temp = temp->_NextPtr;
			prev = temp->_data;
		}
		temp->_NextPtr = _Tail;
		delete temp;
		sizeofit--;
		return prev;
		}

	};


#endif