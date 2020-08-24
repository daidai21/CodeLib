// package com.concurrency.patterns.producer_consumer;


import java.util.UUID;
import java.util.concurrent.BlockingDeque;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;


public class ProducerConsumer {

    private final BlockingQueue<String> data = new LinkedBlockingQueue<>();

    private Callable<Void> consumer = () -> {
        while (true) {
            String dataUint = this.data.poll(5, TimeUnit.SECONDS);
            if (dataUint == null) {
                break;
            }
            System.out.println("Consumed " + dataUint + " from " + Thread.currentThread().getName());
        }
        return null;
    };

    private Callable<Void> producer = () -> {
        for (Integer i = 0; i < 10000; ++i) {
            String dataUnit = UUID.randomUUID().toString();
            this.data.put(dataUnit);
        }
        return null;
    };

    public void run(long forHowLong, TimeUnit unit) throws InterruptedException {
        ExecutorService pool = Executors.newCachedThreadPool();
        pool.submit(producer);
        pool.submit(consumer);
        pool.submit(consumer);
        pool.shutdown();
        pool.awaitTermination(forHowLong, unit);
    }

    public static void main(final String[] args) {
        ProducerConsumer producerConsumer = new ProducerConsumer();
        try {
            producerConsumer.run(5, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
