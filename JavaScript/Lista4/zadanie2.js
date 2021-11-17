function Foo(){
    function Qux () {
        console.log("Q")
    }
    Foo.prototype.Bar=function(){
        return Qux.call(this)
    }
}

var f = new Foo()
f.Bar()
f.Qux()