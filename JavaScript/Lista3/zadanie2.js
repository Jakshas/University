function rekurencyjnie(n){
    if(n==1||n==2){
        return 1;
    }
    return rekurencyjnie(n-1)+rekurencyjnie(n-2);
}

    function memoize(fn) 
    {
        var cache= {};
        return function(n) {
            if( n in cache) {
                return cache[n]
            } else{
                var result= fn(n);
                cache[n] = result;
                return result;
            }
        }
    }
    var n=10;
    var memo = memoize(rekurencyjnie)
    console.time();
    console.log(rekurencyjnie(n));
    console.timeEnd();
    console.time();
    console.log(memo(n));
    console.timeEnd();