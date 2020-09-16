import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.channels.FileChannel;
import java.io.File;


public class FileChannelExample {
    /**
     * @param args
     */
    public static void main(String[] args) {
        FileChannelExample fileChannelExample = new FileChannelExample();
        try {
            if (args.length < 3) {
                System.out.println("Usage: FileChannelExample <source> <destination> <mode> \n");
                return;
            }

            if ("copy".equals(args[2])) {
                fileChannelExample.copy(args[0], args[1]);
            } else if ("zeroCopy".equals(args[2])) {
                fileChannelExample.zeroCopy(args[0], args[1]);
            } else {
                System.out.println("param <mode> err \n");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * @param from
     * @param to
     * @throws IOException
     */
    public void zeroCopy(String from, String to) throws IOException {
        FileChannel source = null;
        FileChannel destination = null;

        try {
            source = new FileInputStream(from).getChannel();
            destination = new FileOutputStream(to).getChannel();
            source.transferTo(0, source.size(), destination);
        } finally {
            if (source != null) {
                source.close();
            }
            if (destination != null) {
                destination.close();
            }
        }
    }

    /**
     * @param from
     * @param to
     * @throws IOException
     */
    public void copy(String from, String to) throws IOException {
        byte[] data = new byte[8 * 1024];
        FileInputStream fis = null;
        FileOutputStream fos = null;
        long bytesToCopy = new File(from).length();
        long bytesCopied = 0;
        try {
            fis = new FileInputStream(from);
            fos = new FileOutputStream(to);

            while (bytesCopied < bytesToCopy) {
                fis.read(data);
                fos.write(data);
                bytesCopied += data.length;
            }
            fos.flush();
        } finally {
            if (fis != null) {
                fis.close();
            }
            if (fos != null) {
                fos.close();
            }
        }
    }
}
