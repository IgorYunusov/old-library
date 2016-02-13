/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   Vector.h

Project:

	RollRat Arithmetic Vector Class

------
   AUTHOR: HyunJun Jeong  2015-08-22

***************************************************************************/

#ifndef _VECTOR_0bb5d5b1df317505f702a78392475df2_
#define _VECTOR_0bb5d5b1df317505f702a78392475df2_

#include <math.h>

template<typename data_type,
	typename size_type = long double> class
	basic_vector3
{
public:
	
	typedef class basic_vector3<data_type> this_type;
	
	typedef typename this_type*	pointer;
	typedef typename const this_type*	const_pointer;
	typedef typename this_type&	reference;
	typedef typename const this_type&	const_reference;

	typedef typename data_type value_type;

	basic_vector3()
		: m_x(nullptr)
		, m_y(nullptr)
		, m_z(nullptr)
	{
	}

	basic_vector3(value_type x, value_type y, value_type z)
		: m_x(x)
		, m_y(y)
		, m_z(z)
	{
	}

	size_type size()
	{
		return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
	}

	reference operator+(const_reference pi)
	{
		m_x += pi.m_x;
		m_y += pi.m_y;
		m_z += pi.m_z;
		return *this;
	}
	
	reference operator-(const_reference pi)
	{
		m_x -= pi.m_x;
		m_y -= pi.m_y;
		m_z -= pi.m_z;
		return *this;
	}
	
	//
	//	Inner Product
	//
	reference operator*(const_reference pi)
	{
		return m_x * pi.m_x + m_y * pi.m_y + m_z * pi.m_z;
	}

private:

	value_type m_x, m_y, m_z;
};

#endif