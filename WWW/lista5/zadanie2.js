$(document).ready(function () {
        let tvn= "https://cors-anywhere.herokuapp.com/"+"https://tvn24.pl/najnowsze.xml"
        $.get(tvn,function (xml) {
            let i=0
            $(xml).find("item").each(function () {
                if(i==5) return;
                let artykul=$(document.createElement('ul'));
                artykul.append(`<b>${$(this).find("title").text()}</b><br><br>`)
                artykul.append(`<p>${rimg($(this).find("description").text())}</p><br>`)
                artykul.append(`<a href="${$(this).find("guild").text()}">link</a><br>`)
                $("#Lista").append(artykul)
            })
        })
})

function rimg(s){
    let ns= s.indexOf("/>")
    return s.substring(ns + 2)
}