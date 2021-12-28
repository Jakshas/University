import java.util.Random;

public class Postac {
    int x;
    int y;
    Postac(){
        Random r=new Random();
        x=((Math.abs(r.nextInt())%9)*40)+10;
        y=((Math.abs(r.nextInt())%9)*40)+10;
    }
}
