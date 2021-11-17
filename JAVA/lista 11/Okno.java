import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.JToolBar;

import java.awt.*;
import java.io.File;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class Okno {
    JFrame frame;
    JList list;
    JScrollPane spanel;
    JToolBar bar;
    JButton button, button1, button2, button3, button4;
    JLabel file;
    JFileChooser fc;
    Sluchacze sl;
    Logika l;

    
    Okno(){

        sl = new Sluchacze(this);
        frame = new JFrame();
		frame.setLayout(new BorderLayout());
		l = new Logika(this);
        list = new JList(l.p);
		list.setCellRenderer(new Kreslarz(l));
		list.setFixedCellHeight(20);
		spanel = new JScrollPane(list);
        bar = new JToolBar();
		button = new JButton("Wybierz");
		button1 = new JButton("Usuń");
		button2 = new JButton("Kopiuj");
		button3 = new JButton("Zmień nazwe");
		button4 = new JButton("Zmień kodowanie");
        file = new JLabel("NAZWA FOLDERU");
        fc = new JFileChooser();
        fc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
        fc.setCurrentDirectory(new File("C:\\"));
        frame.setSize(400, 500);
		button.addActionListener(sl);
		button1.addActionListener(sl);
		button2.addActionListener(sl);
		button3.addActionListener(sl);
		button4.addActionListener(sl);
		bar.add(button);
		bar.add(button1);
		bar.add(button2);
		bar.add(button3);
		bar.add(button4);
        bar.setFloatable(false);
        frame.getContentPane().add(file, BorderLayout.NORTH);
        frame.getContentPane().add(spanel, BorderLayout.CENTER);
        frame.getContentPane().add(bar, BorderLayout.SOUTH);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

		list.addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e) {
				if (e.getClickCount() == 1 && e.getY()/20<l.ft.length) {
					int c = e.getY();
					int y = c/20;
					l.selected=l.ft[y];
                  }
                if (e.getClickCount() == 2 && e.getY()/20<l.ft.length) {
					int c = e.getY();
					int y = c/20;
					l.przypiszpliki(l.ft[y]);
                  }
            }});
    }

}
