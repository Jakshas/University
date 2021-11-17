var http = require('http');
var express = require('express');

var app = express();

app.use(express.urlencoded({extended:true}));

app.set('view engine', 'ejs');
app.set('views', __dirname + '/views');

app.get('/', (req, res) => {
    res.render('index', { przm: '', imie: '', nazw: '', punkty: ''});
});

app.post('/', (req, res) => {
    let przm1 = req.body.przm;
    let imie1 = req.body.imie;
    let nazw1 = req.body.nazw;
    let pkt = req.body.punkty;

    let wiadomosc = "Błędne pola:";
    let formCorrect = true;
    if (przm1 === "") {
        wiadomosc += ' Nazwa przedmiotu';
        formCorrect = false;
    }
    if (imie1=== "") {
        wiadomosc += ' Imię';
        formCorrect = false;
    }
    if (nazw1=== "") {
        wiadomosc += ' Nazwisko';
        formCorrect = false;
    }

    let pkt1 = pkt.split(',');
    if (pkt1.length != 10) {
        wiadomosc += ' Deklarowane zadania';
        formCorrect = false;
    }

    if (formCorrect){
        pkt1 = pkt1.map((x) => {return x == '' ? 0 : x} );
        res.render('print', { przm: przm1, imie: imie1, nazw: nazw1, pkt: pkt1})
    } else {
        res.render('index', { przm: przm1, imie: imie1, nazw: nazw1, punkty: pkt, wiadomosc : wiadomosc})
    }
})

http.createServer(app).listen(4000);
console.log('started');