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

#if !defined(_VECTOR_)
#define _VECTOR_

 #pragma warning(disable: 4100 4345)

template<class _Ty01>
	struct __type
	{ // str type
	typedef _Ty01 value_type;
	typedef _Ty01 &reference;
	typedef _Ty01 *pointer;
	};

template<class _Ty01>
	struct __type<const _Ty01>
	{ // str type
	typedef _Ty01 value_type;
	typedef _Ty01 &reference;
	typedef _Ty01 *pointer;
	};

template<class _Ty01>
	struct _type
	{ // str type
	typedef __type<_type> type;
	};

#define _VECTOR_ELEMENT_OPERATION(my_) \
	template<class my_>
#define _VECTOR_OPERATOR_ITERS(my_) \
	template<class my_>
#define _VECTOR_ITERATOR(my_, _fn, _cls_) \
	template<class my_>\
		_cls_ _fn{\
		_fn() : {} }

typedef void _Force;
#define __Force __forceinline
#define _Force __Force _Force
typedef bool _Hence;
#define _Hence __Force _Hence

namespace _vector_operation
{
	_VECTOR_ELEMENT_OPERATION(_Ty0)
		struct _VECTOR_NODES
		{ // vector nodes DNA
		_Ty0 _DATA;
		_VECTOR_NODES *_NEXT;
		_VECTOR_NODES *_PREV;
		};
#define _VECTOR_OPERATION _vector_operation::
}

_VECTOR_OPERATOR_ITERS(__Ty1)
	_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 
		operator<<(_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 
			*&_First, __Ty1 _Last)
	{ // first search
	for( ; _First != _First->_NEXT; )
		if(_First->_DATA == _Last)
			return _First;
		else
			_First = _First->_NEXT;
	return _First;
	}

_VECTOR_OPERATOR_ITERS(__Ty1)
	_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 
		operator>>(_VECTOR_OPERATION _VECTOR_NODES<__Ty1> 
			*&_First, __Ty1 _Last)
	{ // last search
	for( ; _First != _First->_PREV; )
		if(_First->_DATA == _Last)
			return _First;
		else
			_First = _First->_PREV;
	return _First;
	}

template<class _Ty0> inline
	void _vector_move_forward(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, int _Last = 0)
	{ // vector move forward
	if(!_Last)
		for( ; _First != _First->_NEXT; )
			_First = _First->_NEXT;
	else
		for(int _TMP = 0; _TMP <= _Last &&
			_First != _First->_NEXT; )
			_First = _First->_NEXT;
	}

template<class _Ty0> inline
	void _vector_move_back(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, int _Last = 0)
	{ // vector move back
	if(!_Last)
		for( ; _First != _First->_PREV; )
			_First = _First->_PREV;
	else
		for(int _TMP = 0; _TMP <= _Last &&
			_First != _First->_PREV; )
			_First = _First->_PREV;
	}

template<class _Ty0, 
		typename _Fn0> inline
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		_vector_move_that_forward(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
		*&_First, _Ty0 _Last)
	{ // vector move that forward
	for( ; _First != _First->_NEXT; )
		if(_Fn0(_First->_DATA) == _Last)
			return _First;
		else
			_First = _First->_NEXT;
	}

template<class _Ty0, 
		typename _Fn0> inline
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		_vector_move_that_back(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
		*&_First, _Ty0 _Last)
	{ // vector move that back
	for( ; _First != _First->_PREV; )
		if(_Fn0(_First->_DATA) == _Last)
			return _First;
		else
			_First = _First->_PREV;
	}

namespace _vector_swap_
{
	template<typename unchecked_type> inline
		void _swap(unchecked_type& _Left, unchecked_type& _Right)
		{ // fill all by what parameter
		unchecked_type t = _Left; 
		_Left = _Right; 
		_Right = t;
		}

#define _VECTOR_SWAP _vector_swap_::
}

template<class _Ty0> inline
	void _vector_swap(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // vector swap
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *_TMP = _Second;
	_Second->_NEXT = _First->_NEXT;
	_Second->_PREV = _First->_PREV;
	_VECTOR_SWAP _swap<_Ty0> (_First->_DATA, _Second->_DATA);
	_First->_NEXT = _TMP->_NEXT;
	_First->_PREV = _TMP->_PREV;
	}

