//
//  main.cpp
//  familyInformationTracker
//
//  Created by Martin Nkala on 10/20/22.
//

#include <iostream>
#include "person.hpp"
#include "dob.hpp"
#include "marriage.hpp"
#include<vector>
#include <algorithm>
#include <numeric>
#include <memory>

using namespace std;

int main(int argc, const char * argv[]) {
    int id = 0;
//    person information and Marriage Variables.
    string fname, mname, lname, city, state, country;
   

//    Date of birth variables
    int month;
    int day, year, searchById = 0;
    vector< Person*> persons;
//    vector< shared_ptr< Person*>> persons = make_shared<Person>();
//    shared_ptr<Marriage> marriages = make_shared<Marriage>();
    
    
    cout << "\n";
    
    int choice = -1;
    
    while(choice != 0){
        cout << endl;
        cout << " --------------- Menu ----------------------\n";
        // Options to choice from the menu
        // Creating a Menu
        cout << " 0. Quit Program: "
        << endl << " 1. Display Person's Information: "
        << endl << " 2. Add Person: "
        << endl << " 3. Add Marriage Information:\n\n ";
       
        
        cout << "Select from the menu: ";
        cin >> choice;
        cout << " Your choice: " << choice << "\n";
        
        if (choice == 1){
            for_each(persons.begin(), persons.end(), [](auto& personal){
                personal->display_info();
            }
            );
        } else if (choice == 2){
            cout << " Enter Person ID: ";
            cin >> id;
            
            cout << " Enter First Name: ";
            cin >> fname;
            
            cout << " Enter Middle Name (Option): ";
            cin >> mname;
            
            cout << " Enter Last Name: ";
            cin >> lname;
            
            cout << " Enter month of birth: ";
            cin >> month;
            
            cout << " Enter day of birth: ";
            cin >> day;
            
            cout << " Enter year of birth: ";
            cin >> year;
            
            
//            Creating Person class and date of birth instances.
           Person *addperson = new Person;
//           Marriage *marriage = new Marriage;
           addperson ->set_id(id);
           addperson ->set_name(fname);
           addperson ->set_middlename(mname);
           addperson -> set_lastname(lname);
           addperson -> set_month(month);
           addperson -> set_day(day);
           addperson -> set_year(year);
            
//            I am adding person's information into my vector or list.
           persons.push_back(addperson);
          
        } else if (choice == 3){
//            I am creating an instance of the Marriage class.
            
            cout << "Enter the ID of the account to find: ";
            cin >> searchById;
            for_each(persons.begin(), persons.end(),
                     [&searchById, &city, &state, &country, &persons](auto& Person){
                if(searchById == Person -> get_id()){
                    Person -> add_marriage();
                    }
                
                else {
                        cout << " MemberID not found. ";
                    }
                }
            );
          

        }
    }
    
    return 0;
}
