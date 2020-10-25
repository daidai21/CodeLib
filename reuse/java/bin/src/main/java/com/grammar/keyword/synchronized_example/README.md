| 代码 | 获取的锁 | 修饰的对象 |
| :-: | :-: | :-: |
| `synchronized(this) {}` | 对象锁 | 代码块 |
| `synchronized(Object) {}` | 对象锁 | 代码块 |
| `synchronized(类.class) {}` | 类锁 | 代码块 |
| `synchronized void fn() {}` | 对象锁 | 方法 |
| `synchronized static void fn() {}` | 类锁 | 方法 |
