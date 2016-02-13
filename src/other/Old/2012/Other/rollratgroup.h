/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Version : 3.001.6							                               ********
 ********       Header : <rollratgroup.h>      					                           ********
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

inline char *ADD(char _GET_[], char _GET_T_[]) {char *r=_GET_;while(*_GET_) ++_GET_;while(*_GET_T_) *_GET_++=*_GET_T_++;*_GET_=0;return r;}
inline char *STRCAT(char _GET_[10000000],char _GET_T_[10000000]){return ADD(_GET_,_GET_T_);}
inline void _INT_CHAR_(int _GET_, char buffer[11]){int i, j, cnt = 0;int tempnum = _GET_;for ( i = 0 ; i < 12; i ++ ){if ( tempnum != 0 ) {cnt ++;tempnum = tempnum / 10;}else if ( tempnum == 0 ) {break;}}buffer[cnt] = '\0';for ( j = cnt-1 ; j >= 0 ; j-- ) {buffer[j] = _GET_ % 10 + '0';_GET_ = _GET_ / 10 ;}}

inline char *GET(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_){ts.F += 1;return ts.DATA[_Point_][_Point_T_][_Point_H_][_Point_F_];}int GET_F(){return ts.F;}
inline void POINT(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_){ts.F += 1;ts.PointSet = _Point_;ts.PointSetT = _Point_T_;ts.PointSetH = _Point_H_;ts.PointSetF = _Point_F_;}
inline void SET(char _Saving_[]){ts.F += 1;ts.DATA[ts.PointSet][ts.PointSetT][ts.PointSetH][ts.PointSetF] = _Saving_;}
inline void PUT(char _GET_[]){int c,e,f,g; for (c=0;c<=M_Char;c++){for (e=0;e<=M_Char;e++){for (f=0;f<=M_Char;f++){for (g=0;g<=M_Char;g++){POINT(g,f,e,c);SET(_GET_);}}}}}
inline void CLS(){int c,e,f,g; for (c=0;c<=M_Char;c++){for (e=0;e<=M_Char;e++){for (f=0;f<=M_Char;f++){for (g=0;g<=M_Char;g++){POINT(g,f,e,c);SET(NULL);}}}}}
inline void FINDER(char _GET_[]){int c,e,f,g;for (c=0;c<=M_Char;c++){for (e=0;e<=M_Char;e++){for (f=0;f<=M_Char;f++){for (g=0;g<=M_Char;g++){if ( _GET_ = GET(g,f,e,c)){ts.PointSet = g;ts.PointSetT = f;ts.PointSetH = e;ts.PointSetF = c;goto END;}}}}}END:;}

inline int SAME(char _GET_[],char _GET_T_[]){if (_GET_ = _GET_T_){return 0;}else{return 1;}}
inline void NEXT(int _GET_){ap.Dual += _GET_;}
inline int NGET(){return ap.Dual;}
inline void NRESET(){ap.Dual = 0;}
inline void SETXY(long double X, long double Y){ap.X = X; ap.Y = Y;}
inline long double GETXY(int _GET_){if (_GET_ == 0){return ap.X;}else{return ap.Y;}}
inline void _SET(char _GET_[]){ap.Get = _GET_;}
inline char* _GET(){return ap.Get;}
inline long double _ADD(long double X, long double Y){ap.Prev = X + Y;return X + Y;}
inline long double _SUB(long double X, long double Y){ap.Prev = X - Y;return X - Y;}
inline long double _MUL(long double X, long double Y){ap.Prev = X * Y;return X * Y;}
inline long double _DIV(long double X, long double Y){ap.Prev = X / Y;return X / Y;}
inline long double __GET(){return ap.Prev;}
inline char *_STRCAT(char _GET_[],char _GET_T_[],char _GET_H_[]){return STRCAT(STRCAT(_GET_,_GET_T_),_GET_H_);}
inline char *__STRCAT(char _GET_[],char _GET_T_[],char _GET_H_[],char _GET_F_[]){return STRCAT (STRCAT(STRCAT(_GET_,_GET_T_),_GET_H_),_GET_F_);}

#endif
#endif

/*
 * Update << rollratgroup.h >>
 *
 * < 1.045.0 > The initial version          << 2012 - 10 - 06  11 : 59 PM >>
 *    + A four-dimensional array controller
 *    + String a simple analysis tools
 *
 * < 1.250.0 >					            << 2012 - 10 - 07  02 : 50 PM >>
 *    + String to _INT_CHAR_ (upgrade)
 *
 * < 2.250.9 >					            << 2012 - 10 - 07  07 : 52 PM >> 
 *    + Others namespace
 * 
 * < 3.001.6 >					            << 2012 - 10 - 09  10 : 50 PM >> 
 *    + Speed up FINDER
 *    - Namespace ::SAVER,::STRING,::OTHERS
 *
 *
 * ROLLRAT HEADER
 * Is to use multiple arrays to substitute the name 'namespace' and copy the entire.
 *
Ver_
 3.001.6*/