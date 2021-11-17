import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Tramwaj extends Pojazd {
    private static final long serialVersionUID = 3L;
    int siedzenia;
    int wagony;
    boolean stary;
    @Override
    public String toString() {
        String pom="";
        if(stary){
            pom="stary";
        }else{
            pom="nowy";
        }
        pom=moc+" "+kola+" "+kolor+" "+siedzenia+" "+wagony+" "+pom;
        return pom;
    }
    Tramwaj(String kolor,int moc,int kola,int siedzenia,int wagony,boolean stary){
        super(kolor, moc, kola);
        this.siedzenia=siedzenia;
        this.wagony=wagony;
        this.stary=stary;
    }
    public void pisz(String[] args) throws FileNotFoundException, IOException {
        try (ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream(args[1]))) {
            outputStream.writeObject(this);
        }}
        public static Tramwaj czytaj(String[] args) throws FileNotFoundException, IOException, ClassNotFoundException {
            try (ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream(args[1]))) {
                Tramwaj number = (Tramwaj) inputStream.readObject();
                return number;
            }
        }
}