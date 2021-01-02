import java.io.*;

public class kierwe {
    public static void main(String[] args) throws IOException {
        String[][] tab=new String[96][61];
try (BufferedReader br = new BufferedReader(new FileReader("1.csv"))) {
    String line;
    int j=0;
    while ((line = br.readLine()) != null) {
        String[] values = line.split(";");
        for(int i=0;i<values.length;i++){
            tab[j][i]=values[i];
            Integer.parseInt("0");
        }
        j++;
            }
        }
        int[][] tabi= new int[96][61];
        for(int i=0;i<96;i++){
            for(int j=0;j<61;j++){
                tabi[i][j]=Integer.parseInt(tab[i][j].replace(" ", ""));
            }
        }
    }
}