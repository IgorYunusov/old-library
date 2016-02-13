/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********		Start : 2012 10 10 PM 11 : 18											   ********
 ********										                                           ********
 ********       Version : 1.250.0							                               ********
 ********       Header : <Rollrat.h>      					                               ********
 ********										                                           ********
 ********       Copyright (c) ROLLRAT. All Rights Reserved.								   ********
 ********		This header made by rollrat.										       ********
 ********		The header is Rollrat Os Project			                               ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/

#ifndef _r_def_no_
#define _r_def_no_
#endif

#if !defined(_Free_Consurting_) && !defined(_Free_Comsur_Consurting_)
#define _Free_Consurting_
#define _Free_Comsur_Consurting_

#if !defined(_r_lod_Poly_)
#define _Deleting_Function_
#define _r_lod_Poly_
#endif

#ifndef _R_C_Switch_
#define _R_C_Switch_
struct _C_Switch{
	char* Def;
	char* Sof;
	int Status;
	void Switch_On();
	void Switch_Off();
	void Def_Set(char _Set_Data_[]);
	void Sof_Set(char _Get_Data_[]);
	int Get_Status();
}cs;

inline void Switch_On(){cs.Status = 1;}
inline void Switch_Off(){cs.Status = 0;}
inline int Get_Status(){return cs.Status;}
inline void Def_Set(char _Get_Data_[]){cs.Def = _Get_Data_;}
inline void Sof_Set(char _Get_Data_[]){cs.Sof = _Get_Data_;}
inline char*Get_Def(){return cs.Def;}
inline char*Get_Sof(){return cs.Sof;}

#define GetSwtichStatuc Get_Status
#define SwitchOn Switch_On
#define SwitchOff Switch_Off
#define DefSet(_) Def_Set(_)
#define SofSet(_) Sof_Set(_)
#define GetDef Get_Def
#define GetSof Get_Sof

#endif
#endif