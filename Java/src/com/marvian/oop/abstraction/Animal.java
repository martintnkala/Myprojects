package com.marvian.oop.abstraction;

// Abstraction is a mechanism in OOP that hides internal complex implementation details
// and showing necessary features of an object.
// The main focus is on what the object does instead how it does it.

abstract class Animal {
    // abstract method
    abstract void sound();

    // concrete method
    void eat() {
        System.out.println("Eating...");
    }
}



