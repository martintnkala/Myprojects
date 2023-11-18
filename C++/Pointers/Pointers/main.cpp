#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <iterator>
#include <map>
using namespace std;

int main()
{
//   list<int> nums;
//   cout<< "sizeof nums: " << sizeof(nums) << "\n";
//   cout << "Size before insertion: " << nums.size() << "\n";
//   
//   for (int i = 0; i <= 10; i++)
//      nums.push_back(i);
//   nums.remove(9);
////   nums.sort(nums);
//   
//   cout << "Size after insertion: " << nums.size() << "\n";
//
//      map <char, string> m;
//      m['b'] = string("Bravo");
//      m['a'] = string("Alpha");
//      m['c'] = string("Charlie");
//      m['d'] = string("Delta");
//
//      cout << m.size() << endl;
      map <char, string> m;
      m['b'] = string("Bravo");
      m['a'] = string("Alpha");
      m['c'] = string("Charlie");
      m['d'] = string("Delta");

   cout << "a=" << m['a'] << endl;
   return 0;
}

