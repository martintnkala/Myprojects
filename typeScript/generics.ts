type Role = 'admin' | 'user' | 'editor';

let role: Role;

function performAction(action: string, role: Role){
    //....
}

let roles: Role[];
roles = ['admin', 'user', 'editor'];

// Creating a generic type.

type DataStorage<T> = {
    storage: T[];
    add: (data: T) => void; 
};

const textStorage: DataStorage<string> = {
    storage: [],
    add(data) {}
}