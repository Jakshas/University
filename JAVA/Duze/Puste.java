/**
 * Klasa opisująca puste pole
 */
public class Puste extends Pole{
        /**
 * Konstruktor domyslny klasy
 */
    Puste(){
        
    }
            /**
 * Konstruktor klasy który dostaje inforamcje o widocznosci i ja przypisuje
 */
    Puste(boolean t){
        this.widocznosc=t;
    }
    
    /** 
     * Interakcja z pustym polem
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok, int x, int y) {
        if(ok.plansza[x-1][y] instanceof Gracz){
            ok.plansza[x][y]=ok.plansza[x - 1][y];
            ok.plansza[x-1][y]=new Puste();
            ok.x=x;
        }
        if(ok.plansza[x+1][y] instanceof Gracz){
            ok.plansza[x][y]=ok.plansza[x+ 1][y];
            ok.plansza[x+1][y]=new Puste();
            ok.x=x;
        }
        if(ok.plansza[x][y-1] instanceof Gracz){
            ok.plansza[x][y]=ok.plansza[x][y-1];
            ok.plansza[x][y-1]=new Puste();
            ok.y=y;
        }
        if(ok.plansza[x][y+1] instanceof Gracz){
            ok.plansza[x][y]=ok.plansza[x][y+1];
            ok.plansza[x][y+1]=new Puste();
            ok.y=y;
        }
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                ok.plansza[x+i][y+j].widocznosc=true;
            }
        }
    }
}