package com.concurrency.features.collections;


/* ****************************************************************************
 * File Name   : UsingConcurrentHashMap.java
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 四  8/20 01:30:28 2020
 *************************************************************************** */

// TODO
// ConcurrentHashMap theory


import java.util.Random;
import java.util.UUID;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;


public class UsingConcurrentHashMap {
    public static void main(String[] args) {
        System.out.println("=== ConcurrentHashMap ===");
        ExecutorService executor = Executors.newCachedThreadPool();
        Random random = new Random();
        ConcurrentHashMap<UUID, Integer> valuesPerUuid = new ConcurrentHashMap<UUID, Integer>();
        // atomic operations
        valuesPerUuid.putIfAbsent(UUID.randomUUID(), random.nextInt(100));

        // simulating concurrent access
        for (Integer i = 0; i < 100; ++i) {
            Integer temp = i;
            if (i % 6 == 0) {
                // write
                executor.execute(() -> {
                    UUID uuid = UUID.randomUUID();
                    Integer value = random.nextInt(10);
                    System.out.println(temp + " W Added   " + uuid + " - " + value);
                    valuesPerUuid.putIfAbsent(uuid, value);
                });
            } else {
                // read
                executor.execute(() -> System.out.println(temp + " R Printed " + valuesPerUuid.values().toString()));
            }
        }

        // finishing
        executor.shutdown();

        try {
            executor.awaitTermination(2000, TimeUnit.SECONDS);
            // space for other examples
            Thread.sleep(2000);
            System.out.println("\n");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("=== show valuesPerUuid ===");
        for (Object o : valuesPerUuid.entrySet()) {
            System.out.println(o);
        }
    }
}
