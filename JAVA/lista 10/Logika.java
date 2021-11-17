import java.util.Random;

public class Logika {

    int mikolaj[] = {2,2};
    int dzieci[][];
    Random r = new Random();
    int n,m;
    int status[];
    int przebiegniete[];
    Okno ok;
    int iledzieci=12;

    Logika(int n,int m,Okno ok){
        this.ok=ok;
        this.n=n;
        this.m=m;
        dzieci = new int[12][3];
        status = new int[12];
        przebiegniete = new int[12];
        losowedzieci();
        Runnable[] trdzieci = new Runnable[12];
        Thread[] trthread = new Thread[12];
        for(int i=0; i<12; i++) {
            trdzieci[i] = new Dziecko(i, this);
        }

        for(int i=0; i<12; i++) {
            trthread[i] = new Thread(trdzieci[i]);
        }

        for(int i=0; i<12; i++) {
            trthread[i].start();
        }
    }

    int czydziecko(int i,int j){
        for (int[] js : dzieci) {
            if (js != null && js[0] == i && js[1] == j) {
                return js[2];
            }
        }
        return 0;
    }

    int ktoredziecko(int i,int j){
        int x=0;
        for (int[] js : dzieci) {
            if (js != null && js[0] == i && js[1] == j) {
                return x;
            }
            x++;
        }
        return -1;
    }
    void losowedzieci(){
        for (int i = 0; i < 12; i++) {
            int x, y;
            do{
                x = r.nextInt(n-5)+5;
                y = r.nextInt(m-5)+5;
            }while(czydziecko(x, y) != 0);
            int[] tab={x,y,1};
            dzieci[i]=tab;
        }
    }
}
