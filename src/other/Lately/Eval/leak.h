/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   leak.h - [Private]

Project:

   RollRat Eval

------
   AUTHOR: HyunJun Jeong  2015-01-08

***************************************************************************/

#ifndef _LEAK_
#define _LEAK_
#if defined(_DEBUG) || defined(DEBUG)

#ifdef _LEAK_TEST

void *_DeRtck_memmalloc(size_t _size_ptr, const char *_func, const char *_file, unsigned int _line);
void *_DeRtck_memfree(void *ptr, const char *_func, const char *_file, unsigned int _line);
void *_DeRtck_memrealloc(void *_ptr, size_t _size_ptr, const char *_func, const char *_file, unsigned int _line);
void *_DeRtck_memcalloc(size_t _count_ptr, size_t _size_ptr, const char *_func, const char *_file, unsigned int _line);

void _DeRtck_init();
void _DeRtck_reset();
void _DeRtck_print_all();
void _DeRtck_print_nfree();
void _DeRtck_print_error();

#if !defined(__func__)
#define __func__ __FUNCTION__
#endif

#undef malloc
#undef free
#undef realloc
#undef calloc
#define malloc(s) _DeRtck_memmalloc(s, __func__, __FILE__, __LINE__)
#define free(p) _DeRtck_memfree(p, __func__, __FILE__, __LINE__)
#define realloc(s,p) _DeRtck_memrealloc(s, p, __func__, __FILE__, __LINE__)
#define calloc(c,s) _DeRtck_memcalloc(c, s, __func__, __FILE__, __LINE__)

#endif
#else
#include <malloc.h>
#endif
#endif