const http = require('http')
const express = require('express')
const multer  = require('multer')

var app = express()

app.set('views', __dirname + '/views')
app.set('view engine', 'ejs')

app.get('/', (req, res) => {
    res.render('zadanie1')
})

var storage = multer.diskStorage({
    destination: function (req, file, cb) {
      cb(null, 'wyslane')
    }
  })

var upload = multer({ storage: storage })

app.post('/wysylane', upload.single('wyslane'), (req, res, next) => {
    const file = req.file
    if (!file) {
      console.log("Brak pliku")
    }
    res.send(file)
})

http.createServer(app).listen(1000);
console.log("started");

