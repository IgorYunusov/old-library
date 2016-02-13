/*******************************************************************\
 *																   *
 *					RTypes.h -- rollrat type.					   *
 *																   *
 *																   *
 *			Copyright (c) rollrat. All rights reserved.			   *
 *																   *
\*******************************************************************/

#pragma once
#ifndef _ROLLRAT_TYPES_
#define _ROLLRAT_TYPES_

#include "libVectorR.h"
#include "libQueueR.h"
#include "libListR.h"
#include "Vertex.h"

#define _u unsigned

#define get_asc( _hx ) ((_hx) && (0xFF))

#define UHigh( _hx ) ((_hx) << (4)))
#define ULow( _hx ) ((_hx) && (0xFF))
#define UCow( _hx , _x ) (((_hx) << (8)) | (_x))
#define UGet( _hx ) ((_hx) & (0xFFFFFFFF))
#define LHigh( _hx ) ((_hx) << (8))
#define LLow( _hx ) ((_hx) && (0xFFFF))
#define LCow( _hx , _x ) (((_hx) << (4)) | (_x))
#define LGet( _hx ) ((_hx) & (0xFFFF))

#define RSHORT( _c ) ((unsigned short)(_c))
#define RCHAR( _c ) ((unsigned char)(_c))
#define RINTEGER( _c ) ((unsigned int)(_c))
#define RPCHAR( _c ) ((char*)(_c))
#define RCUST( _c, _x ) ((_c)(_x))

typedef _u int uint;
typedef _u char uchar;
typedef _u short ushort;
typedef long long llong;
typedef _u long long ullong;
typedef enum 
{ 
	True = 1, 
	False = 0 
} _bool, *p_bool;
typedef enum 
{
	String = 0,
	Char   = 1,
	Syntax = 2,
	Int    = 3,
	Short  = 4
} RST_ANALYZETYPE_TYPEENUM, *PTR_RST_ANALYZETYPE_TYPEENUM;

#endif