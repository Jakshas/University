using System;
using System.Collections.Generic;
using System.Linq;
using System.Messaging;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie7
{
    class Program
    {
        static void Main(string[] args)
        {
            int x = 100000000;
            int y = 100000000;
            var s = new Q1();
            var r = new Q2();
            for (int i = 0; i < 5; i++)
            {
                for (int k = 0; k < 10;k++)
                    s.Send(); 
                for (int j = 0; j < 100; j++)
                {
                    if (j % 10 == 0)
                    {
                        r.Receive();
                    }
                    for (int k = 0; k < 10000000; k++)
                    {
                        int v = x + y;
                    }
                }
            }
        }
    }

    class Q1
    {
        int couter = 1;
        public void Send()
        {
            using (MessageQueue q = new MessageQueue())
            {
                q.Path = ".\\Private$\\q";
                if (!MessageQueue.Exists(q.Path))
                {
                    MessageQueue.Create(q.Path);
                }
                Message m = new Message
                {
                    Body = couter.ToString(),
                    Label = couter.ToString()
                };
                couter++;
                q.Send(m);
            }
        }
    }

    class Q2
    {
        public void Receive()
        {
            using (MessageQueue q = new MessageQueue())
            {
                q.Path = ".\\Private$\\q";
                Message m = new Message();
                m = q.Receive(new TimeSpan(0, 0, 10));
                m.Formatter = new XmlMessageFormatter(new string[] { "System.String, mscorlib" });
                Console.WriteLine(m.Body.ToString());
            }
        }
    }
}
