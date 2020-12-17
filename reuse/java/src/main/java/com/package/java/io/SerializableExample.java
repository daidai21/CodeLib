import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

/**
 * serialVersionUID example
 */
public class SerializableExample {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        // serializationExample();
        deserializationExample();

        /**
         * Exception in thread "main" java.io.InvalidClassException: Person; local class incompatible: stream classdesc serialVersionUID = 123456789, local class serialVersionUID = 23525
         */
    }

    private static void serializationExample() throws IOException {
        Person person = new Person(1234, "wang");
        System.out.println("Person Serial" + person);
        FileOutputStream fos = new FileOutputStream("temp.txt");
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(person);
        oos.flush();
        oos.close();

    }

    private static void deserializationExample() throws IOException, ClassNotFoundException {
        // deserialization
        Person person;
        FileInputStream fis3 = new FileInputStream("temp.txt");
        ObjectInputStream ois3 = new ObjectInputStream(fis3);
        person = (Person) ois3.readObject();
        ois3.close();
        System.out.println("Person Deserial" + person);

    }
}

class Person implements Serializable {
    // private static final long serialVersionUID = 123456789L;
    private static final long serialVersionUID = 23525L;

    public Integer id;
    public String name;

    public Person(Integer id, String name) {
        this.id = id;
        this.name = name;
    }

    public String toString() {
        return "Person: " + id + " " + name;
    }
}
