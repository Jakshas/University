package zadanie1;

public class Krzem implements T{
    public int gethardness(){
        return 7;
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