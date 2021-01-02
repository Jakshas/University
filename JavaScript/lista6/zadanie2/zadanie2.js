const http = require('http')
const express = require('express')

var app = express()

app.set('views', __dirname + '/views')
app.set('view engine', 'ejs')

app.get('/', (req, res) => {
    res.render('zadanie2')
})


http.createServer(app).listen(2000)
console.log('started')