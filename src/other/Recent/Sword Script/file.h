/*************************************************************************
  
   RollRat Script Language Interpreter
   (Pre into company for making user manual sword script)


   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _sword_file_define_
#define _sword_file_define_

#include <fstream>
#include <vector>
#include <string>

std::vector<std::string>
RpsReadAllTextFromFileSlowly(
    std::string _file_addr_text
    )
{
    std::ifstream ifs(_file_addr_text);
    std::vector<std::string> alltexts;
    std::string str_buf;
    while (std::getline(ifs, str_buf))
        alltexts.push_back(str_buf);
    ifs.close();
    return alltexts;
}

#endif