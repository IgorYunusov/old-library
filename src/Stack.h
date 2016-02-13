/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Stack.h

Purpose:

   RollRat Library

Author:

   10-31-2015:   HyunJun Jeong, Creation

***/

#ifndef _STACK_9bf1541fdf7efd41b7b39543fd870ac4_
#define _STACK_9bf1541fdf7efd41b7b39543fd870ac4_


#include "List.h"

namespace Utility {
	
	template<typename node_type, class allocator>
	struct StackBase
	{
		typedef typename allocator::template rebind<node_type>::other altype;

		typedef typename allocator::pointer tptr;
		typedef typename allocator::template rebind<tptr>::other alptrtype;
	};

	// node value_type cast from type
	template<typename bind, typename type>
	struct StackTransfer
		: public CollectionContainer
	{
		typedef typename type::size_type size_type;
		typedef typename type::value_type value_type;
		typedef typename type::pointer pointer;
		typedef typename type::reference reference;
		typedef typename type::const_pointer const_pointer;
		typedef typename type::const_reference const_reference;
		typedef typename bind::value_type node_type;
		typedef typename bind::pointer node_pointer;
		typedef typename bind::reference node_reference;

		node_pointer head;
		node_pointer last;
		node_pointer tail;
	};

	template<typename base_type>
	class StackAlloc
		: public StackTransfer<typename base_type::altype, 
							typename base_type::altype::value_type>
	{
	public:
		typename base_type::altype alval;
		typedef typename base_type::altype altype;

		StackAlloc(const altype& al = altype())
			: alval(al)
		{
			typename altype::template rebind<CollectionProxy>::other alproxy(this->alval);
			this->proxy = alproxy.allocate(1);
			alproxy.construct(this->proxy, CollectionProxy());
		}

		~StackAlloc()
		{
			typename altype::template rebind<CollectionProxy>::other alproxy(this->alval);
			alproxy.destroy(this->proxy);
			alproxy.deallocate(this->proxy, 1);
			this->proxy = nullptr;
		}

		altype& get()
		{
			return this->alval;
		}

		const altype& get() const
		{
			return this->alval;
		}

	};

	//----------------------------------

	template<typename type>
	class StackNode final
	{
	public:
		typedef StackNode<type> this_type;
		typedef size_t size_type;
		typedef typename type value_type;
		typedef typename type* pointer;
		typedef typename type& reference;
		typedef typename const type* const_pointer;
		typedef typename const type& const_reference;

		this_type* next;
		this_type* prev;
		value_type data;
	};

	template<typename type, class allocator = CollectionAllocator<StackNode<type>>>
	class Stack
		: public StackAlloc<StackBase<StackNode<type>, allocator>>
	{
		typedef StackAlloc<StackBase<StackNode<type>, allocator>> base_type;

		typedef typename base_type::altype altype;
		
		typedef typename base_type::size_type size_type;
		typedef typename base_type::value_type value_type;
		typedef typename base_type::pointer pointer;
		typedef typename base_type::reference reference;
		typedef typename base_type::const_pointer const_pointer;
		typedef typename base_type::const_reference const_reference;
		typedef typename base_type::node_type node_type;
		typedef typename base_type::node_pointer node_pointer;
		typedef typename base_type::node_reference node_reference;

		size_type size;

	public:
		
		Stack()
			: base_type()
			, size(0)
		{
			__Init();
		}

		~Stack()
		{
			if (size > 0)
			{
				__Dispose();
			}
			else
			{
				this->get().deallocate(this->head, 1);
				this->get().deallocate(this->tail, 1);
			}
		}
		
		size_type Size() const
		{
			return this->size;
		}

		value_type& Top()
		{
			return this->last->data;
		}

		void Push(const value_type& val)
		{
			_Append(val);
		}
		void Push(value_type&& val)
		{
			_Append(std::forward<value_type> (val));
		}

		void Pop()
		{
			node_pointer prev = this->last->prev;
			altype alval(this->get());

			prev->next = nullptr;

			alval.destroy(std::addressof(this->last->data));
			this->get().deallocate(this->last, 1);

			this->last = prev;
			--this->size;
		}

	private:
		
		template<class... other_type>
		void _Append(other_type&&... val)
		{
			node_pointer npt = this->get().allocate(1);
			this->get().construct(std::addressof(npt->data),
				std::forward<other_type>(val)...);
			__ConnectBack(npt);
			this->size++;
		}

		template<class... other_type>
		void _Insert(const size_type starts, other_type&&... val)
		{
			node_pointer nptpos = this->head->next;

			for (size_type i = 0; i < starts && nptpos != tail; i++, nptpos = nptpos->next)
				;

			node_pointer npt = this->get().allocate(1);
			this->get().construct(std::addressof(npt->data),
				std::forward<other_type>(val)...);
			__ConnectWith(nptpos->prev, npt, nptpos);
			this->size++;
		}

		void __Dispose()
		{
			node_pointer npt = this->head->next;
			node_pointer nptnext = this->head->next->next;
			altype alval(this->get());

			for (size_type i = 0; i < this->size; i++)
			{
				nptnext = npt->next;
				alval.destroy(std::addressof(npt->data));
				this->get().deallocate(npt, 1);
				npt = nptnext;
			}

			this->get().deallocate(this->head, 1);
			this->get().deallocate(this->tail, 1);
		}

		void __ConnectBack(node_pointer& nptptr)
		{
			this->last->next = nptptr;
			nptptr->prev = this->last;
			nptptr->next = this->tail;
			this->tail->prev = nptptr;
			this->last = nptptr;
		}

		void __ConnectWith(node_pointer& left, node_pointer& middle, node_pointer& right)
		{
			left->next = middle;
			middle->prev = left;
			middle->next = right;
			right->prev = middle;
		}

		void __Init()
		{
			this->head = this->get().allocate(1);
			this->tail = this->get().allocate(1);

			// Connecting
			this->head->next = this->tail;
			this->tail->prev = this->head;
			this->head->prev = nullptr;
			this->tail->next = nullptr;

			this->last = this->head;
		}
	};
}

#endif