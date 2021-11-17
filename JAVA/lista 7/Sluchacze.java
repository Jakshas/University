import java.awt.Color;
import java.awt.event.*;

import javax.swing.JOptionPane;


public class Sluchacze implements ActionListener {

    Okno ok;

    Sluchacze(Okno o){
        ok=o;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==ok.nowa){
            if (ok.eu.isSelected()) {
                ok.jaka=0;
            }else{
                ok.jaka=1;
            }
            ok.l.uzupełnij();
            ok.planszar.repaint();
        }   
        if(e.getSource()==ok.koniec){
            System.exit(0);
        }
        if(e.getSource()==ok.ogrze){
            JOptionPane.showMessageDialog(ok.frame,
            "Celem gry jest zostawienie na planszy jak najmniejszej liczby pionków.\n Idealnym rozwiązaniem jest pozostawienie jednego pionka, najlepiej w centrum.\n Pionka bije się przeskakując go w pionie lub w poziomie.\n Nie można poruszać się na ukos oraz nie można bić kilku pionków w jednym ruchu.",
            "O grze",
                JOptionPane.PLAIN_MESSAGE);
        }
        if(e.getSource()==ok.oapp){
            JOptionPane.showMessageDialog(ok.frame,
            "Autor: Jakub Szajner \nWersja: 1.0 \nData powstania: 28.11.2020",
            "O aplikacji",
                JOptionPane.PLAIN_MESSAGE);
        }
        if(e.getSource()==ok.kol11){
            ok.planszar.tlo=Color.lightGray;
        }
        if(e.getSource()==ok.kol12){
            ok.planszar.tlo=Color.CYAN;
        }
        if(e.getSource()==ok.kol13){
            ok.planszar.tlo=new Color(102,255,102);
        }
        
        if(e.getSource()==ok.kol21){
            ok.planszar.pion=new Color(0 , 0 ,153);
        }
        if(e.getSource()==ok.kol22){
            ok.planszar.pion=Color.red;
        }
        if(e.getSource()==ok.kol23){
            ok.planszar.pion=new Color(102, 0 ,153);
        }
        if(e.getSource()==ok.kol31){
            ok.planszar.wyp=Color.blue;
        }
        if(e.getSource()==ok.kol32){
            ok.planszar.wyp=Color.orange;
        }
        if(e.getSource()==ok.kol33){
            ok.planszar.wyp=Color.GREEN;
        }
        if(e.getSource()==ok.left){
            ok.plansza[ok.zaznaczony[0]][ok.zaznaczony[1]]=false;
            ok.plansza[ok.zaznaczony[0]-1][ok.zaznaczony[1]]=false;
            ok.plansza[ok.zaznaczony[0]-2][ok.zaznaczony[1]]=true;
            ok.zaznaczony[0]=-1;
            ok.liczba--;
        }
        if(e.getSource()==ok.right){
            ok.plansza[ok.zaznaczony[0]][ok.zaznaczony[1]]=false;
            ok.plansza[ok.zaznaczony[0]+1][ok.zaznaczony[1]]=false;
            ok.plansza[ok.zaznaczony[0]+2][ok.zaznaczony[1]]=true;
            ok.zaznaczony[0]=-1;
            ok.liczba--;
        }
        if(e.getSource()==ok.up){
            ok.plansza[ok.zaznaczony[0]][ok.zaznaczony[1]]=false;
            ok.plansza[ok.zaznaczony[0]][ok.zaznaczony[1]-1]=false;
            ok.plansza[ok.zaznaczony[0]][ok.zaznaczony[1]-2]=true;
            ok.zaznaczony[0]=-1;
            ok.liczba--;
        }
        if(e.getSource()==ok.down){
            ok.plansza[ok.zaznaczony[0]][ok.zaznaczony[1]]=false;
            ok.plansza[ok.zaznaczony[0]][ok.zaznaczony[1]+1]=false;
            ok.plansza[ok.zaznaczony[0]][ok.zaznaczony[1]+2]=true;
            ok.zaznaczony[0]=-1;
            ok.liczba--;
        }
        if (e.getSource()==ok.usun) {
            ok.zaznaczony[0]=-1;
        }
        ok.etykieta.setText("Pozostało "+ok.liczba+" pionków");
        ok.l.sprruchy();
        ok.planszar.repaint();
    }
    
}
