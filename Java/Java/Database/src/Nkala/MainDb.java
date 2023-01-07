package Nkala;

import java.util.Locale;
import java.util.Scanner;

public class MainDb {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);


        Address address = new Address(); // I am creating an instance for the Address class.
        CarDetails carDetails = new CarDetails();

        char choice = 'N';

        while (Character.toUpperCase(choice) == 'N' ){
            System.out.print("Enter Street address: " );
            String yourAddress = scanner.next();

            System.out.print("Enter complex name: ");
            String complexName = scanner.next();


            System.out.print("Enter Apartment number: ");
            int apartmentNumber = scanner.nextInt();

            System.out.println("======== Car Details Section ==================");

            System.out.print("Enter the Vehicle Identification number: ");
            int vin = scanner.nextInt();

            System.out.print("Enter the Car Model: ");
            String carModel = scanner.next();

            System.out.print("Enter the vehicle color: ");
            String vehicleColor = scanner.next();

            System.out.print("What year is your Vehicle: ");
            int year = scanner.nextInt();
            // I am assigning whatever values the use will pass into yourAddress, complexName, and apartmentNumber variables as method arguments.
            address.setStreet(yourAddress);
            address.setComplexName(complexName);
            address.setApartmentNumber(apartmentNumber);

            carDetails.setVin(vin);
            carDetails.setModel(carModel);
            carDetails.setColor(vehicleColor);
            carDetails.setYear(year);

            // I am assigning all my Car details getter methods that I am accessing via the carDetails instance for the CarDetails Class.
            // This is for easy readability.
            int vinNumber = carDetails.getVin();
            String model = carDetails.getModel();
            String carColor = carDetails.getColor();
            int manufacturedYear = carDetails.getYear();


            System.out.println("You entered: " + address.getStreet() + " as your street address.");
            System.out.println("You entered: " + address.getComplexName() + " as the complex name.");
            System.out.println("You entered: "+ address.getApartmentNumber() + " as your apartment number.");


            System.out.println("Vehicle Identification number: " + vinNumber );
            System.out.println("Model: " + model );
            System.out.println("Color: " + carColor );
            System.out.println("Year: "  + manufacturedYear);
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
