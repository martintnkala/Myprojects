#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Dateofbirth{
    private:

    //attributes
    string month;
    int day;
    int year;

    public:
    
    void get_dateOfBirth(string month, int day, int year){
        cout << month << day << " " << year << endl;
    };

};

int main(){
    Dateofbirth *dob1 = new Dateofbirth;
    

    dob1 -> get_dateOfBirth ("Nov ", 12, 1990);
    
}