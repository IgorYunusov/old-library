/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   typei.h

Purpose:

   Provide typically generation tip.

Author:

   09-19-2015:   HyunJun Jeong, Creation

***/

#ifndef _TYPE_I_
#define _TYPE_I_

/*++

   If in the case that will proceed to higher levels of the 
   project, it is necessary to integrate the name of the 
   procedure, and would if the name of the parameter is 
   also easy to identify.

   Stylized, when you try to create and apply a rule, 
   it was decided to make this header.

--*/


/*++

   Windows Kernel Sytle Function Prefix Standard

   Em  - Errata manager
   Se  - Security
   Mm  - Memory manager
   Ob  - Object manager
   Sm  - Storage manager
   Tm  - Transaction manager
   Cm  - Configuration manager
   Ex  - Executive supprot rutines

   +----------------------------------------------------------+

   RollRat Software Function Common Prefix [ C language Only ]

   Dp  - Dispatch manager
   Sc  - Search manager
   Am  - Authority manager
   Pb  - Physics laboratory
   Mb  - Mathematics laboratory


   Parsing Method Prefix

   Re  - Regex Checker


--*/


/*++

   Hungarian Notation ( Parameter, [Variable] )

      If Available - When there are many variables in 
	     a procedure is to be used for variable.

   i   - Integer, Indexing Array
   ui  - Unsigned Integer
   l   - Long Integer
   ul  - Unsigned Long Integer
   d   - Double ( db )
   by  - Byte
   str - String
   sz  - String ( Only, char * )
   c   - Character
   w   - Word ( Unsigned Short Integer )
   dw  - Double Word ( Unsigned Long Integer )
   a   - Array
   p   - Pointer
   lp  - Ohter Pointer Notation
   rg  - Range
   fn  - Function
   f   - Boolean Flags ( Float pointing )
   b   - Boolean
   n   - Count of Array

--*/


/*++

   Simple Parameter Indicator

   IN    - Only read
   OUT   - Only write
   INOUT - Reference variable

--*/

#define IN
#define OUT
#define INOUT


/*++

   Abridgment Microsoft Sourcecode Annotation Language
                                    - #include <sal.h>

   <Parameter Option>
   _In_    : Input to called function. Data is passed to
             the called function, but is treated as read-only.
   _Inout_ : Input to called function, and output to caller.
             Usable data is passed into the function and
			 potentially is modified.
   _Out_   : Ouput to caller. The caller only provieds space
             for the called function to wirte to. The called
			 function writes data into that space.
   _Outptr_: Output to caller

   <Optional Parameter Only>
   Notation -
       <Parameter Option>opt_

   Only 8.

--*/

#define _In_
#define _Inout_
#define _Out_
#define _Outptr_

#define _In_opt_
#define _Inout_opt_
#define _Out_opt_
#define _Outptr_opt_


/*++

   Regural Expression Notation

   Check Function
      ReCheckDigit    : [0-9]
      ReCheckAlpha    : [a-zA-Z]
      ReCheckAlnum    : [a-zA-Z0-9]
      ReCheckVariable : [_a-zA-Z0-9]
      ReCheckSpace    : [ \r\n\t\v\f]
      ReCheckString   : "~^"""
	  ReCheckHexDigit : [a-fA-F0-9]
	  ReCheckHexString: 0x[ReCheckHexDigit]

--*/

/*++

   Compiler Files Notation

   ls<name>.c  - Recusive parser method
   ll<name>.c  - LL(0) parser method
     Not support [ lr<name>.c  - LR parser method ]
   yc<name>.yacc - yacc parser
   op<name>.c  - Compiler optimization method
   sy<name>.c  - Symantic check logic
   cg<name>.c  - Code generator

--*/

#endif