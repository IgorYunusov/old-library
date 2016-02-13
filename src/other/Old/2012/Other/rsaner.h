/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Version : 6.016.2							                               ********
 ********       Header : <rsaner.h>      						                           ********
 ********										                                           ********
 ********       Copyright ¨Ï ROLLRAT. All Rights Reserved.				                   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/
#ifndef _R_GROUP_
#ifndef _R_CHAR_
#define M_Char 100
#define _R_CHAR_
struct AIO4{int PointSet;int PointSetT;int PointSetH;int PointSetF;int F;char *DATA[M_Char][M_Char][M_Char][M_Char];char *I;}ts;
struct AP1{int Dual;long double X, Y;char *Get;long double Prev;}ap;
char *ADD(char _GET_[], char _GET_T_[]) {char *r=_GET_;while(*_GET_) ++_GET_;while(*_GET_T_) *_GET_++=*_GET_T_++;*_GET_=0;return r;}
char *STRCAT(char _GET_[10000000],char _GET_T_[10000000]){return ADD(_GET_,_GET_T_);}
void _INT_CHAR_(int _GET_, char buffer[11]){int i, j, cnt = 0;int tempnum = _GET_;for ( i = 0 ; i < 12; i ++ ){if ( tempnum != 0 ) {cnt ++;tempnum = tempnum / 10;}else if ( tempnum == 0 ) {break;}}buffer[cnt] = '\0';for ( j = cnt-1 ; j >= 0 ; j-- ) {buffer[j] = _GET_ % 10 + '0';_GET_ = _GET_ / 10 ;}}
int SAME(char _GET_[],char _GET_T_[]){if (_GET_ = _GET_T_){return 0;}else{return 1;}}
void NEXT(int _GET_){ap.Dual += _GET_;}
int NGET(){return ap.Dual;}
void NRESET(){ap.Dual = 0;}
void SETXY(long double X, long double Y){ap.X = X; ap.Y = Y;}
long double GETXY(int _GET_){if (_GET_ == 0){return ap.X;}else{return ap.Y;}}
void _SET(char _GET_[]){ap.Get = _GET_;}
char* _GET(){return ap.Get;}
char *_STRCAT(char _GET_[],char _GET_T_[],char _GET_H_[]){return STRCAT(STRCAT(_GET_,_GET_T_),_GET_H_);}
char *__STRCAT(char _GET_[],char _GET_T_[],char _GET_H_[],char _GET_F_[]){return STRCAT (STRCAT(STRCAT(_GET_,_GET_T_),_GET_H_),_GET_F_);}
#endif
#endif
/*
 * ROLLRAT HEADER
 * Is to use multiple arrays to substitute the name 'namespace' and copy the entire.
 *
Ver_
 6.016.2*/