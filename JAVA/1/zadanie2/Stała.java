package zadanie2;

public class Stała extends Wyrażenie{
    int stała;
    public Stała(int stała)
{
    this.stała = stała;
}
public int oblicz(){
    return stała;
}
public String toString(){
    return String.valueOf(stała);
}
}