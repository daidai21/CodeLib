public class LambdaExpressionExample {
    public static void main(String[] args) {
        // All situation
        // 参数类型可选
        // 可选参数圆括号
        // 可选的大括号
        // 可选的返回关键字

        example((1, 2.1) -> {});
    }

    public void example(Fn v) {
        // 
    }
}


// https://www.runoob.com/java/java8-lambda-expressions.html
// https://www.liaoxuefeng.com/wiki/1252599548343744/1305158055100449



@FunctionalInterface
interface Fn {
    void fn(int v0, double v1);
}

