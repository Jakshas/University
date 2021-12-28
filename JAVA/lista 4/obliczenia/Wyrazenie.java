package obliczenia;

public abstract class Wyrazenie implements Obliczalny{
    /** metoda sumująca wyrażenia */
public static double suma (Wyrazenie... wyr) {
    double sum=0;
    for (Wyrazenie wyrazenie : wyr) {
        sum=sum+wyrazenie.oblicz();
    }
    return sum;
}
/** metoda mnożąca wyrażenia */
public static double iloczyn (Wyrazenie... wyr) {
    double sum=1;
    for (Wyrazenie wyrazenie : wyr) {
        sum=sum*wyrazenie.oblicz();
    }
    return sum;
 }
}
