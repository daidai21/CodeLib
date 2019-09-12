/* =============================================================================
> File Name: file_dir.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 06:02:00 PM CST
============================================================================= */




// 一、 stat 结构和权限相关
/////////////////////////////////////////////////////////////
// 四个stat函数：返回文件或者目录的信息结构：

#include<sys/stat.h>
int stat(const char * restrict pathname, struct stat*restrict buf);
int fstat(int fd, struct stat* buf);
int lstat(const char* restrict pathname,struct stat *restrict buf);
int fstatat(int fd,const char*restrict pathname,struct stat*restrict buf,int flag);


// 二、访问测试和文件模式创建屏蔽字
/////////////////////////////////////////////////////////////
// 当用open()函数打开一个文件时，内核根据进程的有效用户ID和有效组ID为依据来执行访问权限测试。但是如果你想测试进程的实际用户ID和实际组ID是否能够通过权限测试时，可以用下列两个函数：

#include<unistd.h>
int access(const char *pathname,int mode);
int faccess(int fd,const char*pathname,int mode,int flag);

// 设置进程的文件模式创建屏蔽字的函数为：

#include<sys/stat.h>
mode_t umask(mode_t cmask);
// 三、修改文件访问权限和文件所属用户
/////////////////////////////////////////////////////////////
// 修改文件的现有的访问权限：

#include<sys/stat.h>
int chmod(const char*pathname,mode_t mode);
int fchmod(int fd,mode_t mode);
int fchmodat(int fd,const char*pathname,mode_t mode,int flag);

// 修改用户的ID和组ID：

#include<unistd.h>
int chown(const char *pathname,uid_t owner,gid_t group);
int fchown(int fd,uid_t owner,gid_t group);
int fchownat(int fd,const char *pathname,uid_t owner,gid_t group,int flag);
int lchown(const char *pathname,uid_t owner,gid_t group);


// 四、修改文件长度
/////////////////////////////////////////////////////////////

// 截断文件：通常可以用带O_TRUNC选项的open()函数来清空一个文件（截断到0）。但是如果希望截断文件使得文件大小为指定字节数，则可以用下列的函数：

#include<unistd.h>
int truncate(const char*pathname,off_t length);
int ftruncate(int fd,off_t length);



// 五、UNIX文件系统、硬链接、软链接、删除、重命名
/////////////////////////////////////////////////////////////
// link/linkat函数：创建一个指向现有文件的硬链接

#include<unistd.h>
int link(const char *existingpath,const char *newpath);
int linkat(int efd,const char*existingpath,int nfd,const char *newpath,int flag);

unlink函数：删除一个现有的目录项

#include<unistd.h>
int unlink(const char*pathname);
int unlinkat(int fd,const char*pathname,int flag);

// remove函数：解除对一个目录或者文件的链接。

#include<stdio.h>
int remove(const char *pathname);
// rename/renameat函数：重命名文件或目录

#include<stdio.h>
int rename(const char*oldname,const char *newname);
int renameat(int oldfd,const char*oldname,int newfd,const char* newname);


// symlink/symlinkat函数：创建一个符号链接

#include<unistd.h>
int symlink(const char*actualpath,const char *sympath);
int symlinkat(const char*actualpath,int fd,const char*sympath);

// readlink/readlinkat函数：打开符号链接本身


#include<unistd.h>
ssize_t readlink(const char *restrict pathname,char *restrict buf,size_t bufsize);
ssize_t readlinkat(int fd, const char* restrict pathname,char *restrict buf,
	size_t bufsize);



// 六、修改文件的时间
/////////////////////////////////////////////////////////////

// futimens/utimensat/utimes函数：修改文件的访问和修改时间

#include<sys/stat.h>
int futimens(int fd,const struct timespec times[2]);
int utimensat(int fd,const char*path,const struct timespec times[2],int flag);
#include<sys/time.h>
int utimes(const char*pathname,const struct timeval times[2]);



// 七、目录操作
/////////////////////////////////////////////////////////////

// mkdir/mkdirat函数创建一个空目录：

#include<sys/stat.h>
int mkdir(const char*pathname,mode_t mode);
int mkdirat(int fd,const char *pathname,mode_t mode);

// rmdir函数：删除一个空目录

#include<unistd.h>
int rmdir(const char *pathname);


// 读、写目录：对于某个目录具有访问权限的任何用户都可以读该目录。但是为了防止文件系统产生混乱，只有内核才能写目录。


#include<dirent.h>
DIR *opendir(const char *pathname);
DIR *fdopendir(int fd);
struct dirent *readdir(DIR *dp);
void rewinddir(DIR *dp);
int closedir(DIR *dp);
long telldir(DIR *dp);
void seekdir(DIR *dp,long loc);


// 与当前工作目录相关的有三个函数：

#include<unistd.h>
int chdir(const char *pathname);
int fchdir(int fd);
char *getcwd(char *buf,size_t size);


