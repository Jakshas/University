import struktury.*;
import obliczenia.*;
public class Main2 {
    public static void main(String[] args) throws Exception {
        Zbior zbior = new ZbiorNaTablicyDynamicznej();
        zbior.wstaw(new Para(2,"x"));
        zbior.wstaw(new Para(4,"y"));
        Zmienna.zbior=zbior;
        Wyrazenie w1=new Dodawanie(new Liczba(3),new Liczba(5));
        System.out.print(w1+"=");
        System.out.println(w1.oblicz());
        Wyrazenie w2=new Mnozenie(new Znak(new Odejmowanie(new Liczba(2),new Zmienna("x"))),new Liczba(7));
        System.out.print(w2+"=");
        System.out.println(w2.oblicz());
        Wyrazenie w3=new Dzielenie(new Odejmowanie(new Mnozenie(new Liczba(3),new Liczba(11)),new Liczba(1)),new Dodawanie(new Liczba(7), new Liczba(5)));
        System.out.print(w3+"=");
        System.out.println(w3.oblicz());
        Wyrazenie w4=new Minimum(new Mnozenie(new Dodawanie(new Zmienna("x"), new Liczba(13)), new Zmienna("x")),new Reszta(new Odejmowanie(new Liczba(1), new Zmienna("x")),new Liczba(2)));
        System.out.print(w4+"=");
        System.out.println(w4.oblicz());
        Wyrazenie w5=new Wieksze(new Dodawanie(new Potegowanie(new Liczba(2),new Liczba(5)),new Mnozenie(new Zmienna("x"), new Logarytm(new Liczba(2),new Zmienna("y")))), new Liczba(20));
        System.out.print(w5+"=");
        System.out.println(w5.oblicz());
        double sum= Wyrazenie.iloczyn(w1,w3);
        System.out.println(sum);
    }
}
