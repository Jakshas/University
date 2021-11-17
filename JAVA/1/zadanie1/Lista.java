package zadanie1;
public class Lista{
    Element pierwszy;
    Lista(){
        this.pierwszy=null;
    }
    public void add(T w){
        Element e = new Element(w);
        if(pierwszy==null){
            pierwszy=e;
        }else{
            Element pom=pierwszy;
            while(pom.next!=null&&pom.next.wartosc.gethardness()<e.wartosc.gethardness()){
                pom=pom.next;
            }
            if(pom.next==null&&pierwszy.wartosc.gethardness()<e.wartosc.gethardness()){
                pom.next=e;
            }else{
                if(pierwszy.wartosc.gethardness()>e.wartosc.gethardness()){
                    e.next=pierwszy;
                    pierwszy=e;
                }else{
                e.next=pom.next;
                pom.next=e;
            }}
        }
    }
    public T pop(){
        T element=pierwszy.wartosc;
        pierwszy=pierwszy.next;
        return element;
    }
    public void print(){
        Element pom=pierwszy;
        while(pom!= null){
            System.out.println(pom.wartosc);
            pom=pom.next;
        }
    }
}