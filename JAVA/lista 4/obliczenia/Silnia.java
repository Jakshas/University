package obliczenia;

public class Silnia extends Wyrazenie {
    Wyrazenie a;  

    public Silnia(Wyrazenie a){
        this.a=a;
    } 
    @Override
    public String toString() {
        
        return "(!"+(a.toString())+")";
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Silnia) {
            return ((Silnia)obj).a.equals(this.a);
        }
        return false;
    }
    @Override
    public int oblicz() {
        int sum=1;
        for (int i = 1; i <= a.oblicz(); i++) {
            sum=sum*i;
        }
        return sum;
    }
}
