* RingBufferWheel

**java的定时任务解决方案**

* 单机
    * 基于线程while和sleep实现的、基于排序容器作为任务存储的实现方案
    * 常见就是最小堆实现的单线程的Timer、线程池的ScheduledThreadPoolExecutor
    * 另外就是效率更高的时间轮的实现方案，代表有RingBufferWheel；


Timer和TimerTask

JDK自带 ：JDK自带的Timer以及JDK1.5+ 新增的ScheduledExecutorService；
Quartz ：简单却强大的JAVA作业调度框架
Spring3.0以后自带的task ：可以将它看成一个轻量级的Quartz，而且使用起来比Quartz简单许多；

===

[CircularFifoBuffer](https://commons.apache.org/proper/commons-collections/javadocs/api-3.2.2/org/apache/commons/collections/buffer/CircularFifoBuffer.html)

