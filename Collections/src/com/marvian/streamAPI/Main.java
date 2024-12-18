package com.marvian.streamAPI;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> nums = Arrays.asList(12 ,1, 2, 18, 11, 50, 4, 7 );

        nums.forEach(System.out::println);
        System.out.println("Printing even numbers");
        nums.stream()
                .filter(num -> num % 2 == 0)
                .sorted()
                .forEach(System.out::println);
    }
}
