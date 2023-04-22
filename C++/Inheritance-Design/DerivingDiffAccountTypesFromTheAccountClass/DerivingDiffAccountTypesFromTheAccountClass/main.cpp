
#include <iostream>
#include"Account.hpp"
#include"SavingsAccount.hpp"

using namespace std;

int main()
{
   // Using the Account class - Base class.
   cout << "\n====Account================================" << endl;
   // Instantiating the Account Object
   Account account;
   
   account.deposit(2000.0);
   account.withdraw(500.0);
   
   cout << endl;
   
   // Instantiating the Account Ptr Object.
   Account *pAccount = nullptr;
   
   pAccount = new Account;
   
   pAccount->deposit(1000.0);
   pAccount->withdraw(250.0);
   
   
   cout << "\n====Savings Account================================" << endl;
   // Using the Savings Account.
   SavingsAccount sAccount;
   
   sAccount.deposit(4000.0);
   sAccount.withdraw(2000.0);
   
   cout << endl;
   
   SavingsAccount *pSavAccount = nullptr;
   
   pSavAccount = new SavingsAccount;
   
   pSavAccount->deposit(1200.0);
   pSavAccount->withdraw(1000.0);
   
   cout << endl;
   return 0;
}
