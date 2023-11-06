package com.iterator;

import java.util.*;

public class NumberIterator {
    public static void main(String[] args) {

        List<Integer> numberList = new ArrayList<>();
        Set<Integer> numberSet = new TreeSet<>();
        numberSet.add(10);
        numberSet.add(19);
        numberSet.add(12);
        numberSet.add(14);
        numberSet.add(16);

        var findNumber = 22;

        Iterator<Integer> numberItr = numberSet.iterator();

        while (numberItr.hasNext())
        {
            numberList.add(numberItr.next());
        }

        if (numberList.contains(findNumber))
            System.out.println(findNumber + " found");
        else
            System.out.println(findNumber + " Not found");




    }
}
