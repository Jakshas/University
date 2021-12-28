using System;
using System.Collections.Generic;
using System.Threading;

namespace ConsoleApp1
{
    class Program
    {
        static List<Klient> lawka;
        static Golibroda g;
        static void Main(string[] args)
        {
            lawka = new List<Klient>();
            g = new Golibroda(lawka);
            Thread t1 = new Thread(new ThreadStart(g.spij));
            t1.Start();
            Thread t2 = new Thread(new ThreadStart(poczekalnia));
            t2.Start();
        }
        public static void poczekalnia()
        {
            Random r = new Random();
            while (true)
            {
                Console.WriteLine("Nowy klient");
                new Klient(g , lawka);
                int n = r.Next(1,4);
                Thread.Sleep(n*1000);
            }
        }
    }
    class Golibroda
    {
        public StanG s;
        public Klient obslugiwany;
        public List<Klient> l;
        public Golibroda(List<Klient> l)
        {
            this.l = l;
            s = StanG.Spi;
            obslugiwany = null;
        }
        public void obudz(Klient k)
        {
            s = StanG.Pracuje;
            obslugiwany = k;
        }
        public void spij()
        {
            while (s == StanG.Spi)
            {
                Thread.Sleep(500);
            }
            Console.WriteLine("Golarz goli");
            pracuj();
        }
        public void  pracuj()
        {
            Thread.Sleep(2000);
            obslugiwany = null;
            Console.WriteLine("Klient ogolony");
            if (l.Count == 0)
            {
                Console.WriteLine("Golarz śpi");
                s = StanG.Spi;
                spij();
            }
            else
            {
                Console.WriteLine("Golarz goli");
                obslugiwany = l[0];
                l.RemoveAt(0);
                pracuj();
            }
        }
    }

    class Klient
    {
        StanK s;
        public Klient(Golibroda g, List<Klient> l)
        {
            if (g.s == StanG.Spi )
            {
                g.obudz(this);
            }
            else
            {
                l.Add(this);
            }
        }
    }
    enum StanK
    {
        Czeka,
        Obslugiwany
    }
    enum StanG
    {
        Spi,
        Pracuje
    }
}
