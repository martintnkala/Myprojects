package com.codingIsFun;

import java.util.*;

public class sets {
    public static void main(String[] args) {
        // Remember that sets hold no duplicate elements.
        // Removing in a set is 0(1).
        // Adding is 0(1).
        // A set is mutable.

        // Working with Strings.
//        Set<String> countries = new HashSet<>();
//
//        countries.add("Zimbabwe");
//        countries.add("USA");
//        countries.add("Canada");
//        countries.add("Namibia");
//        countries.add("Malawi");
//
//        ArrayList<Integer> array = new ArrayList<>();
//        array.add(2);
//        array.add(3);
//
//        for (int value: array){
//            System.out.println(value);
//        }
//        System.out.println("Array size: "+array.size());
//        Iterator<String> iterator = countries.iterator();
//
//        while (iterator.hasNext()){
//            System.out.println(iterator.next());
//        }
//        System.out.println(countries.size());
//
//        // working with numbers.
//        Set<Integer> nums = new HashSet<>();
//        nums.add(1);
//        nums.add(2);
//        nums.add(3);
//        nums.add(4);
//        nums.add(5);
//
//        nums.remove(5);
//
//        System.out.println(nums);
//
//        int sum = 0;
//        for(int num : nums){
//            sum+=num;
//        }
//        System.out.println("The sums is: " + sum);

        int[] nums = {1,2,3,4};

        for (int value:nums) {
            int squared = value * value;
            System.out.println(squared);
        }
        System.out.println(Arrays.toString(nums));

    }
}
