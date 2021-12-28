var http = require('http')
var express = require('express')
var session = require('express-session')

var app = express();

app.set('view engine', 'ejs')
app.set('views', './views')

app.use(session({
    resave: true, saveUninitialized: true, secret: 'kot'
}))

app.use("/", (req, res) => {
    var sesja;
    if (!req.session.sessionValue) { 
        sesja = new Date().toString();
        req.session.sessionValue = sesja;
    } else {
        sesja = req.session.sessionValue;
    }

    res.render("zadanie3", { val: sesja });
});


http.createServer(app).listen(3000);
console.log('started')