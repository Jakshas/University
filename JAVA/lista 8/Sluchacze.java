import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.AdjustmentEvent;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.awt.event.AdjustmentListener;

import javax.swing.JSpinner;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

public class Sluchacze implements ActionListener, ChangeListener, AdjustmentListener {
    Okno ok;

    Sluchacze(Okno o) {
        ok = o;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == ok.lewo) {
            GregorianCalendar g1 = new GregorianCalendar(ok.rok, ok.setmies, 1);
            g1.add(Calendar.MONTH, -1);
            ok.rok = g1.get(Calendar.YEAR);
            ok.setmies = g1.get(Calendar.MONTH);
            ok.wypiszwszy();
        }
        if (e.getSource() == ok.prawo) {
            GregorianCalendar g1 = new GregorianCalendar(ok.rok, ok.setmies, 1);
            g1.add(Calendar.MONTH, 1);
            ok.rok = g1.get(Calendar.YEAR);
            ok.setmies = g1.get(Calendar.MONTH);
            ok.wypiszwszy();
        }
    }

    @Override
    public void stateChanged(ChangeEvent e) {
        int r = (int) ((JSpinner) e.getSource()).getValue();
        ok.rok = r;
        ok.wypiszwszy();
    }

    @Override
    public void adjustmentValueChanged(AdjustmentEvent e) {
        int i=e.getValue();
        ok.setmies = i;
        ok.wypiszwszy();

    }
    
}
