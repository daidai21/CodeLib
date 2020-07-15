/**
 * Generic static method example
 */
public class GenericStaticMethodExample {
    public static void main(String[] args) {
        System.out.println("Pair:");
        Pair<Integer> p0 = new Pair<Integer>(1, 2);
        System.out.println(p0.getFirst() + " " + p0.getSecond());
        Pair<Integer> p1 = Pair.create(1, 2);
        System.out.println(p1.getFirst() + " " + p1.getSecond());

        System.out.println("DiffPair:");
        DiffPair<String, Integer> dp0 = new DiffPair<String, Integer>("1", 2);
        System.out.println(dp0.getK() + ": " + dp0.getV());
        DiffPair<String, Integer> dp1 = DiffPair.create("1", 2);
        System.out.println(dp1.getK() + ": " + dp1.getV());
    }
}


class Pair<T> {
    private T first;
    private T second;

    public Pair(T first, T second) {
        this.first  = first;
        this.second = second;
    }

    public T getFirst()  { return this.first; }
    public T getSecond() { return this.second; }

    public static<K> Pair<K> create(K first, K second) {
        return new Pair<K>(first, second);
    }
}


class DiffPair<K, V> {
    private K k;
    private V v;

    public DiffPair(K k, V v) {
        this.k = k;
        this.v = v;
    }

    public K getK() { return this.k; }
    public V getV() { return this.v; }

    public static<sK, sV> DiffPair<sK, sV> create(sK k, sV v) {
        return new DiffPair<sK, sV>(k, v);
    }
}
