using System;
using System.Diagnostics;

namespace Zadanie1
{
    class Program
    {
        static int Foo(int x, int y)
        { 
            return x * y;
        }
        static dynamic Foo( dynamic x, dynamic y )
        {
            return x * y;
        }
        static void Main(string[] args)
        {
            Stopwatch stopwatch1 = Stopwatch.StartNew();
            for(int i = 0;i<1000000; i++)
            {
                int p = Foo(i,i);
            }
            stopwatch1.Stop();
            var s1 = stopwatch1.ElapsedMilliseconds;
            Console.WriteLine("Czas wykonania int to {0} ms", s1);
            Stopwatch stopwatch2 = Stopwatch.StartNew();
            for (dynamic i = 0; i < 1000000; i++)
            {
                dynamic p = Foo(i, i);
            }
            stopwatch2.Stop();
            var s2 = stopwatch2.ElapsedMilliseconds;
            Console.WriteLine("Czas wykonania dynamic to {0} ms", s2);
            Console.WriteLine("Róznica w czasie wykonania to {0} razy", s2/s1);
        }
    }
}
