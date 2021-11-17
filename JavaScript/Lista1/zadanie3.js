function pierwsze(){
    for(var i=2;i<=100000;i++){
        var ile=0;
        for(var j=2;j<i;j++){
            var pom=i,slowo1;
            if(i%j==0){
                ile++;
            }
        }
        if(ile==0){
            console.log(i);
        }
    }
}
pierwsze();