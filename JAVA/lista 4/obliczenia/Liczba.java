package obliczenia;

public class Liczba extends Wyrazenie {
    int l;
    public Liczba(int a){
        l=a;
    }
    @Override
    public String toString() {
        return String.valueOf(l);
    }
    @Override
    public int oblicz() {
        return l;
    }
    public boolean equals(Object obj) {
        if (obj instanceof Liczba) {
            return ((Liczba)obj).l==this.l;
        }
        return false;
    }
}
