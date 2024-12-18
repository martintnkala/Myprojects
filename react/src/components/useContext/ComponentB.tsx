import ComponentC from "./ComponentC.tsx";
import {useContext} from "react";
import {UserContext} from "./ComponentA.tsx";

export default function ComponentB() {
    const user = useContext(UserContext);
    return (
        <div className={"box"}>
            <h1>Component B</h1>
            <h2>{`Hello second, ${user}`}</h2>
            <ComponentC/>

        </div>
    )
}