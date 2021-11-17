package obliczenia;

public class Wypisz extends Instrukcja {
    Wyrazenie wyr;
    public Wypisz(Wyrazenie w) throws Exception {
        if (w==null) {
            throw new Exception("null");
        }
        wyr=w;
    }
    @Override
    public void wykonaj() throws Exception {
        System.out.println(wyr.oblicz());
    }
    
}
