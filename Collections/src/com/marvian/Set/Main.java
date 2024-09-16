package com.marvian.Set;

import java.util.*;

public class Main {
    public static void main(String[] args) {

        // REMEMBER: SortedSet is a subInterface of the Set interface.
        // This interface ensures that elements in the Set are sorted.


        System.out.println("Sorted Set");
        SortedSet<Integer> numsSortedSet = new TreeSet<>(List.of(20, 2, 11, 2, 9, 10));
        numsSortedSet.forEach(System.out::println);


        System.out.println("Hash Set: Order doesn't matter");
        Set<Integer> numsHashSet = new HashSet<>(List.of( 20,2, 11, 2, 9, 10));
        numsHashSet.forEach(System.out::println);

        System.out.println("Linked Hash Set: Order does matter");
        Set<Integer> numsLinkedHasheSet = new LinkedHashSet<>(List.of(20, 2, 11, 2, 9, 10));
        numsLinkedHasheSet.forEach(System.out::println);
    }
}
