import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

public class Pojazd implements Serializable{
    private static final long serialVersionUID = 1L;
    String kolor;
    int moc;
    int kola;
    @Override
    public String toString() {
        return kolor+" "+moc+" "+kola;
    }
    public Pojazd(String kolor,int moc,int kola){
        this.kolor=kolor;
        this.moc=moc;
        this.kola=kola;
    }
       public void pisz(String[] args) throws FileNotFoundException, IOException {
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(args[1]))) {
            outputStream.writeObject(this);
        }}
        public static Pojazd czytaj(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
            try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(args[1]))) {
                Pojazd number = (Pojazd) inputStream.readObject();
                return number;
            }
        }
}