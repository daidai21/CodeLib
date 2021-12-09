import java.util.Optional;

/**
 * Ref:
 * https://docs.oracle.com/javase/8/docs/api/java/util/Optional.html
 * https://www.runoob.com/java/java8-optional-class.html
 * https://www.cnblogs.com/rjzheng/p/9163246.html
 * https://www.cnblogs.com/qdhxhz/p/12050701.html
 */
public class OptionalExample {
    public static void main(String[] args) throws Exception {
        User user = new User(1, "tom", null);
        User userJerry = new User(1, "jerry", new Address("a", "b", "c"));

        // 空指针
        try {
            user.getAddress().getProvince(); // 或者多层if嵌套判断null
        } catch (NullPointerException e) {
            System.out.println("NullPointerException");
        }
        
        // getCity
        try {
            Optional.ofNullable(user)
                    .map(u -> u.getAddress())
                    .map(a -> a.getCity())
                    .orElseThrow(() -> new Exception("取指错误"));
        } catch (Exception e) {
            System.out.println("Exception");
        }
        Optional.ofNullable(userJerry)
                .map(u -> u.getAddress())
                .map(a -> a.getCity())
                .orElseThrow(() -> new Exception("取指错误"));

        // user判空是否执行if的逻辑
        if (user.getAddress() != null) { System.out.println(user.getAddress().getCity()); }
        Optional.ofNullable(user.getAddress()).ifPresent(u -> System.out.println(u.getCity()) );
        Optional.ofNullable(userJerry.getAddress()).ifPresent(u -> System.out.println(u.getCity()) );
    }
}

class User {
    private int id;
    private String name;
    private Address address;

    public User(int id, String name, Address address) {
        this.id = id;
        this.name = name;
        this.address = address;
    }

    public int getId() { return this.id; }
    public void setId(int id) { this.id = id; }
    public String getName() { return this.name; }
    public void setName(String name) { this.name = name; }
    public Address getAddress() { return this.address; }
    public void setAddress(Address address) { this.address = address; }
}

class Address {
    private String province;
    private String city;
    private String area;

    public Address(String province, String city, String area) {
        this.province = province;
        this.city = city;
        this.area = area;
    }

    public String getProvince() { return this.province; }
    public void setProvince(String province) { this.province = province; }
    public String getCity() { return this.city; }
    public void setCity(String city) { this.city = city; }
    public String getArea() { return this.area; }
    public void setArea(String area) { this.area = area; }
}
