
public class plik {
    public static void main(String[] args) {

        try {
            sprawdzpesel("11111111111");
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }

    static void sprawdzpesel(String S) throws Exception {
        if (S.length() != 11) {
            throw new Exception("String złej długości");
        }

        try {
            Integer.valueOf(S);
        } catch (Exception e) {
            throw new Exception("String zawiera litery");
        }

    }
}