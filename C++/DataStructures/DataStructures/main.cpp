#include <iostream>
using namespace std;


void add (int n)  // T(n)
{
   if (n <= 20)
   {
      add(n+1);  // T(n+1)
      cout << n << " " << "\n"; // T(1)
   }
   
}

int main()
{
   add(1);
   return 0;
}
