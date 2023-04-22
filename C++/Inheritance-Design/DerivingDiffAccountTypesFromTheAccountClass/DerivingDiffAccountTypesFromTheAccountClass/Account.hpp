#ifndef Account_hpp
#define Account_hpp
#include<string>

class Account
{
private:
   // Attributes
   
public:
   double balance;
   std::string accountName;
   // Default Constructor.
   Account();
   
   // Destructor
   ~Account();
   
   // Account Methods.
   void deposit(double amount);
   void withdraw(double amount);
};

#endif /* Account_hpp */
