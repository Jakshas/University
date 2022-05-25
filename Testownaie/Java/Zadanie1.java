
import java.util.ArrayList;


class Zadanie1{
    public ArrayList<String> metoda(ArrayList<String> l, String s) throws IllegalArgumentException{
        if(l == null){
            throw new IllegalArgumentException("Lista ma wartośc null");
        }
        if(s == null){
            throw new IllegalArgumentException("String ma wartośc null");
        }
        ArrayList<String> nl = new ArrayList<String>();
        for (String iterable_element : l) {
            if(iterable_element == null || iterable_element != s){
                nl.add(iterable_element);
            }
        }
        return nl;
    }
    
}

