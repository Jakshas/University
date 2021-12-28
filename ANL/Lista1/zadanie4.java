
public class zadanie4 {
    public static void main(String[] args) {
        double f1=Math.log(2021.0/2020.0),f2;
        for(double i=1;i<21;i++){
            f2=1/i-(2020*f1);
            f1=f2;
            System.out.println(f1);
        }
    }
}
