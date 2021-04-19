using System;
using System.Collections.Generic;

namespace zadanie4
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> li = new List<int>();
            for (int i = 1; i < 20; i++)
            {
                li.Add(i);
            }
            List<double> ld = new List<double>();
            ld = li.ConvertAll<double>(new Converter<int, double>(inttodoubletimes10));
            foreach (double d in ld)
            {
                Console.WriteLine(d);
            }
            List<int> odp = li.FindAll(czyparzysta);
            foreach (double d in odp)
            {
                Console.WriteLine(d);
            }
            ListHelper.RemoveAll(li ,czyparzysta);
            ListHelper.ForEach(li, Print);
            ListHelper.Sort(li, porownaj);
            ListHelper.ForEach(li, Print);
        }
        static int porownaj(int x, int y)
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
            return i * 10.0;
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
    public class ListHelper 
    { 
        public static List<TOutput> ConvertAll<T, TOutput>(List<T> list, Converter<T, TOutput> converter)
        {
            List<TOutput> pom = new List<TOutput>();
            foreach(T element in list)
            {
                pom.Add(converter(element));
            }
            return pom;
        }
        public static List<T> FindAll<T>(List<T> list, Predicate<T> match)
        {
            List<T> pom = new List<T>();
            foreach (T element in list)
            {
                if (match(element))
                {
                    pom.Add(element);
                }
            }
            return pom;
        }
        public static void ForEach<T>(List<T> list, Action<T> action)
        {
            foreach (T element in list)
            {
                action(element);
            }
        }
        public static int RemoveAll<T>(List<T> list, Predicate<T> match)
        {
            List<T> ans = new List<T>();
            int i = 0;
            foreach (T element in list)
            {
                if (!match(element))
                {
                    ans.Add(element);
                    i++;
                }
            }
            list = ans;
            return i;
        }
        public static void Sort<T>(List<T> list, Comparison<T> comparison)
        {
            int n = list.Count;
            for (int i = 0; i < n - 1; i++)
                for (int j = 0; j < n - i - 1; j++)
                    if (comparison(list[j] , list[j + 1]) > 0 )
                    {
                        // swap temp and arr[i] 
                        T temp = list[j];
                        list[j] = list[j + 1];
                        list[j + 1] = temp;
                    }
        }
    }
}
