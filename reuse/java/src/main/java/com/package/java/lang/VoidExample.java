import java.lang.reflect.Method;

public class VoidExample {
    public static void main(String[] args) {
        for(Method method : VoidExample.class.getMethods()) {
            if(method.getReturnType().equals(Void.TYPE)) {
                System.out.println(method.getName());
            }
        }

        System.out.println("********************");
        VoidExample voidExample = (VoidExample) null;
        System.out.println(voidExample);
        voidExample.pn();
    }

    Void fn() {
        return null;
    }

    void pn() {
        System.out.println("VoidExample::pn()");
    }
}
