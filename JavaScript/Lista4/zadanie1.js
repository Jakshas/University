function Tree(val, left, right) {
    this.left = left;
    this.right = right;
    this.val = val;
}
// Tree.prototype[Symbol.iterator] = function*() {
//     yield this.val;
//     if ( this.left )  yield* this.left;
//     if ( this.right ) yield* this.right;
// }

Tree.prototype[Symbol.iterator] = function*() {
    var tab=[];
    tab.splice(0,0,this) 
    while(tab.length>0){
        var get=tab.splice(0,1)
        if ( get[0].left )  tab.splice(0,0,get[0].left);
        if ( get[0].right ) tab.splice(0,0,get[0].right);
        yield get[0].val
    }

}

var root = new Tree( 1,
    new Tree( 2, new Tree( 3 ) ), new Tree( 4 ));
for ( var e of root ) {console.log( e );}