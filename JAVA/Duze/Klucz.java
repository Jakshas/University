/**
 * Klasa opisująca pole z kluczem
 */
public class Klucz extends Przedmiot{
    int rodzaj;
            /**
 * Konstruktor klasy z rodzajem
 */
    Klucz(int rodzaj){
        this.uzycia=1;
        this.rodzaj=rodzaj;
    }
    
    /** 
     * Interakcja podnoszenia klucza
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok, int x, int y) {
        int i=0;
        while(i<5&&ok.ekwipunek[i]!=null){
            i++;
        }
        if(i<5){
        ok.ekwipunek[i]=new Klucz(rodzaj);
        ok.plansza[x][y]=new Puste(true);
    }}
}