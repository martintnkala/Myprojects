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
    contact_info = nullptr;
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

void Account::add_contact_info(){
    contact_info = make_shared<Contact>();
    contact_info->initialize();
    has_contact = true;
}

void Account::display_info(){
    if(has_contact){
        cout << " + Contact Information: Address: " << contact_info -> get_street_address() <<
        " City: " << contact_info->get_city() << " State: " << contact_info->get_state() << " Zip: "
        << contact_info->get_zip_code() << " Phone: " << contact_info->get_phone_number() << endl;
    }
}

