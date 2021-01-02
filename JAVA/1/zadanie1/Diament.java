package zadanie1;

public class Diament implements T{
    @Override
    public int gethardness(){
        return 10;
    }
    public int compareTo(T input){
        if(this.gethardness() < input.gethardness()){
            return -1;
        }
        else if(this.gethardness() > input.gethardness()){
            return 1;
        }
        return 0;
    }
}