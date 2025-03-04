package com.marvian.interfaces;

import com.marvian.interfaces.IAnimal;

public class Cat implements IAnimal {
    @Override
    public void eat() {
        System.out.println("cat eating...");
    }

    @Override
    public void sound() {
        System.out.println("A cat meows");
    }
}
