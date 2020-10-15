import java.util.EnumSet;
import java.util.Set;

public class ofExample {
    public static void main(String[] args) {
        Set<Name> setNames = EnumSet.of(Name.JACK, Name.KING);
        System.out.println(setNames);
        EnumSet<Name> enumSetName = EnumSet.of(Name.JACK);
        System.out.println(enumSetName);
    }
}

enum Name {
    JACK,
    KING,
    QUEEN
}
