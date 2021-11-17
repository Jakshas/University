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
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Studia_Enter(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Akceptuj_Click(object sender, EventArgs e)
        {
            string s;
            if (checkBox1.Checked)
            {
                s = "dzienne";
            }
            else
            {
                s = "uzupełniajace";
            }
            MessageBox.Show(textBox1.Text +"\n"+ textBox2.Text + "\n" +Lata.Text + "\n"+ s + "\n");
        }

        private void uzupelniajace_Click(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                uzupelniajace.Checked = true;
                checkBox1.Checked = false;
            }
        }

        private void checkBox1_Click(object sender, EventArgs e)
        {
            if (uzupelniajace.Checked)
            {
                uzupelniajace.Checked = false;
                checkBox1.Checked = true;
            }
        }

        private void Anuluj_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Pomoc_Click(object sender, EventArgs e)
        {
            Help.ShowHelp(this, helpNazwa.HelpNamespace);
        }
    }
}
