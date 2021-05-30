import java.util.concurrent.DelayQueue;
import java.util.concurrent.Delayed;
import java.util.concurrent.TimeUnit;



public class DelayQueueExample {
    public static void main(String[] args) {
        DelayQueue<DelayedTask> delayQueue = new DelayQueue<>();
        long now = System.currentTimeMillis();

        new Thread(() -> {
            while (true) {
                try {
                    System.out.println(delayQueue.take().toString());
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }).start();

        delayQueue.offer(new DelayedTask("task1",10000));
        delayQueue.offer(new DelayedTask("task2",3900));
        delayQueue.offer(new DelayedTask("task3",1900));
        delayQueue.offer(new DelayedTask("task4",5900));
        delayQueue.offer(new DelayedTask("task5",6900));
        delayQueue.offer(new DelayedTask("task6",7900));
        delayQueue.offer(new DelayedTask("task7",4900));
    }
}

class DelayedTask implements Delayed {
    String taskName;
    long deadline;

    public DelayedTask(String taskName, long deadline) {
        this.taskName = taskName;
        this.deadline = deadline;
    }

    // @Override
    // public long getDelay(TimeUnit unit) {
    //     return deadline - System.currentTimeMillis();
    // }

    // @Override
    // public int compareTo(Delayed o) {
    //     return (int) (getDelay(TimeUnit.MILLISECONDS) - o.getDelay(TimeUnit.MILLISECONDS));
    // }

    @Override
    public String toString() {
        return "DelayedTask {" +" taskName = '" + taskName + "', deadline = " + deadline + " }";
    }
}
