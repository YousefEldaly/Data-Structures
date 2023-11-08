public class Main {
    public static void main(String[] args) {
        RedBlackTree redBlackTree = new RedBlackTree();
        redBlackTree.insert(10);
        redBlackTree.insert(4);
        redBlackTree.insert(1);
        redBlackTree.insert(5);
        redBlackTree.insert(3);
        redBlackTree.insert(100);
        redBlackTree.insert(10);
        redBlackTree.insert(3);

        redBlackTree.printTree();
    }
}