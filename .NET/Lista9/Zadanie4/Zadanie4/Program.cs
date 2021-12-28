using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Zadanie4
{
    public class Student
    {
        public string imie { get; set; }
        public string nazwisko { get; set; }
        public AdresStaly Staly { get; set; }
        public AdresTymczasowy Tymczasowy { get; set; }
        public ListaZajec Zajecia { get; set; }
    }
    public class AdresStaly
    {
        public string misto { get; set; }
    }

    public class AdresTymczasowy
    {
        public string misto { get; set; }
    }
    public class ListaZajec
    {
        public List<Przedmiot> ListapPrzedmiotow { get; set; }
    } 

    public class Przedmiot
    {
        public string nazwa { get; set; }
        public int ocena { get; set; }
    }
    public class ListaStudentow
    {
        public List<Student> Lista { get; set; }
        public string nazwa;
    }
    class Program
    {
        static void Main(string[] args)
        {
            StringReader xml = new StringReader(File.ReadAllText("zadanie1.xml"));
            XmlSerializer ser = new XmlSerializer(typeof(ListaStudentow));

            ListaStudentow l = (ListaStudentow)ser.Deserialize(xml);
            Console.WriteLine();
        }
    }
}
