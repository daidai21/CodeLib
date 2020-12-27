import java.time.Instant;
import java.util.Date;

public class DateExample {

    public static void main(String[] args) {
        Date date = new Date();
        System.out.println(date.getYear() + 1900);
        System.out.println(date.getMonth() + 1);
        System.out.println(date.getDate());
        System.out.println(date.toString());
        System.out.println(date.toGMTString());
        System.out.println(date.toLocaleString());

        Date date1 = new Date();
        Instant instant = Instant.now();
        System.out.println("Date: " + date1.from(instant));

    }
}
