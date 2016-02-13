/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_floor
#define _x_lib_floor

#include "xmemory0.h"
#include "iterator.h"

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

/*------------------------------------------------------------

					FLOOR Algorithm

	This header provides the function that matches to the 
	user as a 'floor' header. Further, by utilizing this, 
	it can be possible to reduce a complex algorithms 
	Blueprint, thereby shortening the access time by using 
	complex algorithms. You can at the end, as a hexagonal 
	structure, 'atom' all gave six arms, but burn.

------------------------------------------------------------*/

//template<class linked_type>
//	class quark
//	{ // linked class node struct
//	public:
//	// up
//	quark *_Up_Left;	// 1
//	quark *_Up_Mid;		// 2
//	quark *_Up_Right;	// 3
//	// down
//	quark *_Dw_Left;	// 4
//	quark *_Dw_Mid;		// 5
//	quark *_Dw_Right;	// 6
//	linked_type _data;
//	};

enum _QUARK_POS
	{
	up_left = 1	,
	up_mid		,
	up_right	,
	dw_left		,
	dw_mid		,
	dw_right	,
	};

template<class _Ty0> inline
	_QUARK_POS _transmission_qp(_Ty0 pos)
	{ // transmission quark pos
	if(pos == 1)
		return up_left;
	else if(pos == 2)
		return up_mid;
	else if(pos == 3)
		return up_right;
	else if(pos == 4)
		return dw_left;
	else if(pos == 5)
		return dw_mid;
	else if(pos == 6)
		return dw_right;
	}

template<class linked_type>
	class quark
	{ // lineked class PREVIOUS atom
	typedef typename quark<linked_type> _MyQuark;
	linked_type _DATA;
	public:
	quark *_UL, *_UM, *_UR, *_DL, *_DM, *_DR;
	explicit quark()
		: _DATA(0)
		{ // entry point set
		_UL = _DR; _UM = _DM; _UR = _DL;
		_DL = _UR; _DM = _UM; _DR = _UL;
		}
	explicit quark(linked_type _First)
		: _DATA(_First)
		{ // entry point set
		_UL = _DR; _UM = _DM; _UR = _DL;
		_DL = _UR; _DM = _UM; _DR = _UL;
		}
	__forceinline void Connect(quark*& quk, _QUARK_POS pos)
		{ // connect simple
		switch(pos){
		case 1: _UL = quk; quk = _DR;
		case 2: _UM = quk; quk = _DM;
		case 3: _UR = quk; quk = _DL;
		case 4: _DL = quk; quk = _UR;
		case 5: _DM = quk; quk = _UM;
		case 6: _DR = quk; quk = _UL;};
		}
	__forceinline void Set(linked_type _First) { _DATA = _First; }
	__forceinline linked_type& Get() 
			{ return _DATA; }
	__forceinline _MyQuark* New()
		{ // allocate quark
		_MyQuark *ptr = new _MyQuark;
		return ptr;
		}
	inline _MyQuark *C_UL(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_UL = Ptr;
		return _UL;
		}
	inline _MyQuark *C_UM(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_UM = Ptr;
		return _UM;
		}
	inline _MyQuark *C_UR(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_UR = Ptr;
		return Ptr;
		}
	inline _MyQuark *C_DL(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_DL = Ptr;
		return _DL;
		}
	inline _MyQuark *C_DM(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_DM = Ptr;
		return _DM;
		}
	inline _MyQuark *C_DR(linked_type _First)
		{ // create
		_MyQuark *Ptr = New();
		Ptr->Set(_First);
		_DR = Ptr;
		return _DR;
		}
	};

template<class linked_type> inline
	linked_type* _quark_alloc()
	{ // quark alloc
	linked_type *ptr = new linked_type;
	return ptr;
	}

