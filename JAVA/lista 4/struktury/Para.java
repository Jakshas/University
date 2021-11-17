package struktury;
public class Para {
    public final String klucz;
    private double wartość;
    public Para(){
        klucz=null;
        wartość=0;
    }
    public Para(double w , String k){
        if(k==null|k==""){
            throw new IllegalArgumentException("klucz musi miec wartosc");
        }
        klucz=k.toLowerCase();
        wartość=w;
    }
    public String toString() {

        return wartość + " | " + klucz;
    }
    public double getWartość() {
        return wartość;
    }
    public void setWartość(double wartość) {
        this.wartość = wartość;
    }
    public boolean equals(Object obj) {
        if(obj instanceof Para){
            return this.klucz==((Para)obj).klucz;
        }
        return false;     
    }
}
