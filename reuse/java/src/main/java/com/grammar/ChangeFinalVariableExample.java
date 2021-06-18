import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.lang.Integer;
// TODO: BUG
/**
 * 修改final变量
 * 
 * https://link.jianshu.com/?t=http://stackoverflow.com/questions/3301635/change-private-static-final-field-using-java-reflection
 */
public class ChangeFinalVariableExample {
    public static void main(String[] args) throws Exception {
        ChangeFinalVariableExample.print();

        // Field canChangeField = ChangeFinalVariableExample.class.getDeclaredField("CAN_CHANGE");
        Field cannotChangeField = ChangeFinalVariableExample.class.getDeclaredField("CANNOT_CHANGE");

        // changeStaticFinal(canChangeField, 2);
        changeStaticFinal(cannotChangeField, 3);

        ChangeFinalVariableExample.print();
    }

    public static void changeStaticFinal(Field field, Object newValue) throws Exception {
        field.setAccessible(true);

        Field modifersField = Field.class.getDeclaredField("modifiers");
        modifersField.setAccessible(true);
        // 把指定的field中的final修饰符去掉
        modifersField.setInt(field, field.getModifiers() & ~Modifier.FINAL);
        // 为指定field设置新值
        field.set(null, newValue);
    }

    // 未内联优化
    // private static final Integer CAN_CHANGE = new Integer("1");

    // 内联优化
    public static final int CANNOT_CHANGE = 1;

    public static void print() {
        System.out.println("------------------------");
        // System.out.println("CAN_CHANGE = " + CAN_CHANGE);
        System.out.println("CANNOT_CHANGE = " + CANNOT_CHANGE);
        System.out.println("------------------------");
    }

}
