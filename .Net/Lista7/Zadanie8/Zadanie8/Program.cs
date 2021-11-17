using System;
using System.Globalization;

namespace Zadanie8
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] cultures = { "en", "de", "fr", "ru", "ar", "cs", "pl" };
            foreach (string c in cultures)
            {
                CultureInfo cul = new CultureInfo(c);
                var df = cul.DateTimeFormat;
                string[] m = df.MonthNames;
                string[] ms = df.AbbreviatedMonthNames;
                for (int i = 0; i < 12; i++)
                    Console.WriteLine(m[i] + " " + ms[i]);
                string[] d = df.DayNames;
                ms = df.AbbreviatedDayNames;
                for (int i = 0; i < 7; i++)
                    Console.WriteLine(d[i] + " " + ms[i]);
                DateTime p = DateTime.Now;
                Console.WriteLine($"{p.Year} {m[p.Month - 1]} {p.Day}");
                Console.WriteLine();
            }
        }
    }
}
