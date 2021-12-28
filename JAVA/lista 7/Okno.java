import javax.swing.AbstractAction;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JPopupMenu;
import javax.swing.JRadioButtonMenuItem;
import javax.swing.KeyStroke;

import java.awt.event.*;
import java.awt.*;

public class Okno {
    JFrame frame;
    boolean plansza[][]= new boolean[7][7];
    int jaka=0;
    int zaznaczony[]= {-1,-1};
    Rysowanka planszar;
    JMenuBar menu;
    JLabel etykieta;
    int liczba;
    JPanel panel;

    private MouseListener mouseList = new MouseAdapter()
    {
        @Override
        public void mouseClicked(MouseEvent ev)
        {

            int x = ev.getX();
            int y = ev.getY();
            int x1= x/planszar.rozmiar;
            int y1= y/planszar.rozmiar;
            if(!planszar.sprawdzpl(x1, y1)){
                return;
            }
            if (zaznaczony[0]==-1 && plansza[x1][y1]==true) {
                zaznaczony[0]=x1;
                zaznaczony[1]=y1;
            }else{
                if (zaznaczony[0]==x1 && zaznaczony[1]==y1) {
                    zaznaczony[0]=-1;
                }else{
                    if(l.czyruch(x1,y1)){
                        zaznaczony[0]=-1;
                        liczba--;
                        etykieta.setText("Pozostało "+liczba+" pionków");
                    }else{
                    }
                }
            }
            l.sprruchy();
            if(ev.getButton()==MouseEvent.BUTTON3 && x1==zaznaczony[0] && y1==zaznaczony[1]){
                l.menupopup(ev,x1,y1);

            }
            planszar.repaint();
        }
    };

    // public void menupopup(MouseEvent ev,int x, int y) {
    //     JPopupMenu popMenu = new JPopupMenu();
    //     if (x-2>=0 && plansza[x-1][y] && !plansza[x-2][y] && planszar.sprawdzpl(x-2, y)) {
    //         popMenu.add(new JMenuItem(new AbstractAction("W lewo") {
    //             @Override
    //             public void actionPerformed(ActionEvent e) {
    //                 plansza[x-2][y]=true;
    //                 plansza[x-1][y]=false;
    //                 plansza[x][y]=false;
    //                 zaznaczony[0]=-1;
    //                 planszar.repaint();
    //                 liczba--;
    //                 if(liczba>1){
    //                     etykieta.setText("Pozostało "+liczba+" pionków");
    //                 }else
    //                 {
    //                     etykieta.setText("Wygrałeś");
    //                 }
                    
    //             }
    //         }));
    //     }
    //     if (x+2<=6 && plansza[x+1][y] && !plansza[x+2][y] && planszar.sprawdzpl(x+2, y)) {
    //         popMenu.add(new JMenuItem(new AbstractAction("W prawo") {
    //             @Override
    //             public void actionPerformed(ActionEvent e) {
    //                 plansza[x+2][y]=true;
    //                 plansza[x+1][y]=false;
    //                 plansza[x][y]=false;
    //                 zaznaczony[0]=-1;
    //                 planszar.repaint();
    //                 liczba--;
    //                 etykieta.setText("Pozostało "+liczba+" pionków");
    //             }
    //         }));
    //     }
    //     if (y-2>=0 && plansza[x][y-1] && !plansza[x][y-2] && planszar.sprawdzpl(x, y-2)) {
    //         popMenu.add(new JMenuItem(new AbstractAction("W góre") {
    //             @Override
    //             public void actionPerformed(ActionEvent e) {
    //                 plansza[x][y-2]=true;
    //                 plansza[x][y-1]=false;
    //                 plansza[x][y]=false;
    //                 zaznaczony[0]=-1;
    //                 planszar.repaint();
    //                 liczba--;
    //                 etykieta.setText("Pozostało "+liczba+" pionków");
    //             }
    //         }));
    //     }
    //     if (y+2<=6 && plansza[x][y+1] && !plansza[x][y+2] && planszar.sprawdzpl(x, y+2)) {
    //         popMenu.add(new JMenuItem(new AbstractAction("W dół") {
    //             @Override
    //             public void actionPerformed(ActionEvent e) {
    //                 plansza[x][y+2]=true;
    //                 plansza[x][y+1]=false;
    //                 plansza[x][y]=false;
    //                 zaznaczony[0]=-1;
    //                 planszar.repaint();
    //                 liczba--;
    //                 etykieta.setText("Pozostało "+liczba+" pionków");
    //             }
    //         }));
    //     }
    //     popMenu.show(ev.getComponent(), ev.getX(), ev.getY());
    // }

