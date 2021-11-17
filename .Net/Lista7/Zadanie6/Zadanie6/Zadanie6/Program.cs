using System;
using System.Net;
using System.Net.Sockets;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Threading;
using static ClassLibrary1.CObiekt;

namespace ServerApplication
{
    class Program
    {
        static void Main(string[] args)
        {
            MessageServer s = new MessageServer(515);
            s.Start();
        }
    }

    public class MessageServer
    {
        private int _port;
        private TcpListener _tcpListener;
        private bool _running;
        private TcpClient connectedTcpClient;
        private BinaryFormatter _bFormatter;
        private Thread _connectionThread;

        public MessageServer(int port)
        {
            this._port = port;
            this._tcpListener = new TcpListener(IPAddress.Loopback, port);
            this._bFormatter = new BinaryFormatter();
        }

        public void Start()
        {
            if (!_running)
            {
                this._tcpListener.Start();
                Console.WriteLine("Waiting for a connection... ");
                this._running = true;
                this._connectionThread = new Thread
                    (new ThreadStart(ListenForClientConnections));
                this._connectionThread.Start();
            }
        }

        public void Stop()
        {
            if (this._running)
            {
                this._tcpListener.Stop();
                this._running = false;
            }
        }

        private void ListenForClientConnections()
        {
            while (this._running)
            {
                this.connectedTcpClient = this._tcpListener.AcceptTcpClient();
                Console.WriteLine("Connected!");
                CObiekt co = new CObiekt(5, DateTime.Now, "Ala ma kota");
                _bFormatter.Serialize(this.connectedTcpClient.GetStream(), co);
                Console.WriteLine("Send!");
            }
        }
    }
    [Serializable()]
    public class CObiekt : ISerializable
    {
        int v; 
        DateTime d; 
        string s;
        public CObiekt(int v, DateTime d, string s) { 
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
        public void GetObjectData(SerializationInfo info,StreamingContext context)
        {
            info.AddValue("v", v);
            info.AddValue("d", d);
            info.AddValue("s", s);
        }
        public override string ToString(){
            return String.Format( "{0}, {1:d}, {2}", v, d, s );
        }
    }
 }