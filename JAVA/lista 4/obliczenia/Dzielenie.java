package obliczenia;

public class Dzielenie extends Wyrazenie {
    Wyrazenie a;
    Wyrazenie b;    

    public Dzielenie(Wyrazenie a,Wyrazenie b){
        this.a=a;
        this.b=b;
    }    

    @Override
    public String toString() {
        
        return "("+(a.toString()+"/"+b.toString())+")";
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Dzielenie) {
            return ((Dzielenie)obj).a.equals(this.a) && ((Dzielenie)obj).b.equals(this.b);
        }
        return false;
    }
    @Override
    public int oblicz() {
        return a.oblicz()/b.oblicz();
    }
}
