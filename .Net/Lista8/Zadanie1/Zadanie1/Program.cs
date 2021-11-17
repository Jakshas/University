using System;
using System.Collections.Generic;
using System.Data.OleDb;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie1
{
    class Program
    {
        static void Main(string[] args)
        {
            using (OleDbConnection cn = new OleDbConnection("Provider=Microsoft.ACE.OLEDB.12.0; Data Source=C:\\Projekty\\University\\dotNet\\Lista8\\Zadanie1\\zad1.xlsx; Extended Properties='Excel 8.0;HDR=Yes'"))
            {
                OleDbCommand co = new OleDbCommand("select * from [Sheet1$]", cn);

                cn.Open();
                OleDbDataReader reader = co.ExecuteReader();

                while (reader.Read())
                {
                    Console.WriteLine(reader[0].ToString()+" "+ reader[1].ToString() + " " + reader[2].ToString() + " " + reader[3].ToString());
                }
                reader.Close();
            }
            Console.ReadLine();
        }
    }
}
