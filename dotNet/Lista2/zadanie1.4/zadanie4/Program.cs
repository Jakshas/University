using System;
using System.Collections.Generic;
using System.Reflection;

namespace zadanie4
{
    class Program
    {
        static void Main(string[] args)
        {
            Foo f = new Foo();
            MethodInfo[] tab = f.GetType().GetMethods(BindingFlags.Public | BindingFlags.Instance);
            List<MethodInfo> pom = new List<MethodInfo>();
            for (int i = 0; i < tab.Length; i++)
                if (tab[i].ReturnType == typeof(int) && tab[i].GetParameters().Length == 0)
                    pom.Add(tab[i]);

            for (int i = 0; i < pom.Count; i++)
            {
                MethodInfo p = pom[i]; 
                foreach (Attribute b in p.GetCustomAttributes())
                {
                    if (b.GetType() == typeof(OznakowaneAttribute))
                        Console.WriteLine(p.Invoke(f, null));
                }
            }
        }
    }

    public class Foo {
        [Oznakowane] 
        public int Bar() 
        { 
            return 1; 
        } 
        public int Qux() 
        { 
            return 2;
        } 
    }
    public class OznakowaneAttribute : Attribute
    {
    }
}
