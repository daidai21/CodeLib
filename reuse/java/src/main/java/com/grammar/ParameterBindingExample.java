package com.grammar;


public class ParameterBindingExample {
    public static void main(String[] args) {
        // Delivery of basic type parameters
        System.out.println("Delivery of basic type parameters");
        Person0 p0 = new Person0();
        int n0 = 1;
        p0.setAge(n0);
        System.out.println(p0.getAge());
        n0 = 2;
        System.out.println(p0.getAge());

        // Reference type parameter binding
        System.out.println("Reference type parameter binding");
        Person1 p1 = new Person1();
        String[] fullName = new String[] { "Homer", "Simpson" };
        p1.setName(fullName);
        System.out.println(p1.getName());
        fullName[0] = "Bart";
        System.out.println(p1.getName());

        // Reference type parameter binding
        System.out.println("Reference type parameter binding");
        Person2 p2 = new Person2();
        String bob = "Bob";
        p2.setName(bob);
        System.out.println(p2.getName());
        bob = "Alice";
        System.out.println(p2.getName());

    }
}


class Person0 {
    private int age;

    public int getAge() {
        return this.age;
    }

    public void setAge(int age) {
        this.age = age;
    }
}


class Person1 {
    private String[] names;

    public String getName() {
        return this.names[0] + " " + this.names[1];
    }

    public void setName(String[] names) {
        this.names = names;
    }
}


class Person2 {
    private String name;

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
