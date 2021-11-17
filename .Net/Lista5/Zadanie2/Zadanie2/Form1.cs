using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zadanie2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Lista.FullRowSelect = true;
        }

        private void button_Click(object sender, EventArgs e)
        {
            ListViewItem li = Lista.Items.Add(name.Text);
            li.SubItems.Add(surname.Text);
            li.SubItems.Add(height.Text);
    
        }

        private void button1_Click(object sender, EventArgs e)
        {
            TreeNode n = new TreeNode(textBox1.Text);
            treeView1.SelectedNode.Nodes.Add(n);
        }

        private void down_Click(object sender, EventArgs e)
        {
            if(progressBar1.Value>0)
                progressBar1.Value = progressBar1.Value - 5;
        }

        private void up_Click(object sender, EventArgs e)
        {
            if (progressBar1.Value < 100)
                progressBar1.Value = progressBar1.Value + 5;
        }
    }
}
