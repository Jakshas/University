using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Zadanie3.Models
{
    public class Student
    {
        public Plec plec { get; set; }
        public string haslo { get; set; }
        public int rok { get; set; }
        public bool czy_zaliczyl_przedmiot;
    }

    public enum Plec
    {
        Mężczyzna,
        Kobieta
    }
}