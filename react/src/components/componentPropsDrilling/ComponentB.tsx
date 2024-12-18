import ComponentC from "./ComponentC.tsx";

export default function ComponentB(props:{user:string}) {
    return (
        <div className={"box"}>
            <h1>Component B</h1>
            <ComponentC  user={props.user} />
        </div>
    )
}