//
//  Account.hpp
//  BankAccount1
//
//  Created by Martin Nkala on 9/24/22.
//

#ifndef Account_hpp
#define Account_hpp
#include <stdio.h>
#include <string>
using namespace std;

class Account{
    // Declaring variables.
private:
    int idNumber;
    string account;
    float balance;
    float deposit;
    float withdraw;
    
public:
    void setIdNumber(int accountIdNumber);
    
    void setAccountname(string account);
    void setbalance (float accountBalance);
    void setdeposit(float makeDeposit);
    void setwithdraw(float makeWithdrawal);
    
    int getidNumber();
    
    string getaccountName();
    
    float getbalance();
    
    float getdeposit();
    
    float getwithdrawal();
};

#endif /* Account_hpp */
