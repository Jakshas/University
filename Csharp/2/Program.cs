//Jakub Szajner zadanie 1 i 2
using System;

namespace _2
{
    
    class Slownik<K,V>{
        public K klucz;
        public V wartosc;
        public Slownik<K,V> next;
        public void Add(K k , V w){
            if(this.next!=null){
                this.next.Add(k,w);
            }else{
                this.next=new Slownik<K,V>();
                this.next.klucz=k;
                this.next.wartosc=w;
                this.next.next=null;
            }
        }
        public V search(K k){
            if(Equals(k,this.klucz)){
               return this.wartosc;
            }
            else{
                if(this.next!=null)
               return this.next.search(k); 
            }
            return default(V);
        }
        public void delete(K k){
            if(this.klucz.Equals(k)){
                Slownik<K,V> pomoc1=this.next;
                this.wartosc=pomoc1.wartosc;
                this.next=pomoc1.next;
                pomoc1.next=null;
            }
            Slownik<K,V> pomoc=this;
            Slownik<K,V> pomocwcz=this;
            while(!k.Equals(pomoc.klucz)||pomoc.next==null){
                pomocwcz=pomoc;
                pomoc=pomoc.next;
            }
            if(k.Equals(pomoc.klucz)){
                pomocwcz.next=pomoc.next;
                pomoc.next=null;
            }
        }
        }
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
        class Lista<T>{
            Pole<T> pierwszy;
            Pole<T> ostatni;
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
        }
            class Program
    {
        static void Main(string[] args)
        {
            Slownik<int,int> s1=new Slownik<int, int>();
            s1.wartosc=11;
            s1.Add(1,1);
            s1.Add(2,3);
            Console.WriteLine(s1.next.klucz);
            Console.WriteLine(s1.search(1));
            s1.delete(1);
            Console.WriteLine(s1.search(1));
            Lista<int> lista=new Lista<int>();
            for(int i=0;i<10;i++)
            lista.dodajp(i);
            for(int i=15;i<20;i++)
            lista.dodajk(i);
            for(int i=0;i<3;i++)
            Console.WriteLine(lista.usunp().wartosc);
            for(int i=0;i<3;i++)
            Console.WriteLine(lista.usunk().wartosc);
        }
    }
    }
    

