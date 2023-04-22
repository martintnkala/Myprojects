/*****************************
 * Header File:
 *    Practice 06 : Files
 * Author:
 *    Caleb Nuttall, Martin Nkala
 * Summary:
 *    Reads, display and stores balance.
 *****************************/

#include <iostream>
#include<fstream>
#include<string>
using namespace std;

/*************************
 * DISPLAY BALANCE
 * Displays the Balance.
 *************************/
void displayBalance(double balance)
{
   cout << "Account balance: $" << balance << endl;
}

/*************************
 * READ BALANCE
 * Reads the balance from the file
 *************************/
double readBalance(string filename)
{
   ifstream fin;
   
   fin.open(filename.c_str());
   
   if(fin.fail())
   {
      cout << "Unable to open " << filename << endl;
      return 0;
     
   }
      
   else
   {
      double balance;
      fin >> balance;
      return balance;
   }
     
}

/*************************
 *  WRITE BALANCE
 *   Stores balance in file.
 *************************/
void writeBalance(string filename, double balance)
{
   ofstream fout;
   
   fout.open(filename.c_str());
   
   if(!fout.fail())
   {
      fout << balance << endl;
      cout << "Balance successfully written to "
      << filename << endl;
   }
   else
   {
      cout << "Unable to write balance to " << filename << endl;
   }
}

/*************************
 *  UPDATE BALANCE
 *   Updates the current balance.
 *************************/
void updateBalance(string filename)
{
   double update;
   cout << "Change: $";
   cin >> update;
   
   double balance = readBalance(filename);
   
   balance += update;
   
   displayBalance(balance);
   writeBalance(filename, balance);
}

/*************************
 *  MAIN
 *   Reads, display and stores balance.
 *************************/
int main() {
   double balance = readBalance("data.txt");
   displayBalance(balance);
   updateBalance("data.txt");
   
   return 0;
}



