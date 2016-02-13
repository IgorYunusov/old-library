/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   SudokuSolver.cpp

Purpose:

Author:

   08-30-2015:   HyunJun Jeong, Creation

***/

#include <iostream>
#include "popcnt_info.h"
#include "NonOverlappedRandomNumberGenerator.h"

class SudokuPannel
{
public:

	SudokuPannel()
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				m_pannel[i][j] = 0;
		setlamp();
	}

	SudokuPannel(const char *m_str)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				m_pannel[i][j] = m_str[i*9+j] - '0';
		setlamp();
	}
	
	SudokuPannel(const char **m_str)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				m_pannel[i][j] = m_str[i][j] - '0';
		setlamp();
	}

	SudokuPannel(const SudokuPannel& sp)
	{
		clone(sp);
		setlamp();
	}

	void setlamp()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				int tx = (i / 3) * 3 + j / 3;
				int ty = (i % 3) * 3 + j % 3;
				m_lamp[tx][ty] = &m_pannel[i][j];
			}
		}
	}

	int getlamp(int i, int j)
	{
		return *m_lamp[i][j];
	}

	void clone(const SudokuPannel& sp)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				m_pannel[i][j] = sp.m_pannel[i][j];
	}

	int& operator()(int i, int j)
	{
		return m_pannel[i][j];
	}

	bool equal(const SudokuPannel& sp)
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (m_pannel[i][j] != sp.m_pannel[i][j])
					return false;
		return true;
	}

	void zeroset()
	{
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				m_pannel[i][j] = 0;
	}

private:

	int* m_lamp[9][9];
	int m_pannel[9][9];
};

class SudokuSolver
{
public:

	SudokuSolver(const SudokuPannel& sp)
		: m_sp(sp)
	{
	}

	bool Solve()
	{
		int max = 9;
		int g_x = 9, g_y = 9;
		unsigned long g_b;
		bool force_exit = false;
		
		//
		//	백 트래킹 알고리즘
		//
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (m_sp(i, j))
					continue;

				int k_c = 0;
				unsigned long k_b = 0;

				int t = (i / 3) * 3 + j / 3;

				//
				//	느슨한 꼬리 생성
				//
				for (int k = 0; k < 9; k++)
				{
					if (m_sp(i, k))
						k_b |= 1 << m_sp(i, k);
					if (m_sp(k, j))
						k_b |= 1 << m_sp(k, j);
					if (m_sp.getlamp(t, k))
						k_b |= 1 << m_sp.getlamp(t, k);
				}

				// WTF??
				k_c = k_b;
				k_c -= (k_c >> 1) & 0x555555555;
				k_c = (k_c & 0x33333333) + ((k_c >> 2) & 0x33333333);
				k_c = (k_c + (k_c >> 4)) & 0x0f0f0f0f;
				k_c = 9 - (k_c * 0x01010101 >> 24);
				//k_c = pop_cnt[k_b];

				if (k_c < max)
				{
					//
					//	다음 세대를 넣음
					//
					g_x = i;
					g_y = j;
					g_b = k_b;

					if (k_c == 1) 
					{
						force_exit = true;
						break;
					}

					max = k_c;
				}
			}
			if (force_exit)
				break;
		}

		//
		//	성공 플래그
		//
		if (g_x == 9)
			return true;

		for (int i = 1; i < 10; i++)
		{
			//
			//	느슨한 꼬리 탐색
			//
			if (1 << i & ~g_b)
			{
				m_sp(g_x, g_y) = i;
				if (Solve())
					return true;
			}
		}

		m_sp(g_x, g_y) = 0;

		return false;
	}

	void print_tmp()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				std::cout << m_sp(i, j);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	SudokuPannel getsp() const
	{
		return m_sp;
	}

protected:
	
	SudokuPannel m_sp;
};

class SudokuAnotherSolve
{
public:

	SudokuAnotherSolve(const SudokuPannel& answer, SudokuPannel sp)
		: m_answer(answer)
		, m_sp(sp)
	{
	}

