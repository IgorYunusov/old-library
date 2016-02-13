/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _traver_
#define _traver_

#include "tree.h"

 #pragma warning(disable: 4100 4345)

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
typedef enum
	{ // traverse sign
	Preorder, Postorder, Inorder
	} traverse_sign;

template<class _Ty0>
	class traver
	{ // tree traver
	typedef leaf<_Ty0> _MyLeaf;
	_MyLeaf *_Head, *Prev;
	tree_stack<_MyLeaf *> _Stack;
	traverse_sign g;
	int tree_deep;
public:
	traver(tree<_Ty0>& _tree, traverse_sign f)
		: _Head((&_tree)), g(f), tree_deep(0)
		{ }
	_MyLeaf*& operator*()
		{ // return now form
		return _Head;
		}
	bool operator++()
		{ // operator ++
		if (g == Preorder)
			{
			if(_Head != _Head->left){tree_deep++;
				_Stack.push(_Head);_Head = _Head->left; 
				return true;}
			if(_Head != _Head->right){tree_deep++;
				_Stack.push(_Head);_Head = _Head->right;
				return true;}
			tree_deep--;
			for(int i = 0; i <= tree_deep; i++){
				Prev = _Head;
				_Head = _Stack.pop();
				if((_Head != _Head->right) 
					&& _Head->right != Prev){
				_Head = _Head->right;
				return true;}
				}
			tree_deep = 0;
			return false;
			} else 
		if (g == Postorder)
			{
			if(!tree_deep)
				for( ; _Head != _Head->left; _Head = _Head->left, tree_deep++)
					;

			} else
		if (g == Inorder)
			{
			}
		}
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
V0.1:0012****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/