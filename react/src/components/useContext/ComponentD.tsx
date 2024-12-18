import {UserContext} from "./ComponentA.tsx";
import {useContext} from "react";

export default function ComponentD(){

    const user = useContext(UserContext);

    return (
        <div className={"box"}>
            <h1>Component D</h1>
            <h2>{`Bye, ${user}`}</h2>
        </div>
    )
}