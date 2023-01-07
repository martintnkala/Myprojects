package Nkala;

public class CarDetails {

    private int vin;
    private String model;
    private String color;
    private int year;

    public void setVin(int vin) {
        this.vin = vin;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public void setYear(int year) {
        this.year = year;
    }


    public int getVin() {
        return vin;
    }

    public String getModel() {
        return model;
    }

    public String getColor() {
        return color;
    }

    public int getYear() {
        return year;
    }
}
