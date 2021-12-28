public class Trojkat {
    private Punkt jeden,dwa,trzy;
    Trojkat(Punkt jeden,Punkt dwa, Punkt trzy){
        if(Punkt.kierunek(jeden, dwa, trzy)){
            throw new IllegalArgumentException("złe argumenty");
        }else{
        this.jeden=jeden;
        this.dwa=dwa;
        this.trzy=trzy;
        }
    }
    public void przesun(Wektor v)  {
        jeden.przesun(v);
        dwa.przesun(v);
        trzy.przesun(v);
    }
    public void obroc(Punkt p, double kat){
        jeden.obroc(p, kat);
        dwa.obroc(p, kat);
        trzy.obroc(p, kat);
    }
    public void odbij(Prosta p){
        jeden.odbij(p);
        dwa.odbij(p);
        trzy.odbij(p);
    }
}
