/*
    Information Expert - Przedmiot ma liste studentów wiec on zwraca ich liczbe
    Low Coupling - Mozemy sie dowiedziec jacy studenci sa na przedmiocie i ajki student ma przedmiotyw tych klasach osobno. Czyli mozemy stwierdzic czy student jest na przedmiocie na dwa spsosby
    High Cohesion - Kazda klasa zajmuje sie tylko swoimi obiektami i jest spujnie opisana.
    Creator - Kazdy obiekt tworzy swoje Listy w konstruktorach
 */

using System;
public class Student
{
    string index;
    List<Przedmiot> przedmioty;
    public Student(string index)
    {
        przedmioty = new List<Przedmiot>();
        this.index = index;
    }
    public void dodajprzedmiot(Przedmiot p)
    {
        przedmioty.Add(p);
        if (!p.czyStudentW(this))
        {
            p.dodajStudenta(this);
        }
    }
}

public class Przedmiot
{
    List<Student> students;
    string nazwa;
    Prowadzacy prowadzacy;
    public Przedmiot(string nazwa,Prowadzacy prowadzacy)
    {
        this.prowadzacy = prowadzacy;
        this.nazwa = nazwa;
        students = new List<Student>();
    }
    public int ileStudentow()
    {
        return students.Count();
    }
    public void dodajStudenta(Student s)
    {
        students.Add(s);
        if (!students.Contains(s))
        {
            s.dodajprzedmiot(this);
        }
        
    }
    public bool czyStudentW(Student s)
    {
        return students.Contains(s);
    }
}

public class Prowadzacy
{
    string nazwisko;
    public Prowadzacy(string nazwisko)
    {
        this.nazwisko = nazwisko;
    }
}

class Zadanie1
{
    static void Main(string[] args)
    {
        Prowadzacy p = new Prowadzacy("Nowak");
        Student s = new Student("111111");
        Przedmiot prz = new Przedmiot("Logika", p);
        prz.dodajStudenta(s);
        Console.WriteLine(prz.ileStudentow());
    }
}