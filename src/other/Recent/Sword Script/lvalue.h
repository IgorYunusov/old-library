/*************************************************************************
  
   RollRat Script Language Interpreter
   (Pre into company for making user manual sword script)


   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _sword_spgpgm_lvalue_
#define _sword_spgpgm_lvalue_

#include <ctype.h>
#include "variable.hh"

typedef enum class _dummy_cd680ce9f8fd627f0d4a96fd26e8d502_ {
    tyCharacter,
    tyString,
    tyArray,
    tyVariable,
    tyMatrix,
    tyFunction,
    tyDigit,
    tyXDigit,
    tyODigit,
    tyBinary,
    tyNone,
}   SPGPGM_LVALUE_TYPE, _SLT;

bool InternalCheckDataTypeNumberic(
    std::string _lvalue
    );

_SLT PredictChDataNumberic;

////////////////////////////////////////////////

bool IslValueDataType(
    std::string _lvalue,
    SPGPGM_LVALUE_TYPE slt
    )
{
    switch(slt)
    {
    case _SLT::tyCharacter:

    case _SLT::tyDigit:
    case _SLT::tyXDigit:
    case _SLT::tyODigit:
    case _SLT::tyBinary:
        return InternalCheckDataTypeNumberic(_lvalue);
        
    case _SLT::tyVariable:

    case _SLT::tyNone:
    default:
        return false;
    }
}

_SLT GetlValueDataType(
    std::string _lvalue
    )
{
    return _SLT::tyNone;
}

////////////////////////////////////////////////

bool InternalCheckDataTypeNumberic(
    std::string _lvalue
    )
{
    /*

    Numberic �����ʹ� ������ ���� ������
    (������ ���� Ȯ�θ� �ϸ� �ǹǷ� �������)

    Digit   ::=  0~9 | *This

    XDigit  ::=  '0x' XDigitIter
            XDigitIter ::= Digit | 'a'~'f' | *This

    ODigit  ::= ODigitIter 'o'
            ODigitIter ::= 0~7 | *This

    Binary  ::= BinaryIter 'b'
            BinaryIter ::= 0 | 1 | *This

    */

    const char *_Ptr = _lvalue.c_str(), *_Temp;

    _Temp = _Ptr;

    // ���ڿ��� ������ ������ �̵�
    while (*_Ptr)
        _Ptr++;

    int predict = 0;

    switch(tolower(*--_Ptr))
    {
    case 'o':
        predict = 1;
        break;
    case 'b':
        predict = 2;
        break;
    }

    if(predict == 2) {
        while(_Temp != _Ptr) {
            if (*_Temp != '0' && *_Temp != '1')
                return false;
            _Temp++;
        }
        PredictChDataNumberic = _SLT::tyBinary;
    } else if (predict == 1) {
        while(_Temp != _Ptr) {
            if ('0' > *_Temp || '7' < *_Temp)
                return false;
            _Temp++;
        }
        PredictChDataNumberic = _SLT::tyODigit;
    } else {
        if (*_Temp == '0' && tolower(*(_Temp + 1)) == 'x') {
            _Temp += 2;
            while (*_Temp) {
                if(*_Temp < '0' || '9' < *_Temp ) {
                    char ch = tolower(*_Temp);
                    if (ch < 'a' || 'f' < ch)
                        return false;
                }
                _Temp++;
            }
            PredictChDataNumberic = _SLT::tyXDigit;
        } else {
            while (*_Temp) {
                if (*_Temp < '0' || '9' < *_Temp)
                    return false;
            }
            PredictChDataNumberic = _SLT::tyDigit;
        }
    }

    return true;
}

#endif