template<class _Ty0> inline
	void _vector_dswap(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // data swap
	_VECTOR_SWAP _swap<_Ty0> (_First->_DATA, _Second->_DATA);
	}

namespace _vector_alloc
{
	template<typename unchecked_type> inline
		_VECTOR_OPERATION 
			_VECTOR_NODES<unchecked_type> *_alloc()
		{ // fill all by what parameter
		_VECTOR_OPERATION 
			_VECTOR_NODES<unchecked_type> *ptr = new _VECTOR_OPERATION 
				_VECTOR_NODES<unchecked_type>;
		return ptr;
		}

#define _VECTOR_ALLOC _vector_alloc::
}

template<class _Ty0> inline
	void _vector_transfer(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // transfer to first
	_First->_NEXT = _Second->_NEXT;
	_First->_DATA = _Second->_DATA;
	_First->_PREV = _Second->_PREV;
	}

template<class _Ty0> inline
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*_vector_move(_VECTOR_OPERATION _VECTOR_NODES<_Ty0>
			*&_First)
	{ // vector move
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*_Temp = _VECTOR_ALLOC _alloc();
	_vector_transfer(_Temp, _First);
	return _Temp;
	}

namespace _vector_reverse
{
	template<class _Ty0> inline
		void _reverse(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
			*&_Head)
	{ // vector reverse
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *prev = 0;
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *curr = _Head;
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *next;
    while (curr != curr->_NEXT)
		{
        next = curr->_NEXT;
        curr->_NEXT = prev;
        prev = curr;
        curr = next;
		}
    _Head = prev;
	}

#define _VECTOR_REVERSE _vector_reverse::
}

template<class _Ty0> inline
	void _vector_homo(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // homo
	_First->_NEXT = _Second;
	_Second->_PREV = _First;
	}

template<class _Ty0> inline
	void _vector_hetero(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second,
			 _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Last)
	{ // hetero
	_First->_NEXT = _Second;
	_Second->_PREV = _First;
	_Second->_NEXT = _Last;
	_Last->_PREV = _Second;
	}

template<class _Ty0> inline
	void _vector_qsort(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // quick sort
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *set;
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *curr;
	if (_First == _Second) 
		return;
	set = _First;
	curr = set->_NEXT;
	while (1)
		{
		if (set->_DATA < curr->_DATA)
			_vector_dswap(set, curr);
		if (curr == _Second) 
			break;
		curr = curr->_NEXT;
		}
	_vector_dswap(_First, curr);
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *currs = curr;
	curr = curr->_PREV;
	if (curr != 0)
		if ((_First->_PREV != curr) && (curr->_NEXT != _First))
			_vector_qsort(_First, curr);
	curr = currs;
	curr = curr->_NEXT;
	if (curr != 0)
		if ((curr->_PREV != _Second) && (_Second->_NEXT != curr))
			_vector_qsort(curr, _Second);
	}

template<class _Ty0> inline
	int _vector_value(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // vector value
	int i = 0;
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *_TMP = _First;
	for(; _TMP != _Second; i++, _TMP = _TMP->_NEXT);
	return i + 1;
	}

template<class _Ty0> inline
	void _vector_sort(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // bubble sort
	int size = _vector_value(_First, _Second);
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *_TMP = _First;
	for(int n = 0; n <= size; n++)
		{
		for( ; _TMP != _Second; _TMP = _TMP->_NEXT)
			if(_TMP->_DATA > _TMP->_NEXT->_DATA)
				_vector_dswap(_TMP, _TMP->_NEXT);
		_TMP = _First;
		}
	}

template<class _Ty0> inline
	void _vector_remove(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second)
	{ // vector remove
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first = _First->_NEXT->_NEXT;
	for( ; first != _Second; first = first->_NEXT);
		delete first->_PREV;
	delete _First;
	delete _Second;
	}

