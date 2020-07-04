import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.UnknownHostException;
import java.io.IOException;


public class SocketClient {
    public static void main(String[] args) {
        try {
            Socket s = new Socket("localhost", 8888);

            InputStream is = s.getInputStream();
            OutputStream os = s.getOutputStream();

            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(os));
            bw.write("hello world\n");
            bw.flush();

            BufferedReader br = new BufferedReader(new InputStreamReader(is));
            String msg = br.readLine();
            System.out.println("Server: " + msg);
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
           e.printStackTrace();
        }
    }
}
