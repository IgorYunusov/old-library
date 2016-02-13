/*
			RCL - ROLLRAT TRANSPLATABLE LIBRARY
				 R COMPILER LANGUAGE PROJECT

			 Cpy (c) 13-14. ALL RIGHTS RESERVED.
   */

#ifndef _TREE_
#define _TREE_		// regex tree
#pragma once

#include "cstring.h"
//#include "vector.h"

template <class u_type>
class StackNodeEx{
public:
	StackNodeEx() :
		_Next(nullptr)
		{
		}
	StackNodeEx<u_type> * _Next;
	u_type _Data;
	};

template<class u_type>
class stack{
public:
	typedef StackNodeEx<u_type> _MyNode;

	_MyNode * _Current;

	stack()
		{
		_Current = nullptr;
		}

	void push(u_type what)
		{ // push data
		_MyNode *_Tmp = new _MyNode();
		_Tmp->_Data = what;
		if (_Current == nullptr)
			_Current = _Tmp;
		else
			{
			_Tmp->_Next = _Current;
			_Current = _Tmp;
			}
		}

	u_type top()
		{ // get top data
		return _Current->_Data;
		}

	void pop()
		{ // pop data
		_MyNode * _Next = _Current->_Next;
		delete _Current;
		_Current = _Next;
		}

	};

template<class _PtrRef> 
class TreeNode{
public:
	TreeNode() : 
		_Left(nullptr), _Right(nullptr), _Parent(nullptr), _Data(0)
		{
		}
	TreeNode(_PtrRef _data) : 
		_Left(nullptr), _Right(nullptr), _Parent(nullptr), _Data(_data)
		{
		}
	TreeNode<_PtrRef> *_Left, *_Right, *_Parent;
	_PtrRef _Data;
	};

template<class u_type> 
class tree
	{
	typedef typename TreeNode<u_type> _MyN;
	_MyN *_Head, *_Now;
	stack<_MyN *> _Save;
public:

	tree()
		{
		_Head = _NewNode();
		_Now = _Head;
		}

	void go_left()
		{
		if (_Now->_Left == nullptr)
			{
			_Now->_Left = _NewNode();
			_Now->_Left->_Parent = _Now->_Left;
			}
		_Now = _Now->_Left;
		}

	void go_right()
		{
		if (_Now->_Right == nullptr)
			{
			_Now->_Right = _NewNode();
			_Now->_Right->_Parent = _Now->_Right;
			}
		_Now = _Now->_Right;
		}

	void go_left(u_type _Data)
		{
		if (_Now->_Left == nullptr)
			{
			_Now->_Left = _NewNode();
			_Now->_Left->_Parent = _Now->_Left;
			}
		_Now = _Now->_Left;
		set(_Data);
		}

	void go_right(u_type _Data)
		{
		if (_Now->_Right == nullptr)
			{
			_Now->_Right = _NewNode();
			_Now->_Right->_Parent = _Now->_Right;
			}
		_Now = _Now->_Right;
		set(_Data);
		}

	void escape()
		{
		_Now = _Now->_Parent;
		}

	void set(u_type _Data)
		{
		_Now->_Data = _Data;
		}

	u_type& get()
		{
		return _Now->_Data;
		}

	void go_top()
		{
		_Now = _Head;
		}

	void save()
		{
		_Save.push(_Now);
		}

	void load()
		{
		_Now = _Save.pop();
		}

private:

	_MyN*& _NewNode()
		{ // create node
		_MyN* _Tn = new _MyN;
		return _Tn;
		}

	};

///////////////////////////////////////////////////////////////////
////
////	ZERO REEL
////
////	STRUCTURE CLASS AND BASIC ITERATOR
////
///////////////////////////////////////////////////////////////////
	
#define _CLASS_DEFINE_CV(CLASS) \
	CLASS() \
	CLASS(const) \
	CLASS(volatile) \
	CLASS(const volatile)
	
		// TEMPLATE CLASS remove_pointer
template<class _Ty>
	struct remove_pointer
	{	// remove pointer
	typedef _Ty type;
	};

