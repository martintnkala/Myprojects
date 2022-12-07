package CodingIsFun;

import java.util.Scanner;

public class recursion {
    public static void main(String[] args) {
//        Scanner input = new Scanner(System.in);

        System.out.println(" The recursion is: " + recursive(50));
    }

    //  This is an exponential algorithm.
   //   I need to make it more efficient.
    public static int recursive(int num){
        if (num == 1){
            // This is a base case.
            return 2;
        } else if (num == 2) {
            // This is a base case.
            return 1;
        }else{
            // function is calling itself.
            return recursive (num - 1) + recursive(num - 2);
        }
    }
}
