
public class BuilderExample {
    public static void main(String[] args) {
        Person person = new Person.Builder(18, "jack").gender(false).high(180).build();
    }
}

class Person {
    private final int age;
    private final String name;
    private final boolean gender;
    private final int high;

    public static class Builder {
        // Optional parameters - initialized to default values
        private final boolean gender = true;
        private final int high = 170;

        // Required parameters
        private final int age;
        private final String name;

        public Builder(int age, String name) {
            this.age = age;
            this.name = name;
        }

        public Builder gender(boolean gender) {
            this.gender = gender;
            return this;
        }

        public Builder high(int high) {
            this.high = high;
        }

        public Person build() {
            return new Person(this);
        }
    }

    private Person(Builder builder) {
        age = builder.age;
        name = builder.name;
        gender = builder.gender;
        high = builder.high;
    }
}
