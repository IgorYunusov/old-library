/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Version : 5.081.2							                               ********
 ********       Header : <rollratg.h>					                         		   ********
 ********										                                           ********
 ********       Copyright ¨Ï ROLLRAT. All Rights Reserved.				                   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/
#pragma once

#ifndef _CURRENT_SUL_S
#define _CURRENT_SUL_S

#define TRUE  1
#define FALSE 0
//#define NULL *(char *)
#ifndef __FUNCTION_GROUP_
#define __FUNCTION_GROUP_

#define Addition(x, y) x + y
#define Subract(x, y) x + y
#define SubractReverse(x, y) y - x

int _TOOL_INT_SUM(int __FR_DATA,int __SR_DATA,int __SR_TYPE){if (__SR_TYPE == 0){return __FR_DATA + __SR_DATA;}else if (__SR_TYPE == 1){return Addition(__FR_DATA,__SR_DATA);}}
int _TOOL_INT_SUB(int __FR_DATA,int __SR_DATA,int __SR_TYPE){if (__SR_TYPE == 0){return __FR_DATA - __SR_DATA;}else if (__SR_TYPE == 1){return Subract(__FR_DATA,__SR_DATA);}}
int _TOOL_CHECKER_B(int __F_DATA,int __F_DATION){if (_TOOL_INT_SUM(__F_DATA,__F_DATION,1) == 16){return 1;}else if (_TOOL_INT_SUM(__F_DATA,__F_DATION,1) == 17){return 2;}else if (_TOOL_INT_SUM(__F_DATA,__F_DATION,1) == 18){return 3;}}
int _TOOL_CHECKER_C(int __F_DATA,int __F_DATION){if (_TOOL_INT_SUB(__F_DATA,__F_DATION,1) == 16){return 1;}else if (_TOOL_INT_SUB(__F_DATA,__F_DATION,1) == 17){return 2;}else if (_TOOL_INT_SUB(__F_DATA,__F_DATION,1) == 18){return 3;}}

#endif

#ifndef _SULTAIN_SOLUTION_S
#define _SULTAIN_SOLUTION_S

#ifndef SOLUTAIN
#define SOLUTAIN "stalrain"
#endif

#ifndef CONTAIN
#define CONTAIN 0x01
#endif

/* Definiation Of New Character */
#define SOLING(C,X,Y)     SOL##C=X+Y
#define Plaint_CULTURE    "SOLUTAIN"
#define Plaint_SOSO       "FORRY   "
#define F_CONTAIN         "$"
#define F_SOULTAIN        "~"
#define F_GROUP           "@"
#define F_IMPO            "0x00000000" //NULL
#define D_DEATH           "0xFFFF0001" //KILL NUMBER
#define D_COMSOL          "0xAAFB9542" //SETTING COMSOLDATA
#define D_SOLVER          "ROLLRAT"
#define D_SOLVE           "$ROLLRAT$"
#define D_SOLV            "#ROLLRAT#"
#define D_UNIQUE          "0x01"
#define D_LEGENDLY        "0x09"
#define C_SIN(x)          (long double)sin((double)x) /* Read __ROLLRATCALCULATION__ */      
#define C_COS(x)          (long double)cos((double)x)  
#define C_TAN(x)          (long double)tan((double)x)  
#define C_LOG(x)          (long double)log((double)x)  
#define C_IN(x)           (long double)in((double)x)   
#define C_SQRT(x)         (long double)sqrt((double)x)    
#define C_NL(x)           (long double)nl((double)x)    
#define C_RECI(x)         (long double)reci((double)x)    
#define C_RAND(x)         (long double)rand((double)x)    
#define L_ERROR0          "Successful !"
#define L_ERROR1          "You cannot choose this point !"
#ifndef SOOF
#define SOOF 0x30
#endif

struct _instack_SO{
	int solar;
	float kondi;
	char* fold;
	char* fptr;
	char* bptr;
	char* loginfor;
	char* logindat;
	char* come;
	int uiop;
}SO;
struct _instack_CA{int fist;int scst;int lsst;}CA;
struct _instack_IO{int login;int process;int admin;}IO;

/* Literal Function */
inline int _CO_DF(int __SULUTAIN,int __STANDING){
	int __S__; for(__S__=0;__S__=__STANDING;__S__++){__SULUTAIN = __SULUTAIN * __SULUTAIN;}return __SULUTAIN;}
inline int _SI_MA(int __SULUTAIN,int __STANDING){
	int __S__; for(__S__=0;__S__=__STANDING;__S__++){__SULUTAIN = __SULUTAIN / __SULUTAIN;}return __SULUTAIN;}
