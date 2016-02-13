/**************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************
 ********									                                               ********
 ********       ROLLRAT SOFTWARE						                             	   ********
 ********       SINCE : 2009 - 2012							                               ********
 ********										                                           ********
 ********       Header : <rstdio.h>      							                       ********
 ********										                                           ********
 **************************************************************************************************
 **************************************************************************************************
 **************************************************************************************************/

/* 
   Standard input and standard output (re-written file) 
 */

#ifdef __cplusplus
extern "C" {
#endif
typedef unsigned size_t;
typedef long    fpos_t;
struct  _iobuf{
        int    level;
        int    flags;
        char   fd;
        char   hold;
        int    bsize;
        char   *buffer;
        char   *curp;
        int    istemp;
        short  token;
        };
typedef struct _iobuf FILE;
void    clearerr(FILE *__stream);
int     fclose(FILE *__stream);
int     fflush(FILE*__stream);
int     fgetc(FILE *__stream);
int     fgetpos(FILE *__stream, FILE *__pos);
char    fgets(char*__s, int __n, FILE *__stream);
FILE   *fopen(const char *__path, const char *__mode);
int     fprintf(FILE *__stream, const char *__format, ...);
int     fputc(int __c, FILE *__stream);
int     fputs(const char *__s, FILE *__stream);
size_t  fread(void *__ptr, size_t __size, size_t __n,FILE *__stream);
FILE    freopen(const char *__path, const char *__mode,FILE *__stream);
int     fscanf(FILE *__stream, const char *__format, ...);
int     fseek(FILE *__stream, long __offset, int __whence);
int     fsetpos(FILE *__stream, const fpos_t *__pos);
long    ftell(FILE *__stream);
size_t  fwrite(const void *__ptr, size_t __size, size_t __n,FILE *__stream);
char    gets(char *__s);
void    perror(const char *__s);
int     printf(const char *__format, ...);
int     puts(const char *__s);
int     remove(const char *__path);
int     rename(const char *__oldname,const char *__newname);
void    rewind(FILE *__stream);
int     scanf(const char *__format, ...);
void    setbuf(FILE *__stream, char *__buf);
int     setvbuf(FILE *__stream, char *__buf,int __type, size_t __size);
int     sprintf(char *__buffer, const char *__format, ...);
int     sscanf(const char *__buffer,const char *__format, ...);
char   *strerror(int __errnum);
FILE   *tmpfile(void);
char   *tmpnam(char *__s);
int     ungetc(int __c, FILE *__stream);
int     vfprintf(FILE *__stream, const char *__format,void *__arglist);
int     vfscanf(FILE *__stream, const char *__format,void *__arglist);
int     vprintf(const char *__format, void *__arglist);
int     vscanf(const char *__format, void *__arglist);
int     vsprintf(char *__buffer, const char *__format,void *__arglist);
int     vsscanf(const char *__buffer, const char *__format,void *__arglist);
int     unlink(const char *__path);
int     getc(FILE *__fp);
int     getchar(void);
int     putchar(const int __c);
int     putc(const int __c, FILE *__fp);
int     feof(FILE *__fp);
int     ferror(FILE *__fp);
#ifdef  __cplusplus
}
#endif