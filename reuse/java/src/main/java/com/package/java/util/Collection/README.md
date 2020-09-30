

* Collection \<interface\>
    * Iterable \<interface\>
    * List \<interface\>
        * ArrayList
        * LinkedList  双向链表
        * Vector
    * Queue \<interface\>
        * PriorityQueue
        * LinkedList
    * Dequeue \<interface\>
        * ArrayDeque
        * LinkedList
    * Set \<interface\>
        * HashSet
        * LinkedHashSet
        * SortedSet \<interface\>
            * TreeSet

* Map \<interface\>
    * HashTable
    * HashMap
    * SortedMap \<interface\>
        * TreeMap

**迭代器**

* Iterator \<interface\>


### **对比**

**List**

---

Collections 提供了多个synchronizedXxx()方法·，该方法可以将指定集合包装成线程同步的集合，从而解决多线程并发访问集合时的线程安全问题。

```java
synchronizedCollection(Collection<T>  c) //返回指定 collection 支持的同步（线程安全的）collection。
synchronizedList(List<T> list)//返回指定列表支持的同步（线程安全的）List。
synchronizedMap(Map<K,V> m) //返回由指定映射支持的同步（线程安全的）Map。
synchronizedSet(Set<T> s) //返回指定 set 支持的同步（线程安全的）set。
```
