public class EnumClassExample {
    public static void main(String[] args) {
        //
    }
}


enum Color {
    RED,
    GREEN,
    BLUE;
}


// "enum Color" Compile result:
/*
final class Color extends Enum {
    public static final Color RED   = new Color();
    public static final Color GREEN = new Color();
    public static final Color BLUE  = new Color();

    private Color() {}
}
*/
