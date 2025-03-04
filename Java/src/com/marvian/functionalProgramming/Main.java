package com.marvian.functionalProgramming;

import java.util.List;

public class Main {
    public static void main(String[] args) {

        List<Student> students = List.of(
                new Student("Martin", 12),
                new Student("John", 34),
                new Student("Leo", 34)
        );

        students.stream()
                .map(Student::getName)
                .filter(name -> !name.equals("Martin"))
                .forEach(System.out::println);



    }
}
