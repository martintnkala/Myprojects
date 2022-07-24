package Nkala;

public class Address {
    private String street;
   private String complexName;
    private int apartmentNumber;


    public void setStreet(String street) {
        this.street = street;
    }

    public void setComplexName(String complexName) {
        this.complexName = complexName;
    }

    public void setApartmentNumber(int apartmentNumber) {
        this.apartmentNumber = apartmentNumber;
    }

    public String getStreet() {
        return street;
    }

    public int getApartmentNumber() {
        return apartmentNumber;
    }

    public String getComplexName() {
        return complexName;
    }
}