#define _REMOVE_POINTER(CV_OPT) \
template<class _Ty> \
	struct remove_pointer<_Ty *CV_OPT> \
	{	/* remove pointer */ \
	typedef _Ty type; \
	};

_CLASS_DEFINE_CV(_REMOVE_POINTER)

#define IF(dest)			{try { dest; }
#define SWITCH_START(ret)	catch(char *value){ ret result = (ret)value;
#define SWITCH_END			}
#define RETURN				throw (char *)(void *)
#define END_IF				}

#define THROWX				throw()

#define NONE_RET			void

template<class _Ptr> _IN
NONE_RET call(_Ptr& t)
	{ // call
	RETURN (t);
	}

template<class _Ptr> _IN
_Ptr receive(_Ptr t) THROWX
	{ // receive
	IF(call(t))
		SWITCH_START(_Ptr)
			return result;
		SWITCH_END
	END_IF
	return t;
	}

template<class _Ptr> _IN
_Ptr& receive(_Ptr& t) THROWX
	{ // receive
	IF(call(t))
		SWITCH_START(_Ptr&)
			return result;
		SWITCH_END
	END_IF
	return t;
	}

template<class _Ty> _IN
	_Ty *_Address_of(_Ty& _Val)
	{	// return address of _Val because of overloading
	return receive((reinterpret_cast<_Ty *>(
		(&const_cast<char&>(
		reinterpret_cast<const volatile char&>(_Val))))));
	}

#pragma pack( push , 8 ) /* Padding bit */

#define _IN		inline

#define _TADC(x) int hf = make_hash(_Dest); _Addr[count]._Addr = _Addr(_Stru, _Ptr);\
	_Addr[count].size = x; _Addr[count].hash_code = hf; count += 1

#define _Addr(ap, v) *((ap *)_Address_of(v))

//template<class _Stru = char *> 

template<class _Stru = char *,
	int _MAX_STRU = 256> class
	structure
	{ // simple connect structure \
		DO NOT USE, if you are not in a special case.
	typedef struct
		{ // structure app
			_Stru _Addr;
			int hash_code, size;
		} structure_app;
	structure_app *_Addr;
	int count;

public:

	explicit structure()
		: count(0)
		{ // count zero
		_Addr = new structure_app[_MAX_STRU];
		for(int i = 0; i < _MAX_STRU; i++)
			_Addr[i]._Addr = 0;
		}

	_Stru operator[](const char * _Dest)
		{ // push or get addr
		int hf = make_hash(_Dest);
		for(int i = 0; i < count; i++)
			if(_Addr[i].hash_code == hf)
				return _Addr[i]._Addr;
		return 0;
		}

	int offset(const char * _Dest)
		{ // offset of function
		int hf = make_hash(_Dest);
		for(int i = 0, j = 0; i < count; i++)
			if(_Addr[i].hash_code == hf)
				return j - _Addr[i].size + 1;
			else
				j += _Addr[i].size;
		return 0;
		}

	_Stru operator*()
		{ // get structure
		int j = 0;
		for(int i = 0; i < count; i++)
			j += _Addr[i].size;
		if(!j)
			return 0;
		_Stru c_ret = new remove_pointer<_Stru>::type[j];
		for(int i = 0, f = 0; i < count; f += _Addr[i++].size)
			for(j = 0; j < _Addr[i].size; j++)
				c_ret[f + j] = (_Addr[i]._Addr)[j];
		return c_ret;
		}

	template<class _Ty> _IN
		void operator()(const char * _Dest, const _Ty *_Ptr)
		{ // push or get addr
		_TADC(sizeof(_Ty));
		}

	_IN void operator()(const char * _Dest, const char *_Ptr)
		{ // push or get addr
		_TADC(sizeof(char) * strlen_c(_Ptr));
		}

private:

	int strlen_c(const char *_Dest)
		{ // strlen
		const char *_ptr = _Dest;
		while( *_ptr != 0 )
			_ptr++;
		return _ptr - _Dest - 1;
		}

	int make_hash(const char *key)
		{ // make hash function
		int j = 0;
		for(int i = 0; *key; key++)
			j = (j << ((_MAX_STRU | 0x7A64) + i)) + *key;
		return j;
		}
	};

