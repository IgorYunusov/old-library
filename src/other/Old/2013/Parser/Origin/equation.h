/*
            ROLLRAT MATHEMATICS PROJECT

             Cpy (c) 14. ALL RIGHTS RESERVED.
   */


#ifndef _EQUATION_
#define _EQUATION_

#include "mathematics.h"

template<class u_type>
class Nomial
	{
public:
	Nomial()
		: _Next(nullptr), _Prev(nullptr), coefficient(0), degree(0)
		{
		}

	Nomial(u_type coff, u_type degr)
		: _Next(nullptr), _Prev(nullptr), coefficient(coff), degree(degr)
		{
		}

	union {
		u_type coefficient;
		u_type _Data;
	};

	int degree;

	Nomial<u_type> *_Next, *_Prev;
	};

template<class u_type, class _Uchar = char *>
class Equation
	{
public:
	typedef typename Nomial<u_type> _Equation;
	typedef typename Nomial<u_type> *_Equation_Ptr;

	_Equation_Ptr _Head;

	Equation()
		{ // entry point
		_Head = new _Equation();
		}

	//explicit Equation(const _Uchar _equation, const char _Ch)
	//	{ // entry point
	//	_Head = new _Equation();
	//	}

	~Equation()
		{
		}

	void push(u_type coefficient, u_type degree)
		{
		if (coefficient)
			return;
		_Equation_Ptr _Ptr = new _Equation(coefficient, degree), _Tmp = _Head;
		while(true)
			{
			if (_Tmp->_Next == nullptr)
				{
				_Tmp->_Next = _Ptr;
				break;
				}
			else if(_Tmp->_Next->degree == degree)
				{
				_Tmp->_Next->_Data += coefficient;
				delete _Ptr;
				break;
				}
			else if(_Tmp->_Next->degree < degree)
				{
				_Ptr->_Next = _Tmp->_Next;
				_Tmp->_Next = _Ptr;
				break;
				}
			else
				_Tmp = _Tmp->_Next;
			}
		}

	Equation<u_type, _Uchar>& operator+(const Equation<u_type, _Uchar>& _EquationTmp)
		{
		Equation<u_type, _Uchar> _Return;
		_Equation_Ptr _n = _Head->_Next, _m = _EquationTmp._Head->_Next, _r = _Return._Head;
		for( ; _n && _m; )
			if(_n->degree > _m->degree){
				_r->_Next = new _Equation(_n->coefficient, _n->degree);
				_r = _r->_Next;
				_n = _n->_Next;}
			else if(_m->degree > _n->degree){
				_r->_Next = new _Equation(_m->coefficient, _m->degree);
				_r = _r->_Next;
				_m = _m->_Next;}
			else if(_n->degree == _m->degree){
				if((_n->coefficient + _m->coefficient) != 0){
					_r->_Next = new _Equation(_n->coefficient + _m->coefficient, _n->degree);
					_r = _r->_Next;}
				_n = _n->_Next;
				_m = _m->_Next;}
		for( ; _n || _m; )
			if(_n){
				_r->_Next = new _Equation(_n->coefficient, _n->degree);
				_r = _r->_Next;
				_n = _n->_Next;}
			else if(_m){
				_r->_Next = new _Equation(_m->coefficient, _m->degree);
				_r = _r->_Next;
				_m = _m->_Next;}
		return _Return;
		}

	Equation<u_type, _Uchar>& operator-(const Equation<u_type, _Uchar>& _EquationTmp)
		{
		Equation<u_type, _Uchar> _Return;
		_Equation_Ptr _n = _Head->_Next, _m = _EquationTmp._Head->_Next, _r = _Return._Head;
		for( ; _n && _m; )
			if(_n->degree > _m->degree){
				_r->_Next = new _Equation(_n->coefficient, _n->degree);
				_r = _r->_Next;
				_n = _n->_Next;}
			else if(_m->degree > _n->degree){
				_r->_Next = new _Equation(_m->coefficient, _m->degree);
				_r = _r->_Next;
				_m = _m->_Next;}
			else if(_n->degree == _m->degree){
				if((_n->coefficient + (-_m->coefficient)) != 0){
					_r->_Next = new _Equation(_n->coefficient + (-_m->coefficient), _n->degree);
					_r = _r->_Next;}
				_n = _n->_Next;
				_m = _m->_Next;}
		for( ; _n || _m; )
			if(_n){
				_r->_Next = new _Equation(_n->coefficient, _n->degree);
				_r = _r->_Next;
				_n = _n->_Next;}
			else if(_m){
				_r->_Next = new _Equation(_m->coefficient, _m->degree);
				_r = _r->_Next;
				_m = _m->_Next;}
		return _Return;
		}

	Equation<u_type, _Uchar>& operator*(const Equation<u_type, _Uchar>& _EquationTmp)
		{
		Equation<u_type, _Uchar> _Return;
		_Equation_Ptr _n = _Head->_Next, _m = _EquationTmp._Head->_Next, _r = _Return._Head;
		for( ; _n; ){
			for( ; _m; ){
				_Return.push(_n->coefficient * _m->coefficient, _n->degree + _m->degree);
				_m = _m->next;}
			_n = _n->next;
			_m = _m->next;}
		return _Return;
		}

	Equation<u_type, _Uchar>& differentiation()
		{
		Equation<u_type, _Uchar> _Return;
		_Equation_Ptr _Ptr = _Head->_Next;
		for(; _Ptr; ){
			_Return.push(_Ptr->degree * _Ptr->coefficient, _Ptr->degree - 1);
			_Ptr = _Ptr->_Next;}
		return _Return;
		}

	Equation<u_type, _Uchar>& integration()
		{
		Equation<u_type, _Uchar> _Return;
		_Equation_Ptr _Ptr = _Head->_Next;
		for(; _Ptr; ){
			if(_Ptr->degree != -1)
				_Return.push(_Ptr->coefficient / (_Ptr->degree + 1), _Ptr->degree + 1);
			_Ptr = _Ptr->_Next;}
		return _Return;
		}

	};

#endif