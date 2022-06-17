package Nkala;

public class Person {
    /**
     * I have created these fields and set them to private so that they can be encapsulated when getting accessed publicly.
     * Setting these fields to private tells intelliJ that don't let a class that is outside the Person Class access these fields
     * When creating attributes in Java make sure that you type in the datatype first with the first letter capitalized.
     */
    private String name;
    private int phoneNumber;
    private String emailAddress;


    public Person(String name, int phoneNumber, String emailAddress){
        System.out.println("Person constructor with parameters called.");
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.emailAddress = emailAddress;
    }



    public void setName(String name){



    }

    public void setPhoneNumber(int phoneNumber){

    }

    public void setEmailAddress(String emailAddress){

    }

    public String getName(){
        return this.name;
    }
    public int getPhoneNumber(){
        return this.phoneNumber;
    }
    public String getEmailAddress(){
        return this.emailAddress;
    }
}
