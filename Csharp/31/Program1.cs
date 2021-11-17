//Jakub Szajner zadanie 1 lista 4
using System;
using System.Collections;

namespace _31
{
    class Pole<T>{
                public T wartosc;
                public Pole<T> next;
                public Pole<T> prev;
                public Pole(T t,Pole<T> next,Pole<T> prev){
                    this.wartosc=t;
                    this.next=next;
                    this.prev=prev;
                }
            }
        class Lista<T>:System.Collections.IEnumerable{
            Pole<T> pierwszy;
            Pole<T> ostatni;
            int length;
            public Lista(){
                this.pierwszy=null;
                this.ostatni=null;
            }
            public bool czypusta(){
                if(this.pierwszy==null){
                    return true;
                }
                return false;
            }
            public void dodajp(T t){
                if(this.pierwszy==null){
                    this.pierwszy=new Pole<T>(t,null,null);
                    this.ostatni=this.pierwszy;
                }else{
                    Pole<T> p=new Pole<T>(t,this.pierwszy,null);
                    this.pierwszy=p;
                }
            }
            public void dodajk(T t){
                if(this.pierwszy==null){
                    this.pierwszy=new Pole<T>(t,null,null);
                    this.ostatni=this.pierwszy;
                }else{
                    Pole<T> p=new Pole<T>(t,null,this.ostatni);
                    this.ostatni=p;
                }
            }
            public Pole<T> usunp(){
                if(this.pierwszy==null){
                    return null;
                }else{
                Pole<T> pole=this.pierwszy;
                this.pierwszy=this.pierwszy.next;
                return pole;
            }}
            public Pole<T> usunk(){
                if(this.ostatni==null){
                    return null;
                }else{
                Pole<T> pole=this.ostatni;
                this.ostatni=this.ostatni.prev;
                return pole;
            }}
            override public string ToString(){
                string lista="";
                Pole<T> element=this.pierwszy;
                while(element.next!=null){
                lista=lista+","+element.wartosc;
                }
                return lista;
            }
            public int Length{
                get{if(this.length!=0){return this.length;}
                    Pole<T> pom=this.pierwszy;
                    int x=0;
                    while(pom!=null){
                        x++;
                        pom=pom.next;
                    }
                    this.length=x;
                    return x;}}
            public T this[int indeks] 
                {
                    get {
                        Pole<T> pom=this.pierwszy;
                        int x=0;
                        while(x!=indeks&&pom.next!=null){
                            pom=pom.next;
                            x++;
                        }
                        return pom.wartosc;}}
                
            
        public IEnumerator GetEnumerator()
        {

            return new ListEnum<T>(pierwszy);
        }
        }
        class ListEnum<T>:IEnumerator{
            Pole<T> pierwszy;
            Pole<T> current;
            public ListEnum(Pole<T> pierwszy) { 
                this.pierwszy = pierwszy;
             }
            public bool MoveNext() { 
                if (this.current == null) 
                this.current = this.pierwszy;
                else this.current = this.current.next;
                return this.current != null; }
            public object Current {
                 get {
                     return current.wartosc;
                     }}
            public void Reset() { 
                this.current = this.pierwszy; }
        }
    class Program
    {
        static void Main(string[] args)
        {
            Lista<int> list = new Lista<int>();
            list.dodajp(4);
            list.dodajp(8);
            foreach(int e in  list)
            Console.WriteLine(e);
            Console.WriteLine(list.Length);
            Console.WriteLine(list[1]);
        }
    }
}
