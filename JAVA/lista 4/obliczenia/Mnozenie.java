package obliczenia;

public class Mnozenie extends Wyrazenie {
    Wyrazenie a;
    Wyrazenie b;    

    public Mnozenie(Wyrazenie a,Wyrazenie b){
        this.a=a;
        this.b=b;
    }    

    @Override
    public String toString() {
        
        return "("+(a.toString()+"*"+b.toString())+")";
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Mnozenie) {
            return ((Mnozenie)obj).a.equals(this.a) && ((Mnozenie)obj).b.equals(this.b);
        }
        return false;
    }
    @Override
    public int oblicz() {
        return a.oblicz()*b.oblicz();
    }
}
