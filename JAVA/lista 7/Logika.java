import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Logika {
    Okno o;

    Logika(Okno o){
        this.o=o;
    }

    public boolean czyruch(int x, int y){
        if (!o.plansza[x][y]) {
            if (o.zaznaczony[0]==x-2 && o.zaznaczony[1]==y && o.plansza[x-1][y]) {
                o.plansza[o.zaznaczony[0]][o.zaznaczony[1]]=false;
                o.plansza[x-1][y]=false;
                o.plansza[x][y]=true;
                o.zaznaczony[0]=-1;
                return true;
            }
            if (o.zaznaczony[0]==x+2 && o.zaznaczony[1]==y && o.plansza[x+1][y]) {
                o.plansza[o.zaznaczony[0]][o.zaznaczony[1]]=false;
                o.plansza[x+1][y]=false;
                o.plansza[x][y]=true;
                o.zaznaczony[0]=-1;
                return true;
            }
            if (o.zaznaczony[0]==x && o.zaznaczony[1]==y-2 && o.plansza[x][y-1]) {
                o.plansza[o.zaznaczony[0]][o.zaznaczony[1]]=false;
                o.plansza[x][y-1]=false;
                o.plansza[x][y]=true;
                o.zaznaczony[0]=-1;
                return true;
            }
            if (o.zaznaczony[0]==x && o.zaznaczony[1]==y+2 && o.plansza[x][y+1]) {
                o.plansza[o.zaznaczony[0]][o.zaznaczony[1]]=false;
                o.plansza[x][y+1]=false;
                o.plansza[x][y]=true;
                o.zaznaczony[0]=-1;
                return true;
            }
        }
        return false;
    }
    
    public void menupopup(MouseEvent ev,int x, int y) {
        JPopupMenu popMenu = new JPopupMenu();
        if (x-2>=0 && o.plansza[x-1][y] && !o.plansza[x-2][y] && o.planszar.sprawdzpl(x-2, y)) {
            popMenu.add(new JMenuItem(new AbstractAction("W lewo") {
                @Override
                public void actionPerformed(ActionEvent e) {
                    o.plansza[x-2][y]=true;
                    o.plansza[x-1][y]=false;
                    o.plansza[x][y]=false;
                    o.zaznaczony[0]=-1;
                    o.planszar.repaint();
                    o.liczba--;
                    if(o.liczba>1){
                        o.etykieta.setText("Pozostało "+o.liczba+" pionków");
                    }else
                    {
                        o.etykieta.setText("Wygrałeś");
                    }
                    
                }
            }));
        }
        if (x+2<=6 && o.plansza[x+1][y] && !o.plansza[x+2][y] && o.planszar.sprawdzpl(x+2, y)) {
            popMenu.add(new JMenuItem(new AbstractAction("W prawo") {
                @Override
                public void actionPerformed(ActionEvent e) {
                    o.plansza[x+2][y]=true;
                    o.plansza[x+1][y]=false;
                    o.plansza[x][y]=false;
                    o.zaznaczony[0]=-1;
                    o.planszar.repaint();
                    o.liczba--;
                    o.etykieta.setText("Pozostało "+o.liczba+" pionków");
                }
            }));
        }
        if (y-2>=0 && o.plansza[x][y-1] && !o.plansza[x][y-2] && o.planszar.sprawdzpl(x, y-2)) {
            popMenu.add(new JMenuItem(new AbstractAction("W góre") {
                @Override
                public void actionPerformed(ActionEvent e) {
                    o.plansza[x][y-2]=true;
                    o.plansza[x][y-1]=false;
                    o.plansza[x][y]=false;
                    o.zaznaczony[0]=-1;
                    o.planszar.repaint();
                    o.liczba--;
                    o.etykieta.setText("Pozostało "+o.liczba+" pionków");
                }
            }));
        }
        if (y+2<=6 && o.plansza[x][y+1] && !o.plansza[x][y+2] && o.planszar.sprawdzpl(x, y+2)) {
            popMenu.add(new JMenuItem(new AbstractAction("W dół") {
                @Override
                public void actionPerformed(ActionEvent e) {
                    o.plansza[x][y+2]=true;
                    o.plansza[x][y+1]=false;
                    o.plansza[x][y]=false;
                    o.zaznaczony[0]=-1;
                    o.planszar.repaint();
                    o.liczba--;
                    o.etykieta.setText("Pozostało "+o.liczba+" pionków");
                }
            }));
        }
        popMenu.show(ev.getComponent(), ev.getX(), ev.getY());
    }
    public void sprruchy(){
        if (o.zaznaczony[0]==-1) {
            o.up.setEnabled(false);
            o.down.setEnabled(false);
            o.left.setEnabled(false);
            o.right.setEnabled(false);
        }else{
            if (o.zaznaczony[0]-2>=0 && o.plansza[o.zaznaczony[0]-1][o.zaznaczony[1]] && !o.plansza[o.zaznaczony[0]-2][o.zaznaczony[1]] && o.planszar.sprawdzpl(o.zaznaczony[0]-2, o.zaznaczony[1])) {
                o.left.setEnabled(true);
            }
            if (o.zaznaczony[0]+2<=6 && o.plansza[o.zaznaczony[0]+1][o.zaznaczony[1]] && !o.plansza[o.zaznaczony[0]+2][o.zaznaczony[1]] && o.planszar.sprawdzpl(o.zaznaczony[0]+2, o.zaznaczony[1])) {
                o.right.setEnabled(true);
            }
            if (o.zaznaczony[1]-2>=0 && o.plansza[o.zaznaczony[0]][o.zaznaczony[1]-1] && !o.plansza[o.zaznaczony[0]][o.zaznaczony[1]-2] && o.planszar.sprawdzpl(o.zaznaczony[0], o.zaznaczony[1]-2)) {
                o.up.setEnabled(true);
            }
            if (o.zaznaczony[1]+2<=6 && o.plansza[o.zaznaczony[0]][o.zaznaczony[1]+1] && !o.plansza[o.zaznaczony[0]][o.zaznaczony[1]+2] && o.planszar.sprawdzpl(o.zaznaczony[0], o.zaznaczony[1]+2)) {
                o.down.setEnabled(true);
            }
        }
    }
    void uzupełnij(){
        for (int i = 0; i < o.plansza.length; i++) {
            for (int j = 0; j < o.plansza.length; j++) {
                o.plansza[i][j]=true;
            }
        }
        if (o.jaka==0) {
            o.plansza[0][0]=false;
            o.plansza[1][0]=false;
            o.plansza[0][1]=false;
            o.plansza[6][6]=false;
            o.plansza[6][5]=false;
            o.plansza[5][6]=false;
            o.plansza[0][6]=false;
            o.plansza[1][6]=false;
            o.plansza[0][5]=false;
            o.plansza[6][0]=false;
            o.plansza[5][0]=false;
            o.plansza[6][1]=false;
            o.plansza[3][3]=false;
    }else{
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
            o.plansza[0+i][0+j]=false;
            o.plansza[6-i][6-j]=false;
            o.plansza[0+i][6-j]=false;
            o.plansza[6-j][0+i]=false;
            }
        }
        o.plansza[3][3]=false;
    }
}
}
