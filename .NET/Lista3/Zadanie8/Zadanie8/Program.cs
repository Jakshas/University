using System;
using System.Collections.Generic;
using System.Linq;

namespace Zadanie8
{
    class Program
    {
        static Func<T, T> F<T>(Func<Func<T, T>, Func<T, T>> f)
        {
            return x => f(F(f))(x);
        }

        static void Main(string[] args)
        {
            Func<Func<int, int>, Func<int, int>> f = fac => x => x <= 2 ? 1 : fac(x - 2) + fac(x - 1);
            var f1 = F(f);
            List<int> list = new List<int>() { 1, 2, 3, 4, 5 }; 
            foreach (var item in
                list.Select(i => f1(i))) Console.WriteLine(item);
        }
    }
 }

