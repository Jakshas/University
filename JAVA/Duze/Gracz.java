/**
 * Klasa opisująca pole z graczem
 */
public class Gracz extends Pole{
    int zdrowie;
            /**
 * Konstruktor domyslny klasy
 */
    Gracz(){
        super(true);
        this.zdrowie=100;
    }
    
    /** 
     * Interakcja z innym graczem
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok,int x, int y) {
        System.out.println("gracz");
    }
}