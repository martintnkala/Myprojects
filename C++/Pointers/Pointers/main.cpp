#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
using namespace std;

int main()
{
   list<int> nums;
   cout<< "sizeof nums: " << sizeof(nums) << "\n";
   cout << "Size before insertion: " << nums.size() << "\n";
   
   for (int i = 0; i <= 10; i++)
      nums.push_back(i);
   nums.remove(9);
//   nums.sort(nums);
   
   cout << "Size after insertion: " << nums.size() << "\n";
   
   return 0;
}

