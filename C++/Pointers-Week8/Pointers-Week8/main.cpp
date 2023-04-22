/*****************************
 * Header File:
 *       Pointers: week 8 - Practice
 * Author:
 *       Caleb Nuttall, Martin Nkala
 * Summary:
 *       Deducts date cost from the account that has the bigger amount.
 *****************************/
#include<iostream>
#include <cassert>
using namespace std;

/*************************
 * An account class
 *************************/
class Account
{
private:
   double balance;
   
public:
   Account(): balance(0.0) {}
   Account(double balance): balance(balance) {}
   
   void setBalance(double balance)
   {
      this->balance = balance;
   }
   
   double getBalance() const
   {
      return this->balance;
   }
   
   void deductBalance(double cost)
   {
      balance -= cost;
   }
};

/*************************
 * MAIN
 *************************/
int main() {
   
   double balance;
   double dinner;
   double movie;
   double iceCream;
   double totalSpending;
   
   // Creating Sam and Sue Account Instances.
   Account accountSam;
   Account accountSue;
   
   
   // Creating a ptr instance of the account class.
   Account *pAccount;
   
   // prompting for amounts for both accounts.
   cout << "What is Sam's account balance? $";
   cin >> balance;
   assert(balance > 0.0 && balance );
   accountSam.setBalance(balance);
   
   cout << "What is Sue's account balance? $";
   cin >> balance;
   assert(balance > 0.0);
   accountSue.setBalance(balance);
   
   cout << endl;
      
   // whoever has more money than the other person the ptr Paccount
   // will point to that account.
   accountSam.getBalance() < accountSue.getBalance() ? pAccount = &accountSue : pAccount = &accountSam;
   
   cout << "Cost of the date: " << endl;
   cout<< "\t\t Dinner: $";
   cin >> dinner;
 
   cout<< "\t\t Movie: $";
   cin >> movie;
   
   cout<< "\t\t Ice Cream: $";
   cin >> iceCream;
   
   // Adding up the total amount spent.
   totalSpending = dinner + movie + iceCream;
   
   // Deducting balance.
   pAccount -> deductBalance(totalSpending);
   
   // Printing balance.
   cout << "Sam's balance: " << accountSam.getBalance() << endl;
   cout << "Sue's balance: " << accountSue.getBalance() << endl;
   
   return 0;
}
