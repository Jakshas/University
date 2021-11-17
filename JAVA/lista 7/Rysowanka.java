import java.awt.Graphics;
import java.awt.*;  

public class Rysowanka extends Canvas{
    Okno o;
    Color tlo=Color.GRAY;
    Color pion=Color.red;
    Color wyp= Color.orange;

    int rozmiar=40;

    Rysowanka(Okno o){
        super();
        this.o=o;
        setBackground (Color.GRAY);  
        setSize(281, 281); 
    }
    
    @Override
    public void paint(Graphics g) {
        o.frame.getContentPane().setBackground(tlo);
        o.panel.setBackground(tlo);
        o.planszar.setBackground(tlo);
        for (int i = 0; i < o.plansza.length; i++) {
            for (int j = 0; j < o.plansza.length; j++) {
                g.setColor(Color.black);
                if(sprawdzpl(i, j))
                g.drawRect(rozmiar * i, rozmiar * j, rozmiar, rozmiar);
                g.setColor(pion);
                if (sprawdzpi(i, j)){
                    g.drawOval((rozmiar * i)+5, (rozmiar * j)+5, rozmiar-10, rozmiar-10);
                    if(o.zaznaczony[0] == i && o.zaznaczony[1] == j){
                        g.setColor(pion);
                    }else{
                        g.setColor(wyp);
                    }
                    g.fillOval((rozmiar * i)+5, (rozmiar * j)+5, rozmiar-10, rozmiar-10);
                }
            }
        }
    }
    public boolean sprawdzpl(int i, int j){
        if (o.jaka==0) {
            if((i==0&&(j==0||j==1||j==6||j==5))||(i==6&&(j==0||j==1||j==6||j==5))||(i==5&&(j==0||j==6))||(i==1&&(j==0||j==6))){
                return false;
            }
            return true;
        }else{
            if((i==0&&(j==0||j==1||j==6||j==5))||(i==6&&(j==0||j==1||j==6||j==5))||(i==5&&(j==0||j==1||j==6||j==5))||(i==1&&(j==0||j==1||j==6||j==5))){
                return false;
            }
            return true;
        }
    }
    public boolean sprawdzpi(int i,int j){
        if (o.plansza[i][j]){
            return true;
        }
        return false;
    }
    public void update(Graphics g) {
        Graphics offgc;
        Image offscreen = null;
        Dimension d = getSize();

        offscreen = createImage(d.width, d.height);
        offgc = offscreen.getGraphics();
        offgc.setColor(getBackground());
        offgc.fillRect(0, 0, d.width, d.height);
        offgc.setColor(getForeground());
        paint(offgc);
        g.drawImage(offscreen, 0, 0, this);
    }
}
