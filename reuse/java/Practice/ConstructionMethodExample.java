public class ConstructionMethodExample {
    public static void main(String[] args) {
        Person p1 = new Person("Xiao Ming", 15);
        Person p2 = new Person();
    }
}


class Person {
    private String name;
    private int age;

    public Person() {
    }

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    
    public String getName() {
        return this.name;
    }

    public int getAge() {
        return this.age;
    }
}
