/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   al.c

Project:

   Basic String Algorithm Set

------
   AUTHOR: HyunJun Jeong  2015-07-18

***************************************************************************/

#include <algorithm> 
#include <functional> 
#include <cctype>
#include <string>
#include "cssi.h"
#include "rocket.h"

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