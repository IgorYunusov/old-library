/*************************************************************************
  
   RollRat Script Language Interpreter
   (Pre into company for making user manual sword script)


   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#include <inttypes.h>
#include <time.h>
#include <intrin.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include "sword.h"

#include "lvalue.h"

using namespace std;

static time_t _sword_begin_time;
static time_t _sword_end_time;

int main(int argc, char *argv[])
{
    init_sword();

    cout << make_vesrion_text() << endl;
    cout << _COPYRIGHT_TEXT << endl;

    time(&_sword_begin_time);

    //////////////////////////////////

    InternalProcessingVariableChannel("$var rollrat = 'kkkkk'");
    
    IslValueDataType("0x1f2d", _SLT::tyXDigit);

    ICAStartCode(
        RpsReadAllTextFromFileSlowly("")
        );
    //////////////////////////////////

    time(&_sword_end_time);

    return 0;
}