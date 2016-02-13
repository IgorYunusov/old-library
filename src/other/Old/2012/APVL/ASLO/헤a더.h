/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Version : 1.110.0							                               ********
 ********       Header : <rio.h> 					                                 	   ********
 ********										                                           ********
 ********       Copyright ¨Ï ROLLRAT. All Rights Reserved.				                   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/

#ifndef _R_IO_
#ifndef $
#define $ 0
#define $$ 1
#endif

#define _R_IO_
#ifndef _R_IO_CLASS_IO_STANDARD_
struct SO{char *Password;char *Republiccharge;}SO;
#define _R_IO_CLASS_IO_STANDARD_
class RIO{public: void GET(char _GET_CHAR_[],char _GET_CHAR_CH_[]);char* OUT(int _GET_TYPE_);private: char* stGetA;char* stGetB;};
inline void RIO::GET(char _GET_CHAR_[],char _GET_CHAR_CH_[]){RIO::stGetA = _GET_CHAR_;RIO::stGetB = _GET_CHAR_CH_;}
inline char* RIO::OUT(int _GET_TYPE_){if (_GET_TYPE_ == $){return RIO::stGetA;}else if (_GET_TYPE_ == $$){return RIO::stGetB;}else{return (char*)$;}}
#endif
#ifndef _R_IO_CLASS_I_
#define _R_IO_CLASS_I_
class RI{public:void ReChar(char _GET_I_[]){SO.Republiccharge = _GET_I_;};void Password(char _GET_I_[]){SO.Password = _GET_I_;};void GET(char _GET_I_[]);};
inline void RI::GET(char _GET_I_[]){RI::ReChar(_GET_I_);}
#endif
#ifndef _R_IO_CLASS_O_
#define _R_IO_CLASS_O_
class RO{public:char* OUT(int _GET_ID_);};
inline char* RO::OUT(int _GET_ID_){if (_GET_ID_ == $){return SO.Republiccharge;}else if (_GET_ID_ == $$){return SO.Password;}}
#endif
#endif
#ifndef _R_SAVER_O_
#define _R_SAVER_O_ //LEVLE 1
struct AIO1{
	int PointSet;
	int F;
	char *DATA[100];
}ts;
namespace SAVERO
{
	void POINT(int _Point_)
	{
		ts.F += 1;
		ts.PointSet = _Point_;}
	void SET(char _Saving_[])
	{
		ts.F += 1;
		ts.DATA[ts.PointSet] = _Saving_;
	}
	char* GET(int _Point_)
	{
		ts.F += 1;
		return ts.DATA[_Point_];
	}
	int GET_F()
	{
		return ts.F;
	}
}
#endif
#ifndef _R_SAVER_T_
#define _R_SAVER_T_ //LEVLE 2
struct AIO2{
	int PointSet;
	int PointSetT;
	int F;
	char *DATA[100][100];
}tss;
namespace SAVERT
{
	void POINT(int _Point_,int _Point_T_)
	{
		tss.F += 1;
		tss.PointSet = _Point_;
		tss.PointSetT = _Point_T_;
	}
	void SET(char _Saving_[])
	{
		tss.F += 1;
		tss.DATA[tss.PointSet][tss.PointSetT] = _Saving_;
	}
	char* GET(int _Point_,int _Point_T_)
	{
		tss.F += 1;
		return tss.DATA[_Point_][_Point_T_];
	}
	int GET_F()
	{
		return ts.F;
	}
}
#endif
#ifndef _R_SAVER_H_
#define _R_SAVER_H_ //LEVLE 3
struct AIO3{
	int PointSet;
	int PointSetT;
	int PointSetH;
	int F;
	char *DATA[100][100][100];
}tsss;
namespace SAVERH
{
	void POINT(int _Point_,int _Point_T_,int _Point_H_)
	{
		tsss.F += 1;
		tsss.PointSet = _Point_;
		tsss.PointSetT = _Point_T_;
		tsss.PointSetH = _Point_H_;
	}
	void SET(char _Saving_[])
	{
		tsss.F += 1;
		tsss.DATA[tsss.PointSet][tsss.PointSetT][tsss.PointSetH] = _Saving_;
	}
	char* GET(int _Point_,int _Point_T_,int _Point_H_)
	{
		tsss.F += 1;
		return tsss.DATA[_Point_][_Point_T_][_Point_H_];
	}
	int GET_F()
	{
		return tsss.F;
	}
}
#endif
#ifndef _R_SAVER_F_
#define _R_SAVER_F_ //LEVLE 4
struct AIO4{
	int PointSet;
	int PointSetT;
	int PointSetH;
	int PointSetF;
	int F;
	char *DATA[100][100][100][100];
}tssss;
namespace SAVERF
{
	void POINT(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_)
	{
		tssss.F += 1;
		tssss.PointSet = _Point_;
		tssss.PointSetT = _Point_T_;
		tssss.PointSetH = _Point_H_;
		tssss.PointSetF = _Point_F_;
	}
	void SET(char _Saving_[])
	{
		tssss.F += 1;
		tssss.DATA[tssss.PointSet][tssss.PointSetT][tssss.PointSetH][tssss.PointSetF] = _Saving_;
	}
	char* GET(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_)
	{
		tssss.F += 1;
		return tssss.DATA[_Point_][_Point_T_][_Point_H_][_Point_F_];
	}
	int GET_F()
	{
		return tssss.F;
	}
}
#endif
#ifndef _R_SAVER_I_
#define _R_SAVER_I_ //LEVLE 5
struct AIO5{
	int PointSet;
	int PointSetT;
	int PointSetH;
	int PointSetF;
	int PointSetI;
	int F;
	char *DATA[100][100][100][10][10]; // 0x7ffffffff Error ! x64 OS Only
}tsssss;
namespace SAVERI
{
	void POINT(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_,int _Point_I_)
	{
		tsssss.F += 1;
		tsssss.PointSet = _Point_;
		tsssss.PointSetT = _Point_T_;
		tsssss.PointSetH = _Point_H_;
		tsssss.PointSetF = _Point_F_;
		tsssss.PointSetT = _Point_I_;
	}
	void SET(char _Saving_[])
	{
		tsssss.F += 1;
		tsssss.DATA[tsssss.PointSet][tsssss.PointSetT][tsssss.PointSetH][tsssss.PointSetF][tsssss.PointSetI] = _Saving_;
	}
	char* GET(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_,int _Point_I_)
	{
		tsssss.F += 1;
		return tsssss.DATA[_Point_][_Point_T_][_Point_H_][_Point_F_][_Point_I_];
	}
	int GET_F()
	{
		return tsssss.F;
	}
}
#endif
#ifndef _R_SAVER_S_
#define _R_SAVER_S_ //LEVLE 6
struct AIO6{
	int PointSet;
	int PointSetT;
	int PointSetH;
	int PointSetF;
	int PointSetI;
	int PointSetS;
	int F;
	char *DATA[100][100][10][10][10][10]; // 0x7ffffffff Error ! x64 OS Only
}tssssss;
namespace SAVERS
{
	void POINT(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_,int _Point_I_,int _Point_S_)
	{
		tssssss.F += 1;
		tssssss.PointSet = _Point_;
		tssssss.PointSetT = _Point_T_;
		tssssss.PointSetH = _Point_H_;
		tssssss.PointSetF = _Point_F_;
		tssssss.PointSetT = _Point_I_;
		tssssss.PointSetS = _Point_S_;
	}
	void SET(char _Saving_[])
	{
		tssssss.F += 1;
		tssssss.DATA[tssssss.PointSet][tssssss.PointSetT][tssssss.PointSetH][tsssss.PointSetF][tssssss.PointSetI][tssssss.PointSetS] = _Saving_;
	}
	char* GET(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_,int _Point_I_,int _Point_S_)
	{
		tssssss.F += 1;
		return tssssss.DATA[_Point_][_Point_T_][_Point_H_][_Point_F_][_Point_I_][_Point_S_];
	}
	int GET_F()
	{
		return tssssss.F;
	}
}
#endif
#ifndef _R_SAVER_E_
#define _R_SAVER_E_ //LEVLE 7
struct AIO7{
	int PointSet;
	int PointSetT;
	int PointSetH;
	int PointSetF;
	int PointSetI;
	int PointSetS;
	int PointSetE;
	int F;
	char *DATA[100][10][10][10][10][10][10]; // 0x7ffffffff Error ! x64 OS Only
}tsssssss;
namespace SAVERE
{
	void POINT(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_,int _Point_I_,int _Point_S_,int _Point_E_)
	{
		tsssssss.F += 1;
		tsssssss.PointSet = _Point_;
		tsssssss.PointSetT = _Point_T_;
		tsssssss.PointSetH = _Point_H_;
		tsssssss.PointSetF = _Point_F_;
		tsssssss.PointSetT = _Point_I_;
		tsssssss.PointSetS = _Point_S_;
		tsssssss.PointSetE = _Point_E_;
	}
	void SET(char _Saving_[])
	{
		tsssssss.F += 1;
		tsssssss.DATA[tsssssss.PointSet][tsssssss.PointSetT][tsssssss.PointSetH][tssssss.PointSetF][tsssssss.PointSetI][tsssssss.PointSetS][tsssssss.PointSetE] = _Saving_;
	}
	char* GET(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_,int _Point_I_,int _Point_S_,int _Point_E_)
	{
		tsssssss.F += 1;
		return tsssssss.DATA[_Point_][_Point_T_][_Point_H_][_Point_F_][_Point_I_][_Point_S_][_Point_E_];
	}
	int GET_F()
	{
		return tsssssss.F;
	}
}
#endif

