//
//  main.cpp
//  Collections
//
//  Created by Martin Nkala on 4/17/23.
//

#include <iostream>
#include<vector>
#include<string>
using namespace std;


int main()
{
   
   int nums[] = { 4, 21, 90, 34, 84};
   
   cout << nums[3] << endl;
   
   cout << *(nums + 3) << endl;
   
   
//   if(*(nums + 3) == 24)
//   {
//      std::cout << *(nums + 3) << " has been found"<< std::endl;
//   }
//   else
//   {
//      std::cout << "Number not found." << std::endl;
//   }
//
//   std::cout << "Using the ptr " << *(nums + 3) << std::endl;
//
//   std::cout << "Using the idx " << nums[3] << std::endl;
////   std::vector<int>nums;
//   std::vector<int>::iterator it;
//
//   nums.push_back(100);
//   nums.push_back(200);
//   nums.push_back(300);
//   nums.push_back(400);
//
//   for(it = nums.begin(); it < nums.end(); ++it)
//      if (*it == 400)
//         std::cout << " has been found." << std::endl;
////      std::cout << *it << std::endl;
//
   return 0;
}


