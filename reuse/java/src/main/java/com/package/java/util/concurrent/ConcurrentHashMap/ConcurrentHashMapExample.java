import java.util.Iterator;
import java.util.concurrent.ConcurrentHashMap;

public class ConcurrentHashMapExample {
    public static void main(String[] args) {
        ConcurrentHashMap<Integer, String> concurrentHashMap = new ConcurrentHashMap<>();
        concurrentHashMap.put(100, "Hello");
        concurrentHashMap.put(101, "Geeks");
        concurrentHashMap.put(102, "Geeks");
        concurrentHashMap.putIfAbsent(101, "Hello");
        concurrentHashMap.remove(101, "Geeks");
        concurrentHashMap.putIfAbsent(103, "Hello");
        concurrentHashMap.replace(101, "Hello", "For");
        System.out.println(concurrentHashMap);
        ConcurrentHashMap<Integer, String> concurrentHashMap2 = new ConcurrentHashMap<>();
        concurrentHashMap2.putAll(concurrentHashMap);
        System.out.println(concurrentHashMap2);
        String string = concurrentHashMap.remove(100);
        System.out.println(string);
        System.out.println(concurrentHashMap);
        concurrentHashMap.clear();
        System.out.println(concurrentHashMap);
        System.out.println(concurrentHashMap2.get(102));
        System.out.println("Print concurrentHashMap2:");
        Iterator<ConcurrentHashMap.Entry<Integer, String>> iterator = concurrentHashMap2.entrySet().iterator();
        while (iterator.hasNext()) {
            ConcurrentHashMap.Entry<Integer, String> entry = iterator.next();
            System.out.println("Key=" + entry.getKey() + " Value=" + entry.getValue());
        }
    }
}
