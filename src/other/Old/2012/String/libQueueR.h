/*-------------------------------------------------

		RollRat Software Queue Class

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
#ifndef _LIB_QUEUE_
#define _LIB_QUEUE_

template<class _TD> 
class Queue
{
public:

	/************************************\
	 * Name		:: Queue				*
	 * Purpose	:: Initialize Buffer	*
	\************************************/
	Queue()
		: size(0), push_point(0)
		{
			TVT = new _TD[sizeof(_TD)];
		}
	~Queue()
		{
			Release();
		}

	/************************************\
	 * Name		:: ClearQueue			*
	 * Purpose	:: Clear To Buffer		*
	\************************************/
	void ClearQueue();

	/************************************\
	 * Name		:: Push					*
	 * Purpose	:: Push To Buffer		*
	\************************************/
	void Push(_TD vt_size)
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
	_TD Pop()
		{
			_TD pop = TVT[size - 1];
			if (size>0)
			{
				//Resize_A(--size);
				resize(--size);
				push_point--;
			}
			return pop;
		}

	/************************************\
	 * Name		:: Front				*
	 * Purpose	:: Front To Buffer		*
	\************************************/
	_TD Front()
		{
			_TD pop = TVT[size - 1];
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

	_TD * TVT; // list

private:
	int size;
	int push_point;

};

template<class _TD>
inline void Queue<_TD>::ClearQueue()
{
	resize(0);
}

template<class _TD>
inline int Queue<_TD>::Size() const
{
	return size;
}

#endif