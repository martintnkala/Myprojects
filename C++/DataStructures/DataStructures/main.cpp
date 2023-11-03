#include <iostream>
using namespace std;
#include <vector>
#include<stack>
#include <string>
#include<map>
#include<list>




//void reverseNums (int nums[], int nums_size)
//{
//   stack<int> s;
//   for (int i = 0; i < nums_size; ++i)
//      s.push(nums[i]);
//   
//   for (int i = 0; i < nums_size; ++i)
//      nums[i] = s.top();
//      s.pop();
//
//}

int fib (int n)
{
   if (n <= 0)
   {
      return 0;
   }
   
   if (n == 1)
   {
      return 1;
   }
    // 0 1 1 2 3 5 8 13 21 34 55
   else
   {
      return fib(n - 1) + fib(n - 2);
   }
}
//int factorial(int num)
//{
//   if (num == 0)
//   {
//      return 1;
//   }
//   return num * factorial(num -1);
//}
int main()
{
   int n = 6;
   cout << fib(n) << "\n";
   
   list<int> nums;
   
   
   nums.p
   
//   cout << size(nums) << endl;
//
//   stack<int> nums;
//   nums.push(20);
//   nums.push(30);
//   nums.push(40);
//   nums.push(50);
//   nums.push(60);
//   nums.
//   // Clear a stack
//   nums = stack<int>();
//   
//   cout << "Stack size of Clear: " << nums.size() << endl;
//   
//   deque<int> numbers {1, 2, 4, 5};
//   deque<int>::iterator it;
//   
//   /********************************
//    * foreach loop
//    *************************************************/
//   for (int num : numbers)
//      cout << num << "\n";
//      numbers.at(0) = 11;
//      numbers.pop_front();
//      numbers.pop_back();
//      numbers.push_front(11);
//      numbers.push_front(12);
//      numbers.push_back(100);
//   
//   cout << "-----------------------------" << endl;
//   
//   /********************************
//    * Iterator for loop
//    *************************************************/
//  
//   for (it = numbers.begin(); it != numbers.end(); ++it)
//      cout << *it << endl;
//    
//         
////
////   stack<int>nums1(move(nums));
////   
////   cout << "Move constructor: " << nums1.size() << endl;
//   int lhs = numbers.at(0);
//   int rhs = numbers.at(1);
//   int result = (lhs > rhs) ? lhs : rhs;
//   
//   cout << "Result: " << result << endl;
   
//   int result= max(2,7);
//   
//   cout << result << endl;
//      
   return 0;
}


