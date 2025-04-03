package com.marvian.recursion;

public class Main {
    public static void main(String[] args) {
        count(10);
    }
    static void count(int num){
        if(num > 0){
            count(num - 1);
            System.out.print(num + " ");
        }
    }
}
