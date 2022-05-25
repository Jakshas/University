import java.util.ArrayList;
import java.util.Calendar;
import java.util.Collections;

public class Zadanie2 {
    ArrayList<Wydarzenie> list = new ArrayList<Wydarzenie>();
    public boolean dodajWydarzenie(Wydarzenie w){
        Collections.sort(list);
        boolean flag = false;
        for (Wydarzenie iterable_element : list) {
            if( (w.poczatek.after(iterable_element.poczatek) && w.poczatek.before(iterable_element.koniec) ) || (w.koniec.after(iterable_element.poczatek) && w.koniec.before(iterable_element.koniec) )){
                flag = true;
                break;
            }
        }
        if(!flag){
            list.add(w);
            return true;
        }
        return false;
    }
    public void usunWydarzenie(String s){
        for(int i = 0; i<list.size(); i++){
            if (list.get(i).nazwa == s) {
                list.remove(i);
            }
        }
    }
    public void zmienWydarzenie(String s, Calendar poczatek,Calendar koniec) throws Exception{
        Wydarzenie w = new Wydarzenie(s, poczatek, koniec);
        for(int i = 0; i<list.size(); i++){
            if (list.get(i).nazwa == s) {
                w = list.remove(i);
            }
        }
        if (!dodajWydarzenie(new Wydarzenie(s, poczatek, koniec))) {
            list.add(w);
            throw new Exception("Wydrzenie nachodzi na inne.");
        }
    }
    
}
