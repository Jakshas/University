using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zadanie3
{
    public partial class Form1 : Form
    {
        Timer timer;
        int WIDTH = 300, HEIGHT = 300, secHAND = 140, minHAND = 110, hrHAND = 80;
        int cx, cy;
        Bitmap bmp;
        Graphics g;

        public Form1()
        {
            timer = new Timer();
            timer.Tick += new EventHandler(Timer_Tick);
            timer.Interval = 50; timer.Start();
            bmp = new Bitmap(WIDTH + 1, HEIGHT + 1);
            cx = WIDTH / 2;
            cy = HEIGHT / 2;
            InitializeComponent();
        }

        void Timer_Tick(object sender, EventArgs e) {
            this.Invalidate();
        }
        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            using (Font f = new Font("LED", 48))
            {
                StringFormat sf = new StringFormat();
                sf.Alignment = StringAlignment.Center;
                sf.LineAlignment = StringAlignment.Center;
                g.Clear(SystemColors.Control);
                timer.Tick += new EventHandler(this.t_Tick);

            }
        }
private void Form1_Load(object sender, EventArgs e)
        {

        }
        private void t_Tick(object sender, EventArgs e)
        {
            g = Graphics.FromImage(bmp);

            int ss = DateTime.Now.Second;
            int mm = DateTime.Now.Minute;
            int hh = DateTime.Now.Hour;
            int[] handCoord = new int[2];
            g.Clear(Color.White);
            g.DrawEllipse(new Pen(Color.Black, 1f), 0, 0, WIDTH, HEIGHT);
            handCoord = msCoord(ss, secHAND);
            g.DrawLine(new Pen(Color.Red, 1f), new Point(cx, cy), new Point(handCoord[0], handCoord[1]));
            handCoord = msCoord(mm, minHAND);
            g.DrawLine(new Pen(Color.Black, 2f), new Point(cx, cy), new Point(handCoord[0], handCoord[1]));
            handCoord = hrCoord(hh % 12, mm, hrHAND);
            g.DrawLine(new Pen(Color.Gray, 3f), new Point(cx, cy), new Point(handCoord[0], handCoord[1]));
            pictureBox1.Image = bmp;
            g.Dispose();
        }
        private int[] msCoord(int val, int hlen)
        {
            val *= 6;
            int x, y;

            if (val >= 0 && val <= 180)
            {
                x = cx + (int)(hlen * Math.Sin(Math.PI * val / 180));
                y = cy - (int)(hlen * Math.Cos(Math.PI * val / 180));
            }
            else
            {
                x = cx - (int)(hlen * -Math.Sin(Math.PI * val / 180));
                y = cy - (int)(hlen * Math.Cos(Math.PI * val / 180));
            }
            int[] n = { x,y};
            return n;
        }

        private int[] hrCoord(int hval, int mval, int hlen)
        {
            int x, y;

            int val = (int)((hval * 30) + (mval * 0.5));

            if (val >= 0 && val <= 180)
            {
                x = cx + (int)(hlen * Math.Sin(Math.PI * val / 180));
                y = cy - (int)(hlen * Math.Cos(Math.PI * val / 180));
            }
            else
            {
                x = cx - (int)(hlen * -Math.Sin(Math.PI * val / 180));
                y = cy - (int)(hlen * Math.Cos(Math.PI * val / 180));
            }
            int[] n = { x, y };
            return n;
        }
    }
}
