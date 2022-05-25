// See https://aka.ms/new-console-template for more information
using Microsoft.Data.Sqlite;
using System.Xml;

Console.WriteLine("Hello, World!");

public abstract class DataAccessHandler
{
    protected abstract void Connect();
    protected abstract void Download();
    protected abstract void Process();
    protected abstract void Disconnect();

    public void Execute()
    {
        this.Connect();
        this.Download();
        this.Process();
        this.Disconnect();
    }
}

public class DatabaseAccessHandler : DataAccessHandler
{
    private SqliteConnection conn;
    private List<int> idlist;
    private int idsum;

    protected override void Connect()
    {
        conn = new SqliteConnection("Data Source=database.db; Version = 3; New = True; Compress = True;");
        conn.Open();
    }

    protected override void Disconnect()
    {
        conn.Close();
    }

    protected override void Download()
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

    protected override void Process()
    {
        idsum = idlist.Sum();
    }
}
public class XMLDataAccessHandler : DataAccessHandler
{
    private XmlDocument xmldocument;
    private string filepath;
    public XmlNode result;

    public XMLDataAccessHandler(string filepath)
    {
        this.filepath = filepath;
        xmldocument = new XmlDocument();
    }

    protected override void Connect()
    {

    }

    protected override void Disconnect()
    {

    }

    protected override void Download()
    {
        this.xmldocument.Load(filepath);
    }

    protected override void Process()
    {
        result = xmldocument.ParentNode;
        foreach (XmlNode node in xmldocument)
        {
            if(node.Name.Length > result.Name.Length)
            {
                result = node;
            }
        }
    }
}