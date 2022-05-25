public class Getter
{
    public Func<string> getter;
    public string GetData()
    {
        return getter();
    }
}

public class Formatter
{
    public Func<string, string> format;
     public string FormatDocument(string text)
    {
        return format(text);
    }
}
public class Printer
{
    public Action<string> printer;
    static public void print(string text)
    {
        print(text);
    }
}
public class ReportComposer
{
    Getter g = new Getter() { getter = () => "abcdefg" };
    Formatter formatter = new Formatter() { format = x => x + "\n"};
    Printer printer = new Printer() { printer = x => Console.WriteLine(x) };
}
