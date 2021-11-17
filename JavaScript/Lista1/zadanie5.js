function iteracyjnie(n){
    if(n==1||n==2){
        return 1;
    }
    var fb1=1,fb2=1,pom,ile=2;
    while(ile!=n){
        pom=fb1+fb2;
        fb1=fb2;
        fb2=pom;
        ile++;
    }
    return fb2;
}

function rekurencyjnie(n){
if(n==1||n==2){
    return 1;
}
return rekurencyjnie(n-1)+rekurencyjnie(n-2);
}
var n=44;
console.time();
console.log(rekurencyjnie(n));
console.timeEnd();
console.time();
console.log(iteracyjnie(n));
console.timeEnd();

