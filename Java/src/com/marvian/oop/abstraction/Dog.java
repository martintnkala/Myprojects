package com.marvian.oop.abstraction;

class Dog extends Animal {

    @Override
    void sound() {
        System.out.println("The dog burks");
    }

    @Override
    void eat() {
        System.out.println("The dog is Eating...");
    }
}
