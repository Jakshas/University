using System;
using System.IO;
using System.Linq;

namespace Zadanie4
{
    class Program
    {
        static void Main(string[] args)
        {
            var size = Directory.GetFiles(@"C:\Projekty\University\.NET\Lista3\Zadanie2").Select(x => new FileInfo(x).Length).Aggregate((x, y) => x + y);
            Console.WriteLine(size);
        }
    }
}
