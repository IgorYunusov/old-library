/*  stdio.h

    Definitions for stream input/output.

    Copyright (c) 1987, 1992 by Borland International
    All Rights Reserved.
*/

#ifndef __STDIO_H
#define __STDIO_H

#if !defined(___DEFS_H)
#define ___DEFS_H

#if __STDC__
#  define _Cdecl
#else
#  define _Cdecl  cdecl
#endif

#ifndef __PAS__
#  define _CType _Cdecl
#else
#  define _CType pascal
#endif

#ifdef __MSC
#  define _emit db
#  define __far _far
#  define __near _near
#  define __cdecl _cdecl
#  define __pascal _pascal
#  define __export _export
#  ifdef __SMALL__
#    define _M_I86SM
#  endif
#  ifdef __COMPACT__
#    define _M_I86CM
#  endif
#  ifdef __MEDIUM__
#    define _M_I86MM
#  endif
#  ifdef __LARGE__
#    define _M_I86LM
#  endif
#  ifndef _Windows
#    define _DOS
#  else
#    define _WINDOWS
#  endif
#endif

#if defined(__STDC__)
#  define _FAR
#  define _FARFUNC
#  define _CLASSTYPE
#else
#  if defined(_BUILDRTLDLL)
#    define _FARFUNC _export
#  elif defined(_RTLDLL)
#    define _FARFUNC far
#  else
#    define _FARFUNC
#  endif
#  if defined(__DLL__)
#    if defined(_RTLDLL) || defined(_CLASSDLL)
#      define _CLASSTYPE _export
#    else
#      define _CLASSTYPE far
#    endif
#    define _FAR far
#  elif defined(_RTLDLL) || defined(_CLASSDLL)
#    define _CLASSTYPE huge
#    define _FAR far
#  else
#    define _FAR
#    if   defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#      define _CLASSTYPE  near
#    elif defined(__COMPACT__) || defined(__LARGE__)
#      define _CLASSTYPE  far
#    else
#      define _CLASSTYPE  huge
#    endif
#  endif
#endif    /* __STDC__ */

#if defined(_BUILDRTLDLL)
#  define _FARCALL _export
#else
#  define _FARCALL far
#endif

#if defined( __cplusplus )
#  define _PTRDEF(name) typedef name _FAR * P##name;
#  define _REFDEF(name) typedef name _FAR & R##name;
#  define _REFPTRDEF(name) typedef name _FAR * _FAR & RP##name;
#  define _PTRCONSTDEF(name) typedef const name _FAR * PC##name;
#  define _REFCONSTDEF(name) typedef const name _FAR & RC##name;
#  define _CLASSDEF(name) class _CLASSTYPE name; \
        _PTRDEF(name) \
    _REFDEF(name) \
    _REFPTRDEF(name) \
    _PTRCONSTDEF(name) \
    _REFCONSTDEF(name)
#endif

#endif  /* ___DEFS_H */


#ifndef ___NFILE_H
#define ___NFILE_H

#define _NFILE_ 20

#endif

#ifndef NULL
#  if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#    define NULL    0
#  else
#    define NULL    0L
#  endif
#endif


#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

/* Definition of the file position type
*/
typedef long    fpos_t;


/* Definition of the control structure for streams
*/
typedef struct  {
        int             level;          /* fill/empty level of buffer */
        unsigned        flags;          /* File status flags          */
        char            fd;             /* File descriptor            */
        unsigned char   hold;           /* Ungetc char if no buffer   */
        int             bsize;          /* Buffer size                */
        unsigned char   _FAR *buffer;   /* Data transfer buffer       */
        unsigned char   _FAR *curp;     /* Current active pointer     */
        unsigned        istemp;         /* Temporary file indicator   */
        short           token;          /* Used for validity checking */
}       FILE;                           /* This is the FILE object    */

/* Bufferisation type to be used as 3rd argument for "setvbuf" function
*/
#define _IOFBF  0
#define _IOLBF  1
#define _IONBF  2

