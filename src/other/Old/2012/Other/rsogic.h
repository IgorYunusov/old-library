/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Version : 1.350.3							                               ********
 ********       Header : <rsogic.h> 					                         		   ********
 ********										                                           ********
 ********       Copyright ¨Ï ROLLRAT. All Rights Reserved.				                   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/

#pragma once

#include "rsituation.h"
#include "racalc.h"
//#include "rio.h"

#ifndef __RSOGIC__Check_
#define __RSOGIC__Check_

#define X_RE __X_RE_ 
#define Y_RE __Y_RE_ 
#define X_RO __X_RO_
#define Y_RO __Y_RO_

#define C_SIN(x)          (long double)sin((double)x)     
#define C_COS(x)          (long double)cos((double)x)  
#define C_TAN(x)          (long double)tan((double)x)  
#define C_LOG(x)          (long double)log((double)x)  
#define C_IN(x)           (long double)in((double)x)   
#define C_SQRT(x)         (long double)sqrt((double)x)    
#define C_NL(x)           (long double)nl((double)x)    
#define C_RECI(x)         (long double)reci((double)x)    
#define C_RAND(x)         (long double)rand((double)x)    

#ifndef $
#define $ 0
#ifndef $$
#define $$ 1
#endif

#ifndef __SOLVER__
#define __SOLVER__
#define _PRE_SENCTENCE_(x)                                 x
#endif
#endif


#define _FLOATING_MUL_                   _ACCESS_NUMBER_GOT_
#define _FLOATING_DIV_                   _ACCESS_NUMBER_GOT_
#define _FLOATING_ADD_                   _ACCESS_NUMBER_GOT_
#define _FLOATING_SUB_                   _ACCESS_NUMBER_GOT_
#define _ADDRESS_(__GET_)    __ADDRESS__SETTING_MAN_(__GET_)
/*
[Poling E] $ Value 0 $
[Poling E]$$ Value 1 $$

_ACCESS_   FIND POINT                X , Y
_FLOATING_ I/O
_SOLVER_   EQUATION                  X , Y     ( LEVEL 2 )
_FORMAGER_ EQUATION OF FORMAGER                ( LEVEL 3 )
_FINDING_  SOLVING OF EQUATION       X , Y     ( LEVEL 2 )
_FINDOR_   SOLVING OF EQUATION                 ( LEVEL 3 )
*/
#define _ACCESS_NUMBER_GET_                                $
#define _ACCESS_NUMBER_POINT_                              $
#define _ACCESS_NUMBER_FLOAT_                             $$
#define _ACCESS_NUMBER_TOTAL_                              $
#define _ACCESS_NUMBER_GOT_                               $$
#define _ACCESS_NUMBER_ADDRESS_                            $
#define _FLOATING_MUL_MULTI_FUNCTION                      $$
#define _FLOATING_MUL_MULTI_FUNCTION_GETTING_             $$
#define _FLOATING_MUL_MULTI_HEADER_                        $
#define _FLOATING_MUL_MULTI_                              $$
#define _FLOATING_DIV_MULTI_FUNCTION                      $$
#define _FLOATING_DIV_MULTI_FUNCTION_GETTING_             $$
#define _FLOATING_DIV_MULTI_HEADER_                        $
#define _FLOATING_DIV_MULTI_                              $$
#define _SOLVER_POSITION_X_                               $$
#define _SOLVER_POSITION_Y_                               $$
#define _SOLVER_ACCESS_POSITION_X_                         $
#define _SOLVER_ACCESS_POSITION_Y_                         $
#define _SOLVER_ACCESS_MEMORY_X_                          $$
#define _SOLVER_ACCESS_MEMORY_Y_                           $
#define _SOLVER_ACCESS_D_                                 $$
#define _SOLVER_ACCESS_F_                                 $$
#define _FINDING_ACCESS_X_                                $$
#define _FINDING_ACCESS_Y_                                $$
#define _FORMAGER_X_MANAGE_COM_SOLVER_EQUATION_           $$
#define _FORMAGER_X_MANAGE_COM_SOLVER_X_                   $
#define _FORMAGER_X_MANAGE_COM_SOLVER_C_                   $
#define _FORMAGER_X_MANAGE_COM_SOLVER_$_                  $$
#define _FORMAGER_X_MANAGE_COM_SOLVER_LEVEL_               $
#define _FORMAGER_X_MANAGE_COM_SOLVER_EQUATION_           $$
#define _FORMAGER_Y_MANAGE_COM_SOLVER_Y_                  $$
#define _FORMAGER_Y_MANAGE_COM_SOLVER_C_                   $
#define _FORMAGER_Y_MANAGE_COM_SOLVER_$_                  $$
#define _FORMAGER_Y_MANAGE_COM_SOLVER_LEVEL_              $$
/*
ROLLRAT SOFTWARE
Version 1.193.6
ROLLRAT _CHECK_SHOWN_DATA_

__ADDRESS__SETTING_MAN_                   __RETURN_      pt[ check __RETURN_     ]
__SURFACE__                               __YOUR_RE_     pt[ check __YOUR_RE_    ]
__TURE_ASSER_               __TREE__      SURFACE        pt[ check SURFACE       ]
*/
#ifndef _CHECK_SHOWN_DATA_
#define _CHECK_SHOWN_DATA_
char* __ADDRESS__SETTING_MAN_(char __RETURN_){
	if (__RETURN_ == 0)
		return (char*)$$;
	else if (__RETURN_ == 1)
		return (char*)$;
}
char* __SURFACE__(char __YOUR_RE_[]){
	if (__YOUR_RE_ = _ADDRESS_(_ACCESS_NUMBER_ADDRESS_))
		return (char*)$$;
}
char* __TRUE_ASSER_(char __TREE__[],char SURFACE[]){
	if (SURFACE = _ADDRESS_(_ACCESS_NUMBER_ADDRESS_))
		return __SURFACE__(__TREE__);
	else
		return (char*)$;
}
char* __PRE_SURFACE__(char __YOUR_RE_[])
{
	if (__YOUR_RE_ = __SURFACE__(_ACCESS_NUMBER_ADDRESS_))
		return __TRUE_ASSER_(__YOUR_RE_,__YOUR_RE_);
	else
		return __TRUE_ASSER_($,$);
}
char* __PRE_RECOVERY__(char _Y_[])
{
	return (char*)$;
}
char* __PRE_UN_RECOVERY__(char _Y_[])
{
	return _Y_;
}
char* __PRE_DIS_RECOVERY__(char _Y_[])
{
	return (char*)$$;
}
#endif

