
/**
 * Multiple inheritance example
 */
public class MultipleInheritanceExample {
    public static void main(String[] args) {
        Son son = new Son();
        System.out.println("getName() of Son: " + son.getName());
        System.out.println("getAge() of Son: " + son.getAge());
    }
}


class Father {
    public String getName() {
        return "Tom";
    }
}

class Mother {
    public int getAge() {
        return 18;
    }
}

class Son {
    private class FatherInherit extends Father {
        public String getName() {
            return super.getName() + "Jerry";
        }
    }

    private class MotherInherit extends Mother {
        public int getAge() {
            return super.getAge() + 10;
        }
    }

    private FatherInherit fatherInherit = null;
    private MotherInherit motherInherit = null;

    public String getName() {
        if (this.fatherInherit == null) {
            this.fatherInherit = new FatherInherit();
        }
        return this.fatherInherit.getName();
    }

    public int getAge() {
        if (this.motherInherit == null) {
            this.motherInherit = new MotherInherit();
        }
        return this.motherInherit.getAge();
    }
}
