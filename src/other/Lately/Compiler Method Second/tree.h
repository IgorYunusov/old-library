/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						ULTRIMATE TREE CLASS
 *								
 *                           (C) Copyright 2015
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

// VERSION 2.1		$ PRELASTEST UPDATE 2014/10/24 $
//                  $    LASTEST UPDATE 2015/02/16 $

#ifndef _TREE_
#define _TREE_
#pragma once


// Binary Search Tree

#include <new>
#include <stack>
#include <vector>

#ifndef _CUSTROM_SIZE_TYPE
using::size_t;
#define __SIZE_TYPE		size_t
#endif
#ifndef _CUSTOM_OTHER_TYPE
//using::ptrdiff_t;
typedef int __w64 _ptrdiff_t;
#define __OTHER_TYPE	_ptrdiff_t
#endif

template<class _Tree_val> class 
	tree_node
{
public:
	typedef tree_node<_Tree_val> _Myt;
	
	typedef typename __SIZE_TYPE		size_type;
	typedef typename __OTHER_TYPE		difference_type;
	typedef typename _Tree_val*			pointer;
	typedef typename const _Tree_val*	const_pointer;
	typedef typename _Tree_val&			reference;
	typedef typename const _Tree_val&	const_reference;
	typedef typename _Tree_val			value_type;

	tree_node();
	tree_node(value_type _data);
    ~tree_node();

	reference operator*();
	bool is_left();
	bool is_right();
	bool is_parent();
	bool is_data();

	_Myt *_Left, *_Right, *_Parent;
	value_type _Data;
};

////////////////////////////////////////////////////////////////////////////

template<class _Tree_val> tree_node<_Tree_val>::
	tree_node()
	: _Left(nullptr), _Right(nullptr), _Parent(nullptr), _Data(value_type()) 
{ 
}

template<class _Tree_val> tree_node<_Tree_val>::
	tree_node(value_type _data)
	: _Left(nullptr), _Right(nullptr), _Parent(nullptr), _Data(_data) 
{ 
}

template<class _Tree_val> tree_node<_Tree_val>::
    ~tree_node()
{
}

template<class _Tree_val> typename tree_node<_Tree_val>::reference
tree_node<_Tree_val>::operator*()
{
	return this->_Data;
}

template<class _Tree_val>
bool tree_node<_Tree_val>::is_left()
{
	return _Left != nullptr;
}

template<class _Tree_val>
bool tree_node<_Tree_val>::is_right()
{
	return _Right != nullptr;
}

template<class _Tree_val>
bool tree_node<_Tree_val>::is_parent()
{
	return _Parent != nullptr;
}

template<class _Tree_val>
bool tree_node<_Tree_val>::is_data()
{
	//
	//	적절한 초기화를 위해 nullptr, NULL, 0 사용금지
	//
	return _Data != value_type();
}

////////////////////////////////////////////////////////////////////////////

