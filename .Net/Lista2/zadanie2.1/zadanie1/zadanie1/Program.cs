using System;
using System.Collections;
using System.Collections.Generic;

namespace zadanie1
{
    class Program
    {
        static void Main(string[] args)
        {
            ArrayList al = new ArrayList();
            List<int> l = new List<int>();
            Hashtable ht = new Hashtable();
            Dictionary<int , int> d = new Dictionary<int, int>();
            int max = 10000000;
            object temp;
            DateTime Start = DateTime.Now;
            for (int i = 0; i <max; i++)
            {
                al.Add(i);
            }
            DateTime End = DateTime.Now;
            Console.WriteLine("ArrayLista dodawanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < max; i++)
            {
                l.Add(i);
            }
            End = DateTime.Now;
            Console.WriteLine("Lista dodawanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < max; i++)
            {
                temp = al[i];
            }
            End = DateTime.Now;
            Console.WriteLine("ArrayLista przegladanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < max; i++)
            {
                temp = l[i];
            }
            End = DateTime.Now;
            Console.WriteLine("Lista przegladanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < 1000; i++)
            {
                al.RemoveAt(0);
            }
            End = DateTime.Now;
            Console.WriteLine("ArrayLista usówanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < 1000; i++)
            {
                l.RemoveAt(0);
            }
            End = DateTime.Now;
            Console.WriteLine("Lista usówanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < max; i++)
            {
                ht.Add(i,i);
            }
            End = DateTime.Now;
            Console.WriteLine("Hashtable dodawanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < max; i++)
            {
                d.Add(i,i);
            }
            End = DateTime.Now;
            Console.WriteLine("Dictionary dodawanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < max; i++)
            {
                temp = ht[i];
            }
            End = DateTime.Now;
            Console.WriteLine("Hashtable przegladanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < max; i++)
            {
                temp = d[i];
            }
            End = DateTime.Now;
            Console.WriteLine("Dictionary przegladanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < 1000; i++)
            {
                ht.Remove(i);
            }
            End = DateTime.Now;
            Console.WriteLine("Hashtable usówanie " + (End - Start));
            Start = DateTime.Now;
            for (int i = 0; i < 1000; i++)
            {
                d.Remove(i);
            }
            End = DateTime.Now;
            Console.WriteLine("Dictionary usówanie " + (End - Start));
        }
    }
}
