package zadanie2;
import java.util.Hashtable;


    public class Zmienna extends Wyrażenie{
        public String zmienna;
        public static Hashtable<String, Integer> zmiennalista = new Hashtable<String, Integer>();
        public Zmienna(String zmienna)
    {
        this.zmienna = zmienna;
    }
    public int oblicz(){
        return zmiennalista.get(zmienna);
    }
    public String toString(){
        return zmienna;
    }
    }
