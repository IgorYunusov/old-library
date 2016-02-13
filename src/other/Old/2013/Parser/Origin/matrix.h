/*
            ROLLRAT MATHEMATICS PROJECT

             Cpy (c) 14. ALL RIGHTS RESERVED.
   */

#ifndef _MATRIX_
#define _MATRIX_
#pragma once

#include <xtgmath.h>

#include "mathematics.h"

#define Link		0
#define Array		1

template<class u_type>
class MatrixRC
	{
public:
	MatrixRC() : 
		_Left(nullptr), _Right(nullptr), _Up(nullptr), _Down(nullptr), _Data(MathZero)
		{
		}

	MatrixRC(u_type _data) : 
		_Left(nullptr), _Right(nullptr), _Up(nullptr), _Down(nullptr), _Data(_data)
		{
		}

	MatrixRC<u_type> *_Left, *_Right, *_Up, *_Down;
	u_type _Data;
	};

template<class u_type = int, int k = Link, typename size_type = unsigned int>
class Matrix
	{
	// Basis Matrix Class
	};

template<class u_type, typename size_type>
class Matrix<u_type, Link, size_type>
	{
public:
	typedef typename MatrixRC<u_type> _Matrix;
	typedef typename MatrixRC<u_type> *_Matrix_Ptr;
	
	size_type row, column;

	_Matrix_Ptr _Head;

	Matrix()
		: row(2), column(2), _Head(nullptr)
		{
		creatematrix(row, column);
		}

	explicit Matrix(size_type _Hand)
		: row(_Hand), column(_Hand), _Head(nullptr)
		{
		creatematrix(row, column);
		}

	explicit Matrix(size_type _Row, size_type _Column)
		: row(_Row), column(_Column), _Head(nullptr)
		{
		creatematrix(row, column);
		}

	explicit Matrix(const Matrix<u_type, Link, size_type>& __Matrix)
		: row(__Matrix.row), column(__Matrix.column), _Head(nullptr)
		{
		creatematrix(row, column, __Matrix);
		}

	explicit Matrix(size_type _Row, size_type _Column, 
		const Matrix<u_type, Link, size_type>& __Matrix)
		: row(row), column(column), _Head(nullptr)
		{
		creatematrix(row, column, __Matrix);
		}

	~Matrix()
		{
		//
		}

	u_type& operator()(size_type _Row, size_type _Column)
		{
		_Matrix_Ptr _Current = _Head;
		if (_Row > row || _Column > column)
			throw (THROW_OVERFLOWMAP);
		for (int _i = 1; _i < _Column; _i++)
			_Current = _Current->_Right;
		for (int _j = 1; _j < _Row; _j++)
			_Current = _Current->_Down;
		return _Current->_Data;
		}

	void fill(u_type _Data)
		{
		_Matrix_Ptr _Current = _Head, _Current_C;
		for (int _i = 0; _i < row; _i++)
			{
			_Current_C = _Current;
			for (int _j = 0; _j < column; _j++)
				{
				_Current_C->_Data = _Data;
				_Current_C = _Current_C->_Right;
				}
			_Current = _Current->_Down;
			}
		}

	template<class _Func>
	void fill(_Func& _func)
		{ // fill for_each function
		_Matrix_Ptr _Current = _Head, _Current_C;
		for (int _i = 0, _k = 0; _i < row; _i++, _k++)
			{
			_Current_C = _Current;
			for (int _j = 0; _j < column; _j++, _k++)
				{
				_Current_C->_Data = _func(_k);
				_Current_C = _Current_C->_Right;
				}
			_Current = _Current->_Down;
			}
		}

	template<class _Func>
	void fill_each(_Func& _func)
		{
		_Matrix_Ptr _Current = _Head, _Current_C;
		for (int _i = 1; _i <= row; _i++)
			{
			_Current_C = _Current;
			for (int _j = 1; _j <= column; _j++)
				{
				_Current_C->_Data = _func(_i, _j);
				_Current_C = _Current_C->_Right;
				}
			_Current = _Current->_Down;
			}
		}

	void new_row(size_type count = 1)
		{
		if (count == 0)
			return;
		_Matrix_Ptr _Current = _Head, _Current_C, _Current_Up;
		for (; _Current->_Down; _Current = _Current->_Down)
			;
		_Current_Up = _Current;
		_Current->_Down = new _Matrix();
		_Current = _Current->_Down;
		_Current->_Up = _Current_Up;
		for (int _i = 2; _i <= column; _i++)
			{
			_Current_Up = _Current_Up->_Right;
			_Current->_Right = new _Matrix();
			_Current->_Right->_Left = _Current;
			_Current = _Current->_Right;
			_Current->_Up = _Current_Up;
			_Current_Up->_Down = _Current;
			}
		row += 1;
		new_row(count - 1);
		}

	void new_column(size_type count = 1)
		{
		if (count == 0)
			return;
		_Matrix_Ptr _Current = _Head, _Current_C, _Current_Left;
		for (; _Current->_Right; _Current = _Current->_Right)
			;
		_Current_Left = _Current;
		_Current->_Right = new _Matrix();
		_Current = _Current->_Right;
		_Current->_Left = _Current_Left;
		for (int _i = 2; _i <= row; _i++)
			{
			_Current_Left = _Current_Left->_Down;
			_Current->_Down = new _Matrix();
			_Current->_Down->_Up = _Current;
			_Current = _Current->_Down;
			_Current->_Left = _Current_Left;
			_Current_Left->_Right = _Current;
			}
		column += 1;
		new_column(count - 1);
		}

	//u_type determinant(_Matrix_Ptr& _Target = _Head, size_type RC = row)
	//	{
	//	// det A = sigma(n, j = 1)( (-1)^(i+j) * a(i, j) * det(S(i, j)) )
	//
	//	if(RC - row == 2)
	//		{
	//		// det T = 1/(ad - bc)
	//		return 1 / ((_Target->_Data) * (_Target->_Right->_Data) 
	//			+ (-((_Target->_Down->_Data) * (_Target->_Down->_Right->_Data))));
	//		}
	//	u_type summation;
	//	for(int i = 0; i < RC; i++)
	//		{
	//		
	//		}
	//	return summation;
	//	}
	//
	//void inverse(Matrix<u_type, size_type>& _Save)
	//	{
	//	if (_Save.row != row || _Save.column != column)
	//		throw (THROW_NOT_MATCHED);
	//	Matrix<u_type, size_type> _Tmp(*this);
	//	u_type pivot;
	//	_Save.fill(0);
	//	for (int k = 1; k <= row; k++)
	//		_Save(k, k) = 1;
	//	for(int i = 1; i <= row; i++)
	//		{
	//		pivot = _Tmp(i, i);
	//		for (int j = i; j <= column; j++)
	//			{
	//			u_type _Tmpx = _Tmp(i, j) / pivot;
	//			_Tmp(i, j) = _Tmpx;
	//			_Save(i, j) = _Tmpx;
	//			}
	//		for(int k = 1; k <= row; k++)
	//			{
	//			if(k != i)
	//				{
	//				pivot = _Tmp(k, i);
	//				for (int j = k; j <= column; j++)
	//					{
	//					u_type _Tmpx = _Tmp(k, j) - pivot * _Tmp(i, j);
	//					_Tmp(k, j) = _Tmpx;
	//					_Save(k, j) = _Tmpx;
	//					}
	//				}
	//			}
	//		}
	//	}

	void gaussjordan()
		{ // ~A = [A:I] -> [I:A^(-1)]
		u_type pivot;
		for(int i = 1; i <= row; i++)
			{
			pivot = operator()(i, i);
			for (int j = i; j <= column; j++)
				operator()(i, j) = operator()(i, j) / pivot;
			for(int k = 1; k <= row; k++)
				{
				if(k != i)
					{
					pivot = operator()(k, i);
					for (int j = k; j <= column; j++)
						operator()(k, j) = operator()(k, j) - pivot * operator()(i, j);
					}
				}
			}
		}

private:

	_Matrix_Ptr& get(size_type _Row, size_type _Column)
		{
		_Matrix_Ptr _Current = _Head;
		if (_Row > row || _Column > column)
			throw (THROW_OVERFLOWMAP);
		for (int _i = 1; _i < _Row; _i++)
			_Current = _Current->_Right;
		for (int _j = 1; _j < _Column; _j++)
			_Current = _Current->_Down;
		return _Current;
		}

	void creatematrix(size_type _Row, size_type _Column)
		{
		_Matrix_Ptr _Current, _Current_C;
		_Current = new _Matrix();
		_Head = _Current;
		for(int _i = 0; _i < _Row; _i++)
			{
			_Current_C = _Current;
			for(int _j = 1; _j < _Column; _j++)
				{
				_Matrix_Ptr _T = new _Matrix();
				_Current_C->_Right = _T;
				_T->_Left = _Current_C;
				_Current_C = _Current_C->_Right;
				}
			if (_i == _Column - 1)
				break;
			_Current->_Down = new _Matrix();
			_Current = _Current->_Down;
			}
		if( (_Row > 1) && (_Column > 1) )
			{
			_Current = _Head;
			_Matrix_Ptr _Up_Ptr, _Down_Ptr;
			for(int _j = 0; _j < (_Row - 1); _j++)
				{
				_Up_Ptr = _Current;
				_Down_Ptr = _Current->_Down;
				for(int _i = 0; _i < _Column; _i++)
					{
					_Up_Ptr->_Down = _Down_Ptr;
					_Down_Ptr->_Up = _Up_Ptr;
					_Up_Ptr = _Up_Ptr->_Right;
					_Down_Ptr = _Down_Ptr->_Right;
					}
				_Current = _Current->_Down;
				}
			}
		}

	void creatematrix(size_type _Row, size_type _Column, const Matrix<u_type, Link, size_type>& __Matrix)
		{
		_Matrix_Ptr _Current, _Current_C, _TCurrent = __Matrix._Head, _TCurrent_C;
		_Current = new _Matrix();
		_Head = _Current;
		for(int _i = 0; _i < _Row; _i++)
			{
			_Current_C = _Current;
			_TCurrent_C = _TCurrent;
			for(int _j = 1; _j < _Column; _j++)
				{
				_Matrix_Ptr _T = new _Matrix();
				_Current_C->_Right = _T;
				_T->_Left = _Current_C;
				_Current->_Data = _TCurrent_C->_Data;
				_Current_C = _Current_C->_Right;
				_TCurrent_C = _TCurrent_C->_Right;
				}
			if (_i == _Column - 1)
				break;
			_Current->_Down = new _Matrix();
			_TCurrent = _TCurrent->_Down;
			_Current = _Current->_Down;
			}
		if( (_Row > 1) && (_Column > 1) )
			{
			_Current = _Head;
			_Matrix_Ptr _Up_Ptr, _Down_Ptr;
			for(int _j = 0; _j < (_Row - 1); _j++)
				{
				_Up_Ptr = _Current;
				_Down_Ptr = _Current->_Down;
				for(int _i = 0; _i < _Column; _i++)
					{
					_Up_Ptr->_Down = _Down_Ptr;
					_Down_Ptr->_Up = _Up_Ptr;
					_Up_Ptr = _Up_Ptr->_Right;
					_Down_Ptr = _Down_Ptr->_Right;
					}
				_Current = _Current->_Down;
				}
			}
		}

	};

