function sum() {
    let sum=0;
    for (let i = 0; i < arguments.length; i++) {
        sum = sum + arguments[i];
    }
    return sum;
}
sum(1,2,3);// 6
console.log(sum(1,2,3))
sum(1,2,3,4,5);// 15