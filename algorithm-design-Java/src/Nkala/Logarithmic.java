package Nkala;
public class Logarithmic {

    public static void main(String[] args) {
        String word = "Martin", reversedWord = "";
        int[] numbers = {1,2,3,4,5,6};
        for (int number = 0; number < numbers.length; number++){

        }
        char eachCharacter;

        for( int i = word.length()-1; i >= 0; i--){
            eachCharacter = word.charAt(i);
//            System.out.println(eachCharacter);
            reversedWord += eachCharacter;
        }
        System.out.println(reversedWord);
    }
}