template<class _Ty0> inline
	void _vector_copy(_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
		*&_First, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Second,
			_VECTOR_OPERATION _VECTOR_NODES<_Ty0> 
				*&_Third, _VECTOR_OPERATION _VECTOR_NODES<_Ty0> *&_Last)
	{ // vector copy

	}

namespace _vector_operation
{
	namespace _vector_iterator
	{
#define _VECTOR_ITERATION _vector_iterator::

#define _VECTOR_OPEARTOR_ITERATOR_DISCONST_CONST_OPEARTION(temporary, iterbuf, iters, consts) \
			_Hence operator==(iterbuf *_left) consts\
			{\
			return temporary == _left;\
			}\
			_Hence operator!=(iterbuf *_left) consts\
			{\
			return temporary != _left;\
			}\
			_Hence operator==(iters _left) consts\
			{\
			return this->operator* == _left;\
			}\
			_Hence operator!=(iters _left) consts\
			{\
			return this->operator* != _left;\
			}\
			_Hence operator<(iters _left) consts\
			{\
			return this->operator* < _left;\
			}\
			_Hence operator>(iters _left) consts\
			{\
			return this->operator* > _left;\
			}\
			_Hence operator<=(iters _left) consts\
			{\
			return this->operator* <= _left;\
			}\
			_Hence operator>=(iters _left) consts\
			{\
			return this->operator* >= _left;\
			}

		_VECTOR_OPERATOR_ITERS(__Ty2)
			class _vector_iterator_dis_const
			{
				typedef typename  __type<__Ty2>::value_type 
					iterator_vector_type;
				typedef typename  __type<typename 
						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::pointer
					iterator_vector_type_disconst;
				typedef typename  __type<typename 
						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::value_type
					iterator_vector_disconst;

				iterator_vector_disconst *__vector__temporary;

			public:

				_vector_iterator_dis_const()
					:
					{ }

				_vector_iterator_dis_const(iterator_vector_disconst _First)
					: __vector__temporary(_First)
					{ }

				_Force operator=(iterator_vector_disconst *_First)
					{ // operator =
					__vector__temporary = _First;
					}

				__Force __Ty2& operator*()
					{ // operator *
					return __vector__temporary->_DATA;
					}

				_Hence operator++(int)
					{ // operator ++
					__vector__temporary = __vector__temporary->_NEXT;
					return __vector__temporary != __vector__temporary->_NEXT;
					}

				_Hence operator--(int)
					{ // operator --
					__vector__temporary = __vector__temporary->_PREV;
					return __vector__temporary != __vector__temporary->_PREV;
					}

				_VECTOR_OPEARTOR_ITERATOR_DISCONST_CONST_OPEARTION
					(__vector__temporary, iterator_vector_disconst, __Ty2, )

			};

		_VECTOR_OPERATOR_ITERS(__Ty2)
			class _vector_iterator_const
			{
				typedef typename  __type<__Ty2>::value_type 
					iterator_vector_type;
				typedef typename  __type<typename 
						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::pointer
					iterator_vector_type_const;
				typedef typename  __type<typename 
						_VECTOR_OPERATION _VECTOR_NODES<__Ty2> >::value_type
					iterator_vector_const;

				iterator_vector_const *__vector__temporary;

			public:

				_vector_iterator_const()
					{ }

				_vector_iterator_const(iterator_vector_const _First)
					: __vector__temporary(_First)
					{ }

				_Force operator=(iterator_vector_const *_First)
					{ // operator =
					__vector__temporary = _First;
					}

				__Force __Ty2 operator*() const
					{ // operator *
					return __vector__temporary->_DATA;
					}

				_Hence operator++(int)
					{ // operator ++
					__vector__temporary = __vector__temporary->_NEXT;
					return __vector__temporary != __vector__temporary->_NEXT;
					}

				_Hence operator--(int)
					{ // operator --
					__vector__temporary = __vector__temporary->_PREV;
					return __vector__temporary != __vector__temporary->_PREV;
					}

				_VECTOR_OPEARTOR_ITERATOR_DISCONST_CONST_OPEARTION
					(__vector__temporary, iterator_vector_const, __Ty2, const)

			};
	}
}
	
	// STANDRAD VECTOR
