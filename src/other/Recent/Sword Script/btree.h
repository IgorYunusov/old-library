/*************************************************************************
  
   RollRat Library
   (The B-Tree Algorithm)


   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _B_TREE_f95371b052ca60558e76a08aed9e6da4_
#define _B_TREE_f95371b052ca60558e76a08aed9e6da4_

// MD5 : rollrat b-tree

/*

        B-Tree의 키는 반드시 숫자여야합니다.

*/

#define B_TREE_OVERFLOW_OK

#define B_TREE_MAXIMUM_ITEM         5

#include <vector>
#include <string>
#include <cmath>
#include <new>
#include <stack>

#ifndef _CUSTROM_SIZE_TYPE
using::size_t;
#define __SIZE_TYPE		size_t
#endif
#ifndef _CUSTOM_OTHER_TYPE
//using::ptrdiff_t;
typedef int __w64 _ptrdiff_t;
#define __OTHER_TYPE	_ptrdiff_t
#endif

template<typename _Tree_val> class
    b_tree_node
{
public:
    typedef b_tree_node<_Tree_val> _Myt;
    
	typedef typename __SIZE_TYPE		size_type;
	typedef typename __OTHER_TYPE		difference_type;
	typedef typename _Tree_val*			pointer;
	typedef typename const _Tree_val*	const_pointer;
	typedef typename _Tree_val&			reference;
	typedef typename const _Tree_val&	const_reference;
	typedef typename _Tree_val			value_type;

	b_tree_node();

	_Myt *_Left, *_Right, *_Parent;

	value_type _Data1;
	value_type _Data2;
	value_type _Data3;
	value_type _Data4;
	value_type _Data5;

    value_type _DataOverflow;

    size_type size;
};

template<class _Tree_val> b_tree_node<_Tree_val>::
	b_tree_node()
	: _Left(nullptr), _Right(nullptr), _Parent(nullptr), 
    _Data1(value_type()),  _Data2(value_type()),  
    _Data3(value_type()),  _Data4(value_type()), _Data5(value_type()),
    _DataOverflow(value_type()),
    size(0)
{ 
}

/*
    B+ Tree Algorithm
*/
template<typename _Ty> class
    b_tree
{
public:
	typedef b_tree<_Ty> _Mytree;
	typedef b_tree_node<_Ty> _Mynode;

	typedef typename _Mynode::size_type size_type;
	typedef typename _Mynode::pointer pointer;
	typedef typename _Mynode::reference reference;
	typedef typename _Mynode::const_pointer const_pointer;
	typedef typename _Mynode::const_reference const_reference;
	typedef typename _Mynode::value_type value_type;

	typedef typename _Mynode this_type;
	typedef typename _Mynode* pointer_type;
	typedef typename _Mynode& reference_type;


private:

    // 오버플로우 파티션 분할
    void tree_partition_over();
    // 언더플로우 파티션 병합
    void tree_merger_over();

    // 다음 인자가 들어오면 오버플로가 발생할 경우 true를 출력합니다.
    bool check_overflow_pre();
    // 다음 인자가 나가면 오버플로가 발생할 경우 true를 출력합니다.
    bool check_underflow_pre();

    // 현재 노드의 기댓값을 계산합니다.
    double calculate_expectation();
    // 기댓값과 가장 가까운 값의 키를 가져옵니다.
    int get_near_expectation();

protected:

    int key_count;
};

#endif