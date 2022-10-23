//
//  marriage.cpp
//  familyInformationTracker
//
//  Created by Martin Nkala on 10/20/22.
//

#include "marriage.hpp"

using namespace std;

// You put your implementation in the .CPP file
    void Marriage::set_city(string marriagecity){
        city = marriagecity;
    }
    
void Marriage::set_state(string marriagestate){
    city = marriagestate;
}


    void Marriage::set_country(string countryofmarriage){
        country = countryofmarriage ;
    }

    string Marriage:: get_city(){
        return city;
    }

    string Marriage::get_state(){
        return state;
    }

    string Marriage::get_country(){
        return country;
    }
void Marriage::display_marriage_info(){
    cout << "Marriage Information: City: " << city << " State: " << state
    << " Country: " << country << endl;
}
void Marriage:: initialize(){
    //
    cout << "Enter city name: ";
    cin >> city;
 
    cout << "Enter state name: ";
    cin >> state;
 
    cout << "Enter country name: ";
    cin >> country;
}
