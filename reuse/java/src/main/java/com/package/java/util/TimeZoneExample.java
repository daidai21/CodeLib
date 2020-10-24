import java.util.TimeZone;

public class TimeZoneExample {
    public static void main(String[] args) {
        TimeZone tzDefault = TimeZone.getDefault();
        TimeZone tzGMT9 = TimeZone.getTimeZone("GMT+09:00");
        TimeZone tzNY = TimeZone.getTimeZone("America/New_York");
        System.out.println(tzDefault.getID());
        System.out.println(tzGMT9.getID());
        System.out.println(tzNY.getID());
    }
}
