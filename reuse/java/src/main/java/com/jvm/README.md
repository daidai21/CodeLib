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



TODO: 问题排查


===

### JVM

相关代码：   github.com/daidai21/CodeLib/reuse/java/jvm


Minor GC 和 Full GC
新生代 老年代


* - Eden Space（伊甸园）、 
* - Survivor Space(幸存者区)、 
* - Old Gen（老年代）。


实践    https://www.infoq.cn/article/3WyReTKqrHIvtw4frmr3



JVM

https://github.com/CyC2018/CS-Notes/blob/master/notes/Java%20%E8%99%9A%E6%8B%9F%E6%9C%BA.md#%E4%BA%8C%E5%9E%83%E5%9C%BE%E6%94%B6%E9%9B%86

https://github.com/xbox1994/Java-Interview/blob/master/MD/Java%E5%9F%BA%E7%A1%80-JVM%E5%8E%9F%E7%90%86.md#%E4%B8%B2%E8%A1%8C%E6%94%B6%E9%9B%86%E5%99%A8

https://github.com/Snailclimb/JavaGuide#jvm-%E5%BF%85%E7%9C%8B-1



#### 类加载机制



##### 类的生命周期 7阶段
	。。。


##### 类加载相关：
	加载过程
	双亲委派
	类加载器的分类
	类初始化时机



#### 运行时数据区域

[深入解析Java的运行时数据区](https://zhuanlan.zhihu.com/p/102431019)

#### 内存分配与回收策略

##### 内存分配策略 共5条
	。。。



##### Full GC触发条件
	。。。。




#### 垃圾收集器 7种

Serial
ParNew
Parallel Scavenge
Serial Old
Parallel Old
CMS
G1

|  | Serial | ParNew | Parallel Scavenge | Serial Old | Parallel Old | CMS | G1 |
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |
| 描述 |  |  |  |  |  |  |  |
| 优点 |  |  |  |  |  |  |  |
| 缺点 |  |  |  |  |  |  |  |
| 使用场景 |  |  |  |  |  |  |  |
| 单线程还是多线程 |  |  |  |  |  |  |  |
| 串行还是并行 |  |  |  |  |  |  |  |
| 备注 |  |  |  |  |  |  |  |

TODO：
	属性
		单线程还是多线程
		串行还是并行



#### 垃圾收集算法

	标记-清除
	标记-整理
	复制
	分代收集

TODO：优缺点

#### 判断一个对象是否可被回收

引用计数算法
可达性分析算法




#### JVM调优
