//
//  main.cpp
//  BankAccount1
//
//  Created by Martin Nkala on 9/24/22.
//

#include <iostream>
#include <stdio.h>
#include "Account.hpp"
#include "Contact.hpp"
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
void display_account(vector<Account*>& account_list);
int main(int argc, const char * argv[]) {
    //    creating an instance of the Account class.
    //       Account *account = new Account;
    // Prompting for user input.
    string name;
    int id = 0;
    int searchById = 0;
    float bal = 0.0;
    float deposit = 0.0f;
    float withdraw = 0.0;
    float increment_by;
    string address;
    string city;
    string state;
    string zip_code;
    string phone_number;
    //       list<Account> accounts;
    cout << "\n";
    
    vector<Account*> accounts;
    shared_ptr<Contact> contact_info {new Contact()};
    int choice = -1;
    
    while(choice != 0){
        cout << endl;
        cout << " --------------- Account Menu ----------------------\n";
        // Options to choice from the menu
        // Creating a Menu
        cout << " 0. Quit Program: " << endl
        << " 1. Display Account Information: " << endl
        << " 2. Add Deposit to an account: " << endl
        << " 3. Withdraw amount from an account: " << endl
        << " 4. Add new account: " << endl
        << " 5. Find account by ID: " << endl
        << " 6. Remove account: " << endl
        << " 7. Show total balance for all accounts: " << endl
        << " 8. Add a dividend to all accounts: " << endl
        << " 9. Add contact information to an account: \n\n" << endl;
;
        cout << "Select from the menu: ";
        cin >> choice;
    
        
                    cout << " Your choice: " << choice << "\n";
//            I am using the for_each to tranverse my account vector
        if (choice == 1) {
            for_each(accounts.begin(), accounts.end(),
                     [&contact_info](auto& account){
                cout << " Account ID: " << account->getidNumber() << " Name: " << account->getaccountName() <<
                " Balance: " << account->getbalance()
                << " Contact Information: " << " Address: " << contact_info -> get_street_address() <<
                " City: " << contact_info -> get_city() << " State: " << contact_info -> get_state() <<
                " Zip: " << contact_info -> get_zip_code() << " Phone: " << contact_info -> get_phone_number();
                }
            );
//            for (Account* account : accounts) {
//                    cout << " Account ID: " << account->getidNumber() << " Name: " << account->getaccountName() << " Balance: " << account->getbalance() << endl;
//            }
        }
            
        if (choice == 2){
            
            cout << "Enter the ID of the account to find: ";
            cin >> searchById;
            for_each(accounts.begin(), accounts.end(),
                     [searchById,&deposit](auto& account){
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
            );
        }
            
            if (choice == 3){
                cout << "Enter the ID of the account to find: ";
                cin >> searchById;
                
//                I am passing both searchById and withdraw by reference implicitly into my lambda function.
                for_each(accounts.begin(),accounts.end(),
                         [searchById,&withdraw](auto& account){
                    if(searchById == account ->getidNumber()){
                        cout << " Found Account: AccountID: " << account -> getidNumber()
                        << " Name: " << account ->getaccountName() << " Balance: " << account -> getbalance() << endl;
                        cout << " Withdrawal amount: ";
                        cin >> withdraw;
                        float balance = account -> getbalance();
                        balance -= withdraw;
                        account -> setbalance(balance);
                        }else{
                            cout << " Account not found. ";
                        }
                    }
                         );
                
            }
            
            if (choice == 4){
                cout << " Enter the name: ";
                cin >> name;
                cout << " Enter account Id: ";
                cin >> id;
                
                
                cout << " Enter the balance: ";
                cin >> bal;
                Account *newAccounts = new Account(id, name, bal);
                accounts.push_back(newAccounts);
            }
            
            if (choice == 5){
                cout << "Enter the ID of the account to find: ";
                cin >> searchById;
                
                for_each(accounts.begin(), accounts.end(),
                [searchById](auto& account){
                    if(searchById == account ->getidNumber()){
                        cout << " Found Account: AccountID: " << account -> getidNumber() << " Name: " << account ->getaccountName() << " Balance: " << account -> getbalance() << endl;
                    } else{
                        cout << " Account not found. " << endl;
                        }
                    }
                );
                
            }
            if (choice == 6){
               
                cout << "Enter account ID to remove: ";
                cin >> id;
                
                auto new_end = remove_if(accounts.begin(), accounts.end(),
                                         [id](Account* account){
                    return account->getidNumber() == id;
                    }
                );
                accounts.erase(new_end, accounts.end());
            }
        
        if (choice == 7){
            float total = accumulate(accounts.begin(), accounts.end(), 0.0f,
                [](auto accumulator, auto& account){
                return accumulator + account->getbalance();
                }
            );
            cout<< "Total amount: " << total << endl;
        }
        if (choice == 8){
            cout << " Enter the dividend as a percentage: ";
            cin >> increment_by;
            increment_by *= .01;
            
            transform(accounts.begin(), accounts.end(), accounts.begin(),
                          [&increment_by](auto& account){
                    float balance = account -> getbalance();
                     balance = balance + (balance* increment_by);
                    account -> setbalance(balance);
                    

                    return account;
                    }
                );
        }
        if (choice == 9){
            
//            cout << "Enter the ID of the account to find: ";
//            cin >> searchById;
//            for_each(accounts.begin(), accounts.end(),
//                     [searchById,&deposit, &address, &city, &state,
//                      &zip_code, &phone_number, &contact_info](auto& account){
//                if(searchById == account -> getidNumber()){
//                    cout << " Found Account: AccountID: " << account -> getidNumber() << " Name: " << account->getaccountName() << " Balance: " << account -> getbalance() << endl;
//                    cout << " Enter Address: ";
//                    cin >> address;
//                    
//                    cout << " Enter City: ";
//                    cin >> city;
//                    
//                    cout << " Enter State: ";
//                    cin >> state;
//                    
//                    cout << " Enter Zip Code: ";
//                    cin >> zip_code;
//                   
//                    cout << " Enter Phone Number: ";
//                    cin >> phone_number;
//                    
//                    contact_info -> set_city(city);
//                    contact_info -> set_street_address(address);
//                    contact_info -> set_state(state);
//                    contact_info -> set_zip_code(zip_code);
//                    contact_info -> set_phone_number(phone_number);
//                    
//                    } else{
//                        cout << " Account not found. ";
//                    }
//                }
//            );
        }
        
}
    return 0;
        
}

