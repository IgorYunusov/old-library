/*************************************************************************
 *
 * FILE NAME : string.h
 *
 * RollRat ISO Standard C Library
 *
 *
 * CREATION : 2014.12.06
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _RISCL_STDIO_
#define _RISCL_STDIO_

#include "riscldef.h"

#ifdef _EXECUTE_ON_DEVICE
#define USING_DEVICE_FLAG_STDIOH
#endif

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

int _sprintf_aes(char *str, const char *format, ... );

#ifdef __cplusplus
}
#endif  /* __cplusplus */


#endif