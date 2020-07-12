public class KeywordinterfaceExample {
    public static void main(String[] args) {
        Student s = new Student("Tom");
        System.out.println(s.getName());
        s.run();
    }
}


interface Person { // Abstract class
    void run();       // Abstract method
    String getName(); // Abstract method
}


class Student implements Person {
    private String name;

    public Student(String name) {
        this.name = name;
    }

    @Override
    public void run() {
        System.out.println(this.name + " run");
    }

    @Override
    public String getName() {
        return this.name;
    }
}
