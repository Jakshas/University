package obliczenia;

public class Potegowanie extends Wyrazenie {
    Wyrazenie a;
    Wyrazenie p;

    public Potegowanie(Wyrazenie a, Wyrazenie b){
        this.a=a;
        this.p=b;
    } 
    @Override
    public String toString() {
        
        return "("+(a.toString())+"^"+p+")";
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Potegowanie) {
            return ((Potegowanie)obj).a.equals(this.a) && ((Potegowanie)obj).p.equals(this.p);
        }
        return false;
    }
    @Override
    public int oblicz() {
        int pom=a.oblicz(),sum=1;
        for (int i = 0; i < p.oblicz(); i++) {
            sum=sum*pom;
        }
        return sum;
    }
}
