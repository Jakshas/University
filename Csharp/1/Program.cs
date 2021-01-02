//Jakub Szajner lista 2 zadanie 2 i 3
using System;

namespace _1
{
   public class BigNum
    {
        int wartoc;
        public BigNum(int wart){
            this.wartoc=wart;
        }
        public BigNum(){
            this.wartoc=0;
        }
        public void wypisz(){
            Console.WriteLine(this.wartoc);
        }
        public static BigNum dodaj(BigNum a,BigNum b){
            BigNum w= new BigNum(a.wartoc+b.wartoc);
            return w;        }
        public static BigNum odejmij(BigNum a,BigNum b){
            BigNum w= new BigNum(a.wartoc-b.wartoc);
            return w;        }
        public static BigNum pomnuz(BigNum a,BigNum b){
                        BigNum w= new BigNum(a.wartoc*b.wartoc);
            return w;
        }
        public static BigNum podziel(BigNum a,BigNum b){
            BigNum w= new BigNum(a.wartoc/b.wartoc);
            return w;
        }
        public void dodaj(BigNum a){
            this.wartoc=this.wartoc+a.wartoc;
        }
        public void odejmij(BigNum a){
            this.wartoc=this.wartoc-a.wartoc;
        }
        public void pomnuz(BigNum a){
            this.wartoc=this.wartoc*a.wartoc;
        }
        public void podziel(BigNum a){
            this.wartoc=this.wartoc/a.wartoc;
        }
    }
    class Array{
        int popczatek;
        int koniec;

        Pole ostatnio;
        Pole pierwsze;
        Pole ostatnie;
        class Pole{
           public int wartosc;
            public int indeks;
            public Pole nast;
            public Pole poprz;
            public Pole(){
                this.wartosc=0;
                this.indeks=0;
                this.nast=null;
                this.poprz=null;
            }
            ~Pole(){

            }
        }
        public Array(){
            this.popczatek=0;
            this.koniec=0;
            this.ostatnio=null;
            this.pierwsze=null;
            this.ostatnie=null;
        }
        public Array(int p,int k){
            this.ostatnio=new Pole();
            this.pierwsze=this.ostatnio;
            this.popczatek=p;
            this.koniec=k;
            this.ostatnio.indeks=p;
            if(p==k){
                this.ostatnie=this.ostatnio;
            }else{
                Pole wczesniejszy=this.ostatnio;
            for(int i=p+1;i<=k;i++){
                Pole akt=new Pole();
                akt.indeks=i;
                wczesniejszy.nast=akt;
                akt.poprz=wczesniejszy;
                wczesniejszy=akt;
            }
            this.ostatnie=wczesniejszy;
        }
        }
        public void set(int indeks,int wartosc){
            if(this.ostatnio.indeks==indeks){
                this.ostatnio.wartosc=wartosc;
            }
            if(this.ostatnio.indeks<indeks){
                while(this.ostatnio.indeks<indeks&&this.ostatnio.nast!=null){
                    this.ostatnio=this.ostatnio.nast;
                }
                if(this.ostatnio.indeks==indeks){
                    this.ostatnio.wartosc=wartosc;
                }
            }else{
                while(this.ostatnio.indeks>indeks&&this.ostatnio.poprz!=null){
                    this.ostatnio=this.ostatnio.poprz;
                }
                if(this.ostatnio.indeks==indeks){
                    this.ostatnio.wartosc=wartosc;
                }
            }
        }
        public int get(int indeks){
            if(this.ostatnio.indeks==indeks){
                return this.ostatnio.wartosc;
            }
            if(this.ostatnio.indeks<indeks){
                while(this.ostatnio.indeks<indeks&&this.ostatnio.nast!=null){
                    this.ostatnio=this.ostatnio.nast;
                }
                if(this.ostatnio.indeks==indeks){
                    return this.ostatnio.wartosc;
                }
            }else{
                while(this.ostatnio.indeks>indeks&&this.ostatnio.poprz!=null){
                    this.ostatnio=this.ostatnio.poprz;
                }
                if(this.ostatnio.indeks==indeks){
                    return this.ostatnio.wartosc;                }
            }
            return 0;
        }
        public void append(int p,int k)//ustawia nowe przedzialy w liscie
        {
            if(p<this.popczatek){
                for(int i=this.pierwsze.indeks-1;i>=p;i--){
                    Pole akt=new Pole();
                    akt.nast=this.pierwsze;
                    akt.indeks=i;
                    this.pierwsze.poprz=akt;
                    this.pierwsze=akt;
                }
                this.popczatek=p;
            }
            if(k>this.koniec){
                for(int i=this.ostatnie.indeks+1;i<=k;i++){
                    Pole akt=new Pole();
                    akt.poprz=this.ostatnie;
                    akt.indeks=i;
                    this.pierwsze.poprz=akt;
                    this.pierwsze=akt;
                }
                this.koniec=k;
            }
            if(p>this.popczatek){
                this.ostatnio=this.pierwsze;
                while(this.ostatnio.indeks<p){
                    Pole akt=this.ostatnio;
                    this.ostatnio=this.ostatnio.nast;
                    this.ostatnio.poprz=null;
                    akt.nast=null;
                    akt.poprz=null;
                }
                this.pierwsze=this.ostatnio;
                this.popczatek=p;
            }
            if(k<this.koniec){
                this.ostatnio=this.ostatnie;
                while(this.ostatnio.indeks>k){
                    Pole akt=this.ostatnio;
                    this.ostatnio=this.ostatnio.poprz;
                    this.ostatnio.nast=null;
                    akt.nast=null;
                    akt.poprz=null;
                }
                this.ostatnie=this.ostatnio;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("a");
            BigNum a= new BigNum(10);
            Console.WriteLine("a");
            BigNum b= new BigNum(12);
            BigNum w;
            w=BigNum.podziel(a,b);
            w.wypisz();
            w=BigNum.dodaj(a,b);
            w.wypisz();
            w=BigNum.odejmij(a,b);
            w.wypisz();
            w=BigNum.pomnuz(a,b);
            w.wypisz();

            Array ar= new Array(0,10);
            ar.set(3,10);
            Console.WriteLine(ar.get(3));
            Console.WriteLine(ar.get(7));
            ar.append(-2,8);
            ar.set(-2,5);
            Console.WriteLine(ar.get(-2));
        }
    }
}
