package com.marvian.streams;

import java.util.Arrays;
import java.util.List;
import java.util.Objects;

public class Main {
    public static void main(String[] args) {
        List<String> names = Arrays.asList("Martin", "Elise", "John", "Vivian");
        names.stream()
                .filter(name -> Objects.equals(name, "Martin"))
                .forEach(System.out::println);
    }
}
