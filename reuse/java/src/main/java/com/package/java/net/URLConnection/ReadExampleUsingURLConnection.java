import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

/**
 * example
 */
public class ReadExampleUsingURLConnection {
    public static void main(String[] args) throws Exception {
        URL baidu = new URL("http://www.baidu.com/");
        URLConnection yc = baidu.openConnection();
        BufferedReader in = new BufferedReader(new InputStreamReader(yc.getInputStream()));
        String inputLine;
        while ((inputLine = in.readLine()) != null)
            System.out.println(inputLine);
        in.close();
    }
}
