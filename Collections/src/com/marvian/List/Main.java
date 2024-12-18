package com.marvian.List;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {

        List<Integer> nums = new ArrayList<>(List.of(2, 6, 11, 10, 3));
        Object[] numArray = nums.toArray();
        System.out.println("Array iteration");
        for (Object o : numArray) {
            System.out.println(o + " ");
        }

        nums.sort(Integer::compare);

        System.out.println("Using Stream API");
        nums.stream()
                .map(num -> num * 2)
                .filter(num -> num % 3 == 1)
                .forEach(System.out::println);


        System.out.println(nums);
    }
}
