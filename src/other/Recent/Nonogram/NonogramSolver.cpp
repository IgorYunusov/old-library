/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   NonogramSolver.cpp (Nemo Logic)

Purpose:

Author:

   09-18-2015:   HyunJun Jeong, Creation

***/

#include <iostream>

typedef enum class _enum_c_
{
	Blank,
	Filled,
	Doubt
}	NONOGRAM_MARKER;

class NonogramPannel
{
public:

	NonogramPannel(int row, int column)
		: m(row)
		, n(column)
	{
		this->row = new int*[m];
		this->column = new int*[n];
		this->row_max = new int[m];
		this->column_max = new int[n];

		int max_row = row >> 1 + row & 1;
		int max_col = column >> 1 + column & 1;
		this->max_row = max_row;
		this->max_column = max_col;

		for (int i = 0; i < m; i++)
		{
			this->row[i] = new int[max_row];
			for (int j = 0; j < max_row; j++)
			{
				this->row[i][j] = -1;
			}
		}
		for (int i = 0; i < n; i++)
		{
			this->column[i] = new int[max_col];
			for (int j = 0; j < max_row; j++)
			{
				this->column[i][j] = -1;
			}
		}

		this->pannel = new NONOGRAM_MARKER *[m];

		for (int i = 0; i < m; i++)
		{
			this->pannel[i] = new NONOGRAM_MARKER[n];
			for (int j = 0; j < n; j++)
			{
				this->pannel[i][j] = NONOGRAM_MARKER::Doubt;
			}
		}
	}

	void SetRowData(int row, int *vec, int size)
	{
		for (int i = 0; i < size; i++)
			this->row[row][i] = vec[i];
		this->row_max[row] = size << 1 - 1;
	}

	void SetColumnData(int column, int *vec, int size)
	{
		for (int i = 0; i < size; i++)
			this->column[column][i] = vec[i];
		this->column_max[column] = size << 1 - 1;
	}

	NONOGRAM_MARKER& operator()(int i, int j)
	{
		return pannel[i][j];
	}

	void RequestFillMustFilled()
	{
		
	}

private:
	
	int m, n;

	int max_row;
	int max_column;

	int *row_max;
	int *column_max;
	int **row;
	int **column;

	NONOGRAM_MARKER **pannel;
};

class NonogramSolver
{
public:

	NonogramSolver(const NonogramPannel& ns)
		: m_ns(ns)
	{
	}

	bool Solve()
	{

	}

	void FindFitnessBlock()
	{

	}

	void FillRight(int m, int n, int _right)
	{
		for (int i = 0; i < _right; i++)
			m_ns(m + i, n) = NONOGRAM_MARKER::Filled;
	}
	void FillLeft(int m, int n, int _left)
	{
		for (int i = 0; i < _left; i++)
			m_ns(m, n + i) = NONOGRAM_MARKER::Filled;
	}
	void BlankRight(int m, int n, int _right)
	{
		for (int i = 0; i < _right; i++)
			m_ns(m + i, n) = NONOGRAM_MARKER::Blank;
	}
	void BlankLeft(int m, int n, int _left)
	{
		for (int i = 0; i < _left; i++)
			m_ns(m, n + i) = NONOGRAM_MARKER::Blank;
	}

private:

	NonogramPannel m_ns;
};