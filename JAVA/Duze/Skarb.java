import javax.swing.*;
/**
 * Klasa opisująca pole z skarbem
 */
public class Skarb extends Pole {
            /**
 * Konstruktor domyslny klasy
 */
    Skarb(){

    }
    
    /** 
     * Interakcja podnoszenia skarbu
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok, int x, int y) {
        //custom title, no icon
        JOptionPane.showMessageDialog(ok.frame,
        "Znalazłeś skarb. Wygrałeś/aś",
        "Koniec gry",
        JOptionPane.PLAIN_MESSAGE);
        System.exit(0);
    }
}