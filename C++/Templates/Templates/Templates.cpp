/*************************************************************
 * 1. Name:
 *             Caleb Nutall, Martin Nkala
 * 2. Assignment Name:
 *      Practice 07: Templates
 * 3. Assignment Description:
 *      Two templates: one of a function, one of a class
 * 4. What was the hardest part? Be as specific as possible.
 *      Honestly, nothing was really hard.
 * 5. How long did it take for you to complete the assignment?
 *            1hr
 **************************************************************/

#include <iostream>
#include<string>

using namespace std;

/***************************************
 * PROMPT
 **************************************/
template <typename T>
void prompt(T & value, const char* message)
{
   while (true)
   {
      // Instructions
      cout << message << ": ";
      cin  >> value;

      // Check for error
      if (cin.fail())
      {
         cerr << "ERROR, try again\n";
         cin.clear();
         cin.ignore(256, '\n');
      }
      else
         return;
   }
}


/***************************************
 * STACK
 **************************************/

template <typename T>
class Stack
{
public:
   Stack() : numElements(0) {}

   // Add an element to the stack
   void push(T value)
   {
      if (numElements < 10)
         data[numElements++] = value;
   }

   // Remove an element from the stack
   void pop()
   {
      if (numElements)
         numElements--;
   }

   // Retrieve the top-most element
   T top()
   {
      if (numElements)
         return data[numElements - 1];
      return T();
   }

private:
   T data[10];
   int numElements;
};


/*********************************
 * MAIN
  ********************************/
int main()
{
   //
   // Test prompt
   //

   // prompt for a double
   double valueDouble;
   prompt(valueDouble, "Enter a number");

   // prompt for a string
   string valueString;
   prompt(valueString, "Enter a string");
   
   // prompt for an integer
   int valueInt;
   prompt(valueInt, "Enter an Integer");
   //
   // Test stack
   //

   // a stack of doubles
   Stack <double>stackDoubles;
   stackDoubles.push(valueDouble);
   stackDoubles.push(2);
   stackDoubles.push(3);
   stackDoubles.pop();
   stackDoubles.pop();
   cout << "The first element is: "
        << stackDoubles.top() << endl;

   // a stack of strings
   Stack <string>stackString;
   stackString.push(valueString);
   stackString.push("Caleb");
   stackString.push("Martin");
   stackString.pop();
   stackString.pop();
   cout << "The first element is: "
        << stackString.top() << endl;

   // a stack of integers
   Stack <int>stackInt;
   stackInt.push(valueInt);
   stackInt.push(20);
   stackInt.push(60);
   stackInt.pop();
   stackInt.pop();
   cout << "The first element is: "
        << stackInt.top() << endl;
   return 0;
}
