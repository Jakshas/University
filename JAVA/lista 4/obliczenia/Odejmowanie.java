package obliczenia;

public class Odejmowanie extends Wyrazenie {
    Wyrazenie a;
    Wyrazenie b;    
    public Odejmowanie(Wyrazenie a,Wyrazenie b){
        this.a=a;
        this.b=b;
    }    

    @Override
    public String toString() {
        return "("+(a.toString()+"-"+b.toString())+")";
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Odejmowanie) {
            return ((Odejmowanie)obj).a.equals(this.a) && ((Odejmowanie)obj).b.equals(this.b);
        }
        return false;
    }
    @Override
    public int oblicz() {
        return a.oblicz()-b.oblicz();
    }
    
    
}