/* don't touch */
#ifndef _CHECK_SOLVE_
#define _CHECK_SOLVE_
inline int __COM_SOLVING_X_(int _POSITION_X_){if (_SOLVER_POSITION_X_ == $ )return _POSITION_X_;else if (_SOLVER_POSITION_X_ == $$ )return $;}
inline int __COM_SOLVING_Y_(int _POSITION_Y_){if (_SOLVER_POSITION_Y_ == $)return _POSITION_Y_;else if (_SOLVER_POSITION_Y_ == $$ )return $;}
inline int __COM_SOLVING_ACCESS_MEMORY_X_(int _ACCESS_MEMORY_X_){if (_SOLVER_ACCESS_MEMORY_X_ == _ACCESS_MEMORY_X_) return $;else if (_SOLVER_ACCESS_MEMORY_X_ == $$)return $$;}
inline int __COM_SOLVING_ACCESS_MEMORY_Y_(int _ACCESS_MEMORY_Y_){if (_SOLVER_ACCESS_MEMORY_Y_ == $) return $;else if (_SOLVER_ACCESS_MEMORY_Y_ == $$)return _ACCESS_MEMORY_Y_;}
inline int __COM_CHECKER_ALL_ACCESS_(int _ACCESS_CODE_){switch(_ACCESS_CODE_){
		case 0:if (_ACCESS_NUMBER_GET_ == $)return $$;else if (_ACCESS_NUMBER_GET_ == $$)return $;break;
		case 1:if (_ACCESS_NUMBER_POINT_ == $)return $$;else if (_ACCESS_NUMBER_POINT_ == $$)return $;break;
		case 2:if (_ACCESS_NUMBER_FLOAT_ == $$)return $$;else if (_ACCESS_NUMBER_FLOAT_ == $)return $;break;
		case 3:if (_ACCESS_NUMBER_TOTAL_ == $)return $$;else if (_ACCESS_NUMBER_TOTAL_ == $$)return $;break;
		case 4:if (_ACCESS_NUMBER_GOT_ == $$)return $$;else if (_ACCESS_NUMBER_GOT_ == $)return $;break;
		case 5:if (_ACCESS_NUMBER_ADDRESS_ == $)return $$;else if (_ACCESS_NUMBER_ADDRESS_ == $$)return $;break;}}
#endif


#ifndef _SOLVE_LEVEL_1_
#define _SOLVE_LEVEL_1_

/*
 * Impormation : Equation Solving
 *
 * Grouping : <rsogic.h>
 * Rendering : "rsituation.h"
 *
ver1.3*/
#endif

#ifndef _SOLVE_LEVEL_2_
#define _SOLVE_LEVEL_2_

inline long float __GET_D__2_(long double __GET_A,long double __GET_B,long double __GET_C){return __GET_B * __GET_B - 4 * __GET_A * __GET_C;}


/*
 * Impormation : Equation Solving
 *
 * Grouping : <rsogic.h>
 * Rendering : "rsituation.h"
 *
ver1.3*/
#endif

#ifndef _SOLVE_LEVEL_3_
#define _SOLVE_LEVEL_3_


/*
 * Impormation : Equation Solving
 *
 * Grouping : <rsogic.h>
 * Rendering : "rsituation.h"
 *
ver1.3*/
#endif

#ifndef _SOLVE_LEVEL_4_
#define _SOLVE_LEVEL_4_

/*
 * Impormation : Equation Solving
 *
 * Grouping : <rsogic.h>
 * Rendering : "rsituation.h"
 *
ver1.3*/
#endif



#endif


