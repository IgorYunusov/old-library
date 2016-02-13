/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_VECTOR_
#define _ROLLRAT_VECTOR_
#include "rutil.h"

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN

	_CCC_C_TEMPLATE_CS
	template<class _Ty,
			 class _Vector,
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
			 struct _X_Vector_Ty
			 { // the vector type class
			 typedef _Vector Iterator;
			 typedef _Ty Value_Type;
			 typedef _Pointer Pointer;
			 typedef _Reference Reference;
			 };

	_CCC_C_TEMPLATE_CS
	template<class _Ty, 
			 class _Vector = _Ty, 
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
	class _X_Vector_Ex 
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Memory<_Ty>,
		public _X_Vector_Ty<_Vector, _Ty, _Pointer, _Reference>
		{
		typedef _X_Vector_Ex<_Ty, _Vector, _Pointer, _Reference> _MyT;
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _X_TYPE<_Ty>::UnPointer _MyUP;
		typedef typename _X_TYPE<_Ty>::Pointer _MyPI;

		public:
		typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Iterator _VeIC;
		//typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Iterator Iterator;
		typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Value_Type _VeT;
		typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Pointer _VePI;
		typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Reference _VeUP;
		typedef typename _X_Memory<_Ty> _XM;

		public:

			explicit _X_Vector_Ex()
				: size(0), push_point(0)
				{ // entry of vector
				List = new _VeIC[sizeof(_VeIC)];
				}

			explicit _X_Vector_Ex(int size)
				: size(size+1), push_point(0)
				{ // entry of vector
				List = new _VeIC[sizeof(this->size)];
				}

			~_X_Vector_Ex()
				{ // desconductor
				release();
				}

			_VePI resize(_VePI Array, _MyVT size)
				{ // allocate array in memory
				_MyC::Set(size, const_cast<_VePI> (Array));
				_VePI buf = new _VeT[size];
				for(int f = 0; f <= this->size; f++)
					buf[f] = Array[f];
				this->List = buf;
				return buf;
				}

			void resize(_MyVT size)
				{ // allocate array in memory
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[size];
				for(int f = 0; f <= this->size; f++)
					buf[f] = List[f];
				this->size = size;
				this->List = buf;
				}

			_VeT operator[](size_t size) const
				{ // operator [ size~ ]
				return (this->List[size]);
				}

			void operator>>(int size)
				{ // operator << decrease
				_MyC::Set(this->size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[this->size - size];
				for(int i = 0; i <= size; i++)
					buf[i] = List[i+size];
				insertion(buf, this->size - size);
				}

			void operator<<(int size)
				{ // operator >> increase
				_MyC::Set(this->size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[this->size + size];
				for(int i = 0; i <= this->size; i++)
					buf[i] = List[i];
				insertion(buf, this->size + size);
				}

			void operator=(_MyT& _List)
				{ // operator = equal
					BEGIN_TRY
				if((this->size && INT_MAX) <= 0) 
					THROW_ERROR_INPUT(_List)
				this->List = _List.List;
				this->push_point = _List.push_point;
				this->size = _List.size;
					END_TRY
					BEGIN_CATCH(_MyT _List)
				throw 0;
					END_CATCH
				}

			bool operator==(_MyT& _List)
				{ // if input = this
				return _List.List == this->List;
				}

			bool operator!=(_MyT& _List)
				{ // if not input = this
				return _List.List != this->List;
				}

			bool operator<(_MyT& _List)
				{ // compare to size
				return this->size < _List.size;
				}
			
			bool operator>(_MyT& _List)
				{ // compare to size
				return this->size > _List.size;
				}
			
			bool operator<=(_MyT& _List)
				{ // compare to size
				return this->size <= _List.size;
				}
			
			bool operator>=(_MyT& _List)
				{ // compare to size
				return this->size >= _List.size;
				}

			void swap(_MyT& _List)
				{ // swap input and list
				int size=_List.size, pp=_List.push_point;
				_VeT* buf = new _VeT[_List.size];
				buf = _List.List;
				this->List = _List.List;
				this->size = _List.size;
				this->push_point = _List.push_point;
				_List.size = size;
				_List.new_vector(buf, size);
				_List.push_point = pp;
				}

			void insertion(_VePI _List, int _Size)
				{ // put info
				this->List = _List;
				this->size = _Size;
				this->push_point = _Size;
				}

			void clear()
				{ // clear the vector
					BEGIN_TRY
				if((this->size && INT_MAX) == 0)
					THROW_ERROR_INPUT(size)
				release();
				this->size = 0;
				this->push_point = 0;
					END_TRY
					BEGIN_CATCH(int size)
				throw 0;
					END_CATCH
				}

#if defined(_ELF_COMMON) // use  _X_COMMON<_Ty, _Ty, _Ty*> set

			void push_back(_VeT data)
				{ // push the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				resize(List, size + 1);
				List[push_point++] = data;
				size++;
				}

			void push_back(_MyT& data)
				{ // push the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= data.size; i++)
					push_back(data.List[i]);
				}

			void push_back(_VeT* data, int size_)
				{ // push the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= size_; i++)
					push_back(data[i]);
				}

			void push_front(_VeT data)
				{ // push the data to front list
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = List;
				resize(this->List, size + 1);
				for(int i = 0; i<= size + 1; i++)
					this->List[i + 1] = buf[i];
				this->List[0] = data;
				push_point++;
				size++;
				}

			void push_front(_VeT* data, int size_)
				{ // push the data to front list
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= size_; i++)
					push_front(data[i]);
				}

			void push_front(_MyT& data)
				{ // push the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= data.size; i++)
					push_front(data.List[i]);
				}

			_VeT pop()
				{ // pop the data and return that
				_MyC::Set(size, const_cast<_VePI> (List));
				_VeT pop = List[size - 1];
				if (size>0){
				resize(--size);
				--this->push_point;}
				return pop;
				}

			void pop_back()
				{ // pop the data to back list
				_MyC::Set(size, const_cast<_VePI> (List));
				_VeT pop = List[size - 1];
				if (size>0){
				resize(--size);
				--this->push_point;}
				}

			void pop_front()
				{ // pop the data to front list
				_MyC::Set(size, const_cast<_VePI> (List));
				_VeT pop = this->List[0];
				_VePI buf = this->List;
				if (size>0)
				{for(int i = 0; i<= size - 1; i++)
					this->List[i - 1] = buf[i];
				resize(--size);
				--this->push_point;}
				}

			void fill(_VeT data)
				{ // fill list by data
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= size; i++)
					List[i] = data;
				}

			void fill(size_t _point, _VeT data)
				{ // fill list by data
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = 0; i <= _point; i++)
					List[i] = data;
				}

			void fill(_VeT data, size_t _point)
				{ // fill list by data
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = _point; i <= size; i++)
					List[i] = data;
				}

			void fill(_VeT data, int _point, int size_)
				{ // fill list by data
				_MyC::Set(size, const_cast<_VePI> (List));
				for(int i = _point; i <= size_; i++)
					List[i] = data;
				}

			void reverse()
				{ // reverse the array point
				_MyC::Set(size, const_cast<_VePI> (List));
				_VeT * buf = new _VeT[size];
				int _size = size - 1;
				for(int i = 0; i <= _size; i++)
					buf[i] = pop();
				size = 0;
				for(int f = 0; f <= _size; f++)
					push_back(buf[f]);
				}

			void sort()
				{ // sorting list
				_MyC::Set(size, const_cast<_VePI> (List));
				int i, pass;
				_VeT hold;
				for(pass = 1; pass <= (size-1); pass++)
				for(i = 0; i <= (size-2); i++)
				if(List[i] > List[i + 1])
				{hold = List[i];
				List[i] = List[i + 1];
				List[i + 1] = hold;}
				}

			void erase(int point, int size_)
				{ // erase the data by p-s
				_MyC::Set(size, const_cast<_VePI> (List));
				int _size = size - (size_ + 1);
				_VePI buf = new _VeT[_size];
				for(int i = 0, f = 0; i<=size; i++)
				{if (point <= i <= (point+size_))continue;
				buf[f++] = List[i];}
				insertion(buf, _size);
				}

			void erase(int point)
				{ // erase the data by point at
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[size - 1];
				for(int i = 0, f = 0; i < (size - 1); i++)
				{if(i == point) continue;
				buf[f++] = List[i];}
				insertion(buf, size - 1);
				}

			void insert(int point, _VeT Data)
				{ // insert the data to point
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[size + 1];
				for(int i = 0; i < point; i++)buf[i] = List[i];
				for(int f = point + 1; f <= size; f++)buf[f] = List[f];
				buf[point] = Data;
				insertion(buf, size+1);
				}

			void insert(int point, int size_, _VeT Data)
				{ // insert the data to point
				_MyC::Set(size, const_cast<_VePI> (List));
				_VePI buf = new _VeT[size + size_];
				for(int i = 0; i < (size + size_); i++)
				{if(point <= i < (point + size_)) buf[i] = Data;
				buf[i] = List[i];}
				insertion(buf, size + size_);
				}

