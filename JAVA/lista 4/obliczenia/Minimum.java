package obliczenia;

public class Minimum extends Wyrazenie{
    Wyrazenie a[]; 

    public Minimum(Wyrazenie... w){
        a=w;
    }
    @Override
    public String toString() {
        String sum="min(";
        for (Wyrazenie wyrazenie : a) {
            sum=sum+wyrazenie.toString();
        }
        return sum+")";
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Minimum) {
            Minimum ob=(Minimum)obj;
            if (a.length==ob.a.length) {
                for (int i = 0; i < a.length; i++) {
                    if (!a[i].equals(ob.a[i])) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
    @Override
    public int oblicz() {
        int min=a[0].oblicz();
        for (Wyrazenie wyrazenie : a) {
            if(wyrazenie.oblicz()<min){
                min=wyrazenie.oblicz();
            }
        }
        return min;
    }
}
