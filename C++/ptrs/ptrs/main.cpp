//
//  main.cpp
//  ptrs
//
//  Created by Martin Nkala on 1/25/23.
//

#include <iostream>
using namespace std;

void getCoordinates(int &r, int &c)
{
   int row;
   int column;
   
   cout << "Enter row value: " << endl;
   cin >> row;
   
   cout << "Enter column value: " << endl;
   cin >> column;
   
}

int main() {
      //   int num{10};
      //   int *p = {&num};
      //   cout << "Address of p: " << p << endl;
      //   cout << "Value of num: " << num << endl;
      //   cout << "memory Address of num: " << &num << endl;
      ////   dereferencing p
      //   cout << "Value of p: " << *p << endl;
      //
      //   int *ptr; // If left uninitialized ptr points somewhere in memory
      //   int *pointer{nullptr}; // Initialize ptr to Zero. This is good practice.
      //   cout << "garbage: " << ptr << endl;
      //   cout << "Set ptr to zero: "<< pointer << endl;
//   int x {10};
//   int y = {11};
//
//   int *p{&x};
//   cout << "Passing x by-reference: " << &x << endl;
//   cout << "Passing y by-reference: " << &y << endl;
//   cout << "Passing x by-value: " << x << endl;
//   cout << "Passing y by-value: " << y << endl;
//   cout << "pointer p: " << p << endl;
//   cout << "deference p: " << *p << endl;
   int r;
   int c;
   
   getCoordinates(r, c);
   cout << "row: " << endl;
   cout << "Column: " << endl;
   

   return 0;
}


