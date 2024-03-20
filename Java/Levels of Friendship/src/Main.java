public class Main {

    public static void main(String[] args) {

        Acquaintance acquaintance = new Acquaintance("Josh");
        acquaintance.getStatus();

        Friend friend = new Friend("Martin", "Bindura");
        friend.getStatus();

        BestFriend bestFriend = new BestFriend("Vivian", "Rexburg", "I need thee every hour");
        bestFriend.getStatus();
    }
}