template<class T>
	Matrix<T>& operator+(
		const Matrix<T>& _Left, const Matrix<T>& _Right)
	{
		if (_Left.row != _Right.row || _Left.column != _Right.column)
			throw(THROW_NOT_MATCHED);
		Matrix<T> _Local(_Left.row, _Left.column);
		MatrixRC<T> *_Left_Ptr = _Left._Head, *_Right_Ptr = _Right._Head, *_Local_Ptr = _Local._Head,
			*_Left_Temp, *_Right_Temp, *_Local_Temp;
		for(int i = 1; i <= _Left.row; i++)
		{
			_Left_Temp = _Left_Ptr;
			_Right_Temp = _Right_Ptr;
			_Local_Temp = _Local_Ptr;
			for(int j = 1; j <= _Left.column; j++)
			{
				_Local_Temp->_Data = (_Left_Temp->_Data) + (_Right_Temp->_Data);
				_Left_Temp = _Left_Temp->_Right;
				_Right_Temp = _Right_Temp->_Right;
				_Local_Temp = _Local_Temp->_Right;
			}
			_Left_Ptr = _Left_Ptr->_Down;
			_Right_Ptr = _Right_Ptr->_Down;
			_Local_Ptr = _Local_Ptr->_Down;
		}
		return _Local;
	}

