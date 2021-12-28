using System;
using System.Linq;

namespace Zadanie7
{
    class Program
    {
        static void Main(string[] args)
        {
            var item = new { Field1 = "The value", Field2 = 5};
            //List<?> theList = ? tak sie nie da
            var list = new[] { item }.ToList(); // tak sie da
        }
    }
}
