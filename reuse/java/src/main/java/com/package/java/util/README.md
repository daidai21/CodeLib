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

![java.util.*](util.png)

## String、StringBuffer、StringBuilder

|  | String | StringBuffer | StringBuilder |
| :-: | :-: | :-: | :-: |
| 原理 | 每次字符串操作都是生产新的String对象 | 和StringBuilder原理一样，只是加了锁 | 类似std::string |
| 是否可变 | 否 | 是 | 是 |
| 是否线程安全 | 是 | 是 | 否 |
| 使用场景 | 操作少量的数据 | 多线程操作大量数据 | 单线程操作大量数据 |

## Vector、ArrayList、LinkedList

|  | Vector | ArrayList | LinkedList |
| :-: | :-: | :-: | :-: |
| 原理 | 和ArrayList一样，加了锁 | 可变大小的数组 | 双向链表 |
| 是否线程安全 | 是 | 否 | 否 |
| get() |  | O(1) | O(n) |
| add() |  | O(1) | O(1) |
| remove() |  | O(n) | O(n) |

## HashMap、LinkedHashMap、HashTable、TreeMap、WeakHashMap

|  | HashMap | LinkedHashMap | HashTable | TreeMap | WeakHashMap |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 原理 | 冲突链表方式 | HashMap+双向链表实现的 |  | 红黑二叉树的NavigableMap的实现 | 有GC的Map，类似cache的作用 |
| 优点 |  |  |  |  |  |
| 缺点 |  |  | 多线程操作锁是在整个table上的，效率低下 |  |  |
| 是否线程安全 |  |  | 是 | 否 |  |

## HashSet、LinkedHashSet、TreeSet、SortedSet、TreeSet、NavigableSet

Set和Map基本一样， value是null类型

## Queue & Stack
