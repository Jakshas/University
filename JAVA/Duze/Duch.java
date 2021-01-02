/**
 * Klasa opisująca pole z duchem
 */
public class Duch extends Pole{
            /**
 * Konstruktor domyslny klasy
 */
    Duch(){
        super();
    }
    
    /** 
     * Interakcja z duchem
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok, int x, int y) {
        int nx=0;
        int ny=0;
        do{
            nx=(int)(Math.random() * (19 - 0 + 1) + 0);
            ny=(int)(Math.random() * (19 - 0 + 1) + 0);
        }while(!(ok.plansza[nx][ny] instanceof Puste));

        if(ok.plansza[x-1][y] instanceof Gracz){
            ((Gracz)ok.plansza[x-1][y]).zdrowie=((Gracz)ok.plansza[x-1][y]).zdrowie-(((Gracz)ok.plansza[x-1][y]).zdrowie/3);
            ok.zdrowie.setText("Zdrowie Gracza "+((Gracz)ok.plansza[ok.x][ok.y]).zdrowie);
            ok.plansza[nx][ny]=ok.plansza[x - 1][y];
            ok.plansza[x-1][y]=new Puste(true);
            ok.x=x;
        }
        if(ok.plansza[x+1][y] instanceof Gracz){
            ((Gracz)ok.plansza[x+1][y]).zdrowie=((Gracz)ok.plansza[x+1][y]).zdrowie-(((Gracz)ok.plansza[x+1][y]).zdrowie/3);
            ok.zdrowie.setText("Zdrowie Gracza "+((Gracz)ok.plansza[ok.x][ok.y]).zdrowie);
            ok.plansza[nx][ny]=ok.plansza[x+ 1][y];
            ok.plansza[x+1][y]=new Puste(true);
            ok.x=x;
        }
        if(ok.plansza[x][y-1] instanceof Gracz){
            ((Gracz)ok.plansza[x][y-1]).zdrowie=((Gracz)ok.plansza[x][y-1]).zdrowie-(((Gracz)ok.plansza[x][y-1]).zdrowie/3);
            ok.zdrowie.setText("Zdrowie Gracza "+((Gracz)ok.plansza[ok.x][ok.y]).zdrowie);
            ok.plansza[nx][ny]=ok.plansza[x][y-1];
            ok.plansza[x][y-1]=new Puste(true);
            ok.y=y;
        }
        if(ok.plansza[x][y+1] instanceof Gracz){
            ((Gracz)ok.plansza[x][y+1]).zdrowie=((Gracz)ok.plansza[x][y+1]).zdrowie-(((Gracz)ok.plansza[x][y+1]).zdrowie/3);
            ok.zdrowie.setText("Zdrowie Gracza "+((Gracz)ok.plansza[ok.x][ok.y]).zdrowie);
            ok.plansza[nx][ny]=ok.plansza[x][y+1];
            ok.plansza[x][y+1]=new Puste(true);
            ok.y=y;
        }
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                ok.plansza[nx+i][ny+j].widocznosc=true;
            }
        }
        ok.x=nx;
        ok.y=ny;
        ok.plansza[x][y]= new Puste(true);
    }
}