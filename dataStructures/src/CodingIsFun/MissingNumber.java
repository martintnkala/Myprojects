package CodingIsFun;

import java.util.ArrayList;
import java.util.Arrays;

public class MissingNumber {
    public static void main(String[] args) {
        int[] nums = {3,0,1};
        Arrays.sort(nums);
        ArrayList<Integer> missingNum = new ArrayList<>();
        int a = 0;
        int b = 1;
        int c;

        if (nums[a]+1 == nums[b]){
            a = b;
            c = b+1;
            System.out.println(nums[c]);
        }else{
            missingNum.add(nums[b]);
//            System.out.println(missingNum);
        }
    }
}
