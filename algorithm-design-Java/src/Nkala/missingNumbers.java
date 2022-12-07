package Nkala;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import static java.util.Arrays.sort;

public class missingNumbers {
    public int missingNumbers() {

        int[] nums = {3,0,1,6};

        int sum = 0;

        for(int i : nums){
            sum+=i;
             }
        int n = nums.length +1;

        return (n *(n-1) / 2) -sum;
        }


    }


