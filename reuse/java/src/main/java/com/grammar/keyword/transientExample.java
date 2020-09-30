import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class transientExample implements Serializable {
    public static void main(String[] args) throws Exception {
        transientExample input = new transientExample();

        // serialization
        FileOutputStream fos = new FileOutputStream("./temp.txt");
        ObjectOutputStream oos = new ObjectOutputStream(fos);
        oos.writeObject(input);

        // de-serialization
        FileInputStream fis = new FileInputStream("./temp.txt");
        ObjectInputStream ois = new ObjectInputStream(fis);
        transientExample output = (transientExample) ois.readObject();
        System.out.println("i = " + output.i);
        System.out.println("j = " + output.j);
        System.out.println("k = " + output.k);
        System.out.println("l = " + output.l);
        System.out.println("m = " + output.m);
    }

    int i = 10;
    int j = 20;
    transient int k = 30;
    transient static int l = 40;
    transient final int m = 50;
}
