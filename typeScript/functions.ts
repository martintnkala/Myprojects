function add (a: number, b: number){
    const result = a + b;
    return result;
}
// Alias
type AddFunc = (a: number, b: number) => number;
// function that take another as a parameter and matches the add function signature
function calculate(a : number, b: number, calcFunc: AddFunc){
  return calcFunc(a, b);
}

console.log(calculate(10, 10, add));