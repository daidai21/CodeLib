
public class Example {
    public static void main(String[] args) {
        System.out.println("***** Start NoUsingVolatile *****");
        NoUsingVolatile noUsingVolatile = new NoUsingVolatile();
        Thread t1 = new Thread() {
            public void run() {
                noUsingVolatile.run();
            }
        };
        Thread t2 = new Thread() {
            public void run() {
                noUsingVolatile.stop();
            }
        };
        t1.start();
        t2.start();
        while (t1.isAlive() || t2.isAlive()) { }
        System.out.println("***** Stop NoUsingVolatile *****");


        System.out.println("***** Start UsingVolatile *****");
        UsingVolatile usingVolatile = new UsingVolatile();
        Thread t3 = new Thread() {
            public void run() {
                usingVolatile.run();
            }
        };
        Thread t4 = new Thread() {
            public void run() {
                usingVolatile.stop();
            }
        };
        t3.start();
        t4.start();
        while (t3.isAlive() || t4.isAlive()) { }
        System.out.println("***** Stop UsingVolatile *****");
    }
}

class UsingVolatile {
    private volatile boolean active;

    public void run() {
        active = true;
        while (active) {
            System.out.println("UsingVolatile::run()#while");
        }
    }

    public void stop() {
        System.out.println("UsingVolatile::stop()");
        active = false;
    }
}

class NoUsingVolatile {
    private boolean active;

    public void run() {
        active = true;
        while (active) {
            System.out.println("UsingVolatile::run()#while");
        }
    }

    public void stop() {
        System.out.println("UsingVolatile::stop()");
        active = false;
    }
}
