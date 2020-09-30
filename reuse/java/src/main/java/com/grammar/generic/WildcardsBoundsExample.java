import java.util.ArrayList;
import java.util.List;


public class WildcardsBoundsExample {
    public static void main(String[] args) {
        // Upper Bounds Wildcards
        // <? super T>

        List<? super Father> list1 = new ArrayList<Grandfather>();
        // Error
        // List<? super Father> list2 = new ArrayList<Son>();


        // Lower Bounds Wildcards
        // <? extends T>
        List<? extends Father> list3 = new ArrayList<Son>();
        // Error
        // List<? extends Father> list4 = new ArrayList<Grandfather>();

    }

}

class Grandfather {}

class Father extends Grandfather {}

class Son extends Father {}
