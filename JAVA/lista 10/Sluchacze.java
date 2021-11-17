import java.awt.event.*;

import javax.swing.JOptionPane;

public class Sluchacze implements KeyListener {

    Okno ok;

    Sluchacze(Okno o){
        ok = o;
    }

    @Override
    public void keyTyped(KeyEvent e) {
        // TODO Auto-generated method stub

    }

    @Override
    public void keyPressed(KeyEvent e) {
        if (e.getKeyChar()=='w') {
            int x=(ok.logika.mikolaj[0]-1+ok.n)%ok.n;
            if (ok.logika.czydziecko(x, ok.logika.mikolaj[1]) == 1) {
                JOptionPane.showMessageDialog(ok.frame,
                "Przegrałeś");
                System.exit(0);
            }
            if (ok.logika.czydziecko(x, ok.logika.mikolaj[1]) == 2) {
                ok.logika.iledzieci= ok.logika.iledzieci-1;
                ok.logika.dzieci[ok.logika.ktoredziecko(x, ok.logika.mikolaj[1])][2]=3;
            }
            if (ok.logika.czydziecko(x, ok.logika.mikolaj[1]) == 0) {
                ok.logika.mikolaj[0] = x;
            }
        }
        if (e.getKeyChar()=='s') {
            int x = (ok.logika.mikolaj[0]+1+ok.n)%ok.n;
            if (ok.logika.czydziecko(x, ok.logika.mikolaj[1]) == 1) {
                JOptionPane.showMessageDialog(ok.frame,
                "Przegrałeś");
                System.exit(0);
            }
            if (ok.logika.czydziecko(x, ok.logika.mikolaj[1]) == 2) {
                ok.logika.iledzieci= ok.logika.iledzieci-1;
                ok.logika.dzieci[ok.logika.ktoredziecko(x, ok.logika.mikolaj[1])][2]=3;
            }
            if (ok.logika.czydziecko(x, ok.logika.mikolaj[1]) == 0) {
                ok.logika.mikolaj[0] = x;
            }
        }
        if (e.getKeyChar()=='a') {
            int y = (ok.logika.mikolaj[1]-1+ok.m)%ok.m;
            if (ok.logika.czydziecko(ok.logika.mikolaj[0], y) == 1) {
                JOptionPane.showMessageDialog(ok.frame,
                "Przegrałeś");
                System.exit(0);
            }
            if (ok.logika.czydziecko(ok.logika.mikolaj[0], y) == 2) {
                ok.logika.iledzieci= ok.logika.iledzieci-1;
                ok.logika.dzieci[ok.logika.ktoredziecko(ok.logika.mikolaj[0], y)][2]=3;
            }
            if (ok.logika.czydziecko(ok.logika.mikolaj[0], y) == 0) {
                ok.logika.mikolaj[1] = y;
            }
        }
        if (e.getKeyChar()=='d') {
            int y = (ok.logika.mikolaj[1]+1)%ok.m;
            if (ok.logika.czydziecko(ok.logika.mikolaj[0], y) == 1) {
                JOptionPane.showMessageDialog(ok.frame,
                "Przegrałeś");
                System.exit(0);
            }
            if (ok.logika.czydziecko(ok.logika.mikolaj[0], y) == 2) {
                ok.logika.iledzieci= ok.logika.iledzieci-1;
                ok.logika.dzieci[ok.logika.ktoredziecko(ok.logika.mikolaj[0], y)][2]=3;
            }
            if (ok.logika.czydziecko(ok.logika.mikolaj[0], y) == 0) {
                ok.logika.mikolaj[1] = y;
            }
        }
        ok.wypisz();
    }

    @Override
    public void keyReleased(KeyEvent e) {
        // TODO Auto-generated method stub

    }
    
}
