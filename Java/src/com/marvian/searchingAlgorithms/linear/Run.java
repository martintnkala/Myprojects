package com.marvian.searchingAlgorithms.linear;

public class Run {
    public static void main(String[] args) {

        int[] array = {11, 22, 13, 44, -15, 26, 97, 88, -9};
        int target = 44;

        boolean result = LinearSearch.linearSearch(array, target);
        System.out.println(result);
    }
}
