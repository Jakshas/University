package zadanie1;
public class Zadanie{
    public static void main(String[] args) {
        Lista list=new Lista();
        Diament d=new Diament();
        Krzem k=new Krzem();
        Talk t=new Talk();
        list.add(d);
        list.add(k);
        list.add(t);
        list.print();
    }
}