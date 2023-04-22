/*****************************
 * Header File:
 *     Pointer Arithmetic
 * Author:
 *     Martin Nkala, Caleb Nuttall
 * Summary:
 *     Practicing how to do pointer Arithmetic.
 *****************************/

#include <iostream>

using namespace std;

/************************************
 * GET TEXT
 * This function will get text from the user.
 ************************************/
void getText(char *text)
{
 
   cout << "Enter text: ";
   
   cin.getline(text, 256);
}

/************************************
 * GET LETTER
 * This function will get a character from the user.
 ************************************/
char getLetter()
{
   char letter;
   cout << "Enter a letter: ";
   cin >> letter;
   
   return letter;
}

/************************************
 * COUNT ARRAY
 * This function will count the number of instances for a in letter in word
 * using index loop.
 ************************************/
int countArray(char *word, char letter)
{
   int count = 0;
   
   for(int i = 0; i < strlen(word); i++)
   {
      if(letter == word[i])
         count++;
   }
   return count;
}

/************************************
 * COUNT POINTER ARRAY
 * This function will count the number of instances for a in letter in word
 * using a pointer loop.
 ************************************/
int countPointerArray(char *word, char letter)
{
   int count = 0;
   
   for (char *p = word; *p; p++)
   {
      if(letter == *p)
      {
         count++;
      }
   }
   return count;
}

/************************************
 * MAIN
 ************************************/
int main() {
   char text[100] = "\0";
   char *word = text;
   
   getText(word);
   char character = getLetter();
   
   cout << "Count using the array loop: " << countArray(word, character) << endl;
   cout << "Count using the pointer loop: " << countPointerArray(word, character) << endl;
   return 0;
}
