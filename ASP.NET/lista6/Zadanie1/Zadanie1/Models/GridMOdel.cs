
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Zadanie1.Models
{
        public class GridMOdel
        {
            public PagedEnumerable<Student> Students { get; set; }
        }

        public class PagedEnumerable<T>
        {
            public int CurrentPage { get; set; }
            public int PageSize { get; set; }
            public int TotalCount { get; set; }

            public IEnumerable<T> Items { get; set; }
        }
    public class DataLayer
    {
        public IEnumerable<Student> GetStudents(string OrderBy, int StartRow, int RowCount)
        {
            IEnumerable<Student> model = StaticModel.Students;

            using (var context = new StudenciDataContext())
            {
                model = context.Studenci.Select(x => new Student
                {
                    ID = x.ID,
                    Imie = x.Imie,
                    Nazwisko = x.Nazwisko,
                    Wiek = x.Wiek
                }).ToList();
            }

            return model.Skip(StartRow).Take(RowCount);
        }

        public int TotalStudents()
        {
            return StaticModel.Students.Count();
        }
    }

    public class StaticModel
    {
        static StaticModel()
        {
            Students = new List<Student>();
            using (var context = new StudenciDataContext())
            {
                Students = context.Studenci.Select(x => new Student
                {
                    ID = x.ID,
                    Imie = x.Imie,
                    Nazwisko = x.Nazwisko,
                    Wiek = x.Wiek
                }).ToList();
            }
        }

        public static List<Student> Students { get; private set; }
    }
    public class Student
    {
        public int ID { get; set; }
        public string Imie { get; set; }
        public string Nazwisko { get; set; }
        public int Wiek { get; set; }
    }
}