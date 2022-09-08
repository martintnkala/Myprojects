package arrays;

public class Arrays {
    public static void main(String[] args) {
//        Arrays are not a dynamic data structure. Once we create an instance of that array we can't change its size.
//        In this case my array size will be 11.
//        Arrays are 0 based.
        /*
        Array properties:
        1. Contiguous block in memory.
        2. Every element occupies the same amount of space in memory.
         */
        int[] numbers = new int[11];

        numbers[0] = -1;
        numbers[1] = 0;
        numbers[2] = 2;
        numbers[3] = 9;
        numbers[4] = -11;
        numbers[5] = 4;
        numbers[6] = 7;
        numbers[7] = 12;
        numbers[8] = 3;
        numbers[9] = 1;
        numbers[10] = 11;

        int idx = 0;
        for(int num = 0; num < numbers.length; num++){
            if (numbers[num] == 12){
                idx = num;
                break;
            }

        }
        System.out.println(idx);
    }
}
