/**
 * Klasa opisująca pole z kilofem
 */
public class Kilof extends Przedmiot{
    int wydajnosc;
            /**
 * Konstruktor domyslny klasy
 */
    Kilof(){
        super();
        wydajnosc=(int)(Math.random() * ((3-1) + 1))+1;
    }
            /**
 * Konstruktor klasy z zadana jako parametr wydajnoscia kilofa
 */
    Kilof(int wydajnosc){
        super();
        this.wydajnosc=wydajnosc;
    }
    
    /** 
     * Interakcja podnoszenia kilofa
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok, int x, int y) {
        int i=0;
        while(i<5&&ok.ekwipunek[i]!=null){
            i++;
        }if(i<5){
        ok.ekwipunek[i]=new Kilof(wydajnosc);
        ok.plansza[x][y]=new Puste(true);
    }}
}