template<class _Vector_Element>
	class vector
	{ // vector class
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Vector_Element> *_Head;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Vector_Element> *_Lastest;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Vector_Element> *_Tail;

	int _Pointer, _Back_PP, _size;
	bool vlock;

	public:

	typedef typename _VECTOR_OPERATION _VECTOR_ITERATION 
		_vector_iterator_const<_Vector_Element>
		const_iterator;

	typedef typename _VECTOR_OPERATION _VECTOR_ITERATION 
		_vector_iterator_dis_const<_Vector_Element>
		iterator;

	explicit vector()
		: _Back_PP(0), _Pointer(0), _size(0)
		{ // vector intalled
			_Head = _New_Node();
			_Tail = _New_Node();
			_Head->_PREV = _Head;
			_Head->_NEXT = _Tail;
			_Tail->_PREV = _Head;
			_Tail->_NEXT = _Tail;
			vlock = true;
		}

	virtual ~vector()
		{ // vector desconductor
		_vector_remove(_Head, _Tail);
		}

	private: __Force void _Vector_Nodes_Connects(_VECTOR_OPERATION 
				 _VECTOR_NODES<_Vector_Element> *_First,
					_VECTOR_OPERATION 
						_VECTOR_NODES<_Vector_Element> *_Target,
							_VECTOR_OPERATION
								_VECTOR_NODES<_Vector_Element> *_Last)
			{ // nodes connect
				_First->_NEXT = _Target;
				_Target->_PREV = _First;
				_Target->_NEXT = _Last;
				_Last->_PREV = _Target;
			}

	public:

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&begin()
			{ // begin function
				return _Head->_NEXT;
			}

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&end()
			{ // begin function
				return _Tail;
			}

	private: __Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *_New_Node()
		{ // create new node
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = new _VECTOR_OPERATION 
				_VECTOR_NODES<_Vector_Element>;
		return ptr;
		}

	public:

		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&operator[](int _First)
		{ // operator []
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *_Temp = _Head;
		for( int Fn_n = 0; 
				Fn_n <= _First; Fn_n++)
			_Temp = _Temp->_NEXT;
		return _Temp;
		}

		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&operator()(int _First)
		{ // operator ()
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *_Temp = _Tail;
		for( int Fn_n = 0; 
				Fn_n <= _First; Fn_n++)
			_Temp = _Temp->_PREV;
		return _Temp;
		}

		void push_back(_Vector_Element _left)
		{ // push back item
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *temp = _New_Node();
		temp->_DATA = _left;
		if (_Back_PP)
			_Vector_Nodes_Connects(_Lastest, temp, _Tail);
		else
			_Vector_Nodes_Connects(_Head, temp, _Tail);
		_Lastest = temp;
		_Back_PP++;
		_size++;
		}
		}

		void push_front(_Vector_Element _left)
		{ // push back item
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *temp = _New_Node();
		temp->_DATA = _left;
		_Vector_Nodes_Connects(_Head, temp, _Head->_NEXT);
		_Lastest = temp;
		_Back_PP++;
		_size++;
		}
		}

		_Vector_Element pop_back()
		{ // pop back item
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *prev = _Head;
		_Vector_Element ret;
		for(int f = -1; ; f++)
			{
			if(ptr == _Tail->_PREV)
				break;
			if(f >= 0)
				prev = prev->_NEXT;
			ptr = ptr->_NEXT;
			}
		ret = ptr->_DATA;
		delete ptr;
		_Connect(prev, _Tail);
		_Back_PP--;
		_size--;
		return ret;
		}
		}

		_Vector_Element pop_front()
		{ // pop back item
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		_Vector_Element ret = ptr->_DATA;
		_Connect(_Head, ptr->_NEXT);
		delete ptr;
		_Back_PP--;
		_size--;
		return ret;
		}
		}

		_Force remove()
		{ // vector clear
		if(vlock){
		_vector_remove(_Head, _Tail);
		}
		}

	private: _Force _Connect(_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *_head, _VECTOR_OPERATION 
				_VECTOR_NODES<_Vector_Element> *_tail)
		{ // connect link
		_head->_NEXT = _tail;
		_tail->_PREV = _head;
		}

	public:

		_Force reserve(int _First)
		{ // resize vector
		if(vlock){
		for(int i = 0; i <= _First; i++)
			push_back(0);
		}
		}

		__Force int size() const
		{ // get size
		return _size;
		}

		void insert(_Vector_Element _First, int _Pos)
		{ // insert value
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr_next;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *temps = _New_Node();
		for( int Fn_n = 0; 
				Fn_n <= _Pos; Fn_n++)
			ptr = ptr->_NEXT;

		ptr_next = ptr->_NEXT;
		ptr->_NEXT = temps;
		temps->_NEXT = ptr_next;
		ptr_next->_PREV = temps;

		temps->_DATA = _First;
		}
		}

		void erase(int _Pos)
		{ // erase value
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr_next;
		for( int Fn_n = 0; 
				Fn_n <= _Pos; Fn_n++)
			ptr = ptr->_NEXT;
		ptr->_PREV->_NEXT = ptr->_NEXT;
		ptr->_NEXT->_PREV = ptr->_PREV;
		delete ptr;
		}
		}

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&front()
		{ // front function
		return _Head->_NEXT;
		}

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *&back()
		{ // front function
		return _Tail->_PREV;
		}

		_Force fill(_Vector_Element _Elem)
		{ // fill all
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		for( ; ptr != _Tail; )
			ptr->_DATA = _Elem, ptr = ptr->_NEXT;
		}
		}

		_Force assign(_Vector_Element _First, int _Last)
		{ // assign function
		if(vlock){
		for(int i = 0; i <= _Last; i++)
			push_back(_First);}
		}

		_Force asign(_Vector_Element _First, int _LPos, int _RPos)
		{ // asign funciton
		if(vlock){
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Vector_Element> *ptr = _Head->_NEXT;
		for(int f = 0; f <= _LPos; f++)
			ptr = ptr->_NEXT;
		for(int i = _LPos; i <= _RPos; i++)
			ptr->_DATA = _First, ptr = ptr->_NEXT;}
		}

		_Force reverse()
		{ // vector reverse
		if(vlock)
		_VECTOR_REVERSE _reverse(_Head);
		}

		_Force sort()
		{ // vector sort
		if(vlock)
		_vector_sort(front(), back());
		}

		_Force lock()
		{ // vector lock
		vlock = false;
		}

		_Force unlock()
		{ // vector unlock
		vlock = true;
		}

	};

