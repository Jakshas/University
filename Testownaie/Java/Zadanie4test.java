import static org.junit.Assert.assertEquals;

import java.util.Arrays;
import java.util.stream.Stream;

import org.junit.jupiter.api.DynamicTest;
import org.junit.jupiter.api.TestFactory;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

public class Zadanie4test {
    @ParameterizedTest
    @MethodSource("Zadanie4test#generate")
    void testexisting(double x1, double y1, double x2, double y2,double x3, double y3){
        Zadanie4 z4 = new Zadanie4();
        assertEquals(null,z4.check_if_triangle(x1, y1, x2, y2, x3, y3));
    }
    static Stream<Arguments> generate() {
        return Stream.of(
            Arguments.of(1, 0, -1, 0, 0, 0),
            Arguments.of(1, 1, 1, 1, 1, 1)
        );
    }
    @TestFactory
    Iterable<DynamicTest> testwhich(){
        Zadanie4 z4 = new Zadanie4();
        return Arrays.asList(
            DynamicTest.dynamicTest("Test równoboczny", () -> assertEquals(triangle.Rownoramienny,z4.check_if_triangle(1, 0, -1, 0, 0, 1.73205080757))),
            DynamicTest.dynamicTest("Test równoramienny", () -> assertEquals(triangle.Rownoramienny,z4.check_if_triangle(1, 0, -1, 0, 0, 2))),
            DynamicTest.dynamicTest("Test różnoboczny", () -> assertEquals(triangle.Roznoboczny,z4.check_if_triangle(1, 0, -1, 0, 1, 5)))
        );
    }
    
}
