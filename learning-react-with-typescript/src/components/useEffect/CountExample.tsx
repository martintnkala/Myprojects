import React, {useState, useEffect} from "react";


export const CountExample = () =>{

    const [count, setCount] = useState(0);

    useEffect(() => {
        // The code we want to run
        console.log("The count is: ", count);

        // Optional return function
        return () =>{
            console.log("I am being cleaned up!");
        }
    }, [count]); // Dependency Array


    return(
        <div className="test">
            <h1>Count: {count}</h1>
            <button onClick={()=> setCount(count - 1)}> 
                Decrement
            </button>
            <button onClick={()=> setCount(count + 1)}> 
                Increment
            </button>

        </div>
    )
}