/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_LINKL_
#define _ROLLRAT_LINKL_

#include "rutil.h"
#include <iostream>
#include <assert.h>

#if defined(_EX_SUCCESS)

_X_LIB_BEGIN
	
	template<class _Nt>class sList;

	template<class _Nt>
	class ListNode{
		friend class sList<_Nt>;
	public:
		ListNode(const _Nt &info){data = info;nextPtr = 0;}
		_Nt getData() const{return data;}
	private:
		_Nt data;
		ListNode *nextPtr;
	};

	template<class _Nt>
	class sList{
	public:
		sList(){firstPtr = lastPtr = 0;}
		~sList()
		{
			if(!isEmpty()){
				ListNode<_Nt> *currentPtr = firstPtr, *tempPtr;
				while(currentPtr != 0)
				{
					tempPtr = currentPtr;
					currentPtr = currentPtr->nextPtr;
					delete tempPtr;
				}
			}
		}
		void insertAtFront(const _Nt &value)
		{
			ListNode<_Nt> *newPtr = getNewNode(value);
			if(!isEmpty())
				firstPtr = lastPtr = newPtr;
			else 
			{
				lastPtr->nextPtr = newPtr;
				lastPtr = newPtr;
			}
		}
		void insertAtBack(const _Nt &value)
		{
			ListNode<_Nt> *newPtr = getNewNode(value);
			if(isEmpty())
				firstPtr = lastPtr = newPtr;
			else 
			{
				lastPtr->nextPtr = newPtr;
				lastPtr = newPtr;
			}
		}
		int removeFromFront(_Nt &value)
		{
			if(isEmpty())
				return 0;
			else
			{
				ListNode<_Nt> *tempPtr = firstPtr;
				if(firstPtr == lastPtr)
					firstPtr = lastPtr = 0;
				else
					firstPtr = firstPtr->nextPtr;
				value = tempPtr->data;
				delete tempPtr;
				return 1;
			}
		}
		int removeFromBack(_Nt &value)
		{
			if(isEmpty())
				return 0;
			else
			{
				ListNode<_Nt> *tempPtr = firstPtr;
				if(firstPtr == lastPtr)
					firstPtr = lastPtr = 0;
				else
				{
					ListNode<_Nt> *currentPtr = firstPtr;
					while(currentPtr->nextPtr != lastPtr)
						currentPtr = currentPtr->nextPtr;
					lastPtr = currentPtr;
					currentPtr->nextPtr = 0;
				}
				value = tempPtr->data;
				delete tempPtr;
				return 1;
			}
		}
		int isEmpty() const{return firstPtr == 0;}
		void print() const
		{
			if(isEmpty())
			{
				std::cout << "The list is Empty" << std::endl << std::endl;
				return;
			}

			ListNode<_Nt> *currentPtr = firstPtr;

			std::cout << "The list is : ";

			while(currentPtr != 0)
			{
				std::cout << currentPtr->data << ' ';
				currentPtr = currentPtr->nextPtr;
			}
			std::cout << std::endl << std::endl;
		}
	private:
		ListNode<_Nt> *firstPtr;
		ListNode<_Nt> *lastPtr;
		ListNode<_Nt> *getNewNode(const _Nt &value)
		{
			ListNode<_Nt> *ptr = new ListNode<_Nt>(value);
			assert(ptr != 0);
			return ptr;
		}
	};




	struct _nodes
		{
		int key;
		struct _nodes *next;
		};

	_nodes *head, *tail;

	void init_list()
		{
		head = new _nodes[sizeof(_nodes)];
		tail = new _nodes[sizeof(_nodes)];
		head->next = tail;
		tail->next = tail;
		}

	_nodes *find_node(int k)
		{
		_nodes *s;
		s = head->next;
		while(s->key != k && s != tail)
			s = s->next;
		return s;
		}

	int delete_node(int k)
		{
		_nodes *s, *p;
		p = head;
		s = p->next;

		while(s->key != k && s != tail)
			{
			p = p->next;
			s = p->next;
			}

		if(s != tail)
			{
			p->next = s->next;
			delete[] s;
			return true;
			}
		return false;
		}

	_nodes *insert_node(int t, int k)
		{
		_nodes *s, *p, *r;
		p = head;
		s = p->next;
		while(s->key != k && s != tail)
			{
			p = p->next;
			s = p->next;
			}
		if(s != tail)
			{
			r = new _nodes[sizeof(_nodes)];
			r->key = t;
			p->next = r;
			r->next = s;
			}
		return p->next;
		}

	_nodes *ordered_insert(int k)
		{
		_nodes *s, *p, *r;
		p = head;
		s = p->next;
		while(s->key != k && s != tail)
			{
			p = p->next;
			s = p->next;
			}
		r = new _nodes[sizeof(_nodes)];
		r->key = k;
		p->next = r;
		r->next = s;
		return r;
		}

_X_LIB_END


#endif

#endif