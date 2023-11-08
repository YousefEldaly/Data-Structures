
public class RedBlackTree {
    public static final int RED = 0;
    public static final int BLACK = 1;
    private class Node {
        int data;
        Node parent;
        Node left;
        Node right;
        int color;



        private Node() {
            this.color = BLACK;
        }
        private Node(final int data) {
            this.data = data;
            this.parent = TNULL;
            this.left = TNULL;
            this.right = TNULL;
            this.color = RED;
        }
    }

    private Node root;
    private final Node TNULL;

    public RedBlackTree() {
        TNULL = new Node();
        TNULL.right = TNULL;
        TNULL.left = TNULL;

        root = new Node((int)Double.NEGATIVE_INFINITY);
        root.color = BLACK;

    }
    public final void printTree() {
        if (TNULL.right == TNULL) {
            System.out.println("Empty Tree");
        } else {
            Node current = root;
            printTree(current);
        }
    }

    private void printTree(Node current) {
        if (current != current.left) {
            printTree(current.left);
            System.out.println(current.data);
            printTree(current.right);
        }
    }

    public void insert(int key) {
        Node newNode = new Node(key);
        insert(key, newNode);
    }
    private void insert(int key, Node newNode) {
        Node current = root;
        Node parent = TNULL;
        while (current != TNULL) {
            parent = current;
            if (newNode.data < current.data) {
                current = current.left;
            } else {
                current = current.right;
            }
        }
        newNode.parent = parent;
        if (TNULL.right == TNULL) {
            root = newNode;
            newNode.parent = TNULL;
            TNULL.right = root;
        } else if (newNode.data < parent.data) {
            parent.left = newNode;
        } else {
            parent.right = newNode;
        }

        RBInsertFixup(newNode);
    }
    private void RBInsertFixup(Node newNode) {
        Node current = newNode;
        while (current.parent.color == RED) {
            if (current.parent == current.parent.parent.left) {
                Node parentSibling = current.parent.parent.right;
                if (parentSibling.color == RED) {
                    current.parent.color = BLACK;
                    parentSibling.color = BLACK;
                    current.parent.parent.color = RED;
                    current = current.parent.parent;
                } else{
                    if (current == current.parent.right) {
                        current = current.parent;
                        leftRotate(current);
                    }
                        current.parent.color = BLACK;
                        current.parent.parent.color = RED;
                        rightRotate(current.parent.parent);
                }
            } else {
                Node parentSibling = current.parent.parent.left;
                if (parentSibling.color == RED) {
                    current.parent.color = BLACK;
                    parentSibling.color = BLACK;
                    current.parent.parent.color = RED;
                    current = current.parent.parent;
                } else {
                    if (current == current.parent.left) {
                        current = current.parent;
                        rightRotate(current);
                    }
                        current.parent.color = BLACK;
                        current.parent.parent.color = RED;
                        leftRotate(current.parent.parent);
                }
            }
        }
        root.color = BLACK;
    }

    private void leftRotate(Node x) {
        Node y = x.right;
        x.right = y.left;
        if (y.left != TNULL) {
            y.left.parent = x;
        }
        y.parent = x.parent;
        if (x.parent == TNULL) {
            this.root = y;
        } else if (x == x.parent.left) {
            x.parent.left = y;
        } else {
            x.parent.right = y;
        }
        y.left = x;
        x.parent = y;
    }

    private void rightRotate(Node x) {
        Node y = x.left;
        x.left = y.right;
        if (y.right != TNULL) {
            y.right.parent = x;
        }
        y.parent = x.parent;
        if (x.parent == TNULL) {
            this.root = y;
        } else if (x == x.parent.right) {
            x.parent.right = y;
        } else {
            x.parent.left = y;
        }
        y.right = x;
        x.parent = y;
    }
}
