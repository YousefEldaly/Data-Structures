
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

    public void deleteNode(int data) {
        deleteNode(this.root, data);
    }

    private void deleteNode(Node node, int data) {
        Node z = TNULL;
        while (node != TNULL) {
            if (node.data == data) {
                z = node;
            }

            if (node.data <= data) {
                node = node.right;
            } else {
                node = node.left;
            }
        }

        if (z == TNULL) {
            System.out.println("Data not found!");
            return;
        }

        Node x, y;
        y = z;
        int yOriginalColor = z.color;
        if (z.left == TNULL) {
            x = z.right;
            transplant(z, z.right);
        } else if (z.right == TNULL) {
            x = z.left;
            transplant(z, z.left);
        } else {
            y = minimum(z.right);
            yOriginalColor = y.color;
            x = y.right;
            if (y.parent == z) {
                x.parent = y;
            } else {
                transplant(y, y.right);
                y.right = z.right;
                y.right.parent = y;
            }
            transplant(z, y);
            y.left = z.left;
            y.left.parent = y;
            y.color = z.color;
        }
        if (yOriginalColor == BLACK) {
            RBDeleteFixup(x);
        }
    }

    private void RBDeleteFixup(Node x) {
        Node w;
        while (x != root & x.color == BLACK) {
            if (x == x.parent.left) {
                w = x.parent.right;
                if (w.color == RED) {
                    w.color = BLACK;
                    x.parent.color = RED;
                    leftRotate(x.parent);
                    w = x.parent.right;
                }
                if (w.left.color == BLACK & w.right.color == BLACK) {
                    w.color = RED;
                    x = x.parent;
                } else {
                    if (w.right.color == BLACK) {
                        w.left.color = BLACK;
                        w.color = RED;
                        rightRotate(w);
                        w = x.parent.right;
                    }
                    w.color = x.parent.color;
                    x.parent.color = BLACK;
                    w.right.color = BLACK;
                    leftRotate(x.parent);
                    x = root;
                }

            } else {
                w = x.parent.left;
                if (w.color == RED) {
                    w.color = BLACK;
                    x.parent.color = RED;
                    rightRotate(x.parent);
                    w = x.parent.left;
                }

                if (w.right.color == BLACK && w.right.color == BLACK) {
                    w.color = RED;
                    x = x.parent;
                } else {
                    if (w.left.color == BLACK) {
                        w.right.color = BLACK;
                        w.color = RED;
                        leftRotate(w);
                        w = x.parent.left;
                    }

                    w.color = x.parent.color;
                    x.parent.color = 0;
                    w.left.color = 0;
                    rightRotate(x.parent);
                    x = root;
                }
            }
        }
        x.color = BLACK;
    }

    private void transplant(Node oldNode, Node transNode){
        if (oldNode.parent == TNULL) {
            root = transNode;
        } else if (oldNode == oldNode.parent.left) {
            oldNode.parent.left = transNode;
        } else {
            oldNode.parent.right = transNode;
        }
        transNode.parent = oldNode.parent;

    }

    private Node minimum(Node node) {
        while (node.left != TNULL) {
            node = node.left;
        }
        return node;
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