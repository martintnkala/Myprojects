import ComponentD from "./ComponentD.tsx";

export default function ComponentC(props: { user: string; }){
    return (
        <div className={"box"}>
            <h1>Component C</h1>
            <ComponentD user={props.user} />

        </div>
    )
}