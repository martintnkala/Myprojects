//
//  person.hpp
//  familyInformationTracker
//
//  Created by Martin Nkala on 10/20/22.
//

#ifndef person_hpp
#define person_hpp
#include "marriage.hpp"
#include <stdio.h>
#include<string>
using namespace std;


class Person{
    public:
    // Person attributes
     string firstname;
     string middlename;
     string lastname;
     int id;
    //DOB attributes
    int month;
    int day;
    int year;
    bool married = false;
    shared_ptr<Marriage> marriages = make_shared<Marriage>();
    
    Person();

    // methods
    /*
    The double error pointing to the left is called an insertion operator
    */
    void  set_name(string fname);
    
    void  set_middlename(string lname);
  
    void  set_lastname(string lname);
    
    void set_id (int id);
    
    void set_month(int dobmonth);
    
    void set_day(int dobday);
    
    void set_year(int dobyear);
    
    

    string get_name();
    
    string get_middlename();
   
    string get_lastname();
    
    int get_id();
    
    int get_month();
    
    int get_day();
    
    int get_year();
    
    void display_info();
    void add_marriage();
};
#endif /* person_hpp */
