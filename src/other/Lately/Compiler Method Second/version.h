/*************************************************************************
  
   RollRat Script Language Interpreter
   (Pre into company for making user manual sword script)


   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _version_define_s_
#define _version_define_s_

#include <fstream>
#include <string>

#define _VERSION_SWORD      "1.0.2"
#define _VERSION_NSWORD     0x00010002

static int build_counting_number;

//
//  빌드 카운트를 늘려주는 도구
//
void build_count()
{
    using namespace std;
    ifstream inf(R"(C:\rollrat\build)", ios::in);
    ofstream onf(R"(C:\rollrat\build)", ios::out);
    onf << ((inf >> build_counting_number, build_counting_number) + 1);
    onf.close();
    inf.close();
}

std::string make_vesrion_text()
{
    const std::string ed("RollRat Script Language Interpreter "_VERSION_SWORD" [Build ");
    return ed + std::to_string(build_counting_number) + "]";
}

#define _COPYRIGHT_TEXT \
    "Copyright (c) rollrat. All rights reserved."

#ifdef __GNUC__
#define USING_COMPILER	1
#define COMPILER_NAME	"GCC"

#elif defined(_MSC_VER)
#define USING_COMPILER	2
#define COMPILER_NAME	"Microsoft"

#elif defined(__INTEL_COMPILER)
#define USING_COMPILER	3
#define COMPILER_NAME	"Intel"

#elif defined(__Turbo-c___)
#define USING_COMPILER	4
#define COMPILER_NAME	"Turbo -C"

#endif

#ifdef _DEBUGGING_MODE
	#error _DEBUGGING_MODE flag is already defined!
#else
	#ifdef _DEBUG
		#define _DEBUGGING_MODE 1		// debug mode
	#else
		#define _DEBUGGING_MODE 0		// release mode
	#endif
#endif

#if !defined(_M_IX86) && !defined(_M_IA64) && !defined(_IA64) \
    && !defined(__amd64) && !defined(_M_X64) && !defined(_IA64) && !defined(_SENDIAN)
	#error This platform is not accepted little endian.
#endif

#endif