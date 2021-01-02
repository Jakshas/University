//Jakub Szajner zadanie 2 lista 4
using System;
using System.Collections;

namespace _3
{
    class PrimeCollection : System.Collections.IEnumerable
    {
        int wartosc;
        public IEnumerator GetEnumerator()
        {

            return new Pierwsza();
        }
    }
    class Pierwsza : System.Collections.IEnumerator
    {
        int wartosc;
        int current;
        bool czypierwsza(int wartosc){
            double root=Math.Sqrt(wartosc);
            int i=2,x=0;;
            while(i<=root){
                if(wartosc%i==0){
                    x++;
                }
               i++;
           }
           if(x>0){return false;}
           return true;
        }
       public Pierwsza() 
        {
            this.wartosc=2;
        }
       public bool MoveNext() 
       {
           this.wartosc=this.wartosc+1;
           while(this.wartosc<Int32.MaxValue&&!czypierwsza(this.wartosc)){
               this.wartosc=this.wartosc+1;
       }
        if(this.wartosc==Int32.MaxValue){
            this.current=this.wartosc;}
            else
            {
                this.current=this.wartosc;
            }
            return this.current!=Int32.MaxValue;
        }
       public object Current { 
           get{
               return current;
           }
       }
       public void Reset() {
           this.current=2;
        }
    }
        
    class Program
    {
        static void Main(string[] args)
        {
            PrimeCollection pc = new PrimeCollection();
            foreach(int p in pc)
            Console.WriteLine(p);
        }
    }
}