    // public boolean czyruch(int x, int y){
    //     if (!plansza[x][y]) {
    //         if (zaznaczony[0]==x-2 && zaznaczony[1]==y && plansza[x-1][y]) {
    //             plansza[zaznaczony[0]][zaznaczony[1]]=false;
    //             plansza[x-1][y]=false;
    //             plansza[x][y]=true;
    //             zaznaczony[0]=-1;
    //             return true;
    //         }
    //         if (zaznaczony[0]==x+2 && zaznaczony[1]==y && plansza[x+1][y]) {
    //             plansza[zaznaczony[0]][zaznaczony[1]]=false;
    //             plansza[x+1][y]=false;
    //             plansza[x][y]=true;
    //             zaznaczony[0]=-1;
    //             return true;
    //         }
    //         if (zaznaczony[0]==x && zaznaczony[1]==y-2 && plansza[x][y-1]) {
    //             plansza[zaznaczony[0]][zaznaczony[1]]=false;
    //             plansza[x][y-1]=false;
    //             plansza[x][y]=true;
    //             zaznaczony[0]=-1;
    //             return true;
    //         }
    //         if (zaznaczony[0]==x && zaznaczony[1]==y+2 && plansza[x][y+1]) {
    //             plansza[zaznaczony[0]][zaznaczony[1]]=false;
    //             plansza[x][y+1]=false;
    //             plansza[x][y]=true;
    //             zaznaczony[0]=-1;
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    Logika l;
    Okno(){
        l= new Logika(this);
        l.uzupełnij();
        if (jaka==0) {
            liczba=36;
        }else{
            liczba=32;
        }
        frame=new JFrame("Gra");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(new BorderLayout());
        menu= new JMenuBar();
        menu();
        frame.add(menu , BorderLayout.NORTH);
        panel= new JPanel();
        planszar= new Rysowanka(this);
        panel.add(planszar);
        planszar.repaint();
        frame.add(panel, BorderLayout.CENTER);
        etykieta=new JLabel();
        etykieta.setText("Pozostało "+liczba+" pionków");
        frame.add(etykieta, BorderLayout.SOUTH);
        frame.setSize(320, 450);
        planszar.addMouseListener(mouseList);
        planszar.setFocusable(true);
        planszar.requestFocus();

        frame.addComponentListener(new ComponentAdapter() {
            @Override
            public void componentResized(ComponentEvent e) {
                int wartosc= Math.min(frame.getContentPane().getHeight()/100*85, frame.getContentPane().getWidth());
                planszar.rozmiar=wartosc/7;
                planszar.setSize(wartosc+1, wartosc+1);
                planszar.repaint();
            }
          });
        frame.setVisible(true);
    }

    JMenu  gra,ruchy,ustawienia,pomoc,kolpi,kolpl,kolwyp; 
    JMenuItem nowa, koniec,ogrze,oapp,kol11,kol12,kol13,kol21,kol22,kol23,kol31,kol32,kol33,up,down,left,right,usun;
    JRadioButtonMenuItem eu;

    public void menu() {
        nowa=new JMenuItem("Nowa",'N');
        koniec=new JMenuItem("Koniec",'K');
        gra=new JMenu("Gra");
        nowa.addActionListener(new Sluchacze(this));
        koniec.addActionListener(new Sluchacze(this));
        gra.add(nowa);
        gra.addSeparator();
        gra.add(koniec);
        menu.add(gra);
        ruchy();
        ustawienia= new JMenu("Ustawienia");
        ButtonGroup grupa= new ButtonGroup();
        eu = new JRadioButtonMenuItem("Europejska");
        eu.setSelected(true);
        JRadioButtonMenuItem en = new JRadioButtonMenuItem("Angielska");
        grupa.add(eu);
        grupa.add(en);
        ustawienia.add(eu);
        ustawienia.add(en);
        kolory();
        menu.add(ustawienia);
        pomoc= new JMenu("Pomoc");
        ogrze=new JMenuItem("O grze");
        oapp=new JMenuItem("O aplikacji");
        ogrze.addActionListener(new Sluchacze(this));
        oapp.addActionListener(new Sluchacze(this));
        pomoc.add(ogrze);
        pomoc.add(oapp);
        menu.add(pomoc);
    }

