using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Zadanie6
{
    class Program
    {
        static void Main(string[] args)
        {
            using (XmlTextWriter xml = new XmlTextWriter(Console.Out))
            {
                xml.WriteStartElement("root");
                xml.WriteAttributeString("xmlns", "x", null, "urn:1");
                xml.WriteStartElement("item", "urn:1");
                xml.WriteEndElement();
                xml.WriteStartElement("item", "urn:1");
                xml.WriteEndElement();
                xml.WriteEndElement();
            }
            using (XmlTextReader rxml = new XmlTextReader("zadanie1.xml"))
            {
                Console.WriteLine(rxml.Value);
            }
            Console.WriteLine();
        }
    }
}