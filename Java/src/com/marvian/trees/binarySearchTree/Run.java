package com.marvian.trees.binarySearchTree;

public class Run {
    public static void main(String[] args) {
        Tree tree = new Tree();

        tree.insert(20);
        tree.insert(15);
        tree.insert(40);
        tree.insert(9);
        tree.insert(19);
        tree.insert(4);
        tree.insert(36);
        tree.insert(45);

        System.out.println("Inorder traversal is: ");
        tree.traverseInOrder();

        System.out.println("\nPreorder traversal is: ");
        tree.traversePreOrder();

        System.out.println("\nsearch for a value: ");
         tree.get(40);
         tree.get(45);
         tree.get(8888);
    }
}
