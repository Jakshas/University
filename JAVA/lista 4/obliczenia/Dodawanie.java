package obliczenia;

import java.util.Vector;

import struktury.Zbior;

public class Dodawanie extends Wyrazenie     {
    Wyrazenie a;
    Wyrazenie b;
    public Dodawanie(Wyrazenie a,Wyrazenie b){
        this.a=a;
        this.b=b;
    }    

    @Override
    public String toString() {
        
        return "("+(a.toString()+"+"+b.toString())+")";
    }
    @Override
    public boolean equals(Object obj) {
            if (obj instanceof Dodawanie) {
                return ((Dodawanie)obj).a.equals(this.a) && ((Dodawanie)obj).b.equals(this.b);
            }
            return false;
    }
    @Override
    public int oblicz() {
        Vector<Zbior> zb=Blok.srodowiska;
        return a.oblicz()+b.oblicz();
    }
    
}
