using System;
using Word = Microsoft.Office.Interop.Word;
namespace Zadanie2
{
    class Program
    {
        static void Main(string[] args)
        {
            var wordApp = new Word.Application();
            wordApp.Visible = true;
            var doc = wordApp.Documents.Add();
            doc.Range(0, 0).Text = "Programowanie pod Windows";
            doc.SaveAs("C:\\Projekty\\University\\.NET\\Lista4\\Zadanie2\\ppw.doc");
            doc.Close();
        }
    }
}
