/**
 * Klasa opisująca pole z drzwiami
 */
public class Drzwi extends Pole {
    int klucz;
        /**
         *  Konstruktor klasy z rodzajem klucza
         * @param klucz rodzaj klucza
 */
    public Drzwi(int klucz){
        super();
        this.klucz=klucz;
    }
    
    /** 
     * Interakcja z drzwiami
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok,int x, int y) {
        if(ok.szukajk(this.klucz)){
            ok.plansza[x][y]=new Puste(true);
        }
    }
}