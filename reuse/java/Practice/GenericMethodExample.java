/**
 * Generic method example
 */
public class GenericMethodExample {
    public static void main(String[] args) {
        Integer[] intArray = { 1, 2, 3, 4, 5 };
        Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4 };
        Character[] charArray = { 'H', 'E', 'L', 'L', 'O' };
 
        System.out.println( "Integer Array:" );
        printArray( intArray  );
        System.out.println();
        System.out.println( "Double Array:" );
        printArray( doubleArray );
        System.out.println();
        System.out.println( "Character Array:" );
        printArray( charArray );
    }

    public static <E> void printArray(E[] inputArray) {
        for (E e : inputArray) {
            System.out.printf("%s ", e);
        }
        System.out.println();
    }
}
