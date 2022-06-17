#include <iostream>
#include <vector>
#include <string>
#ifndef _person_H_
#define _person_H_

using namespace std;


class Person{
    public:
    // attributes
     string firstName;
     string middleName;
     string lastName;
     int age;



    // methods
    /*
    The double error pointing to the left is called an insertion operator
    */
    void  set_name(string fname){
        firstName = fname;
    };
    void  set_middlename(string lname){
        middleName = lname;
    };
    void  set_lastname(string lname){
        lastName = lname;
    };
    void  set_age(string age){
        age = age;
    };

    string get_name(){
        return firstName;
    };
    string get_middleName(){
        return middleName;
    };
    string get_lastname(){
        return lastName;
    };

   
};
#endif