/*  "flags" bits definitions
*/
#define _F_RDWR 0x0003                  /* Read/write flag       */
#define _F_READ 0x0001                  /* Read only file        */
#define _F_WRIT 0x0002                  /* Write only file       */
#define _F_BUF  0x0004                  /* Malloc'ed Buffer data */
#define _F_LBUF 0x0008                  /* line-buffered file    */
#define _F_ERR  0x0010                  /* Error indicator       */
#define _F_EOF  0x0020                  /* EOF indicator         */
#define _F_BIN  0x0040                  /* Binary file indicator */
#define _F_IN   0x0080                  /* Data is incoming      */
#define _F_OUT  0x0100                  /* Data is outgoing      */
#define _F_TERM 0x0200                  /* File is a terminal    */

/* End-of-file constant definition
*/
#define EOF (-1)            /* End of file indicator */

/* Number of files that can be open simultaneously
*/
#if __STDC__
#define FOPEN_MAX (_NFILE_ - 2) /* (_NFILE_ - stdaux & stdprn) */
#else
#define FOPEN_MAX (_NFILE_)     /* Able to have 20 files */
#define SYS_OPEN  (_NFILE_)
#endif

#define FILENAME_MAX 80

/* Default buffer size use by "setbuf" function
*/
#define BUFSIZ  512         /* Buffer size for stdio */

/* Size of an arry large enough to hold a temporary file name string
*/
#define L_ctermid   5       /* CON: plus null byte */
#define P_tmpdir    ""      /* temporary directory */
#define L_tmpnam    13      /* tmpnam buffer size */

/* Constants to be used as 3rd argument for "fseek" function
*/
#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0

/* Number of unique file names that shall be generated by "tmpnam" function
*/
#define TMP_MAX     0xFFFF

/* Standard I/O predefined streams
*/

#if !defined( _RTLDLL )
extern  FILE    _Cdecl _streams[];
extern  unsigned    _Cdecl _nfile;

#define stdin   (&_streams[0])
#define stdout  (&_streams[1])
#define stderr  (&_streams[2])

#if !__STDC__
#define stdaux  (&_streams[3])
#define stdprn  (&_streams[4])
#endif

#else

#ifdef __cplusplus
extern "C" {
#endif
FILE far * far __getStream(int);
#ifdef __cplusplus
}
#endif

#define stdin   __getStream(0)
#define stdout  __getStream(1)
#define stderr  __getStream(2)
#define stdaux  __getStream(3)
#define stdprn  __getStream(4)

#endif

