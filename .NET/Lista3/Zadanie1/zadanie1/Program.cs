using System;

namespace zadanie1
{
    public static class StringExtensions
    {
        public static bool IsPalindrome(this string s)
        {
            s = s.ToLower();
            s = s.Replace(" ", "");
            for (int i = 0, j = s.Length-1; i != j; i++, j--)
            {
                char s1 = s[i], s2 = s[j];
                if (s[i] != s[j])
                {
                    return false;
                }
            }
            return true;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string s = "Kobyła ma mały bok"; 
            bool ispalindrome = s.IsPalindrome();
            Console.WriteLine(ispalindrome);
        }
    }
}
