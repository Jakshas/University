public class zadanie5 {
    public static double policz(double l,double t) {
        double a=l,b=t,M=17;
        double h=b-a;
        double R[][]=new double[(int)M][(int)M];
        R[0][0]=(b-a)*(oblicz(a)+oblicz(b))/2;
        for(int n=1;n<M;n++){
            h=h/2;
            R[n][0]=R[n-1][0]/2+h*suma(n,a,h);
            for(int m=1;m<=n;m++){
                R[n][m]=R[n][m-1]+((R[n][m-1]-R[n-1][m-1])/(Math.pow(4, m)-1));
            }
        }return R[16][16];
    }
    public static double suma(double n,double a,double h) {
        double wynik=0;
        for(int i=1;i<Math.pow(2, n-1)+1;i++){
            wynik= wynik+oblicz(a+((2*i-1)*h));
        }
        return wynik;
    }
    public static double oblicz(double a){
        double x=(2021.0*Math.pow(a, 5))-(2020.0*Math.pow(a, 4))+(2019.0*Math.pow(a, 2));
        //double x=1/(1+25*x*x);
        //double x=Math.sin((7*a) - 2)/a;
        return x;
    }
    public static void main(String[] args) {
        System.out.println(policz(-1, 2));
    }
}
