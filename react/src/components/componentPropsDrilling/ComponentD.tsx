export default function ComponentD(props: { user: string; }){
    return (
        <div className={"box"}>
            <h1>Component D</h1>
            <h2>{`Bye ${props.user}`}</h2>
        </div>
    )
}