template<class _Ty0> inline
	int _vector_first_match(vector<_Ty0> *&_First, 
		_Ty0 &_Last)
	{ // vector first match method
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *ptr = _First->front();
	for(int i = 0 ; ptr != _First->_Tail; 
			ptr = ptr->_NEXT, i++)
		if(ptr->_DATA == _Last)
			return i;
	}

template<class _Ty0> inline
	int _vector_perfect_match(vector<_Ty0> *&_First, 
		vector<_Ty0> *&_Last)
	{ // vector first match method
	if(_First->size() < _Last->size())
		return -1;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first_next = _First->front();
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *last_next = _Last->front();
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first_temp = 0;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *last_temp = 0;
	int flen = _First->size(), llen = _Last->size();
	for(int i = 0; i <= flen; i++, first_next = first_next->_NEXT)
		if(first_next->_DATA == last_next->_DATA){
			first_temp = first_next, last_temp = last_next;
			for(int n = 0; n <= llen; n++, last_next = last_next->_NEXT, 
					first_next = first_next->_NEXT)
				if(last_next->_DATA != first_next->_DATA)
					first_next = first_temp, last_next = last_temp, 
					break;
				else if(n == llen)
					return i;}
	}

template<class _Ty0> inline
	int _vector_times_match(vector<_Ty0> *&_First, 
		_Ty0 &_Last, int times = 1)
	{ // vector times match
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *ptr = _First->front();
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *ptrs = 0;
	for(int i = 0 ; ptr != _First->_Tail; 
			ptr = ptr->_NEXT, i++)
		if(ptr->_DATA == _Last){
			ptrs = ptr;
			for(int f = 1; f <= times; 
				ptr = ptr->_NEXT, f++)
				if(ptr->_DATA == _Last)
					return i;
			ptr = ptrs;}
	}

