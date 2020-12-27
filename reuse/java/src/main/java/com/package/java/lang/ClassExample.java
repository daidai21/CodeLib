import java.lang.Class;
import java.lang.ClassLoader;

public class ClassExample {
    public static void main(String[] args) {
        try {
            Class class1 = Class.forName("forNameExample");
            ClassLoader classLoader = class1.getClassLoader();
            Class class2 = Class.forName("java.lang.Thread", true, classLoader);
            System.out.println("Class = " + class1.getName());
            System.out.println("Class = " + class2.getName()); 
        } catch (ClassNotFoundException e) {
            System.out.println(e.toString());
        }
    }
}



// TODO

```java
getDeclaredConstructors
getDeclaredClasses
getDeclaredFields
getDeclaredAnnotations
```


[ref](https://docs.oracle.com/javase/8/docs/api/java/lang/Class.html)


