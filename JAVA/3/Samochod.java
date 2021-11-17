import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Samochod extends Pojazd {

    private static final long serialVersionUID = 2L;
    int rocznik;
    String marka;
    int przebieg;

    @Override
    public String toString() {
        String pom = "";
        pom = moc + " " + kola + " " + kolor + " " + przebieg + " " + rocznik + " " + marka;
        return pom;
    }

    public Samochod(String kolor, int moc, int kola, int rocznik, String marka, int przebieg) {
        super(kolor, moc, kola);
        this.rocznik = rocznik;
        this.marka = marka;
        this.przebieg = przebieg;
    }

    public void pisz(String[] args) throws FileNotFoundException, IOException {
    try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(args[1]))) {
        outputStream.writeObject(this);
    }}
    public static Samochod czytaj(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
        try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(args[1]))) {
            Samochod number = (Samochod) inputStream.readObject();
            return number;
        }
    }
}