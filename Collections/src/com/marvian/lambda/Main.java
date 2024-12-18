package com.marvian.lambda;


import java.util.function.Consumer;

@FunctionalInterface
interface Hello {
    String sayHello();
}


class Greeting implements Hello {

    @Override
    public String sayHello() {
        return "Hello Martin T. Nkala";
    }
}



public class Main {

    public static void main(String[] args) {
        // Using Lambda
        Hello hello = () -> "Hello Martin";
        System.out.println(hello.sayHello());

        // Using creating a new class and then creating its obj
        // ...and then call the sayHello().
        Hello greet = new Greeting();
        System.out.println(greet.sayHello());

    }


}
