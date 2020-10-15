import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class MethodReferenceExample {
    public static void main(String[] args) {
        System.out.println("List Example");
        List<String> names = new ArrayList<>();
        names.add("Google");
        names.add("Runoob");
        names.add("Taobao");
        names.add("Baidu");
        names.add("Sina");
        names.forEach(System.out::println);

        System.out.println("All Status Example");
        final Car car = Car.create(Car::new);
        final List<Car> cars = Arrays.asList(car);

        cars.forEach(Car::collide);

        cars.forEach(Car::repair);

        final Car police = Car.create(Car::new);
        cars.forEach(police::follow);
    }
}

@FunctionalInterface
interface Supplier<T> {
    public T get();
}

class Car {
    public static Car create(final Supplier<Car> supplier) {
        System.out.println("Create " + supplier.toString());
        return supplier.get();
    }

    public static void collide(final Car car) {
        System.out.println("Collided " + car.toString());
    }

    public void follow(final Car another) {
        System.out.println("Follow " + another.toString());
    }

    public void repair() {
        System.out.println("Repaired " + this.toString());
    }
}
