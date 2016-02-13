/*收收收收收收收收收收收收收收收收收收收收收收收收收收收收收*
 早												 早
 弛			RollRat Software Library			 弛
 弛												 弛
 弛	Copyright (c) rollrat. All rights reserved.  弛
 *收收收收收收收收收收收收收收收收收收收收收收收收收收收收收*/

#pragma once

#ifndef _L_NT_SERVED_ROLLRAT
#define _L_NT_SERVED_ROLLRAT

#define _POSSIBLE
#define _VIRTUAL
#define _NECESSARY
#define _VERSION_CHECK

#define INLINE					inline
#define F_INLINE				__forceinline
#define CLS						class
#define Module					ref class
#define STRUCTURE				struct
#define ENUMERATE				enum
#define NON_TEMPLATE			template<>
#define Functional(x, y, z)		typedef x (y)(z);

/*--------------------------------------------
	BOOL							 == 130802
--------------------------------------------*/
typedef ENUMERATE _STRUCT_BOOL{
	True = 1,
	False = 0,
}	BOOL;

/*--------------------------------------------
	SIGNAL_SIGN						 == 130802
--------------------------------------------*/
typedef STRUCTURE _SCANF_S_SIGNAL_SIGN{
	BOOL Offset;
	BOOL Onset;
}	SIGNAL_SIGN, *SIGNAL_SIGN_PTR;

/*--------------------------------------------
	HANDLE							 == 130802
--------------------------------------------*/
typedef STRUCTURE _FC_HANDLE_POSITIONX{
	SIGNAL_SIGN offset;
	BOOL FLEXIBLE;
	int serial_number;
}	HANDLE, *HANDLE_PTR;

/*--------------------------------------------
	POSITION						 == 130802
--------------------------------------------*/
typedef STRUCTURE _PICTUREING_POSITION{
	int x, y, z;
}	POSITION;

/*--------------------------------------------
	INDEX							 == 130802
--------------------------------------------*/
typedef STRUCTURE _ARE_INDEX_LIB_BOOK{
	POSITION Cycle_XNM;
	HANDLE Serial;
	char * title;
	char * story;
	char CrLf;
}	BOOK;

#endif