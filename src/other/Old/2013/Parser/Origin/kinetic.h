/*
            ROLLRAT MATHEMATICS PROJECT

             Cpy (c) 14. ALL RIGHTS RESERVED.
   */

#ifndef _KINETIC_
#define _KINETIC_

#include "mathematics.h"

#include <xtgmath.h>

template<class _VecloK>
	inline _VecloK& PhyDistance(_VecloK Time, _VecloK Velocity)
	{
		return Time * Velocity;
	}

template<class _VecloK> 
	inline _VecloK& PhyDistance(_VecloK Time, _VecloK Velocity, _VecloK Variation)
	{
		return Velocity * Time + pow(Time, 2) * Variation / 2;
	}



#endif