using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Data.Entity;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie4
{
    class Program
    {
        static void Main(string[] args)
        {
            using (var context = new StudentMiejscowoscContext())
            {
                var newMiejscowosc = new Miejscowosc();
                newMiejscowosc.Nazwa = "Wrocłąw";
                context.Miejscowosc.Add(newMiejscowosc);
                context.SaveChanges();
                var newStudent = new Student();
                newStudent.Imie= "Jan";
                newStudent.Nazwisko = "Kowalski";
                newStudent.DataUrodzenia = DateTime.Parse("01/01/2000");
                newStudent.Miejscowosc = newMiejscowosc;
                newStudent.MiejscowoscNazwa = newMiejscowosc.Nazwa;
                context.Student.Add(newStudent);
                context.SaveChanges();
                var student2 = context.Student.First();
                student2.Nazwisko = "Nowak";
                context.SaveChanges();
                var s = context.Student.Where(x => x.Imie == "Jan").FirstOrDefault();
                context.Student.Remove(s);
                context.SaveChanges();
            }
        }
    }
    public class StudentMiejscowoscContext : DbContext
    {
        public StudentMiejscowoscContext():base("cs")
        {

        }
        public StudentMiejscowoscContext(string connectionString) : base(connectionString)
        {

        }
        public DbSet<Miejscowosc> Miejscowosc { get; set; }
        public DbSet<Student> Student { get; set; }
        protected override void OnModelCreating(DbModelBuilder modelBuilder)
        {
            base.OnModelCreating(modelBuilder);
            modelBuilder
                .Entity<Miejscowosc>()
                .Property(p => p.Nazwa)
                .IsRequired()
                .HasMaxLength(100);
            modelBuilder
                .Entity<Miejscowosc>()
                .HasMany(p => p.Students)
                .WithRequired(c => c.Miejscowosc)
                .HasForeignKey(c => c.MiejscowoscNazwa);
            modelBuilder
                .Entity<Miejscowosc>()
                .ToTable("Miejscowosci");
            modelBuilder
                .Entity<Student>()
                .ToTable("Studentci");
        }
    }
    public class Student
    {
        [Key]
        public int ID { get; set; }
        public string Imie { get; set; }
        public string Nazwisko { get; set; }
        public DateTime DataUrodzenia { get; set; }
        public string MiejscowoscNazwa { get; set; }
        public virtual Miejscowosc Miejscowosc { get; set; }
    }
    public class Miejscowosc
    {
        [Key]
        public string Nazwa { get; set; }
        public virtual ICollection<Student> Students { get; set; }
    }
}