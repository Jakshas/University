import java.util.Calendar;
import java.util.GregorianCalendar;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JSpinner;
import javax.swing.JTabbedPane;
import javax.swing.JToolBar;
import javax.swing.ListCellRenderer;

import java.awt.event.*;
import java.awt.*;

public class Okno {
    JFrame frame;
    JTabbedPane tp;
    int rok;
    GregorianCalendar czasg;
    JPanel prok;
    JPanel pmiesiac;
    JPanel[] mies;
    int setmies=-1;
    Color[] coltab= new Color[12];
    JToolBar pasek;
    JButton lewo, prawo;
    JSpinner spinner;
    JScrollBar scroll;

    void wypelnijcoltab(){
        for (int i = 0; i < coltab.length; i++) {
            if (i==setmies) {
                coltab[i]=Color.BLUE;
            }else{
                coltab[i]=Color.lightGray;
            }
        }
    }

    Okno(){
        Calendar g= GregorianCalendar.getInstance();
        setmies=g.get(Calendar.MONTH);
        rok=g.get(Calendar.YEAR);
        wypelnijcoltab();
        frame=new JFrame();   
        frame.setLayout(new BoxLayout(frame.getContentPane(), BoxLayout.Y_AXIS)); 
        prok=new JPanel();
        prok.setSize(600, 800);
        pmiesiac=new JPanel();
        tp=new JTabbedPane();  
        czasg = new GregorianCalendar(rok,Calendar.JANUARY,1);
        tp.setBounds(0,0,800,600);
        frame.add(tp); 
        prok.addMouseListener(mouseList); 
        frame.setSize(800,670);

        Sluchacze s=new Sluchacze(this);
        pasek =new JToolBar();
        lewo=new JButton("Prev");
        lewo.addActionListener(s);
        prawo=new JButton("Next");
        prawo.addActionListener(s);
        spinner= new JSpinner();
        spinner.setValue(rok);
        spinner.addChangeListener(s);

        scroll= new JScrollBar(0, setmies, 1 , 0, 12);
        scroll.addAdjustmentListener(s);
        pasek.setLayout(new GridLayout(1,4));
        pasek.setFloatable(false);
        pasek.add(lewo);
        pasek.add(prawo);
        pasek.add(spinner);
        pasek.add(scroll);
        frame.add(pasek);
        frame.setDefaultCloseOperation(3);
        frame.setResizable(false);

        wypiszrok(); 
        pmiesiac=wypiszlist(pmiesiac, setmies);
        tp.add("rok",prok);
        tp.add("miesiac",pmiesiac);  
        frame.setVisible(true);  
    }

    void wypiszwszy(){
        wypelnijcoltab();
        czasg = new GregorianCalendar(rok,setmies,1);
        pmiesiac= wypiszlisp(pmiesiac, setmies);
        czasg = new GregorianCalendar(rok,Calendar.JANUARY,1);
        prok=wypiszrok();
        tp.revalidate();
        tp.repaint();
        
    }

    private MouseListener mouseList = new MouseAdapter()
    {
        @Override
        public void mouseClicked(MouseEvent ev)
        {
            int x1=ev.getX()/200;
            int y1=ev.getY()/200;
            setmies=(y1*4)+x1;
            wypiszwszy();
        }
    };
    JList l1,l2,l3;
    Kalendarz k1,k2,k3;

    JPanel wypiszlist(JPanel jp, int miesiac){
        GregorianCalendar g1= new GregorianCalendar(rok,miesiac,1);
        ListCellRenderer renderer = new Kreslarz();
        jp= new JPanel();
        jp.setLayout(new GridLayout(1,3));
        g1.add(Calendar.MONTH, -1);
        k1= new Kalendarz(g1.get(Calendar.YEAR),g1.get(Calendar.MONTH) );
        l1= new JList(k1);
        l1.setCellRenderer(renderer);
        jp.add(l1);
        l1.repaint();
        g1.add(Calendar.MONTH, 1);
        k2= new Kalendarz(g1.get(Calendar.YEAR),g1.get(Calendar.MONTH) );
        l2= new JList(k2);
        l2.setCellRenderer(renderer);
        jp.add(l2);
        l2.repaint();
        g1.add(Calendar.MONTH, 1);
        k3= new Kalendarz(g1.get(Calendar.YEAR),g1.get(Calendar.MONTH) );
        l3= new JList(k3);
        l3.setCellRenderer(renderer);
        jp.add(l3);
        l3.repaint();
        return jp;
    }
    JPanel wypiszlisp(JPanel jp, int miesiac){
        GregorianCalendar g1= new GregorianCalendar(rok,miesiac,1);
        g1.add(Calendar.MONTH, -1);
        k1.przelicz(g1.get(Calendar.YEAR),g1.get(Calendar.MONTH));
        g1.add(Calendar.MONTH, 1);
        k2.przelicz(g1.get(Calendar.YEAR),g1.get(Calendar.MONTH));
        g1.add(Calendar.MONTH, 1);
        k3.przelicz(g1.get(Calendar.YEAR),g1.get(Calendar.MONTH));
        return jp;
    }
    boolean czypazdziernik(GregorianCalendar g){
        if (g.get(Calendar.YEAR)==1582 && g.get(Calendar.MONTH)==9) {
            return true;
        }
        return false;
    }

    JPanel wypiszmies(JPanel jp, int miesiac, GregorianCalendar czas){
        jp=new JPanel();
        jp.setLayout(new GridLayout(6,7));
        czas.set(Calendar.MONTH, miesiac);
        int dzien=czas.get(Calendar.DAY_OF_WEEK)-1;
        if (dzien==0) {
            dzien=7;
        }
        int j=1,el=0;
        for (int j2 = 1; j2 < dzien; j2++) {
            JPanel p=new JPanel();
            p.setBackground(coltab[miesiac]);
            jp.add(p);
            el++;
        }
        int i=czas.get(Calendar.MONTH);
        while (czas.get(Calendar.MONTH)==i) {
            JPanel p=new JPanel();
            p.setBorder(BorderFactory.createLineBorder(Color.black));
            if (j==5 && czypazdziernik(czas)) {
                j=j+10;
            }
            JLabel l =new JLabel(""+j);
            if (czas.get(7)==1) {
                l.setForeground(Color.red);
            }
            p.add(l);
            jp.add(p);
            j++;
            el++;
            czas.add(Calendar.DAY_OF_YEAR, 1);
            if(czas.get(Calendar.DAY_OF_MONTH)==1 && el>10){
                while(el<42){
                    JPanel p1=new JPanel();
                    p1.setBackground(coltab[i]);
                    jp.add(p1);
                    el++;
                }
            }
        }   
        return jp;
    }

    JPanel wypiszrok(){
        GregorianCalendar czas = new GregorianCalendar(rok,Calendar.JANUARY,1);
        prok.removeAll();
        prok.setSize(600, 800);
        prok.setLayout(new GridLayout(3,4));
        prok.addMouseListener(mouseList); 
        mies= new JPanel[12];
        for (int i = 0; i < 12; i++) {
            mies[i]=wypiszmies(mies[i],i,czas);
            prok.add(mies[i]);
        }
        czasg.add(Calendar.YEAR, -1);
        return prok;
    }
}
