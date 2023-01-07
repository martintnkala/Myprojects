package Nkala;

import java.util.ArrayList;
import java.util.Arrays;

public class PrimeNumber {
    public static void main(String[] args) {

        int[] primes = {2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        // i = 0 and value = 6
        // j = 8
        // Defining the Maximum value of my Array.
        int maxArrayValue = primes[primes.length-1];
//        System.out.println(maxArrayValue);
        // T = 0(log n).
        // Finding the square root of the max value in the Array.
        for (int i = 0; i < Math.sqrt(maxArrayValue); i++){
//            primes[i] = 1;
            // Getting each value in my Array using the Index.
            int value = primes[i];

            // Checking all nonprime numbers and then assigning them zero.
            for(int j = i + value; j < primes.length; j+=value) {
                primes[j] = 0;

            }
            System.out.println(Arrays.toString(primes));
        }

        }
    }

