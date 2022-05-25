using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zadanie1
{
    public partial class Form2 : Form
    {
        Form1 f;
        public Form2(Form1 f)
        {
            InitializeComponent();
            this.f= f;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            UserProfileAddedNotification n = new UserProfileAddedNotification(textBox1.Text, textBox2.Text , textBox3.Text, textBox4.Text, checkBox1.Checked);
            f.agregator.Publish(n);
        }
    }
}
