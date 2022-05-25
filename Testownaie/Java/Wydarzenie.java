import java.util.Calendar;

public class Wydarzenie implements Comparable<Wydarzenie>{
    String nazwa;
    Calendar poczatek;
    Calendar koniec;
    Wydarzenie(String nazwa,Calendar poczatek,Calendar koniec){
        this.nazwa = nazwa;
        this.poczatek = poczatek;
        this.koniec = koniec;
    }
    @Override
    public int compareTo(Wydarzenie o) {
        return poczatek.compareTo(o.poczatek);
    }
}