package com.marvian.palindrome;

public class StringPalindrome {
    public static boolean isPalindrome(String s) {
        if (s == null || s.isEmpty()) {
            return false;
        }

        s = s.trim().toLowerCase(); // Assign the modified string

        StringBuilder sb = new StringBuilder(s);
        return sb.reverse().toString().equals(s); // Compare reversed string
    }
}

