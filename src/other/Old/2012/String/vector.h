/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_VECTOR_
#define _ROLLRAT_VECTOR_
#include "rutil.h"
#include "cutilityex.h"

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
	template<class differentkindof_type> class
		_const_iterator_vex
	{ // const iterator class
		typedef _const_iterator_vex<differentkindof_type> _Myiter;
		typedef typename _Myiter* _MyPtr;
	public:
		_const_iterator_vex() : _PtrEx() { }
		_Myiter& operator*() const {return (*this->_PtrEx);}
		_MyPtr operator->() const {return (**this);}
		_Myiter& operator++() {++this->_PtrEx;return (*this);}
		_Myiter operator++(int) {_Myiter TempPtr = *this;++*this;return (TempPtr);}
		_Myiter operator--() {--this->_PtrEx;return (*this);}
		_Myiter operator--(int) {_Myiter TempPtr = *this;--*this;return (TempPtr);}
		template<typename unchecked_type> _Myiter& operator+=(unchecked_type offset) {_PtrEx += offset;return (*this);}
		template<typename unchecked_type> _Myiter operator+(unchecked_type offset) const {_Myiter TempPtr = *this;return TempPtr += offset;}
		template<typename unchecked_type> _Myiter operator-=(unchecked_type offset) {return *this + -offset;}
		template<typename unchecked_type> _Myiter operator-(unchecked_type offset) const {_Myiter TempPtr = *this;return (TempPtr -= offset);}
		template<typename unchecked_type> unchecked_type operator-(const _Myiter& ccc) const {return (this->_PtrEx - ccc._PtrEx);}
		template<typename unchecked_type> _Myiter& operator[](unchecked_type offset) const {return (*(*this + offset));}
		bool operator==(const _Myiter& ccc) const {return (this->_PtrEx == ccc._PtrEx);}
		bool operator!=(const _Myiter& ccc) const {return (!(*this == ccc));}
		bool operator<(const _Myiter& ccc) const {return (this->_PtrEx < ccc._PtrEx);}
		bool operator>(const _Myiter& ccc) const {return (ccc < *this);}
		bool operator<=(const _Myiter& ccc) const {return (!(ccc < *this));}
		bool operator>=(const _Myiter& ccc) const {return (!(*this < ccc));}
	private: _MyPtr _PtrEx;
	};

	template<class differentkindof_type> class
		_iterator_vex
	{ // const iterator class
		typedef _iterator_vex<differentkindof_type> _Myiter;
		typedef typename _Myiter* _MyPtr;
	public:
		_iterator_vex() : _PtrEx() { }
		_Myiter& operator*() {return (*this->_PtrEx);}
		_MyPtr operator->() {return (**this);}
		_Myiter& operator++() {++this->_PtrEx;return (*this);}
		_Myiter operator++(int) {_Myiter TempPtr = *this;++*this;return (TempPtr);}
		_Myiter operator--() {--this->_PtrEx;return (*this);}
		_Myiter operator--(int) {_Myiter TempPtr = *this;--*this;return (TempPtr);}
		template<typename unchecked_type>_Myiter& operator+=(unchecked_type offset) {_PtrEx += offset;return (*this);}
		template<typename unchecked_type> _Myiter operator+(unchecked_type offset) {_Myiter TempPtr = *this;return TempPtr += offset;}
		template<typename unchecked_type> _Myiter operator-=(unchecked_type offset) {return *this + -offset;}
		template<typename unchecked_type> _Myiter operator-(unchecked_type offset) {_Myiter TempPtr = *this;return (TempPtr -= offset);}
		template<typename unchecked_type> unchecked_type operator-(const _Myiter& ccc) {return (this->_PtrEx - ccc._PtrEx);}
		template<typename unchecked_type> _Myiter& operator[](unchecked_type offset) {return (*(*this + offset));}
		bool operator==(const _Myiter& ccc) const {return (this->_PtrEx == ccc._PtrEx);}
		bool operator!=(const _Myiter& ccc) const {return (!(*this == ccc));}
		bool operator<(const _Myiter& ccc) const {return (this->_PtrEx < ccc._PtrEx);}
		bool operator>(const _Myiter& ccc) const {return (ccc < *this);}
		bool operator<=(const _Myiter& ccc) const {return (!(ccc < *this));}
		bool operator>=(const _Myiter& ccc) const {return (!(*this < ccc));}
	private: _MyPtr _PtrEx;
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
		#ifndef _USELESS_OF_COMMON
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		#else
		typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
		#endif
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
				List = new _VeIC[this->size - 1];
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

			_MyT* operator->()
				{ // return this pointer
				return this;
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

			_VeT at(int point)
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

	/*=========================================================

				The Memory Controller Class

		This class provides all the functions on the memory.
		You can redirect all pointers, and provides a number 
		of features for the user's convenience. In addition, 
		the array can be controlled sensitively.

	=========================================================*/

	_CCC_C_TEMPLATE_CS
	template<class _Ty,
			 class _InputT = unsigned,
			 class _Vector = _Ty, 
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
	class _X_Mem_Controller
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Memory<_Ty>
		{
		typedef _X_Mem_Controller<_Ty> _MyT;
		#ifndef _USELESS_OF_COMMON
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		#else
		typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
		#endif
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _Reference _MyUP;
		typedef typename _Pointer _MyPI;

		public:
		typedef typename _X_Memory<_Ty> _XM;

		#define COMMON_INCLASS_USEAGE_FOR _InputT n = 0; n <= arange; n++

		public:
			
			template<class _TyX>
			_TyX& ForceChangeType(_MyPI& _Val)
				{ // get volatile 
				return reinterpret_cast<_TyX&>(_Val);
				}

			_InputT AddressOf(_MyPI& _Val)
				{ // return address of _Val
				return reinterpret_cast<_InputT>(&
					const_cast<_InputT&>
					(ForceChangeType<const volatile _InputT>(_Val)));
				}

			_MyPI ForceArraySet(_MyPI array_, const _InputT set)
				{ // force array value changed
				if(!set)
					return array_;
				array_ = new _MyVT[set];
				return array_;
				}

			_MyPI ForceArraySetWithKeep(const _MyPI array_, 
					const _InputT arange, const _InputT set)
				{ // force array value changed with keep the data
				_MyPI buf = new _MyVT[set];
				for(COMMON_INCLASS_USEAGE_FOR)
					buf[f] = array_[f];
				return buf;
				}

			_MyPI Fill(_MyPI array_, _MyVT value, const _InputT arange)
				{ // fill data by arange to array
				for(COMMON_INCLASS_USEAGE_FOR)
					array_[n] = value;
				return array_;
				}

			_MyPI ZeroMemory(_MyPI array_, const _InputT arange)
				{ // fill zero data by arange to array
				for(COMMON_INCLASS_USEAGE_FOR)
					array_[n] = 0;
				return array_;
				}

			_MyPI Copying(_MyPI oper, const _MyPI array_, const _InputT arange)
				{ // copy datas by arange to array
				for(COMMON_INCLASS_USEAGE_FOR)
					oper[n] = array_[n];
				return oper;
				}

			_MyPI Moving(const _MyPI oper, _MyPI array_, const _InputT arange)
				{ // move data array_ to oper
				for(COMMON_INCLASS_USEAGE_FOR)
					array_[n] = oper[n];
				ZeroMemory(oper, arange);
				return oper;
				}

			_MyPI Swaping(_MyPI oper, _MyPI array_)
				{ // swap from datas to datas
				_MyUP buf1 = *oper;
				_MyUP buf2 = *array_;
				oper = &buf2;
				array_ = &buf1;
				return oper;
				}

			_MyVT SwapVT(_MyVT oper, _MyVT array_)
				{ // swap from data to data
				_MyVT buf = *oper;
				*oper = *array_;
				*array_ = buf;
				return oper;
				}

			_InputT CountItem(_MyPI array_, _MyVT data, const _InputT arange)
				{ // count array item
				_InputT retbuf = 0;
				for(COMMON_INCLASS_USEAGE_FOR)
					if(array_[n] == data)
						retbuf++;
				return retbuf;
				}

			_InputT CountArray(_MyPI array_, _MyVT data, 
					const _InputT first_array_size, const _InputT second_array_size)
				{ // count array items in other array by size
				_InputT retbuf = 0;
				_InputT startat;
				bool state = false;
				for(_InputT n = 0; n <= first_array_size; n++)
					for(_InputT f = 0; f <= second_array_size; f++)
						if(array_[n] == data[f]){
							if(state)startat = array_[n];
								retbuf++;if(retbuf == second_array_size) return startat;}
							else{retbuf = 0;state = false;}
				return 0;
				}

			void ReleaseArray(_MyPI array_, const _InputT array_size)
				{ // release array
				for(_InputT n = 0; n <= array_size; n++)
					delete array_[n];
				delete[] array_;
				}

			void ReleaseArray(_MyPI array_)
				{ // release array
				delete[] array_;
				}

			_MyPI PasteArray(_MyPI array_, _MyVT data, 
					const _InputT first_array_size, const _InputT second_array_size)
				{ // paste two array
				_MyPI buf = new _MyVT[first_array_size + second_array_size];
				_InputT at = 0;
				for(_InputT n = 0; n <= first_array_size; n++, at++)
					buf[n] = array_[n];
				for(_InputT n = 0; n <= second_array_size; n++)
					buf[n + at] = data[n];
				return buf;
				}

			void SetCommonArray(const _MyPI array_, const _InputT size)
				{ // set common array
				CommonArray = new _MyVT[size];
				CommonSize = size;
				Copying(CommonArray, array_, size);
				}

			_MyPI operator>>(const int shift_value)
				{ // create new array which size is basisvalue + shiftvalue
				_MyPI buf = new _MyVT[CommonSize + shift_value];
				for(int n = shift_value; n <= (CommonSize + shift_value); n++)
					buf[n] = CommonArray[n - shift_value];
				return buf;
				}

			_MyPI operator<<(const int shift_value)
				{ // create new array which size is basisvalue - shiftvalue
				if(CommonSize < shift_value)
					throw this*;
				_MyPI buf = new _MyVT[CommonSize - shift_value];
				for(int n = 0; n <= (CommonSize - shift_value); n++)
					buf[n] = CommonArray[n + shift_value];
				return buf;
				}

			_MyPI ReverseArray(_MyPI array_, const _InputT array_size)
				{ // reverse the array
				_MyPI buf = new _MyVT[array_size];
				ZeroMemory(buf, array_size);
				for(_InputT n = 0, f = array_size; n <= array_size; n++, f--)
					buf[n] = array_[f];
				return buf;
				}

			void Sort(_MyPI array_, const _InputT array_size)
				{ // sort array items
				_MyVT hold;
				for(_InputT pass = 1; pass <= (array_size-1); pass++)
				for(_InputT i = 0; i <= (array_size-2); i++)
				if(array_[i] > array_[i + 1])
				{hold = array_[i];
				array_[i] = array_[i + 1];
				array_[i + 1] = hold;}
				}

			_MyPI CreateNewArray(_MyPI array_, const _InputT array_size)
				{ // create new array and put data
				_MyPI buf = new _MyVT[array_size];
				for(_InputT n = 0; n <= array_size; n++)
					buf[n] = array_[n];
				return buf;
				}

			_MyPI CreateNewArrayAndRelease(_MyPI array_, const _InputT array_size)
				{ // create new array and delete input of array
				_MyPI buf = new _MyVT[array_size];
				for(_InputT n = 0; n <= array_size; n++)
					buf[n] = array_[n];
				ReleaseArray(array_, array_size);
				return buf;
				}

			_MyPI CreateMemoryArray(const _InputT array_size)
				{ // create new array
				_MyPI buf = new _MyVT[array_size];
				ZeroMemory(buf, array_size);
				return buf;
				}

			_MyPI RedirectionMemoryC(_MyPI array_, const _InputT array_size, const _InputT redirection_address)
				{ // redirection memory
				_MyPI buf = new _MyVT[array_size];
				_InputT bufc = AddressOf(array_);
				buf = (*_MyVT)&redirection_address;
				buf = (*_MyVT)&array_;
				return buf;
				}

			_InputT GetPointerArraySize(_MyPI array_)
				{ // get array size
				_InputT ccc = sizeof(_MyPI);
				_MyPI buf = CreateMemoryArray(0);
				}

			void* AllocateMemoryBlock(unsigned int Size)
				{ // allocate memory block
				return malloc(Size);
				}
			
			void DeleteMemoryBlock(void** AddressOfBlock)
				{ // delete memoryblock
				if(*AddressOfBlock)
				{free(*AddressOfBlock);
				*AddressOfBlock = 0;}
				}

			void DeleteMemory(void* AddressOfBlcok)
				{ // delete memory
				DeleteMemoryBlock((void**)&AddressOfBlcok);
				}

			bool ArrayFinder(_MyPI array_, _MyPI items ,
					const _InputT first_array_size, const _InputT second_array_size)
				{ // find items in array use of size
				for(_InputT n = 0; n <= first_array_size; n++)
				{for(_InputT f = 0; f <= second_array_size; f++)
				if(array_[n] == items[f]) goto EX;
				else if(f == second_array_size) return false;EX:}
				return true;
				}

			bool MatchArray(_MyPI array_, _MyPI array__, const _InputT arange)
				{ // check match array and array
				for(COMMON_INCLASS_USEAGE_FOR)
					if(array_[n] != array__[n]) return false;
				return true;
				}

			_MyPI ReplaceArray(_MyPI array_, _MyVT e1, _MyVT e2, const _InputT arange)
				{ // replace item to item
				for(COMMON_INCLASS_USEAGE_FOR)
					if(array_[n] == e1) array_[n] = e2;
				return array_;
				}

			_MyPI ChangeVT(_MyPI array_, const _InputT pos1, const _InputT pos2)
				{ // change item to item by position number
				_MyVT buf = *array_[pos1];
				*array_[pos1] = *array_[pos2];
				*array_[pos2] = buf;
				return array_;
				}

		private:

			_MyPI CommonArray;
			unsigned CommonSize;

		};


	_CCC_C_TEMPLATE_CS
	template<class _Ty,
			 class _InputT = unsigned,
			 class _Vector = _Ty, 
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
	class _X_Mem_Controller_Container
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Memory<_Ty>
		{
		typedef _X_Mem_Controller_Container<_Ty> _MyT;
		#ifndef _USELESS_OF_COMMON
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		#else
		typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
		#endif
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _Reference _MyUP;
		typedef typename _Pointer _MyPI;

		public:
		typedef typename _X_Memory<_Ty> _XM;
		typedef typename _X_Mem_Controller<_Ty> _XMC;
		typedef typename _X_Vector_Ex<_Ty> _XV;

			_X_Mem_Controller_Container()
				{
				}

			_X_Mem_Controller_Container(_InputT value)
				{
				ex_mem.resize(value);
				}

			~_X_Mem_Controller_Container()
				{
				ex_mem.release();
				delete memorycontroller;
				}

			_X_Vector_Ex get() const
				{ // return me
				return ex_mem;
				}

			_X_Mem_Controller getmemorycontroller() const
				{
				return memorycontroller;
				}

		private:

			_XV ex_mem;
			_XMC memorycontroller;

	};

	_CCC_C_TEMPLATE_CS
	template<class _Ty, 
			 class _Vector = _Ty, 
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
	class vector
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Memory<_Ty>,
		public _X_Vector_Ty<_Vector, _Ty, _Pointer, _Reference>,
		public _X_Vector_Ex<_Ty>
		{
		typedef _X_Vector_Ex<_Ty, _Vector, _Pointer, _Reference> _MyT;
		#ifndef _USELESS_OF_COMMON
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		#else
		typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
		#endif
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _X_TYPE<_Ty>::UnPointer _MyUP;
		typedef typename _X_TYPE<_Ty>::Pointer _MyPI;

		public:
		typedef typename vector<_Ty, _Vector, _Pointer, _Reference>::Iterator _VeIC;
		//typedef typename _X_Vector_Ty<_Ty, _Vector, _Pointer, _Reference>::Iterator Iterator;
		typedef typename vector<_Ty, _Vector, _Pointer, _Reference>::Value_Type _VeT;
		typedef typename vector<_Ty, _Vector, _Pointer, _Reference>::Pointer _VePI;
		typedef typename vector<_Ty, _Vector, _Pointer, _Reference>::Reference _VeUP;
		typedef typename _X_Memory<_Ty> _XM;
		typedef typename _X_Vector_Ex<_Ty> _MyVeX;
		typedef typename _iterator_vex<_Ty> _Myiter;

		public:



		private:

			_Myiter* firstiter;
			_Myiter* lastiter;

	};

_X_LIB_END

#endif

#endif