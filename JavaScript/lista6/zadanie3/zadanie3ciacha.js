var http = require('http')
var express = require('express')
const cookieParser = require('cookie-parser');

var app = express();

app.set('view engine', 'ejs')
app.set('views', './views')
app.use(cookieParser("kot"));
app.use(express.urlencoded({extended: true}));

app.use("/", (req, res) => {
    var ciacho;
    if (!req.signedCookies.cookie) {
        ciacho = new Date().toString()
        res.cookie('cookie', ciacho, { signed: true })
    } else { 
        ciacho = req.signedCookies.cookie;
    }
    res.render("zadanie3", { val: ciacho })
})


http.createServer(app).listen(3000);
console.log('started')