//
//  Contact.cpp
//  BankAccount1
//
//  Created by Martin Nkala on 10/11/22.
//

#include "Contact.hpp"
#include <iostream>
#include <stdio.h>
#include <iostream>
using namespace std;



string Contact:: get_street_address(){
    return streetAddress;
};
string Contact::get_city(){
    return city;
};
string Contact::get_state(){
    return state;
};
string Contact::get_zip_code(){
    return zipCode;
};
string Contact::get_phone_number(){
    return phoneNumber;
};
//void Contact:: add_contact_info(){
//    contact_info = make_shared<Account>();
//
void Contact::initialize(){
    cout << " Enter Address: ";
    getline(cin, streetAddress);

    cout << " Enter City: ";
    getline(cin, city);

    cout << " Enter State: ";
    getline(cin, state);

    cout << " Enter Zip Code: ";
    getline(cin, zipCode);

    cout << " Enter Phone Number: ";
    getline(cin, phoneNumber);
};

void display_contact_info(){
        
    }

//}
//void Contact::set_street_address(string new_street_address){
//    streetAddress = new_street_address;
//};
//
//void Contact::set_city( string new_city){
//    city = new_city;
//};
//
//void Contact::set_state(string new_state){
//    state = new_state;
//}
//
//void Contact::set_zip_code(string new_zip_code){
//    zipCode = new_zip_code;
//};
//
//void Contact::set_phone_number(string new_phone_number){
//    phoneNumber = new_phone_number;
//};
//
//string Contact:: get_street_address(){
//    return streetAddress;
//};
//
//string Contact:: get_city(){
//    return city;
//};
//
//string Contact::get_state(){
//    return state;
//}
//string Contact::get_zip_code(){
//    return zipCode;
//};
//
//string Contact::get_phone_number(){
//    return phoneNumber;
