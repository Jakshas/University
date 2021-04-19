// zadanie6.Program
using System;

internal class Program
{
    public delegate int Foo(int X);

    private static int Power(int x)
    {
        return x * x;
    }

    private static int Div(int x)
    {
        return x / 2;
    }

    private static void Main(string[] args)
    {
        Foo MyFoo = Power;
        Console.WriteLine("10x10 = " + MyFoo(10));
        MyFoo = Div;
        Console.WriteLine("10/2  = " + MyFoo(10));
        int x = 0;
        for (int i = 0; i < 10; i++)
        {
            x += i;
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
        }
    }
}
