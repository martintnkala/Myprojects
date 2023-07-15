import java.util.Arrays;

public class twodArrays {
    public static void main(String[] args) {
        int[][] source = {
//            -1, -10, -3, -3, -200

                {-1, -10, -3, -3, -200}, {}, {90}, {3,6}, {6,3},
                {3, 12, 26, 38, 49, 59, 64}, {64, 59, 49, 38, 26, 12, 3},
                {3, 12, 26, 38, 49, 59, 64, 79}, {79, 64, 59, 49, 38, 26, 12, 3},
                {31, 55, 99, 31, 49, 49}, {-1, -10, -3, -200}, {-1000, 3000, 10000, 40000},
                {-200, -10, -3, -1 }
        };
        System.out.println(source.length);
        System.out.println(Arrays.toString(source[0]));

        for (int i = 0; i < source.length; i++)
        {
            for (int j = 0; j < source[i].length; j++)
            {
                System.out.print(source[i][j] + ",");
            }
            System.out.println();
        }
    }
}