template<class T>
	Matrix<T>& operator+(
		const Matrix<T>& _Left, const T _Right)
	{
		Matrix<T> _Local(_Left.row, _Left.column);
		MatrixRC<T> *_Left_Ptr = _Left._Head, *_Local_Ptr = _Local._Head,
			*_Left_Temp, *_Local_Temp;
		for(int i = 1; i <= _Left.row; i++)
		{
			_Left_Temp = _Left_Ptr;
			_Local_Temp = _Local_Ptr;
			for(int j = 1; j <= _Left.column; j++)
			{
				_Local_Temp->_Data = (_Left_Temp->_Data) + (_Right);
				_Left_Temp = _Left_Temp->_Right;
				_Local_Temp = _Local_Temp->_Right;
			}
			_Left_Ptr = _Left_Ptr->_Down;
			_Local_Ptr = _Local_Ptr->_Down;
		}
		return _Local;
	}

template<class T>
	Matrix<T>& operator+(
		const T _Left, const Matrix<T>& _Right)
	{
		Matrix<T> _Local(_Right.row, _Right.column);
		MatrixRC<T> *_Right_Ptr = _Right._Head, *_Local_Ptr = _Local._Head,
			*_Right_Temp, *_Local_Temp;
		for(int i = 1; i <= _Right.row; i++)
		{
			_Right_Temp = _Right_Ptr;
			_Local_Temp = _Local_Ptr;
			for(int j = 1; j <= _Left.column; j++)
			{
				_Local_Temp->_Data = (_Left) + (_Right_Temp->_Data);
				_Right_Temp = _Right_Temp->_Right;
				_Local_Temp = _Local_Temp->_Right;
			}
			_Right_Ptr = _Right_Ptr->_Down;
			_Local_Ptr = _Local_Ptr->_Down;
		}
		return _Local;
	}

