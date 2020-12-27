import java.io.PrintWriter;
import java.io.StringWriter;

/**
 * 打印不同的类型的数据到多种的数据源 字符类型的打印输出流
 */
public class PrintWriterExample {
    public static void main(String[] args) {
        StringWriter buffer = new StringWriter();
        try (PrintWriter pw = new PrintWriter(buffer)) {
            pw.println("Hello");
            pw.println(12345);
            pw.println(true);
        }
        System.out.println(buffer.toString());

        // .
        String s = "Hello World!\n";
        PrintWriter p = null;
        try {
            p = new PrintWriter(System.out);
            p.write(s);
            // p.flush(); // 注释掉则不会输出helloworld内容；当缓冲区没有满时，无法将字节流输出到目的地
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            p.close(); // 关闭的时候就算缓冲区没有满也会刷出内容
        }
    }
}
