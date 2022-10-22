//
//  Account.cpp
//  BankAccount1
//
//  Created by Martin Nkala on 9/24/22.
//

#include "Account.hpp"
#include <iostream>

using namespace std;

Account::Account(int accountIdNumber,string account,float accountBalance) {
    idNumber = accountIdNumber;
    balance = accountBalance;
    this->account = account;
    
}
//void Account::setIdNumber(int accountIdNumber){
//    idNumber = accountIdNumber;
//}
//
//void Account::setAccountname(string accountName){
//    account = accountName;
//}
//
void Account::setbalance (float accountBalance){
    balance = accountBalance;
}

void Account::setdeposit(float makeDeposit){
    deposit =  makeDeposit;
}
void Account::setwithdraw(float makeWithdrawal){
    withdraw = makeWithdrawal;
}
int Account:: getidNumber(){
    return idNumber;
}

string Account:: getaccountName(){
    return account;
}

float Account:: getbalance(){
    return balance;
}

float Account:: getdeposit(){
    return deposit;
}

float Account:: getwithdrawal(){
    return withdraw;
};


