package obliczenia;

import struktury.*;

public class Zmienna extends Wyrazenie {
    public String zmienna;
    public static Zbior zbior = new ZbiorNaTablicyDynamicznej();

    public Zmienna(String zmienna) {
        this.zmienna = zmienna;
    }

    public int oblicz() {
        try {
            if (Blok.srodowiska==null) {
                return (int) zbior.czytaj(zmienna);
            }else{
                for (Zbior srodowisko : Blok.srodowiska) {
                    if(srodowisko.szukajtf(zmienna)){
                        return (int) srodowisko.czytaj(zmienna);
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return 0;
    }
    public String toString(){
        return zmienna;
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Zmienna) {
            return ((Zmienna)obj).zmienna==this.zmienna;
        }
        return false;
    }
    }
