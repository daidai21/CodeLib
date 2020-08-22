package com.grammar;

/**
 * Serialization interface
 */

import java.io.Serializable;
import java.lang.reflect.Field;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;


public class SerializableInterfaceExample {
    public static void main(String[] args) throws Exception {
        Foo foo = new Foo("123", "Tom");

        writeFooToFile(foo, "./temp.txt");
        System.out.println("Write object over!");

        foo = readFileToFoo("./temp.txt");
        System.out.println("Read object over!");

        System.out.println(foo.toString());
    }

    public static void writeFooToFile(Foo o, String fileName) throws Exception {
        FileOutputStream fos = new FileOutputStream(fileName);
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(o);

        oos.close();
        fos.close();
    }

    public static Foo readFileToFoo(String fileName) throws Exception {
        FileInputStream fis = new FileInputStream(fileName);
        ObjectInputStream ois = new ObjectInputStream(fis);
        Foo foo = (Foo) ois.readObject();

        fis.close();
        ois.close();

        return foo;
    }
}


class Foo implements Serializable {
    private String userId; 
    private String userName; 
 
    public Foo(String userId, String userName) { 
        this.userId   = userId; 
        this.userName = userName; 
    }

    @Override
    public String toString() {
        return "userId: " + this.userId + " userName: " + this.userName;
    }
}
