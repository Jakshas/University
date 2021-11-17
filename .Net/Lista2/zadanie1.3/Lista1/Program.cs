using System;
using System.Reflection;

namespace Lista1
{
    class Program
    {
        static void Main(string[] args)
        {
            Prywatna p = new Prywatna();
            Console.WriteLine(p.GetType().GetMethod("zwroc", BindingFlags.NonPublic | BindingFlags.Instance).Invoke(p,null));
            p.GetType().GetProperty("x", BindingFlags.NonPublic | BindingFlags.Instance).SetValue(p,1);
            Console.WriteLine(p.GetType().GetProperty("x", BindingFlags.NonPublic | BindingFlags.Instance).GetValue(p));
            int w;
            int LiczbaProb = 1000; 
            DateTime Start = DateTime.Now; 
            for (int proba = 0; proba < LiczbaProb; proba++) {
                w = (int)p.GetType().GetField("c").GetValue(p);
            }
            DateTime End = DateTime.Now; 
            TimeSpan Czas = Start - End; 
            Console.WriteLine(Czas);

            Start = DateTime.Now;
            for (int proba = 0; proba < LiczbaProb; proba++)
            {
                 w = p.c;
            }
            End = DateTime.Now;
            Czas = Start - End;
            Console.WriteLine(Czas);
        }
    }
    class Prywatna
    {
        public int c = 0;
        private int y;
        private int x
        {
            get { return y; }
            set { y = value; }
        }
        private String zwroc()
        {
            return "s";
        }
        public Prywatna()
            {
            }
    }
}
