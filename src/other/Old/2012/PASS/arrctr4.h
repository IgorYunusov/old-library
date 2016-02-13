/***********************************************************************

	RollRat Software ARRCTR4 Algorithm
	Array Control 4

	Copyright (c) rollrat. 2013. All rights reserved.

***********************************************************************/

#pragma once

// 이 문서는 A.C. 2013년 08월 12일 19시 20분에 처음 작성되었습니다.

#ifndef __ARRCTR4
#define __ARRCTR4

////////////////////////////////
//							  //
//	ROLLRAT USED ARRAY SET	  //
//							  //
//		[a][b]				  //
//							  //
//	a = row, b = line		  //
//							  //
//			t0	t1	t2	t3	  //
//							  //
//	f0		00	01	02	03	  //
//	f1		10	11	12	13	  //
//	f2		20	21	22	23	  //
//	f3		30	31	32	33	  //
//							  //
////////////////////////////////

template<class __t> inline
	__t **_New_Array(__t)
	{ // create new array
	__t **s;
	s = new __t*[4];
	for(int i = 0; i < 4; i++)
		s[i] = new __t[4];
	return s;
	}

template<class __t> inline
	void _Shift_Row(__t **&arr, unsigned int t, unsigned int f)
	{ // shift row
	for(__t buf = 0, int i = 0; i < f; i++){
		buf = arr[t][3];arr[t][3] = arr[t][2];
		arr[t][2] = arr[t][1];arr[t][1] = arr[t][0];arr[t][0] = buf;}
	}
	
template<class __t> inline
	void _Shift_Line(__t **&arr, unsigned int t, unsigned int f)
	{ // shift line
	for(__t buf = 0, int i = 0; i < f; i++){
		buf = arr[3][t];arr[3][t] = arr[2][t];
		arr[2][t] = arr[1][t];arr[1][t] = arr[0][t];arr[0][t] = buf;}
	}

template<class __t> inline
	void _Xor_All(__t **&arr, unsigned int what)
	{ // xor all
	for(int i = 0; i < 4; i++) for(int f = 0; f < 4; f++)
		arr[i][f] ^= what;
	}

template<class __t> inline
	void _Xor_Row(__t **&arr, unsigned int what, unsigned int t)
	{ // xor row
	for(int i = 0; i < 4; i++) arr[t][i] ^= what;
	}

template<class __t> inline
	void _Xor_Line(__t **&arr, unsigned int what, unsigned int t)
	{ // xor line
	for(int i = 0; i < 4; i++) arr[i][t] ^= what;
	}

template<class __t> inline
	void _Xor(__t **&arr, const __t **arr1)
	{ // xor array
	for(int i = 0; i < 4; i++) for(int f = 0; f < 4; f++)
		arr[i][f] = arr1[i][f];
	}

template<class __t> inline
	void _Fill(__t **&arr, __t w)
	{ // zero fill
	for(int i = 0; i < 4; i++) for(int f = 0; f < 4; f++)
		arr[i][f] = w;
	}

template<class __t> inline
	void _Zero(__t **&arr)
	{ // zero fill
	_Fill(arr, 0);
	}

#endif