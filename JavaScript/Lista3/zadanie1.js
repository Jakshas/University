var obiekt={
    pole,
    f:function() {
        
    },
    wlasnosc,
    get: function(){
        return obiekt.wlasnosc;
    },
    set: function(i){
        obiekt.wlasnosc = i;
    }
}

Object.defineProperty(obiekt,pole2,{})

Object.defineProperty(pole2,'wlasnosc2',{
    get: function(){
        return obiekt.wlasnosc2;
    },
    set: function(i) {
        obiekt.wlasnosc2 = i;  
    }
})

Object.defineProperty(obiekt,f2,{
    function() {
        
    }
})