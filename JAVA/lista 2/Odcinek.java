public class Odcinek {
    private Punkt jeden;
    private Punkt dwa;
    Odcinek(Punkt jeden,Punkt dwa){
        if(jeden.equals(dwa)){
            throw new IllegalArgumentException("złe argumenty");
        }
        this.dwa=dwa;
        this.jeden=jeden;
    }
    public void przesun(Wektor v)  {
        jeden.przesun(v);
        dwa.przesun(v);
    }
    public void obroc(Punkt p, double kat){
        jeden.obroc(p, kat);
        dwa.obroc(p, kat);
    }
    public void odbij(Prosta p){
        jeden.odbij(p);
        dwa.odbij(p);
    }
    public Punkt getDwa() {
        return dwa;
    }
    public Punkt getJeden() {
        return jeden;
    }
}