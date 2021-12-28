using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.ServiceProcess;
using System.Text;
using System.Threading.Tasks;
using System.Timers;

namespace Zadanie9
{
    public partial class Service1 : ServiceBase
    {
        Timer t;
        public Service1()
        {
            InitializeComponent();
        }

        protected override void OnStart(string[] args)
        {
            t = new Timer(1000);
            t.Elapsed += (s, e) =>
            {
                FileStream fs = new FileStream("files.txt", FileMode.CreateNew);
                StreamWriter sw = new StreamWriter(fs);
                    foreach (Process p in Process.GetProcesses())
                    {
                        if (!string.IsNullOrEmpty(p.MainWindowTitle))
                        {
                            sw.WriteLine(p.MainWindowTitle);
                        }
                    }
            };
            t.Start();
        }

        protected override void OnStop()
        {
        }
    }
}
