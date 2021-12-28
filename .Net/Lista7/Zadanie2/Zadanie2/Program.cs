using System;
using System.Collections;

namespace Zadanie2
{
    class Program
    {
        static void Main(string[] args)
        {
            NewSet test = new NewSet();
            test.Add(1);
            test.Add(2);
            test.Add(2);
            test.Add(3);
            foreach (object a in test)
            {
                Console.WriteLine(a);
            }
            Console.WriteLine(test.Count);
            test.Remove(2);
            test.Remove(1);
            Console.WriteLine(test.Count);
        }
    }
    class NewSet : ArrayList
    {
        public NewSet() : base() { }

        public override int Add(object value)
        {
            int search = this.IndexOf(value);
            if (search == -1)
            {
                return base.Add(value);
            }
            return search;
        }
    }
}
