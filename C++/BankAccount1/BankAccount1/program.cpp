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

void addAccount(list<Account>& accountList);
void displayAccounts(list<Account>& accountList);
list<Account>:: iterator findById(list<Account>& accountList, int id);


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
    
    
    
    // Creating a Menu
    
    
    cout << "Account Menu\n"<< endl;
    
    // Options to choice from the menu
    
    cout << " 0. Quit Program: " << endl << " 1. Display Account Information: " << endl << " 2. Add Deposit: " << endl << " 3. Withdraw amount: " << endl << " 4. Add new account: " << endl << " 5. Find account by ID:\n\n ";
    
    vector<Account*> accounts;
    vector<float> balances;
    
   
    
    
    
    
    int choice = -1;
    
    while(choice != 0){
        cout << "Select from the menu: ";
        cin >> choice;

        
        //Case 1
        //Loop through all accounts and
            //print name, id and amount
        
        //Case 2
            //loop through accounts until I find the account
                // add the money
        
        // Case 3
            //same as case #2
        
        
        //Case 4
            //Add an account with name, id, and amount
                // prompt user if he wants to add more account.
                    // Add account(s) into a list.
            
        
    
        
            
            cout << " Your choice: " << choice << "\n";
            
        if (choice == 1) {
            
            for (Account* account : accounts) {
                cout << " Account ID: " << account->getidNumber() << " Name: " << account->getaccountName() << " Balance: " << account->getbalance() << endl;
            }
        }
            
            if (choice == 2){
                
                cout << "Enter the ID of the account to find: ";
                cin >> searchById;
                if(searchById <= accounts.size()){
                    cout << " Found Account: AccountID: " << searchById << " Name: " << accounts[searchById] << " Balance: " << balances[searchById] << endl;
                    cout << " Deposit amount: ";
                    cin >> deposit;
                    balances[searchById] += deposit;
                    //               account -> setdeposit(deposit);
                    //               bal = account -> getbalance();
                    //               bal = bal + account -> getdeposit();
                }
                else{
                    cout << " Account not found. ";
                }
            }
            
            if (choice == 3){
                cout << "Enter the ID of the account to find: ";
                cin >> searchById;
                if(searchById <= accounts.size()){
                    cout << " Found Account: AccountID: " << searchById << " Name: " << accounts[searchById] << " Balance: " << balances[searchById] << endl;
                    cout << " Withdrawal amount: ";
                    cin >> withdraw;
                    balances[searchById] -= withdraw;
                }
                else{
                    cout << " Account not found. ";
                }
            }
            
            if (choice == 4){
                cout << " Enter the name: ";
                cin >> name;
                //               account -> setAccountname(name);
                
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
                if(searchById <= accounts.size()){
                    cout << " Found Account: AccountID: " << searchById << " Name: " << accounts[searchById] << " Balance: " << balances[searchById] << endl;
                }
                else{
                    cout << " Account not found. " << endl;
                }
            }
        }
    return 0;
        
}

