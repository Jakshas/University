using System;
using System.IO;
using System.Linq;

namespace Zadanie3
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"C:\Projekty\University\.NET\Lista3\Zadanie3\3.txt");
            var li = from l in lines
                     group l by l[0] into groups
                     orderby groups.Key
                     select groups.Key;
            foreach(var l in li)
            {
                Console.WriteLine(l);
            }
        }
    }
}
