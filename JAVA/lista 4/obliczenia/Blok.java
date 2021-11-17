package obliczenia;

import java.util.Vector;

import struktury.*;

public class Blok extends Instrukcja {
    Instrukcja a[];
    public static Vector <Zbior> srodowiska=new Vector<Zbior>();
    public Blok(Instrukcja... ins) throws Exception {
        if (ins==null) {
            throw new Exception("null");
        }
        a=ins;
    }
    @Override
    public void wykonaj() throws Exception {
        srodowiska.add(new ZbiorNaTablicyDynamicznej());
        for (Instrukcja instrukcja : a) {
            instrukcja.wykonaj();
        }
        srodowiska.remove(srodowiska.size()-1);
    }
}
