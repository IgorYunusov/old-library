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
#include "inter_method.h"
#include "type.h"
#include "spgm.h"

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

static variable var_map;

bool InternalProcessingVariableChannel(
    std::string variable_text
    )
{
    const char *_Ptr = variable_text.c_str();

    // Variable Syntax: ex)
    // $var <name>
    // $var <name> = <data>

    const char *_Variable_Prefix = "$var";

    /* Check Prefix */
    for (; *_Ptr == *_Variable_Prefix && *_Variable_Prefix; _Variable_Prefix++, _Ptr++)
        ;

    // error
    if (!*_Variable_Prefix)
        return false;


    /*
        Get Variable Name
    */
    SpgmSkipWhitespace(&_Ptr);

    // Check First Character
    if( !(isalpha(*_Ptr) || *_Ptr == '_') )
        // Invalid variable name.
        return false;

    std::string variable_name_buf;
    
    auto is_chara = [](char ch) -> bool {
        return (
	    	isalnum(ch) ||
	    	ch == '$' ||
	    	ch == '_'
	    );
    };

    auto is_equal = [](char ch) -> bool {
        return (
	    	isalnum(ch) ||
	    	ch == '$' ||
	    	ch == '_' ||
            ch == '{' || ch == '}' ||
            ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' ||
            isxdigit(ch) ||
            ch == 'x'
	    );
    };

    for (; is_chara(*_Ptr); _Ptr++)
        variable_name_buf.push_back(*_Ptr);

    /* already in map */
    if (var_map.isin(variable_name_buf) == true)
        return false;
    
    SpgmSkipWhitespace(&_Ptr);
    
    std::string variable_data_buf;

    // Check equal syntax
    if(*_Ptr == '=') {
        _Ptr++;
        SpgmSkipWhitespace(&_Ptr);

        for (; is_equal(*_Ptr); _Ptr++)
            variable_data_buf.push_back(*_Ptr);

        // not found syntax
        if (variable_data_buf.empty())
            return false;

        var_map.put(variable_name_buf, variable_data_buf);
    } else {
        var_map.put(variable_name_buf);
    }

    return true;
}

#endif
