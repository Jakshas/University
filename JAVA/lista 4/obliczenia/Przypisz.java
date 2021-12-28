package obliczenia;

import struktury.Para;
import struktury.Zbior;

public class Przypisz extends Instrukcja {
    Wyrazenie wyr;
    String zm;
    public Przypisz(String zmienna ,Wyrazenie w) throws Exception {
        if (zmienna==null||w==null) {
            throw new Exception("null");
        }
        wyr=w;
        zm=zmienna;
    }
    @Override
    public void wykonaj() throws Exception {
        for (Zbior srodowisko : Blok.srodowiska) {
            if (srodowisko.szukajtf(zm)) {
                srodowisko.ustaw(new Para(wyr.oblicz(),zm));
            }
        }
        throw new Exception("nie ma zmiennej zadeklarowanej");
    }
    
}
