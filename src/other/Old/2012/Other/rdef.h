/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Header : <rdef.h>      													   ********
 ********										                                           ********
 ********       Copyright �� ROLLRAT. All Rights Reserved.				                   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/

#if !defined(r_def)
#  if def
#    define def_ NONE
#  else
#    define def 1
#    if defi
#      define defi_ NONE
#    else
#      define defi 1
#    endif
#  endif
#else
#  define def  NONE
#  define defi NONE
#endif