package com.marvian.fibonacci.iteration;

import static com.marvian.fibonacci.iteration.fibOptimized.fib;

public class Run {
    public static void main(String[] args) {
        int number = 10;

        int result = fib(number);
        System.out.println(result);
    }
}
