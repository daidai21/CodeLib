import java.util.HashMap;
import java.util.Map;
public class HashMapExample {
    public static void main(String[] args) {
        Map<Integer, String> map = new HashMap<>();
        map.put(1, "one");
        map.put(2, "two");
        map.put(3, "three");
        System.out.println(map.getOrDefault(4, "NoValue"));


        // TODO

    }
}
