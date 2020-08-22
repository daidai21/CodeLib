package com.concurrency.features.threads;


/* ****************************************************************************
 * File Name   : UsingThreads.java
 * Author      : DaiDai
 * Mail        : daidai4269@aliyun.com
 * Created Time: 四  8/20 00:55:51 2020
 *************************************************************************** */


public class UsingThreads {
    public static void main(String[] args) throws InterruptedException {
        // Creating
        Thread created = new Thread();
        created.start();

        // Assigning a task for running on a thread
        Thread threadWithTask = new Thread(
            () -> System.out.println("Inside thread: " + Thread.currentThread().getName())
        );
        threadWithTask.start();

        // Interrupting a thread
        Runnable interrupatblyTask = () -> {
            while (!Thread.currentThread().isInterrupted()) {
                System.out.println("I'm not interrupted " + Thread.currentThread().getName());
            }
        };
        Thread interruptable = new Thread(interrupatblyTask);
        interruptable.start();
        Thread.sleep(3000);
        interruptable.interrupt();
    }
}
