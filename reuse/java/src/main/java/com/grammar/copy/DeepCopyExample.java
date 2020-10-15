public class DeepCopyExample {
    public static void main(String[] args) {
        Student student = new Student("Tom", "Math");
        System.out.println("Source OBject: " + student.getName() + " - " + student.getSubject().getName());

        Student clonedStudent = (Student) student.clone();
        System.out.println("Copy OBject: " + clonedStudent.getName() + " - " + clonedStudent.getSubject().getName());

        System.out.println("Equal Object: " + (student == clonedStudent));
        System.out.println("Equal name property: " + (student.getName() == clonedStudent.getName()));
        System.out.println("Equal subject property: " + (student.getSubject() == clonedStudent.getSubject()));

        student.setName("Jerry");
        student.getSubject().setName("Chinese");
        System.out.println("Updated source object: " + student.getName() + " - " + student.getSubject().getName());
        System.out.println("Updated cloned object: " + clonedStudent.getName() + " - " + clonedStudent.getSubject().getName());
    }
}

class Subject {
    private String name;

    public Subject(String s) {
        name = s;
    }

    public String getName() {
        return name;
    }

    public void setName(String s) {
        name = s;
    }
}

class Student implements Cloneable {
    private Subject subject;

    private String name;

    public Student(String s, String sub) {
        name = s;
        subject = new Subject(sub);
    }

    public Subject getSubject() {
        return subject;
    }

    public String getName() {
        return name;
    }

    public void setName(String s) {
        name = s;
    }

    /**
     * Deep copy
     */
    public Object clone() {
        return new Student(name, subject.getName());
    }
}
