package zadanie2;

public class Odejmij extends Wyrażenie{
Wyrażenie a;
Wyrażenie b;
public Odejmij(Wyrażenie a,Wyrażenie b){
    this.a=a;
    this.b=b;
}
public int oblicz(){
   return a.oblicz()-b.oblicz();        
}
public String toString(){
    return "("+a.toString()+"-"+b.toString()+")";
}
}