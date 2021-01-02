import javax.swing.*;
/**
 * Klasa opisująca pole z strarznikiem
 */
public class Straznik extends Pole{
    public int zdrowie;
    public boolean ruch;
            /**
 * Konstruktor domyslny klasy
 */
    Straznik(){
        zdrowie=5;
        ruch=true;
    }
    
    /** 
     * Interakcja z straznikiem
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    @Override
    public void interakcja(Okno ok, int x, int y) {
        int o;
            if(0<(o=ok.szukajm())){
                ((Straznik)ok.plansza[x][y]).zdrowie=((Straznik)ok.plansza[x][y]).zdrowie-o;
        }else{
            ((Straznik)ok.plansza[x][y]).zdrowie=((Straznik)ok.plansza[x][y]).zdrowie-1;
        }
        if(((Straznik)ok.plansza[x][y]).zdrowie<=0){
            ok.plansza[x][y]=new Puste(true);
        }
    }
    
    /** 
     * Wykonanie ruchu przez strarznika
     * @param ok Klasa Okna które posiada dane o planszy
     * @param x Wartość x pola na którym znajduje sie gracz
     * @param y Wartość y pola na którym znajduje sie gracz
     */
    public void ruch(Okno ok, int x, int y) {
        if((ok.ruchy%2)==0){
        if(ok.plansza[x-1][y] instanceof Gracz){
            ((Gracz)ok.plansza[x-1][y]).zdrowie=((Gracz)ok.plansza[x-1][y]).zdrowie-(int)(Math.random() * (10)+10);
            ok.zdrowie.setText("Zdrowie Gracza "+((Gracz)ok.plansza[ok.x][ok.y]).zdrowie);
            ((Straznik)ok.plansza[x][y]).ruch=false;
            if(((Gracz)ok.plansza[ok.x][ok.y]).zdrowie<=0){
            JOptionPane.showMessageDialog(ok.frame,
            "Zostałeś zabity. Przegrałeś/aś",
            "Koniec gry",
            JOptionPane.PLAIN_MESSAGE);
            System.exit(0);
            }
            return;
        }
        if(ok.plansza[x+1][y] instanceof Gracz){
            ((Gracz)ok.plansza[x+1][y]).zdrowie=((Gracz)ok.plansza[x+1][y]).zdrowie-(int)(Math.random() * (10)+10);;
            ok.zdrowie.setText("Zdrowie Gracza "+((Gracz)ok.plansza[ok.x][ok.y]).zdrowie);
            ((Straznik)ok.plansza[x][y]).ruch=false;
            if(((Gracz)ok.plansza[ok.x][ok.y]).zdrowie<=0){
                JOptionPane.showMessageDialog(ok.frame,
                "Zostałeś zabity. Przegrałeś/aś",
                "Koniec gry",
                JOptionPane.PLAIN_MESSAGE);
                System.exit(0);
                }
            return;
        }
        if(ok.plansza[x][y-1] instanceof Gracz){
            ((Gracz)ok.plansza[x][y-1]).zdrowie=((Gracz)ok.plansza[x][y-1]).zdrowie-(int)(Math.random() * (10)+10);;
            ok.zdrowie.setText("Zdrowie Gracza "+((Gracz)ok.plansza[ok.x][ok.y]).zdrowie);
            ((Straznik)ok.plansza[x][y]).ruch=false;
            if(((Gracz)ok.plansza[ok.x][ok.y]).zdrowie<=0){
                JOptionPane.showMessageDialog(ok.frame,
                "Zostałeś zabity. Przegrałeś/aś",
                "Koniec gry",
                JOptionPane.PLAIN_MESSAGE);
                System.exit(0);
                }
            return;
        }
        if(ok.plansza[x][y+1] instanceof Gracz){
            ((Gracz)ok.plansza[x][y+1]).zdrowie=((Gracz)ok.plansza[x][y+1]).zdrowie-(int)(Math.random() * (10)+10);;
            ok.zdrowie.setText("Zdrowie Gracza "+((Gracz)ok.plansza[ok.x][ok.y]).zdrowie);
            ((Straznik)ok.plansza[x][y]).ruch=false;
            if(((Gracz)ok.plansza[ok.x][ok.y]).zdrowie<=0){
                JOptionPane.showMessageDialog(ok.frame,
                "Zostałeś zabity. Przegrałeś/aś",
                "Koniec gry",
                JOptionPane.PLAIN_MESSAGE);
                System.exit(0);
                }
            return;
        }
        if(x>2&&ok.plansza[x-2][y] instanceof Gracz&&ok.plansza[x-1][y] instanceof Puste){
            boolean wid=ok.plansza[x-1][y].widocznosc;
            ok.plansza[x-1][y]=ok.plansza[x][y];
            ok.plansza[x-1][y].widocznosc=wid;
            ok.plansza[x][y]=new Puste(ok.plansza[x][y].widocznosc);
            ((Straznik)ok.plansza[x-1][y]).ruch=false;
            return;
        }
        if(x<17&&ok.plansza[x+2][y] instanceof Gracz&&ok.plansza[x+1][y] instanceof Puste){
            boolean wid=ok.plansza[x+1][y].widocznosc;
            ok.plansza[x+1][y]=ok.plansza[x][y];
            ok.plansza[x+1][y].widocznosc=wid;
            ok.plansza[x][y]=new Puste(ok.plansza[x][y].widocznosc);
            ((Straznik)ok.plansza[x+1][y]).ruch=false;
            return;
        }
        if(y>2&&ok.plansza[x][y-2] instanceof Gracz&&ok.plansza[x][y-1] instanceof Puste){
            boolean wid=ok.plansza[x][y-1].widocznosc;
            ok.plansza[x][y-1]=ok.plansza[x][y];
            ok.plansza[x][y-1].widocznosc=wid;
            ok.plansza[x][y]=new Puste(ok.plansza[x][y].widocznosc);
            ((Straznik)ok.plansza[x][y-1]).ruch=false;
            return;
        }
        if(y<17&&ok.plansza[x][y+2] instanceof Gracz&&ok.plansza[x][y+1] instanceof Puste){
            boolean wid=ok.plansza[x][y+1].widocznosc;
            ok.plansza[x][y+1]=ok.plansza[x][y];
            ok.plansza[x][y+1].widocznosc=wid;
            ok.plansza[x][y]=new Puste(ok.plansza[x][y].widocznosc);
            ((Straznik)ok.plansza[x][y+1]).ruch=false;
            return;
        }
        boolean ruche=false;
        int rn;
        if(!(ok.plansza[x+1][y] instanceof Puste)){
            if(!(ok.plansza[x-1][y] instanceof Puste)){
                if(!(ok.plansza[x][y-1] instanceof Puste)){
                    if(!(ok.plansza[x][y+1] instanceof Puste)){
                        ruche=true;
                    }
                }
            }
        }
        while(!ruche){
        rn=(int)(Math.random() * (4));
        if(rn==0){
            if(ok.plansza[x-1][y] instanceof Puste){
                boolean wid=ok.plansza[x-1][y].widocznosc;
                boolean widpol=ok.plansza[x][y].widocznosc;
                ok.plansza[x-1][y]=ok.plansza[x][y];
                ok.plansza[x-1][y].widocznosc=wid;
                ok.plansza[x][y]=new Puste(widpol);
                ruche=true;
                ((Straznik)ok.plansza[x-1][y]).ruch=false;
                return;
            }
        }
        if(rn==1){
            if(ok.plansza[x+1][y] instanceof Puste){
                boolean wid=ok.plansza[x+1][y].widocznosc;
                boolean widpol=ok.plansza[x][y].widocznosc;
                ok.plansza[x+1][y]=ok.plansza[x][y];
                ok.plansza[x+1][y].widocznosc=wid;
                ok.plansza[x][y]=new Puste(widpol);
                ruche=true;
                ((Straznik)ok.plansza[x+1][y]).ruch=false;
                return;
            }
        }if(rn==2){
            if(ok.plansza[x][y-1] instanceof Puste){
                boolean wid=ok.plansza[x][y-1].widocznosc;
                boolean widpol=ok.plansza[x][y].widocznosc;
                ok.plansza[x][y-1]=ok.plansza[x][y];
                ok.plansza[x][y-1].widocznosc=wid;
                ok.plansza[x][y]=new Puste(widpol);
                ruche=true;
                ((Straznik)ok.plansza[x][y-1]).ruch=false;
                return;
            }
        }if(rn==3){
            if(ok.plansza[x][y+1] instanceof Puste){
                boolean wid=ok.plansza[x][y+1].widocznosc;
                boolean widpol=ok.plansza[x][y].widocznosc;
                ok.plansza[x][y+1]=ok.plansza[x][y];
                ok.plansza[x][y+1].widocznosc=wid;
                ok.plansza[x][y]=new Puste(widpol);
                ruche=true;
                ((Straznik)ok.plansza[x][y+1]).ruch=false;
                return;
            }
        }

    }
    }}
}