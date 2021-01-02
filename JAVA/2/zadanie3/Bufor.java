import java.util.*;
public class Bufor<T> {
    final int rozm=10;
    List<T> buf;
    Bufor(){
        buf=new ArrayList<>(rozm);
    }
    public synchronized void add(T p) throws InterruptedException {
        if(buf.size() == rozm){
            wait();
        }
        buf.add(p);
        notify();
    }
    public synchronized T get() throws InterruptedException {
        if(buf.size() == 0){
            wait();
        }
        notify();
        return buf.remove(0);
    }
}