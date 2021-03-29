import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

/**
 * 类比Java中的Future机制
 * 
 * 阻塞等待task计算完成
 */
public class FutureTaskExample1 {
    public static void main(String[] args) throws InterruptedException, ExecutionException {
        FutureTask<String> ret = service();
        System.out.println("Do other something.");
        String result = ret.get();
        System.out.println(result);
    }

    private static FutureTask<String> service() {
        System.out.println("Start service()");
        FutureTask<String> task = new FutureTask<String>(
            new Callable<String>() {
                @Override
                public String call() throws InterruptedException {

                    System.out.println("Running task");
                    Thread.sleep(1000);

                    return "Do something.";
                }
            }
        );
        new Thread(task).start();
        System.out.println("End service()");
        return task;
    }
}
