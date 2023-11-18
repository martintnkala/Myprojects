interface Person{
    name: string;
    surname: string;
    gender: string;
    age: number;
}

let person: Person = {
    name: 'Martin',
    surname: 'Nkala',
    gender: 'Male',
    age: 32
};

class PDetails implements Person{
    name: string;
    surname: string;
    gender: string;
    age: number;

}


function personalDetails(person: Person){
person.name;
person.surname;
person.gender;
person.age;
}

personalDetails(new PDetails());
