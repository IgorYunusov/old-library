// 운영체제나 프로그램이 한글을 포함하지않을시, 한글 주석은 모두 지우십시오.
/*

   Rollrat Software << lodefinitions.h >>

   공부용

 */
#define _r_lod_

#include "rinputin.h"

#pragma once

#define true 0
#define false 1

#if !defined(_lode_)
#define _lode_
//주석 모음(주석은 프로그램에 영향을 끼치지않습니다.)
//이 주석은 이하헤더에도 동일하게 적용됩니다.
//주석은 무시해도 됩니다.
#if !defined(_r_lod_list_)
#define lod             //처음에 위치
#define _single_        //싱글 코드
#define _other_         //다른 코드
#define _multi_         //멀티 코드
#define _r_sub_return_  //서브 리턴
#define _r_fun_return_  //함수 리턴
#define _r_sub_g_       //최고 순위에 위치함
#define _r_f_           //이게 들어가면 함수임 (생략될 수 있음)
#define _r_sub_r_       //리턴이 가능함 (생략될 수 있음)
#define _r_sub_r_e_     //리턴이 불 가능함 (생략될 수 있음)
#define _r_sub_r_j_     //리턴이 모호함
#define _r_sub_r_t_i_   //int 형식이 리턴됨
#define _r_sub_r_t_f_   //float 형식이 리턴됨
#define _r_sub_r_t_c_   //char 형식이 리턴됨
#define _r_sub_r_t_cl_  //char* 형식이 리턴됨
#define _r_sub_r_t_lf_  //long float 형식이 리턴됨
#define _r_sub_r_t_no_  //어쩃든 리턴됨
#define _r_sub_r_t_lf_  //특정값에만 리턴됨
#define _r_calc_        //계산을 사용함
#define _r_calc_c_      //4칙 연산을 사용함
#define _r_calc_sqrt_   //제곱근을 사용함
#define _r_calc_tf_     //삼각함수를 사용함
#define _r_calc_tb_     //삼각비를 사용함
#define _r_calc_hg_     //고등연산을 사용함 (sigma, solver 등)
#define _r_sub_c_c_     //함수중에 4칙연산이 존재함
#define _r_sub_c_hg_    //함수중에 고등연산이 존재함
#define _r_def_         //정의를 나타냄 (생략될 수 있음)
#define _r_def_r_       //값을 리턴하는 정의임
#define _r_def_s_       //구성하는 정의임
#define _r_def_c_       //계산과 관련된 정의임
#define _r_def_no_      //이 주석이 헤더의 처음에 있으면 그 헤더는 주석을 사용하지않음
#define _r_def_o_       //출력전용 정의임
#define _r_def_i_       //입력전용 정의임
#define _f_c_e_         //외부 헤더에서 가져온 함수임 (생략될 수 있음)
#define _f_r_           //함수가 읽기전용임
#define _f_s_s_         //함수가 저장함수임
#define _f_j_s_         //함수가 재귀함수임
#define _f_f_           //함수가 파일관련된 함수임 (생략될 수 있음) stdio.h
#define _f_h_e_         //함수가 자주사용됨
#define _j_e_           //데이터정의 주석임
#define _j_c_i_         //데이터가 char형태로 들어가고 int형식으로 나옴
#define _j_i_c_         //데이터가 int형태로 들어가고 char형식으로 나옴
#define _f_r_           //함수가 리터럴함수임
#define _a_l_           //알리고즘임
#define _o_e_           //함수가 os의 일부임
#define _o_e_j_         //함수가 os의 실행의 일부임
#define _b_l_           //부트로더임
#define _f_j_f_         //이단 함수임
#define _d_j_e_         //라이브러리함수임
#define _f_f_f_         //함수가 기본 헤더에 포함되는 함수임
#define _$Function      //함수안에서 정의됨. _r_def_no_ 주석이 선언이 되어있을떄 가능함
#define _$_$_f_         //알 수 없는 형식임
#endif
//이 모음에 없는 주석들은 다른 헤더에 포함되어있습니다.
//모음 끝

#if defined(_p_r_define_)
/* 지원하지않음  
#define include                  _load_include_(_h_)
#define load                     _load_include_(_load_)    
#define set                      _load_include_(_set_)
#define save                     _load_include_(_save_)
#define _load_                   _load_ex_(3)
#define _include_                _load_ex_(2)
#define _set_                    _load_ex_(0)
#define _save_                   _load_ex_(1)
#define _load_include_(_h_)      _input_r_header_(_h_)
#define _load_ex_(_h_)           _input_r_header_ex_(_h_)
*/
#else
#if !defined(_r_return_Set_)
#define _r_return_Set_
_r_return_Set_ _multi_ _r_input_in_ lod _R_input_in_ _R_RINKPUTING_ _inline_input_d_ int _Set_r_On_(){return _re_input_;}; 
_r_return_Set_ _multi_ _r_input_in_ _R_input_in_ _R_RINKPUTING_ _inline_input_d_ int _Set_r_Off_(){return _e_input_;}; 
#endif
#define _On_ _single_ _r_sub_g_ _Set_r_On_
#define _Off_ _single_ _r_sub_g_ _Set_r_Off_
#define _if_(_,__)  _ifover_(_,__)
#define __s_return_ __return
_r_return_Set_ _multi_ _single_ _r_input_in_ lod _R_input_in_ _inline_input_d_ _R_SWITCH_ _r_on_ void _switch_r_on_(){_s_on_;}; 
_r_return_Set_ _single_ _r_input_in_ _R_input_in_ _inline_input_d_ _R_SWITCH_ _r_on_ void _switch_r_off_(){_s_off_;}; 
_r_sub_return_ _r_return_Set_ _other_ _r_input_in_ _R_input_in_ _inline_input_d_ _R_SWITCH_ _r_on_ int __return(){return _s_return();}; 
#define _Support_(_) _r_sub_return_ _r_input_in_ _R_input_in_ _R_RINKPUTING_ _R_SAVE_ _Set_D_(_)
#define _Reset_ _r_sub_return_ _r_input_in_ _R_input_in_ _R_RINKPUTING_  _R_INCLUDE_ _R_SAVE_ _Set_R_
_r_sub_return_ _multi_ _r_return_Set_ _R_SAVE_ _inline_input_d_ int _R_Preset_(int _Buf_){_Reset_;return 0;}
#define _Preset_ _R_Preset_
int _Check_s_(){return __return();}
#define _Check_Switch_On_Off_ _Check_s_
#endif

#endif