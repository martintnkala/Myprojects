#include <iostream>
#include<string>

using namespace std;


template <typename T>
class Item 
{
private:
   string name;
   T value;
   
public:
   
   // constructor
   Item(string name, T value): name{name}, value{value}
   {}
   // getters
   string getName() const {return name;}
   T getValue() const   {return value;}
};


int main()
{
   Item<int>item {"Keys", 2};
   Item<string> item1 {"Mouse", "Laptop"};
   
   cout << item.getName() << " " << item.getValue() << endl;
   return 0;
}
