console.log("b");
exports.done= false
var b = require("./zadanie3c")
console.log('bc');
if (b.done) {
    console.log("c");
}
exports.done=true
console.log("bd");