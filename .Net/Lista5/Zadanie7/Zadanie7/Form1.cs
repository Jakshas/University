using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zadanie7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            int i = 1;
            
        }
        public static void DownloadString(string address)
        {
            WebClient client = new WebClient();
            string reply = client.DownloadString(address);

            Console.WriteLine(reply);
        }
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            label1.Text = (Int32.Parse(label1.Text) + 1).ToString();
            for (int i = 0;i<10;i++) 
                DownloadString("file:///C:/Projekty/University/dotNet/Lista5/Zadanie7/pt.txt");
        }

        private async void button2_ClickAsync(object sender, EventArgs e)
        {
            label1.Text = (Int32.Parse(label1.Text) + 1).ToString();
            pobierz();
        }
        private async void pobierz()
        {
            HttpClient client = new HttpClient();
            HttpResponseMessage response = client.GetAsync("https://skos.ii.uni.wroc.pl/pluginfile.php/40328/mod_resource/content/1/pan_tadeusz_bez_spacji.txt").Result;
            string jsonString = await response.Content.ReadAsStringAsync();
        }
    }
}
