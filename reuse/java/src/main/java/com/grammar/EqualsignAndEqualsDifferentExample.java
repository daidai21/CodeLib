public class EqualsignAndEqualsDifferentExample {
    public static void main(String[] args) {
        String s1 = new String("abc");
        String s2 = new String("abc");
        System.out.println("s1 == s2 " + (s1 == s2));
        System.out.println("s1.equals(s2) " + s1.equals(s2));

        String s3 = "abc";
        String s4 = "abc";
        System.out.println("s3 == s4 " + (s3 == s4));
        System.out.println("s3.equals(s4) " + (s3.equals(s4)));

    }
}
