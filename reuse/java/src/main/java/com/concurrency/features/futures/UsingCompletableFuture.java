package com.concurrency.features.futures;


import java.util.Random;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.function.Supplier;


public class UsingCompletableFuture {
    public static void main(String[] args) throws InterruptedException, ExecutionException{
        Random random = new Random();
        ExecutorService executor = Executors.newCachedThreadPool();

        // Creating
        CompletableFuture<Integer> randomNum = CompletableFuture.supplyAsync(() -> random.nextInt(140), executor);

        // Mapping
        String strNum = randomNum.thenApplyAsync(n -> Integer.toString(n), executor).get();
        System.out.println("Executed " + strNum);

        // Combining
        CompletableFuture<Integer> anotherNum = CompletableFuture.supplyAsync(() -> random.nextInt(140), executor);

        // Accept both and do something
        randomNum.thenAcceptBoth(anotherNum, (num1, num2) -> {
            System.out.println("Num1 is: " + num1);
            System.out.println("Num2 is: " + num2);
        });

        // Combine both into a new type/value
        CompletableFuture<Integer> mapperAndCombined = randomNum.thenCombine(anotherNum, (num1, num2) -> num1 + num2);

        // Retrieving value
        Integer value = mapperAndCombined.get();
        System.out.println("Sum " + value);

        // Undefined time task
        Supplier<Double> randomDouble = () -> {
            try {
                Thread.sleep(random.nextInt(1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return random.nextDouble();
        };

        // Run after executed
        CompletableFuture<Double> f1 = CompletableFuture.supplyAsync(randomDouble);
        CompletableFuture<Double> f2 = CompletableFuture.supplyAsync(randomDouble);
        CompletableFuture<Double> f3 = CompletableFuture.supplyAsync(randomDouble);
        CompletableFuture<Double> f4 = CompletableFuture.supplyAsync(randomDouble);
        CompletableFuture.anyOf(f1, f2, f3, f4).thenRun(() -> System.out.println("Completed"));

        // Fasttest result will be delivered
        // Undefined time task - static value
        Supplier<String> getVal1 = () -> {
            try {
                Thread.sleep(random.nextInt(1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return "First";
        };
        Supplier<String> getVal2 = () -> {
            try {
                Thread.sleep(random.nextInt(1000));
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return "Second";
        };
        CompletableFuture.supplyAsync(getVal1)
                         .acceptEitherAsync(
            CompletableFuture.supplyAsync(getVal2, executor), 
            (firstToBeReady) -> System.out.println(firstToBeReady), 
            executor
        );
        executor.shutdown();
        executor.awaitTermination(3000, TimeUnit.SECONDS);

    }
}
