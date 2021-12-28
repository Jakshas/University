package obliczenia;

public class Stala extends Wyrazenie {
    double pi=Math.PI;
    double e=Math.E;
    double phi=1.61803398;
    String s;
    @Override
    public int oblicz() {
        if(s=="pi"){
            return (int)pi;
        }
        if(s=="e"){
            return (int)e;
        }        
        if(s=="phi"){
            return (int)phi;
        }
        return Integer.parseInt(s);
    }
    public Stala(String s){
        this.s=s;
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Stala) {
            return ((Stala)obj).s==this.s;
        }
        return false;
    }
    @Override
    public String toString() {
        return s;
    }
}
