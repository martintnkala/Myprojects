//
//  Contact.hpp
//  BankAccount1
//
//  Created by Martin Nkala on 10/11/22.
//

#ifndef Contact_hpp
#define Contact_hpp
//#include "Account.hpp"
#include <stdio.h>
#include <iostream>
#include<memory>
using namespace std;

class Contact{
//  declaring data members
    
private:
    string streetAddress;
    string  city;
    string state;
    string zipCode;
    string phoneNumber;
    //    This pointer should point to the instance of the Account class.
    
public:
    Contact();
    
    Contact(string new_street_address, string new_city,string new_state, string new_zip_code, string new_phone_number);
    
//    setting get methods.
    string get_street_address();
    string get_city();
    string get_state();
    string get_zip_code();
    string get_phone_number();
    

    
//    display contact information
    void display_contact_info();
    
 // Asking for user input
    void initialize();
};


#endif /* Contact_hpp */
