using System;
using System.IO;
using System.Linq;

namespace Zadanie6
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines1 = File.ReadAllLines(@"C:\Projekty\University\.NET\Lista3\Zadanie6\6.txt");
            string[][] lines11 = new string[lines1.Length][];
            for (int i = 0; i < lines1.Length; i++)
            {
                lines11[i] = lines1[i].Split();
            }
            var ans = (from i in lines11
                     group i by i into l
                     orderby l.Count() descending
                     select l.Key + " " + l.Count())
                                .Take(3);
            foreach(var a in ans)
            {
                Console.WriteLine(a);
            }
        }
    }
}
