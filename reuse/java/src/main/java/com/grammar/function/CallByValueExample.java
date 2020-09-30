
public class CallByValueExample {
    public static void main(String[] args) {
        System.out.println("swap");
        int num1 = 10;
        int num2 = 20;
        swap(num1, num2);
        System.out.println("num1 = " + num1);
        System.out.println("num2 = " + num2);

        System.out.println("change");
        int[] arr = { 1, 2, 3 };
        System.out.println(arr[0]);
        change(arr);
        System.out.println(arr[0]);

        System.out.println("swapStudent");
        Student s1 = new Student("tom");
        Student s2 = new Student("mary");
        swapStudent(s1, s2);
        System.out.println("s1: " + s1.getName());
        System.out.println("s2: " + s2.getName());
    }

    public static void swap(int a, int b) {
        int temp = a;
        a = b;
        b = temp;

        System.out.println("a = " + a);
        System.out.println("b = " + b);
    }

    public static void change(int[] arr) {
        arr[0] = 0;
    }

    public static void swapStudent(Student x, Student y) {
        Student temp = x;
        x = y;
        y = temp;
        System.out.println("x:" + x.getName());
        System.out.println("y:" + y.getName());
    }
}

class Student {
    private String name;

    public Student(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }
}