template<typename _Ty> class
	tree
	{
public:
	typedef tree<_Ty> _Mytree;
	typedef tree_node<_Ty> _Mynode;

	typedef typename _Mynode::size_type size_type;
	typedef typename _Mynode::pointer pointer;
	typedef typename _Mynode::reference reference;
	typedef typename _Mynode::const_pointer const_pointer;
	typedef typename _Mynode::const_reference const_reference;
	typedef typename _Mynode::value_type value_type;

	typedef typename _Mynode this_type;
	typedef typename _Mynode* pointer_type;
	typedef typename _Mynode& reference_type;

	tree();
	explicit tree(pointer_type _Head);
	virtual ~tree();

protected:
	pointer_type _Head, _Last;
	pointer_type attach_temp;

    //
    //  -1이면 왼쪽, 1이면 오른쪽, 0이면 헤드
    //
    int last_into;
    int last_escape;
    
private:
	pointer_type allocate(const void * = 0);
	void deallocate(pointer_type __p);

	template<typename T>
	void swap(T& _Left, T& _Right);

public:

	// 왼쪽에 새 요소를 추가합니다.
	void push_left();
	// 오른쪽에 새 요소를 추가합니다.
	void push_right();
	// 왼쪽에 새 요소를 추가하고, 값을 초기화합니다.
	void push_left(value_type val);
	// 오른족에 새 요소를 추가하고, 값을 초기화합니다.
	void push_right(value_type val);

	// 현재 노드를 왼쪽 노드로 옮깁니다.
	// 왼쪽 노드가 존재하지 않는다면 false가 반환됩니다.
	bool into_left();
	// 현재 노드를 오른쪽 노드로 옮깁니다.
	// 오른쪽 노드가 존재하지 않는다면 false가 반환됩니다.
	bool into_right();
	// 현재 노드를 현재 노드의 상위 계층의 노드로 옮깁니다.
	// 해당 노드가 존재하지 않는다면 false가 반환됩니다.
	bool escape();
	// 현재 노드를 꼭대기로 옮깁니다.
	void ground();

	// 왼쪽 노드가 존재하는지의 여부를 가져옵니다.
	bool is_left();
	// 오른쪽 노드가 존재하는지의 여부를 가져옵니다.
	bool is_right();
	// 현재 노드에 값이 있는지의 여부를 가져옵니다.
	bool is_data();
	// 현재 노드에 상위 노드가 존재하는지의 여부를 가져옵니다.
	bool is_parent();
	// 현재 노드가 최 상위 노드를 가리키는지의 여부를 가져옵니다.
	bool is_ground();

	// 현재 노드의 데이터를 참조합니다.
	reference operator*();
	pointer operator->();
	pointer_type operator&();

	pointer_type travel();
	reference left();
	reference right();

	// 새로운 헤드를 만들고 헤드의 왼쪽로 기존의 헤드를 옮깁니다.
	void make_head_left();
	// 새로운 헤드를 만들고 헤드의 오른쪽으로 기존의 헤드를 옮깁니다.
	void make_head_right();
	// 노드의 값을 초기화하는 새로운 헤드를 만들고 헤드의 왼쪽로 기존의 헤드를 옮깁니다.
	void make_head_left(value_type val);
	// 노드의 값을 초기화하는 새로운 헤드를 만들고 헤드의 오른쪽로 기존의 헤드를 옮깁니다.
	void make_head_right(value_type val);

	// 현재 노드를 왼쪽 최하단으로 옮깁니다.
	void into_deep_left();
	// 현재 노드를 오른쪽 최하단으로 옮깁니다.
	void into_deep_right();

	/*
		
		노드 저장은 한 번에 한 개만 가능하다.
		알고리즘 작성시 2개 이상은 쓰이는 경우가 거의 
		없기 때문에 그렇게 설계했습니다.

	*/
    
	// 임시저장된 노드를 현재 노드의 왼쪽에 붙입니다.
	void attach_left();
	// 임시저장된 노드를 현재 노드의 오른쪽에 붙입니다.
	void attach_right();
    // 임시저장된 노드를 헤드에 붙입니다.
    void attach_to_head();
	// 왼쪽 노드를 임시 저장합니다.
	void detach_left();
	// 오른쪽 노드를 임시 저장합니다.
	void detach_right();
    // 현재 노드를 임시 저장합니다.
    void detach_this();

    // 마지막으로 어디서 detach_this되었는지 가져옵니다.
    int last_detach();

	void attach_left_tree(pointer_type v_det);
	void attach_right_tree(pointer_type v_det);
	pointer_type& detach_left_tree();
	pointer_type& detach_right_tree();

	// 현재 노드의 값과 왼쪽 노드의 값을 서로 바꿉니다.
	void dswap_left();
	// 현재 노드의 값과 오른쪽 노드의 값을 서로 바꿉니다.
	void dswap_right();
	// 왼쪽 노드의 값과 오른쪽 노드의 값을 서로 바꿉니다.
	void dswap_rl();

	class postorder_iterator {
	public:

		postorder_iterator(pointer_type head);

		reference operator*() const;
		pointer operator->() const;

		postorder_iterator& operator++();
		postorder_iterator& operator--();
		postorder_iterator operator++(int);
		postorder_iterator operator--(int);
		postorder_iterator& operator+=(unsigned int);
		postorder_iterator& operator-=(unsigned int);

		pointer_type begin();
		pointer_type end();

		pointer_type last;

		void postorder_init(pointer_type _Next);
		std::vector<pointer_type> postorder_vector;
	};

	template<class _Func>
	void postorder_travel(_Func& _T, pointer_type _Next);
	template<class _Func>
	void preorder_travel(_Func& _T, pointer_type _Next);
	template<class _Func>
	void inorder_travel(_Func& _T, pointer_type _Next);
	};

