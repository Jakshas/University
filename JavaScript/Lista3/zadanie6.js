
function createGenerator(i) {
    return () => {  
    var _state = 0;
    return {
        next : function() {
            return {
                value : _state,
                done : _state++ >= i
            }
        }
    }
}}

function foo1Generator(j){
    return function*() { 
        for(let i = 0; i < j; i++)
            yield 2 ** i;
    }
}
let i=11
var foo1 = {
    [Symbol.iterator] : createGenerator(5)
};

var foo2 = {
    [Symbol.iterator] : createGenerator(10)
};
for ( var f of foo1 )
console.log(f);
i=20
for ( var f of foo2 )
console.log(f);