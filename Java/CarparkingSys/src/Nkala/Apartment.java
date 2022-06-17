package Nkala;

public class Apartment {

    private String street;
    private int apartmentNumber;
    private String town;
    private String state;
    private int zip;


    public Apartment(String street, int apartmentNumber, String town, String state, int zip){

        this.apartmentNumber = apartmentNumber;
        this.state = state;
        this.town = town;
        this.state = state;
        this.zip = zip;
        this.street = street;
    }


    public void setStreet(String street){

    }
    public void setApartmentNumber(int apartmentNumber){

    }
    public void setTown(String town){

    }
    public void setState(String state){

    }
    public void setZip(int zip){

    }

    public int getApartmentNumber() {
        return apartmentNumber;
    }

    public int getZip() {
        return zip;
    }

    public String getState() {
        return state;
    }

    public String getStreet() {
        return street;
    }

    public String getTown() {
        return town;
    }
}

