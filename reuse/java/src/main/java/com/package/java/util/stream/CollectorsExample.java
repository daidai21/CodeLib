import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class CollectorsExample {
    public static void main(String[] args) {

        // 将Stream转换成容器或Map
        System.out.println("=====");
        Stream<String> stream8 = Stream.of("I", "love", "you", "too");
        List<String> list = stream8.collect(Collectors.toList());
        // Set<String> set = stream8.collect(Collectors.toSet());
        // Map<String, Integer> map = stream8.collect(Collectors.toMap(Function.identity(), String::length));
        System.out.println(list);
        // System.out.println(set);
        // System.out.println(map);


        //　将Stream规约成List
        System.out.println("=====");
        Stream<String> stream9 = Stream.of("I", "love", "you", "too");
        List<String> list1 = stream9.collect(ArrayList::new, ArrayList::add, ArrayList::addAll);
        // List<String> list = stream.collect(Collectors.toList());
        System.out.println(list1);

        // 使用toCollection()指定规约容器的类型
        System.out.println("=====");
        Stream<String> stream10 = Stream.of("I", "love", "you", "too");
        // ArrayList<String> arrayList = stream10.collect(Collectors.toCollection(ArrayList::new));
        HashSet<String> hashSet = stream10.collect(Collectors.toCollection(HashSet::new));// (4)
        System.out.println(hashSet);
    }
}