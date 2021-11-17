function fib() {
    let jeden=0;
    let dwa=1;
    let pom;
    return {
        next : function() { 
            pom=dwa,
            dwa=dwa+jeden,
            jeden=pom
            return {
                value: dwa,
                done: false 
            }
        }
    }
}

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

    var _it = fib();
    for ( var _result; _result = _it.next(), !_result.done; ) {
        console.log( _result.value );
        if(_result.value>1000)break;
    }

    for ( var i of fib() ) {
        console.log( i );
    }