public class OverloadObjectMethodExample {
    public static void main(String[] args) {
        Person p = new Person("Tom");
        System.out.println(p.toString());
        System.out.println(p.equals(new Object()));
        System.out.println(p.hashCode());
    }
}


class Person {
    private String name;

    Person (String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Person:name=" + name;
    }

    @Override
    public boolean equals(Object o) {
        if (o instanceof Person) {
            Person p = (Person) o;
            return this.name.equals(p.name);
        }
        return false;
    }

    @Override
    public int hashCode() {
        return this.name.hashCode();
    }
}
