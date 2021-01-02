/**
 * Klasa opisująca przedmiot
 */
public class Przedmiot extends Pole{
    int uzycia;
        /**
 * Konstruktor domyslny klasy
 */
    Przedmiot(){
        super();
        this.uzycia=3;
    }
    
    /** 
     * Interakcja podnoszenia przedmiotu
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok, int x, int y) {
        
    }
}