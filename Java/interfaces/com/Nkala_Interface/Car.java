package com.Nkala_Interface;

public class Car implements IVehicle {
    @Override
    public void start_engine() {
        System.out.println("The engine is running.");
    }

    @Override
    public void drive() {
        System.out.println("The car is moving.");
    }
}
