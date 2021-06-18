/**
 * 
 * 跳出多级循环
 */
public class GotoMultiLevelLoop {
    public static void main(String[] args) {
        ok:
            for (int i = 0; i < 10; ++i) {
                for (int j = 0; j < 10; ++j) {
                    System.out.println(i + " " + j);
                    if (i == 2 & j == 2) {
                        break ok;
                    }
                }
            }
        
        System.out.println("=====");

        search:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 50; j++) {
                    System.out.println(i+" "+j);
                    if (j == 3) {
                        continue search;
                    }
                }
            }

    }
}
