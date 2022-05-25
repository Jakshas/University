// See https://aka.ms/new-console-template for more information
using Microsoft.Data.Sqlite;
using System.Xml;

Console.WriteLine("Hello, World!");

public interface Strategy
{
    void Connect();
    void Download();
    void Process();
    void Disconnect();
}
public class Context
{
    public Strategy strategy;

    public Context(Strategy strategy)
    {
        this.strategy = strategy;
    }

    public void Execute()
    {
        strategy.Connect();
        strategy.Download();
        strategy.Process();
        strategy.Disconnect();
    }
}
public class DatabaseAccessHandler : Strategy
{
    private SqliteConnection conn;
    private List<int> idlist;
    private int idsum;

    public void Connect()
    {
        conn = new SqliteConnection("Data Source=database.db; Version = 3; New = True; Compress = True;");
        conn.Open();
    }

    public void Disconnect()
    {
        conn.Close();
    }

    public void Download()
    {
        SqliteDataReader sqlite_datareader;
        SqliteCommand sqlite_comand;
        sqlite_comand = conn.CreateCommand();
        sqlite_comand.CommandText = "SELECT id FROM Product";
        sqlite_datareader = sqlite_comand.ExecuteReader();
        while (sqlite_datareader.Read())
        {
            string myreader = sqlite_datareader.GetString(0);
            idlist.Add(int.Parse(myreader));
        }
        conn.Close();
    }

    public void Process()
    {
        idsum = idlist.Sum();
    }
}
public class XMLDataAccessHandler : Strategy
{
    private XmlDocument xmldocument;
    private string filepath;
    public XmlNode result;

    public XMLDataAccessHandler(string filepath)
    {
        this.filepath = filepath;
        xmldocument = new XmlDocument();
    }

    public void Connect()
    {

    }

    public void Disconnect()
    {

    }

    public void Download()
    {
        xmldocument.Load(filepath);
    }

    public void Process()
    {
        result = xmldocument.ParentNode;
        foreach (XmlNode node in xmldocument)
        {
            if (node.Name.Length > result.Name.Length)
            {
                result = node;
            }
        }
    }
}