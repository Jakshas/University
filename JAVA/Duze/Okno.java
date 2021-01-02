import java.awt.*;
import javax.swing.*;
/** 
 * Głowna klasa przechowujaca dane planszy jak i informacje o wyświetlanym oknie
*/
public class Okno{
    JLabel tab[][]= new JLabel[20][20];
    Pole plansza[][]={
{new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana() },
{new Sciana(), new Klucz(2), new Sciana(), new Kilof(), new Puste(), new Sciana(), new Miecz(), new Kilof(), new Puste(), new Puste(), new Puste(), new Sciana(), new Puste(), new Puste(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Skarb(), new Sciana() },
{new Sciana(), new Drzwi(1), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Kilof(5), new Sciana(), new Klucz(2), new Sciana(), new Drzwi(3), new Sciana() },
{new Sciana(), new Puste(), new Sciana(), new Puste(), new Puste(), new Sciana(), new Klucz(4), new Puste(), new Sciana(), new Puste(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Drzwi(2), new Sciana() },
{new Sciana(), new Puste(), new Sciana(), new Sciana(), new Duch(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Straznik(), new Sciana(), new Sciana(), new Drzwi(4), new Sciana(), new Puste(), new Puste(), new Puste(), new Puste(), new Straznik(), new Sciana() },
{new Sciana(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Sciana(), new Puste(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana() },
{new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Puste(), new Puste(), new Puste(), new Straznik(), new Sciana() },
{new Sciana(), new Puste(), new Puste(), new Puste(), new Puste(), new Straznik(), new Puste(), new Sciana(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana() },
{new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Puste(), new Puste(), new Sciana() },
{new Sciana(), new Puste(), new Puste(), new Puste(), new Sciana(), new Puste(), new Puste(), new Sciana(), new Puste(), new Puste(), new Puste(), new Puste(), new Sciana(), new Puste(), new Puste(), new Duch(), new Puste(), new Sciana(), new Puste(), new Sciana() },
{new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana() },
{new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Klucz(1), new Puste(), new Puste(), new Puste(), new Puste(), new Sciana(), new Puste(), new Puste(), new Sciana(), new Miecz(), new Sciana(), new Puste(), new Sciana() },
{new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana() },
{new Sciana(), new Straznik(), new Puste(), new Puste(), new Puste(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Puste(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Kilof(), new Puste(), new Puste(), new Sciana() },
{new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Miecz(), new Puste(), new Puste(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana() },
{new Sciana(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Puste(), new Puste(), new Sciana(), new Puste(), new Puste(), new Puste(), new Sciana() },
{new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Straznik(), new Miecz(3), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Straznik(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Sciana() },
{new Sciana(), new Puste(), new Sciana(), new Miecz(2), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Puste(), new Sciana(), new Klucz(3), new Sciana() },
{new Sciana(), new Puste(), new Duch(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Sciana(), new Puste(), new Puste(), new Puste(), new Puste(), new Puste(), new Drzwi(4), new Puste(), new Sciana() },
{new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana(), new Sciana() }};
    JLabel eq[]= new JLabel[5];
    Przedmiot ekwipunek[]=new Przedmiot[5];
    JFrame frame = new JFrame("Labirynt");
    Container kontenerg = frame.getContentPane();
    Container kontenerp = new Container();
    Container kontenere = new Container();
    Container kontenergr = new Container();
    Container kontenerz = new Container();
    JLabel zdrowie;
    /**
 * Zmienna x pola gracza
 */
    int x;
        /**
 * Zmienna y pola gracza
 */
    int y;
        /**
 * Liczba ruchów
 */
    int ruchy=0;
    {
    x=18;
    y=1;
    plansza[x][y]=new Gracz();
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            this.plansza[18+i][1+j].widocznosc=true;
         }  
       }
    zdrowie=new JLabel("Zdrowie Gracza "+((Gracz)plansza[x][y]).zdrowie);
    }
/**
 * Konstruktor klasy tworzy domyslną plansze
 */
    public Okno(){
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        kontenergr.setLayout(new GridLayout(4,1));
        kontenerg.setLayout(new FlowLayout());
        kontenerp.setLayout(new GridLayout(21,20));
        kontenere.setLayout(new GridLayout(1,5,1,1)); 
        for(int i=0;i<5;i++){
            this.ekwipunek[i]=null;
        }
        this.wypisz();
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                kontenerp.add(tab[j][i]); 
            }}
            for(int i=0;i<5;i++){
                kontenere.add(eq[i]);
            }
        Klawisz listener = new Klawisz(this);
        frame.addKeyListener(listener);
        frame.setFocusable(true);
        kontenerg.add(kontenerp);
        kontenerg.add(kontenergr);
        kontenergr.add(new JLabel("Ekwipunek"));
        kontenergr.add(kontenere);
        kontenergr.add(zdrowie);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);
        frame.setVisible(true);
    }
    /**
 * Funkcja wypisujaca plansze z obiektami klas jako ikony widoczne na planszy na poczatku
 */
    public void wypisz() {
        JLabel mo;
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(plansza[i][j].widocznosc){
                    switch (plansza[i][j].getClass().getName()) {
                        case "Sciana":
                        mo = new JLabel(new ImageIcon(getClass().getResource("x.jpg")));
                        tab[j][i]=mo;
                        break;
                        case "Gracz":
                        mo = new JLabel(new ImageIcon(getClass().getResource("B.jpg")));
                        tab[j][i]=mo;
                        break;
                        case "Drzwi":
                        if(((Drzwi)plansza[i][j]).klucz==1){
                            mo = new JLabel(new ImageIcon(getClass().getResource("D1.jpg")));
                            tab[j][i]=mo;
                            }
                            if(((Drzwi)plansza[i][j]).klucz==2){
                                mo = new JLabel(new ImageIcon(getClass().getResource("D2.jpg")));
                                tab[j][i]=mo;
                                }
                            if(((Drzwi)plansza[i][j]).klucz==3){
                                mo = new JLabel(new ImageIcon(getClass().getResource("D3.jpg")));
                                tab[j][i]=mo;
                                }
                            if(((Drzwi)plansza[i][j]).klucz==4){
                                mo = new JLabel(new ImageIcon(getClass().getResource("D4.jpg")));
                                tab[j][i]=mo;
                                }
                            if(((Drzwi)plansza[i][j]).klucz==5){
                                mo = new JLabel(new ImageIcon(getClass().getResource("D5.jpg")));
                                tab[j][i]=mo;
                                }
                        break;
                        case "Duch":
                        mo = new JLabel(new ImageIcon(getClass().getResource("Du.jpg")));
                        tab[j][i]=mo;
                        break;
                        case "Straznik":
                        if(((Straznik)plansza[i][j]).zdrowie==3){
                            mo = new JLabel(new ImageIcon(getClass().getResource("St.jpg")));
                            tab[j][i]=mo;
                        }else{
                            if(((Straznik)plansza[i][j]).zdrowie==2){
                                mo = new JLabel(new ImageIcon(getClass().getResource("St1.jpg")));
                                tab[j][i]=mo;
                            }else{
                                if(((Straznik)plansza[i][j]).zdrowie==1){
                                    mo = new JLabel(new ImageIcon(getClass().getResource("St2.jpg")));
                                    tab[j][i]=mo;
                                }
                            }
                        }
                        break;
                        case "Klucz":
                        if(((Klucz)plansza[i][j]).rodzaj==1){
                            mo = new JLabel(new ImageIcon(getClass().getResource("K1.jpg")));
                            tab[j][i]=mo;
                        }
                        if(((Klucz)plansza[i][j]).rodzaj==2){
                            mo = new JLabel(new ImageIcon(getClass().getResource("K2.jpg")));
                            tab[j][i]=mo;
                        }
                        if(((Klucz)plansza[i][j]).rodzaj==3){
                            mo = new JLabel(new ImageIcon(getClass().getResource("K3.jpg")));
                            tab[j][i]=mo;
                        }
                        if(((Klucz)plansza[i][j]).rodzaj==4){
                            mo = new JLabel(new ImageIcon(getClass().getResource("K4.jpg")));
                            tab[j][i]=mo;
                        }
                        if(((Klucz)plansza[i][j]).rodzaj==5){
                            mo = new JLabel(new ImageIcon(getClass().getResource("K5.jpg")));
                            tab[j][i]=mo;
                        }
                        break;
                        case "Miecz":
                        mo = new JLabel(new ImageIcon(getClass().getResource("M.jpg")));
                        tab[j][i]=mo;
                        break;
                        case "Kilof":
                        mo = new JLabel(new ImageIcon(getClass().getResource("Ki.jpg")));
                        tab[j][i]=mo;
                        break;
                        case "Puste":
                        mo = new JLabel(new ImageIcon(getClass().getResource("pusty.jpg")));
                        tab[j][i]=mo;
                        break;
                        default:
                        mo = new JLabel(new ImageIcon(getClass().getResource("pusty.jpg")));
                        tab[j][i]=mo;
                            break;
                    }}else{
                        mo = new JLabel(new ImageIcon(getClass().getResource("mgla.jpg")));
                        tab[j][i]=mo;
                    }
            }
        }
        for(int i=0;i<5;i++){
            if(ekwipunek[i]==null){
                mo = new JLabel(new ImageIcon(getClass().getResource("pustek.jpg")));
                eq[i]=mo; 
            }else{
            switch (ekwipunek[i].getClass().getName()) {
                case "Klucz":
                if(((Klucz)ekwipunek[i]).rodzaj==1){
                    mo = new JLabel(new ImageIcon(getClass().getResource("Kek1.jpg")));
                    eq[i]=mo;
                }
                if(((Klucz)ekwipunek[i]).rodzaj==2){
                    mo = new JLabel(new ImageIcon(getClass().getResource("Kek2.jpg")));
                    eq[i]=mo;
                }
                if(((Klucz)ekwipunek[i]).rodzaj==3){
                    mo = new JLabel(new ImageIcon(getClass().getResource("Kek3.jpg")));
                    eq[i]=mo;
                }
                if(((Klucz)ekwipunek[i]).rodzaj==4){
                    mo = new JLabel(new ImageIcon(getClass().getResource("Kek4.jpg")));
                    eq[i]=mo;
                }
                if(((Klucz)ekwipunek[i]).rodzaj==5){
                    mo = new JLabel(new ImageIcon(getClass().getResource("Kek5.jpg")));
                    eq[i]=mo;
                }
                break;
                case "Miecz":
                mo = new JLabel(new ImageIcon(getClass().getResource("grafiki\\Mek.jpg")));
                eq[i]=mo;
                break;
                case "Kilof":
                mo = new JLabel(new ImageIcon(getClass().getResource("grafiki\\Kiek.jpg")));
                eq[i]=mo;
                break;
                default:
                mo = new JLabel(new ImageIcon(getClass().getResource("grafiki\\pustek.jpg")));
                eq[i]=mo;
                    break;
            }
        }
    }
        frame.setVisible(true);
    }
        /**
 * Funkcja wypisujaca plansze z obiektami klas jako ikony widoczne na planszy po wykonaniu interakcji
 */
    public void wypiszp() {
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(plansza[i][j].widocznosc){
                    switch (plansza[i][j].getClass().getName()) {
                        case "Sciana":
                        tab[j][i].setIcon(new ImageIcon(getClass().getResource("x.jpg")));
                        break;
                        case "Skarb":
                        tab[j][i].setIcon(new ImageIcon(getClass().getResource("Sk.jpg")));
                        break;
                        case "Gracz":
                        tab[j][i].setIcon(new ImageIcon(getClass().getResource("B.jpg")));
                        break;
                        case "Drzwi":
                        if(((Drzwi)plansza[i][j]).klucz==1){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("D1.jpg")));
                        }
                        if(((Drzwi)plansza[i][j]).klucz==2){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("D2.jpg")));
                        }
                        if(((Drzwi)plansza[i][j]).klucz==3){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("D3.jpg")));
                        }
                        if(((Drzwi)plansza[i][j]).klucz==4){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("D4.jpg")));
                        }
                        if(((Drzwi)plansza[i][j]).klucz==5){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("D5.jpg")));
                        }
                        break;
                        case "Duch":
                        tab[j][i].setIcon(new ImageIcon(getClass().getResource("Du.jpg")));
                        break;
                        case "Straznik":
                        if(((Straznik)plansza[i][j]).zdrowie>3){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("St.jpg")));
                        }else{
                            if((2<=((Straznik)plansza[i][j]).zdrowie)||((Straznik)plansza[i][j]).zdrowie<=3){
                                tab[j][i].setIcon(new ImageIcon(getClass().getResource("St1.jpg")));
                            }else{
                                if(((Straznik)plansza[i][j]).zdrowie==1){
                                    tab[j][i].setIcon(new ImageIcon(getClass().getResource("St2.jpg")));
                                }
                            }
                        }
                        break;
                        case "Klucz":
                        if(((Klucz)plansza[i][j]).rodzaj==1){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("K1.jpg")));
                        }
                        if(((Klucz)plansza[i][j]).rodzaj==2){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("K2.jpg")));
                        }
                        if(((Klucz)plansza[i][j]).rodzaj==3){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("K3.jpg")));
                        }
                        if(((Klucz)plansza[i][j]).rodzaj==4){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("K4.jpg")));
                        }
                        if(((Klucz)plansza[i][j]).rodzaj==5){
                            tab[j][i].setIcon(new ImageIcon(getClass().getResource("K5.jpg")));
                        }
                        break;
                        case "Miecz":
                        tab[j][i].setIcon(new ImageIcon(getClass().getResource("M.jpg")));
                        break;
                        case "Kilof":
                        tab[j][i].setIcon(new ImageIcon(getClass().getResource("Ki.jpg")));
                        break;
                        case "Puste":
                        tab[j][i].setIcon(new ImageIcon(getClass().getResource("pusty.jpg")));
                        break;
                        default:
                        tab[j][i].setIcon(new ImageIcon(getClass().getResource("pusty.jpg")));
                            break;
                    }}else{
                        tab[j][i].setIcon(new ImageIcon(getClass().getResource("mgla.jpg")));
                    }
            }
        }
        for(int i=0;i<5;i++){
            if(ekwipunek[i]==null){
                eq[i].setIcon(new ImageIcon(getClass().getResource("pustek.jpg")));
            }else{
            switch (ekwipunek[i].getClass().getName()) {
                case "Klucz":
                if(((Klucz)ekwipunek[i]).rodzaj==1)
                eq[i].setIcon(new ImageIcon(getClass().getResource("Kek1.jpg")));
                if(((Klucz)ekwipunek[i]).rodzaj==2)
                eq[i].setIcon(new ImageIcon(getClass().getResource("Kek2.jpg")));
                if(((Klucz)ekwipunek[i]).rodzaj==3)
                eq[i].setIcon(new ImageIcon(getClass().getResource("Kek3.jpg")));
                if(((Klucz)ekwipunek[i]).rodzaj==4)
                eq[i].setIcon(new ImageIcon(getClass().getResource("Kek4.jpg")));
                if(((Klucz)ekwipunek[i]).rodzaj==5)
                eq[i].setIcon(new ImageIcon(getClass().getResource("Kek5.jpg")));                
                break;
                case "Miecz":
                eq[i].setIcon(new ImageIcon(getClass().getResource("Mek.jpg")));
                break;
                case "Kilof":
                eq[i].setIcon(new ImageIcon(getClass().getResource("Kiek.jpg")));
                break;
                default:
                eq[i].setIcon(new ImageIcon(getClass().getResource("pustek.jpg")));
                    break;
            }
        }
    }
        frame.setVisible(true);
    }
    
    /** 
     * Funkcja szukająca pasujacego klucza
     * @param rodzaj Rodzaj drzwi
     * @return boolean Czy jest pasujacy klucz
    */
    public boolean szukajk(int rodzaj){
        boolean wynik=false;
        for(int i=0;i<5;i++){
            if(ekwipunek[i] instanceof Klucz){
                if(((Klucz) ekwipunek[i]).rodzaj==rodzaj){
                    wynik=true;
                    ekwipunek[i].uzycia-=1;
                    if(ekwipunek[i].uzycia==0){
                        ekwipunek[i]=null;
                    }
                }
            }
        }
        return wynik;
    }
        /**
 * Funkcja poruszająca wszystkich strazników po planszy
 */
    public void porusz(){
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(plansza[i][j] instanceof Straznik&&((Straznik)plansza[i][j]).ruch){
                    ((Straznik)plansza[i][j]).ruch(this, i, j);
                }
            }
        }
        for(int i=0;i<20;i++){
            for(int j=0;j<20;j++){
                if(plansza[i][j] instanceof Straznik){
                    ((Straznik)plansza[i][j]).ruch=true;
                }
            }
        }
    }
    
    /** 
     * Funkcja szukająca miecza
     * @return int Miejsce na któym znajduje sie poszukiwany miecz
     */
    public int szukajm(){
        int wynik=0;
        for(int i=0;i<5;i++){
            if(ekwipunek[i] instanceof Miecz){
                    wynik=((Miecz)ekwipunek[i]).obrazenia;
                    ekwipunek[i].uzycia=ekwipunek[i].uzycia-1;
                    if(ekwipunek[i].uzycia<=0){
                        ekwipunek[i]=null;
                    }
            }
        }
        return wynik;
    }
    
    /** 
     * Funkcja szukająca kilofa
     * @return int Miejsce na któym znajduje sie poszukiwany kilof
     */
    public int szukajki(){
        int wynik=0;
        for(int i=0;i<5;i++){
            if(ekwipunek[i] instanceof Kilof){
                    wynik=((Kilof)ekwipunek[i]).wydajnosc;
                    ekwipunek[i].uzycia=ekwipunek[i].uzycia-1;
                    if(ekwipunek[i].uzycia<=0){
                        ekwipunek[i]=null;
                    }
            }
        }
        return wynik;
    }
    
    /** 
     * main
     * @param args Argumenty wywołania programu
     */
    public static void main(String[] args) {
        new Okno();
    }
}