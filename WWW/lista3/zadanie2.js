let tab =['Ford','Fiat']
let tabm=[['Focus','Mustang'],['126p','500']]
function dodajmarki() {
    for (let i = 0; i < tab.length; i++) {
        var sel = document.getElementById('marka');
        var opt = document.createElement('option');
        opt.appendChild( document.createTextNode(tab[i]) );
        opt.value = tab[i]; 
        sel.appendChild(opt);
    }
    for (let i = 0; i < tabm[0].length; i++) {
        var sel = document.getElementById('model');
        var opt = document.createElement('option');
        opt.appendChild( document.createTextNode(tabm[0][i]) );
        opt.value = tabm[0][i]; 
        sel.appendChild(opt);
    }
}
dodajmarki()
let marka=document.getElementById('marka')
marka.onchange=
function(){
    var model = document.getElementById('model');
    model.options.length=0
    for (let j = 0; j < tab.length; j++) {
        if(tab[j]==marka.value){
            for (let i = 0; i < tabm[j].length; i++) {
                var sel = document.getElementById('model');
                var opt = document.createElement('option');
                opt.appendChild( document.createTextNode(tabm[j][i]));
                opt.value = tabm[j][i]; 
                sel.appendChild(opt);
            }
        }
    }
}
let klik=document.getElementById('klik')
klik.onclick=
function() {
    let ikonka = document.getElementsByName('rodzaj')
    for (let k = 0; k < ikonka.length; k++) {
        if(ikonka[k].checked){
            let tekst = document.getElementById('nowa')
            if(k==0){
                tab.push(tekst.value)
                tabm.push([])
                document.getElementById('marka').options.length=0
                for (let i = 0; i < tab.length; i++) {
                    var sel = document.getElementById('marka');
                    var opt = document.createElement('option');
                    opt.appendChild( document.createTextNode(tab[i]) );
                    opt.value = tab[i]; 
                    sel.appendChild(opt);
                }
            }
            if(k==1){
                for (let j = 0; j < tab.length; j++) {
                    if(tab[j]==marka.value){
                        tabm[j].push(tekst.value)
                        console.log(tabm[j].length)
                        var model = document.getElementById('model');
                        model.options.length=0
                        for (let i = 0; i < tabm[j].length; i++) {
                            var sel = document.getElementById('model');
                            var opt = document.createElement('option');
                            opt.appendChild( document.createTextNode(tabm[j][i]));
                            opt.value = tabm[j][i]; 
                            sel.appendChild(opt);
                        }
                    }
                    
                }
            }
        }
    }

}