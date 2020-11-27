import java.io.PrintWriter;
import java.io.StringWriter;

/**
 * 打印不同的类型的数据到多种的数据源
 * 字符类型的打印输出流
 */
public class PrintWriterExample {
    public static void main(String[] args)     {
        StringWriter buffer = new StringWriter();
        try (PrintWriter pw = new PrintWriter(buffer)) {
            pw.println("Hello");
            pw.println(12345);
            pw.println(true);
        }
        System.out.println(buffer.toString());
    }
}
