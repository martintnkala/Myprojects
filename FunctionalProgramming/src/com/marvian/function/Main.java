package com.marvian.function;

import java.util.function.Function;

public class Main {
    public static void main(String[] args) {

        // Function chaining
        Integer addAndMultiplyAndDivide = addFunction
                .andThen(multiplyFunction)
                .andThen(divideFunction)
                .apply(10);
        System.out.println(addAndMultiplyAndDivide);


    }


    static Function<Integer, Integer> addFunction = num -> num + 1;
    static Function<Integer, Integer> multiplyFunction = num -> num * 2;
    static Function<Integer, Integer> divideFunction = num -> num / 2;


}
