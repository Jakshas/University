/**
 * Klasa opisująca pole z scianą
 */
public class Sciana extends Pole{
    int wytrzymalosc;
            /**
 * Konstruktor domyslny klasy
 */
    public Sciana(){
        super();
        wytrzymalosc=((int)Math.random()%5)+1;
    }
    
    /** 
     * Interakcja z sciana
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok,int x, int y) {
        if(x==0||y==0||x==19||y==19){
        }else{
            int o=ok.szukajki();
            if(o>0){
                wytrzymalosc=-o;
            }
            if(wytrzymalosc<=0){
                ok.plansza[x][y]=new Puste();
            }
        }
    }
}