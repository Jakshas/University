function forEach( a, f ) {
    for (let i = 0; i < a.length; i++) {
        f(a[i]);
    }
}
function map( a, f ) {
    for (let i = 0; i < a.length; i++) {
        a[i]=f(a[i]);
    }
}
function filter( a, f ) {
    let p = []
    for (let i = 0; i < a.length; i++) {
        if(f(a[i])){
            p.push(a[i])
        }
    }
    a=p
}
var a = [1,2,3,4];
forEach( a, _ => { console.log( _ ); } );
// [1,2,3,4]
filter( a, _ => _ < 3 );
// [1,2]
map( a, _ => _ * 2 );
// [2,4,6,8]