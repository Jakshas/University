// See https://aka.ms/new-console-template for more information
Request r = new Request("complaint","I want co complain");
AbstractHandler handler = new ArchiveHandler();
handler.AttachNextHandler(new PraiseHandler());
handler.AttachNextHandler(new ComplaintHandler());
handler.AttachNextHandler(new OrderHandler());
handler.AttachNextHandler(new ElseHandler());

handler.DispatchRequest(r);
public class Request
{
    public string header;
    public string text;

    public Request(string header, string text)
    {
        this.header = header;
        this.text = text;
     }
}

public abstract class AbstractHandler
{
    public void DispatchRequest(Request request)
    {
        var result = this.ProcessRequest(request);

        if(result && this.Next != null)
        {
            this.Next.DispatchRequest(request);
        }
    }
    public void AttachNextHandler(AbstractHandler next)
    {
        if(this.Next != null)
        {
            this.Next.AttachNextHandler(next);
        }
        else
        {
            this.Next = next;
        }
    }
    public AbstractHandler Next { get; set; }

    public abstract bool ProcessRequest(Request request);
}

public class ArchiveHandler : AbstractHandler
{
    public override bool ProcessRequest(Request request)
    {
        Console.WriteLine("Wysłane do archiwizacji");
        return true;
    }

}
public class PraiseHandler : AbstractHandler
{
    public override bool ProcessRequest(Request request)
    {
        if (request.header.Contains("praise"))
        {
            Console.WriteLine("Wysłane do Prezesa");
            return false;
        }
        return true;
    }
}
public class ComplaintHandler : AbstractHandler
{
    public override bool ProcessRequest(Request request)
    {
        if (request.header.Contains("complaint"))
        {
            Console.WriteLine("Wysłane do działu prawnego");
            return false;
        }
        return true;
    }
}
public class OrderHandler : AbstractHandler
{
    public override bool ProcessRequest(Request request)
    {
        if (request.header.Contains("order"))
        {
            Console.WriteLine("Wysłane do działu handlowego");
            return false;
        }
            
        return true;
    }
}
public class ElseHandler : AbstractHandler
{
    public override bool ProcessRequest(Request request)
    {
        Console.WriteLine("Wysłane do działu handlowego");
        return true;
    }
}