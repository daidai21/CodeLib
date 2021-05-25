**Java 虚拟机栈**


* 局部变量表（LVT） Local Variable Table

```sh
javac -g JvmStackLvt.java
javap -v JvmStackLvt
javap -v JvmStackLvt > JvmStackLvt.txt

```

LVT按照变量的声明顺序进行存储

* 操作数栈（OS）

```sh
javac -g JvmStackOs.java
javap -v JvmStackOs
javap -v JvmStackOs > JvmStackOs.txt
```

* 运行时常量池引用（Runtime Constant Pool Reference）

```sh
javac -g JvmStackCpr.java
javap -v JvmStackCpr
javap -v JvmStackCpr > JvmStackCpr.txt
```

* 运行时常量池（Runtime Constant Pool）

```sh
javac -g MethodAreaRtcp.java
javap -v MethodAreaRtcp
javap -v MethodAreaRtcp > MethodAreaRtcp.txt
```

[基础类型的包装类也用到了常量池技术。](./../grammar/WrappingTypeCacheExmaple.java)
[深入解析Java的运行时数据区](https://zhuanlan.zhihu.com/p/102431019)
