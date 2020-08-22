package com.concurrency.features.atomics;


/* ****************************************************************************
 * File Name   : UsingAtomics.java
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 四  8/20 01:17:39 2020
 *************************************************************************** */


import java.util.concurrent.TimeUnit;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.atomic.AtomicInteger;


public class UsingAtomics {
    public static void main(String[] args) throws InterruptedException {
        AtomicCounter counter = new AtomicCounter();
        ExecutorService cachedThreadPool = Executors.newCachedThreadPool();
        for (int i = 0; i < 10000; ++i) {
            cachedThreadPool.execute(() -> counter.increment());
        }
        cachedThreadPool.shutdown();
        cachedThreadPool.awaitTermination(4000, TimeUnit.SECONDS);
        System.out.println("Result shound be 10000: Actual result is: " + counter.get());
    }

    /**
     * A counter using AtomicInteger
     */
    static class AtomicCounter {
        private AtomicInteger atomicInteger = new AtomicInteger();

        public void increment() {
            atomicInteger.incrementAndGet();
        }

        public void decrement() {
            atomicInteger.decrementAndGet();
        }

        public int get() {
            return atomicInteger.get();
        }
    }
}
