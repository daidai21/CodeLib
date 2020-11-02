**Java中的线程有7种状态：**

* new
* runable 
* running 
* blocked
* waiting 
* time_waiting
* terminate

**Runnable VS Runnable**

```java
@FunctionalInterface
public interface Callable<V> {
    V call() throws Exception;
}
```

```java
@FunctionalInterface
public interface Runnable {
    public abstract void run();
}
```
