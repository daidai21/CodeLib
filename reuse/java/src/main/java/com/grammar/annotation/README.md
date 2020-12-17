[同比](../AOP/README.md)

**JDK 1.8 自带的注解**

* `java.lang`
    * `@Override` 检查该方法是否是重写方法。如果发现其父类，或者是引用的接口中并没有该方法时，会报编译错误。
    * `@Deprecated` 标记过时方法。如果使用该方法，会报编译警告。
    * `@SuppressWarnings` 指示编译器去忽略注解中声明的警告。
    * (`@FunctionalInterface`)
    * (`@Indicates`)
    * (`@SafeVarargs`)

* `java.lang.annotation`
    * `@Target`  元注解  标记这个注解应该是哪种 Java 成员。
    * `@Retention`  元注解  标识这个注解怎么保存，是只在代码中，还是编入class文件中，或者是在运行时可以通过反射访问。
    * `@Documented`  元注解  标记这些注解是否包含在用户文档（javadoc）中。
    * `@Inherited`  元注解  标记这个注解是继承于哪个注解类(默认 注解并没有继承于任何子类)
    * `@Native`
    * `@Repeatable`

**注解分类**

* 编译期
* 类加载器
* 运行期

**定义注解**

```java
@Documented
@Target(ElementType.TYPE)
@Retention(RetentionPolicy.RUNTIME)
public @interface MyAnnotation1 {
    //
}

/*

    `@interface` 定义 Annotation 时，@interface 是必须的
    `@Target(ElementType.TYPE)` 的意思就是指定该 Annotation 的类型是 ElementType.TYPE。这就意味着，MyAnnotation1 是来修饰"类、接口（包括注释类型）或枚举声明"的注解。
    `@Retention(RetentionPolicy.RUNTIME)` 的意思就是指定该 Annotation 的策略是 RetentionPolicy.RUNTIME。这就意味着，编译器会将该 Annotation 信息保留在 .class 文件中，并且能被虚拟机读取。

*/
```

注解是aop的一种形式
