/*-------------------------------------------------

		RollRat Software Vector Class

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
#ifndef _LIB_VECTOR_
#define _LIB_VECTOR_

template<class _TD> 
class Vector
{
public:

	/************************************\
	 * Name		:: Vector				*
	 * Purpose	:: Initialize Buffer	*
	\************************************/
	Vector()
		: size(0), push_point(0)
		{
			TVT = new _TD[sizeof(_TD)];
		}
	~Vector()
		{
			Release();
		}

	/************************************\
	 * Name		:: SetVector			*
	 * Purpose	:: SetVector To Buffer	*
	\************************************/
	void SetVector(const _TD, const _TD, const _TD) const;
	
	/************************************\
	 * Name		:: GetVector			*
	 * Purpose	:: GetVector To Buffer	*
	\************************************/
	void GetVector(_TD, _TD, _TD) const;

	/************************************\
	 * Name		:: ClearVector			*
	 * Purpose	:: Clear To Buffer		*
	\************************************/
	void ClearVector();

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
	_TD pop_back()
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
	 * Name		:: Operator[]			*
	 * Purpose	:: Return Buffer		*
	\************************************/
	_TD operator[](int size_)
		{
			if(size_<=size)
				return TVT[size_];
		}
	_TD operator[](int size_) const
		{
			if(size_<=size)
				return TVT[size_];
		}
	void operator=(Vector<_TD> vt)
		{
			Swap(vt);
		}

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
	 * Name		:: Reverse				*
	 * Purpose	:: Reverse To Buffer	*
	\************************************/
	void Reverse()
		{
			_TD * buf = new _TD[size];
			int _size = size - 1;
			for(int i = 0; i <= _size; i++)
				buf[i] = Pop();
			size = 0;
			for(int f = 0; f <= _size; f++)
				Push(buf[f]);
		}

	/************************************\
	 * Name		:: Swap					*
	 * Purpose	:: Swap To Buffer		*
	\************************************/
	void Swap(Vector<_TD> _TVT)
		{
			_TD * buf = new _TD[_TVT.Size()];
			int _size = _TVT.Size() - 1;
			for(int i = 0; i <= _size; i++)
				buf[i] = _TVT.Pop();
			size = 0;
			for(int f = 0; f <= _size; f++)
				Push(buf[f]);
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
	 * Name		:: Start				*
	 * Purpose	:: Start At Buffer		*
	\************************************/
	_TD Start()
		{
			return TVT[0];
		}
	_TD Front()
		{
			return TVT[0];
		}


	/************************************\
	 * Name		:: End					*
	 * Purpose	:: End At Buffer		*
	\************************************/
	_TD End()
		{
			return TVT[size - 1];
		}
	_TD Back()
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

	mutable _TD VT_1;
	mutable _TD VT_2;
	mutable _TD VT_3;

	_TD * TVT; // list

private:

	int size;
	int push_point;

};

template<class _TD>
inline void Vector<_TD>::SetVector(const _TD vt_1, const _TD vt_2, const _TD vt_3) const
{
	VT_1 = vt_1;
	VT_2 = vt_2;
	VT_3 = vt_3;
}

template<class _TD>
inline void Vector<_TD>::GetVector(_TD vt_1, _TD vt_2, _TD vt_3) const
{
	vt_1 = VT_1;
	vt_2 = VT_2;
	vt_3 = VT_3;
}

template<class _TD>
inline void Vector<_TD>::ClearVector()
{
	VT_1 = 0;
	VT_2 = 0;
	VT_3 = 0;
	resize(0);
}

template<class _TD>
inline int Vector<_TD>::Size() const
{
	return size;
}

#endif