class Checkers{

    constructor(own,turn){
        this.boarad=[1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2];
        this.own=own;
        this.enemy=(own+1)%2;
        this.checed=null;
        this.turn=turn;
        this.moves=[];
        this.haveToMove=[];
        this.deleting=[];
        this.deletingtemp=[];
    }

    setNewBoard(){
        this.boarad=[1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2];
    }

    click(x,y){
        if (this.haveToMove) {
            if (this.inHaveToMove(this.convertxy(x,y))) {
                this.markPawn(x,y);
                this.makeMove(x,y);
            }
        }else{
            this.markPawn(x,y);
            this.makeMove(x,y);
        }
        this.checkQueens;
    }

    convertxy(x,y){
        if (this.checkifwhite(x,y)) {
            return false
        } else {
            return Math.floor(x/2)+y*4;
        }
    }

    checkPawn(x,y,worb){
        if (checkifwhite(x,y)) {
            return false;
        } else {
            if (this.boarad[this.convertxy(x,y)]%2==worb) {
                return true;
            } else {
                return false;
            }
        }
    }

    checkIfWhite(x,y){
        if(y%2==1&&x%2==1){
            return true;
        }
        if(y%2==0&&x%2==0){
            return true;
    }
    return false;
    }

    markPawn(x,y){
        if (this.convertxy(x,y)===this.checed) {
            this.checed=null;
            this.moves=[];
        }else{
            if(this.checkPawn(x,y, this.own)){
                this.checed=this.convertxy(x,y);
                this.moves=this.checkBeating();
            }
        }
        this.checkMoves();
    }

    ifEmpty(x,y){
        if(this.boarad[this.convertxy(x,y)]==0){
            return true;
        }else{
            return false;
        }
    }

    checkBeating(x,y){
        var returning=[];
        if (x-2>=0||y-2>=0) {
            if (this.ifEmpty(x-2,y-2)) {
                if (this.checkPawn(x-1,y-1,this.enemy)) {
                    returning.push(this.convertxy(x-2,y-2));
                    returning.join(this.checkBeating(x-2,y-2));
                }
            }
        }
        if (x-2>=0||y+2<=7) {
            if (this.ifEmpty(x-2,y+2)) {
                if (this.checkPawn(x-1,y+1,this.enemy)) {
                    returning.push(this.convertxy(x-2,y+2));
                    returning.join(this.checkBeating(x-2,y+2));
                }
            }
        }
        if (x+2<=7||y-2>=0) {
            if (this.ifEmpty(x+2,y-2)) {
                if (this.checkPawn(x+1,y-1,this.enemy)) {
                    returning.push(this.convertxy(x+2,y-2));
                    returning.join(this.checkBeating(x+2,y-2));
                }
            }
        }
        if (x+2<=7||y+2<=7) {
            if (this.ifEmpty(x+2,y+2)) {
                if (this.checkPawn(x+1,y+1,this.enemy)) {
                    returning.push(this.convertxy(x+2,y+2));
                    returning.join(this.checkBeating(x+2,y+2));
                }
            }
        }
        return returning;
    }
    
    beat(x,y,xz,yz){
        if (x==xz && y==yz) {
            this.deletingtemp.push(this.convertxy(z,y));
            this.deleting=this.deletingtemp;
        }
        if (x-2>=0||y-2>=0) {
            if (this.inMoves(this.convertxy(x-2,y-2))) {
                deleting.push(this.convertxy(x-1,y-1));
                this.beat(x-2,y-2,xz,yz);
            }
        }
        if (x-2>=0||y+2<=7) {
            if (this.inMoves(this.convertxy(x-2,y+2))) {
                deleting.push(this.convertxy(x-1,y+1));
                this.beat(x-2,y+2,xz,yz);
            }
        }
        if (x+2<=7||y-2>=0) {
            if (this.inMoves(this.convertxy(x+2,y-2))) {
                deleting.push(this.convertxy(x+1,y-1));
                this.beat(x+2,y-2,xz,yz);
            }
        }
        if (x+2<=7||y+2<=7) {
            if (this.inMoves(this.convertxy(x+2,y+2))) {
                deleting.push(this.convertxy(x+1,y+1));
                this.beat(x+2,y+2,xz,yz);
            }
        }
        this.deletingtemp.pop;
    }

    convertId(id){
        var x, y;
        if(id%2==0){
            x=(id%4)*2+1;
            y=(Math.floor(id/4));
        }else{
            x=(id%4)*2;
            y=(Math.floor(id/4));
        }
        return [x,y];
    }

