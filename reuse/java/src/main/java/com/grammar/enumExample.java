
public class enumExample {
    public static void main(String[] args) {
        Person person1 = Person.getPersonById(1);
    }
}

enum Person {
    TOM(1, "tom"), JERRY(2, "jerry"), MARY(3, "mary");

    private int id;

    private String name;

    Person(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public static Person getPersonById(int id) {
        for (Person person : Person.values()) {
            if (person.id == id) {
                return person;
            }
        }
        return null;
    }
}
