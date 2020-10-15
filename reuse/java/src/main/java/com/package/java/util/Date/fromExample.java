import java.time.Instant;
import java.util.Date;

public class fromExample {
    public static void main(String[] args) {
        Date date = new Date();
        Instant instant = Instant.now();
        System.out.println("Date: " + date.from(instant));
    }
}
