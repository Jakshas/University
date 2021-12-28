public class Wektor {
    public final double dx,dy;
    Wektor(double x,double y){
        dx=x;
        dy=y;
    }
    public static Wektor name(Wektor w1,Wektor w2) {
        double dx=w1.dx+w2.dx;
        double dy=w1.dy+w2.dy;
        return new Wektor(dx,dy);
    }
}
