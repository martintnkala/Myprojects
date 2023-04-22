/*************************************************************
 * 1. Name:
 *      Martin Nkala, Caleb Nuttall
 * 2. Assignment Name:
 *      Practice 11: Exceptions
 * 3. Assignment Description:
 *      Throwing and catching exceptions
 * 4. What was the hardest part? Be as specific as possible.
 *      How to use one try catch block to handle all the error messages.
 * 5. How long did it take for you to complete the assignment?
 *      30 mins
 **************************************************************/

#include <iostream>
using namespace std;

/**************************************
 * GET POSITION
 * Turn a chess position like "d4" into a number
 **************************************/

int getPosition(const char* position)
{
   int row = -1;
   int col = -1;
   try {
      if (nullptr == position)
      {
         throw "Please provide a valid string\n";
      }

      for (const char * p = position; *p; p++)
      {
         if (isalpha(*p))
         {
            if (col != -1)
            {
               throw "More than one column specifier\n";
            }
            else if (isupper(*p))
            {
               throw "Columns must be lowercase\n";
            }
            else if ('a' <= *p && *p <= 'h')
               col = *p - 'a';
            else
            {
               throw "Columns must be between a and h\n";
            }
         }
         else if (isdigit(*p))
         {
            if (row != -1)
            {
               throw " More than one row specifier\n";
            }
            else if ('1' <= *p && *p <= '8')
               row = *p - '1';
            else
            {
               throw "Rows must be between 1 and 8\n";
            }
         }
         else
         {
            throw "Unknown letter\n";
         }
      }

      if (row == -1)
      {
          throw "You must specify a row\n";
      }
      else if (col == -1)
      {
        throw "You must specify a column\n";
      }
      
   } catch (const char *message) {
      cout << "\tERROR: " << message << endl;
      return  -1;
   }
   return row * 8 + col;
}

/**************************************
 * MAIN
 **************************************/
int main()
{
   char text[256];
   cout << "Enter a chess position such as 'd4'\n";

   while (true)
   {
      cout << "> ";
      cin  >> text;
      int position = getPosition(text);
      if (position != -1)
         cout << "\tPosition: " << position << endl;
   }

   return 0;
}

