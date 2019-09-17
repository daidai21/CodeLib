/* =============================================================================
> File Name: std_io_lib.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 06:07:37 PM CST
============================================================================= */



// 流和 FILE对象
///////////////////////////////////////////////////////////

// fwide函数：设置流的定向

#include<stdio.h>
#include<wchar.h>
int fwide(FILE *fp,int mode);


// setbuf/setvbuf函数：设置流的缓冲类型


#include<stdio.h>
void setbuf(FILE *restrict fp,char *restrict buf);
int setvbuf(FILE *restrict fp,char* restrict buf,int mode,size_t size);

// fflush函数：手动冲洗一个流

#include<stdio.h>
int fflush(FILE *fp);

// 打开关闭流
///////////////////////////////////////////////////////////


// fopen/freopen/fdopen函数：打开标准IO流

#include<stdio.h>
FILE *fopen(const char*restrict pathname,const char*restrict type);
FILE *freopen(const char*restrict pathname,const char*restrict type,\
	FILE *restrict fp);
FILE *fdopen(int fd,const char*type);

// fclose：关闭一个打开的流

#include<stdio.h>
int fclose(FILE *fp);


// 读写流
///////////////////////////////////////////////////////////


// getc/fgetc/getchar函数：一次读一个字符：

#include<stdio.h>
int getc(FILE*fp);
int fgetc(FILE*fp);
int getchar(void);

// ferror/feof函数：查看是读文件出错，还是到达读文件遇到尾端

#include<stdio.h>
int ferror(FILE *fp);
int feof(FILE *fp);
// clearerr函数：清除文件出错标志和文件结束标志

#include<stdio.h>
void clearerr(FILE *fp)

// ungetc函数：将字符压回流中

#include<stdio.h>
int ungetc(int c,FILE *fp);

// putc/fputc/putchar函数：一次写一个字符

#include<stdio.h>
int putc(int c,FILE*fp);
int fputc(int c,FILE*fp);
int putchar(int c);
// fgets/gets函数：一次读一行字符：

#include<stdio.h>
char *fgets(char *restrict buf,int n, FILE* restrict fp);
char *gets(char *buf);
// fputs/puts函数：一次写一行字符：

#include<stdio.h>
int fputs(const char* restrict str,FILE*restrict fp);
int puts(const char*str);
// fread/fwrite函数：执行二进制读写IO

#include<stdio.h>
size_t fread(void *restrict ptr,size_t size,size_t nobj,FILE *restrict fp);
size_t fwrite(const void*restrict ptr,size_t size,size_t nobj,FILE *restrict fp);


// 通过 ftell/fseek函数：

#include<stdio.h>
long ftell(FILE *fp);
// ftell就是返回这种字节位置。

#include<stdio.h>
int fseek(FILE *fp,long offset,int whence);
#include<stdio.h>
void rewind(FILE *fp);

// ftello/fseeko与ftell/fseek相同

#include<stdio.h>
off_t ftello(FILE *fp);
#include<stdio.h>
int fseeko(FILE *fp,off_t offset,int whence);


// fgetpos/fsetpos函数：由 ISO C 引入

#include<stdio.h>
int fgetpos(FILE *restrict fp,fpos_t *restrict pos);
int fsetpos(FILE * fp,const fpos_t * pos);


// 格式化IO
///////////////////////////////////////////////////////////
// 格式化输出函数：

#include<stdio.h>
int printf(const char *restrict format,...);
int fprintf(FILE *restrict fp,const char*restrict format,...);
int dprintf(int fd,const char *restrict format,...);
int sprintf(char *restrict buf,const char*restrict format,...);
int snprintf(char *restrict buf,size_t n,const char *restrict format,...);

// printf族的变体：将可变参数(...)替换成了va_list arg:

#include<stdarg.h>
#include<stdio.h>
int vprintf(const char *restrict format,va_list arg);
int vfprintf(FILE *restrict fp,const char*restrict format,va_list arg);
int vdprintf(int fd,const char *restrict format,va_list arg);
int vsprintf(char *restrict buf,const char*restrict format,va_list arg);
int vsnprintf(char *restrict buf,size_t n,const char *restrict format,va_list arg);



// 格式化输入函数：

#include<stdio.h>
int scanf(const char*restrict format,...);
int fscanf(FILE *restrict fp,const char *restrict format,...);
int sscanf(const char *restrict buf,const char *restrict format,...);

// scanf族也有一类变体：将可变参数(...)替换成了va_list arg:

#include<stdarg.h>
#include<stdio.h>
int vscanf(const char*restrict format,va_list arg);
int vfscanf(FILE *restrict fp,const char *restrict format,va_list arg);
int vsscanf(const char *restrict buf,const char *restrict format,va_list arg);




// 其他
///////////////////////////////////////////////////////////


// fileno函数：获取文件对象的文件描述符

#include<stdio.h>
int fileno(FILE *fp);


// tmpnam/tmpfile函数：创建临时文件

#include<stdio.h>
char *tmpnam(char *ptr);
FILE *tmpfile(void);


// mkdtemp/mkstemp函数：创建临时文件（由SUS 标准给出）

#include<stdlib.h>
char *mkdtemp(char *template);
int mkstemp(char *template);


// 创建内存流：

#include<stdio.h>
FILE *fmemopen(void *restrict buf,size_t size,const char *restrict type);



// 创建内存流的其他两个函数：

#include<stdio.h>
FILE *open_memstream(char **bufp,size_t *sizep);
#include <wchar.h>
FILE *open_wmemstream(wchar_t **bufp,size_t *sizep);


