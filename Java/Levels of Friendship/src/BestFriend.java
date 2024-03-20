public class BestFriend extends Friend {
    private String favoriteSong;


    public BestFriend(String name, String homeTown, String favoriteSong) {
        super(name, homeTown);
        this.favoriteSong = favoriteSong;

    }

    public void getStatus() {
        System.out.printf(name + " is my best friend." + " He is from " + homeTown + ". And her favorite song is " + favoriteSong + ".\n") ;
    }
}
