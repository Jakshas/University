import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import static org.junit.Assert.assertEquals;

public class Zadanie3 {
    @Test
    @ExtendWith(FileExtension.class)
    public void test(@FileExtension.File(path = "C:\\Projekty\\University\\Testownaie\\Java\\file.txt") String content) {
        System.out.println(content);
        assertEquals(1, 1);
    }
}