#undef IN
#undef OUT
#define IN(k)	&k
#define OUT(k, t) ((t *)(void *)(k))->

#pragma pack( pop )

template<class _iterator> class
	basic_iterator
	{ // basic iterator
	typedef basic_iterator<_iterator> this_type;
	
	typedef typename _iterator::value_type value_type;
	typedef typename _iterator::pointer pointer;
	typedef typename _iterator::str_pointer str_pointer;
	typedef typename _iterator::reference reference;
public:

	basic_iterator()
		: _Ptr()
		{ // nullptr
		}

	basic_iterator(str_pointer ptr)
		: _Ptr(ptr)
		{ // set pointer
		}

	virtual void operator=(str_pointer ptr)
		{ // set pointer
		_Ptr = ptr;
		}

	virtual pointer operator->()
		{ // return pointer to class object
		return &(**this);
		}

	virtual this_type& operator++()
		{ // pre increment
		if(this->_Ptr->_Next == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Next;
		return (*this);
		}

	virtual this_type operator++(int)
		{ // post increment
		this_type _Tmp = *this;
		++*this;
		return (_Tmp);
		}
	
	virtual this_type& operator--()
		{ // pre decrement
		if(this->_Ptr->_Prev == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Prev;
		return (*this);
		}

	virtual this_type operator--(int)
		{ // post decrement
		this_type _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	virtual reference operator*()
		{ // return
		return (_Ptr->_Data);
		}

	virtual this_type& operator+=(int _Off)
		{ // increment by integer
		if(_Off > 0)
			for( int i = 0; i < _Off; i++)
				++*this;
		else if(_Off < 0)
			for( int i = 0; i < -_Off; i++)
				--*this;
		return (*this);
		}

	virtual this_type operator+(int _Off)
		{ // return this + integer
		this_type _Tmp = *this;
		return (_Tmp += _Off);
		}

	virtual this_type& operator-=(int _Off)
		{ // decrement by integer
		return (*this += -_Off);
		}

	virtual this_type operator-(int _Off)
		{ // return this - integer
		this_type _Tmp = *this;
		return (_Tmp -= _Off);
		}

	virtual int operator-(const this_type& _Right) const
		{ // return difference of iterators
		int _tmp;
		str_pointer my = _Ptr, rig = _Right._Ptr;
		if(my == rig)
			return (0);
		for(_tmp = 0; (my != rig) && (my != my->_Next)
			; _tmp++, my = my->_Next)
			;
		if(my == rig)
			return (_tmp);
		for(_tmp = 0, my = _Ptr; (my != rig) && (rig != rig->_Next)
			; _tmp++, rig = rig->_Next)
			;
		if(my == rig)
			return (_tmp);
		return (-1);
		}

	virtual reference operator[](int _Off)
		{ // subscript
		return (*(*this + _Off));
		}

	virtual bool operator==(const this_type& _Right) const
		{ // test for iterator equality
		return (this->_Ptr == _Right._Ptr);
		}

	virtual bool operator!=(const this_type& _Right) const
		{ // test for iterator inequality
		return (!(*this == _Right));
		}

	virtual bool operator<(const this_type& _Right) const
		{ // test if this < _Right
		return (this->_Ptr < _Right._Ptr);
		}

	virtual bool operator>(const this_type& _Right) const
		{ // test if this > _Right
		return (_Right < *this);
		}

	virtual bool operator<=(const this_type& _Right) const
		{ // test if this <= _Right
		return (!(_Right < *this));
		}

	virtual bool operator>=(const this_type& _Right) const
		{ // test if this >= _Right
		return (!(*this < _Right));
		}

protected:

	str_pointer _Ptr;
	};

template<class _iterator> class
	const_basic_iterator
	{ // basic iterator
	typedef const_basic_iterator<_iterator> this_type;
	
	typedef typename _iterator::value_type value_type;
	typedef typename _iterator::pointer pointer;
	typedef typename _iterator::str_pointer str_pointer;
	typedef typename _iterator::reference reference;
public:

	const_basic_iterator()
		: _Ptr()
		{ // nullptr
		}

	const_basic_iterator(str_pointer ptr)
		: _Ptr(ptr)
		{ // set pointer
		}
	
	virtual void operator=(str_pointer ptr)
		{ // set pointer
		_Ptr = ptr;
		}

	virtual pointer operator->() const
		{ // return pointer to class object
		return &(**this);
		}

	virtual this_type& operator++()
		{ // pre increment
		if(this->_Ptr->_Next == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Next;
		return (*this);
		}

	virtual this_type operator++(int)
		{ // post increment
		this_type _Tmp = *this;
		++*this;
		return (_Tmp);
		}
	
	virtual this_type& operator--()
		{ // pre decrement
		if(this->_Ptr->_Prev == this->_Ptr)
			return (*this);
		this->_Ptr = this->_Ptr->_Prev;
		return (*this);
		}

	virtual this_type operator--(int)
		{ // post decrement
		this_type _Tmp = *this;
		--*this;
		return (_Tmp);
		}

	virtual reference operator*() const
		{ // return
		return (_Ptr->_Data);
		}

	virtual this_type& operator+=(int _Off)
		{ // increment by integer
		if(_Off > 0)
			for( int i = 0; i < _Off; i++)
				++*this;
		else if(_Off < 0)
			for( int i = 0; i < -_Off; i++)
				--*this;
		return (*this);
		}

	virtual this_type operator+(int _Off)
		{ // return this + integer
		this_type _Tmp = *this;
		return (_Tmp += _Off);
		}

	virtual this_type& operator-=(int _Off)
		{ // decrement by integer
		return (*this += -_Off);
		}

	virtual this_type operator-(int _Off)
		{ // return this - integer
		this_type _Tmp = *this;
		return (_Tmp -= _Off);
		}

	virtual int operator-(const this_type& _Right) const
		{ // return difference of iterators
		int _tmp;
		str_pointer my = _Ptr, rig = _Right._Ptr;
		if(my == rig)
			return (0);
		for(_tmp = 0; (my != rig) && (my != my->_Next)
			; _tmp++, my = my->_Next)
			;
		if(my == rig)
			return (_tmp);
		for(_tmp = 0, my = _Ptr; (my != rig) && (rig != rig->_Next)
			; _tmp++, rig = rig->_Next)
			;
		if(my == rig)
			return (_tmp);
		return (-1);
		}

	virtual reference operator[](int _Off) const
		{ // subscript
		return (*(*this + _Off));
		}

	virtual bool operator==(const this_type& _Right) const
		{ // test for iterator equality
		return (this->_Ptr == _Right._Ptr);
		}

	virtual bool operator!=(const this_type& _Right) const
		{ // test for iterator inequality
		return (!(*this == _Right));
		}

	virtual bool operator<(const this_type& _Right) const
		{ // test if this < _Right
		return (this->_Ptr < _Right._Ptr);
		}

	virtual bool operator>(const this_type& _Right) const
		{ // test if this > _Right
		return (_Right < *this);
		}

	virtual bool operator<=(const this_type& _Right) const
		{ // test if this <= _Right
		return (!(_Right < *this));
		}

	virtual bool operator>=(const this_type& _Right) const
		{ // test if this >= _Right
		return (!(*this < _Right));
		}
	
protected:

	str_pointer _Ptr;
	};

///////////////////////////////////////////////////////////////////
////
////	RTL TREE CLASS
////
////	INCLUDING TREE NODE ITERATOR.
////
///////////////////////////////////////////////////////////////////

#define BOOL_CAST(_x)		bool((_x::__value))

#define TRUE_OFREUSE			enum{ __value = 1 };
#define FALSE_OFNOREUSE			enum{ __value = 1 };

#define PUBLIC		public:
#define PRIVATE		private:

template<class _PtrRef> 
class TreeNodeEx{
public:
	// ZERO REEL COMPATIBILITY
	typedef typename _PtrRef value_type;
	typedef typename _PtrRef* pointer;
	typedef typename _PtrRef& reference;
	typedef typename const _PtrRef* const_pointer;
	typedef typename const _PtrRef& const_reference;
	typedef class TreeNodeEx<_PtrRef> * str_pointer;

	TreeNodeEx() : 
		_First(nullptr), _Last(nullptr), _Parent(nullptr), _Data(0), _Next(nullptr), _Prev(nullptr)
		{
		}
	TreeNodeEx(_PtrRef _data) : 
		_First(nullptr), _Last(nullptr), _Parent(nullptr), _Data(_data), _Next(nullptr), _Prev(nullptr)
		{
		}

	inline _PtrRef& operator*()
		{
		return _Data;
		}

	TreeNodeEx<_PtrRef> *_First, *_Last, *_Parent;
	TreeNodeEx<_PtrRef> *_Next, *_Prev;
	_PtrRef _Data;
	};

template<class u_type, typename size_type = unsigned int>
class xtree{
public:
	typedef typename u_type _MyT;
	typedef typename TreeNodeEx<_MyT> _Leaf;
	typedef typename TreeNodeEx<_MyT> * _Leaf_Ptr;

	typename _Leaf_Ptr _Head;
	typename _Leaf_Ptr _Current;

	typename size_type _Deep;

	stack<_Leaf_Ptr> _deep_ordering;

	///////////////////////////////////////////////////////////////////
	////
	////	RTL TREE CLASS DRIVER ROUTINE ITERATOR
	////		-NON RECUSIVE
	////	FOR PROFESSIONAL USER
	////
	///////////////////////////////////////////////////////////////////
	
	//
	//	THIS TREE CLASS IS NOT BINRAY TREE, SO I CAN'T STANDARD SEARCH FUNCTION.
	//
	class in_order_iterator
		{
		typedef in_order_iterator this_type;
	public:
		typename _Leaf_Ptr _Ptr;

		// Å½»ö¹ýhttp://real2won0.tistory.com/18
		in_order_iterator(_Leaf_Ptr _CurrentX)
			: _Ptr(_CurrentX)
			{
			initializing();
			}

		this_type operator++()
			{ // pre increment
			if (_Ptr->_Next != nullptr)
				_Ptr = _Ptr->_Next;
			else
				_Ptr = _Ptr->_Parent;
			return (*this);
			}

		this_type operator++(int)
			{ // post increment
			this_type _Tmp = *this;
			++*this;
			return (_Tmp);
			}

		this_type operator--()
			{ // pre increment
			if (_Ptr->_Prev != nullptr)
				_Ptr = _Ptr->_Prev;
			else
				if(_Ptr->_First->_Next != nullptr)
					_Ptr = _Ptr->_First;
			return (*this);
			}

		this_type operator--(int)
			{ // post increment
			this_type _Tmp = *this;
			--*this;
			return (_Tmp);
			}

		u_type operator*() const
			{ // return
			return (_Ptr->_Data);
			}

		u_type* operator->() const
			{ // return pointer to class object
			return &(**this);
			}
	private:

		void initializing()
			{
			if (_Ptr->_First != nullptr)
				{
				_Ptr = _Ptr->_First;
				initializing();
				}
			else
				return;
			}

		};

	//
	//	THIS TREE CLASS IS NOT BINRAY TREE, SO I CAN'T STANDARD SEARCH FUNCTION.
	//
	class pre_order_iterator
		{
		typedef pre_order_iterator this_type;
	public:
		typename _Leaf_Ptr _Ptr;

		stack<_Leaf_Ptr> _Stack;

		pre_order_iterator(_Leaf_Ptr _CurrentX)
			: _Ptr(_CurrentX)
			{
			initializing();
			}

		this_type operator++()
			{ // pre increment
			if (_Ptr->_First != nullptr)
			{
				_Stack.push(_Ptr);
				_Ptr = _Ptr->_First;
			}
			else
			{
				if (_Ptr->_Next != nullptr)
					_Ptr = _Ptr->_Next;
				else
				{
					_Ptr = _Stack.top();
					_Ptr = _Ptr->_First->_Next;
					_Stack.pop();
				}
			}
			return (*this);
			}

		this_type operator++(int)
			{ // post increment
			this_type _Tmp = *this;
			++*this;
			return (_Tmp);
			}

		this_type operator--()
			{ // pre increment
			if (_Ptr->_Prev != nullptr)
			{
				_Ptr = _Ptr->_Prev;
				while (_Ptr->_Last)
					_Ptr = _Ptr->_Last;
			}
			else
				if(_Ptr->_First != nullptr)
					_Ptr = _Ptr->_First;
			return (*this);
			}

		this_type operator--(int)
			{ // post increment
			this_type _Tmp = *this;
			--*this;
			return (_Tmp);
			}

		u_type operator*() const
			{ // return
			return (_Ptr->_Data);
			}

		u_type* operator->() const
			{ // return pointer to class object
			return &(**this);
			}
	private:

		void initializing()
			{
			if (_Ptr->_Parent != nullptr)
				{
				_Ptr = _Ptr->_Parent;
				initializing();
				}
			else
				return;
			}

		};

	class post_order_iterator
		{
		typedef post_order_iterator this_type;
	public:
		typename _Leaf_Ptr _Ptr;

		post_order_iterator(_Leaf_Ptr _CurrentX)
			: _Ptr(_CurrentX)
			{
			initializing();
			}

		this_type operator++()
			{ // pre increment
			if (_Ptr->_Next != nullptr)
				_Ptr = _Ptr->_Next;
			else
				_Ptr = _Ptr->_Parent;
			return (*this);
			}

		this_type operator++(int)
			{ // post increment
			this_type _Tmp = *this;
			++*this;
			return (_Tmp);
			}

		this_type operator--()
			{ // pre increment
			if (_Ptr->_Prev != nullptr)
				_Ptr = _Ptr->_Prev;
			else
				if(_Ptr->_First->_Next != nullptr)
					_Ptr = _Ptr->_First;
			return (*this);
			}

		this_type operator--(int)
			{ // post increment
			this_type _Tmp = *this;
			--*this;
			return (_Tmp);
			}

		u_type operator*() const
			{ // return
			return (_Ptr->_Data);
			}

		u_type* operator->() const
			{ // return pointer to class object
			return &(**this);
			}
	private:

		void initializing()
			{
			if (_Ptr->_First != nullptr)
				{
				_Ptr = _Ptr->_First;
				initializing();
				}
			else
				return;
			}

		};
	
	//
	//	THIS TREE CLASS IS NOT BINRAY TREE, SO I CAN'T STANDARD SEARCH FUNCTION.
	//	THIS CLASS EQUAL TO POST ORDER ITERATOR CLASS.
	//
	class level_order_iterator
		{
		typedef level_order_iterator this_type;
	public:
		typename _Leaf_Ptr _Ptr;

		level_order_iterator(_Leaf_Ptr _CurrentX)
			: _Ptr(_CurrentX)
			{
			initializing();
			}

		this_type operator++()
			{ // pre increment
			if (_Ptr->_Next != nullptr)
				_Ptr = _Ptr->_Next;
			else
				_Ptr = _Ptr->_First;
			return (*this);
			}

		this_type operator++(int)
			{ // post increment
			this_type _Tmp = *this;
			++*this;
			return (_Tmp);
			}

		this_type operator--()
			{ // pre increment
			if (_Ptr->_Prev != nullptr)
				_Ptr = _Ptr->_Prev;
			else
				if(_Ptr->_First->_Next != nullptr)
					_Ptr = _Ptr->_First;
			return (*this);
			}

		this_type operator--(int)
			{ // post increment
			this_type _Tmp = *this;
			--*this;
			return (_Tmp);
			}

		u_type operator*() const
			{ // return
			return (_Ptr->_Data);
			}

		u_type* operator->() const
			{ // return pointer to class object
			return &(**this);
			}
	private:

		void initializing()
			{
			if (_Ptr->_First != nullptr)
				{
				_Ptr = _Ptr->_First;
				initializing();
				}
			else
				return;
			}

		};

	class leaf_iterator
		: public basic_iterator<_Leaf>
		{
	public:
		leaf_iterator(_Leaf_Ptr _CurrentX)
			: basic_iterator(_CurrentX)
			{
			}
		};

	///////////////////////////////////////////////////////////////////
	////
	////	RTL TREE CLASS LEAF ANLAYZER
	////
	////	RTL CODE AND TREE ANALYZER
	////
	///////////////////////////////////////////////////////////////////

	class leaf_analyzer
		: public basic_iterator<_Leaf>
		{
	public:
		stack<_Leaf_Ptr> _Save;

		leaf_analyzer(_Leaf_Ptr _CurrentX)
			: basic_iterator(_CurrentX)
			{
			}

		size_type calculate_deep()
			{
			_Leaf_Ptr _Head = __super::_Ptr;
			size_type k = 0;
			for (; _Head->_Parent != nullptr; _Head = _Head->_Parent, k++)
				;
			return k;
			}

		int calculate_deep_stack()
			{
			_Leaf_Ptr _Set = *this->load();
			size_type k = 0;
			for (; _Head->_Parent != nullptr; _Head = _Head->_Parent, k++)
				;
			return k - calculate_deep();
			}

		void save()
			{ // save and push data into stack
			_Save.push(__super::_Ptr);
			}

		_Leaf_Ptr load()
			{ // load and pop data into stack
			_Leaf_Ptr _ret = _Save.top();
			_Save.pop();
			return ret;
			}

		_Leaf_Ptr _find(u_type _Data)
			{ // find node by data
			post_order_iterator poi(_Ptr);
			for (; *poi != _Data; poi++)
				;
			return poi._Ptr;
			}
		};

	///////////////////////////////////////////////////////////////////
	////
	////	RTL TREE CLASS MAIN MODULE
	////
	///////////////////////////////////////////////////////////////////
	
	xtree() : _Deep(0)
		{
		_Head = _cn();
		_Current = _Head;
		}

	PRIVATE virtual _Leaf*& _cn()
		{ // Create New Node
		_Leaf_Ptr _Tmp = new _Leaf();
		return _Tmp;
		}

	void _connect_leftvalue(_Leaf_Ptr& _Left, _Leaf_Ptr& _Right)
		{ // connect from left
		_Leaf_Ptr _Iter = _Left->_First;
		for (; _Iter != _Left->_Last; _Iter = _Iter->_Next)
			;
		_Iter->_Next = _Right;
		_Right->_Parent = _Left;
		_Right->_Prev = _Iter;
		_Left->_Last = _Right;
		}
	
	void _connect_rightvalue(_Leaf_Ptr& _Left, _Leaf_Ptr& _Right)
		{ // connect from right
		_Leaf_Ptr _Iter = _Left->_Last;
		for (; _Iter != _Left->_First; _Iter = _Iter->_Prev)
			;
		_Iter->_Prev = _Right;
		_Right->_Parent = _Left;
		_Right->_Next = _Iter;
		_Left->_First = _Right;
		}

	PRIVATE void __ex_connect_leftvalue(_Leaf_Ptr& _Left, _Leaf_Ptr& _Right)
		{
			_Right->_Parent = _Left;
		if (_Left->_First == nullptr)
			{
			_Left->_First = _Right;
			_Left->_Last = _Right;
			}
		else
			{
			_Right->_Next = _Left->_First;
			_Left->_First->_Prev = _Right;
			_Left->_First = _Right;
			}
		}

	void __ex_connect_rightvalue(_Leaf_Ptr& _Left, _Leaf_Ptr& _Right)
		{
			_Right->_Parent = _Left;
		if (_Left->_First == nullptr)
			{
			_Left->_First = _Right;
			_Left->_Last = _Right;
			}
		else
			{
			_Right->_Prev = _Left->_Last;
			_Left->_Last->_Next = _Right;
			_Left->_Last = _Right;
			}
		}

	PUBLIC void push_left(u_type _Data)
		{ // push _first node or either ...
		_Leaf_Ptr _Tmp = _cn();
		__ex_connect_leftvalue(_Current, _Tmp);
		_Tmp->_Data = _Data;
		}

	void push_right(u_type _Data)
		{ // push _last node or either ...
		_Leaf_Ptr _Tmp = _cn();
		__ex_connect_rightvalue(_Current, _Tmp);
		_Tmp->_Data = _Data;
		}

	bool escape()
		{ // goto _parent
		if (_Current->_Parent != nullptr && _Deep)
			{
			_Current = _Current->_Parent;
			_Deep--;
			}
		else
			return false;
		_deep_ordering.pop();
		return true;
		}

	void pop_left()
		{ // pop _first node or either ...
		_Leaf_Ptr _PreDel = _Current->_First;
		if (_PreDel == nullptr)
			return;
		if(_Current->_First->_Next != nullptr)
			_Current = _Current->_First->_Next;
		delete _PreDel;
		}

	void pop_right()
		{ // pop _last node or either ...
		_Leaf_Ptr _PreDel = _Current->_Last;
		if (_PreDel == nullptr)
			return;
		if (_Current->_Last->_Prev != nullptr)
			_Current = _Current->_Last->_Prev;
		delete _PreDel;
		}

	PRIVATE void __ex_connect_othervalue(_Leaf_Ptr& _First, _Leaf_Ptr& _Target, _Leaf_Ptr& _Last)
		{
		_Target->_Parent = _First->_Parent;
		// insert _target
		// _First -> _Last
		// _First -> _Target -> _Last
		_First->_Next = _Target;
		_Target->_Prev = _First;
		_Target->_Next = _Last;
		_Last->_Prev = _Target;
		}

	PUBLIC void insert(size_type _Position, u_type _Data)
		{ // insert data
		if (_Position == 0)
			push_left(_Data);
		else
			{
			_Leaf_Ptr _Ptr = _Current->_First;
			for (int i = 0; i < _Position; i++, _Ptr = _Ptr->_Next)
				;
			if (_Ptr == _Current->_Last)
				push_right(_Data);
			else
				{
				_Leaf_Ptr _Tmp = _cn();
				__ex_connect_othervalue(_Ptr->_Prev, _Tmp, _Ptr);
				_Tmp->_Data = _Data;
				}
			}
		}

	void insert(size_type _Position, u_type _Data, int _Time)
		{ // insert data
		for(; _Time; _Time--)
			*this->insert(_Position, _Data);
		}

	void into(size_type _Position)
		{ // go into _Pos
		_Leaf_Ptr _Ptr = _Current->_First;
		for (int i = 0; i < _Position; i++, _Ptr = _Ptr->_Next)
			;
		_Current = _Ptr;
		_Deep++;
		_deep_ordering.push(_Ptr);
		}

	u_type operator[](size_type _Position)
		{
		_Leaf_Ptr _Ptr = _Current->_First;
		for (int i = 0; i < _Position; i++, _Ptr = _Ptr->_Next)
			;
		return _Ptr->_Data;
		}

	const struct _Stack_Order{
		StackNodeEx<_Leaf_Ptr> *_Stack;	// Top of Stack
		size_type _Size;
	}	hookstack()
		{ // hook stack
		_Stack_Order SO = { _deep_ordering._Current, _Deep };
		return SO;
		}

	_Leaf_Ptr begin() const
		{ // get _first node
		return _Current->_First;
		}

	_Leaf_Ptr end() const
		{ // get _last node
		return _Current->_Last;
		}

	_Leaf_Ptr& begin()
		{ // get _first node
		return _Current->_First;
		}

	_Leaf_Ptr& end()
		{ // get _last node
		return _Current->_Last;
		}

	_Leaf_Ptr& operator*()
		{ // get _current
		return _Current;
		}

	};

#endif