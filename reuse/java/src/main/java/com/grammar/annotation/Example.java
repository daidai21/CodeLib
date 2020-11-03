import java.lang.annotation.Annotation;
import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.reflect.Method;

public class Example {
    public static void main(String[] args) {

        Method[] methods = SampleClass.class.getMethods();

        Annotation annotation = methods[0].getAnnotation(CustomAnnotation.class);
        if (annotation instanceof CustomAnnotation) {
            CustomAnnotation customAnnotation = (CustomAnnotation) annotation;
            System.out.println("name: " + customAnnotation.name());
            System.out.println("value: " + customAnnotation.value());
        }
    }
}

@CustomAnnotation(name = "SampleClass", value = "Sample Class Annotation")
class SampleClass {
    private String sampleField;

    @CustomAnnotation(name = "getSampleMethod", value = "Sample Method Annotation")
    public String getSampleField() {
        return sampleField;
    }

    public void setSampleField(String sampleField) {
        this.sampleField = sampleField;
    }
}

@Retention(RetentionPolicy.RUNTIME)
@interface CustomAnnotation {
    public String name();

    public String value();
}
