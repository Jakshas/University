import java.util.Calendar;
import java.util.GregorianCalendar;

import javax.swing.AbstractListModel;

public class Kalendarz extends AbstractListModel {

    int rok;
    int miesiac;

    public Kalendarz(int r,int m){
        rok=r;
        miesiac=m;
    }

    void przelicz(int r,int m){
        rok=r;
        miesiac=m;
        fireContentsChanged(this, 0, getSize());
    }

    @Override
    public int getSize() {
        GregorianCalendar g = new GregorianCalendar(rok, miesiac, 1);
        if (g.get(Calendar.YEAR)==1582 && g.get(Calendar.MONTH)==9) {
            return 21;
        }
        return g.getActualMaximum(Calendar.DAY_OF_MONTH);

    }

    @Override
    public String getElementAt(int index) {
        GregorianCalendar g = new GregorianCalendar(rok, miesiac, 1);
        int indexx=index;
        if (rok == 1582 && miesiac == 9) {
            if (index>4) {
                indexx=index+10;
            }
        }

        g.add(Calendar.DAY_OF_MONTH, index);
        String s="";
        switch (g.get(Calendar.DAY_OF_WEEK)) {
            case 1:
                s=s+"Niedziela ";
                break;
            case 2:
                s=s+"Poniedziałek ";
                break;
            case 3:
                s=s+"Wtorek ";
                break;
            case 4:
                s=s+"Środa ";
                break;
            case 5:
                s=s+"Czwartek ";
                break;
            case 6:
                s=s+"Piatek ";
                break;
            case 7:
                s=s+"Sobota ";
                break;
            default:
                break;
        }
        s=s+(indexx+1)+" ";
        switch (g.get(Calendar.MONTH)) {
            case 0:
                s=s+"Styczeń ";
                break;
            case 1:
                s=s+"Luty ";
                break;
            case 2:
                s=s+"Marzec ";
                break;
            case 3:
                s=s+"Kwiecień ";
                break;
            case 4:
                s=s+"Maj ";
                break;
            case 5:
                s=s+"Czerwiec ";
                break;
            case 6:
                s=s+"Lipiec ";
                break;
            case 7:
                s=s+"Sierpień ";
                break;
            case 8:
                s=s+"Wrzesień ";
                break;
            case 9:
                s=s+"Październik ";
                break;
            case 10:
                s=s+"Listopad ";
                break;
            case 11:
                s=s+"Grudzień ";
                break;
            default:
                break;
        }
        return s;
        
    }
    
}
