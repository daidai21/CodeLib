
/**
 * StackOverFlow
 * 栈溢出
 */
public class StackOverFlow {
    public static void main(String[] args) {
        StackOverFlow stackOverFlow = new StackOverFlow();
        try {
            stackOverFlow.stackLeak();
        } catch (Throwable e) {
            System.out.println(stackOverFlow.stackLength);
            throw e;
        }
    }

    private int stackLength = 1;

    private void stackLeak() {
        stackLength++;
        stackLeak();
    }
}