template<class T>
	Matrix<T>& operator-(
		const Matrix<T>& _Left, const Matrix<T>& _Right)
	{
		if (_Left.row != _Right.row || _Left.column != _Right.column)
			throw(THROW_NOT_MATCHED);
		Matrix<T> _Local(_Left.row, _Left.column);
		MatrixRC<T> *_Left_Ptr = _Left._Head, *_Right_Ptr = _Right._Head, *_Local_Ptr = _Local._Head,
			*_Left_Temp, *_Right_Temp, *_Local_Temp;
		for(int i = 1; i <= _Left.row; i++)
		{
			_Left_Temp = _Left_Ptr;
			_Right_Temp = _Right_Ptr;
			_Local_Temp = _Local_Ptr;
			for(int j = 1; j <= _Left.column; j++)
			{
				_Local_Temp->_Data = (_Left_Temp->_Data) + (-(_Right_Temp->_Data));
				_Left_Temp = _Left_Temp->_Right;
				_Right_Temp = _Right_Temp->_Right;
				_Local_Temp = _Local_Temp->_Right;
			}
			_Left_Ptr = _Left_Ptr->_Down;
			_Right_Ptr = _Right_Ptr->_Down;
			_Local_Ptr = _Local_Ptr->_Down;
		}
		return _Local;
	}

template<class T>
	Matrix<T>& operator-(
		const Matrix<T>& _Left, const T _Right)
	{
		Matrix<T> _Local(_Left.row, _Left.column);
		MatrixRC<T> *_Left_Ptr = _Left._Head, *_Local_Ptr = _Local._Head,
			*_Left_Temp, *_Local_Temp;
		for(int i = 1; i <= _Left.row; i++)
		{
			_Left_Temp = _Left_Ptr;
			_Local_Temp = _Local_Ptr;
			for(int j = 1; j <= _Left.column; j++)
			{
				_Local_Temp->_Data = (_Left_Temp->_Data) + (-_Right);
				_Left_Temp = _Left_Temp->_Right;
				_Local_Temp = _Local_Temp->_Right;
			}
			_Left_Ptr = _Left_Ptr->_Down;
			_Local_Ptr = _Local_Ptr->_Down;
		}
		return _Local;
	}

