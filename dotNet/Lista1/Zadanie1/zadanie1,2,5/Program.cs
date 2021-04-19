
using System;
using System.Collections.Generic;
/// <summary>
/// namespace zadań 1 2 5
/// </summary>
namespace zadanie1_2_5
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> l = Zadanie1.znajdzliczby();
            foreach (int p in l)
            {
                Console.Write(p+" ");
            }
            Zadanie2.Grid g = new Zadanie2.Grid(5, 5);
            g[1, 1] = 2;
            int a = g[1, 1];
            int[] b = g[1];
            Console.WriteLine(a);
        }
    }

    /// <summary>
    ///    Klasa do zadania 1<br />
    /// </summary>
    class Zadanie1
    {
        /// <summary>Funkcja znajdująca liczby które są podzielone przez każdą swoich cyfr i ich sumę</summary>
        /// <returns>
        ///   Lista liczb które są podzielone przez każdą swoich cyfr i ich sumę<br />
        /// </returns>
        public static List<int> znajdzliczby()
        {
            List<int> liczby = new List<int>();
            for (int i = 1; i <= 10000; i++)
            {
                int suma = 0;
                int l = i;
                bool podzielna = true;
                while(l > 0)
                {
                    int c = l % 10;
                    suma = suma + c;
                    l = l / 10;
                    if(c == 0 || i % c != 0)
                    {
                        podzielna = false;
                        break;
                    }
                }
                if(podzielna && i%suma == 0)
                {
                    liczby.Add(i);
                }
            }
            return liczby;
        }
    }

    /// <summary>
    ///   Klasa do zadania 2<br />
    /// </summary>
    class Zadanie2
    {
        /// <summary>
        ///   Klasa odpowiadająca za siatkę
        ///   <br />
        /// </summary>
        public class Grid
        {

            int wysokosc,szerokosc;
            /// <summary>Tablica dwuwymiarowa odpowiadajca siatce</summary>
            int[,] tab;
            /// <summary>Tworzy obiekt klasy <see cref="Grid" />.</summary>
            /// <param name="x">Szerokość</param>
            /// <param name="y">Wysokość</param>
            public Grid(int x, int y)
            {
                tab = new int[y, x];
                szerokosc = x;
                wysokosc = y;
            }
            /// <summary>Znajduje wiersz o zadanym indexie.</summary>
            /// <param name="index">Index.</param>
            /// <value><see cref="System.Int32[]" />.</value>
            /// <returns>
            ///   Wiersz siatki<br />
            /// </returns>
            public int[] this[int index]
            {
                get
                {
                    int[] wiersz = new int[szerokosc];
                    for (int i = 0; i < szerokosc; i++)
                    {
                        wiersz[i] = tab[i, index];
                    }
                    return wiersz;
                }
            }
            /// <summary>ustawia albo pobiera <see cref="System.Int32" /> specyficznego indexu.</summary>
            /// <param name="index1">X</param>
            /// <param name="index2">Y</param>
            /// <value><see cref="System.Int32" />.</value>
            /// <returns>
            ///   Wartość na danych indeksach<br />
            /// </returns>
            public int this[int index1,int index2]
            {
                get
                {
                    return tab[index1, index2];
                }
                set
                {
                    tab[index1, index2] = value;
                }
            }
        }
    }
}
