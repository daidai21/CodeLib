# socket echo program

| 名称 | 描述 | 支持平台 | 优点 | 缺点 | 模式 | 备注 |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| 多进程 |  | all  |  |   |  |  |
| 多线程|  |  all  |  |   |  |  |
| tcp select |   | all  | 跨平台 | 单个进程打开的文件描述是有一定限制的，它由FD_SETSIZE设置，默认值是1024，采用数组存储，虽然可以通过编译内核改变，但相对麻烦。 另外在检查数组中是否有文件描述需要读写时，采用的是线性扫描的方法，即不管这些socket是不是活跃的，我都轮询一遍，所以效率比较低 |  |  |
| tcp poll |   | all  | 采样链表的形式存储，它监听的描述符数量没有限制，可以超过select默认限制的1024大小 | 类似select，另外在检查链表中是否有文件描述需要读写时，采用的是线性扫描的方法，即不管这些socket是不是活跃的，我都轮询一遍，所以效率比较低 |  |  |
| tcp epoll  |   | Linux | 监视的描述符数量不受限制。IO的效率不会随着监视fd的数量的增长而下降。 |  | Reacor |  |
| tcp kqueue |   | MacOS  |  |   | Reacor |  |
| tcp iocp |  |  Windows |  |   | Proactor | asynchronous I/O |

Reactor and Proactor

### schedule

* [x] tcp
* [x] udp
* [x] tcp multi thread
* [x] tcp select
* [x] tcp poll
* [-] tcp epoll
    * code over, not test, need linux

### Links

https://github.com/yuanrw/tcp-server-client
https://github.com/shineyr/Socket
https://github.com/spch2008/Socket
