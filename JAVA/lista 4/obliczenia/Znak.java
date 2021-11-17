package obliczenia;

public class Znak extends Wyrazenie {
    Wyrazenie a;  

    public Znak(Wyrazenie a){
        this.a=a;
    }    

    @Override
    public String toString() {
        
        return "-"+a.toString();
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Znak) {
            return ((Znak)obj).a.equals(this.a);
        }
        return false;
    }
    @Override
    public int oblicz() {
            return -1*a.oblicz();
    }
}
