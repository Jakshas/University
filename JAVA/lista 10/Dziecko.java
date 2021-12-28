import java.util.Random;

import javax.swing.JOptionPane;

public class Dziecko implements  Runnable {

    int id;
    Random r;
    Logika l;

    Dziecko(int i, Logika log){
        id=i;
        l=log;
        r = new Random();
    }

    @Override
    public void run() {
        while(true) {
            synchronized(l){
                losujdroge();
            }
             if (l.status[id]==1) {
                try {
                    Thread.sleep(700);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
             }else{
                try {
                    Thread.sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
             }

        }
    }

    boolean przylegajacymikolaj(){
        if ((l.mikolaj[0]==l.dzieci[id][0]+1 && l.mikolaj[1]==l.dzieci[id][1])||
        (l.mikolaj[0]==l.dzieci[id][0]-1 && l.mikolaj[1]==l.dzieci[id][1])||
        (l.mikolaj[0]==l.dzieci[id][0] && l.mikolaj[1]==l.dzieci[id][1]+1)||
        (l.mikolaj[0]==l.dzieci[id][0] && l.mikolaj[1]==l.dzieci[id][1]-1)) {
            return true;
        }
        return false;
    }

    void losujdroge(){

        if (l.dzieci[id][2]==1) {
            int c;
            if ((c=czymikolaj()) != -1) {
                l.status[id]=1;
                if (c==0) {
                    l.dzieci[id][0] = (l.dzieci[id][0]-1+l.n)%l.n;
                }
                if (c==1) {
                    l.dzieci[id][0] = (l.dzieci[id][0]+1+l.n)%l.n;
                }
                if (c==2) {
                    l.dzieci[id][1] = (l.dzieci[id][1]-1+l.m)%l.m;
                }
                if (c==3) {
                    l.dzieci[id][1] = (l.dzieci[id][1]+1+l.m)%l.m;
                }
                if (przylegajacymikolaj()) {
                    JOptionPane.showMessageDialog(l.ok.frame,
                    "Przegrałeś");
                    System.exit(0);
                }
                l.przebiegniete[id]=l.przebiegniete[id]+1;
                if (l.przebiegniete[id]>=7) {
                    l.dzieci[id][2]=2;
                    l.status[id]=0;
                }
            } else {
                l.status[id]=0;
                boolean ok= false;
                do{
                    int rn= r.nextInt(4);
                    if (rn == 0 && 0 == czydziecko((l.dzieci[id][0]-1+l.n)%l.n, l.dzieci[id][1])) {
                        l.dzieci[id][0] = (l.dzieci[id][0]-1+l.n)%l.n;
                        ok= true;
                    }
                    if (rn == 1 && 0 == czydziecko((l.dzieci[id][0]+1+l.n)%l.n, l.dzieci[id][1])) {
                        l.dzieci[id][0] = (l.dzieci[id][0]+1+l.n)%l.n;
                        ok= true;
                    }
                    if (rn == 2 && 0 == czydziecko(l.dzieci[id][0], (l.dzieci[id][1]-1+l.m)%l.m)) {
                        l.dzieci[id][1] = (l.dzieci[id][1]-1+l.m)%l.m;
                        ok= true;
                    }
                    if (rn == 3 && 0 == czydziecko(l.dzieci[id][0], (l.dzieci[id][1]+1)%l.m)) {
                        l.dzieci[id][1] = (l.dzieci[id][1]+1)%l.m;
                        ok= true;
                    }
                }while(!ok);
            }
        }
        if (l.dzieci[id][2]==2) {
            int rand = r.nextInt(3)+1;
            l.przebiegniete[id]=l.przebiegniete[id]-rand;
            if (l.przebiegniete[id]<=0) {
                l.przebiegniete[id]=0;
                l.dzieci[id][2]=1;
            }
        }
    }

    int czydziecko(int i,int j){
        for (int[] js : l.dzieci) {
            if (js != null && js[0] == i && js[1] == j) {
                return js[2];
            }
        }
        return 0;
    }

    int czymikolaj(){
        int x = 0;
        int y = 0;

        for (int k = -5; k < 5; k++) {
            for (int k2 = -5; k2 < 5; k2++) {
                if (l.mikolaj[0] == (l.dzieci[id][0]+k+l.n)%l.n && l.mikolaj[1] == (l.dzieci[id][1]+k2+l.m)%l.m) {
                    x=k;
                    y=k2;
                }
            }
        }
        

        if (x>-5 && x<0 && Math.abs(x)>=Math.abs(y) && czydziecko(l.dzieci[id][0]-1, l.dzieci[id][1]) == 0) {
            return 0;
        } 
        if (x<5 && x>0 && Math.abs(x)>=Math.abs(y) && czydziecko(l.dzieci[id][0]+1, l.dzieci[id][1]) == 0) {
            return 1;
        }
        if (y>-5 && y<0 && Math.abs(y)>=Math.abs(x) && czydziecko(l.dzieci[id][0], l.dzieci[id][1]-1) == 0) {
            return 2;
        }
        if (y<5 && y>0 && Math.abs(y)>=Math.abs(x) && czydziecko(l.dzieci[id][0], l.dzieci[id][1]+1) == 0) {
            return 3;
        }
        return -1;
    }
}
