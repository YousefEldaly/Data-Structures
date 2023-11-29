package org.example;

import java.util.HashMap;
import java.util.Map;

public class BTree {
    private int T;
    public class Node {
        int n;
        int key[] = new int[2 * T - 1];
        Node[] child = new Node[2 * T];
        boolean leaf = true;

        public int find(int key) {
            for (int i = 0; i < this.n; i++) {
                if(this.key[i] == key) {
                    return i;
                }
            }
            return -1;
        }
    }

    private Node root;

    private class Pair<Node, Integer> {
        private final Node node;
        private final Integer index;

        Pair(Node node, Integer index) {
            this.node = node;
            this.index = index;
        }

        public Node getNode() {
            return node;
        }

        public Integer getIndex() {
            return index;
        }

    }
    public BTree(int t) {
        this.T = t;
        root = new Node();
        root.n = 0;
        root.leaf = true;
    }

    public Pair<Node, Integer> search(Node x, int key) {
        int i = 0;
        while (i < x.n && key > x.key[i]) {
            i++;
        }
        if (i <= x.n && key == x.key[i]) {
            return new Pair<>(x, i);
        } else if (x.leaf) {
            return null;
        } else {
            return search(x.child[i], key);
        }
    }

    private void splitChild(Node x, int i) {
        Node z = new Node();
        Node y = x.child[i];
        z.leaf = y.leaf;
        z.n = T - 1;

        for (int j = 0; j < T - 1; j++) {
            z.key[j] = y.key[j + T];
        }

        if (!y.leaf) {
            for (int j = 0; j < T; j++) {
                z.child[j] = y.child[j + T];
            }
        }
        y.n = T - 1;

        for (int j = x.n + 1; j >= i + 1; j--) {
            x.child[j + 1] = x.child[j];
        }
        x.child[i + 1] = z;

        for (int j = x.n; j >= i; j--) {
            x.key[j + 1] = x.key[j];
        }
        x.key[i] = y.key[T - 1];
        x.n = x.n + 1;
    }

    public void insert(final int key) {
        Node r = root;

        if (r.n == 2 * T - 1) {
            Node s = new Node();
            this.root = s;
            s.leaf = false;
            s.n = 0;
            s.child[0] = r;
            splitChild(s, 0);
            insertNonFull(s, key);
        } else {
            insertNonFull(r, key);
        }
    }

    private void insertNonFull(Node x, int key) {
        int i = x.n - 1;
        if (x.leaf) {
            while (i >= 0 && key < x.key[i]) {
                x.key[i + 1] = x.key[i];
                i--;
            }
            x.key[i + 1] = key;
            x.n = x.n + 1;
        } else {
            while (i >= 0 && key < x.key[i]) {
                i--;
            }
            i++;
            if (x.child[i].n == 2 * T - 1) {
                splitChild(x, i);
                if (key > x.key[i]) {
                    i++;
                }
            }
            insertNonFull(x.child[i], key);
        }
    }
    public void Show() {
        Show(root);
    }

    private void Show(Node x) {
        assert (x == null);
        for (int i = 0; i < x.n; i++) {
            System.out.print(x.key[i] + " ");
        }
        if (!x.leaf) {
            for (int i = 0; i < x.n + 1; i++) {
                System.out.println();
                Show(x.child[i]);
            }
        }
    }

    public boolean contains(int key) {
        if (search(root, key) != null) {
            return true;
        } else {
            return false;
        }
    }

    public Node getNodeOf(int key) {
        if (contains(key)) {
            return search(root, key).getNode();
        } else {
            return null;
        }
    }

    public int getKeyIdx(int key) {
        if (contains(key)) {
            return search(root, key).getIndex();
        } else {
            return -1;
        }
    }

}
