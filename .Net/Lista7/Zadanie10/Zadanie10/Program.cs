using System;
using System.IO;
using System.Reflection;

namespace Zadanie10
{
    static class FileReader
    {
        public static string GetData(string filename)
        {
            var exe = Assembly.GetExecutingAssembly();
            using Stream s = exe.GetManifestResourceStream("Zadanie10." + filename);
            using StreamReader r = new StreamReader(s);
            return r.ReadToEnd();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(FileReader.GetData("1"));
        }
    }
}
