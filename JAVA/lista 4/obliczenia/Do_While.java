package obliczenia;

public class Do_While extends Instrukcja {

    Wyrazenie wyr;
    Instrukcja ins;
    Do_While(Wyrazenie wyr,Instrukcja ins) throws Exception {
        if (wyr==null||ins==null) {
            throw new Exception("null");
        }
        this.wyr=wyr;
        this.ins=ins;
    }

    @Override
    public void wykonaj() throws Exception {
         do{
            ins.wykonaj();
        }while (wyr.oblicz()>0);
    }
    
}

