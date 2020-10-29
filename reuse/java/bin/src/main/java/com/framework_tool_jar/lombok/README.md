
#### @NoArgsConstructor @RequiredArgsConstructor  @AllArgsConstructor

#### @Getter @Setter

https://projectlombok.org/features/GetterSetter


#### @Data

包含：
* @ToString
* @EqualsAndHashCode
* @Getter
* @Setter
* @RequiredArgsConstructor!

https://projectlombok.org/features/Data

```java

```

CompileTo


```java

```

#### @EqualsAndHashCode

从对象的字段生成hashCode和equals实现。

#### @RequiredArgsConstructor

会生成一个包含常量，和标识了NotNull的变量 的构造方法。生成的构造方法是private，如何想要对外提供使用可以使用staticName选项生成一个static方法。

```java
import lombok.RequiredArgsConstructor;

@RequiredArgsConstructor(staticName = "of")
public class ConstructorExample<T> {
    private int x, y;
    
    @NonNull
    private T description;
}
```

CompileTo

```java
import lombok.RequiredArgsConstructor;

public class ConstructorExample<T> {
    private int x, y;
    
    @NonNull
    private T description;
  
    public static <T> ConstructorExample<T> of(T description) {
        return new ConstructorExample<T>(description);
    }
}
```

#### @Accessors

https://projectlombok.org/features/experimental/Accessors

类似 @Getter @Setter 的新的实验性的api

#### @Slf4j


```java

@Slf4j(topic = "config")
```



================================================================

javac -cp lombok.jar example.java

================================================================




https://projectlombok.org/
https://projectlombok.org/features/all



```java
// @Slf4j

@Slf4j(topic = "test123")
public class Slf4jDemo {
    @Test
    public void test1(){
        log.info("OK");
    }
}
//上边的编译结果

public class Slf4jDemo {
    private static final Logger log = LoggerFactory.getLogger("test123");

    public Slf4jDemo() {
    }

    @Test
    public void test1() {
        log.info("OK");
    }
}

/*
输出
14:14:40.216 [main] INFO slf4j - OK
14:14:40.219 [main] WARN slf4j - OK
14:14:40.219 [main] ERROR slf4j - OK
*/
```

