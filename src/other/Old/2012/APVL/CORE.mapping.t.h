/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

// Unlimited Intervene Algorithms

#ifndef CORE_MAPPING
#define CORE_MAPPING

#include "UIA.algorithm.h"

#ifndef __UIAM
#define __UIAM unsigned long long
#endif


//---------------------------------------------------------------------
// Mapping UIA Structure R2
//---------------------------------------------------------------------
typedef UIASTRUCT {
	__UIAM	x, y; 
}	CoordinatesR2, *PCoordinatesR2;

typedef UIASTRUCT {
	CoordinatesR2 *World;
	CoordinatesR2 *Local;
	CoordinatesR2 CartesianCS; // max min set
}	MAPPING32, *PMAPPING32;		// Random Set Unit

typedef UIASTRUCT {
	CoordinatesR2 **Coordinates;
}	MAPPING64, *PMAPPING64;		// Static Set Unit


//---------------------------------------------------------------------
// Auto Ptr
//---------------------------------------------------------------------
AFXCLASS (map_dec)
{ // map decs
public:
	_UIA *ptr;
	inline map_dec(_UIA *x)
	{
		ptr = x;
	}
	inline ~map_dec()
	{
		delete ptr[];
	}
};



/**********************************************************************

							R2 Map Server

/*********************************************************************/
MKCLASS	(map_R2)
{ // map server
protected:

	DEKS_TEMSET map_dec<_UIA> *CreateNewMapDec(_UIA *ptr);

	//mapping32
	static ATVOID CreateNewMap32(PMAPPING32 mUIA32);
	static ATVOID PutStraightLine32(PMAPPING32 mUIA32, __UIAM m, __UIAM n);
	static ATVOID TransRotation32(PMAPPING32 mUIA32, int dwAngle);
	PCoordinatesR2 CreateNewCoordinates();
	static ATVOID CoordinateTransRotation(PCoordinatesR2 t, int dwAngle);


	SET_COLLECTOR( Direction, PCoordinatesR2 t );

	ATVOID CreateNewMap64(PMAPPING64 mUIA64, 
		unsigned int allocX, unsigned int allocY);
};

#endif