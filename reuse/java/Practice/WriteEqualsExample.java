import java.util.List;
import static java.util.Arrays.asList;


/**
 * Reflexive
 * Symmetric
 * Transitive
 * Consistent
 */
public class WriteEqualsExample {
    public static void main(String[] args) {
        List<Person> list = asList(
            new Person("XiaoMing", 18),
            new Person("XiaoHong", 25),
            new Person("BobSmith", 20)
        );
        boolean exist = list.contains(new Person("BobSmith", 20));
        System.out.println(exist ? "test succeed!" : "test fail!");
    }
}


class Person {
    private String name;
    private int    age;

    public Person(String name, int age) {
        this.name = name;
        this.age  = age;
    }

    public boolean equals(Object o) {
        if (o instanceof Person) {
            Person p = (Person) o;
            boolean nameEquuals = false;
            if (this.name == null && p.name == null) {
                nameEquuals = true;
            }
            if (this.name != null) {
                if (this.name.equals(p.name)) {
                    nameEquuals = true;
                }
            }
            boolean ageEquals = false;
            if (this.age == p.age) {
                ageEquals = true;
            }
            return nameEquuals && ageEquals;
        }
        return false;
    }
}
