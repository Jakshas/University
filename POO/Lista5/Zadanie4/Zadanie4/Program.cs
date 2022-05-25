using System.Collections;


    class ComparisonToIComparerAdapter<T> : IComparer
    {
        Comparison<T> comparison;

        public ComparisonToIComparerAdapter(Comparison<T> comparison) { this.comparison = comparison; }
        public int Compare(object x, object y) { return comparison((T)x, (T)y); }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ArrayList a = new ArrayList() { 1, 5, 3, 3, 2, 4, 3 };

            a.Sort(new ComparisonToIComparerAdapter<int>((x, y) => x.CompareTo(y)));

            Console.WriteLine(a[1]);
            Console.ReadLine();
        }
    }
