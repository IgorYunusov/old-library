/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Matrix.h

Purpose:

   RollRat Library

Author:

   10-11-2015:   HyunJun Jeong, Creation

***/

#ifndef _MATRIX_9bf1541fdf7efd41b7b39543fd870ac4_
#define _MATRIX_9bf1541fdf7efd41b7b39543fd870ac4_

#define radian 0.01745329251994329576923690768489 // 57.295779513082320876798154814105

#define __STDC_IEC_559__ 
#define _USE_MATH_DEFINES

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <math.h>
#include <xtgmath.h>
#include <stdint.h>

#define DETERMINANT_ERROR	(10e-10)

namespace Utility {

	template<class u_type>
	class Matrix
		{
	public:
		typedef typename u_type _Matrix;

		size_t row, column;

		// Access Method : _Array[Row][Column]
		_Matrix **_Array;

		Matrix()
			: row(2), column(2), _Array(nullptr)
			{
			creatematrix(row, column);
			}

		explicit Matrix(size_t _Hand)
			: row(_Hand), column(_Hand), _Array(nullptr)
			{
			creatematrix(row, column);
			}

		explicit Matrix(size_t _Row, size_t _Column)
			: row(_Row), column(_Column), _Array(nullptr)
			{
			creatematrix(row, column);
			}

		Matrix(const Matrix& __Matrix)
			: row(__Matrix.row), column(__Matrix.column), _Array(nullptr)
			{
			creatematrix(row, column, __Matrix);
			}

		explicit Matrix(size_t _Row, size_t _Column, 
			const Matrix& __Matrix)
			: row(row), column(column), _Array(nullptr)
			{
			creatematrix(row, column, __Matrix);
			}

		~Matrix()
			{
			}

		u_type& operator()(size_t _Row, size_t _Column)
			{
			if (_Row > row || _Column > column)
				throw (2); // THROW_OVERFLOWMAP
			return _Array[_Row - 1][_Column - 1];
			}

		u_type operator()(size_t _Row, size_t _Column) const
			{
			if (_Row > row || _Column > column)
				throw (2);
			return _Array[_Row - 1][_Column - 1];
			}

		void fill(u_type _Data)
			{
			for (int i = 0; i < row; i++)
				for (int j = 0; j < column; j++)
					_Array[i][j] = _Data;
			}

		template<class _Func>
		void fill(_Func& _func)
			{ // fill for_each function
			for (int i = 0, k = 0; i < row; i++, k++)
				for (int j = 0; j < column; j++, k++)
					_Array[i][j] = _func(k);
			}

		template<class _Func>
		void fill_each(_Func& _func)
			{
			for (int i = 0; i < row; i++)
				for (int j = 0; j < column; j++)
					_Array[i][j] = _func(i, j);
			}

		void new_row(size_t count = 1)
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

		void new_column(size_t count = 1)
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

		double determinant()
			{
			double det = 1.0f, a, b;
			size_t r, c, k, w, z;
			Matrix tpm = *new Matrix(*this);
			for (r = 0; r < row; r++)
				{
				if (-DETERMINANT_ERROR < tpm._Array[r][r]
					&& tpm._Array[r][r] < -DETERMINANT_ERROR)
					{
					for (k = 0; k < row; k++)
						{
						if (-DETERMINANT_ERROR < tpm._Array[k][r]
							&& tpm._Array[k][r] < DETERMINANT_ERROR)
							continue;
						for (c = 0; c < column; c++)
							tpm._Array[r][c] += tpm._Array[k][c];
						break;
						}
					}
				}
			for (r = 0; r < row; r++)
				{
				w = tpm._Array[r][r];
				for (k = r + 1; k < row; k++)
					{
					if (tpm._Array[k][r] == 0)
						continue;
					z = tpm._Array[k][r];
					for (c = 0; c < column; c++)
						tpm._Array[k][c] -= tpm._Array[r][c] / w * z;
					}
				}
			for (r = 0; r < row; r++)
				{
				det *= tpm._Array[r][r];
				}
			return det;
			}

		Matrix& transpose()
			{
			Matrix pm = *new Matrix(row, column);
			size_t r, c;
			for (r = 0; r < row; r++)
				{
				for (c = 0; c < column; c++)
					{
					pm._Array[c][r] = _Array[r][c];
					}
				}
			return pm;
			}

		Matrix& Inverse()
			{
			size_t r, c, k, cross;
			Matrix tpm = *new Matrix(*this);
			Matrix pm = createunit(row);
			for (r = 0; r < row; r++) 
				{
				if (-DETERMINANT_ERROR < tpm._Array[r][r]
					&& tpm._Array[r][r] < -DETERMINANT_ERROR)
					{
					for (k = 0; k < row; k++)
						{
						if (-DETERMINANT_ERROR < tpm._Array[k][r]
							&& tpm._Array[k][r] < DETERMINANT_ERROR)
							continue;
						for (c = 0; c < column; c++)
							{
							tpm._Array[r][c] += tpm._Array[k][c];
							pm._Array[r][c] += pm._Array[k][c];
							}
						break;
						}
					if (-DETERMINANT_ERROR < tpm._Array[r][r]
						&& tpm._Array[r][r] < -DETERMINANT_ERROR)
						return nullptr;
					}
				}
			for (r = 0; r < row; r++)
				{
				cross = tpm._Array[r][r];
				for (c = 0; c < column; c++)
					{
					tpm._Array[r][c] /= cross;
					tpm._Array[r][c] /= cross;
					}
				for (k = 0; k < row; k++)
					{
					if (k == r)
						continue;
					if (tpm._Array[k][r] == 0.0f)
						continue;
					cross = tpm._Array[k][r];
					for (c = 0; c < column; c++)
						{
						tpm._Array[k][c] -= tpm._Array[r][c] * cross;
						pm._Array[k][c] -= pm._Array[r][c] * cross;
						}
					}
				}
			return pm;
			}

