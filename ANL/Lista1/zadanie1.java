class zadanie1{
public static void main(String[] args) {
    for(double i=10;i<21;i++){
        double x=1.0*Math.pow(10, -i);
        double wynik=12120*((x-Math.sin(x))/Math.pow(x, 3));
        System.out.println("duoble "+wynik);
    }
    for(float i=10;i<21;i++){
        float x=(float)Math.pow(10, -i);
        float wynik=(float)(12120.0*((x-Math.sin(x))/Math.pow(x, 3)));
        System.out.println("float "+wynik);
    }
}
}