#endif

			void at(int point)
				{ // return point
				if(point > size) 
					THROW_ERROR_INPUT(size)
				return List[point];
				}

			void assign(int n, _VeT Data)
				{ // put data by n
				for(int i = 0; i < n; i++)
					this->push_back(Data);
				}

			void asign(int n, int m, _VeT Data)
				{ // put data n ~ m
				for(int i = n; n <= m; i++)
					List[i] = Data;
				}

			_VeT front() const
				{ // get the front list item
				return List[0];
				}

			_VeT back() const
				{ // get the back list item
				return List[size - 1];
				}

			int size_r() const
				{ // return size
				return size - 1;
				}

			void new_vector()
				{ // create new vector
				if(if_size())
					release();
				_X_Vector_Ex;
				this->size = 0;
				this->push_point = 0;
				}

			void new_vector(_VeT * _List, int size)
				{ // create new vector 
				_VePI listheap = new _VeT[size];
				for(int i = 0; i <= size; i++)
					listheap[i] = _List[i];
				this->List = listheap;
				}

			bool if_size() const
				{ // if size
				return (this->size && INT_MAX) > 0;
				}

			bool empty() const
				{ // if empty
				return size == 0;
				}

			void set_point(int point)
				{ // set point array
				if((point && INT_MAX) <= 0)
					exit(0);
				push_point = point;
				}

			void release() const
				{ // desconductor event
				_XM::free(List);
				}

			_VePI get_pi()
				{ // return list
				return (this->List);
				}

			int get_pp()
				{
				return push_point;
				}

		private:

			int size;
			_VePI List;
			int push_point;

		};

		
_X_LIB_END

#endif

#endif