package Nkala;

public class AssertsStatement {
        public static void main(String[] args) {
            int[] toSum = {1,4,5};
            System.out.println(SumArray(toSum));
        }
        public static int SumArray(int [] numbers){
            assert numbers.length > 0;
            int total = 0;
            for(int i = 0; i < numbers.length; i++){
                total+=numbers[i];
            } return  total;
        }
    }
