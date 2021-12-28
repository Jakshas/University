package obliczenia;

import java.util.Scanner;
import struktury.*;

public class Czytaj extends Instrukcja {

    String z;
    public Czytaj(String z) throws Exception {
        if (z==null) {
            throw new Exception("null");
        }
        this.z=z;
    }
    @Override
    public void wykonaj() throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        try {
            Blok.srodowiska.get(Blok.srodowiska.size()-1).ustaw(new Para(n, z));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}
