package com.marvian.lambda;

public class Cat implements Printable {
    @Override
    public void print() {
        System.out.println("meow");
    }

    @Override
    public String toString() {
        return "Cat{}";
    }
}
