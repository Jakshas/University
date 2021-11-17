using System;
using System.Collections.Generic;
using System.Linq;
using System.Configuration;
using System.Text;
using System.Data.SqlClient;
using System.Threading.Tasks;

namespace Zadanie3
{
    class Program
    {
        static void Main(string[] args)
        {
            using (DataClasses1DataContext context = new DataClasses1DataContext(@"server=.\sqlexpress;database=zadanie2;integrated security=true"))
            {
                Student s1 = new Student();
                s1.Imie = "Jan";
                s1.Nazwisko = "Kowalski";
                s1.DataUrodzenia = new DateTime(2000, 5, 1, 8, 30, 52);
                s1.Miejscowosc = "Wrocław";
                Student s2 = new Student();
                s2.Imie = "Adam";
                s2.Nazwisko = "Nowak";
                s2.DataUrodzenia = new DateTime(2001, 5, 1, 8, 30, 52);
                s2.Miejscowosc = "Wrocław";
                Miejscowosc m = new Miejscowosc();
                m.Nazwa = "Wrocław";
                context.Student.InsertOnSubmit(s1);
                context.Student.InsertOnSubmit(s2);
                context.Miejscowosc.InsertOnSubmit(m);
                context.SubmitChanges();
                var query = context.Student
                    .Where(p => p.Imie.StartsWith("J"))
                    .OrderBy(p => p.Imie)
                    .Take(2);

                foreach (var student in query)
                {
                    student.Imie = student.Imie + '!';
                    context.SubmitChanges();
                    Console.WriteLine(student);
                }
                var del = context.Student
                    .Where(p => p.Nazwisko.StartsWith("N"));
                context.Student.DeleteOnSubmit(del.First());

            }
        }
    }
}
