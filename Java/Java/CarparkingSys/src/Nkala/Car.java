package Nkala;

public class Car {
    /**
     * First set your fields and then afterwards create a class that you will pass in some parameters. Once you have done that with your constructor use the "THIS" keyword
     * to be able to reuse that constructor. Create a set method for each field within your constructor and then after that construct get methods likewise.
     * You will use the get method whenever you call each object for every instance you created. This is how you will be able to retrieve data without disclosing
     * the structure of each class you created.
     */
    private int plate;
    private String model;
    private String color;

    public Car(int plate, String model, String color){
        this.plate = plate;
        this.model = model;
        this.color = color;


    }

    public void setModel(String model){

    }
    public void setPlate(int plate){

    }
    public void setColor(String color){

    }
    public String getModel(){

        return this.model;
    }
    public int getPlate(){
        return this.plate;
    }
    public String getColor(){
        return this.color;
    }

}

