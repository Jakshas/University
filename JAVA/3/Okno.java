import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.IOException;

public class Okno implements ActionListener {
    JTextField rocznik;
    JTextField kolor;
    JTextField moc;
    JTextField kola;
    JTextField marka;
    JTextField przebieg;
    String argss[];
    public Okno(String args[]) {
        argss=args;
        JFrame frame = new JFrame("Pojazdy");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container kontener = frame.getContentPane();
        GridLayout layout;
        if(args[0].equals("Pojazd")){
        layout = new GridLayout(4, 2);
        }
        else{
        layout = new GridLayout(7, 2);
        }
        kontener.setLayout(layout);
        JLabel kolor_etykieta = new JLabel("kolor");
        kontener.add(kolor_etykieta);
        kolor = new JTextField("", 40);
        kontener.add(kolor);
        JLabel moc_etykieta = new JLabel("moc");
        kontener.add(moc_etykieta);
        moc = new JTextField("", 40);
        kontener.add(moc);
        JLabel kola_etykieta = new JLabel("kola");
        kontener.add(kola_etykieta);
        kola = new JTextField("", 40);
        kontener.add(kola);
        if(args[0].equals("Pojazd")){
        }else{
            if(args[0].equals("Samochod")){
                JLabel rocznik_etykieta = new JLabel("rocznik");
                kontener.add(rocznik_etykieta);
                rocznik = new JTextField("", 40);
                kontener.add(rocznik);
                JLabel marka_etykieta = new JLabel("marka");
                kontener.add(marka_etykieta);
                marka = new JTextField("", 40);
                kontener.add(marka);
                JLabel przebieg_etykieta = new JLabel("przebieg");
                kontener.add(przebieg_etykieta);
                przebieg = new JTextField("", 40);
                kontener.add(przebieg);
            }else{
                JLabel rocznik_etykieta = new JLabel("siedzenia");
                kontener.add(rocznik_etykieta);
                rocznik = new JTextField("", 40);
                kontener.add(rocznik);
                JLabel marka_etykieta = new JLabel("wagony");
                kontener.add(marka_etykieta);
                marka = new JTextField("", 40);
                kontener.add(marka);
                JLabel przebieg_etykieta = new JLabel("stary");
                kontener.add(przebieg_etykieta);
                przebieg = new JTextField("", 40);
                kontener.add(przebieg);
            }
        }
        JButton b = new JButton("Zapisz");
        b.addActionListener(this);
        kontener.add(b);
        JButton p = new JButton("Wypisz");
        p.addActionListener(new Listner(args, rocznik, kolor, moc, kola, marka, przebieg,frame));
        kontener.add(p);
        frame.pack();
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new Okno(args);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (argss[0].equals("Pojazd")) {
            Pojazd p = new Pojazd(kolor.getText(), Integer.parseInt(moc.getText()), Integer.parseInt(kola.getText()));
            try {
                p.pisz(this.argss);
            } catch (IOException e1) {
                e1.printStackTrace();
            }
}else
{
    if (argss[0].equals("Samochod")){
        Samochod p = new Samochod(kolor.getText(), Integer.parseInt(moc.getText()), Integer.parseInt(kola.getText()),
        Integer.parseInt(rocznik.getText()),marka.getText(),Integer.parseInt(przebieg.getText()));
        try {
            p.pisz(this.argss);
        } catch (IOException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        }
    }else{
        boolean b;
        if(przebieg.getText().equals("tak")){
            b=true;
        }else
        b=false;
        Tramwaj p = new Tramwaj(kolor.getText(), Integer.parseInt(moc.getText()), Integer.parseInt(kola.getText()),
        Integer.parseInt(rocznik.getText()),Integer.parseInt(marka.getText()),b);
        try {
            p.pisz(this.argss);
        } catch (IOException e1) {
            // TODO Auto-generated catch block
            e1.printStackTrace();
        }
    }
}
}
}