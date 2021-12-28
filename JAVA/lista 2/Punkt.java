/**
 * Punkt
 */
public class Punkt {
    private double x,y;
    Punkt(double x,double y){
        this.x=x;
        this.y=y;
    }
    double getx(){
        return this.x;
    }
    double gety(){
        return this.y;
    }
    public static boolean kierunek(Punkt a,Punkt b,Punkt c) {
        double mianownik1 =a.x-b.x,mianownik2=a.x-c.x,licznik1=a.y-b.y,licznik2=a.y-c.y;
        if(licznik1/mianownik1==licznik2/mianownik2){
            return false;
        }else{
            return true;
        }
    }
    public void przesun(Wektor v){
        this.x=this.x+v.dx;
        this.y=this.y+v.dy;
    }
    public void obroc(Punkt p, double kat){
        this.x = Math.cos(kat)*(this.x-p.x)-Math.sin(kat)+(this.y-p.y)+p.x;
        this.y = Math.sin(kat)*(this.x-p.x)-Math.cos(kat)+(this.y-p.y)+p.y;
    }
    public void odbij(Prosta p){
        double c1=-1*((-1*p.b*x)+p.a*y);
        Prosta pp= new Prosta(-1*p.b, p.a, c1);
        Punkt prz=Prosta.punkt(p, pp);
        double dx=prz.x-this.x, dy=prz.y-this.y;
        Wektor w=new Wektor(dx, dy);
        this.przesun(w);
        this.przesun(w);
    }
}