import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.Timer;
import javax.swing.border.Border;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.*;
public class Okno {
    
    Sluchacze sl;
    Logika logika;
    JFrame frame;
    JPanel plansza;
    JPanel pola[][];
    int n,m;

    Okno(int n,int m){
        this.n=n;
        this.m=m;
        sl = new Sluchacze(this);
        logika = new Logika(n,m,this);
        frame = new JFrame();
        plansza = new JPanel();
        plansza.setLayout(new GridLayout(n,m));
        pola = new JPanel[n][m];
        Border blackline = BorderFactory.createLineBorder(Color.black);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pola[i][j] = new JPanel();
                pola[i][j].setBorder(blackline);
                plansza.add(pola[i][j]);
            }
        }
        wypisz();
        frame.addKeyListener(sl);
        frame.add(plansza);
        frame.setSize(n*50,m*50);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);  
        int delay = 200; //milliseconds
        ActionListener taskPerformer = new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                wypisz();
            }
        };
        new Timer(delay, taskPerformer).start();
    }

    void wypisz(){
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pola[j][i].setBackground(Color.white);
                if (logika.mikolaj[0]==j && logika.mikolaj[1]==i) {
                    pola[j][i].setBackground(Color.RED);
                }
                int d = logika.czydziecko(j, i);
                if (d == 1){
                    pola[j][i].setBackground(Color.blue);
                }
                if (d == 2){
                    pola[j][i].setBackground(Color.lightGray);
                }
                if (d == 3){
                    pola[j][i].setBackground(Color.black);
                }
            }
        }
        if (logika.iledzieci==0) {
            JOptionPane.showMessageDialog(frame,
            "Wygrałes");
            System.exit(0);
        }
    }
}
