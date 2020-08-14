import java.lang.reflect.Method;
import java.lang.reflect.Field;


public class printAllMethodsAndFieldsFromObject {
    public static void main(String[] args) {
        try {
            Class thisClass = printAllMethodsAndFieldsFromObject.class;

            System.out.println("All methods:");
            Method[] methods = thisClass.getDeclaredMethods();
            for (int i = 0; i < methods.length; i++) {
                System.out.println(methods[i].toString());
            }

            System.out.println("All fields:");
            Field[] fields = thisClass.getDeclaredFields();
            for (int i = 0; i < fields.length; i++) {
                System.out.println(fields[i].toString());
            }

        } catch (Exception e) {
            System.out.println(e);
            e.printStackTrace();
        }

    }

    public void foo() {}
    public int bar() { return 12; }
    public String baz() { return "abc"; }

    private String var0 = "asdaf";
    private int var1 = 112414;
    private boolean var2 = false;
}

