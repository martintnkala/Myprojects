package com.Nkala_Interface;

import com.sun.source.tree.Tree;

import java.util.*;

class Animal{
   static String name;
   static int legs;

    public Animal(String name, int legs)
    {
        this.name = name;
        this.legs = legs;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setLegs(int legs) {
        this.legs = legs;
    }

    public String getName() {
        return name;
    }

    public int getLegs() {
        return legs;
    }


}
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World!");


    }
}


