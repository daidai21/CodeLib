import java.util.ArrayList;
import java.util.Arrays;
import java.util.function.Consumer;


public class ConsumerExample {
    public static void main(String[] args) {
        // for loop
        ArrayList<String> list = new ArrayList<>(Arrays.asList("I", "love", "you", "too"));
        for(String str : list){
            if(str.length()>3)
                System.out.println(str);
        }

        // Consumer
        ArrayList<String> list1 = new ArrayList<>(Arrays.asList("I", "love", "you", "too"));
        list1.forEach(new Consumer<String>() {
            @Override
            public void accept(String str) {
                if (str.length() > 3)
                    System.out.println(str);
            }
        });

        // forEach + Lambda
        ArrayList<String> list2 = new ArrayList<>(Arrays.asList("I", "love", "you", "too"));
        list2.forEach( str -> {
        if(str.length()>3)
            System.out.println(str);
    });


    }

}
