import java.util.ArrayList;
import java.util.List;

/**
 * HeapOverFlow
 * 堆溢出
 */
public class HeapOverFlow {

    public static void main(String[] args) {
        List<OOMObject> list = new ArrayList<>();
        while (true) {
            list.add(new OOMObject());
        }
    }

    private static class OOMObject {}
}
