using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Zadanie5
{
    class Program
    {
        static void Main(string[] args)
        {
            XmlDocument doc = new XmlDocument();
            doc.LoadXml("<Student name='Jakub'/>\n");
            doc.Save(Console.Out);

            XmlDocument doc1 = new XmlDocument();
            doc.Load("zadanie1.xml");
            doc.Save(Console.Out);
            Console.WriteLine();
        }
    }
}
