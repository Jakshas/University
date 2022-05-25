using System.Net.Mail;

class SmtpFacad
{
    public void Send(string From, string To, string Subject, string Body, Stream Attachment, string AttachmentMimeType)
    {
        MailMessage message = new MailMessage(From, To, Subject, Body);
        if (Attachment is not null){
            message.Attachments.Add(new Attachment(Attachment, AttachmentMimeType));
        }

        SmtpClient client = new SmtpClient(/*data*/);
        try
        {
            client.Send(message);
        }
        catch (Exception exception)
        {
            Console.WriteLine(exception);
        }
    }
}
class Program
{
    static void Main()
    {
    }
}