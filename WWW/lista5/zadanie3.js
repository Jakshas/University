$(document).ready(function () {
    $.getJSON("http://localhost/zadanie3/zadanie3.json",function (data) {
        let template = "<ul> {{#res}}{{/res}} </ul>"
        let text= Mustache.render(template, data);
        $("#Lista").append(text)
    })

})