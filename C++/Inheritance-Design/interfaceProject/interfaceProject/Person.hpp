//
//  Person.hpp
//  interfaceProject
//
//  Created by Martin Nkala on 4/20/23.
//

#ifndef Person_hpp
#define Person_hpp
#include<string>

class Person
{
public:
   // This method can be overidden by the any subclass that inherits the Person class.
   virtual void getFullname(std::string firstName,
                            std::string middleName,
                            std::string lastName);
   
   virtual void getContactInfor(std::string emailAddress,
                                int cellNumber);
};

#endif /* Person_hpp */