////////////////////////////////////////////////////////////////////////////

template<typename _Ty>
tree<_Ty>::tree()
	: attach_temp(nullptr), last_into(0), last_escape(0)
{
	this->_Last = 
	this->_Head = 
		this->allocate();
}

template<typename _Ty>
tree<_Ty>::tree(pointer_type _Head)
	: attach_temp(nullptr)
{
	this->_Last = 
	this->_Head = 
		_Head;
}

template<typename _Ty>
tree<_Ty>::~tree()
{
    // I don't know how to solve this fucking syntax problem.
    // It's just twice called, and when second calling,
    // error is coming from this.
    //
    //postorder_iterator pi(this->_Head);
    //
    //for (auto& pivtitem : pi.postorder_vector)
    //    deallocate(pivtitem);
    //
    //this->_Head = this->_Last = nullptr;
}

//////////////////////////////////////

template<typename _Ty> 
typename tree<_Ty>::pointer_type tree<_Ty>::allocate(const void * = 0)
{
	return new _Mynode();
}

template<typename _Ty> 
void tree<_Ty>::deallocate(pointer_type __p)
{
	delete __p;
}

template<typename _Ty> 
template<typename T>
void tree<_Ty>::swap(T& _Left, T& _Right)
{
	T _Tmp = _Left;
	_Left = _Right;
	_Right = _Tmp;
}

//////////////////////////////////////

template<typename _Ty>
void tree<_Ty>::push_left()
{
	pointer_type _Left = pointer_type();
	_Left = allocate();
	**_Left = value_type();
	this->_Last->_Left = _Left;
	this->_Last->_Left->_Parent = this->_Last;
}

template<typename _Ty>
void tree<_Ty>::push_right()
{
	pointer_type _Right = pointer_type();
	_Right = allocate();
	**_Right = value_type();
	this->_Last->_Right = _Right;
	this->_Last->_Right->_Parent = this->_Last;
}

template<typename _Ty>
void tree<_Ty>::push_left(typename tree<_Ty>::value_type val)
{
	this->push_left();
	**this->_Last->_Left = val;
}

template<typename _Ty>
void tree<_Ty>::push_right(typename tree<_Ty>::value_type val)
{
	this->push_right();
	**this->_Last->_Right = val;
}

//////////////////////////////////////

template<typename _Ty>
bool tree<_Ty>::into_left()
{
	if ((*this->_Last).is_left())
		this->_Last = this->_Last->_Left;
	else
		return false;
    last_into = -1;
	return true;
}

template<typename _Ty>
bool tree<_Ty>::into_right()
{
	if ((*this->_Last).is_right())
		this->_Last = this->_Last->_Right;
	else
		return false;
    last_into = 1;
	return true;
}

template<typename _Ty>
bool tree<_Ty>::escape()
{
	if ((*this->_Last).is_parent()) {
        pointer_type save = this->_Last;
        this->_Last = this->_Last->_Parent;

        // escape된 위치가 어디인지 저장함
        if (save == this->_Last->_Left)
            last_escape = -1;
        else if (save == this->_Last->_Right)
            last_escape = 1;
        else if (this->_Last == this->_Head)
            last_escape = 0;
    }
	else
		return false;
	return true;
}

