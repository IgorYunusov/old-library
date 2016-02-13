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

// NOTICE : Standard Vector Mapping

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

// gradient <= only (n = 1 or n = 2)
typedef UIASTRUCT {
	int n;
	__UIAM gradient, height;
	__UIAM vertexX, vertexY;
}	GraphR2, *PGraphR2;

//---------------------------------------------------------------------
// Mapping UIA Structure R3
//---------------------------------------------------------------------
typedef UIASTRUCT {
	__UIAM	x, y, z;
}	CoordinatesR3, *PCoordinatesR3;

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
		delete ptr;
	}
};


//---------------------------------------------------------------------
// Direction Over Function
//---------------------------------------------------------------------

#define PORTING_OPTION_TRANSFORMEACH	0x0001
#define PORTING_OPTION_TRANSFORMXCU		0x0002
#define PORTING_OPTION_TRANSFORMYCU		0x0003
#define PORTING_OPTION_TRANSFORMOCU		0x0004

#define TRANSFORM_ROTATION				0x0001
#define TRANSFORM_DIRECTION				0x0002	// ex) x, y, z
#define TRANSFORM_SYMMETRY				0x0003	// ´ëÄª

UNAFIX_CLASSUNIT
CoordinatesR2 *
__m_serve_directporting(
	map_dec<CoordinatesR2> *msUIA,
	int
	);

UNAFIX_CLASSUNIT
CoordinatesR2 *
__m_serve_staticporting(
	map_dec<CoordinatesR2> *msUIA,
	int static_option
	);

AFFIX_CLASSUNIT
CoordinatesR2 *
VERSION_SELECTION(
	DirectionCorrect, 
	(map_dec<CoordinatesR2> *, int), 
	map_dec<CoordinatesR2> *mdUIA 
	);

UNAFIX_CLASSUNIT
CoordinatesR2 *
TransformCoordinate(
	PGraphR2 pGraphR2,
	map_dec<CoordinatesR2> *mdUIA,
	int transformoption,
	__UIAM transformunit
	);

#endif