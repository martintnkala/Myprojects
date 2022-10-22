//
//  Contact.hpp
//  tenantAndCarDb
//
//  Created by Martin Nkala on 10/20/22.
//

#ifndef Contact_hpp
#define Contact_hpp

#include <stdio.h>
#include <string>
using namespace std;

class contact{
private:
    string apartment_number;
    int phone_number;
    string email_address;
    
    void set_apartment_number(string apartment_number);
    void set_phone_number(int phone_number);
    void set_email_address(string email_address);
    
    
    string get_apartment_number();
    int get_phone_number();
    string get_email_address();
};

#endif /* Contact_hpp */
