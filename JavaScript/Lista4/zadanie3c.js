console.log("c");
exports.done= false
var b = require("./zadanie3b")
console.log('cb');
if (b.done) {
    console.log("b");
}
exports.done=true
console.log("cd");