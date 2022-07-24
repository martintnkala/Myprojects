package Nkala;

import java.util.Scanner;

public class MainDb {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Address address = new Address();


        System.out.print("Enter Street address: " );
        String yourAddress = scanner.nextLine();

        System.out.print("Enter complex name: ");
        String complexName = scanner.nextLine();


        System.out.print("Enter Apartment number: ");
        int apartmentNumber = scanner.nextInt();

        address.setStreet(yourAddress);
        address.setComplexName(complexName);
        address.setApartmentNumber(apartmentNumber);

        System.out.println("You entered: " + address.getStreet() + "as your street address.");
        System.out.println("You entered: " + address.getComplexName() + "as the complex name.");
        System.out.println("You entered: "+ address.getApartmentNumber() + "as your apartment number.");


        System.out.print("Is this correct? (Y/N): ");
        String choice = scanner.next();

        if (choice == "Y".toUpperCase()){
            System.out.println("Your information has been successfully saved");
        } else if(choice == "N".toUpperCase()){
            System.out.print("Enter Street address: " );
//            String yourAddress = scanner.nextLine();

            System.out.print("Enter complex name: ");
//            String complexName = scanner.nextLine();


            System.out.print("Enter Apartment number: ");
//            int apartmentNumber = scanner.nextInt();

            address.setStreet(yourAddress);
            address.setComplexName(complexName);
            address.setApartmentNumber(apartmentNumber);

            System.out.println("You entered: " + address.getStreet() +" "+ " as your street address.");
            System.out.println("You entered: " + address.getComplexName() +" "+ " as the complex name.");
            System.out.println("You entered: "+ address.getApartmentNumber() +" " + " as your apartment number.");

            System.out.print("Is this correct? (Y/N): ");
//            char choice = scanner.next();
            if (choice == "Y".toUpperCase()){
                System.out.println("Your information has been successfully saved");
            }
        } else{
            System.out.println("Invalid");
        }
    }
}
