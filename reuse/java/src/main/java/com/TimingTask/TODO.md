* RingBufferWheel

**java的定时任务解决方案**

* 单机
    * 基于线程while和sleep实现的、基于排序容器作为任务存储的实现方案
    * 常见就是最小堆实现的单线程的Timer、线程池的ScheduledThreadPoolExecutor
    * 另外就是效率更高的时间轮的实现方案，代表有RingBufferWheel；


https://www.jianshu.com/p/98c4ba7eaccc
