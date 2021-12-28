public class rpis {
public static double po;
public static double policz(double t,double p) {
    po=p;
    double a=0,b=t,M=10;
    double h=b-a;
    double R[][]=new double[(int)M][(int)M];
    R[0][0]=(b-a)*(oblicz2(a)+oblicz2(b))/2;
    for(int n=1;n<M;n++){
        h=h/2;
        R[n][0]=R[n-1][0]/2+h*suma(n,a,h);
        for(int m=1;m<=n;m++){
            R[n][m]=R[n][m-1]+((R[n][m-1]-R[n-1][m-1])/(Math.pow(4, m)-1));
            if(Math.abs(R[n][m]-R[n][m-1])<0.0001){
                return R[n][m];
            }
        }
    }return 0;
}
public static double oblicz(double a){
    double x=Math.exp(-1*(a*a/2));
    return x;
}
public static double oblicz2(double x){
    double w=Math.pow(1+((x*x)/po),(-(po+1)/2));
    return w;
}
public static double suma(double n,double a,double h) {
    double wynik=0;
    for(int i=1;i<Math.pow(2, n-1)+1;i++){
        wynik= wynik+oblicz2(a+((2*i-1)*h));
    }
    return wynik;
}
public static void main(String[] args) {
<<<<<<< HEAD
    double n=1;
    double x=1;
    double wyn=(1/2.0)+(ulamek(n)*policz(x,n));
    System.out.println("Dla stopnia swobody "+n+" i x="+ x+" otrzymujemy "+wyn);
    n=5;
    x=2;
    wyn=(1/2.0)+ulamek(n)*policz(x,n);
    System.out.println("Dla stopnia swobody "+n+" i x="+ x+" otrzymujemy "+wyn);
    n=10;
    x=0.1;
    wyn=(1/2.0)+ulamek(n)*policz(x,n);
    System.out.println("Dla stopnia swobody "+n+" i x="+ x+" otrzymujemy "+wyn);
    n=4;
    x=4;
    wyn=(1/2.0)+ulamek(n)*policz(x,n);
    System.out.println("Dla stopnia swobody "+n+" i x="+ x+" otrzymujemy "+wyn);
=======
    // double n=1;
    // double x=1;
    // double wyn=(1/2.0)+(ulamek(n)*policz(x,n));
    // System.out.println("Dla stopnia swobody "+n+" i x="+ x+" otrzymujemy "+wyn);
    // n=5;
    // x=2;
    // wyn=(1/2.0)+ulamek(n)*policz(x,n);
    // System.out.println("Dla stopnia swobody "+n+" i x="+ x+" otrzymujemy "+wyn);
    // n=10;
    // x=0.1;
    // wyn=(1/2.0)+ulamek(n)*policz(x,n);
    // System.out.println("Dla stopnia swobody "+n+" i x="+ x+" otrzymujemy "+wyn);
    // n=4;
    // x=4;
    // wyn=(1/2.0)+ulamek(n)*policz(x,n);
    // System.out.println("Dla stopnia swobody "+n+" i x="+ x+" otrzymujemy "+wyn);
>>>>>>> 17217ae776ba9628dbc9594a72934a138d91aa54
}
public static double ulamek(double n){
    double wyng;
    double wynd;
    if(n==1){
        return 1/Math.PI;
    }
    if(n%2==0){
        wyng=(pow2(n-1)*Math.sqrt(Math.PI))/Math.pow(2, n/2);
        wynd=pow1((n-2)/2);
        System.out.println(wyng);
        System.out.println((wynd*Math.sqrt(Math.PI*n)));
        return wyng/(wynd*Math.sqrt(Math.PI*n));
    }
        else{
        wyng=pow1((n-1)/2);
        wynd=(pow2(n-2)*Math.sqrt(Math.PI))/Math.pow(2, (n-1)/2);
        System.out.println(wyng);
        System.out.println((wynd*Math.sqrt(Math.PI*n)));
        return wyng/(wynd*Math.sqrt(Math.PI*n));
        }
}
public static double pow1(double v) {
    if(v<=1){
        return 1;
    }else
    return v*pow1(v-1);
}
public static double pow2(double v) {
    if(v<=1){
        return 1;
    }else
    return v*pow2(v-2);
}
}