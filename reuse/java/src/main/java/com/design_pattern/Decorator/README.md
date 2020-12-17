关键代码：
1、Component 类充当抽象角色，不应该具体实现。
2、修饰类引用和继承 Component 类，具体扩展类重写父类方法。

装饰模式包含如下角色：
Component: 抽象构件
ConcreteComponent: 具体构件
Decorator: 抽象装饰类
ConcreteDecorator: 具体装饰类
