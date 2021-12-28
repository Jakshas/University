package obliczenia;

public class Reszta extends Wyrazenie {
    Wyrazenie a;
    Wyrazenie b;    

    public Reszta(Wyrazenie a,Wyrazenie b){
        this.a=a;
        this.b=b;
    }    

    @Override
    public String toString() {
        
        return "("+(a.toString()+"%"+b.toString())+")";
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Reszta) {
            return ((Reszta)obj).a.equals(this.a) && ((Reszta)obj).b.equals(this.b);
        }
        return false;
    }
    @Override
    public int oblicz() {
        return a.oblicz()%b.oblicz();
    }
}
