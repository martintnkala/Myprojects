
#include "marriage.h"
#include "person.h"


using namespace std;

 /*
    * I created pointers using the *objectname and then instantiated it using the NEW keyword.
    * Note that the  in order to get to the player object I need to de-reference the pointer. To de-reference I can use (*playerObjectname in this case marriage and person). Now it becomes any Object 
    * or I can de-reference using the arrow operator like so (PlayerObjectname(marriage or person) followed by the arrow as shown below.)
    */
int main(){
        Marriage *marriage = new Marriage;
        string name;
        cout << "Enter city name: ";
        cin >> name;
        marriage ->set_city(name);
        marriage ->set_state("Masholand Central ");
        marriage->set_country("Zimbabwe ");


        Person *person = new Person;

        person ->set_name("Seth");
        person ->set_middlename("Nyasha");
        person -> set_lastname("Thompson"); 


        cout << person -> get_name()<< " " << person->get_middleName()<< " " << person -> get_lastname() << " was married in ";
        cout << marriage->get_city()<<","<<marriage->get_state()<<","<<marriage->get_country() << endl;
    }

