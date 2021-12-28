$(document).ready(function(){
    $('#searchphrase').on('input', function() {
        if ($('#searchphrase').val().length > 2){
            $('#items').find('li').each(function(){
                let searched_index = ($(this).text().indexOf($('#searchphrase').val()));
                let thi_text = $(this).text();
                if (searched_index != -1){
                    $(this).text("");
                    var f_span = $(document.createElement('span'));
                    f_span.text(thi_text.substring(0, searched_index));
                    f_span.css("color", "lightgray");
                    $(this).append(f_span);

                    var m_span = $(document.createElement('span'));
                    m_span.text(thi_text.substring(searched_index, $('#searchphrase').val().length ));
                    m_span.css("background-color", "yellow");
                    $(this).append(m_span);

                    var l_span = $(document.createElement('span'));
                    l_span.text(thi_text.substring($('#searchphrase').val().length ));
                    l_span.css("color", "lightgray");
                    $(this).append(l_span);
                }
                else{
                    $(this).text("");
                    var pom_span = $(document.createElement('span'));
                    pom_span.text(thi_text);
                    $(pom_span).css("color", "lightgray");
                    $(this).append(pom_span);
                }
            })
        }
    })
})