# 集合

集合共有14种接口

* **接口类&具体类**
    * Collection:  一二级为接口，三级为具体实现
        * List `interface`
            * LinkedList: 通过双向链表实现
            * ArrayList: 同比C++的std::vector
            * Vector
        * Set
            * HashSet: 冲突链表方式，包装的HashMap
            * LinkedHashSet: 包装的LinkedHashMap
            * TreeSet
        * SortedSet
            * TreeSet: 红黑树
        * NavigableSet
        * Map
            * HashMap: 冲突链表方式
            * LinkedHashMap: HashMap+双向链表实现的
            * HashTable
            * TreeMap
            * WeakHashMap: 有GC的Map，类似cache的作用
        <!-- * Map.Entry -->
        * SortedMap
            * TreeMap: 红黑树
        * ConcurrentMap
        * NavigableMap
        * ConcurrentNavigableMap
        * Enumeration
        * Queue
            * PriorityQueue: 保证每次取出的元素都是队列中权值最小的，小根堆实现的
            * LinkedList
        * Deque
            * ArrayDeque
        * BlockingQueue
        * BlockingDeque

* **算法Collections**
    * ...
* **其他**
    * Vector
    * Stack
    * Dictionary
    * Hashtable
    * Properties
    * BitSet

===

https://raw.githubusercontent.com/Snailclimb/JavaGuide/master/docs/java/collection/images/Java-Collections.jpeg


![](util.png)