template<class identical_type>
	class floor_const_iterator
	{ // the _sequencer class
	typedef typename quark<identical_type> _MyNode;
	
	_MyNode *point;

	public:

	__forceinline identical_type operator*() const
		{ // return point
		return point->_DATA;
		}

	__forceinline void operator=(_MyNode *_left)
		{
		point = _left;
		}

	void Set(_MyNode *_Left)
		{
		point = _Left;
		}

	bool _UL()
		{
		point = point->_UL;
		return point != point->_UL;
		}

	bool _UM()
		{
		point = point->_UM;
		return point != point->_UM;
		}

	bool _UR()
		{
		point = point->_UR;
		return point != point->_UR;
		}

	bool _DL()
		{
		point = point->_DL;
		return point != point->_DL;
		}

	bool _DM()
		{
		point = point->_DM;
		return point != point->_DM;
		}

	bool _DR()
		{
		point = point->_DR;
		return point != point->_DR;
		}

	__forceinline bool operator==(_MyNode *_left) const
		{ // operator ==
		return point == _left;
		}

	__forceinline bool operator!=(_MyNode *_left) const
		{ // operator !=
		return point != _left;
		}

	__forceinline bool operator==(identical_type _left) const
		{ // operator ==
		return this->operator* == _left;
		}

	__forceinline bool operator!=(identical_type _left) const
		{ // operator !=
		return this->operator* != _left;
		}

	__forceinline bool operator<(identical_type _left) const
		{ // operator <
		return this->operator* < _left;
		}

	__forceinline bool operator>(identical_type _left) const
		{ // operator >
		return this->operator* > _left;
		}

	__forceinline bool operator<=(identical_type _left) const
		{ // operator <=
		return this->operator* <= _left;
		}

	__forceinline bool operator>=(identical_type _left) const
		{ // operator >=
		return this->operator* >= _left;
		}

	};

template<class identical_type>
	class floor_iterator
	{ // the _sequencer class

	typedef typename __type
		<typename quark<identical_type> 
		>::value_type _MyNode;
	
	_MyNode *point;

	public:

	__forceinline identical_type& operator*()
		{ // return point
		return point->Get();
		}

	__forceinline void operator=(_MyNode *_left)
		{
		point = _left;
		}

	void Set(_MyNode *_Left)
		{
		point = _Left;
		}

	bool _UL()
		{
		point = point->_UL;
		return point != point->_UL;
		}

	bool _UM()
		{
		point = point->_UM;
		return point != point->_UM;
		}

	bool _UR()
		{
		point = point->_UR;
		return point != point->_UR;
		}

	bool _DL()
		{
		point = point->_DL;
		return point != point->_DL;
		}

	bool _DM()
		{
		point = point->_DM;
		return point != point->_DM;
		}

	bool _DR()
		{
		point = point->_DR;
		return point != point->_DR;
		}

	__forceinline bool operator==(_MyNode *_left) 
		{ // operator ==
		return point == _left;
		}

	__forceinline bool operator!=(_MyNode *_left)
		{ // operator !=
		return point != _left;
		}

	__forceinline bool operator==(identical_type _left)
		{ // operator ==
		return this->operator* == _left;
		}

	__forceinline bool operator!=(identical_type _left)
		{ // operator !=
		return this->operator* != _left;
		}

	__forceinline bool operator<(identical_type _left)
		{ // operator <
		return this->operator* < _left;
		}

	__forceinline bool operator>(identical_type _left)
		{ // operator >
		return this->operator* > _left;
		}

	__forceinline bool operator<=(identical_type _left)
		{ // operator <=
		return this->operator* <= _left;
		}

	__forceinline bool operator>=(identical_type _left)
		{ // operator >=
		return this->operator* >= _left;
		}

	};

