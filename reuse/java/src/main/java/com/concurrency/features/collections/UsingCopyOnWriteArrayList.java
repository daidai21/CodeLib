package com.concurrency.features.collections;


/* ****************************************************************************
 * File Name   : UsingCopyOnWriteArrayList.java
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 四  8/20 01:30:50 2020
 *************************************************************************** */


import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.CopyOnWriteArrayList;


public class UsingCopyOnWriteArrayList {
    public static void main(String[] args) {
        System.out.println("=== CopyOnWriteArrayList ===");
        ExecutorService executor = Executors.newCachedThreadPool();
        Random random = new Random();
        // No ConcurrentModificationException
        CopyOnWriteArrayList<Integer> copyOnWriteArrayList = new CopyOnWriteArrayList<Integer>();
        for (int i = 0; i < 100; ++i) {
            Integer temp = i;
            if (i % 8 == 0) {
                // write
                executor.execute(() -> {
                    Integer value = random.nextInt(100);
                    System.err.println(temp + " Added " + value);
                    copyOnWriteArrayList.add(value);
                });
            } else {
                // read
                executor.execute(() -> {
                    StringBuilder stringBuilder = new StringBuilder();
                    for (Object valueObject : copyOnWriteArrayList) {
                        stringBuilder.append(valueObject + " ");
                    }
                    System.out.println(temp + " Reading " + stringBuilder.toString());
                });
            }
        }

        // Finishing
        executor.shutdown();
        try {
            executor.awaitTermination(2000, TimeUnit.SECONDS);
            // space for other examples
            Thread.sleep(2000);
            System.out.println("\n");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
