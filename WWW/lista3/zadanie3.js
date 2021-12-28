let div1 =document.getElementById('div1')
let div2 =document.getElementById('div2')
let div3 =document.getElementById('div3')
push1up()
function push1up() {
    setInterval(function(){div1.style.top="75px"},3000)
    setTimeout(function(){
        setInterval(function(){div1.style.top="100px"},3000)},250)
    setTimeout(function(){push2up()},500)
    setTimeout(function(){push3up()},1000)
    setTimeout(function(){push1down()},1500)
}
function push1down() {
    setInterval(function(){div1.style.top="75px"},3000)
    setTimeout(function(){
        setInterval(function(){div1.style.top="50px"},3000)},250)
    
}
function push2up() {
    setInterval(function(){div2.style.top="75px"},3000)
    setTimeout(function(){
        setInterval(function(){div2.style.top="100px"},3000)},250)
    setTimeout(function(){push2down()},1500)
}
function push2down() {
    setInterval(function(){div2.style.top="75px"},3000)
    setTimeout(function(){
        setInterval(function(){div2.style.top="50px"},3000)},250)
}
function push3up() {
    setInterval(function(){div3.style.top="75px"},3000)
    setTimeout(function(){
        setInterval(function(){div3.style.top="100px"},3000)},250)
    setTimeout(function(){push3down()},1500)
}
function push3down() {
    setInterval(function(){div3.style.top="75px"},3000)
    setTimeout(function(){
        setInterval(function(){div3.style.top="50px"},3000)},250)
}

