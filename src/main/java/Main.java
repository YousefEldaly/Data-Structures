public class Main {
    public static void main(String[] args) {
        RedBlackTree redBlackTree = new RedBlackTree();
        redBlackTree.insert(10);
        redBlackTree.insert(4);
        redBlackTree.insert(1);
        redBlackTree.insert(5);
        redBlackTree.insert(3);
        redBlackTree.insert(100);
        redBlackTree.printTree();
        System.out.println("\n\n");
        redBlackTree.deleteNode(4);
        //redBlackTree.deleteNode(10);
        //redBlackTree.deleteNode(100);
        redBlackTree.printTree();

    }
}