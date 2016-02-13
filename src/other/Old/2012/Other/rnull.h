/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Header : <rnull.h>      							                       ********
 ********										                                           ********
 ********       Copyright ¨Ï ROLLRAT. All Rights Reserved.				                   ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/

#if !defined(NULL) || !defined(r_null)
#define r_null
#  if r_FF
/* 
     Defintion NULL 0L
	      Long type NULL 0L
 */
#     define NULL 0L
#  else
/*

    In the following cases, to clear the header
	1. NULL defined in another header
	2. If you do not define NULL
	3. If you interfere with this header
	
	-------------------------------------------

	#define NULL 0 // Re defined NULL
	
	Impormation Header

	   Definition NULL
	        The NULL initialize zero or char NULL

	   Definition r_null
	        Header << rnull.h >> defined

	2012 - 10 - 13

*/
#     define NULL 0
#  endif
#else /* Else defined NULL */
#  if r_FF
/* 
     Defintion NULL_ 0L
	      Long type NULL_ 0L
 */
#     define NULL_ 0L
#  else
#     define NULL_ 0
#  endif
#endif

/* Char NULL Text
   
   ASCII 0x00
 */
#define _NULL \0