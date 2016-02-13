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
	//	������ �ʱ�ȭ�� ���� nullptr, NULL, 0 ������
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
    //  -1�̸� ����, 1�̸� ������, 0�̸� ���
    //
    int last_into;
    int last_escape;
    
private:
	pointer_type allocate(const void * = 0);
	void deallocate(pointer_type __p);

	template<typename T>
	void swap(T& _Left, T& _Right);

public:

	// ���ʿ� �� ��Ҹ� �߰��մϴ�.
	void push_left();
	// �����ʿ� �� ��Ҹ� �߰��մϴ�.
	void push_right();
	// ���ʿ� �� ��Ҹ� �߰��ϰ�, ���� �ʱ�ȭ�մϴ�.
	void push_left(value_type val);
	// �������� �� ��Ҹ� �߰��ϰ�, ���� �ʱ�ȭ�մϴ�.
	void push_right(value_type val);

	// ���� ��带 ���� ���� �ű�ϴ�.
	// ���� ��尡 �������� �ʴ´ٸ� false�� ��ȯ�˴ϴ�.
	bool into_left();
	// ���� ��带 ������ ���� �ű�ϴ�.
	// ������ ��尡 �������� �ʴ´ٸ� false�� ��ȯ�˴ϴ�.
	bool into_right();
	// ���� ��带 ���� ����� ���� ������ ���� �ű�ϴ�.
	// �ش� ��尡 �������� �ʴ´ٸ� false�� ��ȯ�˴ϴ�.
	bool escape();
	// ���� ��带 ������ �ű�ϴ�.
	void ground();

	// ���� ��尡 �����ϴ����� ���θ� �����ɴϴ�.
	bool is_left();
	// ������ ��尡 �����ϴ����� ���θ� �����ɴϴ�.
	bool is_right();
	// ���� ��忡 ���� �ִ����� ���θ� �����ɴϴ�.
	bool is_data();
	// ���� ��忡 ���� ��尡 �����ϴ����� ���θ� �����ɴϴ�.
	bool is_parent();
	// ���� ��尡 �� ���� ��带 ����Ű������ ���θ� �����ɴϴ�.
	bool is_ground();

	// ���� ����� �����͸� �����մϴ�.
	reference operator*();
	pointer operator->();
	pointer_type operator&();

	pointer_type travel();
	reference left();
	reference right();

	// ���ο� ��带 ����� ����� ���ʷ� ������ ��带 �ű�ϴ�.
	void make_head_left();
	// ���ο� ��带 ����� ����� ���������� ������ ��带 �ű�ϴ�.
	void make_head_right();
	// ����� ���� �ʱ�ȭ�ϴ� ���ο� ��带 ����� ����� ���ʷ� ������ ��带 �ű�ϴ�.
	void make_head_left(value_type val);
	// ����� ���� �ʱ�ȭ�ϴ� ���ο� ��带 ����� ����� �����ʷ� ������ ��带 �ű�ϴ�.
	void make_head_right(value_type val);

	// ���� ��带 ���� ���ϴ����� �ű�ϴ�.
	void into_deep_left();
	// ���� ��带 ������ ���ϴ����� �ű�ϴ�.
	void into_deep_right();

	/*
		
		��� ������ �� ���� �� ���� �����ϴ�.
		�˰��� �ۼ��� 2�� �̻��� ���̴� ��찡 ���� 
		���� ������ �׷��� �����߽��ϴ�.

	*/
    
	// �ӽ������ ��带 ���� ����� ���ʿ� ���Դϴ�.
	void attach_left();
	// �ӽ������ ��带 ���� ����� �����ʿ� ���Դϴ�.
	void attach_right();
    // �ӽ������ ��带 ��忡 ���Դϴ�.
    void attach_to_head();
	// ���� ��带 �ӽ� �����մϴ�.
	void detach_left();
	// ������ ��带 �ӽ� �����մϴ�.
	void detach_right();
    // ���� ��带 �ӽ� �����մϴ�.
    void detach_this();

    // ���������� ��� detach_this�Ǿ����� �����ɴϴ�.
    int last_detach();

	void attach_left_tree(pointer_type v_det);
	void attach_right_tree(pointer_type v_det);
	pointer_type& detach_left_tree();
	pointer_type& detach_right_tree();

	// ���� ����� ���� ���� ����� ���� ���� �ٲߴϴ�.
	void dswap_left();
	// ���� ����� ���� ������ ����� ���� ���� �ٲߴϴ�.
	void dswap_right();
	// ���� ����� ���� ������ ����� ���� ���� �ٲߴϴ�.
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

        // escape�� ��ġ�� ������� ������
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
	//	���� �� ���� �õ� ���� ����, ť�� ����
	//	������� ������ ������ �� ����, �ʱ�ȭ�� ���Ϳ� ��� ����
	//	�ִ� ����� ���� ȿ�����̰�(Ʈ�� �ڵ��ð�) ���Űǰ�����
	//	���� �� �Ͽ� �����Ͽ����ϴ�.
	//	�ӵ� ���ϰ� ������, �ʱ�ȭ ���� �ʴ� tree::xxx_traver �Լ���
	//	�̿��Ͻñ� �ٶ��ϴ�.
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