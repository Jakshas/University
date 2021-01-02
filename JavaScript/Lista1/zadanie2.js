function które(){
    for(var i=1;i<=100000;i++){
        var pom=i, sum=0,slowo1=0,slowo2=0;
        while(pom>0){
            var pom2=pom%10;
            sum+=pom2;
            pom=pom/10;
            pom=Math.floor(pom);
            if(i%pom2==0){
                    slowo1+=1;
            }
            slowo2+=1;
        }
        if(slowo1==slowo2){
            if(i%sum==0){
                console.log(i);
                cale=cale+1;
            }
        }
        }
}

które();
