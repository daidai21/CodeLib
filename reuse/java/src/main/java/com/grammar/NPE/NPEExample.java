public class NPEExample {
    public static void main(String[] args) {
        // NPE example
        String ptr = null;

        try {
            if (ptr.equals("abc")) {
                System.out.println("Same");
            } else {
                System.out.println("Not same");
            }
        } catch (NullPointerException e) {
            System.out.println("NullPointerException Caught");
            // e.printStackTrace();
        }

        try {
            if ("abc".equals(ptr)) {
                System.out.println("Same");
            } else {
                System.out.println("Not same");
            }
        } catch (NullPointerException e) {
            System.out.println("NullPointerException Caught");
            e.printStackTrace();
        }
    }
}
