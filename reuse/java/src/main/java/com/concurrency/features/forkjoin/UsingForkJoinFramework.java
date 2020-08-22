package com.concurrency.features.forkjoin;


import java.lang.Thread.UncaughtExceptionHandler;
import java.math.BigInteger;
import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;
import java.util.concurrent.RecursiveTask;
import java.util.LinkedList;
import java.util.List;


public class UsingForkJoinFramework {
    /**
     * Common pool
     */
    public ForkJoinPool getCommonPool() {
        return ForkJoinPool.commonPool();
    }

    /**
     * Customize ForkJoinPool
     */
    public ForkJoinPool customForkJoinPool(int parallelism,
            ForkJoinPool.ForkJoinWorkerThreadFactory factory,
            UncaughtExceptionHandler handler,
            boolean asyncMode) {
        return new ForkJoinPool(parallelism, factory, handler, asyncMode);
    }

    /**
     * RecursiveTask
     */
    static class RecSumTask extends RecursiveTask<BigInteger> {
        private static final long serialVersionUID = 1l;

        public static final int DIVIED_AT = 500;

        private List<Integer> numbers;

        public RecSumTask(List<Integer> numbers) {
            this.numbers = numbers;
        }

        @Override
        protected BigInteger compute() {
            LinkedList<RecSumTask> subTasks = new LinkedList<RecSumTask>();
            if (numbers.size() < DIVIED_AT) {
                // directly
                BigInteger subSum = BigInteger.ZERO;
                for (Integer number : numbers) {
                    subSum = subSum.add(BigInteger.valueOf(number));
                }

                return subSum;
            } else {
                // Divide to conquer
                int size = numbers.size();
                List<Integer> numbersLeft  = numbers.subList(0, size / 2);
                List<Integer> numbersRight = numbers.subList(size / 2, size);

                RecSumTask recSumLeft  = new RecSumTask(numbersLeft);
                RecSumTask recSumRight = new RecSumTask(numbersRight);

                subTasks.add(recSumLeft);
                subTasks.add(recSumRight);

                // Fork child tasks
                recSumLeft.fork();
                recSumRight.fork();
            }

            BigInteger sum = BigInteger.ZERO;
            for (RecSumTask recSum : subTasks) {
                // Join child tasks
                sum = sum.add(recSum.join());
            }

            return sum;
        }
    }

    /**
     * RecursiveTask
     */
    static class ARecursiveAction extends RecursiveAction {
        private static final long serialVersionUID = 1L;

        @Override
        protected void compute() {
            // same pattern goes here
        }
    }

    public static void debugPool(ForkJoinPool commonPool) {
        System.out.println("Debuggin ForJoinPool");
        System.out.println("Active Thread Count: " + commonPool.getActiveThreadCount());
        System.out.println("Pool Size: " + commonPool.getPoolSize());
        System.out.println("Parallelism level: " + commonPool.getParallelism());
        System.out.println("Queue submitted tasks: " + commonPool.getQueuedSubmissionCount());
        System.out.println("Steal count: " + commonPool.getStealCount());
        System.out.println("\n");
    }

    public static void main(String[] args) {
        // prepares dataset for the example
        LinkedList<Integer> numbers = new LinkedList<Integer>();
        for (int i = 0; i < 500000; ++i) {
            numbers.add(i);
        }

        // Usage
        ForkJoinPool commonPool = ForkJoinPool.commonPool();
        RecSumTask task = new RecSumTask(numbers);
        BigInteger result = commonPool.invoke(task);
        System.out.println("Result is: " + result);
    }
}
