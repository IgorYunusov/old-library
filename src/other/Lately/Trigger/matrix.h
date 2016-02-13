/*************************************************************************
 *
 * FILE NAME : graph.h
 *
 * ROLLRAT LIBRARY
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.04.02
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _MATRIX_
#define _MATRIX_
#pragma once

#define THROW_OVERFLOWMAP			1L
#define THROW_OVERRAP				2L

// MATRIX

#define THROW_NOT_MATCHED			3L

template<class u_type = int, typename size_type = size_t>
class Matrix
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

	Matrix(const Matrix<u_type, size_type>& __Matrix)
		: row(__Matrix.row), column(__Matrix.column), _Array(nullptr)
		{
		creatematrix(row, column, __Matrix);
		}

	explicit Matrix(size_type _Row, size_type _Column, 
		const Matrix<u_type, size_type>& __Matrix)
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
		return _Array[_Row - 1][_Column - 1];
		}

	u_type operator()(size_type _Row, size_type _Column) const
		{
		if (_Row > row || _Column > column)
			throw (THROW_OVERFLOWMAP);
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

	void creatematrix(size_type _Row, size_type _Column)
		{
		_Array = new _Matrix*[_Row];
		for (int i = 0; i < _Row; i++)
			_Array[i] = new _Matrix[_Column];
		}

	void creatematrix(size_type _Row, size_type _Column, const Matrix<u_type, size_type>& __Matrix)
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

	};

template<class T>
	Matrix<T>& operator+(
		const Matrix<T>& _Left, const Matrix<T>& _Right)
	{
		if (_Left.row != _Right.row || _Left.column != _Right.column)
			throw(THROW_NOT_MATCHED);
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
			throw(THROW_NOT_MATCHED);
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

#endif