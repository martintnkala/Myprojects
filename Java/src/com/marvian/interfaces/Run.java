package com.marvian.interfaces;

public class Run {
    public static void main(String[] args) {
        IAnimal dog = new Dog();
        IAnimal cat = new Cat();

        Dog myDog = new Dog();
        Cat myCat = new Cat();

        dog.sound();
        cat.sound();

        myDog.sound();
        myCat.sound();
    }

}
