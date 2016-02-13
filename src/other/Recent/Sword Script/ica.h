/*************************************************************************
  
   RollRat Script Language Interpreter
   (Pre into company for making user manual sword script)


   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _sword_ica_define_
#define _sword_ica_define_

////////////////////////////////////////////////////////////////////////////
/*----------                                                    ----------*/
/*----------                                                    ----------*/
/*----------                Interpreter Code Area               ----------*/
/*----------                                                    ----------*/
/*----------                                                    ----------*/
////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <stack>
#include <string>
#include "parse_method.h"
#include "inter_method.h"
#include "type.h"
#include "spgm.h"
#include "variable.hh"

void RgpProcessingNextLine(
    std::string line_text
    )
{
    std::string buf = ::ltrim(line_text);
    std::string comment(_SPGPGM_TEXT_ANNOTATION);

    /* Check this line is comment line. */
    if (buf.find(comment.length()) == 0)
        return;

    /* Check this line is variable line. */
    if (buf[0] == _SPGPGM_SYNTAX_VARIABLE_)
        InternalProcessingVariableChannel(buf);
}

///////////////////////////////////////////

void ICAStartCode(
    std::vector<std::string> texts
    )
{
    for (std::string line_text : texts)
        RgpProcessingNextLine(line_text);
}

#endif