package com.marvian.interfaces;

@FunctionalInterface
interface A {
    int add(int a, int b);
}

public class Main {
    public static void main(String[] args) {

        A obj = (i, j) -> i + j;
        System.out.println((obj.add(4, 5)));
    }
}
