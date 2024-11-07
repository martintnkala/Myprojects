import react from 'react';

function myButton() {

    return (
        <button>
            My Button
            </button>
    )
}

export  default function myApp(){
    return (
        <button onClick={myButton}>
            <h4>Welcome to React + Typescript.....</h4>
        </button>
    )
};