inline int _SI_MU(int __SULUTAIN,int __STANDING){
	int __S__; for(__S__=0;__S__=__STANDING;__S__++){__SULUTAIN = __SULUTAIN * __SULUTAIN * __SULUTAIN;}return __SULUTAIN;}
inline int _SI_MD(int __SULUTAIN,int __STANDING){
	int __S__; for(__S__=0;__S__=__STANDING;__S__++){__SULUTAIN = __SULUTAIN / __SULUTAIN / __SULUTAIN;}return __SULUTAIN;}
inline char* __SHOR__COM__(char __INF_I[]){
	if (__INF_I == "L0"){CA.fist += 1;return SOLUTAIN;}else if (__INF_I == "L1"){CA.scst += 1;return Plaint_CULTURE;}}

#ifndef _ANALYSIS_I_DATA_
#define _ANALYSIS_I_DATA_
char* _DATA_SET(char __STD_NUM_RD[],int __STD_NUM_RE)
{
	if (__STD_NUM_RD == "LOGIN"){
		if (__STD_NUM_RE > 0 && __STD_NUM_RE <= 10){
			SO.fold = "FOLT";return L_ERROR0;
		}else if (__STD_NUM_RE = 0xF){
			SO.fold = "ADMIN";return L_ERROR0; //ADMIN GET
		}else{
			return "Error : Header >> <rollratg.h> << FUNCTION _DATA_SET (...,int __STD_NUM_RE)... CODE : 0xF001 IMPORMATION : Please check the ADMIN POINTER";
		}
	}else if (__STD_NUM_RD == "CHECKER"){
		if (__STD_NUM_RE == 9654332){
			SO.fptr = "ADMIN";return L_ERROR0; //ADMIN GET
		}else{
			return "Error : Header >> <rollratg.h> << FUNCTION _DATA_SET (...,int __STD_NUM_RE)... CODE : 0xF013 IMPORMATION : Please check the ADMIN POINTER";
		}
	}else{
		return "Error : Header >> <rollratg.h> << FUNCTION _DATA_SET (...,int __STD_NUM_RE)... CODE : 0xA001 IMPORMATION : Please check the ADMIN POINTER";
	}
}
char* _DATA_READ(char __STD_NUM_RD[],int __STD_NUM_RE) //ADMIN
{
	if (__STD_NUM_RD == "LOGIN"){
		SO.loginfor = "READED";
		return D_SOLVE;
	}else if (__STD_NUM_RD == "ADMIN" && SO.fold != "ADMIN"){
		return L_ERROR1;
	}else{
		return "Error : Header >> <rollratg.h> << FUNCTION _DATA_READ (...,char __STD_NUM_RD[])... CODE : 0xF009 IMPORMATION : Please check the ADMIN POINTER";
	}
}
char* _DATA_SERCHER(int __RETURN_SO,int __RETURN_CO) //ADMIN
{
	if (__RETURN_SO == 0){
		if (__RETURN_CO == 0){
			return "Error : Header >> <rollratg.h> << FUNCTION _DATA_READ (...,int __RETURN_SO,int __RETURN_CO)... CODE : 0xF005 IMPORMATION : Please check the ADMIN POINTER";
		}else if(__RETURN_CO == 1){
			return "Error : Header >> <rollratg.h> << FUNCTION _DATA_READ (...,int __RETURN_SO,int __RETURN_CO)... CODE : 0xF006 IMPORMATION : Please check the ADMIN POINTER";
		}
	}else if (__RETURN_SO ==1){
		if (__RETURN_CO == 0){
			return "Error : Header >> <rollratg.h> << FUNCTION _DATA_READ (...,int __RETURN_SO,int __RETURN_CO)... CODE : 0xF007 IMPORMATION : Please check the ADMIN POINTER";
		}else if(__RETURN_CO == 1){
			return "Error : Header >> <rollratg.h> << FUNCTION _DATA_READ (...,int __RETURN_SO,int __RETURN_CO)... CODE : 0xF008 IMPORMATION : Please check the ADMIN POINTER";
		}
	}
}
char* _DATA_COME(char __SOLVE_ERROR_RD[],int __ERROR_CODE) //ADMIN
{
	if (SO.fold != "ADMIN"){
		return "Error : Header >> <rollratg.h> << FUNCTION _DATA_COME (...,char __SOLVE_ERROR_RD[])... CODE : 0xF009 IMPORMATION : Please check the ADMIN POINTER";
	}else{
		SO.come = "ADMIN";
		return L_ERROR0;
	}
}
//..., end of _ANALYSIS_I_DATA_
#endif

