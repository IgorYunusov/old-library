/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Sudoku.h

Purpose:

   RollRat Library

Author:

   10-11-2015:   HyunJun Jeong, Creation

***/

#ifndef _SUDOKU_9bf1541fdf7efd41b7b39543fd870ac4_
#define _SUDOKU_9bf1541fdf7efd41b7b39543fd870ac4_

#include <iostream>
#include "Random.h"

namespace Utility {

	class SudokuPannel
	{
	public:

		// 빈 판을 생성함
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
				m_pannel[i][j] = m_str[i * 9 + j] - '0';
			setlamp();
		}

		SudokuPannel(const char **m_str)
		{
			for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				m_pannel[i][j] = m_str[i][j] - '0';
			setlamp();
		}

		SudokuPannel(const SudokuPannel& refer)
		{
			for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				m_pannel[i][j] = refer.m_pannel[i][j];
			setlamp();
		}

		int getlamp(int i, int j)
		{
			return *m_lamp[i][j];
		}

		int& operator()(int i, int j)
		{
			return m_pannel[i][j];
		}

		void zeroset()
		{
			for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				m_pannel[i][j] = 0;
		}

		bool equal(const SudokuPannel& sp)
		{
			for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (m_pannel[i][j] != sp.m_pannel[i][j])
					return false;
			return true;
		}

		void print_tmp()
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					std::cout << m_pannel[i][j];
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		
		int* m_lamp  [9][9];
		int  m_pannel[9][9];

