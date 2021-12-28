const http = require('http');
const express = require('express');

app = express();

function jakasfunkcja(dana1, dana2) {}; 
//przekazujac dane przez url mozna łatwo sie do nich dostac i przy nich majstrowac co jest nieporzadane i niebezpieczne
//mozna temu przeciwdziałać za pomoca csurfa który wysyła tokeny razem z formulazem i jelsi token z odpowiedzi sie zgadza to walidacja przechodzi
//inaczej zapytanie jest blokowane
app.use('/', (req, res) => {
    jakasfunkcja(req.query.acc, req.query.am); 
})

http.createServer(app).listen(3000);