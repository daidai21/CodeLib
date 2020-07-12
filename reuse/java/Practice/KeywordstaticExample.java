public class KeywordstaticExample {    
    public static void main(String[] args) {
        // static field
        System.out.println("static field");
        Person ming = new Person("Xiao Ming", 12);
        Person hong = new Person("Xiao Hong", 15);
        ming.number = 88;
        System.out.println(hong.number);
        hong.number = 99;
        System.out.println(ming.number);

        // static method
        System.out.println("static method");
        Person1.setNumber(99);
        System.out.println(Person1.number);
    }
}

class Person {
    public String     name;
    public int        age;
    public static int number;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}


class Person1 {
    public static int number;

    public static void setNumber(int value) {
        number = value;
    }
}
