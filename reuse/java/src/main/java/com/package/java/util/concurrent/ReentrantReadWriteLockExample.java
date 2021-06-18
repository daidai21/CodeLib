import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.Lock;

public class ReentrantReadWriteLockExample {
    public static void main(String[] args) {
        Counter counter = new Counter(1);    
        new Thread( () -> { System.out.println(counter.get()); } ).run();    
        new Thread( () -> { counter.add(1); } ).run();
        new Thread( () -> { System.out.println(counter.get()); } ).run();    
        new Thread( () -> { counter.add(1); } ).run();
        new Thread( () -> { System.out.println(counter.get()); } ).run();    
    }
}

class Counter {
    private final ReadWriteLock rwlock = new ReentrantReadWriteLock();

    private final Lock rlock = rwlock.readLock();

    private final Lock wlock = rwlock.writeLock();

    private int count;

    public Counter(int count) {
        this.count = count;
    }

    public void add(int val) {
        wlock.lock(); // 加写锁
        try {
            count += val;
        } finally {
            wlock.unlock(); // 释放写锁
        }
    }

    public int get() {
        rlock.lock(); // 加读锁
        try {
            return count;
        } finally {
            rlock.unlock(); // 释放读锁
        }
    }
}
