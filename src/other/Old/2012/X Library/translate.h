/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _translate_
#define _translate_

#include "string.h"

 #pragma warning(disable: 4100 4345)

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

	namespace translate_tree{
		template<class _Ty0>
		struct _stack_nodes
		{ // nodes
			_Ty0 _DATA;
			_stack_nodes *_NEXT;
			_stack_nodes *_PREV;
		};
		template<class _Ty0> inline
			void __remove(_stack_nodes<_Ty0> 
			*&_First, _stack_nodes<_Ty0> *&_Second)
		{ // vector remove
			_stack_nodes<_Ty0> *first = _First->_NEXT->_NEXT;
			for( ; first != _Second; first = first->_NEXT);
			delete first->_PREV;
			delete _First;
			delete _Second;
		}
		template<class _Stack_Element>
		class tree_stack
		{ // stack class
			_stack_nodes<_Stack_Element> *_Head;
			_stack_nodes<_Stack_Element> *_Lastest;
			_stack_nodes<_Stack_Element> *_Tail;
		public:
			explicit tree_stack()
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
			virtual ~tree_stack()
			{ // stack desconductor
				__remove(_Head, _Tail);
			}
			void push(_Stack_Element _left)
			{ // push back item
				_stack_nodes<_Stack_Element> *temp = _New_Node();
				temp->_DATA = _left;
				_Connects(_Lastest, temp, _Tail);
				_Lastest = temp;
			}
			_Stack_Element& pop()
			{ // pop back item
				_stack_nodes<_Stack_Element> *ptr = _Tail->_PREV;
				_stack_nodes<_Stack_Element> *prev = _Tail->_PREV->_PREV;
				_Stack_Element ret;
				ret = ptr->_DATA;
				delete ptr;
				_Connect(prev, _Tail);
				return ret;
			}
		private:
			inline void _Connect(
				_stack_nodes<_Stack_Element> *_head,
				_stack_nodes<_Stack_Element> *_tail)
			{ // connect link
				_head->_NEXT = _tail;
				_tail->_PREV = _head;
			}
			inline void _Connects(
				_stack_nodes<_Stack_Element> *_First,
				_stack_nodes<_Stack_Element> *_Target,
				_stack_nodes<_Stack_Element> *_Last)
			{ // nodes connect
				_First->_NEXT = _Target;
				_Target->_PREV = _First;
				_Target->_NEXT = _Last;
				_Last->_PREV = _Target;
			}
			inline _stack_nodes<_Stack_Element> *_New_Node()
			{ // create new node
				_stack_nodes<_Stack_Element> *ptr = new  
					_stack_nodes<_Stack_Element>;
				return ptr;
			}
		};
		template<class _Ty2>
		class leaf
		{ // leaf of tree
		public:
			leaf *left, *right;
			_Ty2 _data;
			inline _Ty2& operator*()
			{ return _data; }
		};
		template<class _Ty2> inline
			void swap_lr_l(leaf<_Ty2>*& _first)
		{ // swap left right leaf
			leaf<_Ty2> *right = _first->right;
			_first->right = _first->left;
			_first->left = right;
		}
		template<typename unchecked_type> inline
			void _swap(unchecked_type& _Left, unchecked_type& _Right)
		{ // fill all by what parameter
			unchecked_type t = _Left; 
			_Left = _Right; 
			_Right = t;
		}
		template<class _Ty0> inline 
			_Ty0 *new_leaf()
		{ // new leaf
			_Ty0 *ptr = new _Ty0;
			return ptr;
		}
		// STANDRAD Tree
		template<class _Tree_Element>
		class tree
		{ // tree
			typedef leaf<_Tree_Element> _MyLeaf;
			_MyLeaf *_Head;
			tree_stack<_MyLeaf *> _Stack;
		public:
			tree()
			{ // entry point
				_Head = new_leaf<_MyLeaf>();
				suture(_Head);
				_Head->_data = 0;
			}
			void left(_Tree_Element _datas)
			{ // left
				_MyLeaf *ptr = new_leaf<_MyLeaf>();
				suture(ptr);
				ptr->_data  = _datas;
				_Head->left = ptr;
			}
			void right(_Tree_Element _datas)
			{ // left
				_MyLeaf *ptr = new_leaf<_MyLeaf>();
				suture(ptr);
				ptr->_data = _datas;
				_Head->right = ptr;
			}
			_MyLeaf*& left()
			{ return _Head->left; }
			_MyLeaf*& right()
			{ return _Head->right; }
			void visit_left()
			{ // visit left
				_Stack.push(_Head);
				_Head = _Head->left;
			}
			void visit_right()
			{ // visit right
				_Stack.push(_Head);
				_Head = _Head->right;
			}
			_Tree_Element& operator*()
			{ return (_Head->_data); }
			_MyLeaf*& operator&()
			{ return _Head; }
			void leave()
			{ _Head = _Stack.pop(); }
		private:
			inline void suture(_MyLeaf *that)
			{ // suture
				that->left = that;
				that->right = that;
			}
		};
		// TREE ROTATE ALGORITHM
		template<class _Ty1> inline
			void _tree_rotate_right(tree<_Ty1>& _first)
		{ // rotate right (1,2,3) -> (2,3,1)
			leaf<_Ty1> *_head = &_first,	// 1
				*_right = _first.right(),	// 2
				*_left = _first.left();		// 3
			_swap(_head->_data, _right->_data); // (1,2,3) -> (3,2,1)
			_swap(_head->_data, _left->_data); // (3,2,1) -> (2,3,1)
		}
		template<class _Ty1> inline
			void _tree_rotate_left(tree<_Ty1>& _first)
		{ // rotate right (1,2,3) -> (3,1,2)
			leaf<_Ty1> *_head = &_first,	// 1
				*_right = _first.right(),	// 2
				*_left = _first.left();		// 3
			_swap(_head->_data, _left->_data); // (1,2,3) -> (2,1,3)
			_swap(_head->_data, _right->_data); // (2,1,3) -> (3,1,2)
		}
		// TREE SWAP ALGORITHM
		template<class _Ty3> inline
			void _tree_swap_sr_tr(tree<_Ty3>& _first)
		{ // swap second right <-> third right
			leaf<_Ty3> *_l = _first.left()->right,
				*_r = _first.right();
			_swap(_r->_data, _l->_data);
		}
		template<class _Ty3> inline
			void _tree_swap_sl_tl(tree<_Ty3>& _first)
		{ // swap second left <-> third left
			leaf<_Ty3> *_l = _first.right()->left,
				*_r = _first.left();
			_swap(_r->_data, _l->_data);
		}
		template<class _Ty3> inline
			void _tree_swap_ftl_str(tree<_Ty3>& _first)
		{ // f_third right - s_third left
			leaf<_Ty3> *_l = _first.left()->right,
				*_r = _first.right()->left;
			_swap(_r->_data, _l->_data);
		}
		template<class _Ty3> inline
			void _tree_swap_ftr_stl(tree<_Ty3>& _first)
		{ // f_third left - s_third right
			leaf<_Ty3> *_l = _first.left()->left,
				*_r = _first.right()->right;
			_swap(_r->_data, _l->_data);
		}
		template<class _Ty3> inline
			void _tree_swap_ftl_stl(tree<_Ty3>& _first)
		{ // f_third left - s_thid left
			leaf<_Ty3> *_l = _first.left()->left,
				*_r = _first.right()->left;
			_swap(_r->_data, _l->_data);
		}
		template<class _Ty3> inline
			void _tree_swap_ftr_str(tree<_Ty3>& _first)
		{ // f_third right - s_third right
			leaf<_Ty3> *_l = _first.left()->right,
				*_r = _first.right()->right;
			_swap(_r->_data, _l->_data);
		}
		template<class _Ty3> inline
			void _tree_swap(tree<_Ty3>& _first)
		{ // f_second - s_second
			leaf<_Ty3> *_l = _first.left(),
				*_r = _first.right();
			_swap(_r->_data, _l->_data);
		}
		template<class _Ty3> inline
			void _tree_swap_s_tr(tree<_Ty3>& _first)
		{ // second - right third
			leaf<_Ty3> *_rl = _first.right()->left,
				*_rr = _first.right()->right;
			_swap(_first.left()->_data, _rl->_data);
			_swap(_first.right()->_data, _rr->_data);
		}
		template<class _Ty3> inline
			void _tree_swap_s_tl(tree<_Ty3>& _first)
		{ // second - right left
			leaf<_Ty3> *_rl = _first.left()->left,
				*_rr = _first.left()->right;
			_swap(_first.left()->_data, _rl->_data);
			_swap(_first.right()->_data, _rr->_data);
		}
}

template<class _Ty5>
	class engine_node
	{ // engine node
	engine_node *prefix;
	engine_node *suffix;
	_Ty5 word;
	int subex_pos;
	};

template<class _Ty5>
	class engine_syntax
	{ // engine syntax
	engine_node *subject;
	engine_node *verb;
	engine_node **object;
	engine_node **adverb;
	engine_syntax *prev;
	engine_syntax *next;
	_Ty5 syntax;
	};

typedef enum{
	korean,
	english,
	japanese,
}	LANGUAGE_CODE;

template<class _Ty18 = unsigned char>
	class make_tree
	{ // make tree
	translate_tree::tree<_Ty18> trees;
	translate_tree::tree<engine_syntax<_Ty18> > syntax_e;
	LANGUAGE_CODE num;
	string<_Ty18> str;
public:
	make_tree(string<_Ty18> *all)
		: str(all), num(korean)
		{}
	make_tree(string<_Ty18> *all, LANGUAGE_CODE numberic)
		: str(all), num(numberic)
		{}
private:

	};

template<class _Ty0>
	class translate
	{

	};

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-04
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/