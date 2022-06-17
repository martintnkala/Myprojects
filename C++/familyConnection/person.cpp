#include "person.h"

    // methods
    /*
    The double arrow pointing to the left is called an insertion operator
    */
    void  Person::set_name(string fname){
        firstName = fname;
    };
    void  Person::set_middlename(string lname){
        middleName = lname;
    };
    void  Person::set_lastname(string lname){
        lastName = lname;
    };
    void  Person::set_age(string age){
        age = age;
    };

    string Person::get_name(){
        return firstName;
    };
    string Person::get_middleName(){
        return middleName;
    };
    string Person::get_lastname(){
        return lastName;
    };
