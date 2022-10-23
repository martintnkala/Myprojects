//
//  marriage.hpp
//  familyInformationTracker
//
//  Created by Martin Nkala on 10/20/22.
//

#ifndef marriage_hpp
#define marriage_hpp
#include <algorithm>
#include <numeric>
#include <memory>
#include <iostream>
#include<locale>
#include<iomanip>
#include <vector>
#include <stdio.h>
#include<string>
using namespace std;

class Marriage{

    private:

    string city;
    string state;
    string country;


    public:
    
    Marriage() : city(""), state(""), country(""){};
    
//    Marriage(string city,string state, string country);
    void set_city(string marriagecity);
    void set_state(string marriagestate);
    void set_country(string countryofmarriage);
    
    string get_city();
    string get_state();
    string get_country();
    void display_marriage_info();
    void initialize();
};
#endif /* marriage_hpp */
