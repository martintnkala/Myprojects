import java.util.ArrayList;
import java.util.List;


class Main {
    // A method to calculate encryption validity based on instruction count, validity period, and keys
    public static int[] encryptionValidity(int instructionCount, int validityPeriod, int keys[]) {
        // Create an array to store the results
        int ret[] = new int[2];

        // Initialize variables
        int max = 1, i, j;

        // Loop through the keys array to find the maximum count of keys that can divide other keys
        for (i = 0; i < keys.length; i++) {
            int count = 0;
            for (j = 0; j < keys.length; j++) {
                if (keys[i] % keys[j] == 0)
                    count++;
            }
            if (count > max)
                max = count;
        }

        // Calculate encryption strength
        int encryptStrength = max * 100000;

        // Calculate the hijack value
        int hijack = instructionCount * validityPeriod;

        // Check if encryption strength is less than or equal to hijack value
        if (encryptStrength <= hijack)
            ret[0] = 1;

        // Store the encryption strength in the result array
        ret[1] = encryptStrength;

        return ret;
    }

    public static void main(String[] args) {
        // Call the encryptionValidity method with sample values
        int ans[] = encryptionValidity(1000, 10000, new int[]{2, 4, 8, 2});

        // Display the results
        System.out.println("Hijacker result: " + ans[0]);
        System.out.println("Encryption strength: " + ans[1]);
    }
}

