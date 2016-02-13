/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   StringGenetic.h

Project:

	RollRat Genetic Set of Algorithms

------
   AUTHOR: HyunJun Jeong  2015-08-23

***************************************************************************/

#ifndef _STRINGGENETIC_f1ee1185f22bfceac395316de3a0ee58_
#define _STRINGGENETIC_f1ee1185f22bfceac395316de3a0ee58_

#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <cassert>
#include <iomanip>

//
//	mutation_rate range = [0, 1000]
//
template<int length, int mutation_rate>
class StringGeneticCode
{
public:

	StringGeneticCode()
	{
		for (int i = 0; i < length; i++)
		{
			m_string[i] = 32 + (std::rand() % (128 - 32 + 1));
		}
		m_string[length] = 0;
	}

	void fitness(const char target[length + 1])
	{
		int summation = 0;
		for(int i = 0; i < length; i++)
		{
			if (m_string[i] == target[i])
				summation++;
		}
		m_fitness = summation / (double)length;
	}

	StringGeneticCode *crossover(const StringGeneticCode& other)
	{
		StringGeneticCode *ret = new StringGeneticCode < length, mutation_rate > ();
		int replacement_pos = std::rand() % length;

		//
		//	Random Crossover with two DNA
		//
		for (int i = 0; i < replacement_pos; i++)
			ret->m_string[i] = other.m_string[i];
		for (int i = replacement_pos; i < length; i++)
			ret->m_string[i] = this->m_string[i];

		ret->m_string[length] = 0;

		return ret;
	}

	void mutate()
	{
		for (int i = 0; i < length; i++)
		{
			int rand = std::rand();
			if (rand % 1001 <= mutation_rate)
				m_string[i] = 32 + (rand % (128 - 32 + 1));
		}
	}

	double get_fitness() const
	{
		return m_fitness;
	}

	char *get_string()
	{
		return m_string;
	}

private:

	char m_string[length + 1];
	double m_fitness;
};

template<int length, int mutation_rate, int population, int putup>
class StringGeneticField
{
public:

	typedef class StringGeneticCode<length, mutation_rate> code_type;

	StringGeneticField(const char dest[length + 1])
	{
		std::srand(std::time(0));

		strncpy_s(m_dest, length + 1, dest, length);

		for(int i = 0; i < population; i++)
		{
			m_codes.push_back(new code_type);
		}
	}

	void evolution()
	{
		//
		//	Selection Algorithm
		//
		
		std::vector<code_type *> m_hunting;
		for (int i = 0; i < population; i++)
		{
			//
			//	Set hunting group during fitness time
			//

			m_codes[i]->fitness(m_dest);
			m_hunting.push_back(m_codes[i]);
			for (int j = 0; j < m_codes[i]->get_fitness() * putup; j++)
				m_hunting.push_back(m_codes[i]);
		}

		
		//
		//	Intercross
		//

		for (int i = 0; i < population; i++)
		{
			code_type origin = *m_hunting[std::rand() % m_hunting.size()];
			code_type other = *m_hunting[std::rand() % m_hunting.size()];

			code_type *crossover_proc = origin.crossover(other);

			crossover_proc->mutate();

			std::cout  << origin.get_string() << " + " << 
				other.get_string() << " = \t" << crossover_proc->get_string() << std::endl;

			m_codes[i] = crossover_proc;
		}

		count++;
	}

	bool check_generation()
	{
		for (code_type* ct : m_codes)
		{
			if (!strcmp(ct->get_string(), m_dest))
				return true;
		}
		return false;
	}

	int get_generation() const
	{
		return count;
	}

	void print_all()
	{
		for (int i = 0; i < population; i++)
		{
			std::cout << m_codes[i]->get_string() << ' ';
		}
		std::cout << std::endl;
	}

private:

	int count = 0;
	char m_dest[length + 1];
	std::vector<code_type *> m_codes;

};

#endif