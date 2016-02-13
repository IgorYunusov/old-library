/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Version : 1.110.4							                               ********
 ********       Header : <rsituation.h> 					                         	   ********
 ********										                                           ********
 ********       Copyright ¨Ï ROLLRAT. All Rights Reserved.				                   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/

#pragma once
#ifndef _R_SITUATION_
#define _R_SITUATION_
#define SO( _RS_ ) _RS_
#ifndef _R_NAMESPACE_COMS_

namespace n_coms_r{
#endif
	enum SO( _R_Type_ ){SO( NULL_ ) = 0,SO( ACCESS_ ) = 1};typedef SO( _R_Type_ ) SO( _R_Type_ );enum SO( _R_OUT_ ){SO( _Type_RE_ ) = 0,SO( _Type_RO_ ) = 1};
	typedef SO( _R_OUT_ ) SO( _R_OUT_ );
	struct X{unsigned int _R_IO_X__;char *RESOLVER_X__;char *COMSOLVER_X__;char *LEVELSOLVER_X__;char *INPUT_X__;char *OUTPUT_X__;};
	struct Y{unsigned int _R_IO_Y__;char *RESOLVER_Y__;char *COMSOLVER_Y__;char *LEVELSOLVER_Y__;char *INPUT_Y__;char *OUTPUT_Y__;};
#ifndef _R_NAMESPACE_COMS_
};
#endif
#define SA( _RS_ ) _RS_
#ifndef _R_NAMESPACE_COMS_SOLVER_
namespace n_coms_r_s{
#endif
	enum SA( _R_Type_S_ ){SA( NULL_S_ ) = 0,SA( ACCESS_S_ ) = 1};typedef SA( _R_Type_S_ ) SA( _R_Type_S_ );enum SA( _R_OUT_S_ ){SA( _Type_RE_S_ ) = 0,SA( _Type_RO_S_ ) = 1};
	typedef SA( _R_OUT_S_ ) SA( _R_OUT_S_ );
	struct X_SOLVER{unsigned int _R_IO_X__;char *RESOLVER_X__;char *COMSOLVER_X__;char *LEVELSOLVER_X__;char *INPUT_X__;char *OUTPUT_X__;};
	struct Y_SOLVER{unsigned int _R_IO_Y__;char *RESOLVER_Y__;char *COMSOLVER_Y__;char *LEVELSOLVER_Y__;char *INPUT_Y__;char *OUTPUT_Y__;};
#ifndef _R_NAMESPACE_COMS_SOLVER_
};
#endif
#define SK( _RS_ ) _RS_
#ifndef _R_NAMESPACE_COMS_ANAL_ 
namespace n_coms_r_k{
#endif
	enum SK( _R_Type_K_ ){SK( NULL_S_ ) = 0,SK( ACCESS_K_ ) = 1};typedef SK( _R_Type_K_ ) SO( _R_Type_K_ );enum SK( _R_OUT_K_ ){SK( _Type_RE_K_ ) = 0,SK( _Type_RO_K_ ) = 1};
	typedef SK( _R_OUT_K_ ) SK( _R_OUT_K_ );
	struct X_ANAL{unsigned int _R_IO_X__;char *RESOLVER_X__;char *COMSOLVER_X__;char *LEVELSOLVER_X__;char *INPUT_X__;char *OUTPUT_X__;};
	struct Y_ANAL{unsigned int _R_IO_Y__;char *RESOLVER_Y__;char *COMSOLVER_Y__;char *LEVELSOLVER_Y__;char *INPUT_Y__;char *OUTPUT_Y__;};
#ifndef _R_NAMESPACE_COMS_ANAL_
};
#endif
#ifndef _R_SOLVER_RE_
#define _X_RE_ ::n_coms_r::X::INPUT_X__
#define _Y_RE_ ::n_coms_r::Y::INPUT_Y__
#define _X_RO_ ::n_coms_r::X::OUTPUT_X__
#define _Y_RO_ ::n_coms_r::Y::OUTPUT_Y__
#define _X_L_ ::n_coms_r::ACCESS_ 
#define _Y_L_ ::n_coms_r::ACCESS_ 
#define _X_S_ ::n_coms_r::_Type_RE_
#define _Y_S_ ::n_coms_r::_Type_RE_
#define _X_A_ ::n_coms_r::_Type_RO_
#define _Y_A_ ::n_coms_r::_Type_RO_
#define _X_LL_ ::n_coms_r::X::LEVELSOLVER_X__
#define _Y_LL_ ::n_coms_r::Y::LEVELSOLVER_Y__
#define _X_R_ ::n_coms_r::X::RESOLVER_X__
#define _Y_R_ ::n_coms_r::Y::RESOLVER_Y__
#define _X_C_ ::n_coms_r::X::COMSOLVER_X__
#define _Y_C_ ::n_coms_r::Y::COMSOLVER_Y__
#define __X_RE_ ::n_coms_r_s::X_SOLVER::INPUT_X__
#define __Y_RE_ ::n_coms_r_s::Y_SOLVER::INPUT_Y__
#define __X_RO_ ::n_coms_r_s::X_SOLVER::OUTPUT_X__
#define __Y_RO_ ::n_coms_r_s::Y_SOLVER::OUTPUT_Y__
#define __X_L_ ::n_coms_r_s::ACCESS_S_
#define __Y_L_ ::n_coms_r_s::ACCESS_S_ 
#define __X_S_ ::n_coms_r_s::_Type_RE_S_
#define __Y_S_ ::n_coms_r_s::_Type_RE_S_
#define __X_A_ ::n_coms_r_s::_Type_RO_S_
#define __Y_A_ ::n_coms_r_s::_Type_RO_S_
#define __X_LL_ ::n_coms_r_s::X_SOLVER::LEVELSOLVER_X__
#define __Y_LL_ ::n_coms_r_s::Y_SOLVER::LEVELSOLVER_Y__
#define __X_R_ ::n_coms_r_s::X_SOLVER::RESOLVER_X__
#define __Y_R_ ::n_coms_r_s::Y_SOLVER::RESOLVER_Y__
#define __X_C_ ::n_coms_r_s::X_SOLVER::COMSOLVER_X__
#define __Y_C_ ::n_coms_r_s::Y_SOLVER::COMSOLVER_Y__
#define _A_X_RE_ ::n_coms_r_k::X_ANAL::INPUT_X__
#define _A_Y_RE_ ::n_coms_r_k::Y_ANAL::INPUT_Y__
#define _A_X_RO_ ::n_coms_r_k::X_ANAL::OUTPUT_X__
#define _A_Y_RO_ ::n_coms_r_k::Y_ANAL::OUTPUT_Y__
#define _A_X_L_ ::n_coms_r_k::ACCESS_K_ 
#define _A_Y_L_ ::n_coms_r_k::ACCESS_K_ 
#define _A_X_S_ ::n_coms_r_k::_Type_RE_K_
#define _A_Y_S_ ::n_coms_r_k::_Type_RE_K_
#define _A_X_A_ ::n_coms_r_k::_Type_RO_K_
#define _A_Y_A_ ::n_coms_r_k::_Type_RO_K_
#define _A_X_LL_ ::n_coms_r_k::X_ANAL::LEVELSOLVER_X__
#define _A_Y_LL_ ::n_coms_r_k::Y_ANAL::LEVELSOLVER_Y__
#define _A_X_R_ ::n_coms_r_k::X_ANAL::RESOLVER_X__
#define _A_Y_R_ ::n_coms_r_k::Y_ANAL::RESOLVER_Y__
#define _A_X_C_ ::n_coms_r_k::X_ANAL::COMSOLVER_X__
#define _A_Y_C_ ::n_coms_r_k::Y_ANAL::COMSOLVER_Y__
#endif
#endif