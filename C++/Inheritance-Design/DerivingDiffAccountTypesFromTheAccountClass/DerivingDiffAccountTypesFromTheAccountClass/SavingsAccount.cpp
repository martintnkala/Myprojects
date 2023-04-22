#include "SavingsAccount.hpp"
#include<iostream>

//initialize the Interest Rate using the initiliazer list.
SavingsAccount::SavingsAccount(): intRate(3.0)
{
   
}

SavingsAccount:: ~SavingsAccount()
{
   
}

void SavingsAccount::deposit(double amount)
{
   std::cout << "Savings account deposit called with $" << amount << std::endl;
}

void SavingsAccount::withdraw(double amount)
{
   std::cout << "Savings account withdraw called with $" << amount << std::endl;
}
