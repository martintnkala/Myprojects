public class Friend extends Acquaintance{
    protected String homeTown;

    public Friend (String name, String homeTown){
        super(name);
        this.homeTown = homeTown;

    }

    public void getStatus() {
        System.out.printf(name + " is my best friend." + " He is from " + homeTown + ".\n") ;
    }

}


