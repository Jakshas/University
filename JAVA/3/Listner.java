import java.awt.event.*;
import java.io.IOException;

import javax.swing.JFrame;
import javax.swing.JTextField;

public class Listner implements ActionListener {
    JFrame frame;
    String argss[];
    JTextField rocznik;
    JTextField kolor;
    JTextField moc;
    JTextField kola;
    JTextField marka;
    JTextField przebieg;

    Listner(String args[],JTextField rocznik,JTextField kolor,JTextField moc,JTextField kola,JTextField marka,JTextField przebieg,JFrame frame) 
    {
        this.frame=frame;
        argss = args;
        this.rocznik=rocznik;
        this.kolor=kolor;
        this.moc=moc;
        this.kola=kola;
        this.marka=marka;
        this.przebieg=przebieg;
    }
    public void nadpiszp(Pojazd p){
        kola.setText(String.valueOf(p.kola));
        kolor.setText(String.valueOf(p.kolor));
        moc.setText(String.valueOf(p.moc));
        this.frame.setVisible(true);
    }
    public void nadpiszs(Samochod p){
        kola.setText(String.valueOf(p.kola));
        kolor.setText(String.valueOf(p.kolor));
        moc.setText(String.valueOf(p.moc));
        rocznik.setText(String.valueOf(p.rocznik));
        marka.setText(String.valueOf(p.marka));;
        przebieg.setText(String.valueOf(p.przebieg));;
        this.frame.setVisible(true);
    }
    public void nadpiszt(Tramwaj p){
        kola.setText(String.valueOf(p.kola));
        kolor.setText(String.valueOf(p.kolor));
        moc.setText(String.valueOf(p.moc));
        rocznik.setText(String.valueOf(p.siedzenia));
        marka.setText(String.valueOf(p.wagony));;
        przebieg.setText(String.valueOf(p.stary));;
        this.frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (argss[0].equals("Pojazd")) {
            Pojazd p;
            try {
                p = Pojazd.czytaj(argss);
            } catch (ClassNotFoundException | IOException e1) {
                p=new Pojazd("",0,0);
                try {
                    p.pisz(argss);
                } catch (IOException e2) {
                    // TODO Auto-generated catch block
                }
            }
            this.nadpiszp(p);

        } else {
            if (argss[0].equals("Samochod")) {
                Samochod p;
                try {
                    p = Samochod.czytaj(argss);
                } catch (ClassNotFoundException | IOException e1) {
                    // TODO Auto-generated catch block
                    p= new Samochod("", 0, 0, 0, "", 0);
                }
                this.nadpiszs(p);
            } else {
                Tramwaj p;
                try {
                    p = Tramwaj.czytaj(argss);
                } catch (ClassNotFoundException | IOException e1) {
                    // TODO Auto-generated catch block
                    p= new Tramwaj("", 0, 0, 0, 0, false);
                }
                this.nadpiszt(p);
        }
    }
}

}