// See https://aka.ms/new-console-template for more information
using System.Net;

Console.WriteLine("Hello, World!");

public interface Command
{
    public void Run();
}

public class FTP : Command
{
    string _filename;
    public FTP(string name)
    {
        this._filename = name;
    }

    public void Run()
    {
        WebClient client = new WebClient();
        client.DownloadFile(this._filename, "D:/");
    }
}
public class HTTP : Command
{
    string _filename;

    public HTTP(string name)
    {
        this._filename = name;
    }

    public void Run()
    {
        WebClient client = new WebClient();
        client.DownloadFile(this._filename, "D:/");
    }
}

public class Empty : Command
{
    string _filepath;

    public Empty(string _filepath)
    {
        this._filepath = _filepath;
    }

    public void Run()
    {
        File.Create(_filepath);
        using (var writer = new StreamWriter(_filepath))
        {
            writer.Write(new Random().Next().ToString());
        }
    }
}

public class Move : Command
{
    string source, destination;

    public Move(string source, string destination)
    {
        this.source = source;
        this.destination = destination;
    }

    public void Run()
    {
        File.Move(source, destination);
    }
}