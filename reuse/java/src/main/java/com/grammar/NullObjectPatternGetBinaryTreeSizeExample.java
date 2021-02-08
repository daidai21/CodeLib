import javax.lang.model.type.NullType;


// TODO:bug

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
        System.out.println(tree_node_num(root));
    }

    private static int tree_node_num(Node node) {
        return tree_node_num(node.left) + tree_node_num(node.right) + 1;
    }

    private int tree_node_num(NullType nil) {
        return 0;
    }
}

class Node {
    Node() {}

    Node(Node left, Node right) {
        this.left = left;
        this.right = right;
    }

    Node left;
    Node right;
}
