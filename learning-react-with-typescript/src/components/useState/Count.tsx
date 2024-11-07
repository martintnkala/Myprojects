import React, {useState} from "react";
// import './Count.css';


export const Count = () => {

    const [count, setCount] = useState(0);

    return (
        <div>
            <p>Current count {count}</p>
            <button onClick={() => setCount(count + 1)}> Increment</button>
        </div>
    );
}