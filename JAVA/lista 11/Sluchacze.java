import java.awt.event.*;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.io.UnsupportedEncodingException;
import java.io.Writer;
import java.nio.file.Files;
import java.nio.file.Paths;

import javax.swing.JFileChooser;
import javax.swing.JOptionPane;

public class Sluchacze implements ActionListener {

    Okno o;

    Sluchacze(Okno o) {
        this.o = o;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == o.button) {
            int returnVal = o.fc.showDialog(o.frame, "Wybierz");
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                File file = o.fc.getSelectedFile();
                o.l.przypiszpliki(file);
            }
        }
        if (o.l.selected != null) {
            if (e.getSource() == o.button1) {
                String[] s = { "Tak", "Nie" };
                int x = JOptionPane.showOptionDialog(o.frame, "Czy usunąć?", "Usuń", 0, 0, null, s, s[1]);
                if (x == 0) {
                    o.l.selected.delete();
                    o.l.przypiszpliki(o.l.f);
                }
            }
            if (e.getSource() == o.button2) {
                try {
                    Files.copy(o.l.selected.toPath(),
                            Paths.get(o.l.selected.getParentFile().toPath() + "\\kopia-" + o.l.selected.getName()));
                    o.l.przypiszpliki(o.l.f);
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
            }
            if (e.getSource() == o.button3) {
                String name = JOptionPane.showInputDialog(o.frame, "Zmień nazwe");
                if (name != null) {
                    String s = o.l.selected.getParent();
                    o.l.selected.renameTo(new File(s + "\\" + name));
                    o.l.przypiszpliki(o.l.f);
                }
            }

            if (e.getSource() == o.button4) {
                String[] pizzas = { "ISO-8859-1" };
                String favoritePizza = (String) JOptionPane.showInputDialog(o.frame, "Z jakiego kodwania zmieniasz",
                        "Kodowanie", JOptionPane.QUESTION_MESSAGE, null, pizzas, pizzas[0]);

                FileInputStream fis;
                try {
                    fis = new FileInputStream(o.l.selected.getPath());
                    InputStreamReader isr = new InputStreamReader(fis, favoritePizza);

                    Reader in = new BufferedReader(isr);
                    StringBuffer buffer = new StringBuffer();

                    int ch;
                    while ((ch = in.read()) > -1) {
                        buffer.append((char) ch);
                    }
                    in.close();

                    FileOutputStream fos;
                    fos = new FileOutputStream(o.l.selected.getPath());
                    Writer out = new OutputStreamWriter(fos, "UTF8");
                    out.write(buffer.toString());
                    out.close();
                } catch (IOException e2) {
                    // TODO Auto-generated catch block
                    e2.printStackTrace();
                }

            }
            o.l.selected = null;
        }
    }
    
}
