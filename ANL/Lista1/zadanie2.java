public class zadanie2 {
    public static void main(String[] args) {
        for(int i=11;i<21;i++){
            double zmienna=Math.pow(10, -1*i);
            double w=12120*((zmienna-Math.sin(zmienna))/Math.pow(zmienna,3));
            System.out.println(w);
        }
    }
}