	private:

		void creatematrix(size_t _Row, size_t _Column)
			{
			_Array = new _Matrix*[_Row];
			for (int i = 0; i < _Row; i++)
				_Array[i] = new _Matrix[_Column];
			}

		void creatematrix(size_t _Row, size_t _Column, const Matrix& __Matrix)
			{
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

		Matrix& createunit(size_t unit_size)
			{
			Matrix pm = *new Matrix(unit_size);
			size_t r, c;
			for (r = 0; r < unit_size; r++)
				{
				for (c = 0; c < unit_size; c++)
					{
					r[pm._Array][c] = r == c ? 1 : 0;
					}
				}
			return pm;
			}

		};

	template<class T>
		Matrix<T>& operator+(
			const Matrix<T>& _Left, const Matrix<T>& _Right)
		{
			if (_Left.row != _Right.row || _Left.column != _Right.column)
				throw(1); // THROW_NOT_MATCHED
			Matrix<T> _Tmp(_Left.row, _Left.column);
			for (int i = 1; i <= _Left.row; i++)
				for (int j = 1; j <= _Left.column; j++)
					_Tmp(i, j) = _Left(i, j) + _Right(i, j);
			return _Tmp;
		}
	
	template<class T>
		Matrix<T>& operator+(
			const Matrix<T>& _Left, const T _Right)
		{
			Matrix<T> _Tmp(_Left.row, _Left.column);
			for (int i = 1; i <= _Left.row; i++)
				for (int j = 1; j <= _Left.column; j++)
					_Tmp(i, j) = _Left(i, j) + _Right;
			return _Tmp;
		}
	
	template<class T>
		Matrix<T>& operator+(
			const T _Left, const Matrix<T>& _Right)
		{
			Matrix<T> _Tmp(_Left.row, _Left.column);
			for (int i = 1; i <= _Right.row; i++)
				for (int j = 1; j <= _Right.column; j++)
					_Tmp(i, j) = _Right(i, j) + _Left;
			return _Tmp;
		}
	
	template<class T>
		Matrix<T>& operator-(
			const Matrix<T>& _Left, const Matrix<T>& _Right)
		{
			if (_Left.row != _Right.row || _Left.column != _Right.column)
				throw(1);
			Matrix<T> _Tmp(_Left.row, _Left.column);
			for (int i = 1; i <= _Left.row; i++)
				for (int j = 1; j <= _Left.column; j++)
					_Tmp(i, j) = _Left(i, j) + (-_Right(i, j));
			return _Tmp;
		}
	
	template<class T>
		Matrix<T>& operator-(
			const Matrix<T>& _Left, const T _Right)
		{
			Matrix<T> _Tmp(_Left.row, _Left.column);
			for (int i = 1; i <= _Left.row; i++)
				for (int j = 1; j <= _Left.column; j++)
					_Tmp(i, j) = _Left(i, j) + (-_Right);
			return _Tmp;
		}
	
	template<class T>
		Matrix<T>& operator-(
			const T _Left, const Matrix<T>& _Right)
		{
			Matrix<T> _Tmp(_Left.row, _Left.column);
			for (int i = 1; i <= _Right.row; i++)
				for (int j = 1; j <= _Right.column; j++)
					_Tmp(i, j) = (-_Right(i, j)) + _Left;
			return _Tmp;
		}
	
	template<class T>
		Matrix<T>& operator*(
			const Matrix<T>& _Left, const Matrix<T>& _Right)
		{
			if (_Left.column != _Right.row)
				throw(THROW_NOT_MATCHED);
			Matrix<T> _Tmp(_Left.row, _Right.column);
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
		Matrix<T>& operator*(
			const Matrix<T>& _Left, const T _Right)
		{
			Matrix<T> _Tmp(_Left.row, _Left.column);
			for(int i = 1; i <= _Left.row; i++)
				for (int j = 1; j <= _Left.column; j++)
					_Tmp(i, j) = _Left(i, j) * _Right;
			return _Tmp;
		}
	
	template<class T>
		Matrix<T>& operator*(
			const T _Left, const Matrix<T>& _Right)
		{
			Matrix<T> _Tmp(_Right.row, _Right.column);
			for(int i = 1; i <= _Right.row; i++)
				for (int j = 1; j <= _Right.column; j++)
					_Tmp(i, j) = _Right(i, j) * _Left;
			return _Tmp;
		}

}

#endif