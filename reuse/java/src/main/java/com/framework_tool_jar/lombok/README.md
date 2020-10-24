
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

To


```java

```


#### @Accessors

https://projectlombok.org/features/experimental/Accessors



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

