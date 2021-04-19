import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.Collator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
import java.util.Scanner;

public class zadanie2 {
    public static void main(String[] args) throws IOException {
        File file = new File("slowa.txt");
        Scanner sc = new Scanner(file);
        ArrayList<String> text = new ArrayList<String>();
        ArrayList<String> slowa = new ArrayList<String>();
        while (sc.hasNext()) {
            String i = sc.next();
            slowa.add(i);
        }
        sc.close();
        sc = new Scanner(new File("1.txt"));
        while (sc.hasNext()) {
            String i = sc.next();
            text.add(i);
        }
        Collections.sort(slowa);
        ArrayList<Slowa> sl = new ArrayList<Slowa>();
        FileWriter file2 = new FileWriter("zad2_outputl.txt");
        for (int g = 0; g <= 100; g++) {
            String string = text.get(g);
        //  for (String string : text) {
            sl.clear();
            for (int i = 1; i <= string.length(); i++) {
                String s = string.substring(0, i);
                if (wslowach(slowa, s)) {
                    sl.add(new Slowa(s, i));
                }
            }
            for (Slowa slowo : sl) {
                przeszukanie(slowo, string.substring(slowo.dlugosc ,string.length()), slowa);
            }
            najlepsze(string.length(), 0, sl);
            maxdl = 0;
            String out = "";
            for (String str : smax) {
                out += str+" ";
            }
            out = out.substring(0, out.length()-1);
            out += '\n';
            file2.append(out);
        }
        file2.close();
    }

    public static void przeszukanie(Slowa sl, String text, ArrayList<String> slowa) {
        for (int i = 1; i <= text.length(); i++) {
            String s = text.substring(0, i);
            if (wslowach(slowa, s)) {
                sl.dzieci.add(new Slowa(s, i));
            }
        }
        for (Slowa slowo : sl.dzieci) {
            przeszukanie(slowo, text.substring(slowo.dlugosc,text.length()), slowa);
        }
    }

    public static boolean wslowach(ArrayList<String> slowa, String sl) {
        if (Collections.binarySearch(slowa, sl) > 0) {
            return true;
        }else{
            return false;
        }
    }

    static int maxdl = 0;
    static ArrayList<String> smax = new ArrayList<String>();
    static ArrayList<String> str = new ArrayList<String>();
    static Collator myDefaultCollator = Collator.getInstance();

    public static boolean najlepsze(int dlugosctxt, int dlugosc, ArrayList<Slowa> ars) {

        boolean[] a = new boolean[ars.size()];
        Random r = new Random();
        if (ars.size() > 0) {
            int i = r.nextInt(ars.size());
            int j = 0;
            boolean f = true;
            while(f && j < ars.size()){
                while (a[i]) {
                    i = r.nextInt(ars.size());
                }
                str.add(ars.get(i).slowo);
                if ((dlugosc + ars.get(i).dlugosc == dlugosctxt)) {
                    smax.clear();
                    for (String string2 : str) {
                        smax.add(string2);
                    }
                    str.remove(str.size()-1);
                    return false;
                } else {
                    if (ars.size() == 0) {
                        str.remove(str.size()-1);
                        return true;
                    }else{
                        f = najlepsze(dlugosctxt, dlugosc + ars.get(i).dlugosc, ars.get(i).dzieci);
                    }
                }
                j++;
                str.remove(str.size()-1);
                a[i] = true;
            }
        }
        return true;
    }
}
