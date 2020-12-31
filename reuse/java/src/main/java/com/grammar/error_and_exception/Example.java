import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;

public class Example {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(new FileInputStream("file_path.txt"), "UTF-8")) {
            // 会自动释放资源scanner，不用finally
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
