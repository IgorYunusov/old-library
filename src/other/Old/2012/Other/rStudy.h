/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Copyright (c) ROLLRAT. All Rights Reserved.								   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/

#include "rstdio.h"
#include "rnull.h"
#include "rdef.h"
#include "rnum.h"

// /*  */
#ifndef _R_Study_
#define _R_Study_
#ifdef  __cplusplus
extern "C" {
extern "C++"{
#endif

#if !defined(_Return_Function_) && !defined(_Return_Char_)
#define _Return_Function_
#define _Return_Char_
#define _Check_Int_
#define _Check_Calc_B_ _Calc_B_
#define _Check_Calc_H_ _Calc_H_
#define _Check_Return_Calc_
#define _Check_Return_Char_
#define _Check_Error_
#define _Check_Return_Error_
#define _Check_Return_Exception_
#define _Type_Int64_
#define _Type_LF_
#define _Deleted_Function_
#define _Deleted_Char_
#define _Unuseable_Function_
#define _Used_Function_
#define _Outside_Define_
#define _Insid_Define_
#else
#define _Return_Function_Calc_
#define _Return_Char_Pre
#endif

#define Credit_Line 100000000
#define Bank_Limit  1000000000
#define Job_Limit   100
#define Per_Limit   3


#define _Calc_B_ _Type_Int64_

#define _min_(X, Y) ((X < Y) ? (X) : (Y))
#define _max_(X, Y) ((X > Y) ? (X) : (Y))
#define _min(X, Y) ((X < Y) ? 1 : 0)
#define _max(X, Y) ((X > Y) ? 0 : 1)


_Return_Function_ _Check_Return_Calc_ _Check_Calc_B_ int _Check_Int_ sum(int x,int y){return x + y;}
_Return_Function_ _Check_Return_Calc_ _Check_Calc_B_ int _Check_Int_ sub(int x,int y){return x - y;}
_Return_Function_ _Check_Return_Calc_ _Check_Calc_B_ int _Check_Int_ mul(int x,int y){return x * y;}
_Return_Function_ _Check_Return_Calc_ _Check_Calc_B_ int _Check_Int_ div(int x,int y){return x / y;}
/* Please Modification this line */_Return_Function_ _Check_Return_Calc_ _Check_Calc_B_ int _Check_Int_ rand(int x,int _max__){static int seed = 1;seed = ((seed * x * 6553565535 + x * 6355653556)/65535)%_max__;return seed;}
_Return_Function_ _Check_Return_Calc_ _Check_Calc_B_ int _Check_Int_ type(int x){if (x%2)return 0;else return 1;}
_Return_Function_ _Check_Return_Calc_ _Check_Calc_B_ int _Check_Int_ abs(int x){if (x < 0)return (-1) * x;else if (x > 0)return x;else if (x == 0)return 0;}

#define _Calc_H_
_Return_Function_ _Check_Return_Calc_ _Check_Calc_H_ long double _Type_LF_ fact(long double fact_){if (fact_ == 0) return 1; else return fact_ * fact(fact_ - 1);}
//_Return_Function_ _Check_Return_Calc_ _Check_Calc_H_ int _Check_Int_ summation(int num,int start){int i;long double _sum = 0.0;for (i=0;i=start;i++)_sum += num;return _sum;}


__int64 loan_money = Credit_Line;
__int64 real_money;
__int64 bank_money;

__int64 loan(__int64 loaning){
#ifdef Credit_Line
	if (loaning < Credit_Line){
		if (loan_money < loaning)
			return 0x0002;
		else{
			real_money += loaning;
			loan_money -= loaning;
			return real_money;
		}
		return 0x0010;
	}else if (loan_money <= loaning){
		return 0x1012;
	}
#else
	return 0xffffffffffffffff;
#endif
}
__int64 save(__int64 saving){
#ifdef Bank_Limit
	bank_money += saving;
	real_money -= saving;
	return real_money;
#else
	return 0xffffffffffffffff;
#endif
}
__int64 nmoney(){return real_money;}
__int64 work(__int64 working){
#ifdef Job_Limit
	real_money = Job_Limit * working;
	return real_money;
#else
	return 0xffffffffffffffff;
#endif
}
int gamble(int i){
	rand(i,100);
	rand(i,100);
	rand(i,100);
	if (rand(rand(i,100) * rand(i,100),66666) > 33333)
		real_money *= i;
	else
		real_money /= i;
	return real_money;
}
#ifdef  __cplusplus
}
}
#endif

#endif