#ifdef __cplusplus
extern "C" {
#endif

void    _Cdecl clearerr(FILE _FAR *__stream);
int     _Cdecl _FARFUNC fclose(FILE _FAR *__stream);
int     _Cdecl _FARFUNC fflush(FILE _FAR *__stream);
int     _Cdecl _FARFUNC fgetc(FILE _FAR *__stream);
int     _Cdecl fgetpos(FILE _FAR *__stream, fpos_t _FAR *__pos);
char   _FAR *_Cdecl _FARFUNC fgets(char _FAR *__s, int __n, FILE _FAR *__stream);
FILE   _FAR *_Cdecl _FARFUNC fopen(const char _FAR *__path, const char _FAR *__mode);
int     _Cdecl _FARFUNC fprintf(FILE _FAR *__stream, const char _FAR *__format, ...);
int     _Cdecl _FARFUNC fputc(int __c, FILE _FAR *__stream);
int     _Cdecl _FARFUNC fputs(const char _FAR *__s, FILE _FAR *__stream);
size_t  _Cdecl _FARFUNC fread(void _FAR *__ptr, size_t __size, size_t __n,
                     FILE _FAR *__stream);
FILE   _FAR *_Cdecl _FARFUNC freopen(const char _FAR *__path, const char _FAR *__mode,
                            FILE _FAR *__stream);
int     _Cdecl _FARFUNC fscanf(FILE _FAR *__stream, const char _FAR *__format, ...);
int     _Cdecl _FARFUNC fseek(FILE _FAR *__stream, long __offset, int __whence);
int     _Cdecl fsetpos(FILE _FAR *__stream, const fpos_t _FAR *__pos);
long    _Cdecl _FARFUNC ftell(FILE _FAR *__stream);
size_t  _Cdecl _FARFUNC fwrite(const void _FAR *__ptr, size_t __size, size_t __n,
                      FILE _FAR *__stream);
char   _FAR *_Cdecl gets(char _FAR *__s);
void    _Cdecl perror(const char _FAR *__s);
int     _Cdecl printf(const char _FAR *__format, ...);
int     _Cdecl puts(const char _FAR *__s);
int     _CType remove(const char _FAR *__path);
int     _CType _FARFUNC rename(const char _FAR *__oldname,const char _FAR *__newname);
void    _Cdecl _FARFUNC rewind(FILE _FAR *__stream);
int     _Cdecl scanf(const char _FAR *__format, ...);
void    _Cdecl setbuf(FILE _FAR *__stream, char _FAR *__buf);
int     _Cdecl _FARFUNC setvbuf(FILE _FAR *__stream, char _FAR *__buf,
                       int __type, size_t __size);
int     _Cdecl _FARFUNC sprintf(char _FAR *__buffer, const char _FAR *__format, ...);
int     _Cdecl _FARFUNC sscanf(const char _FAR *__buffer,
                      const char _FAR *__format, ...);
char   _FAR *_Cdecl _FARFUNC strerror(int __errnum);
FILE   _FAR *_Cdecl _FARFUNC tmpfile(void);
char   _FAR *_Cdecl _FARFUNC tmpnam(char _FAR *__s);
int     _Cdecl _FARFUNC ungetc(int __c, FILE _FAR *__stream);
int     _Cdecl _FARFUNC vfprintf(FILE _FAR *__stream, const char _FAR *__format,
                        void _FAR *__arglist);
int     _Cdecl _FARFUNC vfscanf(FILE _FAR *__stream, const char _FAR *__format,
                        void _FAR *__arglist);
int     _CType vprintf(const char _FAR *__format, void _FAR *__arglist);
int     _Cdecl vscanf(const char _FAR *__format, void _FAR *__arglist);
int     _Cdecl _FARFUNC vsprintf(char _FAR *__buffer, const char _FAR *__format,
                        void _FAR *__arglist);
int     _Cdecl _FARFUNC vsscanf(const char _FAR *__buffer, const char _FAR *__format,
                        void _FAR *__arglist);
int     _CType unlink(const char _FAR *__path);
int     _Cdecl getc(FILE _FAR *__fp);

int     _Cdecl getchar(void);
int     _Cdecl putchar(const int __c);

int     _Cdecl putc(const int __c, FILE _FAR *__fp);
int     _Cdecl feof(FILE _FAR *__fp);
int     _Cdecl ferror(FILE _FAR *__fp);


#if !__STDC__
int     _Cdecl _FARFUNC fcloseall(void);
FILE   _FAR *_Cdecl _FARFUNC fdopen(int __handle, char _FAR *__type);
int     _Cdecl _FARFUNC fgetchar(void);
int     _Cdecl _FARFUNC flushall(void);
int     _Cdecl _FARFUNC fputchar(int __c);
FILE   _FAR * _Cdecl _fsopen (const char _FAR *__path, const char _FAR *__mode,
                  int __shflag);
int     _Cdecl getw(FILE _FAR *__stream);
int     _Cdecl putw(int __w, FILE _FAR *__stream);
int     _Cdecl rmtmp(void);
char   _FAR * _Cdecl _FARFUNC _strerror(const char _FAR *__s);
char   _FAR * _Cdecl _FARFUNC tempnam(char _FAR *__dir, char _FAR *__pfx);

#define fileno(f)       ((f)->fd)
#ifdef __MSC
#define _fileno(f)  fileno(f)
#endif

#endif  /* !__STDC__ */

int      _Cdecl _FARFUNC _fgetc(FILE _FAR *__stream);           /* used by getc() macro */
int      _Cdecl _FARFUNC _fputc(char __c, FILE _FAR *__stream); /* used by putc() macro */

void    _Cdecl _InitEasyWin(void);  /* Initialization call for Easy Windows */

#ifdef  __cplusplus
}
#endif

/*  The following macros provide for common functions */

#define ferror(f)   ((f)->flags & _F_ERR)
#define feof(f)     ((f)->flags & _F_EOF)

#define getc(f) \
	((--((f)->level) >= 0) ? (unsigned char)(*(f)->curp++) : \
    _fgetc (f))

#define putc(c,f) \
  ((++((f)->level) < 0) ? (unsigned char)(*(f)->curp++=(c)) : \
    _fputc ((c),f))

#define getchar()  getc(stdin)
#define putchar(c) putc((c), stdout)

#define ungetc(c,f) ungetc((c),f)   /* traditionally a macro */

#endif

