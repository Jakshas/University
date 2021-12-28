package obliczenia;

public class If_else extends Instrukcja {

    Wyrazenie wyr;
    Instrukcja ins1;
    Instrukcja ins2;

    public If_else(Wyrazenie w,Instrukcja ins1,Instrukcja ins2) throws Exception {
        if (ins1==null||w==null||ins2==null) {
            throw new Exception("null");
        }
        wyr=w;
        this.ins1=ins1;
        this.ins2=ins2;
    }

    @Override
    public void wykonaj() throws Exception {
        if (wyr.oblicz()>0) {
            ins1.wykonaj();
        }else{
            ins2.wykonaj();
        }
    }
    
}
