package zadanie2;
import java.util.Hashtable;

public class Zadanie {
    public static void main(String[] args){
        Hashtable<String, Integer> lista = new Hashtable<String, Integer>();

        lista.put("x", 2);
      
        Zmienna.zmiennalista= lista;
        Wyrażenie wyr = new Pomnoz(new Dodaj(new Stała(2), new Zmienna("x")), new Odejmij(new Stała(5), new Zmienna("x")));
        System.out.println(wyr.toString());
        System.out.println(wyr.oblicz());
    }
}