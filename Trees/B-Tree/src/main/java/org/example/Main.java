package org.example;

public class Main {
    public static void main(String[] args) {
        BTree b = new BTree(3);
        System.out.println("Testing insertion...");
        b.insert(8);
        b.insert(9);
        b.insert(10);
        b.insert(11);
        b.insert(15);
        b.insert(20);
        b.insert(17);
        b.insert(16);
        b.insert(21);

        b.Show();

        System.out.println("\n\nTesting Contains method...");
        if (b.contains(21)) {
            System.out.println("21 Found");
        } else {
            System.out.println("21 Not found");
        }
        System.out.println("\nTesting Correctness of nodes and children...");
        System.out.println(b.getNodeOf(16).key[b.getKeyIdx(16)]);


    }
}