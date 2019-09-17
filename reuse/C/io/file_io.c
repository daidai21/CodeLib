/* =============================================================================
> File Name: file_io.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:57:56 PM CST
============================================================================= */
// 一、打开、创建文件、关闭文件

//////////////////////////////////////////////////
// open和openat函数：打开文件

#include<fcntl.h>
int open(const char* path,int oflag,.../*mode_t mode*/);
int openat(int fd,const char*path,int oflag,.../*mode_t mode */);

// creat函数：创建一个新文件

#include<fcntl.h>
int creat(const char*path,mode_t mode);

// close函数：关闭文件

#include<unistd.h>
int close(int fd);

// 二、定位、读、写文件
//////////////////////////////////////////////////
// lseek函数：设置打开文件的偏移量

#include<unistd.h>
off_t lseek(int fd, off_t offset,int whence);

// read函数：读取文件内容

#include<unistd.h>
ssize_t read(int fd,void *buf,size_t nbytes);

// write函数：想文件写数据

#include<unistd.h>
ssize_t write(int fd,const void *buf,size_t nbytes);


// 三、 原子操作、同步、复制、修改文件描述符
//////////////////////////////////////////////////

// pread/pwrite：原子定位读和原子定位写
#include<unistd.h>
ssize_t pread(int fd,void*buf,size_t nbytes,off_t offset);
ssize_t pwrite(int fd,const void*buf,size_t nbytes,off_t offset);


// dup/dup2：复制一个现有的文件描述符：

#include<unistd.h>
int dup(int fd);
int dup2(int fd,int fd2);


// 你也可以调用下列函数来显式的将延迟写的数据库写入磁盘
#include<unistd.h>
int fsync(int fd);
int fdatasync(int fd);
void sync(void);


// fcntl函数：改变已经打开的文件的属性

#include<fcntl.h>
int fcntl(int fd,int cmd,.../* int arg */);



