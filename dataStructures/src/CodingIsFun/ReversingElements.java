package CodingIsFun;

import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class ReversingElements {
    public static void main(String[] args) {

       int[] nums = {10, 20, 30, 40, 50, 60, 70};
        System.out.println("Original Array: " + Arrays.toString(nums));

        reverse(nums);

        System.out.println("Reversed Array: " + Arrays.toString(nums));
    }

    private static void reverse(int[] nums){

        int maxIdx = nums.length-1;
        int midIdx = nums.length/2;

        // Time complexity is 0(n) and space complexity is 0(1).
        for(int idx = 0; idx < midIdx; idx++){

            int temp = nums[idx];
            nums[idx] = nums[midIdx-idx];
            nums [maxIdx-idx] = temp;

            System.out.println(nums[maxIdx -idx]);
        }

    }
}
