import obliczenia.*;
public class Main3 {
    public static void main(String[] args) throws Exception {
        Instrukcja ins = new Blok(
            new Deklaracja("n"),
            new Czytaj("n"),
            new If_else(new Mniejsze(new Zmienna("n") ,new Liczba(2)),new Wypisz(new Liczba(0)),
                new Blok(
                    new Deklaracja("p"),
                    new Przypisz("p",new Liczba(2)),
                    new Deklaracja("wyn"),
                    new While(new Mniejszerowne(new Mnozenie(new Zmienna("p"), new Zmienna("p")),new Zmienna("n")),
                        new Blok(
                            new If(new Rowne(new Reszta(new Zmienna("n"), new Zmienna("p")),new Liczba(0)),
                                new Blok(
                                    new Przypisz("wyn", new Zmienna("p")),
                                    new Przypisz("p",new Zmienna("n")))),
                                new Przypisz("p", new Dodawanie(new Zmienna("p"), new Liczba(1))))),
                                new If_else(new Wieksze(new Zmienna("wyn"),new Liczba(0)), new Wypisz(new Liczba(0)),
                                new Wypisz(new Liczba(1))))));
                  ins.wykonaj();              
    }
}
