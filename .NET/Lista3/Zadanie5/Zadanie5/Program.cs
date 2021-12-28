using System;
using System.IO;
using System.Linq;

namespace Zadanie5
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] lines1 = File.ReadAllLines(@"C:\Projekty\University\.NET\Lista3\Zadanie5\51.txt");
            string[][] lines11 = new string[lines1.Length][];
            for (int i = 0; i < lines1.Length; i++)
            {
                lines11[i] = lines1[i].Split();
            }
            string[] lines2 = File.ReadAllLines(@"C:\Projekty\University\.NET\Lista3\Zadanie5\52.txt");
            string[][] lines22 = new string[lines1.Length][];
            for (int i = 0; i < lines1.Length; i++)
            {
                lines22[i] = lines2[i].Split();
            }
            var p = from i in lines11
                    join j in lines22 on i[2] equals j[0]
                    select new
                    {
                        imie = i[0],
                        nazwisko = i[1],
                        pesel = i[2],
                        konto = j[1]
                    };
            foreach(var pp in p)
            {
                Console.WriteLine(pp.imie +" "+pp.nazwisko + " "+ pp.pesel+" " + pp.konto);
            }
        }
    }
}
