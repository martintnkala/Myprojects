package com.marvian.interfaces;

import com.marvian.interfaces.IAnimal;

class Dog implements IAnimal {
    @Override
    public void eat() {
        System.out.println("Dog is eating...");
    }

    @Override
    public void sound() {
        System.out.println("A dog burks");
    }
}
