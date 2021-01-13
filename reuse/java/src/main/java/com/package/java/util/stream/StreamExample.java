import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class StreamExample {
    public static void main(String[] args) {
        // forEach
        System.out.println("=====");
        Stream<String> stream = Stream.of("I", "love", "you", "too");
        stream.forEach(str -> System.out.println(str));

        // filter
        System.out.println("=====");
        Stream<String> stream1 = Stream.of("I", "love", "you", "too");
        stream1.filter(str -> str.length() == 3)
                .forEach(str -> System.out.println(str));

        // distinct
        System.out.println("=====");
        Stream<String> stream2 = Stream.of("I", "love", "you", "too", "too");
        stream2.distinct()
                .forEach(str -> System.out.println(str));

        // sorted
        System.out.println("=====");
        Stream<String> stream3 = Stream.of("I", "love", "you", "too");
        stream3.sorted((str1, str2) -> str1.length() - str2.length())
                .forEach(str -> System.out.println(str));

        // map
        System.out.println("=====");
        Stream<String> stream4 = Stream.of("I", "love", "you", "too");
        stream4.map(str -> str.toUpperCase())
                .forEach(str -> System.out.println(str));

        // flatMap
        System.out.println("=====");
        Stream<List<Integer>> stream5 = Stream.of(Arrays.asList(1, 2), Arrays.asList(3, 4, 5));
        stream5.flatMap(list -> list.stream())
                .forEach(i -> System.out.println(i));

        // 找出最长的单词
        System.out.println("=====");
        Stream<String> stream6 = Stream.of("I", "love", "you", "too");
        Optional<String> longest = stream6.reduce((s1, s2) -> s1.length() >= s2.length() ? s1 : s2);
        // Optional<String> longest = stream.max((s1, s2) -> s1.length()-s2.length());
        System.out.println(longest.get());

        // 求单词长度之和
        System.out.println("=====");
        Stream<String> stream7 = Stream.of("I", "love", "you", "too");
        Integer lengthSum = stream7.reduce(0,
                (sum, str) -> sum + str.length(),
                (a, b) -> a + b);
        // int lengthSum = stream.mapToInt(str -> str.length()).sum();
        System.out.println(lengthSum);

    }
}
