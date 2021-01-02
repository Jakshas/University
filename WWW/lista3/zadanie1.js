var numer = document.getElementById('numer')
var pesel = document.getElementById('pesel')
var data = document.getElementById('data')
var mail = document.getElementById('mail')
var klik = document.getElementById('klik')
klik.onclick=
function() {
    var test= /\S+@\S+\.\S+/;
    if(test.test(mail.value)){
        mail.style.color="green";
    }
    test= /^[0-9]{2}\s[0-9]{4}\s[0-9]{4}\s[0-9]{4}\s[0-9]{4}\s[0-9]{4}\s[0-9]{4}$/;
    if(test.test(numer.value)){
        numer.style.color="green";
    }
    test= /^(0[1-9]|1\d|2\d|3[01])\/(0[1-9]|1[0-2])\/(19|20)\d{2}$/;
    if(test.test(data.value)){
        data.style.color="green";
    }
    test= /^\d\d\d\d\d\d\d\d\d\d\d$/;
    if(test.test(pesel.value)){
        pesel.style.color="green";
    }
}
pesel.onchange=
function () {
    var test= /^\d\d\d\d\d\d\d\d\d\d\d$/;
    if(test.test(pesel.value)){
        pesel.style.color="green";
    }
}
data.onchange=
function () {
    var test= /^(0[1-9]|1\d|2\d|3[01])\/(0[1-9]|1[0-2])\/(19|20)\d{2}$/;
    if(test.test(data.value)){
        data.style.color="green";
    }
}
numer.onchange=
function () {
    var test= /^[0-9]{2}\s[0-9]{4}\s[0-9]{4}\s[0-9]{4}\s[0-9]{4}\s[0-9]{4}\s[0-9]{4}$/;
    if(test.test(numer.value)){
        numer.style.color="green";
    }
}
mail.onchange=
function () {
    var test= /\S+@\S+\.\S+/;
    if(test.test(mail.value)){
        mail.style.color="green";
    }
}