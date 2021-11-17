import java.awt.*;
import java.awt.image.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Vector;

import javax.imageio.*;

class MyCanvas extends Canvas  
{  
    Okno ok;
    public MyCanvas(Okno o) 
    {
        ok=o;
        setBackground (Color.GRAY);  
        setSize(400, 400);  
    }  

    public void paint(Graphics g)  
    {  
        Graphics2D g2= (Graphics2D) g;
        g2.setColor(Color.blue);
        g2.setStroke(new BasicStroke(3));
        g2.drawLine(0, 0, 0, 399);
        g2.drawLine(399, 399, 0,399);
        g2.drawLine(0, 0, 799, 0);
        g2.drawLine(399, 399, 399, 0);
        int k=0;
        for (Vector<Integer> el : ok.m.sciezki) {
            int[] tt= new int[4];
            for (int i=0;i<4 ; i++) {
                tt[i]=0;
            }
            for (Integer i : el) {
                if (k-1==i) {
                    tt[0]=1;
                }
                if(k+1==i) {
                    tt[1]=1;
                }
                if (k-10==i) {
                    tt[2]=1;
                }
                if (k+10==i) {
                    tt[3]=1;
                }
            }
            if (tt[0]==0) {
                g2.drawLine((k%10)*40,(k/10)*40 , (k%10)*40, ((k/10)+1)*40);
                for (int i = (k/10)*40; i < ((k/10)+1)*40 ; i++) {
                    ok.mapa[(k%10)*40][i]=1;
                }
            }
            if (tt[1]==0) {
                g2.drawLine(((k%10)+1)*40,(k/10)*40 , ((k%10)+1)*40, ((k/10)+1)*40);
                for (int i = (k/10)*40; i < ((k/10)+1)*40 ; i++) {
                    ok.mapa[(((k%10)+1)*40)-1][i]=1;
                }
            }
            if (tt[2]==0) {
                g2.drawLine((k%10)*40,(k/10)*40 , ((k%10)+1)*40 , (k/10)*40);
                for (int i = (k%10)*40; i < ((k%10)+1)*40 ; i++) {
                    ok.mapa[i][(k/10)*40]=1;
                }
            }
            if (tt[3]==0) {
                g2.drawLine((k%10)*40,((k/10)+1)*40 , ((k%10)+1)*40, ((k/10)+1)*40);
                for (int i = (k%10)*40; i < ((k%10)+1)*40 ; i++) {
                    ok.mapa[i][(((k/10)+1)*40)-1]=1;
                }
            }
            k++;
        }
        BufferedImage img;
        try {
            img = ImageIO.read(new File("Postac.png"));
            g2.drawImage(img, ok.pl.x,ok.pl.y, null);
        } catch (IOException e) {
        }
        BufferedImage img2;
        try {
            img2 = ImageIO.read(new File("Skarb.png"));
            g2.drawImage(img2, 10 , 10, null);
        } catch (IOException e) {
        }
    }
} 