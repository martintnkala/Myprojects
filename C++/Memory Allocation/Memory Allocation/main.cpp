/*****************************
 * Header File:
 *       Memory Allocation - Week 9: Practice.
 * Author:
 *    Martin Nkala, Caleb Nuttall
 *****************************/

#include <iostream>
using namespace std;

/************************************
 *  PROMPT SIZE
 * This function will prompt for size.
 ************************************/
int promptSize()
{
   
   int size;
   cout << "How many items are in the array? ";
   cin >> size;
   
   return size;
}

/************************************
 *  ALLOCATE ARRAY
 * This function will allocate proper amount
 * of memory for the given array size..
 ************************************/
template <typename T>
bool allocateArray(int size, T* &array)
{
   array = new(nothrow) T[size +1];
   
   if (!array)
   {
      cout << "Array could not be allocated\n";
      return false;
   }
   else
   {
      return true;
   }
}

/************************************
 *  PROMPT VALUES
 * This function will prompt for values.
 ************************************/
template <typename T>
void promptValues(int size, T *array)
{
   cout << "Please enter " << size << " values: \n";
   
   for(int i = 1; i <= size; i++)
   {
      cout << "# " << i << ": ";
      cin >> array[i-1];
   }
}

/************************************
 *  DISPLAY
 * This function will display the values in the array.
 ************************************/
template<typename T>
void display(int size, const T* array)
{
   cout << "The elements in the list: \n";
   
   for(int i = 0; i < size; i++)
   {
      cout << "\t" << array[i] << endl;
   }
}

/************************************
 *  FREE MEMORY
 * This function will free memory used by array.
 ************************************/
void freeMemory(int* &array)
{
   delete array;
   array = nullptr;
}

/************************************
 *  MAIN
 * This function will populate the array with user input and displays.
 ************************************/
int main()
{
   int* array = nullptr;
   int size = promptSize();
   allocateArray(size,array);
   promptValues(size, array);
   display(size, array);
   freeMemory(array);

}
