public class Prosta {
    public final double a,b,c;
    Prosta(double a1,double b1,double c1){
        a=a1;
        b=b1;
        c=c1;
    }
    public static Prosta przesun(Prosta p,Wektor w){
        double y1=p.a*w.dx+w.dy;
        return new Prosta(p.a,p.b,p.c+y1);
    }
    public static boolean prostopadle(Prosta p1,Prosta p2) {
        if (p1.a/p1.b==-1*p2.b/p2.a) {
            return true;
        }else{
            return false;
        }
    }
    public static boolean rownolegle(Prosta p1,Prosta p2) {
        if (p1.a/p1.b==p2.a/p2.b) {
            return true;
        }else{
            return false;
        }
    }
    public static Punkt punkt(Prosta p1,Prosta p2) {
        if (Prosta.rownolegle(p1, p2)) {
            throw new IllegalArgumentException("równoległe");
        }
        double w=(p1.a*p2.b)-(p2.a*p1.b);
        double wx=((-1.0*p1.c)*p2.b)-((-1.0*p2.c)*p1.b);
        double wy=(p1.a*(-1.0*p2.c))-(p2.a*(-1.0*p1.c));
        return new Punkt(wx/w, wy/w);
    }
}
