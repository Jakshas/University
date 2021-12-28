package obliczenia;

public class Rozne extends Wyrazenie {
    Wyrazenie a;
    Wyrazenie b;    

    public Rozne(Wyrazenie a,Wyrazenie b){
        this.a=a;
        this.b=b;
    }    

    @Override
    public String toString() {
        
        return "("+(a.toString()+"!="+b.toString())+")";
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Rozne) {
            return ((Rozne)obj).a.equals(this.a) && ((Rozne)obj).b.equals(this.b);
        }
        return false;
    }
    @Override
    public int oblicz() {
        if(a.equals(b)){
            return 0;
        }else{
            return 1;
        }
    }
}
