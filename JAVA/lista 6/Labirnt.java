    import java.util.Random;
import java.util.Vector;

public class Labirnt {
    Vector<Integer>[] sciezki;
    int rozmiar;
    boolean[] sprawdzone;
    Random r = new Random();

    public Labirnt(int srozmiar)
    {
        this.rozmiar = srozmiar;
        sprawdzone = new boolean[rozmiar * rozmiar];
        sciezki = new Vector[rozmiar * rozmiar];
        for (int i = 0; i < rozmiar*rozmiar; i++) { 
            sciezki[i] = new Vector<Integer>(); 
        }
        sciezki(0,0);
    }

    private void sciezki(int rzad, int kolumna)
    {
        int index = rzad * rozmiar + kolumna;
        sprawdzone[index] = true;
        Vector<Integer> kierunki = new Vector<Integer>();
        if(rzad < rozmiar - 1){
            kierunki.add(index + rozmiar);
        }
        if(rzad > 0){
            kierunki.add(index - rozmiar);
        }
        if(kolumna > 0){
            kierunki.add(index - 1);
        } 
        if(kolumna < rozmiar - 1){
            kierunki.add(index + 1);
        }
        while(!kierunki.isEmpty())
        {
            int losowa = Math.abs(r.nextInt()) % kierunki.size(); 
            int droga = kierunki.get(losowa); 

            if( sprawdzone[droga] == false)
            {
                sciezki[index].add(droga);
                sciezki[droga].add(index);
                sciezki(droga / rozmiar, droga % rozmiar);
            }
            kierunki.remove(losowa);
        }
    }
}