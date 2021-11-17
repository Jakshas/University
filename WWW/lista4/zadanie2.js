var tab=[['1','2','3','4'],['1','2','3','4'],['1','2','3','4']]

$(document).ready(function(){
    for (let i = 0; i < tab[0].length; i++) {
        const element = tab[0][i];
        $("#div1").append(element)
        $("#div1").append("<br>")
    }   
    for (let i = 0; i < tab[1].length; i++) {
        const element = tab[1][i];
        $("#div2").append(element)
        $("#div2").append("<br>")
    }   
    for (let i = 0; i < tab[2].length; i++) {
        const element = tab[2][i];
        $("#div3").append(element)
        $("#div3").append("<br>")
    }
    function getRandomInt(min, max) {
        min = Math.ceil(min);
        max = Math.floor(max);
        return Math.floor(Math.random() * (max - min)) + min;
      }      
    $("#klik").on('click',function () {
        let s=''
        for (let i = 0; i < 3; i++) {
            const element = tab[i][getRandomInt(0,4)];
            s=s+element+" "
        }
        $("#wypisz").val(s)
    })  
})
