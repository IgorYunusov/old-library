/******** 
 ********       long double V
 ********        
 ********       ROLLRAT SOFT WARE HEADER
 ********       SINCE : 2009 - 2012
 ********
 ********       Impormation : RollRat Calculation Tool Group Header
 ********       Version : 2.040.3
 ********       Header : <rlongdoublecalc.h>
 ********
 ********       [Public Project]
 ********
 ********       Copyright ¨Ï ROLLRAT. All Rights Reserved.
 ********              
 ********
 *******************************************************************************************
 *******************************************************************************************
 *******************************************************************************************/

#ifndef __ROLLRATCALCULATION__
#define __ROLLRATCALCULATION__
#define E 2.71828182845904523536
#define PI 3.14159265358979323846
#define RATIO 0.01745329251994329576923690768489
#define Tf(x) Div(square(__GET_Formager, x), fact(x))
#define Tff(x, y, z) Div(square(__GET_Formager, x) * y, fact(z))
//struct _instruct_calcint{int FD;int SD;int LD;}calci;
//struct _instruct_calcdouble{float FO;float SO;float LO;}calcd;
struct _instruct_calcfloat{long double FF;long double SF;long double LF;}calcf;
long double Add(long double __GET_FD, long double __GET_SD){return __GET_FD + __GET_SD;}
long double Sub(long double __GET_FD, long double __GET_SD){return __GET_FD - __GET_SD;}
long double Mul(long double __GET_FD, long double __GET_SD){return __GET_FD * __GET_SD;}
long double Div(long double __GET_FD, long double __GET_SD){return __GET_FD / __GET_SD;}
long double reci(long double __GET_FD){return 1 / __GET_FD;}
long double sqrt(long double __GET_Formage, long double r = 1){if( __GET_Formage * __GET_Formage-__GET_Formage > -0.5 && __GET_Formage * __GET_Formage-__GET_Formage < 0.5 ){return r;}return sqrt(__GET_Formage , ( __GET_Formage / r + r ) / 2);}
long double fact(long double __GET_Formager){long double i;if(__GET_Formager>=2){i=__GET_Formager*fact(__GET_Formager-1);}else{i=1;}return i;}
long double square(long double __GET_FD, long double __GET_SD){calcf.SF = 1;while(__GET_SD > 0){calcf.SF = __GET_FD * calcf.SF;__GET_SD--;}return calcf.SF;}
long double sin(long double __GET_Formager){__GET_Formager *= RATIO;return __GET_Formager - Tf(3) + Tf(5) - Tf(7) + Tf(9) - Tf(11);}
long double cos(long double __GET_Formager){__GET_Formager *= RATIO;return 1 - Tf(2) + Tf(4) - Tf(6) + Tf(8) - Tf(10);}
long double tan(long double __GET_Formager){__GET_Formager *= RATIO;return Tff(1,1,1) + Tff(2,3,3) + Tff(16,5,5) + Tff(272,7,7) + Tff(7936,9,9)/* + Tff(353792,11,11) + Tff(22368256,13,13)*/;}
long double nl(long double __GET_Formager){return 1 + Tf(1) + Tf(2) + Tf(3) + Tf(4) + Tf(5);}
long double in(long double __GET_Formager){return Tf(1) - Tf(2) + Tf(3) - Tf(4) + Tf(5) - Tf(6);}
long double log(long double __GET_Formager){return Div(in(__GET_Formager),2.30258);}
long double Solver(long double __GET_A,long double __GET_B,long double __GET_C){calcf.SF = __GET_B * __GET_B - 4 * __GET_A * __GET_C;if (calcf.SF < 0){return 0xFFFFFFFE;}else if (calcf.SF > 0){return -__GET_B + sqrt(calcf.SF)/(2 * __GET_A);}else if (calcf.SF == 0){return -(Div(__GET_C,__GET_A));}else{return 0xFFFFFFFF;}}
long double Solver3(long double __GET_A,long double __GET_B,long double __GET_C,long double __GET_D){return 0;}
long double solve(long double __GET_Formager,long double __GET_Type,long double __GET_A,long double __GET_B,long double __GET_C,long double __GET_D){if (__GET_Type == 0){if (__GET_Formager == 2){return Solver(__GET_A,__GET_B,__GET_C);}else if (__GET_Formager == 3){return 0;}}}
#endif