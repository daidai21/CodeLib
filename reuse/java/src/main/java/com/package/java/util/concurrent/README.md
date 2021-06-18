# JUC (java.util.concurrent)

![](concurrent.jpg)

![](并发容器.png)

**线程安全集合**

* ConcurrentHashMap: 可以看作是线程安全的 HashMap
* CopyOnWriteArrayList:可以看作是线程安全的 ArrayList，在读多写少的场合性能非常好，远远好于 Vector.
* ConcurrentLinkedQueue:高效的并发队列，使用链表实现。可以看做一个线程安全的 LinkedList，这是一个非阻塞队列。
* BlockingQueue: 这是一个接口，JDK 内部通过链表、数组等方式实现了这个接口。表示阻塞队列，非常适合用于作为数据共享的通道。
* ConcurrentSkipListMap :跳表的实现。这是一个Map，使用跳表的数据结构进行快速查找。

## ConcurrentHashMap

TODO

https://snailclimb.gitee.io/javaguide/#/docs/java/collection/Java%E9%9B%86%E5%90%88%E6%A1%86%E6%9E%B6%E5%B8%B8%E8%A7%81%E9%9D%A2%E8%AF%95%E9%A2%98?id=_149-concurrenthashmap-%e5%92%8c-hashtable-%e7%9a%84%e5%8c%ba%e5%88%ab


https://doc.codingdict.com/java_api/java/util/concurrent/ConcurrentHashMap.html

1.7 vs 1.8


## Queue

TODO: 7中队列对比，表格

### DelayQueue

https://zhuanlan.zhihu.com/p/67948565

业务中并没有用到，MQ可以这样

爬虫 ip/http代理池
    每个ip/http需要需要间歇工作
        https://github.com/javagaorui5944/ProxyIpPool/blob/f42c63c4f780ab289e66e7d94be527567acdcdb9/src/main/java/com/myapp/proxy/ProxyPool.java

延迟队列的6种方式
https://segmentfault.com/a/1190000022718540

### LinkedBlockingQueue

单链表实现的

https://doc.codingdict.com/java_api/java/util/concurrent/BlockingQueue.html

https://www.cnblogs.com/teach/p/10665947.html
https://www.jianshu.com/p/9394b257fdde

===

有界队列：就是有固定大小的队列
无界队列：指的是没有设置固定大小的队列

===

# CopyOnWriteArrayList

优点：
保证多线程的并发读写的线程安全
数据一致性完整  因为加锁了，并发数据不会乱
解决了像ArrayList、Vector这种集合多线程遍历迭代问题
    线程a在遍历list b，然后线程c写入数据，a在遍历的还是list b的修改前的情况
    https://segmentfault.com/a/1190000010277948  ArrayList使用的计数器机制  多线程遍历修改会出现ConcurrentModificationException问题


缺点：
内存消耗大
保证数据的最终一致性，不能保证数据的实时一致性。 实时性不高

场景：
读多写少
集合不大

比如白名单，黑名单，商品类目的访问和更新场景
