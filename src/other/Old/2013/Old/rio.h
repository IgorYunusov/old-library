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
#define M_Char 100
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