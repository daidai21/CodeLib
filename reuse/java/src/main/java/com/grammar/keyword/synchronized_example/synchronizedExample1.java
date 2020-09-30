
public class synchronizedExample1 {
    public static void main(String[] args) {
        Sender send = new Sender();

        ThreadedSend s1 = new ThreadedSend(" Hi ", send);
        ThreadedSend s2 = new ThreadedSend(" Bye ", send);

        s1.start();
        s2.start();

        try {
            s1.join();
            s2.join();
        } catch (Exception e) {
            System.out.println("Interrupted");
        }

        System.out.print("*****");
        SenderSync sendSync = new SenderSync();
        ThreadedSend sSync1 = new ThreadedSend(" Hi ", sendSync);
        ThreadedSend sSync2 = new ThreadedSend(" Bye ", sendSync);
        sSync1.start();
        sSync2.start();
        try {
            sSync1.join();
            sSync2.join();
        } catch (Exception e) {
            System.out.println("Interrupted");
        }
    }
}

class Sender {
    public void send(String msg) {
        System.out.println("Sending\t" + msg);
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
            System.out.println("Thread interrupted.");
        }
        System.out.println("\n" + msg + "Sent.");
    }
}

class ThreadedSend extends Thread {
    private String msg;
    private Sender sender;

    ThreadedSend(String m, Sender obj) {
        msg = m;
        sender = obj;
    }

    public void run() {
        synchronized (sender) {
            sender.send(msg);
        }
    }
}

class SenderSync extends Sender {
    public synchronized void send(String msg) {
        System.out.println("Sending\t" + msg);
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
            System.out.println("Thread interrupted.");
        }
        System.out.println("\n" + msg + "Sent.");
    }
}
