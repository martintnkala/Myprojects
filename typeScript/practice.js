// Creating a user Object with explicit
// var primitive datatypes
var user;
user = {
    name: 'Max',
    age: 24,
    isAdmin: true,
    id: 'qbc1'
};
// Array type
var hobbies;
hobbies = ['Sports', 'Cooking', 'Reading'];
for (var hobby in hobbies) {
    console.log(hobbies[hobby] + '');
}
