import java.util.EnumSet;
import java.util.Set;

public class EnumSetExample {
    public static void main(String[] args) {
        EnumSet<Color> set1, set2, set3, set4;
        set1 = EnumSet.of(Color.RED, Color.GREEN, Color.BLOCK);
        set2 = EnumSet.complementOf(set1);
        set3 = EnumSet.allOf(Color.class);
        set4 = EnumSet.range(Color.RED, Color.BLOCK);
        System.out.println("Set 1: " + set1);
        System.out.println("Set 2: " + set2);
        System.out.println("Set 3: " + set3);
        System.out.println("Set 4: " + set4);

        Set<Name> setNames = EnumSet.of(Name.JACK, Name.KING);
        System.out.println(setNames);
        EnumSet<Name> enumSetName = EnumSet.of(Name.JACK);
        System.out.println(enumSetName);
    }
}

enum Color {
    RED, GREEN, BLOCK, YELLOW
}

enum Name {
    JACK, KING, QUEEN
}