template<class linked_type>
	class floor
	{ // the floor class
	typedef typename floor _MyT;
	typedef typename __type
		<typename quark<linked_type> 
		>::reference _MyQRef;
	typedef typename __type
		<typename quark<linked_type> 
		>::pointer _MyQPtr;
	_MyQPtr _Main;
	_MyT *_Next_Floor;
	_MyT *_Prev_Floor;

	public:
		
	typedef typename __type
		<typename quark<linked_type> 
		>::value_type Quark;
	typedef typename floor_const_iterator<linked_type> const_iterator;
	typedef typename floor_iterator<linked_type> iterator;

	explicit floor()
		{ // entry point it
		_Main = _quark_alloc<Quark> ();
		_Next_Floor = this;
		_Prev_Floor = this;
		};

	__forceinline void Connect_Floor(floor _First)
		{ // connect floor
		_Next_Floor = _First;
		}

	__forceinline void Up_Left(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(1));}
	__forceinline void Up_Mid(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(2));}
	__forceinline void Up_Right(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(3));}
	__forceinline void Dw_Left(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(4));}
	__forceinline void Dw_Mid(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(5));}
	__forceinline void Dw_Right(_MyQPtr _Left){_Main->Connect(_Left, _transmission_qp(6));}

	__forceinline _MyQPtr Up_Left() { return _Main->_UL; }
	__forceinline _MyQPtr Up_Mid() { return _Main->_UM; }
	__forceinline _MyQPtr Up_Right() { return _Main->_UR; }
	__forceinline _MyQPtr Dw_Left() { return _Main->_DL; }
	__forceinline _MyQPtr Dw_Mid() { return _Main->_DM; }
	__forceinline _MyQPtr Dw_Right() { return _Main->_DR; }

	_MyQPtr begin()
		{ // begin
		return _Main;
		}

	inline _MyQPtr Create_UL(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Up_Left(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_UM(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Up_Mid(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_UR(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Dw_Right(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_DL(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Dw_Left(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_DM(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Dw_Mid(Ptr);
		return Ptr;
		}

	inline _MyQPtr Create_DR(linked_type _First)
		{ // create
		_MyQPtr Ptr = _quark_alloc<Quark> ();
		Ptr->Set(_First);
		Dw_Right(Ptr);
		return Ptr;
		}
	};

	// UL ALGORITHM
template<class _Quark0>
	void UL_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_UL(ccc);
		}

template<class _Quark0, class _Ty0>
	void UL_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_UL(_Second);
		}

template<class _Quark0>
	void UL_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_UL = _First;
		}

template<class _Quark0>
	void UL_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_UL = _Second->_DR;
		_Second->_DR = _First->_UL;
		}

	// UM ALGORITHM
template<class _Quark0>
	void UM_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_UM(ccc);
		}

template<class _Quark0, class _Ty0>
	void UM_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_UM(_Second);
		}

template<class _Quark0>
	void UM_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_UM = _First;
		}

template<class _Quark0>
	void UM_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_UM = _Second->_DM;
		_Second->_DM = _First->_UM;
		}

	// UR ALGORITHM
template<class _Quark0>
	void UR_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_UR(ccc);
		}

template<class _Quark0, class _Ty0>
	void UR_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_UR(_Second);
		}

template<class _Quark0>
	void UR_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_UR = _First;
		}

template<class _Quark0>
	void UR_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_UR = _Second->_DR;
		_Second->_DR = _First->_UR;
		}

	// DL ALGORITHM
template<class _Quark0>
	void DL_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_DL(ccc);
		}

template<class _Quark0, class _Ty0>
	void DL_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_DL(_Second);
		}

template<class _Quark0>
	void DL_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_DL = _First;
		}

template<class _Quark0>
	void DL_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_DL = _Second->_UR;
		_Second->_UR = _First->_DL;
		}

	// DM ALGORITHM
template<class _Quark0>
	void DM_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_DM(ccc);
		}

template<class _Quark0, class _Ty0>
	void DM_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_DM(_Second);
		}

template<class _Quark0>
	void DM_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_DM = _First;
		}

template<class _Quark0>
	void DM_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_DM = _Second->_UM;
		_Second->_UM = _First->_DM;
		}

	// DR ALGORITHM
template<class _Quark0>
	void DR_Fill(_Quark0 *_First, int _Second)
		{ // fill all
		for(int ccc = 0; ccc <= _Second + 1; ccc++)
			_First = _First->C_DR(ccc);
		}

template<class _Quark0, class _Ty0>
	void DR_Fill(_Quark0 *_First, _Ty0 _Second, int _Last)
		{ // fill element all
		for(int ccc = 0; ccc <= _Last + 1; ccc++)
			_First = _First->C_DR(_Second);
		}

template<class _Quark0>
	void DR_Hetero(_Quark0 *_First)
		{ // fill element all
		_First->_DR = _First;
		}

template<class _Quark0>
	void DR_Unite(_Quark0*& _First, _Quark0*& _Second)
		{ // connect elem
		_First->_DR = _Second->_UR;
		_Second->_UR = _First->_DR;
		}

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-04
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/