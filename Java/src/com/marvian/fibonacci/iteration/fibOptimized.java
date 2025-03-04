package com.marvian.fibonacci.iteration;

public class fibOptimized {
    public static int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        int prev2 = 0, prev1 = 1, curr = 0;

        for(int i = 2; i <= n; i++) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
}

// Index   0 1 2 3 4 5 6  7 8  9  10
//         0 1 1 2 3 5 8 13 21 34 55
// curr = 1 + 0;
// 0 = 1;
// curr(1) = prev1(1)