package Nkala;

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        /**
         * I am using classes I created to create their Objects. Something to remember is that
         * an Object should have a state and behavior. I am using encapsulation to hide my attributes.
         */
        Car ford = new Car(12334, "Taurus", "Ruby Red");

        Person person = new Person("Martin", 2084440003, "John123@gmail.com");

        Apartment apartment = new Apartment("273 S. 5th W", 12, "Rexburg", "Idaho",83440);


        System.out.println("-------------------------------------------------");
        System.out.println("VEHICLE INFORMATION: "+ "\n"+ "Model: " + ford.getModel() +"\n" +"Plate number: " + ford.getPlate() + "\n"+ "color: " + ford.getColor());

        System.out.println("-------------------------------------------------------------");
        System.out.println("PERSONAL INFORMATION: " + "\n" + "Name:" + person.getName() + "\n" + "Phone Number: " + person.getPhoneNumber() + "\n" +" Email Address: " + person.getEmailAddress());
        System.out.println("-----------------------------------------------------------------------------------------------------------------------");
        System.out.println("APARTMENT INFORMATION: " +"\n" +" Apt. Number: "+apartment.getApartmentNumber()+ "\n" + "Street: "+apartment.getStreet() + "\n"+" Town: "+ apartment.getTown()+ "\n"+" State: " + apartment.getState() + "\n"+" Zip Code: " + apartment.getZip());

    }

}
