package obliczenia;

public class If extends Instrukcja {

    Wyrazenie wyr;
    Instrukcja ins;

    public If(Wyrazenie w,Instrukcja ins) throws Exception {
        if (w==null||ins==null) {
            throw new Exception("null");
        }
        wyr=w;
        this.ins=ins;
    }

    @Override
    public void wykonaj() throws Exception {
        if (wyr.oblicz()>0) {
            ins.wykonaj();
        }
    }
    
}
