===

**数据类型**

![](./数据类型.png)

**String 相关**

```java
import java.lang.StringBuffer;
import java.lang.StringBuilder;
import java.lang.String;
```

* 操作少量的数据: 适用 String
* 单线程操作字符串缓冲区下操作大量数据: 适用 StringBuilder
* 多线程操作字符串缓冲区下操作大量数据: 适用 StringBuffer




===

**异常处理**

Throwable
Error
Exception

* 在Java中定义了两种类型的异常和错误。
    * JVM(Java虚拟机) 异常：由 JVM 抛出的异常或错误。例如：NullPointerException 类，ArrayIndexOutOfBoundsException 类，ClassCastException 类。
    * 程序级异常：由程序或者API程序抛出的异常。例如 IllegalArgumentException 类，IllegalStateException 类。
* .
    * 受查异常：受查异常会在编译时被检测。
    * 非受查异常：非受查异常不会在编译时被检测。JAVA 中 Error 和 RuntimeException 类的子类属于非受查异常，除此之外继承自 Exception 的类型为受查异常。

![](./异常处理.png)

===

ThreadLocal

内存泄漏


ThreadLocalMap中的key为若引用，value为强引用；ThreadLocal在没有外部对象强引用时，发生GC时key会被回收，而value不会被回收，entry就会变为<null, value>，如果theadlocal线程一直运行，entry对象就会永远不会被回收，发生内存泄漏

```java
// 使用完threadLocal后一定要调用remove方法，不然可能会导致内存泄漏
ThreadLocal<Variable> threadLocal = new ThreadLocal<Variable>();
try {
    threadLocal.set(new Variable());
    ...
} finally {
    threadLocal.remove();
}
```

===


Thread Local Storage (TLS)

https://github.com/alibaba/transmittable-thread-local

ThreadLocalMap

二级map = { threadId: { key: value, ... }... }

多线程安全性解决方案
1. 采用synchronized进行同步控制，但是效率略低，使得并发变同步（串行）
2. 采用ThreadLocal线程本地存储，为每个使用该变量的线程都存储一个本地变量副本（线程互不相干）
两种线程安全方案的区别
1. synchronized同步机制采用了“以时间换空间”的方式，仅仅只提供一份变量，让参与的多个不同的线程排队进行访问
2. ThreadLocal采用“以空间换时间”的方式，为参与的每个线程都各自提供一份本地副本，因此可以做到同时访问而互不影响。
