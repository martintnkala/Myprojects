//
//  main.cpp
//  BankAccount1
//
//  Created by Martin Nkala on 9/24/22.
//

#include <iostream>
#include <stdio.h>
#include "account.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    //    creating an instance of the Account class.
       Account *account = new Account;
       // Prompting for user input.
       string name;
       int id;
       float bal;
       float deposit;
       float withdraw;
       cout << "Enter the name: ";
       cin >> name;
       account -> setAccountname(name);
       
       cout << "Enter account Id: ";
       cin >> id;
       account -> setIdNumber(id);
           
       
       cout << "Enter the balance: ";
       cin >> bal;
       account -> setbalance(bal);
       cout << "\n";
           
       // Creating a Menu
       
       cout << "Account Menu\n"<< endl;

       // Options to choice from the menu

       cout << " 0. Quit Program" << endl << " 1. Display Account Information" << endl << " 2. Add Deposit" << endl << " 3. Withdraw amount\n\n" ;
       int choice = -1;



       while(choice != 0){
           cout << "Select from the menu: ";
           cin >> choice;
           if (choice == 1) {
               cout << " Your choice: " << choice;
               cout << " Account ID: " << account -> getidNumber() << " Name: " << account -> getaccountName() << " Balance: " << bal << endl;
           }
   
           if (choice == 2){
               cout << " Your choice: " << choice << "\n";
               cout << " Deposit amount: ";
               cin >> deposit;
               account -> setdeposit(deposit);
               bal = account -> getbalance();
               bal = bal + account -> getdeposit();
           }
   
           if (choice == 3){
               cout << " Withdrawal amount: ";
               cin >> withdraw;
               account -> setwithdraw(withdraw);
               bal = bal - account -> getwithdrawal();
           }

       }
       return 0;
}
