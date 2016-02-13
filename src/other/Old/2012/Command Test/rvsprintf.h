//
// vsprintf.c
//
// Print formatting routines
//
// Copyright (C) 2002 Michael Ringgaard. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
// 1. Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.  
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.  
// 3. Neither the name of the project nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
// SUCH DAMAGE.
// 

#ifndef __VSPRINTF__
#define __VSPRINTF__

#define ZEROPAD 1               // Pad with zero
#define SIGN    2               // Unsigned/signed long
#define PLUS    4               // Show plus
#define SPACE   8               // Space if plus
#define LEFT    16              // Left justified
#define SPECIAL 32              // 0x
#define LARGE   64              // Use 'ABCDEF' instead of 'abcdef'

#define is_digit(c) ((c) >= '0' && (c) <= '9')

static char *digits = "0123456789abcdefghijklmnopqrstuvwxyz";
static char *upper_digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

typedef char *  va_list;

#define va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
    #define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
    #define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
   #define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

#define va_end(ap)      ( ap = (va_list)0 )

static size_t strnlen(const char *s, size_t count) {
  const char *sc;
  for (sc = s; *sc != '\0' && count--; ++sc);
  return sc - s;
}

int 
strlen
(
	const char* ptr
	)
{
    int i = 0;
	while( ptr[i] ) { i++; }
    return i;
}//rollrat

void *memcpy(void *dst, void *src, size_t n)
{
	int i=0;
	unsigned char *pDst = (unsigned char*)dst;
	unsigned char *pSrc = (unsigned char*)src;
	for(;i<n;++i)
		pDst[i] = pSrc[i];
	return dst;
}// http://babolive00.blog.me/100136076241

static int skip_atoi(const char **s) {
  int i = 0;
  while (is_digit(**s)) 
	  i = i*10 + *((*s)++) - '0';
  return i;
}

static char *number(char *str, long num, int base, int size, int precision, int type) {
  char c, sign, tmp[66];
  char *dig = digits;
  int i;

  if (type & LARGE)  dig = upper_digits;
  if (type & LEFT) type &= ~ZEROPAD;
  if (base < 2 || base > 36) return 0;
  
  c = (type & ZEROPAD) ? '0' : ' ';
  sign = 0;
  if (type & SIGN) {
    if (num < 0) {
      sign = '-';
      num = -num;
      size--;
    } else if (type & PLUS) {
      sign = '+';
      size--;
    } else if (type & SPACE) {
      sign = ' ';
      size--;
    }
  }

  if (type & SPECIAL) {
    if (base == 16) {
      size -= 2;
    } else if (base == 8) {
      size--;
    }
  }

  i = 0;

  if (num == 0) {
    tmp[i++] = '0';
  } else {
    while (num != 0) {
      tmp[i++] = dig[((unsigned long) num) % (unsigned) base];
      num = ((unsigned long) num) / (unsigned) base;
    }
  }

  if (i > precision) precision = i;
  size -= precision;
  if (!(type & (ZEROPAD | LEFT))) while (size-- > 0) *str++ = ' ';
  if (sign) *str++ = sign;
  
  if (type & SPECIAL) {
    if (base == 8) {
      *str++ = '0';
    } else if (base == 16) {
      *str++ = '0';
      *str++ = digits[33];
    }
  }

  if (!(type & LEFT)) while (size-- > 0) *str++ = c;
  while (i < precision--) *str++ = '0';
  while (i-- > 0) *str++ = tmp[i];
  while (size-- > 0) *str++ = ' ';

  return str;
}

int vsprintf(char *buf, const char *fmt, va_list args) 
{

  int len;
  unsigned long num;
  int i, base;
  char *str;
  char *s;

  int flags;            // Flags to number()

  int field_width;      // Width of output field
  int precision;        // Min. # of digits for integers; max number of chars for from string
  int qualifier;        // 'h', 'l', or 'L' for integer fields

  for (str = buf; *fmt; fmt++) {
    if (*fmt != '%') {
      *str++ = *fmt;
      continue;
    }
                  
    // Process flags
    flags = 0;
repeat:
    fmt++; // This also skips first '%'
    switch (*fmt) {
      case '-': flags |= LEFT; goto repeat;
      case '+': flags |= PLUS; goto repeat;
      case ' ': flags |= SPACE; goto repeat;
      case '#': flags |= SPECIAL; goto repeat;
      case '0': flags |= ZEROPAD; goto repeat;
    }
          
    // Get field width
    field_width = -1;
    if (is_digit(*fmt)) {
      field_width = skip_atoi(&fmt);
    } else if (*fmt == '*') {
      fmt++;
      field_width = va_arg(args, int);
      if (field_width < 0) {
        field_width = -field_width;
        flags |= LEFT;
      }
    }

    // Get the precision
    precision = -1;
    if (*fmt == '.') {
      ++fmt;    
      if (is_digit(*fmt)) {
        precision = skip_atoi(&fmt);
      } else if (*fmt == '*') {
        ++fmt;
        precision = va_arg(args, int);
      }
      if (precision < 0) precision = 0;
    }

    // Get the conversion qualifier
    qualifier = -1;
    if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L') {
      qualifier = *fmt;
      fmt++;
    }

    // Default base
    base = 10;

    switch (*fmt) {
      case 's':
        s = va_arg(args, char *);
        if (!s) s = "<NULL>";
        len = strnlen(s, precision);
        if (!(flags & LEFT)) while (len < field_width--) *str++ = ' ';
        for (i = 0; i < len; ++i) *str++ = *s++;
        while (len < field_width--) *str++ = ' ';
        continue;

        continue;

      default:
        if (*fmt != '%') *str++ = '%';
        if (*fmt) {
          *str++ = *fmt;
        } else {
          --fmt;
        }
        continue;
    }

    if (qualifier == 'l') {
      num = va_arg(args, unsigned long);
    } else if (qualifier == 'h') {
      if (flags & SIGN) {
        num = va_arg(args, short);
      } else {
        num = va_arg(args, unsigned short);
      }
    } else if (flags & SIGN) {
      num = va_arg(args, int);
    } else {
      num = va_arg(args, unsigned int);
    }

    str = number(str, num, base, field_width, precision, flags);
  }

  *str = '\0';
  return str - buf;
}

#endif