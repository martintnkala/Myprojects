package com.marvian.example;

public class Main {

    // 0(logN)
    static boolean isPalindrome(String str) {
        if (str == null || str.isEmpty()) {
            return false;
        }
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        String str = "Madam,I'm Adam."
                .toLowerCase()
                .replaceAll("[\\p{Punct}\\s]", "");

        Boolean isPalindrome = isPalindrome(str);

        System.out.println(isPalindrome);

        // Using StringBuilder => O(n)

        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(str);
        String reversedString = stringBuilder.reverse().toString();

        if (str.equals(reversedString)) {
            System.out.println("YES");
        } else {

            System.out.println("false");
        }


    }


}
