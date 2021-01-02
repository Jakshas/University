const http = require('http')
const express = require('express')
const url = require('url')
app = express();
//jesli chcemy dostać sie do strony admina przez url zablokuje dostep do podstrony
app.use('/:id', (req, res) => {
    if(req.params.id.includes('admin')){
        res.end("Error")
    } else{
        res.end(req.params.id);
    }
})

http.createServer(app).listen(3000)
console.log('started')