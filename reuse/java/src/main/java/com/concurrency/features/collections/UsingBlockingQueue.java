package com.concurrency.features.collections;


/* ****************************************************************************
 * File Name   : UsingBlockingQueue.java
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 四  8/20 01:31:03 2020
 *************************************************************************** */


/**
 * Implementations: LinkedBlockingQueue, ArrayBlockingQueue, 
 * PriorityBlockingQueue, SynchronizedQueue.
 */


import java.util.Random;
import java.util.UUID;
import java.util.concurrent.LinkedBlockingQueue;


public class UsingBlockingQueue {
    public static void main(String[] args) {
        System.out.println("=== BlockingQueue ===");

        LinkedBlockingQueue<UUID> uuidQueue = new LinkedBlockingQueue<UUID>(10);

        System.out.println("Queue will execute for 10s");

        // Multiple consumers
        Runnable runConsumers = () -> {
            while (!Thread.currentThread().isInterrupted()) {
                try {
                    UUID uuid = uuidQueue.take();
                    System.out.println("Consumed: " + uuid + " by " + Thread.currentThread().getName());
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                    System.err.println("Cunsumer Finished");
                }
            }
        };
        Thread consumer1 = new Thread(runConsumers);
        consumer1.start();
        Thread consumer2 = new Thread(runConsumers);
        consumer2.start();

        // Producer Thread
        Runnable runProducer = () -> {
            try {
                while (!Thread.currentThread().isInterrupted()) {
                    Random random = new Random();
                    Thread.sleep(random.nextInt(1000));
                    UUID ranUuid = UUID.randomUUID();
                    System.out.println("Produced: " + ranUuid + " by " + Thread.currentThread().getName());
                    uuidQueue.put(ranUuid);
                }
            } catch (InterruptedException e) {
                System.err.println("Producer Finished");
            }
        };

        // Multiple producers
        Thread producer1 = new Thread(runProducer);
        producer1.start();
        Thread producer2 = new Thread(runProducer);
        producer2.start();
        Thread producer3= new Thread(runProducer);
        producer3.start();

        try {
            // Queue will run for 10seconds
            Thread.sleep(10000);
            producer1.interrupt();
            producer2.interrupt();
            producer3.interrupt();
            consumer1.interrupt();
            consumer2.interrupt();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
