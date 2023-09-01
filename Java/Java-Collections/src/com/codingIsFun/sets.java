package com.codingIsFun;

import java.util.*;

public class sets {

    public static void main(String[] args)
    {
        boolean isFound = true;
        List<Integer> array = new ArrayList<>();
        array.add(5);
        array.add(1);
        array.add(22);
        array.add(25);
        array.add(6);
        array.add(-1);
        array.add(8);
        array.add(10);

        List<Integer> seq = new ArrayList<>();
        seq.add(1);
        seq .add(6);
        seq.add(-1);
        seq .add(10);

        int arrIdx = 0;
        int seqIdx = 0;

        System.out.println(seqIdx);
        System.out.println(seq.size());

        if (seq.get(seqIdx) == array.get(arrIdx))
        {
            seqIdx++;

        } else {
            arrIdx++;
            System.out.println(!isFound);
        }
        System.out.println(seqIdx);


    }



}
