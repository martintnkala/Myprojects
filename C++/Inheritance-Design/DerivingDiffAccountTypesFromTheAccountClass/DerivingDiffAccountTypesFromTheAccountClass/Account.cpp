#include "Account.hpp"
#include<iostream>

// initilazing balance and accountName using the initializer list.
Account::Account(): balance{0.0}, accountName{"Account name"}
{
   
}

Account::~Account()
{
   
}

void Account::deposit(double amount)
{
   std::cout << "Account deposit with $" << amount << std::endl;
}

void Account::withdraw(double amount)
{
   std::cout << "Account withdrawal with $" << amount << std::endl;
}
