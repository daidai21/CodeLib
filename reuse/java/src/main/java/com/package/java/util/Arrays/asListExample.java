import java.util.Arrays;
import java.util.List;

public class asListExample {
    public static void main(String[] args) {
        String[] fruitNames = { "Apple", "Banana", "Orange" };
        List<String> fruitNamesList = Arrays.asList(fruitNames);
        System.out.println(fruitNamesList);

        // Arrays.asList() 返回结果不可操作
        // Exception in thread "main" java.lang.UnsupportedOperationException
        fruitNamesList.add("asd");
    }
}
