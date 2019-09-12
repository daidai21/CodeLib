/* =============================================================================
> File Name: io.c
> Author: DaiDai
> Mail: daidai4269@aliyun.com
> Created Time: Thu 12 Sep 2019 05:39:41 PM CST
============================================================================= */


// 非阻塞 IO
/////////////////////////////////////////////////////////
fcntl(fd,F_SETFL,O_NONBLOCK)

// 记录锁
/////////////////////////////////////////////////////////
// POSIX.1中，通过fcntl设置文件记录锁：

#include<fcntl.h>
int fcntl(int fd,int cmd,.../*struct flock *flockptr */);


// IO多路转换
/////////////////////////////////////////////////////////
////////////////// select

// select函数：执行IO多路转换
#include<sys/select.h>
int select(int maxfdp1,fd_set *restrict readfds,fd_set *restrict writefds,
		fd_set *restrict exceptfds,struct timeval *restrict tvptr);
#include<sys/select.h>
int FD_ISSET(int fd,fd_set *fdset);
void FD_CLR(int fd,fd_set *fdset);
void FD_SET(int fd,fd_set *fdset);
void FD_ZERO(fd_set *fdset);
// POSIX.1也定义了一个pselect函数，它是select的变体：
#include<sys/select.h>
int pselect(int maxfdp1,fd_set *restrict readfds,fd_set *restrict writefds,
		fd_set *restrict exceptfds,const struct timespec *restrict tsptr,
		const sigset_t *restrict sigmask);


////////////////// poll
// 函数poll类似于select，但是接口不同。其原型为：

#include<poll.h>
int poll(struct pollfd fdarray[],nfds_t nfds,int timeout);


// 异步IO
/////////////////////////////////////////////////////////
// POSIX 异步 IO
/////////////////////////////////////////////////////////
// aio_read/aio_write函数：异步读/写操作
#include<aio.h>
int aio_read(struct aiocb *aiocb);
int aio_write(struct aiocb *aiocb);

// aio_error函数：获取一个异步读、写或者同步操作的完成状态

#include<aio.h>
int aio_error(const struct aiocb *aiocb);
// aio_return函数：如果异步操作成功，该函数获取异步操作的返回值

#include<aio.h>
ssize_t aio_return(const struct aiocb *aiocb);
// 如果想等待异步操作的完成，则可以使用aio_suspend函数：

// 如果想等待异步操作的完成，则可以使用aio_suspend函数：

#include<aio.h>
int aio_suspend(const struct aiocb *const list[],int nent,
				const struct timespec *timeout);


// aio_cancel函数：取消异步IO：

#include<aio.h>
int aio_cacel(int fd,struct aiocb *aiocb);

// lio_listio函数：提交一系列由一个AIO控制块列表描述的IO请求

#include<aio.h>
int lio_listio(int mode,struct aiocb *restrict const list[restrict_arr],
	int nent,struct sigenvent* restrict sigev);


// readv/writev
/////////////////////////////////////////////////////////
// readv和writev用于在一次函数调用中读、写多个非连续缓冲区。也称它们为散布读与聚集写

#include<sys/uio.h>
ssize_t readv(int fd,const struct iovec *iov,int iovcnt);
ssize_t writev(int fd,const struct iovec *iov,int iovcnt);


// 存储映射 IO
/////////////////////////////////////////////////////////
// mmap函数：将一个给定的文件映射到一个存储区域中：

#include<sys/mman.h>
void *mmap(void *addr,size_t len,int prot,int flag,int fd,
// mprotect函数：修改一个现有映射区的权限：

#include<sys/mman.h>
int mprotect(void *addr,size_t len,int prot);
// 如果共享映射中的页已修改，则可以调用msync函数将该页冲洗到底层文件中。它类似于fsync，但是作用于存储映射区：

#include<sys/mman.h>
int msync(void *addr,size_t len,int flags);
// 当进程终止时，会自动解除存储映射区的映射。你也可以直接调用munmap函数来手动解除映射区。

#include<sys/mman.h>
int nummap(void* addr,size_t len);
