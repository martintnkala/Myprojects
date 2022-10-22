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
#include <list>
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
    Account();
    
    Account(int accountIdNumber,string account,float accountBalance);
//    void setIdNumber(;
//    void setAccountname();
    void setbalance (float newBalance);
    void setdeposit(float makeDeposit);
    void setwithdraw(float makeWithdrawal);
//    void addAccount(list<Account>& accountList(int id, string account, float balance));
    
    int getidNumber();
    
    string getaccountName();
    
    float getbalance();
    
    float getdeposit();
    
    float getwithdrawal();
};

#endif /* Account_hpp */
