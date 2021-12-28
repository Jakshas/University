public class zadanie5 {
    public static void main(String[] args) {
        double suma=0,sumt=1,sumtt=suma,i=0;
        do{
            sumtt=suma;
            sumt=suma+4*(Math.pow(-1, i)/(2*i+1));
                suma=sumt;
            i++;
        }while(Math.abs(sumtt-suma)>0.0001);
        System.out.println(i-1);
    }
}
