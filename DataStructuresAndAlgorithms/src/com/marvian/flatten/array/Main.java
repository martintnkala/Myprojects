package com.marvian.flatten.array;

public class Main {
    public static void main(String[] args) {
        int[][] array = {{1, 2, 3}, {4, 5, 6}, {7}};

        for (int[] outterArr : array) {
            for (int innerArr : outterArr) {
                System.out.print(innerArr + " ");
            }
        }
    }
}
