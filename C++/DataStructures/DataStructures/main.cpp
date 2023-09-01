#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include<map>

//void add (int n)  // T(n)
//{
//   if (n <= 20)
//   {
//      add(n+1);  // T(n+1)
//      cout << n << " " << "\n"; // T(1)
//   }
//
//}
//
//int main()
//{
//   add(1);
//   return 0;
//}

//struct Array
//{
//   // Data representation
//   int A[20] ;
//   int size;
//   int length;
//};

int main()
{
   vector<int> array{3,5,-4,11,-1,6};
   int targetSum = 10;
   
   map<int, int> results;
   
   for(auto value :array)
   {
      int difference = targetSum - value;
//      cout << value << "\n";
      if (difference == value)
         return array.empty();
      else
      {
         results.insert({difference, value});
      }
      for (auto itr = results.begin(); itr != results.end(); ++itr)
      {
         cout << itr->first
         << '\t' << itr->second << '\n';
      }
   }
   return 0;
}
 // 1 1 4 6 8 9
