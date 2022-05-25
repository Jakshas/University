import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertThrows;

import java.util.GregorianCalendar;

import org.junit.Test;

public class Zadanie2test {
    @Test
    public void dodajWydarzenie(){
        Zadanie2 z2 = new Zadanie2();
        GregorianCalendar c1 = new GregorianCalendar(2000,1,1);
        GregorianCalendar c2 = new GregorianCalendar(2000,1,2);
        z2.dodajWydarzenie(new Wydarzenie("1", c1 , c2));
        assertEquals(z2.list.size(), 1);
    }
    @Test
    public void dodajPodczasInnego(){
        Zadanie2 z2 = new Zadanie2();
        GregorianCalendar c1 = new GregorianCalendar(2000,1,1);
        GregorianCalendar c2 = new GregorianCalendar(2000,1,3);
        z2.dodajWydarzenie(new Wydarzenie("1", c1 , c2));
        z2.dodajWydarzenie(new Wydarzenie("2", new GregorianCalendar(2000,1,2) , new GregorianCalendar(2000,1,4)));
        assertEquals(z2.list.size(), 1);
    }
    @Test
    public void koniecKiedyPoczatek(){
        Zadanie2 z2 = new Zadanie2();
        GregorianCalendar c1 = new GregorianCalendar(2000,1,1);
        GregorianCalendar c2 = new GregorianCalendar(2000,1,3);
        z2.dodajWydarzenie(new Wydarzenie("1", c1 , c2));
        z2.dodajWydarzenie(new Wydarzenie("2", new GregorianCalendar(2000,1,3) , new GregorianCalendar(2000,1,4)));
        assertEquals(z2.list.size(), 2);
    }
    @Test
    public void modyfiukujPodczasInnego(){
        Zadanie2 z2 = new Zadanie2();
        GregorianCalendar c1 = new GregorianCalendar(2000,1,1);
        GregorianCalendar c2 = new GregorianCalendar(2000,1,3);
        z2.dodajWydarzenie(new Wydarzenie("1", c1 , c2));
        z2.dodajWydarzenie(new Wydarzenie("2", new GregorianCalendar(2000,1,3) , new GregorianCalendar(2000,1,4)));
        Throwable throwable = assertThrows(Exception.class, () -> z2.zmienWydarzenie("2", new GregorianCalendar(2000,1,2) , new GregorianCalendar(2000,1,4)));
        assertEquals("Wydrzenie nachodzi na inne.", throwable.getMessage());
        assertEquals(z2.list.size(), 2);
    }
}
