using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zadanie6
{

    public partial class Form1 : Form
    {
        Thread won;
        public class Wontki
        {
            ProgressBar ppr;
            public void pierwsze()
            {
                long n = 1000000000000, x = 0; ;
                for (int i = 2; i <= (int)Math.Sqrt(n); i++)
                {
                    if (n % i == 0)
                        x++;
                    int pr = i / 10000;
                    ppr.Value=pr;
                }
            }
            public Wontki(ProgressBar p)
            {
                ppr = p;
            }
        }
        public Form1()
        {
            InitializeComponent();
            Wontki w = new Wontki(progressBar2);
            won = new Thread(new ThreadStart(w.pierwsze));

            won.Start(); 
            //backgroundWorker1.WorkerReportsProgress = true;
           // backgroundWorker1.RunWorkerAsync();
        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {
            BackgroundWorker worker = sender as BackgroundWorker;
            long n = 1000000000000, x = 0; ;
            for (int i = 2; i <= (int)Math.Sqrt(n); i++)
            {
                if (n % i == 0)
                    x++;
                int pr = i / 10000;
                worker.ReportProgress(pr);
            }
        }

        private void backgroundWorker1_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            progressBar1.Value = e.ProgressPercentage;
        }

        private void start_Click(object sender, EventArgs e)
        {
            backgroundWorker1.WorkerReportsProgress = true;
            backgroundWorker1.RunWorkerAsync();
        }
    }
}
