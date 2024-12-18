import ComponentB from "./ComponentB.tsx";
import {UserContext} from "./UserContext.tsx";
import {useState,} from "react";

export default function ComponentA() {
    const [user] = useState<string>("Martin");
    return (
        <div className={"box"}>
            <h1>Component A</h1>
            <h2>{`Hello ${user}`}</h2>
            <UserContext.Provider value={user}>
                <ComponentB/>
            </UserContext.Provider>
        </div>
    )
}