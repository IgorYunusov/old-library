// �ü���� ���α׷��� �ѱ��� ��������������, �ѱ� �ּ��� ��� ����ʽÿ�.
/*

   Rollrat Software << lodefinitions.h >>

   ���ο�

 */
#define _r_lod_

#include "rinputin.h"

#pragma once

#define true 0
#define false 1

#if !defined(_lode_)
#define _lode_
//�ּ� ����(�ּ��� ���α׷��� ������ ��ġ���ʽ��ϴ�.)
//�� �ּ��� ����������� �����ϰ� ����˴ϴ�.
//�ּ��� �����ص� �˴ϴ�.
#if !defined(_r_lod_list_)
#define lod             //ó���� ��ġ
#define _single_        //�̱� �ڵ�
#define _other_         //�ٸ� �ڵ�
#define _multi_         //��Ƽ �ڵ�
#define _r_sub_return_  //���� ����
#define _r_fun_return_  //�Լ� ����
#define _r_sub_g_       //�ְ� ������ ��ġ��
#define _r_f_           //�̰� ���� �Լ��� (������ �� ����)
#define _r_sub_r_       //������ ������ (������ �� ����)
#define _r_sub_r_e_     //������ �� ������ (������ �� ����)
#define _r_sub_r_j_     //������ ��ȣ��
#define _r_sub_r_t_i_   //int ������ ���ϵ�
#define _r_sub_r_t_f_   //float ������ ���ϵ�
#define _r_sub_r_t_c_   //char ������ ���ϵ�
#define _r_sub_r_t_cl_  //char* ������ ���ϵ�
#define _r_sub_r_t_lf_  //long float ������ ���ϵ�
#define _r_sub_r_t_no_  //��� ���ϵ�
#define _r_sub_r_t_lf_  //Ư�������� ���ϵ�
#define _r_calc_        //����� �����
#define _r_calc_c_      //4Ģ ������ �����
#define _r_calc_sqrt_   //�������� �����
#define _r_calc_tf_     //�ﰢ�Լ��� �����
#define _r_calc_tb_     //�ﰢ�� �����
#define _r_calc_hg_     //������ ����� (sigma, solver ��)
#define _r_sub_c_c_     //�Լ��߿� 4Ģ������ ������
#define _r_sub_c_hg_    //�Լ��߿� ������ ������
#define _r_def_         //���Ǹ� ��Ÿ�� (������ �� ����)
#define _r_def_r_       //���� �����ϴ� ������
#define _r_def_s_       //�����ϴ� ������
#define _r_def_c_       //���� ���õ� ������
#define _r_def_no_      //�� �ּ��� ����� ó���� ������ �� ����� �ּ��� �����������
#define _r_def_o_       //������� ������
#define _r_def_i_       //�Է����� ������
#define _f_c_e_         //�ܺ� ������� ������ �Լ��� (������ �� ����)
#define _f_r_           //�Լ��� �б�������
#define _f_s_s_         //�Լ��� �����Լ���
#define _f_j_s_         //�Լ��� ����Լ���
#define _f_f_           //�Լ��� ���ϰ��õ� �Լ��� (������ �� ����) stdio.h
#define _f_h_e_         //�Լ��� ���ֻ���
#define _j_e_           //���������� �ּ���
#define _j_c_i_         //�����Ͱ� char���·� ���� int�������� ����
#define _j_i_c_         //�����Ͱ� int���·� ���� char�������� ����
#define _f_r_           //�Լ��� ���ͷ��Լ���
#define _a_l_           //�˸�������
#define _o_e_           //�Լ��� os�� �Ϻ���
#define _o_e_j_         //�Լ��� os�� ������ �Ϻ���
#define _b_l_           //��Ʈ�δ���
#define _f_j_f_         //�̴� �Լ���
#define _d_j_e_         //���̺귯���Լ���
#define _f_f_f_         //�Լ��� �⺻ ����� ���ԵǴ� �Լ���
#define _$Function      //�Լ��ȿ��� ���ǵ�. _r_def_no_ �ּ��� ������ �Ǿ������� ������
#define _$_$_f_         //�� �� ���� ������
#endif
//�� ������ ���� �ּ����� �ٸ� ����� ���ԵǾ��ֽ��ϴ�.
//���� ��

#if defined(_p_r_define_)
/* ������������  
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