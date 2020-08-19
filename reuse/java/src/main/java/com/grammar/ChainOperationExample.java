/**
 * Chain operation example
 */
public class ChainOperationExample {
    public static void main(String[] args) {
        Number n = new Number(1);
        n.add(1)
         .divide(2)
         .multiply(100)
         .divide(5);
        System.out.println(n.toString());
    }
}


class Number {
    private int num = 0;

    public Number(int num) {
        this.num = num;
    }

    public Number add(int num) {
        this.num += num;
        return this;
    }

    public Number subtract(int num) {
        this.num -= num;
        return this;
    }

    public Number multiply(int num) {
        this.num *= num;
        return this;
    }

    public Number divide(int num) {
        this.num /= num;
        return this;
    }

    @Override
    public String toString() {
        return Integer.toString(this.num);
    }
}
