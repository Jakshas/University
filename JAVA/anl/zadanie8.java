import java.io.FileWriter;
import java.io.IOException;
import java.util.Vector;

public class zadanie8 {

    public static Vector<double[]> v = new Vector<double[]>();

    public static double[] vagi = { 1,2,3,2.5,6,1.5,5,1,2,1,3,5,1 };

    public static void main(String[] args) throws IOException {
        double[] d1= {39.5, 10.5};
        v.add(d1);
        double[] d2= {30.0, 20.0};
        v.add(d2);
        double[] d3= {6.0, 6.0};
        v.add(d3);
        double[] d4= {13.0, -12.0};
        v.add(d4);
        double[] d5= {63.0, -12.5};
        v.add(d5);
        double[] d6= {18.5, 17.5};
        v.add(d6);
        double[] d7= {48.0, 63.0};
        v.add(d7);
        double[] d8= {7.0, 25.5};
        v.add(d8);
        double[] d9= {48.5, 49.5};
        v.add(d9);
        double[] d10= {9.0, 19.5};
        v.add(d10);
        double[] d11= {48.5, 35.5};
        v.add(d11);
        double[] d12= {59, 32.5};
        v.add(d12);
        double[] d13= {56, 20.5};
        v.add(d13);

        FileWriter myWriter = new FileWriter("filename.csv");
        for(double i = 0; i <= 1; i += 0.01) {
            double[] res = wypukla_krzywa_beziera(13, i);
            String s = res[0] + ", " + res[1]+ '\n';
            myWriter.append(s);
        }
        myWriter.close();
    }
    
    static int silnia(int n) {
        int res = 1;
        for(int i = 2; i <= n; i++)
            res *= i;
        return res;
    }

    static int dwumian_newtona(int n, int k) {
        int licznik = silnia(n);
        int mianownik = silnia(k) * silnia(n-k);
        return licznik/mianownik;
    }

    static double bernouli(int n, int k, double t) {
        return dwumian_newtona(n, k) * Math.pow(t, k) * Math.pow(1 - t, n - k);
    }

    static double[] wypukla_krzywa_beziera(int n, double t) {
        double licznik[] = {0,0};
        double mianownik = 0.0;
        for(int i = 0; i < n; i++) {
            double mnoznik = bernouli(n, i, t) * vagi[i];
            licznik[0] += v.get(i)[0] * mnoznik;
            licznik[1] += v.get(i)[1] * mnoznik;
            mianownik += mnoznik;
        }
        double[] wynik= {licznik[0] /= mianownik, licznik[1] /= mianownik};
        return wynik;
    }
}
