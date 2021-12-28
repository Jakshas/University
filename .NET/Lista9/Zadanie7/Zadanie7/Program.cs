using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Zadanie7
{
    class Program
    {
        static void Main(string[] args)
        {
            string first = Console.ReadLine();
            XElement element = XElement.Load("zadanie1.xml");
            var studenst = element.Descendants().Where(a => a.Name == "Student");
            var persons = studenst.Where(k => k.Attributes().Any(b => b.Value.StartsWith(first)&& b.Name == "nazwisko" ));
            foreach (var person in persons)
            {
                Console.WriteLine(person.ToString());
            }
            Console.WriteLine();
        }
    }
}