template<class T>
	Matrix<T>& operator-(
		const T _Left, const Matrix<T>& _Right)
	{
		Matrix<T> _Local(_Right.row, _Right.column);
		MatrixRC<T> *_Right_Ptr = _Right._Head, *_Local_Ptr = _Local._Head,
			*_Right_Temp, *_Local_Temp;
		for(int i = 1; i <= _Right.row; i++)
		{
			_Right_Temp = _Right_Ptr;
			_Local_Temp = _Local_Ptr;
			for(int j = 1; j <= _Left.column; j++)
			{
				_Local_Temp->_Data = (_Left) + (-(_Right_Temp->_Data));
				_Right_Temp = _Right_Temp->_Right;
				_Local_Temp = _Local_Temp->_Right;
			}
			_Right_Ptr = _Right_Ptr->_Down;
			_Local_Ptr = _Local_Ptr->_Down;
		}
		return _Local;
	}

template<class T>
	Matrix<T>& operator*(
		const Matrix<T>& _Left, const Matrix<T>& _Right)
	{
		if (_Left.column != _Right.row)
			throw(THROW_NOT_MATCHED);
		Matrix<T> _Local(_Left.row, _Right.column);
		MatrixRC<T> *_Left_Ptr = _Left._Head, *_Right_Ptr = _Right._Head, *_Local_Ptr = _Local._Head,
			*_Left_Temp, *_Right_Temp = _Right_Ptr, *_Local_Temp, *_Right_Ptr_C;
		for(int i = 1; i <= _Left.row; i++)
		{
			_Local_Temp = _Local_Ptr;
			for(int j = 1; j <= _Right.column; j++)
			{
				T Summation = 0;
				_Right_Ptr_C = _Right_Temp;
				_Left_Temp = _Left_Ptr;
				for(int _I = 1; _I <= _Right.row; _I++)
				{
					Summation += (_Left_Temp->_Data) * (_Right_Ptr_C->_Data);
					_Left_Temp = _Left_Temp->_Right;
					_Right_Ptr_C = _Right_Ptr_C->_Down;
				}
				_Right_Temp = _Right_Temp->_Right;
				_Local_Temp->_Data = Summation;
				_Local_Temp = _Local_Temp->_Right;
			}
			_Right_Temp = _Right_Ptr;
			_Left_Ptr = _Left_Ptr->_Down;
			_Local_Ptr = _Local_Ptr->_Down;
		}
		return _Local;
	}

template<class T>
	Matrix<T>& operator*(
		const Matrix<T>& _Left, const T _Right)
	{
		Matrix<T> _Local(_Left.row, _Left.column);
		MatrixRC<T> *_Left_Ptr = _Left._Head, *_Local_Ptr = _Local._Head,
			*_Left_Temp, *_Local_Temp;
		for(int i = 1; i <= _Left.row; i++)
		{
			_Left_Temp = _Left_Ptr;
			_Local_Temp = _Local_Ptr;
			for(int j = 1; j <= _Left.column; j++)
			{
				_Local_Temp->_Data = (_Right) * (_Left_Temp->_Data);
				_Left_Temp = _Left_Temp->_Right;
				_Local_Temp = _Local_Temp->_Right;
			}
			_Left_Ptr = _Left_Ptr->_Down;
			_Local_Ptr = _Local_Ptr->_Down;
		}
		return _Local;
	}

template<class T>
	Matrix<T>& operator*(
		const T _Left, const Matrix<T>& _Right)
	{
		Matrix<T> _Local(_Right.row, _Right.column);
		MatrixRC<T> *_Right_Ptr = _Right._Head, *_Local_Ptr = _Local._Head,
			*_Right_Temp, *_Local_Temp;
		for(int i = 1; i <= _Right.row; i++)
		{
			_Right_Temp = _Right_Ptr;
			_Local_Temp = _Local_Ptr;
			for(int j = 1; j <= _Right.column; j++)
			{
				_Local_Temp->_Data = (_Left) * (_Right_Temp->_Data);
				_Right_Temp = _Right_Temp->_Right;
				_Local_Temp = _Local_Temp->_Right;
			}
			_Right_Ptr = _Right_Ptr->_Down;
			_Local_Ptr = _Local_Ptr->_Down;
		}
		return _Local;
	}

