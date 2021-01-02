function *fib() {
    let jeden=0;
    let dwa=1;
    let pom;
    while(1>0){
        pom=dwa
        dwa=dwa+jeden
        jeden=pom
        yield dwa
    }
}
function* take(it, top) {
    for( var i=0; i<top; i++ ) {
        yield it.next().value;
    }
}
// zwróć dokładnie 10 wartości z potencjalnie
// "nieskończonego" iteratora/generatora
for (let num of take( fib(), 10 ) ) {
    console.log(num);
}