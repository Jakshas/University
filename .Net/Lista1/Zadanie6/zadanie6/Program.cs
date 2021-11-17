using System;

namespace zadanie6
{
    class Program
    {
        static int Power(int x)
        {
            return x * x;
        }

        static int Div(int x)
        {
            return x / 2;
        }

        public delegate int Foo(int X);
        static void Main(string[] args)
        {
            Foo MyFoo = new Foo(Power);
            Console.WriteLine("10x10 = " + MyFoo(10));
            MyFoo = Div;
            Console.WriteLine("10/2  = " + MyFoo(10));
            int x = 0;
            for (int i = 0; i < 10; i++)
            {
                x = x + i;
            }
            if (x % 2 == 1)
            {
                Console.WriteLine('1');
            }
            else
            {
                Console.WriteLine('0');
            }
            switch (x)
            {
                case 0:
                    Console.WriteLine('1');
                    break;
                case 1:
                    Console.WriteLine('0');
                    break;
                case 2:
                    break;
            }
        }
    }

    class Pomocnicza
    {
        int x = 1;
        int y = 2;
        int add(int x, int y)
        {
            return x + y;
        }

        private int _wiek;

        public int Wiek
        {
            get
            {
                return _wiek;
            }
            set
            {
                _wiek = value;
            }
        }
        int[] tab = new int[10];
        public int this[int index]
        {
            get
            {
                return tab[index];
            }
            set
            {
                tab[index] = value;
            }
        }

    }
}
