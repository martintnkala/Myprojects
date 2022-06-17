#include <iostream>
#include <vector>
#include <string>

// This my header guards
#ifndef _marriage_H_
#define _marriage_H_
// File specifications goes in the .h
using namespace std;


class Marriage{

    private:

    string city;
    string state; 
    string country;


    public:
    void set_city(string marriagecity){
        city = marriagecity;


    }
    void set_state(string marriagestate){
        state= marriagestate;


    }
    void set_country(string countryofmarriage){
        country = countryofmarriage ;

    }
    string get_city(){
        return city;
    }
    string get_state(){
        return state;
    }
    string get_country(){
        return country;
    }

};
#endif
