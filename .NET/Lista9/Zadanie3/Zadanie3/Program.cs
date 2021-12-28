using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Linq;
using System.Xml.Schema;

namespace Zadanie3
{
    class Program
    {
        static void Main(string[] args)
        {
            XmlSchemaSet set = new XmlSchemaSet();
            XmlReader read = XmlReader.Create("zadanie1.xml");
            set.Add("l9", "zadanie2.xsd");
            XDocument d = XDocument.Load(read);
            d.Validate(set, (object sender, ValidationEventArgs e) => { 
                throw new Exception(e.Message); 
            });
        }
    }
}
