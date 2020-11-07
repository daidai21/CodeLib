**引用类型**

```java
House seller = new House();
...
seller = null;
```

* 强引用

```java
House buyer1 = seller;
```

* 软引用

```java
SoftReference<House> buyer2 = new SoftReference<House>(seller);
```

* 弱引用

```java
WeakReference<House> buyer3 = new WeakReference<House>(seller);
```

* 虚引用

```java
PhantomReference<House> buyer4 = new PhantomReference<House>(seller, null);
```
