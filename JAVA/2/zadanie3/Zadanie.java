
public class Zadanie {
    public static void main(String[] args){
        Bufor<String> testowy = new Bufor<String>();
        Producent p = new Producent(testowy);
        Konsument k = new Konsument(testowy);
        p.start();
        k.start();
    }
}