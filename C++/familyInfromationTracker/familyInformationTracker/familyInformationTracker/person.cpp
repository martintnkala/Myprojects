//
//  person.cpp
//  familyInformationTracker
//
//  Created by Martin Nkala on 10/20/22.
//

#include "person.hpp"
#include<string>
#include<iostream>
using namespace std;
Person::Person() : firstname(""), middlename(""), lastname(""), day(0), month(0), year(0), marriages(nullptr){
    
}


void  Person::set_name(string fname){
        firstname = fname;
    };
void  Person::set_middlename(string mname){
    middlename = mname;
};
void  Person::set_lastname(string lname){
    lastname = lname;
};

void Person:: set_id(int pid){
    id = pid;
};
void Person::set_month(int dobmonth){
    month = dobmonth;
};

void Person::set_day(int dobday){
    day = dobday;
};

void Person:: set_year(int dobyear){
    year = dobyear;
};

string Person::get_name(){
    return firstname;
};
string Person::get_middlename(){
    return middlename;
};
string Person::get_lastname(){
    return lastname;
};


int Person::get_id(){
    return id;
}

int Person::get_month(){
    return month;
};

int Person::get_day(){
    return day;
};

int Person::get_year(){
    return year;
};

void Person::display_info(){
    cout << " Person ID: " << id << " First Name: " << firstname << " Middle: " << middlename << " Last Name: " << lastname
         << " Date of Birth: "<< month<< "/"
        << day<< "/" << year;
    if (married) {
        marriages->display_marriage_info();
    }
    
}
void Person::add_marriage(){
    marriages = make_shared<Marriage>();
    marriages -> initialize();
    married = true;
}
