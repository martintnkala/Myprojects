//
//  dob.hpp
//  familyInformationTracker
//
//  Created by Martin Nkala on 10/20/22.
//

#ifndef dob_hpp
#define dob_hpp

#include <stdio.h>
#include <string>
using namespace std;

class Dateofbirth{
    private:

    //attributes
    string month;
    int day;
    int year;

    public:
    
    void set_month(string month);
    
    void set_day(int day);
    
    void set_year(int year);
    
    string get_month();
    
    int get_day();
    
    int get_year();

};

#endif /* dob_hpp */
