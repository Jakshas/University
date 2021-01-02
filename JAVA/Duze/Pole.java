/**
 * Klasa opisująca podstawowe pole na planszy
 */
public class Pole {
    boolean widocznosc;
    /**
 * Konstruktor domyslny klasy
 */
    Pole(){
        widocznosc=false;
    }
        /**
 * Konstruktor klasy który dostaje inforamcje o widocznosci i ja przypisuje
 */
    Pole(boolean widocznosc){
        this.widocznosc=widocznosc;
    }
    
    /** 
     * Interakcja z polem
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    public void interakcja(Okno ok,int x, int y){
        System.out.println("Błąd Pole");
    }
}