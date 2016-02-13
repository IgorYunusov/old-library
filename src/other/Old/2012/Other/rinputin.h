/*

   rollrat < inputin.h >
   °øºÎ¿ë

 */
#define _r_input_in_
#pragma once
#if !defined(_R_input_in_)
#define _R_input_in_
#define buffer 1000

#define _input_imp_

#define _input_(_) extending(_)
#define _input_menu_(_) menu(_)
#define _input_r_(_) rollrat(_)
#define _input_r_include_(_) include(_)
#define _input_r_header_(_) header(_)
#define _input_r_hear_(_) out(_)
#define _input_r_header_ea_(_) extenda(_)
#define _input_r_header_ex_(_) extend(_)

#define _R_RINKPUTING_

#define _re_input_ extend(1)
#define _e_input_ extend(0)
#define _ifover_(_,__) _ifover_(_,__)
#define _t_ifover_ _ifover_(0,0)

int ifover(int i, int o);

#define _inline_input_d_

inline int extend(int _in_){if (_in_ == 0){return 1;}else if (_in_ == 1){return 0;}else return -1;}
inline int extending(int _inccc){return _input_r_header_ex_(_inccc);}
inline void menu(int _switch){if (ifover(_switch,0) == 1) _switch = 10;else _switch = 9;}
inline int ifover(int i, int o){if (i == o){return 0;}else{return 1;}}
//inline void rollrat(char Get[]){if (Get == "lincense") Get = "no lincense"; else if (Get == "name") Get = "rollrat"; else Get = "error";}
//inline int serch(char Get[],int Get_){return 0;}; // mody
//inline void include(char including[]){ if (ifover(serch(including,0),0) == 1) including = "error";else including = "successful";}

#define _R_INCLUDE_

#define _serch_R_(_h_) including(_h_)

template<class TypeNone>
TypeNone including(TypeNone _GET_,TypeNone _GOT_){
	if (_GET_ == 0x999)
		return _GOT_;
	else if (_GET_ == 0x001)
		return _GOT_;
}



#define _R_SAVE_

#define _inc_(_h) _incc(_h)
#define _Set_Def_
struct _saver_{
	void OIL001();
	void OIL002();
	void OIL003();
	void OIL004();
	void OIL005();
	void OIL006();
	void OIL007();
	void OIL008();
	void OIL009();
	void OIL00A();
	void OILRESET();
}tsc;
void OULRESET(){

}

inline void _Set_D_(int _h){if (_h > 100) _h = 0;else _h = -1;}
inline void _Set_R_(){tsc.OILRESET();}

#define _R_SWITCH_

#define _r_on_
struct _switch_{
	int onoff;
	int _s_return();
}s;

inline int _s_return(){return s.onoff;}
inline void _switch_on_(){s.onoff = 1;}
inline void _switch_off_(){s.onoff = 0;}

#define _s_on_ _switch_on_
#define _s_off_ _switch_off_

#define R
#endif
