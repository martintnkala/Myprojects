//
//  main.cpp
//  PrimesNumbers
//
//  Created by Martin Nkala on 10/16/23.
//

#include <iostream>

bool primeNumber(int num)
{
   if (num == 2)
   {
      return true;
   }
   
   if (num % 1 == 0 && num % 2 != 0)
   {
      return true;
   }
   
   
   return false;
}


int main()
{
   bool result  = primeNumber(12);
   
   std::cout << result << "\n";
   
   return 0;
}