template<class u_type, typename size_type>
class Matrix<u_type, Array, size_type>
	{
public:
	typedef typename u_type _Matrix;
	
	size_type row, column;

	// Access Method : _Array[Row][Column]
	_Matrix **_Array;

	Matrix()
		: row(2), column(2), _Array(nullptr)
		{
		creatematrix(row, column);
		}

	explicit Matrix(size_type _Hand)
		: row(_Hand), column(_Hand), _Array(nullptr)
		{
		creatematrix(row, column);
		}

	explicit Matrix(size_type _Row, size_type _Column)
		: row(_Row), column(_Column), _Array(nullptr)
		{
		creatematrix(row, column);
		}

	explicit Matrix(const Matrix<u_type, Link, size_type>& __Matrix)
		: row(__Matrix.row), column(__Matrix.column), _Array(nullptr)
		{
		creatematrix(row, column, __Matrix);
		}

	explicit Matrix(size_type _Row, size_type _Column, 
		const Matrix<u_type, Link, size_type>& __Matrix)
		: row(row), column(column), _Array(nullptr)
		{
		creatematrix(row, column, __Matrix);
		}

	explicit Matrix(const Matrix<u_type, Array, size_type>& __Matrix)
		: row(__Matrix.row), column(__Matrix.column), _Array(nullptr)
		{
		creatematrix(row, column, __Matrix);
		}

	explicit Matrix(size_type _Row, size_type _Column, 
		const Matrix<u_type, Array, size_type>& __Matrix)
		: row(row), column(column), _Array(nullptr)
		{
		creatematrix(row, column, __Matrix);
		}

	~Matrix()
		{
		//
		}

	u_type& operator()(size_type _Row, size_type _Column)
		{
		if (_Row > row || _Column > column)
			throw (THROW_OVERFLOWMAP);
		return _Array[_Row - 1][ _Column - 1];
		}

	void fill(u_type _Data)
		{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				_Array[i, j] = _Data;
		}

	template<class _Func>
	void fill(_Func& _func)
		{ // fill for_each function
		for (int i = 0, k = 0; i < row; i++, k++)
			for (int j = 0; j < column; j++, k++)
				_Array[i, j] = _func(k);
		}

	template<class _Func>
	void fill_each(_Func& _func)
		{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column; j++)
				_Array[i, j] = _func(i, j);
		}

	void new_row(size_type count = 1)
		{
		if (count == 0)
			return;
		row += 1;
		_Matrix **_Tmp = new _Matrix*[row];
		for (int i = 0; i < row; i++)
			_Tmp[i] = new _Matrix[column];
		for (int i = 0; i < row - 1; i++)
			for (int j = 0; j < column; j++)
				_Tmp[i, j] = _Array[i, j];
		new_row(count - 1);
		}

	void new_column(size_type count = 1)
		{
		if (count == 0)
			return;
		column += 1;
		_Matrix **_Tmp = new _Matrix*[row];
		for (int i = 0; i < row; i++)
			_Tmp[i] = new _Matrix[column];
		for (int i = 0; i < row; i++)
			for (int j = 0; j < column - 1; j++)
				_Tmp[i, j] = _Array[i, j];
		new_column(count - 1);
		}

private:
	typedef typename MatrixRC<u_type> *_Matrix_Ptr;

	void creatematrix(size_type _Row, size_type _Column)
		{
		_Array = new _Matrix*[_Row];
		for (int i = 0; i < _Row; i++)
			_Array[i] = new _Matrix[_Column];
		}

	void creatematrix(size_type _Row, size_type _Column, const Matrix<u_type, Link, size_type>& __Matrix)
		{
		_Matrix_Ptr _TCurrent = __Matrix._Head, _TCurrent_C;
		_Array = new _Matrix*[_Row];
		for (int i = 0; i < _Row; i++)
			_Array[i] = new _Matrix[_Column];
		for(int _i = 0; _i < _Row; _i++)
			{
			_TCurrent_C = _TCurrent;
			for(int _j = 0; _j < _Column; _j++)
				{
				_Array[_i, _j] = _TCurrent_C->_Data;
				_TCurrent_C = _TCurrent_C->_Right;
				}
			if (_i == _Column - 1)
				break;
			_TCurrent = _TCurrent->_Down;
			}
		*this->_Array = _Array;
		}

	void creatematrix(size_type _Row, size_type _Column, const Matrix<u_type, Array, size_type>& __Matrix)
		{
		_Matrix_Ptr _TCurrent = __Matrix._Head, _TCurrent_C;
		_Array = new _Matrix*[_Row];
		for (int i = 0; i < _Row; i++)
			_Array[i] = new _Matrix[_Column];
		for(int _i = 0; _i < _Row; _i++)
			{
			for(int _j = 0; _j < _Column; _j++)
				{
				_Array[_i, _j] = __Matrix._Array[_i, _j];
				}
			if (_i == _Column - 1)
				break;
			}
		}

	};

