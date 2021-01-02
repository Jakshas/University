package struktury;

public class Main {
    public static void main(String[] args) throws Exception {
        ZbiorNaTablicy z= new ZbiorNaTablicy(5);
        Para s = new Para(1,"s");
        Para p = new Para(1,"p");
        Para r = new Para(1,"r");
        Para t = new Para(2,"t");
        Para u = new Para(1,"u");
        z.wstaw(s);
        z.wstaw(p);
        z.wstaw(r);
        z.wstaw(t);
        z.wstaw(u);
        Para m = z.szukaj("p");
        z.usuń("p");
        double x = z.czytaj("t");
        Para t1 = new Para(1,"t");
        z.ustaw(t1);
        z.ustaw(p);
        int i=z.ile();
        z.czysc();
        ZbiorNaTablicyDynamicznej zd= new ZbiorNaTablicyDynamicznej();
        zd.wstaw(s);
        zd.wstaw(p);
        zd.wstaw(r);
        zd.wstaw(t);
        zd.wstaw(u);
        Para md = zd.szukaj("p");
        zd.usuń("p");
        double xd = zd.czytaj("t");
        Para t1d = new Para(1,"t");
        zd.ustaw(t1);
        zd.ustaw(p);
        int id=zd.ile();
        zd.czysc();
        }
}