    checkMoves(x,y){
        if (this.own==1) {
            if (this.boarad[this.convertxy(x,y)]!=2+(this.own%2)) {
                if (this.boarad[this.convertxy(x+1,y+1)]==0) {
                    this.moves.push(this.convertxy(x+1,y+1));
                }
                if (this.boarad[this.convertxy(x-1,y+1)]==0) {
                    this.moves.push(this.convertxy(x-1,y+1));
                }
            }else{
                let i=1;
                while (this.boarad[this.convertxy(x-i,y+i)]==0) {
                    this.moves.push(this.convertxy(x-i,y+i));
                }
                i=1;
                while (this.boarad[this.convertxy(x+i,y+i)]==0) {
                    this.moves.push(this.convertxy(x+i,y+i));
                }
                i=1;
                while (this.boarad[this.convertxy(x-i,y-i)]==0) {
                    this.moves.push(this.convertxy(x-i,y-i));
                }
                i=1;
                while (this.boarad[this.convertxy(x+i,y-i)]==0) {
                    this.moves.push(this.convertxy(x+i,y-i));
                }
            }
        }else{
            if (this.boarad[this.convertxy(x,y)]!=2+(this.own%2)) {
                if (this.boarad[this.convertxy(x+1,y-1)]==0) {
                    this.moves.push(this.convertxy(x+1,y-1));
                }
                if (this.boarad[this.convertxy(x-1,y-1)]==0) {
                    this.moves.push(this.convertxy(x-1,y-1));
                }
            }else{
                let i=1;
                while (this.boarad[this.convertxy(x-i,y+i)]==0) {
                    this.moves.push(this.convertxy(x-i,y+i));
                    i++;
                }
                if ((this.boarad[this.convertxy(x-i,y+i)]==this.enemy || this.boarad[this.convertxy(x-i,y+i)]==this.enemy+2) && 
                this.boarad[this.convertxy(x-i-1,y+i+1)]==0) {
                    this.moves.push(this.convertxy(x-i-1,y+i+1));
                    this.moves.push(this.checkBeating(x-i-1,y+i+1));
                }
                i=1;
                while (this.boarad[this.convertxy(x+i,y+i)]==0) {
                    this.moves.push(this.convertxy(x+i,y+i));
                    i++;
                }
                if ((this.boarad[this.convertxy(x+i,y+i)]==this.enemy || this.boarad[this.convertxy(x+i,y+i)]==this.enemy+2) && 
                this.boarad[this.convertxy(x+i+1,y+i+1)]==0) {
                    this.moves.push(this.convertxy(x+i+1,y+i+1));
                    this.moves.push(this.checkBeating(x+i+1,y+i+1));
                }
                i=1;
                while (this.boarad[this.convertxy(x-i,y-i)]==0) {
                    this.moves.push(this.convertxy(x-i,y-i));
                    i++;
                }
                if ((this.boarad[this.convertxy(x-i,y-i)]==this.enemy || this.boarad[this.convertxy(x-i,y-i)]==this.enemy+2) && 
                this.boarad[this.convertxy(x-i-1,y-i-1)]==0) {
                    this.moves.push(this.convertxy(x-i-1,y-i-1));
                    this.moves.push(this.checkBeating(x-i-1,y-i-1));
                }
                i=1;
                while (this.boarad[this.convertxy(x+i,y-i)]==0) {
                    this.moves.push(this.convertxy(x+i,y-i));
                    i++;
                }
                if ((this.boarad[this.convertxy(x+i,y-i)]==this.enemy || this.boarad[this.convertxy(x+i,y-i)]==this.enemy+2) && 
                this.boarad[this.convertxy(x+i+1,y-i-1)]==0) {
                    this.moves.push(this.convertxy(x+i+1,y-i-1));
                    this.moves.push(this.checkBeating(x+i+1,y-i-1));
                }
            }
        }
    }

    inMoves(id){
        this.moves.forEach(element => {
            if (elemnet==id) {
                return true;
            }
        });
        return false;
    }
    inHaveToMove(id){
        this.haveToMove.forEach(element => {
            if (elemnet==id) {
                return true;
            }
        });
        return false;
    }
    checkIfCan(){
        this.boarad.forEach(element => {
            this.haveToMove=[];
            var temp = this.convertId(elemnet);
            if (this.checkBeating(temp[0],temp[1])) {
                this.haveToMove.push(element);
            }
        });
    }

    makeMove(xz,yz){
        var temp = this.convertId(this.checed);
        var x = temp[0];
        var y = temp[1];
        if (this.checed!=null) {
            if (this.inMoves(this.convertxy(xz,yz))) {
                if (this.boarad[this.checed]==this.own%2+2) {
                    let i=1;
                    while (this.boarad[this.convertxy(x-i,y+i)]==0) {
                        i++;
                    }
                    if (this.inMoves(this.convertxy(x-i-1,y+i+1)==0)) {
                        this.beat(x-i,y+i,xz,xy);
                    }
                    i=1;
                    while (this.boarad[this.convertxy(x+i,y+i)]==0) {
                        i++;
                    }
                    if (this.inMoves[this.convertxy(x+i+1,y+i+1)]==0) {
                        this.beat(x+i,y+i,xz,xy);
                    }
                    i=1;
                    while (this.boarad[this.convertxy(x-i,y-i)]==0) {
                        i++;
                    }
                    if (this.inMoves[this.convertxy(x-i-1,y-i-1)]==0) {
                        this.beat(x-i,y-i,xz,xy);
                    }
                    i=1;
                    while (this.boarad[this.convertxy(x+i,y-i)]==0) {
                        i++;
                    }
                    if (this.inMoves[this.convertxy(x+i+1,y-i-1)]==0) {
                        this.beat(x+i,y-i,xz,xy);
                    }
                    }else{
                        this.beat(x,y,xz,xy);
                    }
            }
        } 
    }

    checkQueens(){
            if (own%2==1) {
                for (let i = 0; i < this.boarad.length; i++) {
                    const element = this.boarad[i];
                    if (i>27) {
                        if (elemnet==1) {
                            this.boarad[i]+= 2;
                        }
                    }
                }
            }else{
                for (let i = 0; i < this.boarad.length; i++) {
                    const element = this.boarad[i];
                    if (i<4) {
                        if (elemnet==2) {
                            this.boarad[i]+= 2;
                        }
                    }
                }
            }
    }
}