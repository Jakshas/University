
public class Konsument extends Thread {
    Bufor<String> buf;

    Konsument(Bufor<String> inp) {
        buf = inp;
    }

    public void run() {
        while (true) {
            try {
                System.out.println("usuniety=" + buf.get());
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}