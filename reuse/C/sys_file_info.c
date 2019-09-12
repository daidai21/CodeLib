/* =============================================================================
> File Name: sys_file_info.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 06:13:54 PM CST
============================================================================= */


// 系统文件
/////////////////////////////////////////////////////
// getpwuid/getpwnam函数：读取口令文件：

#include<pwd.h>
struct passwd* getpwuid(uid_t uid);
struct passwd* getpwnam(const char*name);


// 查看整个口令文件，使用下面的函数：

#include<pwd.h>
struct passwd *getpwent(void);
void setpwent(void);
void endpwent(void);

// 用于读取阴影口令文件的函数为：

#include<shadow.h>
struct spwd *getspnam(const char*name);
struct spwd *getspent(void);
void setspent(void);
void endspent(void);


// getgrgid/getgrnam函数：查看组文件：

#include<grp.h>
struct group* getgrgid(gid_t gid);
struct group* getgrnam(const char* name);

// 查看整个组文件，使用下面的函数：

#include<grp.h>
struct group *getgrent(void);
void setgrent(void);
void endgrent(void);


// UNIX中还提供了附属组ID。其中获取和设置附属组ID的函数为：

#include<unistd.h>
int getgroups(int gidsetsize,gid_t grouplist[]);

#include<grp.h>    	//对Linux
#include<unistd.h>	//对 FreeBSD, Mac OS X, Solaris
int setgroups(int ngroups,const gid_t grouplist[]);

#include<grp.h>    	//对Linux
#include<unistd.h>	//对 FreeBSD, Mac OS X, Solaris
int initgroups(const char *username, gid_t basegid);


// uname函数：返回主机和操作系统的有关信息：

#include<sys/utsname.h>
int uname(struct utsname *name);



// gethostname函数：返回主机名。改名字通常就是 TCP/IP 网络上主机的名字：

#include<unistd.h>
int gethostname(char *name,int namelen);



// 时间和日期
/////////////////////////////////////////////////////

// time函数：返回当前的日历时间

#include<time.h>
time_t time(time_t *calptr);
clock_gettime函数：用于获取指定的时钟类型的时间：

#include<sys/time.h>
int clock_gettime(clockid_t clock_id,struct timespec *tsp);


// clock_getres函数：时间精度调整

#include<sys/time.h>
int clock_getres(clockid_t clock_id,struct timespec *tsp);


// clock_settime函数：设置时间

#include<sys/time.h>
int clock_settime(clockid_t clock_id,const struct timepsec *tsp);




// gettimeofday函数：更高精度的获取当前时间（但是目前已经弃用）

#include<sys/time.h>
int gettimeofday(struct timeval *restrict tp,void *restrict tzp);



// gmtime/localtime函数：将日历时间转换成struct tm结构：

#include<time.h>
struct tm* gmtime(const time_t *calptr);
struct tm* localtime(const time_t *calptr);


// mktime函数：以本地时间的年月日等作为参数，将其变化成time_t值：

#include<time.h>
time_t mktime(struct tm*tmptr);


// strftime/strftime_l函数：类似printf的打印时间的函数。它们可以通过可用的多个参数来定制产生的字符串

#include<time.h>
size_t strftime(char *restrict buf,size_t maxsize,const char*restrict format,
	const struct tm* restrict tmptr);
size_t strftime_l(char *restrict buf,size_t maxsize,const char*restrict format,
	const struct tm* restrict tmptr,locale_t locale);



// strptime函数：它是strftime的逆向过程，把时间字符串转换成struct tm时间

#include<time.h>
char *strptime(const char*restrict buf,const char*restrict format,
	struct tm*restrict tmptr);

