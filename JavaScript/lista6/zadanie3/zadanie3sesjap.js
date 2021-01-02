var http = require('http')
var express = require('express')
var session = require('express-session')
var FileStore = require('session-file-store')(session)

let app = express()

app.set('view engine', 'ejs')
app.set('views', './views')

app.use(session({
    store: new FileStore,
    secret: 'keyboard cat',
    resave: true,               
    saveUninitialized: true
  })
);

app.use('/', (req, res) => {
    if (req.session.views) {
        req.session.views++
    } else {
        req.session.views = 1
    }
    res.render("zadanie3", { val: req.session.views })
});

http.createServer(app).listen(3000)
console.log('started')