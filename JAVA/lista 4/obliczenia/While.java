package obliczenia;

public class While extends Instrukcja {

    Wyrazenie wyr;
    Instrukcja ins;
    public While(Wyrazenie wyr,Instrukcja ins) throws Exception {
        if (wyr==null||ins==null) {
            throw new Exception("null");
        }
        this.wyr=wyr;
        this.ins=ins;
    }

    @Override
    public void wykonaj() throws Exception {
        while (wyr.oblicz()>0) {
            ins.wykonaj();
        }
    }
    
}