template<typename _Ty>
void tree<_Ty>::ground()
{
	this->_Last = this->_Head;
}

//////////////////////////////////////

template<typename _Ty>
bool tree<_Ty>::is_left()
{
	return ((*this->_Last).is_left());
}

template<typename _Ty>
bool tree<_Ty>::is_right()
{
	return ((*this->_Last).is_right());
}

template<typename _Ty>
bool tree<_Ty>::is_data()
{
	return ((*this->_Last).is_data());
}

template<typename _Ty>
bool tree<_Ty>::is_parent()
{
	return ((*this->_Last).is_parent());
}

template<typename _Ty>
bool tree<_Ty>::is_ground()
{
	return this->_Last == this->_Head;
}

//////////////////////////////////////

template<typename _Ty>
typename tree<_Ty>::reference tree<_Ty>::operator*()
{
	return **this->_Last;
}

template<typename _Ty>
typename tree<_Ty>::pointer_type tree<_Ty>::operator&()
{
	return this->_Last;
}

template<typename _Ty>
typename tree<_Ty>::pointer tree<_Ty>::operator->()
{
	return &(**this->_Last);
}

//////////////////////////////////////

template<typename _Ty>
typename tree<_Ty>::pointer_type tree<_Ty>::travel()
{
	return this->_Head;
}

template<typename _Ty>
typename tree<_Ty>::reference tree<_Ty>::left()
{
	return **this->_Last->_Left;
}

template<typename _Ty>
typename tree<_Ty>::reference tree<_Ty>::right()
{
	return **this->_Last->_Right;
}

//////////////////////////////////////

template<typename _Ty>
void tree<_Ty>::make_head_left()
{
	pointer_type _Head = pointer_type();
	_Head = allocate();
	**_Head = value_type();
	_Head->_Left = this->_Head;
	this->_Head->_Parent = _Head;
	this->_Head = _Head;
	this->_Last = this->_Head;
}

template<typename _Ty>
void tree<_Ty>::make_head_right()
{
	pointer_type _Head = pointer_type();
	_Head = allocate();
	**_Head = value_type();
	_Head->_Right = this->_Head;
	this->_Head->_Parent = _Head;
	this->_Head = _Head;
	this->_Last = this->_Head;
}

template<typename _Ty>
void tree<_Ty>::make_head_left(value_type val)
{
	this->make_head_left();
	**this->_Head = val;
}

template<typename _Ty>
void tree<_Ty>::make_head_right(value_type val)
{
	this->make_head_right();
	**this->_Head = val;
}

//////////////////////////////////////

template<typename _Ty>
void tree<_Ty>::into_deep_left()
{
	for (; into_left();)
		;
}

template<typename _Ty>
void tree<_Ty>::into_deep_right()
{
	for (; into_right();)
		;
}

//////////////////////////////////////

template<typename _Ty>
void tree<_Ty>::attach_left()
{
	if(!(*this->_Last).is_left() &&
		this->attach_temp != nullptr) {
		this->_Last->_Left = attach_temp;
		this->_Last->_Left->_Parent = this->_Last;
		attach_temp = nullptr;
	}
}

template<typename _Ty>
void tree<_Ty>::attach_right()
{
	if(!(*this->_Last).is_right() &&
		this->attach_temp != nullptr) {
		this->_Last->_Right = attach_temp;
		this->_Last->_Right->_Parent = this->_Last;
		attach_temp = nullptr;
	}
}

template<typename _Ty>
void tree<_Ty>::attach_to_head()
{
	if(this->attach_temp != nullptr) {
		this->_Last = this->_Head = attach_temp;
		attach_temp = nullptr;
	}
}

