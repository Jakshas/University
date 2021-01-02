/**
 * Klasa opisująca pole z mieczem
 */
public class Miecz extends Przedmiot{
    int obrazenia;
            /**
 * Konstruktor domyslny klasy
 */
    Miecz(){
        super();
        obrazenia=(int)(Math.random() * ((3-2) + 1))+2;
    }
            /**
 * Konstruktor klasy z zadanymi jako poarametr obrzniemai miecza
 */
    Miecz(int obrazenia){
        super();
        this.obrazenia=obrazenia;
    }
    Miecz(int obrazenia,int uzycia){
        super();
        this.obrazenia=obrazenia;
        this.uzycia=uzycia;
    }
    
    /** 
     * Interakcja podnoszenia miecza
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
        ok.ekwipunek[i]=new Miecz(obrazenia);
        ok.plansza[x][y]=new Puste(true);
    }}
}