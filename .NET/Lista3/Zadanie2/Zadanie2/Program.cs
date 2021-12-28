using System;
using System.IO;
using System.Linq;

namespace Zadanie2
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Projekty\University\.NET\Lista3\Zadanie2\2.txt");
            var l = from li in lines
                    select Int32.Parse(li);
            var lowNums = from num in l
                          where num > 100
                          orderby num descending
                          select num;
            foreach(var s in lowNums)
            {
                Console.WriteLine(s);
            }
            foreach (var s in l.Where(x => x > 100).OrderByDescending(x => x))
            {
                Console.WriteLine(s);
            }
        }
    }
}
