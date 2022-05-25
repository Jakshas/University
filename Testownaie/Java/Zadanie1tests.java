import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNull;
import static org.junit.Assert.assertThrows;

import java.util.ArrayList;

import org.junit.Test;

public class Zadanie1tests {
    @Test
    public void test_prawidlowe(){
        Zadanie1 z1 = new Zadanie1();
        ArrayList<String> l1 = new ArrayList<String>();
        l1.add("1");
        l1.add("2");
        l1.add("3");
        ArrayList<String> l2 = new ArrayList<String>();
        l2.add("1");
        l2.add("3");
        l1 = z1.metoda(l1, "2");
        assertEquals(l1, l2);
    }
    @Test
    public void test_null_argument(){
        Zadanie1 z1 = new Zadanie1();
        ArrayList<String> l1 = new ArrayList<String>();
        l1.add("1");
        l1.add("2");
        l1.add("3");
        Throwable throwable = assertThrows(IllegalArgumentException.class, () -> z1.metoda(l1, null));
        assertEquals("String ma wartośc null", throwable.getMessage());
        throwable = assertThrows(IllegalArgumentException.class, () -> z1.metoda(null, "2"));
        assertEquals("Lista ma wartośc null", throwable.getMessage());
    }
    @Test
    public void test_null_wartosc(){
        Zadanie1 z1 = new Zadanie1();
        ArrayList<String> l1 = new ArrayList<String>();
        l1.add("1");
        l1.add(null);
        l1.add("3");
        assertNull(z1.metoda(l1, "2").get(1));
    }
    
}
