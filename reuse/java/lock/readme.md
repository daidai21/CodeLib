# Java Lock

**悲观锁**

* 优点：
* 缺点：
* 适用场景：适合写操作多的场景，先加锁可以保证写操作时数据正确

```java
// synchronized
public synchronized void testMethod() {
    // 操作同步资源
}

// ReentrantLock
import java.util.concurrent.locks.ReentrantLock;
private ReentrantLock lock = new ReentrantLock(); // 需要保证多个线程使用的是同一个锁
public void modifyPublicResources() {
    this.lock.lock();
    // 操作同步资源
    this.lock.unlock();
}
```

**乐观锁**

* 优点：
* 缺点：
* 适用场景：适合读操作多的场景，不加锁的特点能够使其读操作的性能大幅提升

```java
import java.util.concurrent.atomic.AtomicInteger;
private AtomicInteger atomicInteger = new AtomicInteger();  // 需要保证多个线程使用的是同一个AtomicInteger
atomicInteger.incrementAndGet(); //执行自增1
```

**自旋锁**

* 优点：
* 缺点：
* 适用场景：

**适应性自旋锁**

* 优点：
* 缺点：
* 适用场景：


无锁
偏向锁
轻量级锁
重量级锁
公平锁
非公平锁
可重入锁
非可重入锁
独享锁
共享锁
