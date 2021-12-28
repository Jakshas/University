using System;
using System.Net;
using System.Net.Http;
using System.Net.Sockets;
using System.Threading.Tasks;

namespace Zadanie5
{
    class Program
    {
        static readonly HttpClient client = new HttpClient();
        static async Task Main(string[] args)
        {
            FtpWebRequest ftp = (FtpWebRequest)WebRequest.Create("ftp://dlpuser@ftp.dlptest.com/10MB.zip");
            ftp.Method = WebRequestMethods.Ftp.DownloadFile;
            FtpWebResponse ftr = (FtpWebResponse)ftp.GetResponse();
            Console.WriteLine(ftr.StatusDescription);
            ftr.Close();

            HttpWebRequest myReq = (HttpWebRequest)WebRequest.Create("http://localhost/dashboard/");
            myReq.Method = WebRequestMethods.Http.Get;
            HttpWebResponse htr = (HttpWebResponse)myReq.GetResponse();
            Console.WriteLine(htr.StatusDescription);
            htr.Close();

            using (WebClient web = new WebClient())
            {
                string url = "https://upload.wikimedia.org/wikipedia/commons/thumb/1/15/White_Persian_Cat.jpg/521px-White_Persian_Cat.jpg";
                web.DownloadFile(new Uri(url), "Kot.jpg");
            }

            HttpResponseMessage r = await client.GetAsync("http://localhost/dashboard/");
            r.EnsureSuccessStatusCode();
            string rb = await r.Content.ReadAsStringAsync();
            Console.WriteLine(rb);

            using (HttpListener hlist = new HttpListener())
            {
                hlist.Start();
                hlist.Prefixes.Add("http://localhost/dashboard/");
                HttpListenerContext listContext = hlist.GetContext();
                System.IO.Stream outStr = listContext.Response.OutputStream;
                byte[] buf = System.Text.Encoding.UTF8.GetBytes("1");
                outStr.Write(buf, 0, buf.Length);
                outStr.Close();
                hlist.Stop();
            }

            using (TcpClient tcp = new TcpClient("", 3000))
            {
                Byte[] data = System.Text.Encoding.ASCII.GetBytes("2");
                NetworkStream a = tcp.GetStream();

                a.Write(data, 0, data.Length);
                a.Close();
            }
        }
    }
}
