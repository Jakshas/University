var http = require('http')
var fs= require('fs')


http.createServer((req,res) =>{
    var plik =fs.readFileSync('kot.jpg')
    res.setHeader('Content-type','image/jpeg')
    res.setHeader('Content-Disposition','attachment; name=kot; kot.jpg')
    res.end(plik)
}).listen(3000)

console.log("started")