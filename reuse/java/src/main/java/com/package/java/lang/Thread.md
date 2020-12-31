
Thread 状态

```java
public enum State {
    NEW, // 线程尚未启动
    RUNNABLE, // 可运行的状态，可能在等其他资源，如cpu
    BLOCKED, // 阻塞状态，等待锁的释放
    WAITING, // 等待另一个线程
    TIMED_WAITING, // 指定等待时间的等待线程的线程状态
    TERMINATED; // 执行结束
}
```
