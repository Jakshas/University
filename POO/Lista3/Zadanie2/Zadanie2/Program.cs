/* 
    Powstaną 3 nowe klasy poniewarz mamy 3 rózne właściwosci. Nie trzeba jesli jakies 2 metody opisują tą sama własciwosc np ustawianie i pozyskiwanie jakiejs właściwości można je dac w tej samej klasie.
 */


public class ReportPrinter
{
    string text;
    ReportPrinter(string s)
    {
        text = s;
    }
    public string GetData()
    {
        return text;
    }
    public void FormatDocument()
    {
        text = text + "\n";
    }
    public void PrintReport()
    {
        Console.WriteLine(text);
    }
}


public class Getter
{
    static String s = "sss";
    public static string GetData()
    {
        return s;
    }
}

public class Formatter
{
    static public string FormatDocument(string text)
    {
        return text + "\n";
    }
}
public class Printer
{
    static public void print()
    {
        Console.WriteLine(Formatter.FormatDocument(Getter.GetData()));
    }
}