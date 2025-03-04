package com.marvian.oop.encapsulation;

public class Run {
    public static void main(String[] args) {
        Encapsulation encapsulation = new Encapsulation();

//                new Encapsulation(
//                "Martin", "Nkala", "martinnkala@gmail.com", "801-201-0011"
//        );

        encapsulation.setFirstName("John");
        encapsulation.setLastName("Doe");
        encapsulation.setEmailAddress("john@doe.com");
        encapsulation.setPhoneNumber("1234567890");

        String studentDetails = " First Name: " + encapsulation.getFirstName() + " \n" +
                                " Last Name: " + encapsulation.getLastName() + "\n " +
                                "Email Address: " +  encapsulation.getEmailAddress() + "\n " +
                                "Phone Number: "+ encapsulation.getPhoneNumber();


       System.out.println(studentDetails);
    }
}