	bool Find()
	{
		int max = 9;
		int g_x = 9, g_y = 9;
		unsigned long g_b;
		bool force_exit = false;
		
		//
		//	백 트래킹 알고리즘
		//
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (m_sp(i, j))
					continue;

				int k_c = 0;
				unsigned long k_b = 0;

				int t = (i / 3) * 3 + j / 3;

				//
				//	느슨한 꼬리 생성
				//
				for (int k = 0; k < 9; k++)
				{
					if (m_sp(i, k))
						k_b |= 1 << m_sp(i, k);
					if (m_sp(k, j))
						k_b |= 1 << m_sp(k, j);
					if (m_sp.getlamp(t, k))
						k_b |= 1 << m_sp.getlamp(t, k);
				}

				// WTF??
				k_c = k_b;
				k_c -= (k_c >> 1) & 0x555555555;
				k_c = (k_c & 0x33333333) + ((k_c >> 2) & 0x33333333);
				k_c = (k_c + (k_c >> 4)) & 0x0f0f0f0f;
				k_c = 9 - (k_c * 0x01010101 >> 24);
				//k_c = pop_cnt[k_b];

				if (k_c < max)
				{
					//
					//	다음 세대를 넣음
					//
					g_x = i;
					g_y = j;
					g_b = k_b;

					if (k_c == 1) 
					{
						force_exit = true;
						break;
					}

					max = k_c;
				}
			}
			if (force_exit)
				break;
		}

		//
		//	성공 플래그. 단, 기존 정답이 아닐 경우,
		//
		if (g_x == 9)
		{
			if (m_answer.equal(m_sp))
				return false;
			return true;
		}

		for (int i = 1; i < 10; i++)
		{
			//
			//	느슨한 꼬리 탐색
			//
			if (1 << i & ~g_b)
			{
				m_sp(g_x, g_y) = i;
				if (Find())
					return true;
			}
		}

		m_sp(g_x, g_y) = 0;

		//
		//	실패 플래그, 또 다른 정답이 존재하지 않음
		//
		return false;
	}
	
	void print_tmp()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				std::cout << m_sp(i, j);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

private:

	SudokuPannel m_answer;
	SudokuPannel m_sp;
};

class SudokuCreator
	: public SudokuPannel
{
public:

	SudokuCreator()
	{
		SudokuPannel();
	}

	bool Create(int dest = 25)
	{
		//
		//	임의로 선정된 9칸에 1부터 9까지 각각 집어 넣는다.
		//
		NonOverlappedRandomNumberGenerator random1(1, 9);
		NonOverlappedRandomNumberGenerator random2(1, 9);
		NonOverlappedRandomNumberGenerator random3(1, 9);

		for (int i = 0; i < 9; i++)
			operator()(random2[i], random3[i]) = random1[i];

		//
		//	푼다
		//
		SudokuSolver ss(static_cast<SudokuPannel> (*this));
		if (!ss.Solve())
		{
			return false;
		}
		clone(ss.getsp());
		
		NonOverlappedRandomNumberGenerator random(0, 80);

		int count = 0;

		//
		//	항목을 하나씩 지워나가며 새로운 판넬을 찾는다.
		//	무작위로 최대로 지울 수 있는 개수는 정하지 못함
		//
		for (int i = 0; i < 81; i++)
		{
			int temp = operator()(random[i] / 9, random[i] % 9);
			operator()(random[i] / 9, random[i] % 9) = 0;
			SudokuSolver tss(static_cast<SudokuPannel> (*this));
			if (!tss.Solve())
			{
				//
				//	에러이므로 더 이상 진행 불가능
				//
				return false;
			}

			//
			//	중복된 답이 있나 검색함
			//
			SudokuAnotherSolve sas(tss.getsp(), static_cast<SudokuPannel> (*this));
			if (sas.Find())
			{
				operator()(random[i] / 9, random[i] % 9) = temp;
			}
			else
			{
				count++;
				if (count == dest)
				{
					//
					//	성공
					//
					return true;
				}
			}
		}

		zeroset();

		//
		//	실패
		//
		return false;
	}
	
	void print_tmp()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				std::cout << operator()(i, j);
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

};

const char *sudoku_ex =     "800000000"
							"003600000"
							"070090200"
							"050007000"
							"000045700"
							"000100030"
							"001000068"
							"008500010"
							"090000400";

void main()
{
	/*SudokuPannel sp(sudoku_ex);
	SudokuSolver ss(sp);

	ss.Solve();
	ss.print_tmp();

	SudokuAnotherSolve sas(ss.getsp(), sp);
	if (sas.Find())
	{
		std::cout << "다른 답 존재" << std::endl;
		sas.print_tmp();
	}
	else
	{
		std::cout << "다른 답 X" << std::endl;
		sas.print_tmp();
	}*/

	SudokuCreator sc;
	while (true)
	{
		while (!sc.Create(81-22))
			;
		sc.print_tmp();
		sc.zeroset();
	}
}