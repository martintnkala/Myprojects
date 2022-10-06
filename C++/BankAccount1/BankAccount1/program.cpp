//
//  main.cpp
//  BankAccount1
//
//  Created by Martin Nkala on 9/24/22.
//

#include <iostream>
#include <stdio.h>
#include "Account.hpp"
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    //    creating an instance of the Account class.
    //       Account *account = new Account;
    // Prompting for user input.
    string name;
    int id = 0;
    int searchById = 0;
    float bal = 0.0;
    float deposit = 0.0;
    float withdraw = 0.0;
    //       list<Account> accounts;
    cout << "\n";
    
    vector<Account*> accounts;

    int choice = -1;
    
    while(choice != 0){
        cout << endl;
        cout << " --------------- Account Menu ----------------------\n";
        // Options to choice from the menu
        // Creating a Menu
        cout << " 0. Quit Program: " << endl << " 1. Display Account Information: " << endl << " 2. Add Deposit to an account: " << endl << " 3. Withdraw amount from an account: " << endl << " 4. Add new account: " << endl << " 5. Find account by ID:\n\n ";
        cout << "Select from the menu: ";
        cin >> choice;
    
        
                    cout << " Your choice: " << choice << "\n";
            
        if (choice == 1) {
            
            for (Account* account : accounts) {
                cout << " Account ID: " << account->getidNumber() << " Name: " << account->getaccountName() << " Balance: " << account->getbalance() << endl;
            }
        }
            
            if (choice == 2){
                
                cout << "Enter the ID of the account to find: ";
                cin >> searchById;
                for (Account* account : accounts) {
                    if(searchById == account -> getidNumber()){
                        cout << " Found Account: AccountID: " << account -> getidNumber() << " Name: " << account->getaccountName() << " Balance: " << account -> getbalance() << endl;
                        cout << " Deposit amount: ";
                        cin >> deposit;
                        float balance = account -> getbalance();
                        balance += deposit;
                        account -> setbalance(balance);
                        
                } else{
                    cout << " Account not found. ";
                }
                
                }
            }
            
            if (choice == 3){
                cout << "Enter the ID of the account to find: ";
                cin >> searchById;
                for (Account* account : accounts){
                    if(searchById == account ->getidNumber()){
                        cout << " Found Account: AccountID: " << account -> getidNumber()<< " Name: " << account ->getaccountName() << " Balance: " << account -> getbalance() << endl;
                        cout << " Withdrawal amount: ";
                        cin >> withdraw;
                        float balance = account -> getbalance();
                        balance -= withdraw;
                        account -> setbalance(balance);
                    }
                    else{
                        cout << " Account not found. ";
                    }
                }
                
            }
            
            if (choice == 4){
                cout << " Enter the name: ";
                cin >> name;
                cout << " Enter account Id: ";
                cin >> id;
                
                
                cout << " Enter the balance: ";
                cin >> bal;
                Account *account1 = new Account(id, name, bal);
                accounts.push_back(account1);
            }
            
            if (choice == 5){
                cout << "Enter the ID of the account to find: ";
                cin >> searchById;
                for (Account* account : accounts){
                    if(searchById == account ->getidNumber()){
                        cout << " Found Account: AccountID: " << account -> getidNumber() << " Name: " << account ->getaccountName() << " Balance: " << account -> getbalance() << endl;
                    } else{
                        cout << " Account not found. " << endl;
                    }
                }
                
            }
        }
    return 0;
        
}

