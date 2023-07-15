package Nkala;

public class Main
{
    public static void main(String[] args)
    {
        // Running my test cases.
        int[] source = { -1, -10, -3, -3, -200

//                         {-1, -10, -3, -3, -200}, {}, {90}, {3,6}, {6,3},
//                         {3, 12, 26, 38, 49, 59, 64}, {64, 59, 49, 38, 26, 12, 3},
//                         {3, 12, 26, 38, 49, 59, 64, 79}, {79, 64, 59, 49, 38, 26, 12, 3},
//                         {31, 55, 99, 31, 49, 49}, {-1, -10, -3, -200}, {-1000, 3000, 10000, 40000},
//                         {-200, -10, -3, -1 }
                            };


        // Calling the MergeSort method.
        mergesort(source, 0, source.length);


//        System.out.println("Sorted Array: " + Arrays.toString(source) );
    }

    public static  void mergesort(int[] input, int start, int end)
    {
         // Checking to see if it's a one element array.
        // If there's one element then the Array is sorted.
        if(end - start < 2)
        {
            return;
        }

        // Partitioning the array.
        int mid = (start + end) / 2;

        // Performing a merge sort on the left partition of my source array.
        mergesort(input, start,mid);

        //performing a merge sort on the right side of my source array.
        mergesort(input, mid, end);

        // Merging both sub Arrays.
        merge(input, start, mid, end);

    }

    public static void merge(int[] input, int start, int mid, int end)
    {
        // If the last element of the left sub array is less or equal to the first element of the right partition
        // this means that all elements on the left partition are less or equal than the smallest element in the right partition. .
        if (input[mid-1] <= input[mid])
        {
            return;
        }

        int i = start;
        int j = mid;
        int tempIdx = 0;

        // Creating and initializing temporal array with it's size.
        int[] temp = new int[end-start];

        // Once we are done traversing both left and right partitions drop out the loop.
        while (i < mid && j < end)
        {
            // Compare the first element in the left partition with the first element in the right partition.
            // if the first element in the left partition is less or equal to that of the first element on the right partition
            // increment i otherwise increment j.
            temp[tempIdx++] = input[i] <= input[j] ? input[i++] : input[j++];
        }
        System.arraycopy(input, i, input, start + tempIdx, mid-i);
        System.arraycopy(temp, 0, input, start, tempIdx);
    }

}



