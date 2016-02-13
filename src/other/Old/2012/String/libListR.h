/*-------------------------------------------------

		RollRat Software List Class

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
#ifndef _LIB_LIST_
#define _LIB_LIST_

template<class _TD> 
class List
{
public:
	
	/************************************\
	 * Name		:: List					*
	 * Purpose	:: Initialize Buffer	*
	\************************************/
	List()
		: size(0), push_point(0)
		{
			TVT = new _TD[sizeof(_TD)];
		}
	~List()
		{
			Release();
		}

	/************************************\
	 * Name		:: ClearList			*
	 * Purpose	:: Clear To Buffer		*
	\************************************/
	void ClearList();

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
	void push_back(_TD vt_size)
		{
			//Resize_A(size + 1);
			resize(size + 1);
			TVT[push_point++] = vt_size;
			size++;
		}
	void push_front(_TD vt_size)
		{
			//Resize_A(size + 1);
			_TD * buf = TVT;
			resize(size + 1);
			for(int i = 0; i<= size + 1; i++)
				TVT[i + 1] = buf[i];
			TVT[0] = vt_size;
			push_point++;
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
	_TD pop_back()
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
	_TD pop_front()
		{
			_TD pop = TVT[0];
			_TD * buf = TVT;
			if (size>0)
			{
				//Resize_A(--size);
				for(int i = 0; i<= size - 1; i++)
					TVT[i - 1] = buf[i];
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

	/************************************\
	 * Name		:: Reverse				*
	 * Purpose	:: Reverse To Buffer	*
	\************************************/
	void Reverse()
		{
			_TD * buf = new _TD[size];
			int _size = size - 1;
			for(int i = 0; i <= _size; i++)
				buf[i] = pop();
			size = 0;
			for(int f = 0; f <= _size; f++)
				push(buf[f]);
		}

	/************************************\
	 * Name		:: sort					*
	 * Purpose	:: sort To Buffer		*
	\************************************/
	void sort()
		{
			int i, pass;
			_TD hold;
			for(pass = 1; pass <= (size-1); pass++)
				for(i = 0; i <= (size-2); i++)
					if(TVT[i] > TVT[i + 1])
					{
						hold = TVT[i];
						TVT[i] = TVT[i + 1];
						TVT[i + 1] = hold;
					}
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

	_TD * TVT; // list

private:

	int size;
	int push_point;
	int pop_point;


};

template<class _TD>
inline void List<_TD>::ClearList()
{
	resize(0);
}

template<class _TD>
inline int List<_TD>::Size() const
{
	return size;
}


#endif