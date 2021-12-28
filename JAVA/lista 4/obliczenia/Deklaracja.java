package obliczenia;
import struktury.*;
public class Deklaracja extends Instrukcja{
    String zmienna;

    public Deklaracja(String z) throws Exception {
        if (z==null) {
            throw new Exception("null");
        }
        this.zmienna=z;
    }

    @Override
    public void wykonaj() throws Exception {
        for (Zbior srodowisko : Blok.srodowiska) {
            if (srodowisko.szukajtf(zmienna)) {
                throw new Exception("taka zmienna juz jest");
            }
        }
        Blok.srodowiska.get(Blok.srodowiska.size()-1).wstaw(new Para(0,zmienna));
    }
    
}