template<class T>
	Matrix<T, Array>& operator+(
		const Matrix<T, Array>& _Left, const Matrix<T, Array>& _Right)
	{
		if (_Left.row != _Right.row || _Left.column != _Right.column)
			throw(THROW_NOT_MATCHED);
		Matrix<T, Array> _Tmp(_Left.row, _Left.column);
		for (int i = 1; i <= _Left.row; i++)
			for (int j = 1; j <= _Left.column; j++)
				_Tmp(i, j) = _Left(i, j) + _Right(i, j);
		return _Tmp;
	}

template<class T>
	Matrix<T, Array>& operator+(
		const Matrix<T, Array>& _Left, const T _Right)
	{
		Matrix<T, Array> _Tmp(_Left.row, _Left.column);
		for (int i = 1; i <= _Left.row; i++)
			for (int j = 1; j <= _Left.column; j++)
				_Tmp(i, j) = _Left(i, j) + _Right;
		return _Tmp;
	}

template<class T>
	Matrix<T, Array>& operator+(
		const T _Left, const Matrix<T, Array>& _Right)
	{
		Matrix<T, Array> _Tmp(_Left.row, _Left.column);
		for (int i = 1; i <= _Right.row; i++)
			for (int j = 1; j <= _Right.column; j++)
				_Tmp(i, j) = _Right(i, j) + _Left;
		return _Tmp;
	}

template<class T>
	Matrix<T>& operator-(
		const Matrix<T, Array>& _Left, const Matrix<T, Array>& _Right)
	{
		if (_Left.row != _Right.row || _Left.column != _Right.column)
			throw(THROW_NOT_MATCHED);
		Matrix<T, Array> _Tmp(_Left.row, _Left.column);
		for (int i = 1; i <= _Left.row; i++)
			for (int j = 1; j <= _Left.column; j++)
				_Tmp(i, j) = _Left(i, j) + (-_Right(i, j));
		return _Tmp;
	}

template<class T>
	Matrix<T, Array>& operator-(
		const Matrix<T, Array>& _Left, const T _Right)
	{
		Matrix<T, Array> _Tmp(_Left.row, _Left.column);
		for (int i = 1; i <= _Left.row; i++)
			for (int j = 1; j <= _Left.column; j++)
				_Tmp(i, j) = _Left(i, j) + (-_Right);
		return _Tmp;
	}

template<class T>
	Matrix<T, Array>& operator-(
		const T _Left, const Matrix<T, Array>& _Right)
	{
		Matrix<T, Array> _Tmp(_Left.row, _Left.column);
		for (int i = 1; i <= _Right.row; i++)
			for (int j = 1; j <= _Right.column; j++)
				_Tmp(i, j) = (-_Right(i, j)) + _Left;
		return _Tmp;
	}

template<class T>
	Matrix<T, Array>& operator*(
		const Matrix<T, Array>& _Left, const Matrix<T, Array>& _Right)
	{
		if (_Left.column != _Right.row)
			throw(THROW_NOT_MATCHED);
		Matrix<T, Array> _Tmp(_Left.row, _Right.column);
		for(int i = 1; i <= _Left.row; i++)
			for(int j = 1; j <= _Right.column; j++)
			{
				T Summation = 0;
				for(int k = 1; k <= _Right.row; j++)
					Summation += _Left(i, k) * _Right(k, j);
				_Tmp(i, j) = Summation;
			}
		return _Tmp;
	}

template<class T>
	Matrix<T, Array>& operator*(
		const Matrix<T, Array>& _Left, const T _Right)
	{
		Matrix<T, Array> _Tmp(_Left.row, _Left.column);
		for(int i = 1; i <= _Left.row; i++)
			for (int j = 1; j <= _Left.column; j++)
				_Tmp(i, j) = _Left(i, j) * _Right;
		return _Tmp;
	}

template<class T>
	Matrix<T, Array>& operator*(
		const T _Left, const Matrix<T, Array>& _Right)
	{
		Matrix<T, Array> _Tmp(_Right.row, _Right.column);
		for(int i = 1; i <= _Right.row; i++)
			for (int j = 1; j <= _Right.column; j++)
				_Tmp(i, j) = _Right(i, j) * _Left;
		return _Tmp;
	}

#endif