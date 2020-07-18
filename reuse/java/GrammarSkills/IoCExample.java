
public class IoCExample {
    public static void main(String[] args) {
        Fruit f = Factory.getInstance("Apple");
        if (f != null) {
            f.eat();
        }
    }
}

interface Fruit {
    public abstract void eat();
}

class Apple implements Fruit {
    public void eat() {
        System.out.println("Apple");
    }
}

class Orange implements Fruit {
    public void eat() {
        System.out.println("Orange");
    }
}

class Factory {
    public static Fruit getInstance(String ClassName) {
        Fruit f = null;
        try {
            f = (Fruit) Class.forName(ClassName).newInstance();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return f;
    }
}