#ifndef __ROLLRATCALCULATION__ // Don't have to #include <rcalc.h>
#define __ROLLRATCALCULATION__ // If you were including this header, the header is ignored.

#define E 2.71828182845904523536
#define PI 3.14159265358979323846
#define RATIO 0.01745329251994329576923690768489
#define Tf(x) Div(square(__GET_Formager, x), fact(x))
#define Tff(x, y, z) Div(square(__GET_Formager, x) * y, fact(z))

struct _instruct_calcfloat{
	long double FF;
	long double SF;
	long double LF;
}calcf;

int Rand(){static int Random = 1;Random = ((Random * 11012542565354 + 221504)/336524)%998547;return Random;}

long double Add(long double __GET_FD, long double __GET_SD){
	return __GET_FD + __GET_SD;}
long double Sub(long double __GET_FD, long double __GET_SD){
	return __GET_FD - __GET_SD;}
long double Mul(long double __GET_FD, long double __GET_SD){
	return __GET_FD * __GET_SD;}
long double Div(long double __GET_FD, long double __GET_SD){
	return __GET_FD / __GET_SD;}

long double reci(long double __GET_FD){
	return 1 / __GET_FD;}
long double sqrt(long double __GET_Formage, long double r = 1){
	if( __GET_Formage * __GET_Formage-__GET_Formage > -0.5 && __GET_Formage * __GET_Formage-__GET_Formage < 0.5 ){
		return r;}return sqrt(__GET_Formage , ( __GET_Formage / r + r ) / 2);}
long double fact(long double __GET_Formager){
	long double i;if(__GET_Formager>=2){
		i=__GET_Formager*fact(__GET_Formager-1);}else{i=1;}return i;}
long double square(long double __GET_FD, long double __GET_SD){
	calcf.SF = 1;while(__GET_SD > 0){calcf.SF = __GET_FD * calcf.SF;__GET_SD--;}return calcf.SF;}
long double sin(long double __GET_Formager){
	__GET_Formager *= RATIO;return __GET_Formager - Tf(3) + Tf(5) - Tf(7) + Tf(9) - Tf(11);}
long double cos(long double __GET_Formager){
	__GET_Formager *= RATIO;return 1 - Tf(2) + Tf(4) - Tf(6) + Tf(8) - Tf(10);}
long double tan(long double __GET_Formager){
	__GET_Formager *= RATIO;return Tff(1,1,1) + Tff(2,3,3) + Tff(16,5,5) + Tff(272,7,7) + Tff(7936,9,9);}
long double nl(long double __GET_Formager){
	return 1 + Tf(1) + Tf(2) + Tf(3) + Tf(4) + Tf(5);}
long double in(long double __GET_Formager){
	return Tf(1) - Tf(2) + Tf(3) - Tf(4) + Tf(5) - Tf(6);}
long double log(long double __GET_Formager){
	return Div(in(__GET_Formager),2.30258);}
long double Solver(long double __GET_A,long double __GET_B,long double __GET_C){
	calcf.SF = __GET_B * __GET_B - 4 * __GET_A * __GET_C;if (calcf.SF < 0){
		return 0xFFFFFFFE;}else if (calcf.SF > 0){return -__GET_B + sqrt(calcf.SF)/(2 * __GET_A);
		}else if (calcf.SF == 0){return -(Div(__GET_C,__GET_A));}else{return 0xFFFFFFFF;}}
long double solve(long double __GET_Formager,long double __GET_Type,long double __GET_A,long double __GET_B,long double __GET_C,long double __GET_D){
	if (__GET_Type == 0){if (__GET_Formager == 2){return Solver(__GET_A,__GET_B,__GET_C);}else if (__GET_Formager == 3){return 0;}}}
#endif // End of ROLLRAT CALULATION 3.103.4 Version DATA SECTOR

