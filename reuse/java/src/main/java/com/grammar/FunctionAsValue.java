import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.function.Function;

public class FunctionAsValue {
    public static void main(String[] args) {
        // Map<String, Function<String, Map<String, Object>>> mp = new ConcurrentHashMap<String, Function<String, Map<String, Object>>>();

        
        // mp.put("f", (Map<String, Object> param) -> { func(param); });

        Map<String, Object> p1 = new HashMap<>() {{
            put("asd", 123);
        }};

        // mp.get("f").run(p1);

        Map<String, Generator> mp = new HashMap<String, Generator>();
        mp.put("f1",  param -> func(param) );

        mp.put("f", new Generator() {
            @Override
            public String run(Map<String, Object> param) {
                return func(param);
            }
        });
        mp.get("f").run(p1);
        mp.get("f1").run(p1);
    }

    private static String func(Map<String, Object> param) {
        System.out.println(param);
        String str = "Runoob";

        return str;
    }


}



@FunctionalInterface
interface Generator { 
    String run(Map<String, Object> param); 
} 
