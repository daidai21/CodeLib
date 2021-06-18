import javax.lang.model.type.NullType;


/**
 * null object pattern, used example
 */
public class NullObjectPatternGetBinaryTreeSizeExample {
    public static void main(String[] args) throws NullPointerException {
        Node root = new Node(
            new Node(),
            new Node(
                new Node(),
                new Node()
            )
        );
        System.out.println(root.total());  // expect: 5
        Node root2 = new Node(
            new Node(),
            new Node(
                new Node(),
                new Node(
                    new Node(
                        new Node(
                            new Node(),
                            new Node()            
                        ),
                        new Node()
                    ),
                    new Node()
                )
            )
        );
        System.out.println(root2.total());  // expect: 11

    }

}

class Node {
    Node() {}

    Node(Node left, Node right) {
        this.left = left;
        this.right = right;
    }

    private Node left;
    private Node right;

    public int total() {
        return total(left) + total(right) + 1;
    }

    private int total(Node node) {
        return node == null ? 0 : (total(node.left) + total(node.right) + 1);
    }
}
