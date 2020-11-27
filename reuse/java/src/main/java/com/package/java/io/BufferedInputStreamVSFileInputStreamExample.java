import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

/**
 * BufferedInputStream VS FileInputStream
 */
public class BufferedInputStreamVSFileInputStreamExample {

    static int BUFFER_SIZE = 100;

    public static void main(String[] args) {
        exec_test(10000, 10000);
        exec_test(1, 10000);
        exec_test(10000, 1);

        exec_test(10000000, 10000000);
        exec_test(1, 10000000);
        exec_test(10000000, 10000);
        exec_test(1, 10000000);

    }

    private static String repeatString(String s, int count) {
        StringBuilder r = new StringBuilder();
        for (int i = 0; i < count; i++) {
            r.append(s);
        }
        return r.toString();
    }

    private static void exec_test(int fileStrSize, int streamBufSize) {
        System.out.print(repeatString("*", 5) + "  ");
        System.out.print(String.format("[fileStrSize] %s, [streamBufSize] %s", fileStrSize, streamBufSize));
        System.out.println("  " + repeatString("*", 5));

        BUFFER_SIZE = streamBufSize;

        File src = new File("./1temp.txt");
        File dest = new File("./2temp.txt");

        try {
            if (!src.exists()) {
                src.createNewFile();
            }
            if (!dest.exists()) {
                dest.createNewFile();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        try {
            FileWriter fileWriter = new FileWriter("./1temp.txt");
            fileWriter.write(getRandomString(fileStrSize));
            fileWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

        long startTime = System.currentTimeMillis();

        copyFileWithFileInputStream(src, dest);

        long endTime = System.currentTimeMillis();
        System.out.println("Copy file using FileStream takes : " + (endTime - startTime) + " ms.");

        // test copy using BufferedStream
        startTime = System.currentTimeMillis();

        copyFileWithBufferedInputStream(src, dest);

        endTime = System.currentTimeMillis();
        System.out.println("Copy file using BufferedStream takes : " + (endTime - startTime) + " ms.");
    }

    private static String getRandomString(int length) {
        String str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        Random random = new Random();
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < length; i++) {
            int number = random.nextInt(62);
            sb.append(str.charAt(number));
        }
        return sb.toString();
    }

    private static void copyFileWithBufferedInputStream(File src, File dest) {

        BufferedInputStream bufferedInput = null;
        BufferedOutputStream bufferedOutput = null;
        try {
            bufferedInput = new BufferedInputStream(new FileInputStream(src));
            bufferedOutput = new BufferedOutputStream(new FileOutputStream(dest));

            byte[] buffer = new byte[BUFFER_SIZE];
            int copySize;

            while ((copySize = bufferedInput.read(buffer)) > 0) {
                bufferedOutput.write(buffer, 0, copySize);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                bufferedInput.close();
                bufferedOutput.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }

    private static void copyFileWithFileInputStream(File src, File dest) {
        FileInputStream input = null;
        FileOutputStream output = null;

        try {
            input = new FileInputStream(src);
            output = new FileOutputStream(dest);

            byte[] buffer = new byte[BUFFER_SIZE];
            int copySize;

            while ((copySize = input.read(buffer)) > 0) {
                output.write(buffer, 0, copySize);
                output.flush();
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                input.close();
                output.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
