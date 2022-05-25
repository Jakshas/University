import static org.junit.Assert.assertEquals;
import static org.junit.jupiter.api.DynamicTest.dynamicTest;

import java.util.Arrays;
import java.util.stream.Stream;

import org.junit.jupiter.api.DynamicTest;
import org.junit.jupiter.api.TestFactory;

public class Zadanie5test {
    public class CustomPair {
        int key;
        String value;
    }
    @TestFactory
    Stream<DynamicTest> testDifferentMultiplyOperations() {
        CustomPair[] data = new CustomPair[4000];
        
        for(int i = 0; i< 4000; i++){
            data[i] = new CustomPair();
            data[i].key = i+1;
            data[i].value = Zadanie5.integerToRoman(i+1);
        }
        return Arrays.stream(data).map(entry -> {
            int m = entry.key;
            String expected = entry.value;
            return dynamicTest(m + " = " + expected, () -> {
                assertEquals(expected, Zadanie5.integerToRoman(m));
            });
        });
    }
}
