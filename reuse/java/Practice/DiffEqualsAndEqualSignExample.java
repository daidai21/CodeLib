/**
 * == and equals()
 * 
 * doc
 *      ==
 *          Basic type: compare whether the values are the same
 *          Reference type: it compares whether the references are the same
 *      equals()
 *          Reference comparison is the default
 *          You can override the equals method to compare values
 * 
 * Ref:
 *      https://www.geeksforgeeks.org/difference-equals-method-java/
 */
public class DiffEqualsAndEqualSignExample {
    public static void main(String[] args) {
        String s1 = new String("HELLO"); 
        String s2 = new String("HELLO"); 
        System.out.println(s1 == s2); 
        System.out.println(s1.equals(s2)); 

        System.out.println('a' == 97.0);
        System.out.println(true == true);
    }
}
