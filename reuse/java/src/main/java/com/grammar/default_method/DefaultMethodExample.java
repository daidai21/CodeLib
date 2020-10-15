public class DefaultMethodExample {
    public static void main(String[] args) {
        GrandFather vehicle = new Son();
        vehicle.print();
    }
}

interface GrandFather {
    default void print() {
        System.out.println("GrandFather.print()");
    }

    static void fn() {
        System.out.println("GrandFather.fn()");
    }
}

interface Father {
    default void print() {
        System.out.println("Father.print()");
    }
}

class Son implements GrandFather, Father {
    public void print() {
        GrandFather.super.print();
        Father.super.print();
        GrandFather.fn();
        System.out.println("Son.print()");
    }
}
