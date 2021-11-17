using System;
using System.Collections.Generic;

namespace zadanie3
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> li = new List<int>();
            for(int i = 1; i <20; i++)
            {
                li.Add(i);
            }
            List<double> ld = new List<double>();
            ld = li.ConvertAll<double>(new Converter<int, double>(inttodoubletimes10));
            foreach(double d in ld)
            {
                Console.WriteLine(d);
            }
            List<int> odp = li.FindAll(czyparzysta);
            foreach (double d in odp)
            {
                Console.WriteLine(d);
            }
            li.RemoveAll(czyparzysta);
            li.ForEach(Print);
            li.Sort(porownaj);
            li.ForEach(Print);
        }
        static int porownaj(int x , int y)
        {
            if (x > y)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
        public static double inttodoubletimes10(int i)
        {
            return i*10.0;
        }
        public static bool czyparzysta(int x)
        {
            return x % 2 == 0;
        }
        static void Print(int s)
        {
            Console.WriteLine(s);
        }


    }
}