/*
 * Read Me. x86 OS can't not be this 8-dimensional array
 *
 * The reason for the run.
 *
 */
/*
#ifndef _R_SAVER_G_
#define _R_SAVER_G_ //LEVLE 8
struct AIO8{
	int PointSet;
	int PointSetT;
	int PointSetH;
	int PointSetF;
	int PointSetI;
	int PointSetS;
	int PointSetE;
	int PointSetG;
	int F;
	char *DATA[10][10][10][10][10][10][10][10]; // 0x7ffffffff Error ! x64 OS Only
}tssssssss;
namespace SAVERG
{
	void POINT(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_,int _Point_I_,int _Point_S_,int _Point_E_,int _Point_G_)
	{
		tssssssss.F += 1;
		tssssssss.PointSet = _Point_;
		tssssssss.PointSetT = _Point_T_;
		tssssssss.PointSetH = _Point_H_;
		tssssssss.PointSetF = _Point_F_;
		tssssssss.PointSetT = _Point_I_;
		tssssssss.PointSetS = _Point_S_;
		tssssssss.PointSetE = _Point_E_;
		tssssssss.PointSetG = _Point_G_;
	}
	void SET(char _Saving_[])
	{
		tssssssss.F += 1;
		tssssssss.DATA[tssssssss.PointSet][tssssssss.PointSetT][tssssssss.PointSetH][tsssssss.PointSetF][tssssssss.PointSetI][tssssssss.PointSetS][tssssssss.PointSetE][tssssssss.PointSetG] = _Saving_;
	}
	char* GET(int _Point_,int _Point_T_,int _Point_H_,int _Point_F_,int _Point_I_,int _Point_S_,int _Point_E_,int _Point_G_)
	{
		tssssssss.F += 1;
		return tssssssss.DATA[_Point_][_Point_T_][_Point_H_][_Point_F_][_Point_I_][_Point_S_][_Point_E_][_Point_G_];
	}
	int GET_F()
	{
		return tsssssss.F;
	}
}
#endif
*/