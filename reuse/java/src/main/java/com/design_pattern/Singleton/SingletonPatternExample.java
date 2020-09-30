
public class SingletonPatternExample {
    public static void main(String[] args) {
        // Err
        // SingleObject object = new SingleObject();

        SingleObject object = SingleObject.getInstance();
        object.showMsg();
    }
}

class SingleObject {
    private static SingleObject instance = new SingleObject();

    private SingleObject() {
    }

    public static SingleObject getInstance() {
        return instance;
    }

    public void showMsg() {
        System.out.println("SingleObject.showMsg()");
    }
}
