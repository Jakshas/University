using System;

namespace Zadanie1
{
    class Program
    {
        static void Main(string[] args)
        {
            Complex z = new Complex(4, 3);
            Console.WriteLine(String.Format("{0}", z));
            Console.WriteLine(String.Format("{0:d}", z));
            Console.WriteLine(String.Format("{0:w}", z));
        }
    }
    class Complex : IFormattable
    {
        private readonly int R;
        private readonly int I;



        public static Complex operator +(Complex x, Complex y) => new Complex(x.R + y.R, x.I + y.I);

        public static Complex operator -(Complex x, Complex y) => new Complex(x.R - y.R, x.I - y.I);

        public static Complex operator *(Complex x, Complex y) => new Complex(x.R * y.R - x.I * y.I, x.I * y.R + x.R * y.I);

        public static Complex operator /(Complex x, Complex y) => new Complex((x.R * y.R + x.I * y.I)/(y.R*y.R + y.I*y.I), (x.R * y.R + x.I * y.I) / (x.I * y.R - x.R * y.I));
        public Complex(int R, int I)
        {
            this.R = R;
            this.I = I;
        }

        public override string ToString()
        {
            return R.ToString() + " + " + I.ToString() + "i";
        }

        public string ToString(string format, IFormatProvider formatProvider)
        {
            if (format == "d" || format == null)
                return R.ToString() + " + " + I.ToString() + "i";
            if (format == "w")
                return "[" + R.ToString() + ", " + I.ToString() + "]";
            return "Nieznane formatowanie";
        }
    }
}