#ifndef __CALL_FUNCTION__
#define __CALL_FUNCTION__
char* __CALL_FF(char _READ_DATA_[],int RR)
{
	return &_READ_DATA_[RR];
}
char* __CALL_CF(char _READ_DATA_[],int RR)
{
	if (_READ_DATA_ == "F"){
		int _INT_I_;
		for (_INT_I_=0;_INT_I_=6;_INT_I_++){
			if  (_TOOL_INT_SUM(RR,_INT_I_,1) == 300){
				__SHOR__COM__("L0");
				return L_ERROR0;
			}
		}
	}else if (_READ_DATA_ == "G"){
		int _INT_I_;
		for (_INT_I_=0;_INT_I_=12;_INT_I_++){
			if  (_TOOL_INT_SUM(RR,_INT_I_,1) == 300){
				__SHOR__COM__("L0");
				return L_ERROR0;
			}
	    }
	}else if (_READ_DATA_ == "H"){
		int _INT_I_;
		for (_INT_I_=0;_INT_I_=32;_INT_I_++){
			if  (_TOOL_INT_SUM(RR,_INT_I_,1) == 300){
				__SHOR__COM__("L0");
				return L_ERROR0;
			}
	    }
	}else if (_READ_DATA_ == "I"){
		int _INT_I_;
		for (_INT_I_=0;_INT_I_=64;_INT_I_++){
			if  (_TOOL_INT_SUM(RR,_INT_I_,1) == 300){
				__SHOR__COM__("L0");
				return L_ERROR0;
			}
	    }
	}else if (_READ_DATA_ == "J"){
		int _INT_I_;
		for (_INT_I_=0;_INT_I_=128;_INT_I_++){
			if  (_TOOL_INT_SUM(RR,_INT_I_,1) == 300){
				__SHOR__COM__("L0");
				return L_ERROR0;
			}
	    }
	}
	return "Error : Header >> <rollratg.h> << FUNCTION _DATA_READ (...,int __RETURN_SO,int __RETURN_CO)... CODE : 0xB001 IMPORMATION : Please check the ADMIN POINTER";
}

#endif

#ifndef __ERROR_SERCHER__ //Error Impormation Library
#define __ERROR_SERCHER__
char* __RECHER__IMPOMATION__(int __ERROR_CODE,char __FUNCTION__CHAR[],char __HEADER__CHAR[],int __TYPE_NUM)
{
	if (__ERROR_CODE > 0xF000){
		if (__FUNCTION__CHAR == "_DATA_SET"){
			if (__HEADER__CHAR == "<rollratg.h>"){
				if (__TYPE_NUM == 1){
					return "This error occurs when there is no reference to return value as an error function.";
				}else if (__TYPE_NUM == 13){
					return "This error occurs when there is no reference to return value as an error function.";
				}
			}
		}else if(__FUNCTION__CHAR == "_DATA_READ"){
			if (__HEADER__CHAR == "<rollratg.h>"){
				if (__TYPE_NUM == 9){
					return "You failed to get the \"Admin\" privileges.First obtained your permission.";
				}
			}
		}else if(__FUNCTION__CHAR == "_DATA_SERCHER"){
			if (__HEADER__CHAR == "<rollratg.h>"){
				if (__TYPE_NUM == 5){
					return "Return standard data \"zero\" if the value can not be interpreted.";
				}else if (__TYPE_NUM == 6){
					return "Return standard data \"zero\" if the value can not be interpreted.";
				}else if (__TYPE_NUM == 7){
					return "Return standard data \"zero\" if the value can not be interpreted.";
				}else if (__TYPE_NUM == 8){
					return "Return standard data \"zero\" if the value can not be interpreted.";
				}
			}
		}
	}else if(__ERROR_CODE < 0xF000){
		if (__FUNCTION__CHAR == "_DATA_SET"){
			if (__HEADER__CHAR == "<rollratg.h>"){
				if (__TYPE_NUM == 1){
					return "This error occurs when you receive a phenomenon that does not function to return a pre-prepared.";
				}
			}
		}
	}
}
#endif

#ifndef __ROLLRATCALCULATION__ //Random seed extract function
#define __ROLLRATCALCULATION__ 
#define E 2.71828182845904523536
#define PI 3.14159265358979323846
#define RATIO 0.01745329251994329576923690768489
#define Tf(x) Div(square(__GET_Formager, x), fact(x))
#define Tff(x, y, z) Div(square(__GET_Formager, x) * y, fact(z))
struct _instruct_calcfloat{
	long double FF;
	long double SF;
	long double LF;
}calcf;
long double Div(long double __GET_FD, long double __GET_SD){
	return __GET_FD / __GET_SD;}
long double square(long double __GET_FD, long double __GET_SD){
	calcf.SF = 1;while(__GET_SD > 0){calcf.SF = __GET_FD * calcf.SF;__GET_SD--;}return calcf.SF;}
int Rand(){static int Random = 1;Random = ((Random * 11012542565354 + 221504)/336524)%998547;return Random;} //random seed
#endif
#endif

#undef True
#undef False

#endif