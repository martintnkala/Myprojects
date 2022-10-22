//
//  Contact.hpp
//  BankAccount1
//
//  Created by Martin Nkala on 10/11/22.
//

#ifndef Contact_hpp
#define Contact_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class Contact{
//  declaring data members
    
private:
    string streetAddress;
    string  city;
    string state;
    string zipCode;
    string phoneNumber;
    
public:
//    setting set methods.
    void set_street_address(string new_street_address);
    void set_city( string new_city);
    void set_zip_code(string new_zip_code);
    void set_phone_number(string new_phone_number);
    void initialize();
//    setting get methods.
    string get_street_address();
    string get_city();
    string get_state();
    string get_zip_code();
    string get_phone_number();
    
};


#endif /* Contact_hpp */
