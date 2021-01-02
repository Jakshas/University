public class zadanie3 {
    public static void main(String[] args) {
        for(double i=2;i<51;i++){
            System.out.println(f(i));
        }
    }
    public static double f(double x){
        if(x==0){
            return 1.0;
        }
        if(x==1){
            return (-1.0/7.0);
        }
        double f1=69.0*f(x-1);
        double f2=10.0*f(x-2);

        return (1.0/7.0)*(f1+f2);
    }
}
