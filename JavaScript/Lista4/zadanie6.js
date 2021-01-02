var czytacz = require('readline').createInterface({
    input: require('fs').createReadStream('log.txt')
});

var ids = []
var count = []
czytacz.on('line', function (line) {
    let l = line.split(' ')
    if(ids.indexOf(l[1]) == -1) {
        ids.push(l[1])
        count.push(1)
    } else {
        count[ids.indexOf(l[1])]++;
    }
}).on('close', function() {
    for(let i = 0; i < ids.length; i++) {
        console.log(`id = ${ids[i]} count = ${count[i]}`)
    }
})