template<class _Ty0> inline
	_VECTOR_OPERATION _VECTOR_NODES<_Ty0> *& 
		_vector_disconnect_and_connect(_VECTOR_OPERATION 
			_VECTOR_NODES<_Ty0> *&_First, _VECTOR_OPERATION 
				_VECTOR_NODES<_Ty0> *&_Second, _VECTOR_OPERATION 
					_VECTOR_NODES<_Ty0> *&_Third, _VECTOR_OPERATION 
						_VECTOR_NODES<_Ty0> *&_Last)
	{ // disconnect and connect
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first_next = _First->_NEXT;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *last_prev = _Last->_PREV;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *gd = _VECTOR_ALLOC _alloc();
	_First->_NEXT = _Second;
	_Second->_PREV = _First;
	_Third->_NEXT = _Last;
	_Last->_PREV = _Third;
	gd->_NEXT = first_next;
	gd->_PREV = last_prev;
	return gd;
	}

template<class _Ty0> inline
	int _vector_element_count(_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *&_First, _Ty0 _Second)
	{ // vector element count
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Ty0> *first_next = _First;
	int let = 0;
	for( ; first_next != 
		first_next->_NEXT; first_next = first_next->_NEXT)
			if(first_next->_DATA == _Second)
				let++;
	return let;
	}

		// STANDARD STACK
template<class _Stack_Element>
	class stack
	{ // stack class
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Stack_Element> *_Head;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Stack_Element> *_Lastest;
	_VECTOR_OPERATION 
		_VECTOR_NODES<_Stack_Element> *_Tail;
	
	public:

		explicit stack()
		{ // stack intalled
		_Head = _New_Node();
		_Tail = _New_Node();
		_Head->_PREV = _Head;
		_Head->_NEXT = _Tail;
		_Tail->_PREV = _Head;
		_Tail->_NEXT = _Tail;
		_Head->_DATA = 0;
		_Lastest = _Head;
		}

		virtual ~stack()
		{ // stack desconductor
		_vector_remove(_Head, _Tail);
		}

		void push(_Stack_Element _left)
		{ // push back item
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *temp = _New_Node();
		temp->_DATA = _left;
		_Vector_Nodes_Connects(_Lastest, temp, _Tail);
		_Lastest = temp;
		}

		_Stack_Element pop()
		{ // pop back item
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *ptr = _Head;
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *prev = _Head;
		_Stack_Element ret;
		for(int f = -1; ; f++)
			{
			if(ptr == _Tail->_PREV)
				break;
			if(f >= 0)
				prev = prev->_NEXT;
			ptr = ptr->_NEXT;
			}
		ret = ptr->_DATA;
		delete ptr;
		_Connect(prev, _Tail);
		return ret;
		}

	private:

		_Force _Connect(_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *_head, _VECTOR_OPERATION 
				_VECTOR_NODES<_Stack_Element> *_tail)
		{ // connect link
		_head->_NEXT = _tail;
		_tail->_PREV = _head;
		}

		__Force void _Vector_Nodes_Connects(_VECTOR_OPERATION 
		 _VECTOR_NODES<_Stack_Element> *_First,
			_VECTOR_OPERATION 
				_VECTOR_NODES<_Stack_Element> *_Target,
					_VECTOR_OPERATION
						_VECTOR_NODES<_Stack_Element> *_Last)
		{ // nodes connect
		_First->_NEXT = _Target;
		_Target->_PREV = _First;
		_Target->_NEXT = _Last;
		_Last->_PREV = _Target;
		}

		__Force _VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *_New_Node()
		{ // create new node
		_VECTOR_OPERATION 
			_VECTOR_NODES<_Stack_Element> *ptr = new _VECTOR_OPERATION 
				_VECTOR_NODES<_Stack_Element>;
		return ptr;
		}

	};

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0013****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/