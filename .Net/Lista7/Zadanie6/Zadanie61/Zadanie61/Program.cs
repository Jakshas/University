using System;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading;
using static ClassLibrary1.CObiekt;

namespace ClientApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            MessageClient client = new MessageClient(515);
            client.StartListening();
        }
    }

    public class MessageClient
    {
        private int _port;
        private TcpClient _tcpClient;
        private BinaryFormatter _bFormatter;
        private Thread _listenThread;
        private bool _running;
        private CObiekt house;

        public MessageClient(int port)
        {
            this._port = port;
            this._tcpClient = new TcpClient("localhost", port);
            this._bFormatter = new BinaryFormatter();
            this._running = false;
        }

        public void StartListening()
        {
            lock (this)
            {
                if (!_running)
                {
                    this._running = true;
                    this._listenThread = new Thread
                        (new ThreadStart(ListenForMessage));
                    this._listenThread.Start();
                }
                else
                {
                    this._running = true;
                    this._listenThread = new Thread
                        (new ThreadStart(ListenForMessage));
                    this._listenThread.Start();
                }
            }
        }

        private void ListenForMessage()
        {
            Console.WriteLine("Reading...");
            try
            {
                while (this._running)
                {
                    this.house = (CObiekt)this._bFormatter.Deserialize(this._tcpClient.GetStream());
                    Console.WriteLine(house.ToString());
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
                Console.ReadLine();
            }
        }
    }
    [Serializable()]
    public class CObiekt : ISerializable
    {
        int v;
        DateTime d;
        string s;
        public CObiekt(int v, DateTime d, string s)
        {
            this.v = v;
            this.d = d;
            this.s = s;
        }
        public CObiekt(SerializationInfo info, StreamingContext context)
        {
            v = (int)info.GetValue("v", typeof(int));
            d = (DateTime)info.GetValue("d", typeof(DateTime));
            s = (string)info.GetValue("s", typeof(string));
        }
        public void GetObjectData(SerializationInfo info, StreamingContext context)
        {
            info.AddValue("v", v);
            info.AddValue("d", d);
            info.AddValue("s", s);
        }
        public override string ToString()
        {
            return String.Format("{0}, {1:d}, {2}", v, d, s);
        }
    }
}