template<typename _Ty>
void tree<_Ty>::detach_left()
{
	if((*this->_Last).is_left() &&
		this->attach_temp == nullptr) {
		this->attach_temp = this->_Last->_Left;
		this->attach_temp->_Parent = nullptr;
		this->_Last->_Left = nullptr;
	}
}

template<typename _Ty>
void tree<_Ty>::detach_right()
{
	if((*this->_Last).is_right() &&
		this->attach_temp == nullptr) {
		this->attach_temp = this->_Last->_Right;
		this->attach_temp->_Parent = nullptr;
		this->_Last->_Right = nullptr;
	}
}

template<typename _Ty>
void tree<_Ty>::detach_this()
{
    if(this->is_ground()) {
        if(this->is_left() || this->is_right() || this->is_data()) {
            attach_temp = this->_Head;
            last_escape = last_into = 0;
            this->_Head =
            this->_Last = 
                this->allocate();
        }
    } else {
        this->escape();
        if (last_escape == -1) {
            detach_left();
        } else if (last_escape == 1) {
            detach_right();
        }
    }
}

template<typename _Ty>
int tree<_Ty>::last_detach()
{
    return last_escape;
}

/////////////

template<typename _Ty>
void tree<_Ty>::attach_left_tree(
	typename tree<_Ty>::pointer_type v_det)
{
	if(!(*this->_Last).is_left()) {
		this->_Last->_Left = v_det;
		this->_Last->_Left->_Parent = this->_Last;
	}
}

template<typename _Ty>
void tree<_Ty>::attach_right_tree(
	typename tree<_Ty>::pointer_type v_det)
{
	if(!(*this->_Last).is_right()) {
		this->_Last->_Right = v_det;
		this->_Last->_Right->_Parent = this->_Last;
	}
}

template<typename _Ty>
typename tree<_Ty>::pointer_type& tree<_Ty>::detach_left_tree()
{
	if((*this->_Last).is_left()) {
		pointer_type tmp = this->_Last->_Left;
		tmp->_Parent = nullptr;
		this->_Last->_Left = nullptr;
		return tmp;
	}
}

template<typename _Ty>
typename tree<_Ty>::pointer_type& tree<_Ty>::detach_right_tree()
{
	if((*this->_Last).is_right()) {
		pointer_type tmp = this->_Last->_Right;
		tmp->_Parent = nullptr;
		this->_Last->_Right = nullptr;
		return tmp;
	}
}

//////////////////////////////////////

template<typename _Ty>
void tree<_Ty>::dswap_left()
{
	if ((*this->_Last).is_left())
		if((this->_Last->_Left)->is_data() &&
		   (this->_Last)->is_data())
		this->swap(**this->_Last, **this->_Last->_Left);
}

template<typename _Ty>
void tree<_Ty>::dswap_right()
{
	if ((*this->_Last).is_right())
		if((this->_Last->_Right)->is_data() &&
		   (this->_Last)->is_data())
		this->swap(**this->_Last, **this->_Last->_Right);
}

template<typename _Ty>
void tree<_Ty>::dswap_rl()
{
	if ((*this->_Last).is_left() &&
		(*this->_Last).is_right())
		if((this->_Last->_Right)->is_data() &&
		   (this->_Last->_Left)->is_data())
		this->swap(**this->_Last->_Left, **this->_Last->_Right);
}

//////////////////////////////////////

template<typename _Ty>
template<class _Func>
void tree<_Ty>::postorder_travel(_Func& _T, 
	typename tree<_Ty>::pointer_type _Next)
{
	if (_Next == nullptr)
		return;
	postorder_travel(_T, _Next->_Left);
	postorder_travel(_T, _Next->_Right);
	_T(_Next->_Data);
}

template<typename _Ty>
template<class _Func>
void tree<_Ty>::preorder_travel(_Func& _T, 
	typename tree<_Ty>::pointer_type _Next)
{
	if (_Next == nullptr)
		return;
	_T(_Next->_Data);
	preorder_travel(_T, _Next->_Left);
	preorder_travel(_T, _Next->_Right);
}

