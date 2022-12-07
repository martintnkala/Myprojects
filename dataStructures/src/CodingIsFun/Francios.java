package CodingIsFun;

import java.math.BigInteger;
import java.util.Scanner;

public class Francios {

    public static void main(String[] args) {
        int number ;
        do { // This is the Loop body, and I am using a post-condition.
            Scanner input = new Scanner(System.in);
            System.out.println(" Enter a number: ");
            number = input.nextInt();


            System.out.println(" Your number is: " + number + " and the Francios number is: " + francios(number) );
        } while (number >= 1); // This is the controlling expression.


    }

    public static BigInteger francios(int num){

        if (num == 2 || num == 1){
            return BigInteger.valueOf(num);
        }


        BigInteger francFirstNum = BigInteger.valueOf(2);
        BigInteger francSecondNum = BigInteger.valueOf(1);
        BigInteger currentNum = BigInteger.valueOf(3);

        /* This is 0(n) because I am getting the francios number by
           adding the two preceding numbers in sequence.
           This complexity is way better than the exponential algorithm using recursion.
        * */
        for (int i = 3; i <= num; i++){
            assert i >= 3 ;
            currentNum = francFirstNum.add(francSecondNum);
            francFirstNum = francSecondNum;
            francSecondNum = currentNum;
        }
        return currentNum;
    }
}
