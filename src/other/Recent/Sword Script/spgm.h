/*************************************************************************
  
   RollRat Script Language Interpreter
   (Pre into company for making user manual sword script)


   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _sword_spgm_string_
#define _sword_spgm_string_

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include "parse_method.h"
#include "second_layer_priority.h"

#define _SPGPGM_TEXT_ANNOTATION     "--+"
#define _SPGPGM_SYNTAX_VARIABLE_    '$'

std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}
std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}
std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}

//
//  parse_rvalue의 값을 넣어두는 벡터
//
std::vector <
    ::tree < std::string >> count_slider_vector;

/*
    parse_rvalue구문을 실행하고 위치를 반환합니다.
*/
position 
parse_and_put_slider(
    const char *_parts
    )
{
    count_slider_vector.push_back(parse_rvalue<priority_second_layer>().start(_parts));
    return count_slider_vector.size() - 1;
}

void SpgmSkipWhitespace(char const const* *ptr)
{
    while (**ptr)
        if (!((char *)isspace((int)(void *)*(*ptr))))
            return;
        else
            (*ptr)++;
}

#endif