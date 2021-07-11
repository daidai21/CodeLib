import java.util.SortedMap;
import java.util.TreeMap;
import java.util.Set;
import java.util.Collection;
import java.util.SortedSet;
import java.util.TreeSet;
import java.util.Iterator;


/**
 * 非线程安全
 */
public class ConsistentHashing<T> {
    /**
     * 节点的复制因子，实际节点个数 * numberOfReplicas = 虚拟节点个数
     */
    private final int numberOfReplicas;

    /**
     * 存储虚拟节点的hash值到真实节点的映射
     */
    private final SortedMap<Integer, T> circle = new TreeMap<Integer, T>();

    public ConsistentHashing(int numberOfReplicas, Collection<T> nodes) {
        this.numberOfReplicas = numberOfReplicas;
        for (T node : nodes) {
            add(node);
        }
    }

    /**
     * 增加一个真实节点
     */
    public void add(T node) {
        for (int i = 0; i < numberOfReplicas; ++i) {
            circle.put((node.toString() + i).hashCode(), node);
        }
    }

    /**
     * 减去一个真实节点
     */
    public void remove(T node) {
        for (int i = 0; i < numberOfReplicas; ++i) {
            circle.remove((node.toString() + i).hashCode());
        }
    }

    /**
     * 获取一个节点
     */
    public T get(Object key) {
        if (circle.isEmpty()) {
            return null;
        }
        int hash = key.hashCode();
        if (!circle.containsKey(hash)) {
            SortedMap<Integer, T> tailMap = circle.tailMap(hash);
            hash = tailMap.isEmpty() ? circle.firstKey() : tailMap.firstKey();
        }
        return circle.get(hash);
    }

    /**
     * 获取环的虚拟大小
     */
    public long getSize() {
        return circle.size();
    }

    /**
     * 测试方法，非功能方法
     */
    public void testBalance() {
        // 获取TreeMap的所有key
        Set<Integer> sets = circle.keySet();
        // 获得key的排序
        SortedSet<Integer> sortedSets = new TreeSet<Integer>(sets);
        for (Integer hashCode : sortedSets) {
            System.out.println(hashCode);
        }
        System.out.println("===== each location's distance are follows: =====");
        // 查看相邻两个hashCode的差值
        Iterator<Integer> it1 = sortedSets.iterator();
        Iterator<Integer> it2 = sortedSets.iterator();
        if (it2.hasNext()) {
            it2.next();
        }
        long keyPre, KeyAfter;
        while (it1.hasNext() && it2.hasNext()) {
            keyPre = it1.next();
            KeyAfter = it2.next();
            System.out.println(KeyAfter - keyPre);
        }
    }
}