    public void ruchy(){
        ruchy= new JMenu("Ruchy");
        up=new JMenuItem("Góra");
        down=new JMenuItem("Dół");
        left=new JMenuItem("Lewo");
        right=new JMenuItem("Prawo");
        usun=new JMenuItem("Usuń");
        up.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_W,0));
        down.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S,0));
        left.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_A,0));
        right.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_D,0));
        usun.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_E,0));
        l.sprruchy();
        up.addActionListener(new Sluchacze(this));
        down.addActionListener(new Sluchacze(this));
        left.addActionListener(new Sluchacze(this));
        right.addActionListener(new Sluchacze(this));
        usun.addActionListener(new Sluchacze(this));
        ruchy.add(up);
        ruchy.add(down);
        ruchy.add(left);
        ruchy.add(right);
        ruchy.add(usun);
        menu.add(ruchy);
    }

    // public void sprruchy(){
    //     if (zaznaczony[0]==-1) {
    //         up.setEnabled(false);
    //         down.setEnabled(false);
    //         left.setEnabled(false);
    //         right.setEnabled(false);
    //     }else{
    //         if (zaznaczony[0]-2>=0 && plansza[zaznaczony[0]-1][zaznaczony[1]] && !plansza[zaznaczony[0]-2][zaznaczony[1]] && planszar.sprawdzpl(zaznaczony[0]-2, zaznaczony[1])) {
    //             left.setEnabled(true);
    //         }
    //         if (zaznaczony[0]+2<=6 && plansza[zaznaczony[0]+1][zaznaczony[1]] && !plansza[zaznaczony[0]+2][zaznaczony[1]] && planszar.sprawdzpl(zaznaczony[0]+2, zaznaczony[1])) {
    //             right.setEnabled(true);
    //         }
    //         if (zaznaczony[1]-2>=0 && plansza[zaznaczony[0]][zaznaczony[1]-1] && !plansza[zaznaczony[0]][zaznaczony[1]-2] && planszar.sprawdzpl(zaznaczony[0], zaznaczony[1]-2)) {
    //             up.setEnabled(true);
    //         }
    //         if (zaznaczony[1]+2<=6 && plansza[zaznaczony[0]][zaznaczony[1]+1] && !plansza[zaznaczony[0]][zaznaczony[1]+2] && planszar.sprawdzpl(zaznaczony[0], zaznaczony[1]+2)) {
    //             down.setEnabled(true);
    //         }
    //     }
    // }

    public void kolory() {
        kolpi=new JMenu("Kolor pionów");
        kolpl=new JMenu("Kolor planszy");
        kolwyp=new JMenu("Kolor wypełnienia");
        kol11=new JMenuItem("Jasnoszary");
        kol12=new JMenuItem("Jasnoniebieski");
        kol13=new JMenuItem("Jasnozielony");
        kol21=new JMenuItem("Ciemnoniebieski");
        kol22=new JMenuItem("Czerowny");
        kol23=new JMenuItem("Fioletowy");
        kol31=new JMenuItem("Niebieski");
        kol32=new JMenuItem("Pomarańczowy");
        kol33=new JMenuItem("Zielony");
        kolpi.add(kol21);
        kolpi.add(kol22);
        kolpi.add(kol23);
        kolpl.add(kol11);
        kolpl.add(kol12);
        kolpl.add(kol13);
        kolwyp.add(kol31);
        kolwyp.add(kol32);
        kolwyp.add(kol33);
        kol11.addActionListener(new Sluchacze(this));
        kol12.addActionListener(new Sluchacze(this));
        kol13.addActionListener(new Sluchacze(this));
        kol21.addActionListener(new Sluchacze(this));
        kol22.addActionListener(new Sluchacze(this));
        kol23.addActionListener(new Sluchacze(this));
        kol31.addActionListener(new Sluchacze(this));
        kol32.addActionListener(new Sluchacze(this));
        kol33.addActionListener(new Sluchacze(this));
        ustawienia.add(kolpi);
        ustawienia.add(kolpl);
        ustawienia.add(kolwyp);
    }

    // void uzupełnij(){
    //         for (int i = 0; i < plansza.length; i++) {
    //             for (int j = 0; j < plansza.length; j++) {
    //                 plansza[i][j]=true;
    //             }
    //         }
    //         if (jaka==0) {
    //             plansza[0][0]=false;
    //             plansza[1][0]=false;
    //             plansza[0][1]=false;
    //             plansza[6][6]=false;
    //             plansza[6][5]=false;
    //             plansza[5][6]=false;
    //             plansza[0][6]=false;
    //             plansza[1][6]=false;
    //             plansza[0][5]=false;
    //             plansza[6][0]=false;
    //             plansza[5][0]=false;
    //             plansza[6][1]=false;
    //             plansza[3][3]=false;
    //     }else{
    //         for(int i=0;i<2;i++){
    //             for(int j=0;j<2;j++){
    //             plansza[0+i][0+j]=false;
    //             plansza[6-i][6-j]=false;
    //             plansza[0+i][6-j]=false;
    //             plansza[6-j][0+i]=false;
    //             }
    //         }
    //         plansza[3][3]=false;
    //     }
    // }
}