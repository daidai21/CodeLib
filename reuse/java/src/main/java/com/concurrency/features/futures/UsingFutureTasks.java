package com.concurrency.features.futures;


import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.TimeoutException;


public class UsingFutureTasks {
    public static void main(String[] args) {
        Callable<Integer> callable = () -> {
            int random = new Random().nextInt(10) * 100;
            System.out.println("Preparing to execute");
            Thread.sleep(random);
            System.out.println("Executed - " + random);
            return random;
        };

        FutureTask<Integer> futureTask = new FutureTask<>(callable);

        ExecutorService executor = Executors.newSingleThreadExecutor();
        executor.execute(futureTask);

        try {
            Integer value = futureTask.get(2, TimeUnit.SECONDS);
            System.out.println("Value is " + value);
        } catch (InterruptedException | ExecutionException | TimeoutException e) {
            e.printStackTrace();
        }
        executor.shutdown();
    }
}