		/*

			lamp에 pannel lamp를 채웁니다.

			m_pannel: 기본 저장

			      x1   x2   x3    x4   x5   x6    x7   x8   x9
			   +------------------------------------------------+
			y1 ||x1y1|x2y1|x3y1||x4y1|x5y1|x6y1||x7y1|x8y1|x9y1||
			   ||----+----+----||----+----+----||----+----+----||
			y2 ||x1y2|x2y2|x3y2||x4y2|x5y2|x6y2||x7y2|x8y2|x9y2||
			   ||----+----+----||----+----+----||----+----+----||
			y3 ||x1y3|x2y3|x3y3||x4y3|x5y3|x6y3||x7y3|x8y3|x9y3||
			   ++--------------++--------------++--------------++
			y4 ||x1y4|x2y4|x3y4||x4y4|x5y4|x6y4||x7y4|x8y4|x9y4||
			   ||----+----+----||----+----+----||----+----+----||
			y5 ||x1y5|x2y5|x3y5||x4y5|x5y5|x6y5||x7y5|x8y5|x9y5||
			   ||----+----+----||----+----+----||----+----+----||
			y6 ||x1y6|x2y6|x3y6||x4y6|x5y6|x6y6||x7y6|x8y6|x9y6||
			   ++--------------++--------------++--------------++
			y7 ||x1y7|x2y7|x3y7||x4y7|x5y7|x6y7||x7y7|x8y7|x9y7||
			   ||----+----+----||----+----+----||----+----+----||
			y8 ||x1y8|x2y8|x3y8||x4y8|x5y8|x6y8||x7y8|x8y8|x9y8||
			   ||----+----+----||----+----+----||----+----+----||
			y9 ||x1y9|x2y9|x3y9||x4y9|x5y9|x6y9||x7y9|x8y9|x9y9||
			   +------------------------------------------------+

			m_lamp: lamp 저장 (패널용 트랜잭션 시리얼 배열)

			  \ y y1   y2   y3    y4   y5   y6    y7   y8   y9
			 x +------------------------------------------------+
			x1 ||x1y1|x2y1|x3y1||x1y2|x2y2|x3y3||x1y3|x2y3|x3y3||
			   ||----+----+----||----+----+----||----+----+----||
			x2 ||x4y1|x5y1|y6y1||x4y2|x5y2|x6y2||x4y3|x5y3|x6y3||
			   ||----+----+----||----+----+----||----+----+----||
			x3 ||x7y1|x8y1|x9y1||x7y2|x8y2|x9y2||x7y3|x8y3|x9y3||
			   ++--------------++--------------++--------------++
			x4 ||x1y4|x2y4|x3y4||x1y5|x2y5|x3y5||x1y6|x2y6|x3y6||
			   ||----+----+----||----+----+----||----+----+----||
			x5 ||x4y4|x5y4|x6y4||x4y5|x5y5|x6y5||x4y6|x5y6|x6y6||
			   ||----+----+----||----+----+----||----+----+----||
			x6 ||x7y4|x8y4|x9y4||x7y5|x8y5|x9y5||x7y6|x8y6|x9y6||
			   ++--------------++--------------++--------------++
			x7 ||x1y7|x2y7|x3y7||x1y8|x2y8|x3y8||x1y9|x2y9|x3y9||
			   ||----+----+----||----+----+----||----+----+----||
			x8 ||x4y7|x5y7|x6y7||x4y8|x5y8|x6y8||x4y9|x5y9|x6y9||
			   ||----+----+----||----+----+----||----+----+----||
			x9 ||x7y7|x8y7|x9y7||x7y8|x8y8|x9y8||x7y9|x8y9|x9y9||
			   +------------------------------------------------+

		*/
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

	};

	//
	//	스도쿠를 푸는 알고리즘입니다.
	//
	class SudokuSolver
		: public SudokuPannel
	{
		SudokuPannel other;
		bool	     check_other;

	public:

		SudokuSolver(const SudokuPannel& refer)
			: SudokuPannel(refer)
			, check_other(false)
		{
		}

		SudokuSolver(const SudokuPannel& refer, const SudokuPannel& other)
			: SudokuPannel(refer)
			, other(other)
			, check_other(true)
		{
		}

		bool Solve()
		{
			int max = 9;
			int g_x = 9, g_y = 9;
			unsigned long g_b;

			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if ((*this)(i, j))
						continue;

					int k_c = 0;
					unsigned long k_b = 0;

					int t = (i / 3) * 3 + j / 3;

					for (int k = 0; k < 9; k++)
					{
						if ((*this)(i, k))
							k_b |= 1 << (*this)(i, k);
						if ((*this)(k, j))
							k_b |= 1 << (*this)(k, j);
						if ((*this).getlamp(t, k))
							k_b |= 1 << (*this).getlamp(t, k);
					}

					// hamming weight popcount(__popcnt)
					k_c = k_b;
					k_c -= (k_c >> 1) & 0x555555555;
					k_c = (k_c & 0x33333333) + ((k_c >> 2) & 0x33333333);
					k_c = (k_c + (k_c >> 4)) & 0x0f0f0f0f;
					k_c = 9 - (k_c * 0x01010101 >> 24);

					if (k_c < max)
					{
						g_x = i;
						g_y = j;
						g_b = k_b;

						if (k_c == 1)
						{
							goto EXIT;
						}

						max = k_c;
					}
				}
			}
		EXIT:

			if (g_x == 9)
			{
				if (!check_other)
					return true;
				else if (other.equal(*this))
					return false;
			}

			for (int i = 1; i < 10; i++)
			{
				if (1 << i & ~g_b)
				{
					(*this)(g_x, g_y) = i;
					if (Solve())
						return true;
				}
			}

			(*this)(g_x, g_y) = 0;

			return false;
		}

	};
	
	//
	//	스도쿠를 생성하는 알고리즘입니다.
	//
	class SudokuCreator
		: public SudokuPannel
	{
	public:

		bool Create(int dest = 25)
		{
			//
			//	임의로 선정된 9칸에 1부터 9까지 각각 집어 넣는다.
			//
			Random random1(1, 9);
			Random random2(1, 9);
			Random random3(1, 9);

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

			for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				m_pannel[i][j] = ss.m_pannel[i][j];

			Random random(0, 80);

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
				SudokuSolver sas(tss, static_cast<SudokuPannel> (*this));
				if (!sas.Solve())
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
	};

	const char *sudoku_ex = "800000000"
						    "003600000"
						    "070090200"
						    "050007000"
						    "000045700"
						    "000100030"
						    "001000068"
						    "008500010"
						    "090000400";

	class SudokuTest
	{
	public:

		static void test()
		{
			SudokuPannel sp(sudoku_ex);
			SudokuSolver ss(sp);

			ss.Solve();
			ss.print_tmp();

			SudokuSolver sas(ss, sp);
			if (!sas.Solve())
			{
				std::cout << "다른 답 존재" << std::endl;
				sas.print_tmp();
			}
			else
			{
				std::cout << "다른 답 X" << std::endl;
				sas.print_tmp();
			}
		}

		static void create()
		{
			SudokuCreator sc;
			while (true)
			{
				while (!sc.Create(81 - 30))
					;
				sc.print_tmp();
				sc.zeroset();
			}
		}

	};

}

#endif