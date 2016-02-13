/*-------------------------------------------------

		RollRat Software Stack Class

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

/***********************************************************

		 _____    __  __   ______           __
		/  __ |___\ \ \ \ /  __  | __   _ __\ \__
		| |_| | _ \ | | | | |__| |/  \_| |/___  _/
		|  __/ (_)| | | | |  _  / |(_)  |   | |
		| |  \ ___/ |_| |_| | \ \ \____/    | |
		\_/ \_\    \__\\__\_/  \_\          \_\

		RollRatSoftware-PrivateProgrammingLab

	Copyright (c) rollrat. 2009-2013 All rights reserved.


************************************************************/

#pragma once
#ifndef _LIB_STACK_
#define _LIB_STACK_

template<class _TD> 
class Stack
{
public:
	
	/************************************\
	 * Name		:: Stack				*
	 * Purpose	:: Initialize Buffer	*
	\************************************/
	Stack()
		: size(0), push_point(0)
		{
			TVT = new _TD[sizeof(_TD)];
		}
	~Stack()
		{
			Release();
		}

	/************************************\
	 * Name		:: ClearStack			*
	 * Purpose	:: Clear To Buffer		*
	\************************************/
	void ClearStack();

	/************************************\
	 * Name		:: Push					*
	 * Purpose	:: Push To Buffer		*
	\************************************/
	void push(_TD vt_size)
		{
			//Resize_A(size + 1);
			resize(size + 1);
			TVT[push_point++] = vt_size;
			size++;
		}

	/************************************\
	 * Name		:: Pop					*
	 * Purpose	:: Pop To Buffer		*
	\************************************/
	_TD pop()
		{
			_TD pop = TVT[0];
			if (size>0)
			{
				//Resize_A(--size);
				resize(--size);
				push_point--;
			}
			return pop;
		}

	/************************************\
	 * Name		:: Size					*
	 * Purpose	:: Size To Buffer		*
	\************************************/
	int Size() const;

	/************************************\
	 * Name		:: Resize				*
	 * Purpose	:: Resize To Buffer		*
	\************************************/
	void resize(int size_)
		{
			if (size >= 0)
			{
				_TD * buf = new _TD[size_];
				for(int f = 0; f <= size; f++)
					buf[f] = TVT[f];
				TVT = buf;
				
			}
		}

	/************************************\
	 * Name		:: Release				*
	 * Purpose	:: Release To Buffer	*
	\************************************/
	void Release()
		{
			delete[] TVT;
		}

	/************************************\
	 * Name		:: Get					*
	 * Purpose	:: Get To Buffer		*
	\************************************/
	_TD * GetTVT()
		{
			return TVT;
		}

	/************************************\
	 * Name		:: End					*
	 * Purpose	:: End At Buffer		*
	\************************************/
	_TD End()
		{
			return TVT[size - 1];
		}

	/************************************\
	 * Name		:: Empty				*
	 * Purpose	:: Empty At Buffer		*
	\************************************/
	bool Empty()
		{
			return size == 0;
		}

private:

	/************************************\
	 * Name		:: erase				*
	 * Purpose	:: Erase The Buffer	 	*
	\************************************/
	void erase(int size_)
		{
			resize(size_);
		}

private:

	_TD * TVT; // Stack

private:

	int size;
	int push_point;
	int pop_point;


};

template<class _TD>
inline void Stack<_TD>::ClearStack()
{
	resize(0);
}

template<class _TD>
inline int Stack<_TD>::Size() const
{
	return size;
}

#endif