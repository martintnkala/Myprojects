// Creating a user Object with explicit
// var primitive datatypes

// Alias type. 
// Allows the user Object to be reusable
type User = {
    name: string;
    age: number;
    isAdmin: boolean;
    id: string | number;
};

let user: User;

user = {
    name : 'Max',
    age: 24,
    isAdmin : true,
    id: 'qbc1'
}


// Array type

let hobbies: string[];

hobbies = ['Sports', 'Cooking', 'Reading'];

for (var hobby in hobbies)
{
    console.log(hobbies[hobby] + '');
}
