using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zadanie4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            SmoothProgressBar s = new SmoothProgressBar(0, 100, 50);
            s.Text = "Komponent 1";
            s.BackColor = Color.Red;
            s.Font = new Font("Tahoma", 18);
            s.Size = new Size(50, 50);
            s.Dock = DockStyle.Fill;
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }
    }

    public class SmoothProgressBar : UserControl
    {
        int min;
        int max;
        int val;
        int Min {
            set
            {
                min = value;
            }
            get
            {
                return min;
            }
        }
        int Max
        {
            set
            {
                max = value;
            }
            get
            {
                return max;
            }
        }
        int Value {
            set
            {
                int oldValue = val;
                if (value < min)
                {
                    val = min;
                }
                else if (value > max)
                {
                    val = max;
                }
                else
                {
                    val = value;
                }
                float percent;

                Rectangle newValueRect = this.ClientRectangle;
                Rectangle oldValueRect = this.ClientRectangle;
                percent = (float)(val - min) / (float)(max - min);
                newValueRect.Width = (int)((float)newValueRect.Width * percent);
                percent = (float)(oldValue - min) / (float)(max - min);
                oldValueRect.Width = (int)((float)oldValueRect.Width * percent);

                Rectangle updateRect = new Rectangle();
                if (newValueRect.Width > oldValueRect.Width)
                {
                    updateRect.X = oldValueRect.Size.Width;
                    updateRect.Width = newValueRect.Width - oldValueRect.Width;
                }
                else
                {
                    updateRect.X = newValueRect.Size.Width;
                    updateRect.Width = oldValueRect.Width - newValueRect.Width;
                }

                updateRect.Height = this.Height;
                this.Invalidate(updateRect);
            }
            get {
                return val;
                    } 
        }

        Color BarColor = Color.Blue;
        public SmoothProgressBar(int min, int max, int value)
        {
            this.max = max;
            this.min = min;
            this.val = value;
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            SolidBrush brush = new SolidBrush(BarColor);
            float percent = (float)(val - min) / (float)(max - min);
            Rectangle rect = this.ClientRectangle;
            rect.Width = (int)((float)rect.Width * percent);

            // Draw the progress meter.
            g.FillRectangle(brush, rect);

            // Clean up.
            brush.Dispose();
            g.Dispose();
        }
    }
}
