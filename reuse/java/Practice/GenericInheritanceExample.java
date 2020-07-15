/**
 * A class inherits from a generic class
 */
public class GenericInheritanceExample {
    public static void main(String[] args) {
        IntPair ip = new IntPair(1, 2);
        System.out.println(ip.getFirst() + " " + ip.getSecond());
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


class IntPair extends Pair<Integer> {
    public IntPair(Integer first, Integer second) {
        super(first, second);
    }
}
