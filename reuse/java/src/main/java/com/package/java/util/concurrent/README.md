重点

JUC


**线程安全集合**

* ConcurrentHashMap: 可以看作是线程安全的 HashMap
* CopyOnWriteArrayList:可以看作是线程安全的 ArrayList，在读多写少的场合性能非常好，远远好于 Vector.
* ConcurrentLinkedQueue:高效的并发队列，使用链表实现。可以看做一个线程安全的 LinkedList，这是一个非阻塞队列。
* BlockingQueue: 这是一个接口，JDK 内部通过链表、数组等方式实现了这个接口。表示阻塞队列，非常适合用于作为数据共享的通道。
* ConcurrentSkipListMap :跳表的实现。这是一个Map，使用跳表的数据结构进行快速查找。



**ConcurrentHashMap**


TODO
https://snailclimb.gitee.io/javaguide/#/docs/java/collection/Java%E9%9B%86%E5%90%88%E6%A1%86%E6%9E%B6%E5%B8%B8%E8%A7%81%E9%9D%A2%E8%AF%95%E9%A2%98?id=_149-concurrenthashmap-%e5%92%8c-hashtable-%e7%9a%84%e5%8c%ba%e5%88%ab
