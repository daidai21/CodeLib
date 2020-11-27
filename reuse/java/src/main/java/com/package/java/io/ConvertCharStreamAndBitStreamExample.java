import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.io.InputStreamReader;

public class ConvertCharStreamAndBitStreamExample {
    public static void main(String[] args) throws Exception {
        // init file
        FileWriter fileWriter = new FileWriter("./temp.txt");
        fileWriter.write(String.join("\n", "test".split("")));
        fileWriter.close();

        // example
        File file = new File("./temp.txt");
        InputStream inputStream = new FileInputStream(file);
        // covert
        InputStreamReader inputStreamReader = new InputStreamReader(inputStream, "UTF-8");
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
        String line = null;
        while ( null != (line = bufferedReader.readLine()) ) {
            System.out.println(line);
        }

    }
}
