import java.util.Random;

public class Producent extends Thread {
    Bufor<String> buf;

    Producent(Bufor<String> t) {
        buf = t;
    }

    public void run() {
        while (true) {
            Random r = new Random();
            try {
                buf.add(Integer.toString(r.nextInt()));
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
    }
}
}