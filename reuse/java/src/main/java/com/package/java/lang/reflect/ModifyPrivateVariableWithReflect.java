import java.lang.reflect.Field;

// TODO
// https://gist.github.com/asaskevich/4c6dee9169095fa2477f
public class ModifyPrivateVariableWithReflect {
    public static void main(String[] args) {
        // private var
        try {
            Foo foo = new Foo();
            Field f = foo.getClass().getDeclaredField("id");
            f.setAccessible(true);
            f.set(foo, 2);
            System.out.println(foo.getId());
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }

        // private final var
        // 修改final变量
        // TODO

        // private method to public method
        // TODO
    }
}

class Foo {
    private int id = 1;

    public int getId() {
        return id;
    }
}
