#ifndef SavingsAccount_hpp
#define SavingsAccount_hpp
#include "Account.hpp"

// Savings account IS-An Account
class SavingsAccount: public Account
{
private:
   // Attributes here.
   
public:
   double intRate;
   SavingsAccount();
   ~SavingsAccount();
   void deposit(double amount);
   void withdraw(double amount);
};

#endif /* SavingsAccount_hpp */
