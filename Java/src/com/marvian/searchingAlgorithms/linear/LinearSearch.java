package com.marvian.searchingAlgorithms.linear;

public class LinearSearch {

    public static boolean linearSearch(int[] array, int value) {
        // Using an enhanced for loop.
        for (int i : array) {
            if (i == value) {
                return true;
            }
        }
        return false;
    }
}
