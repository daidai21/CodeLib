package com.parallel_stream;


import java.math.BigInteger;
import java.util.ArrayList;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

// package com.parallel_stream;


public class UsingParallelStreams {
    public static void main(String[] args) {
        // Creating parallel streams from existing collections
        new ArrayList<>().parallelStream();

        // Making stream parallel
        IntStream.rangeClosed(0, 30000) // source
                 .parallel() // intermediate operations
                 .mapToObj(BigInteger::valueOf)
                 .map(UsingParallelStreams::isPrime)
                 .collect(Collectors.toList()); // terminal operation

        System.out.println("\n");

        // Each operation run in parallel, out of order
        IntStream.rangeClosed(0, 20) // source
                 .parallel() // intermediate operations
                 .mapToObj(Integer::toString)
                 .forEach(System.out::print); // terminal operation

        System.out.println("\n");

        // Runs sequentially, in order
        IntStream.rangeClosed(0, 20)
                 .mapToObj(Integer::toString)
                 .forEach(System.out::print);

        System.out.println("\n");

        dummyPerformanceCheck();
    }

    private static void dummyPerformanceCheck() {
        // Sequentail stream
        long start1 = System.currentTimeMillis();
        IntStream.rangeClosed(0, 50000)
                 .mapToObj(BigInteger::valueOf)
                 .map(UsingParallelStreams::isPrime)
                 .collect(Collectors.toList());
        long end1 = System.currentTimeMillis();
        long time1 = (end1 - start1) / 1000;
        System.out.println("Sequentail: " + time1);

        // Parallel stream
        long start2 = System.currentTimeMillis();
        IntStream.rangeClosed(0, 50000)
                 .parallel()
                 .mapToObj(BigInteger::valueOf)
                 .map(UsingParallelStreams::isPrime)
                 .collect(Collectors.toList());
        long end2 = System.currentTimeMillis();
        long time2 = (end2 - start2) / 1000;
        System.out.println("Parallel: " + time2);
    }

    public static boolean isPrime(BigInteger n) {
        BigInteger counter = BigInteger.ONE.add(BigInteger.ONE);
        boolean isPrime = true;
        while (counter.compareTo(n) == -1) {
            if (n.remainder(counter).compareTo(BigInteger.ZERO) == 0) {
                isPrime = false;
                break;
            }
            counter = counter.add(BigInteger.ONE);
        }
        return isPrime;
    }
}
