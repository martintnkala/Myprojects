//
//  Account.cpp
//  BankAccount1
//
//  Created by Martin Nkala on 9/24/22.
//

#include "Account.hpp"
#include <iostream>
#include <memory>

using namespace std;

Account::Account(int accountIdNumber,string account,float accountBalance) {
    idNumber = accountIdNumber;
    balance = accountBalance;
    this->account = account;
    account_info = nullptr;
}

void Account:: add_contact_info(){
    account_info = make_shared<Contact>();
    account_info->initialize();
    
    
    //void Contact::initialize(){
    //    cout << " Enter Address: ";
    //    getline(cin, streetAddress);
    //
    //    cout << " Enter City: ";
    //    getline(cin, city);
    //
    //    cout << " Enter State: ";
    //    getline(cin, state);
    //
    //    cout << " Enter Zip Code: ";
    //    getline(cin, zipCode);
    //
    //    cout << " Enter Phone Number: ";
    //    getline(cin, phoneNumber);
    //};
    //void Account::setIdNumber(int accountIdNumber){
    //    idNumber = accountIdNumber;
    //}
    //
    //void Account::setAccountname(string accountName){
    //    account = accountName;
    //}
    
    void Account::setbalance(float accountBalance){
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
    }
    
}
