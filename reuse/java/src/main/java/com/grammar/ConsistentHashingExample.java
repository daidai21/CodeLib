import java.util.Set;
import java.util.HashSet;

public class ConsistentHashingExample {
    public static void main(String[] args) {
        Set<String> nodes = new HashSet<String>();
        nodes.add("A");
        nodes.add("B");
        nodes.add("C");
        ConsistentHashing<String> consistentHashing = new ConsistentHashing<String>(2, nodes);
        consistentHashing.add("D");
        System.out.println("hash circle size(): " + consistentHashing.getSize());
        System.out.println("location of each node are follows: ");
        consistentHashing.testBalance();
        String node = consistentHashing.get("apple");
        System.out.println("---------->" + node);
    }
}
