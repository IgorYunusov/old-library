/*************************************************************************
  
   RollRat Script Language Interpreter
   (Pre into company for making user manual sword script)


   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _sword_spgpgm_variable_
#define _sword_spgpgm_variable_

#include <vector>
#include <stack>
#include <string>
#include <functional>
#include <hash_map>
#include "parse_method.h"
#include "type.h"

typedef struct _dstt_ {
    std::string variable_name;
    std::string variable_data;
    std::string variable_replace;
}   _VariableStt;

class variable
{
    std::hash_map<size_t, _VariableStt *> map;
        std::hash<std::string> hash_func;
public:

    void put(std::string& variable_name)
    {
        _VariableStt *vstt = new _VariableStt;
        vstt->variable_name = variable_name;
        vstt->variable_data = std::string();
        vstt->variable_replace = std::string();
        map.insert(std::hash_map<size_t, _VariableStt *>::value_type
            (hash_func(variable_name), vstt));
    }

    void put(std::string& variable_name, std::string& variable_data)
    {
        _VariableStt *vstt = new _VariableStt;
        vstt->variable_name = variable_name;
        vstt->variable_data = variable_data;
        vstt->variable_replace = std::string();
        map.insert(std::hash_map<size_t, _VariableStt *>::value_type
            (hash_func(variable_name), vstt));
    }

    bool isin(std::string variable_name)
    {
        if (map.find(hash_func(variable_name)) != map.end())
            return true;
        return false;
    }

    _VariableStt *get(std::string variable_name)
    {
        auto find = map.find(hash_func(variable_name));
        if (find != map.end())
            return find->second;
        return nullptr;
    }
};

//static variable var_map;

#endif