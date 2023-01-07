package Nkala;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class PrimeNumberOptimized {
    public static void main(String[] args) {
        while (true){
            Scanner input = new Scanner(System.in);
            System.out.println("Enter a number: ");
            int userInput = input.nextInt();
            ArrayList<Integer> primes = new ArrayList<>();


            for (int number = 2; number <= userInput; number++){ // 0 (n)
                primes.add(number);
            }
            // Defining the Maximum value of my Array.
//        int maxArrayValue = primes[primes.length-1];
            // T = 0(log n).
            // Finding the square root of the max value in the Array.
            for (int i = 0; i < Math.sqrt(userInput); i++){ // 0 (logN)
//            primes[i] = 1;
                // Getting each value in my Array using the Index.
                int value = primes.get(i);

                if (value != 0){
                    // Checking all nonprime numbers and then assigning them zero.
                    for(int j = i + value; j < primes.size(); j+=value) { // 0(n)

                        primes.set(j, 0);

                    }
                }


        }
            System.out.println(Arrays.toString(primes.toArray()));
        }
    }

}