template<typename _Ty>
template<class _Func>
void tree<_Ty>::inorder_travel(_Func& _T, 
	typename tree<_Ty>::pointer_type _Next)
{
	if (_Next == nullptr)
		return;
	inorder_travel(_T, _Next->_Left);
	_T(_Next->_Data);
	inorder_travel(_T, _Next->_Right);
}

//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////

template<typename _Ty>
tree<_Ty>::postorder_iterator::postorder_iterator(
	typename tree<_Ty>::pointer_type head)
{
	postorder_init(head);
}

template<typename _Ty>
typename tree<_Ty>::reference tree<_Ty>::
	postorder_iterator::operator*() const
{
	return ***postorder_vector;
}

template<typename _Ty>
typename tree<_Ty>::pointer tree<_Ty>::
	postorder_iterator::operator->() const
{
	return &(***postorder_vector);
}

template<typename _Ty>
typename tree<_Ty>::postorder_iterator& tree<_Ty>::
	postorder_iterator::operator++()
{
	postorder_vector++;
	return *this;
}

template<typename _Ty>
typename tree<_Ty>::postorder_iterator& tree<_Ty>::
	postorder_iterator::operator--()
{
	postorder_vector--;
	return *this;
}

template<typename _Ty>
typename tree<_Ty>::postorder_iterator tree<_Ty>::
	postorder_iterator::operator++(int)
{
	postorder_iterator pi = *this;
	++(*this);
	return pi;
}

template<typename _Ty>
typename tree<_Ty>::postorder_iterator tree<_Ty>::
	postorder_iterator::operator--(int)
{
	postorder_iterator pi = *this;
	--(*this);
	return pi;
}

template<typename _Ty>
typename tree<_Ty>::postorder_iterator& tree<_Ty>::
	postorder_iterator::operator+=(unsigned int co)
{
	postorder_vector += co;
	return *this;
}

template<typename _Ty>
typename tree<_Ty>::postorder_iterator& tree<_Ty>::
	postorder_iterator::operator-=(unsigned int co)
{
	postorder_vector -= co;
	return *this;
}

template<typename _Ty>
void tree<_Ty>::postorder_iterator::postorder_init(pointer_type _Next)
{
	//
	//	저는 수 많은 시도 끝에 스택, 큐와 같은
	//	방법으로 루프를 돌리는 것 보다, 초기화시 벡터에 모든 값을
	//	넣는 방법이 가장 효율적이고(트리 코딩시간) 정신건강으로
	//	좋을 듯 하여 선택하였습니다.
	//	속도 저하가 있으면, 초기화 하지 않는 tree::xxx_traver 함수를
	//	이용하시기 바랍니다.
	//
	if (_Next == nullptr)
			return;
	postorder_init(_Next->_Left);
	postorder_init(_Next->_Right);
	postorder_vector.push_back(_Next);
}

namespace traversal {

	template<typename _Iter, class _Func>
		void inorder_travel(_Func& _T, _Iter _Next)
		{
		if (_Next == nullptr)
			return;
		inorder_travel(_T, _Next->_Left);
		_T(_Next->_Data);
		inorder_travel(_T, _Next->_Right);
		}
	
	template<typename _Iter, class _Func>
		void postorder_travel(_Func& _T, _Iter _Next)
		{
		if (_Next == nullptr)
			return;
		postorder_travel(_T, _Next->_Left);
		postorder_travel(_T, _Next->_Right);
		_T(_Next->_Data);
		}
	
	template<typename _Iter, class _Func>
		void preorder_travel(_Func& _T, _Iter _Next)
		{
		if (_Next == nullptr)
			return;
		_T(_Next->_Data);
		preorder_travel(_T, _Next->_Left);
		preorder_travel(_T, _Next->_Right);
		}

}

#endif