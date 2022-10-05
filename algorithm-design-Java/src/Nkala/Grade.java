package Nkala;

import java.util.Scanner;

public class Grade {

    public static void main(String[] args) {
        Scanner myGrade = new Scanner(System.in);

        System.out.println("Please enter your class grade: ");
        int grade = myGrade.nextInt();
            if (grade >= 90) {
                System.out.println("A");
            } else if (grade >= 80) {
                System.out.println("B");

            } else if (grade >= 70) {
                System.out.println("C");
            } else {
                System.out.println("D");
            }


        }
    }



