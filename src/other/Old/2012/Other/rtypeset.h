/*
 *
 *			ROLLRAT SOFTWARE SUBROUTINE
 *			SINCE : 2009 - 2012
 *
 *			Version: 0.3.2.6
 *
 *
 *			Copyright (c) ROLLRAT. All Rights Reserved.
 *
 *
 ***************************************************************************/

#pragma once
#if !defined(_r_type_set_)
#define _r_type_set_
#define _Only_True_(_tPut_) _tPut_ > 0 ? 1 : 0
#define _Only_False_(_tPut_) _tPut_ < 0 ? 1 : 0
#define _Type_Get_(_kPut_) \
	(sizeof(_kPut_) > 1 ? \
	(sizeof(_kPut_) > 2 ? \
	(sizeof(_kPut_) > 4 ? \
	(sizeof(_kPut_) > 8 ? \
	(sizeof(_kPut_) > 16 ? \
	(sizeof(_kPut_) > 32 ? \
	(sizeof(_kPut_) > 64 ? 7 : 6) : 5) : 4) : 3) : 2) : 1) : 0)
#endif