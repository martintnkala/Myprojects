package Nkala;

import java.util.Locale;
import java.util.Scanner;

public class MainDb {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        Address address = new Address(); // I am creating an instance for the Address class.
        CarDetails cardetails = new CarDetails();

        char choice = 'N';

        while (Character.toUpperCase(choice) == 'N' ){
            System.out.print("Enter Street address: " );
            String yourAddress = scanner.next();

            System.out.print("Enter complex name: ");
            String complexName = scanner.next();


            System.out.print("Enter Apartment number: ");
            int apartmentNumber = scanner.nextInt();

            // I am assigning whatever values the use will pass into yourAddress, complexName, and apartmentNumber variables as method arguments.
            address.setStreet(yourAddress);
            address.setComplexName(complexName);
            address.setApartmentNumber(apartmentNumber);

            System.out.println("You entered: " + address.getStreet() + " as your street address.");
            System.out.println("You entered: " + address.getComplexName() + " as the complex name.");
            System.out.println("You entered: "+ address.getApartmentNumber() + " as your apartment number.");


            System.out.print("Is this correct? (Y/N): ");
            choice = scanner.next().charAt(0);
        }


//        System.out.println(choice);
        if (Character.toUpperCase(choice) == 'Y'){
            System.out.println("Your information has been successfully saved");
        }
        else{
            System.out.println("Invalid");
        }
    }
}
