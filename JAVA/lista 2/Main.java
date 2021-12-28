public class Main {
    public static void main(String[] args) {
        Odcinek o=new Odcinek(new Punkt(0, -2.0), new Punkt(2.0, 0));
        Prosta p=new Prosta(1.0, -1.0, 0.0);
        o.odbij(p);
        System.out.println(o.getDwa().getx()+", "+o.getDwa().gety()+"  |  "+o.getJeden().getx()+", "+o.getJeden().gety());
    }
}
