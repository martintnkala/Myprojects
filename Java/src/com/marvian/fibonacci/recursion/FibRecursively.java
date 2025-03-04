package com.marvian.fibonacci.recursion;

public class FibRecursively {

    // (T) complexity = 2^n
    public static int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
// Index   0 1 2 3 4 5 6  7 8  9  10
        // 0 1 1 2 3 5 8 13 21 34 55
    }
}
