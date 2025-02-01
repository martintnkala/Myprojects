package com.marvian.trees.binarySearchTree;

public class Tree {

    private Node root;

    public void insert(int value) {
        if (root == null) {
            root = new Node(value);
        }
        else {
            root.insert(value);
        }
    }

    public void traverseInOrder() {
        if (root != null) {
            root.traverseInOrder();
        }
    }
    public void traversePreOrder() {
        if (root != null) {
            root.traversePreOrder();
        }
    }
    public Node get(int value) {
        if (root != null) {
            root.get(value);
        }
        return null;
    }
}
