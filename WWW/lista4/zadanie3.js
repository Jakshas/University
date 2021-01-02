$(document).ready(function(){
    $("#img1").click(function(){
        if ($(this).data("marked")) {
            $(this).css({
                'border-width' : '0px'
            })
            $(this).data("marked",false)
        }else{
            $(this).css({
                "border-color":"red",
                'border-style': 'solid',
                'border-width' : '4px'
            })
            $(this).data("marked",true)
        }
    })
    $("#img2").click(function(){
        if ($(this).data("marked")) {
            $(this).css({
                'border-width' : '0px'
            })
            $(this).data("marked",false)
        }else{
            $(this).css({
                "border-color":"red",
                'border-style': 'solid',
                'border-width' : '4px'
            })
            $(this).data("marked",true)
        }
    })
    $("#img3").click(function(){
        if ($(this).data("marked")) {
            $(this).css({
                'border-width' : '0px'
            })
            $(this).data("marked",false)
        }else{
            $(this).css({
                "border-color":"red",
                'border-style': 'solid',
                'border-width' : '4px'
            })
            $(this).data("marked",true)
        }
    })
    $("#img4").click(function(){
        if ($(this).data("marked")) {
            $(this).css({
                'border-width' : '0px'
            })
            $(this).data("marked",false)
        }else{
            $(this).css({
                "border-color":"red",
                'border-style': 'solid',
                'border-width' : '4px'
            })
            $(this).data("marked",true)
        }
    })
    $("#klik").click(function() {
        if($(this).data("marked")==true){
            $('img').css({
                'border-width' : '0px'
            })
            $(this).data("marked",false)
        }else{
            $("img").css({
                "border-color":"red",
                'border-style': 'solid',
                'border-width' : '4px'
            })
            $(this).data("marked",true)
        }
    })
    $("#kliklog").click(function() {
        let s=''
        $("img").each( function() {
            if($(this).data("marked")){
                s=s+$(this).attr('id')+" "
            }
        });
        $("#log").val(s)
    })
})