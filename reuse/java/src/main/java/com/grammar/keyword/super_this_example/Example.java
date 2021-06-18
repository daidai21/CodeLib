/**
 * this
 * 
 * super
 */
public class Example {
    public static void main(String[] args) {
        Student student = new Student("father", "child");
        student.getInfo();
    }
}


class Person {
    protected String name;

    public Person(String name) {
        this.name = name;
    }
}



class Student extends Person {
    private String name;
    
    public Student(String personName, String studentName) {
        super(personName);
        this.name = studentName;
    }

    public void getInfo() {
        System.out.println(this.name);
        System.out.println(super.name);
    }
}
