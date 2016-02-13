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

#ifndef _RISCL_STRING_
#define _RISCL_STRING_

#include "riscldef.h"

#ifdef _EXECUTE_ON_DEVICE
#define USING_DEVICE_FLAG_STRINGH
#endif

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

int _isspace(int ch);
int _isnumeric(int ch);
int _isdigit(int ch);
int _isalpha(int ch);
int _isupper(int ch);
int _islower(int ch);
int _isalnum(int ch);
int _isxdigit(int ch);

char * _strcpy_asc(char * dest, const char * src);
_wchar_t * _strcpy_w(_wchar_t * dest, const _wchar_t * src);
char * _strncpy_asc(char * dest, const char * src, _size_t n);
_wchar_t * _strncpy_w(char * dest, const _wchar_t * src, _size_t n);
int _strcmp_asc(const char * s1, const char * s2);
int _strncmp_asc(const char * s1, const char * s2, _size_t n);
char * _strcat_asc(char * dest, const char * src);
_wchar_t * _strcat_w(_wchar_t * dest, const _wchar_t * src);
char * _strchr_asc(const char * str, int ch);
char * _strrchr_asc(const char * str, int ch);
_size_t _strspn_asc(const char * str1, const char * str2);
_size_t _strcspn_asc(const char * str1, const char * str2);
_size_t _strlen_asc(const char * str);
_size_t _strnlen_asc(const char * str, _size_t n);
char * _strupr_asc(char * str);
char * _strlwr_asc(char * str);
char * _strncat_asc(char * dest, const char * src, _size_t n);
_wchar_t * _strncat_w(_wchar_t * dest, const _wchar_t * src, _size_t n);
char * _strset_asc(char * str, int ch);
char * _strnset_asc(char * str, int ch, _size_t n);
char * _strrev_asc(char * str);
char * _strstr_asc(const char * s1, const char * s2);
char * _strtok_asc(char * str, const char * src);
char * _strpbrk_asc(const char * str, const char * src);
long _strtol_asc(const char *nptr, char **endptr, int base);
long _strtol_t(const char *nptr, char **endptr, int base);
unsigned long _strtoul_asc(const char *nptr, char **endptr, int base);
unsigned long _strtoul_t(const char *nptr, char **endptr, register int base);

int _atoi(const char * src);
double _atof(const char * src);
long _atol(const char * src);
char *__itoa(int i);
char * __dtoa(double n);

int _to_upper(int ch);
int _to_lower(int ch);

#ifdef __cplusplus
}
#endif  /* __cplusplus */


#endif