package obliczenia;

public class Logarytm extends Wyrazenie {
    Wyrazenie a;
    Wyrazenie b;
    public Logarytm(Wyrazenie a,Wyrazenie b){
        this.a=a;
        this.b=b;
    } 
    @Override
    public String toString() {
        
        return "log("+(a.toString())+")";
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Logarytm) {
            return ((Logarytm)obj).a.equals(this.a) && ((Logarytm)obj).b.equals(this.b);
        }
        return false;
    }
    @Override
    public int oblicz() {
        return (int)(Math.log(a.oblicz())/Math.log(b.oblicz()));
    }
}
